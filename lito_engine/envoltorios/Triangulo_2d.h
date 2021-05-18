#ifndef TRIANGULO_2D_H
#define TRIANGULO_2D_H

#include "Poligono_convexo_2d.h"

namespace lito {

template <class T>
class Triangulo_2d : public Poligono_convexo_2d<T> {
public:
    Triangulo_2d<T> ( const Vec_2<T> &p_1, const Vec_2<T> &p_2, const Vec_2<T> &p_3 )
    : Poligono_convexo_2d<T>( 3 )
    {
        pontos[0] = p_1;
        pontos[1] = p_2;
        pontos[2] = p_3;
    }

    int quantidade_eixos () {
        return 3;
    }

    Vec_2<T> eixo ( int i ) {
        switch( i ) {
            case 0: return p_2 - p_1; break;
            case 1: return p_3 - p_2; break;
            case 2: return p_1 - p_3; break;
            default: return Vec_2<T>( 0.0f, 0.0f ); break;
        }
    }
};

}

#endif