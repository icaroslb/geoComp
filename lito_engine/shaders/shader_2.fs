#version 430 core

uniform vec3 cor;

out vec4 FragColor;

void main () {
	FragColor = vec4( cor, 1.0 );
}