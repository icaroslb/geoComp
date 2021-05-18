#include <iostream>
#include <Engine_SDL.h>
#include <Engine_OpenGl.h>
#include <Shader.h>

#include "config.h"

#if defined(WIN32) || defined(_WIN32) || defined(__WIN32) && !defined(__CYGWIN__)
int wmain( int argc, wchar_t* argv[] ) {
#else
int main( int argc, char* argv[] ) {
#endif

    std::cout << PROJECT_NAME << " - VERSION " << PROJECT_VER << std::endl;

    lito::Engine_SDL tela( "Projeto", 500, 500 );
    SDL_Event evento;
	bool loop = true;

    float cor_cinza = 0.0f;

    printf( "Versão do OpenGl: %s\n", tela.obter_versao_opengl() );

    while ( loop ) {

		while ( SDL_PollEvent( &evento ) ) {

			if ( evento.type == SDL_QUIT ) {
				loop = false;
			}
		}

		/***********************************************************************/
		/*********************************PRINT*********************************/

		glClearColor( cor_cinza, cor_cinza, cor_cinza, 1.0f );

		glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );

		tela.swap_tela();

        cor_cinza += 0.001f;
        cor_cinza = std::fmodf(cor_cinza, 1.0f);
	}

    return 0;
}