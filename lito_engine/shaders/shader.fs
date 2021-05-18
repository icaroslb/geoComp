#version 430 core

in vec3 cor;

out vec4 FragColor;

void main () {
	FragColor = vec4( cor, 1.0 );
}