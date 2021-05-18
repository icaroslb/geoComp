#define STB_IMAGE_IMPLEMENTATION
#include "Leitor_imagem.h"

namespace lito {

unsigned int ler_imagem ( std::string nome_imagem, int &largura, int &altura, int &n_canais ) {
	unsigned int id;
	unsigned char *data;
	
	stbi_set_flip_vertically_on_load(true);
	
	glGenTextures( 1, &id );
	glBindTexture( GL_TEXTURE_2D, id );
	
	glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT );
	glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT );
	glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR );
	glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR );

	data = stbi_load( nome_imagem.data(), &largura, &altura, &n_canais, 0 );

	if ( data ) {
		glTexImage2D( GL_TEXTURE_2D, 0, GL_RGB, largura, altura, 0, GL_RGB, GL_UNSIGNED_BYTE, data );
    	glGenerateMipmap( GL_TEXTURE_2D );
	} else {
		std::cout << "Falha ao ler a imagem " << nome_imagem << "!" << std::endl;
	}

	stbi_image_free( data );
	
	return id;
}
/*==================================================*/
float* carregar_imagem ( std::string nome_imagem, int &largura, int &altura, int &n_canais, const Canais &canal )
{
	unsigned char *data_img;
	float *data;
	int area;
	
	stbi_set_flip_vertically_on_load(true);

	data_img = stbi_load( nome_imagem.data(), &largura, &altura, &n_canais, 0 );

	if ( data_img ) {
		area = largura * altura;

		if ( canal == Canais::CINZA ) {
			data = new float [ area ];

			if ( n_canais == 3 ) {
				for ( int i = 0; i < area; i++  ) {
					data[i] = ( 0.298936f * ( (float)data_img[ ( 3 * i )     ] ) / 255.0f )
					        + ( 0.587043f * ( (float)data_img[ ( 3 * i ) + 1 ] ) / 255.0f )
							+ ( 0.114021f * ( (float)data_img[ ( 3 * i ) + 2 ] ) / 255.0f );
				}
			} else {
				for ( int i = 0; i < area; i++  ) {
					data[i] = ( 0.298936f * ( (float)data_img[ ( 4 * i )     ] ) / 255.0f )
					        + ( 0.587043f * ( (float)data_img[ ( 4 * i ) + 1 ] ) / 255.0f )
					        + ( 0.114021f * ( (float)data_img[ ( 4 * i ) + 2 ] ) / 255.0f );
				}
			}
		} else {
			data = new float [ area * 3 ];

			if ( n_canais == 3 ) {
				for ( int i = 0; i < area; i++  ) {
					data[ ( 3 * i )     ] = ( (float)data_img[ ( 3 * i )     ] ) / 255.0f;
					data[ ( 3 * i ) + 1 ] = ( (float)data_img[ ( 3 * i ) + 1 ] ) / 255.0f;
					data[ ( 3 * i ) + 2 ] = ( (float)data_img[ ( 3 * i ) + 2 ] ) / 255.0f;
				}
			} else {
				for ( int i = 0; i < area; i++  ) {
					data[ ( 3 * i )     ] = ( (float)data_img[ ( 4 * i )     ] ) / 255.0f;
					data[ ( 3 * i ) + 1 ] = ( (float)data_img[ ( 4 * i ) + 1 ] ) / 255.0f;
					data[ ( 3 * i ) + 2 ] = ( (float)data_img[ ( 4 * i ) + 2 ] ) / 255.0f;
				}
			}
		}
	} else {
		std::cout << "Falha ao ler a imagem " << nome_imagem << "!" << std::endl;
	}

	stbi_image_free( data_img );
	
	return data;
}

}