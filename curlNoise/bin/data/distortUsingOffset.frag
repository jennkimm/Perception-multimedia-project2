#version 150

out vec4 fragColor;

uniform vec2 u_resolution;
uniform sampler2D imageTexture;
uniform sampler2D offsetTexture;

void main() {
	// Get the texture co-ordinate of the current pixel
    vec2 texCoord = gl_FragCoord.xy / textureSize(offsetTexture, 0);

	// Lookup the offset value for this pixel from the offsetTexture
	vec4 offsetVal = texture(offsetTexture, texCoord);
	texCoord.y = 1.0 - texCoord.y;

	// Lookup the colour value for this pixel applying the offset to the texture coordinate
	vec4 textureCol = texture(imageTexture, texCoord + offsetVal.xy);

	// Set output colour for this pixel
	fragColor = vec4(textureCol.rgb, 1.0);
}
