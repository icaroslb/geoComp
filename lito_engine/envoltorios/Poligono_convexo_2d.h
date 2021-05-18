#ifndef POLIGONO_CONVEXO_2D_H
#define POLIGONO_CONVEXO_2D_H

#include <limits>
#include <algorithm>
#include "../algebra/algebra_vetor.h"

namespace lito {

template <class T>
class Poligono_convexo_2d {
public:
    Vec_2<T> *pontos;
    int qtd_pontos;

    Poligono_convexo_2d( Vec_2<T> pos, int qtd )
    : qtd_pontos( qtd )
    {
        pontos = new Vec_2<T>[ qtd ];
    }

    int quantidade_eixos () = 0;
    virtual Vec_2<T> eixo ( int i ) = 0;
    
    Vec_2<T> projetar_eixo ( const Vec_2<T> &eixo )
    {
        T proj_calc;
        Vec_2<T> min_max( +std::numeric_limits<T>::infinity()
                        , -std::numeric_limits<T>::infinity() );
        
        for ( int i = 0; i < qtd_pontos; i++ ) {
            proj_calc = projecao_p( pontos[i], eixo );

            if ( min_max._x > proj_calc )
                min_max._x = proj_calc;
            else if ( min_max._y < proj_calc )
                min_max._y = proj_calc;
        }

        return min_max;
    }

    ~Poligono_convexo_2d()
    {
        delete [] pontos;
    }
};

}

#endif