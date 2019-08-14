#version 150

in vec4 position;
in vec4 color;
in vec4 normal;
in vec2 texcoord;

out vec2 v_texcoord;
out vec3 v_viewSpaceNormal;
out vec3 v_viewSpacePos;
out float v_terrainHeight;

uniform float heightScale;
uniform float noiseScale;
uniform float waterLevel;

uniform mat4 modelViewMatrix;
uniform mat4 modelMatrix;
uniform mat4 viewMatrix;
uniform mat4 projectionMatrix;
uniform mat4 textureMatrix;
uniform mat4 modelViewProjectionMatrix;

float random (in vec2 st) {
    return fract(sin(dot(st.xy,
                         vec2(12.9898,78.233)))*
        43758.5453123);
}

// Based on Morgan McGuire @morgan3d
// https://www.shadertoy.com/view/4dS3Wd
float noise (in vec2 st) {
    vec2 i = floor(st);
    vec2 f = fract(st);

    // Four corners in 2D of a tile
    float a = random(i);
    float b = random(i + vec2(1.0, 0.0));
    float c = random(i + vec2(0.0, 1.0));
    float d = random(i + vec2(1.0, 1.0));

    vec2 u = f * f * (3.0 - 2.0 * f);

    return mix(a, b, u.x) +
            (c - a)* u.y * (1.0 - u.x) +
            (d - b) * u.x * u.y;
}

// Some useful functions
vec3 mod289(vec3 x) { return x - floor(x * (1.0 / 289.0)) * 289.0; }
vec2 mod289(vec2 x) { return x - floor(x * (1.0 / 289.0)) * 289.0; }
vec3 permute(vec3 x) { return mod289(((x*34.0)+1.0)*x); }

//
// Description : GLSL 2D simplex noise function
//      Author : Ian McEwan, Ashima Arts
//  Maintainer : ijm
//     Lastmod : 20110822 (ijm)
//     License :
//  Copyright (C) 2011 Ashima Arts. All rights reserved.
//  Distributed under the MIT License. See LICENSE file.
//  https://github.com/ashima/webgl-noise
//
float snoise(vec2 v) {

    // Precompute values for skewed triangular grid
    const vec4 C = vec4(0.211324865405187,
                        // (3.0-sqrt(3.0))/6.0
                        0.366025403784439,
                        // 0.5*(sqrt(3.0)-1.0)
                        -0.577350269189626,
                        // -1.0 + 2.0 * C.x
                        0.024390243902439);
                        // 1.0 / 41.0

    // First corner (x0)
    vec2 i  = floor(v + dot(v, C.yy));
    vec2 x0 = v - i + dot(i, C.xx);

    // Other two corners (x1, x2)
    vec2 i1 = vec2(0.0);
    i1 = (x0.x > x0.y)? vec2(1.0, 0.0):vec2(0.0, 1.0);
    vec2 x1 = x0.xy + C.xx - i1;
    vec2 x2 = x0.xy + C.zz;

    // Do some permutations to avoid
    // truncation effects in permutation
    i = mod289(i);
    vec3 p = permute(
            permute( i.y + vec3(0.0, i1.y, 1.0))
                + i.x + vec3(0.0, i1.x, 1.0 ));

    vec3 m = max(0.5 - vec3(
                        dot(x0,x0),
                        dot(x1,x1),
                        dot(x2,x2)
                        ), 0.0);

    m = m*m ;
    m = m*m ;

    // Gradients:
    //  41 pts uniformly over a line, mapped onto a diamond
    //  The ring size 17*17 = 289 is close to a multiple
    //      of 41 (41*7 = 287)

    vec3 x = 2.0 * fract(p * C.www) - 1.0;
    vec3 h = abs(x) - 0.5;
    vec3 ox = floor(x + 0.5);
    vec3 a0 = x - ox;

    // Normalise gradients implicitly by scaling m
    // Approximation of: m *= inversesqrt(a0*a0 + h*h);
    m *= 1.79284291400159 - 0.85373472095314 * (a0*a0+h*h);

    // Compute final noise value at P
    vec3 g = vec3(0.0);
    g.x  = a0.x  * x0.x  + h.x  * x0.y;
    g.yz = a0.yz * vec2(x1.x,x2.x) + h.yz * vec2(x1.y,x2.y);
    return 130.0 * dot(m, g);
}

#define OCTAVES 6
float fbm (in vec2 st) {
    // Initial values
    float value = 0.0;
    float amplitude = .5;
    float frequency = 0.;
    
    // Loop of octaves
	for (int i = 0; i < OCTAVES; i++) {
		value += -amplitude * snoise(st);
		st *= 2.;
		amplitude *= .5;
	}

    return value;
}

vec4 heightfieldPos(vec4 gridPos) {
	// Calculate the position that a point in the grid is moved to by the heightfield.
	// All calculations are in world-space, where up is in the y-axis direction.

	// Comment in one of the following lines to get different style mountainscapes:
	float heightVal = max(heightScale * fbm(noiseScale * gridPos.xz), waterLevel);
	//float heightVal = max(heightScale * abs(fbm(noiseScale * gridPos.xz)), waterLevel);
	//float heightVal = max(-heightScale * abs(fbm(noiseScale * gridPos.xz)), waterLevel);

	return gridPos + vec4(0.0, heightVal, 0.0, 0.0);
}

vec4 heightfieldNormal(vec4 gridPos) {
	// Calculate normal by taking the cross product of the gradients in the
	// x and z directions of the grid. Note that all values are calculated
	// in world-space
	const float epsilon = 0.01;
	vec4 p0 = heightfieldPos(gridPos);
	vec4 p1 = heightfieldPos(gridPos + vec4(epsilon, 0.0, 0.0, 0.0));
	vec4 p2 = heightfieldPos(gridPos + vec4(0.0, 0, epsilon, 0.0));
	vec3 n = normalize(cross(p2.xyz - p0.xyz, p1.xyz - p0.xyz));
	return vec4(n, 0.0);
}

void main(){
	// Get the world-space position of the current vertex
	vec4 ws_position = modelMatrix * position;

	// Calculate the world-space position of the vertex in after being offset
	vec4 ws_terrainPos = heightfieldPos(ws_position);

	// Calculate the normal in world-space 
	vec4 ws_terrainNormal = heightfieldNormal(ws_position);

	// Calculate the position of the vertex in view-space for use by the fragment shader
	vec4 viewSpacePos = viewMatrix * ws_terrainPos;
	v_viewSpacePos = viewSpacePos.xyz / viewSpacePos.w;

	// Calculate the normal of the vertex in view-space for use by the fragment shader
	vec4 viewSpaceNormal = transpose(inverse(viewMatrix)) * ws_terrainNormal;
	v_viewSpaceNormal = normalize(viewSpaceNormal.xyz);

	// Calculate the terrain height at the vertex for use by the fragment shader
	v_terrainHeight = ws_terrainPos.y;

	// Pass on the texture coordinate of the vertex for use by the fragment shader
	v_texcoord = texcoord;

	// Use the projectionMatrix and viewMatrix to calculate the position of the vertex
	// in display-space
	gl_Position = projectionMatrix * viewMatrix * ws_terrainPos;
}
