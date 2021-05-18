#ifndef ENGINE_OPENGL_H
#define ENGINE_OPENGL_H

#include <iostream>
#include <GL/glew.h>
#include <vector>

namespace lito {

enum class Attrib_config { FLOAT, INT, DOUBLE };

struct Vertex_array_config {
	int tipo;
	int tam;
	Attrib_config tipo_attrib;
	bool norm;

	Vertex_array_config ( int tipo, int tam, Attrib_config tipo_attrib, bool norm )
	: tipo( tipo ), tam( tam ), tipo_attrib( tipo_attrib ), norm( norm ) {}

	Vertex_array_config ( int tipo, int tam, Attrib_config tipo_attrib )
	: tipo( tipo ), tam( tam ), tipo_attrib( tipo_attrib ), norm( GL_FALSE ) {}
};

static int tam_tipo_config ( int tipo )
{
	switch ( tipo )
	{
		case GL_BYTE:           return 1;
		case GL_UNSIGNED_BYTE:  return 1;
		case GL_SHORT:          return 2;
		case GL_UNSIGNED_SHORT: return 2;
		case GL_INT:            return 4;
		case GL_UNSIGNED_INT:   return 4;
		case GL_HALF_FLOAT:     return 2;
		case GL_FLOAT:          return 4;
		case GL_DOUBLE:         return 8;
	}
}

class Engine_OpenGl {
	std::vector<unsigned int> VAOs,
	                          VBOs,
	                          EBOs;
public:
	Engine_OpenGl ();
	
	unsigned int criar_vertice_buffer ( void *vertices, int tam_data, int qtd_data, int tam_array, int qtd_sub_data, int *tam_sub_data = nullptr, int uso = GL_STATIC_DRAW );
	unsigned int criar_element_buffer ( unsigned int *indices, int qtd, int uso = GL_STATIC_DRAW );
	
	void reiniciar_vertice_buffer ( int id, void *vertices, int tam_data, int qtd_data, int uso = GL_STATIC_DRAW );
	void reiniciar_element_buffer ( int id, unsigned int *indices, int qtd, int uso = GL_STATIC_DRAW );
	
	void atualizar_vertice_buffer ( int id, void *vertices_atu, int ini_data, int tam_data, int qtd_data );
	void atualizar_element_buffer ( int id, unsigned int *indices, int qtd, int uso = GL_STATIC_DRAW );
	
	void usar_vertice_buffer ( int id );
	void usar_element_buffer ( int id );
	
	void desusar_vertice_buffer ();
	void desusar_element_buffer ();
};

unsigned int criar_vertice_buffer ( void *vertices, int tam_data, int qtd_data, int tam_array, int qtd_sub_data, int *tam_sub_data = nullptr, int uso = GL_STATIC_DRAW );
unsigned int criar_vertice_buffer ( void *vertices, Vertex_array_config *array_config, int qtd_config, int qtd_data, int uso = GL_STATIC_DRAW );
unsigned int criar_element_buffer ( unsigned int *indices, int qtd, int uso = GL_STATIC_DRAW );

void reiniciar_vertice_buffer ( int id, void *vertices, int tam_data, int qtd_data, int uso = GL_STATIC_DRAW );
void reiniciar_element_buffer ( int id, unsigned int *indices, int qtd, int uso = GL_STATIC_DRAW );

void atualizar_vertice_buffer ( int id, void *vertices_atu, int ini_data, int tam_data, int qtd_data );
void atualizar_element_buffer ( int id, unsigned int *indices, int qtd, int uso = GL_STATIC_DRAW );

void usar_vertice_buffer ( int id );
void usar_element_buffer ( int id );

void desusar_vertice_buffer ();
void desusar_element_buffer ();

}

#endif
