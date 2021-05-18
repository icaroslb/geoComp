#ifndef AABB_2D_H
#define AABB_2D_H

#include "Poligono_convexo_2d.h"

namespace lito {

template <class T>
class AABB_2d : public Poligono_convexo_2d<T> {
public:
    AABB_2d<T> ( const Vec_2<T> &pos, T largura, T altura )
    : Poligono_convexo_2d<T>( 4 )
    {
        for ( int i = 0; i < 4; i++ ) {
            pontos[i] = pos;
        }
        
        pontos[0]._x -= largura / T(2);
        pontos[0]._y -= altura / T(2);
        
        pontos[1]._x += largura / T(2);
        pontos[1]._y -= altura / T(2);
        
        pontos[2]._x += largura / T(2);
        pontos[2]._y += altura / T(2);
        
        pontos[3]._x -= largura / T(2);
        pontos[3]._y += altura / T(2);
    }

    int quantidade_eixos () {
        return 2;
    }

    Vec_2<T> eixo ( int i ) {
        switch( i ) {
            case 0: return Vec_2<T>( 1.0f, 0.0f ); break;
            case 1: return Vec_2<T>( 0.0f, 1.0f ); break;
            default: return Vec_2<T>( 0.0f, 0.0f ); break;
        }
    }
};

}

#endif