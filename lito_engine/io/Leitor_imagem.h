#include <iostream>
#include <fstream>

#include <GL/glew.h>
#include <GL/gl.h>
#include <GL/glu.h>

#include "stb_image.h"

namespace lito {

enum class Canais{ RGB, CINZA };

unsigned int ler_imagem ( std::string nome_imagem, int &largura, int &altura, int &n_canais );
float* carregar_imagem ( std::string nome_imagem, int &largura, int &altura, int &n_canais, const Canais &canal );

}