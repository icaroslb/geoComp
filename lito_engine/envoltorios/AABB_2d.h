#ifndef AABB_2D_H
#define AABB_2D_H

#include "Envoltorio_2d.h"

namespace lito {

template <class T>
class AABB_2d : public Envoltorio_2d<T> {
public:
    Vec_2<T> _pos;
    T _largura;
    T _altura;

    AABB_2d<T> ( const Vec_2<T> &pos, T largura, T altura )
    : Envoltorio_2d<T>( pos, largura, altura )
    , _pos( pos )
    , _largura( largura )
    , _altura( altura )
    {}
};

}

#endif