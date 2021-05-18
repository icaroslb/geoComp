#ifndef ENVOLTORIO_2D_H
#define ENVOLTORIO_2D_H

#include "../algebra/Vec_2.h"

namespace lito {

template <class T>
struct Quadri_envol
{
    Vec_2<T> inf_dir;
    Vec_2<T> sup_dir;
    Vec_2<T> sup_esq;
    Vec_2<T> inf_esq;
};

template <class T>
class Envoltorio_2d {
public:
    union {
        Quadri_envol<T> _quadri_envol;
        T _array_val[8];
        Vec_2<T> _array_vec[4];
    };

    Envoltorio_2d( const Vec_2<T> &pos, T largura, T altura )
    {
        _quadri_envol.inf_dir = pos + Vec_2<T>( +largura, -altura );
        _quadri_envol.sup_dir = pos + Vec_2<T>( +largura, +altura );
        _quadri_envol.sup_esq = pos + Vec_2<T>( -largura, +altura );
        _quadri_envol.inf_esq = pos + Vec_2<T>( -largura, -altura );
    }
};

}

#endif