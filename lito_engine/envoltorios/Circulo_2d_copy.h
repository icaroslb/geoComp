#ifndef CIRCULO_2D_H
#define CIRCULO_2D_H

#include "Poligono_convexo_2d.h"

namespace lito {

template <class T>
class Circulo_2d : public Poligono_convexo_2d<T> {
public:
    T raio;

    Circulo_2d<T> ( const Vec_2<T> &pos, T raio )
    : Poligono_convexo_2d<T>( 1 )
    , raio( raio )
    {
        pontos[0] = pos;
    }

    int quantidade_eixos () {
        return 0;
    }

    Vec_2<T> eixo ( int i ) {
        return Vec_2<T>( 0.0f, 0.0f );
    }

    Vec_2<T> projetar_eixo ( const Vec_2<T> &eixo )
    {
        T proj_calc;
        T eixo_tam = norma( eixo );
        Vec_2<T> ponto_ang( 0.0f
                          , 0.0f );
        
        proj_calc = projecao_p( pontos[0], eixo );

        ponto_ang._x = truncagem( proj_calc, eixo_tam, 0.0f );
        ponto_ang._y = pseudoangulo( eixo, pontos[0] - ( eixo * ponto_ang._x ) );

        return ponto_ang;
    }
};

}

#endif