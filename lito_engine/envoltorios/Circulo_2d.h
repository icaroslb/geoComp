#ifndef CIRCULO_2D_H
#define CIRCULO_2D_H

#include "Envoltorio_2d.h"

namespace lito {

template <class T>
class Circulo_2d : public Envoltorio_2d<T> {
public:
    Vec_2<T> _pos;
    T _raio;

    Circulo_2d<T> ( const Vec_2<T> &pos, T raio )
    : Envoltorio_2d<T>( pos, raio, raio )
    , _pos( pos )
    , _raio( raio )
    {}
};

}

#endif