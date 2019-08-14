#version 150

out vec4 v_color;

in vec4 position;

// these are passed in from OF programmable renderer
uniform mat4 modelViewMatrix;
uniform mat4 modelMatrix;
uniform mat4 viewMatrix;
uniform mat4 projectionMatrix;
uniform mat4 modelViewProjectionMatrix;
uniform vec4 modelColor;
uniform float time;
uniform float amplitude;
uniform float freqTime;
uniform float freqSpace;

void main (void){
	v_color = modelColor;
	vec4 posModelSpace = position;
	vec4 posWorldSpace = modelMatrix * posModelSpace;
	posWorldSpace.y += amplitude * sin(freqTime * time + freqSpace * posWorldSpace.y);
	vec4 posViewSpace = viewMatrix * posWorldSpace;
	vec4 posProjectionSpace = projectionMatrix * posViewSpace;
	posProjectionSpace /= posProjectionSpace.w;
	gl_Position = posProjectionSpace;
}
