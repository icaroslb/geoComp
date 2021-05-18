#include "Camera.h"

int main () {
    lito::Camera<float> camera( lito::Vec_3f( 0.0f, 0.0, 0.0f ), lito::Vec_3f( 0.0f, 0.0f, 1.0f ), lito::Vec_3f( 0.0f, 1.0f, 0.0f )
                              , -1.0f, 1.0f, -1.0f, 1.0f, -1.0f, 1.0f, lito::ORTHO );

    return 0; 
}