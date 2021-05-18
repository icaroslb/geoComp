#version 430 core

layout ( location = 0 ) in vec2 aPos;
layout ( location = 1 ) in vec3 Cor;

out vec3 cor;

uniform mat4 matriz_modelo;

void main () {
	gl_Position = matriz_modelo * vec4( aPos, 0.0, 1.0 );
	cor = Cor;
}