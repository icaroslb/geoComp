#ifndef VEC_4_H
#define VEC_4_H

#include <iostream>
#include <cstring>

#include "Vec_3.hpp"

namespace lito {

template <class T>
class Vec_4 {
public:
	
	union
	{
		T coord[4];
		struct { T _x, _y, _z, _w; };
	};
	
	Vec_4<T> ( T x = 0, T y = 0, T z = 0, T w = 0 );
	
	T& x ();
	const T& x () const;
	T& y ();
	const T& y () const;
	T& z ();
	const T& z () const;
	T& w ();
	const T& w () const;
	
	T&       operator [] ( int i );
	const T& operator [] ( int i ) const;
	
	Vec_4<T>  operator + ( const Vec_4<T> &v ) const;
	Vec_4<T>  operator - ( const Vec_4<T> &v ) const;
	Vec_4<T>  operator * ( const Vec_4<T> &v ) const;
	Vec_4<T>  operator + ( const Vec_3<T> &v ) const;
	Vec_4<T>  operator - ( const Vec_3<T> &v ) const;
	Vec_4<T>  operator * ( const Vec_3<T> &v ) const;
	Vec_4<T>  operator + ( T c ) const;
	Vec_4<T>  operator - ( T c ) const;
	Vec_4<T>  operator * ( T c ) const;
	Vec_4<T>  operator / ( T c ) const;
	
	Vec_4<T>& operator  = ( const Vec_4<T> &v );
	Vec_4<T>& operator += ( const Vec_4<T> &v );
	Vec_4<T>& operator -= ( const Vec_4<T> &v );
	Vec_4<T>& operator *= ( const Vec_4<T> &v );
	Vec_4<T>& operator += ( T c );
	Vec_4<T>& operator -= ( T c );
	Vec_4<T>& operator *= ( T c );
	Vec_4<T>& operator /= ( T c );

	operator Vec_3<T> () { return Vec_3<T>( _x, _y, _z ); }
	operator Vec_3<T> () const { return Vec_3<T>( _x, _y, _z ); }

};

typedef Vec_4<float>  Vec_4f;
typedef Vec_4<double> Vec_4d;

template <class T> Vec_4<T> operator + ( const Vec_4<T> &v );
template <class T> Vec_4<T> operator - ( const Vec_4<T> &v );
template <class T> Vec_4<T> operator + ( T c, const Vec_4<T> &v );
template <class T> Vec_4<T> operator - ( T c, const Vec_4<T> &v );
template <class T> Vec_4<T> operator * ( T c, const Vec_4<T> &v );
template <class T> Vec_4<T>& operator << ( Vec_4<T> &vet, T dado );
template <class T> Vec_4<T>& operator ,  ( Vec_4<T> &vet, T dado );
template <class T> std::ostream& operator << ( std::ostream &os, const Vec_4<T> &v );

template <class T> Vec_4<T>  operator + ( const Vec_3<T> &v3, const Vec_4<T> &v4 );
template <class T> Vec_4<T>  operator - ( const Vec_3<T> &v3, const Vec_4<T> &v4 );
template <class T> Vec_4<T>  operator * ( const Vec_3<T> &v3, const Vec_4<T> &v4 );

/*********************************************************************************************************************************/
/*********************************************************************************************************************************/
/*********************************************************************************************************************************/
/*********************************************************************************************************************************/
/*********************************************************************************************************************************/

template <class T>
Vec_4<T>::Vec_4 ( T x, T y, T z, T w )
: _x( x )
, _y( y )
, _z( z )
, _w( w )
{}
/*===============================================================================================================================*/
template <class T>
T& Vec_4<T>::x () { return _x; }
/*===============================================================================================================================*/
template <class T>
const T& Vec_4<T>::x () const { return _x; }
/*===============================================================================================================================*/
template <class T>
T& Vec_4<T>::y () { return _y; }
/*===============================================================================================================================*/
template <class T>
const T& Vec_4<T>::y () const { return _y; }
/*===============================================================================================================================*/
template <class T>
T& Vec_4<T>::z () { return _z; }
/*===============================================================================================================================*/
template <class T>
const T& Vec_4<T>::z () const { return _z; }
/*===============================================================================================================================*/
template <class T>
T& Vec_4<T>::w () { return _w; }
/*===============================================================================================================================*/
template <class T>
const T& Vec_4<T>::w () const { return _w; }
/*===============================================================================================================================*/
template <class T>
T& Vec_4<T>::operator[] ( int i ) { return coord[i]; }
/*===============================================================================================================================*/
template <class T>
const T& Vec_4<T>::operator[] ( int i ) const { return coord[i]; }
/*===============================================================================================================================*/
template <class T>
Vec_4<T> Vec_4<T>::operator + ( const Vec_4<T> &v ) const
{
	return Vec_4<T>( _x + v._x, _y + v._y, _z + v._z, _w + v._w );
}
/*===============================================================================================================================*/
template <class T>
Vec_4<T> Vec_4<T>::operator - ( const Vec_4<T> &v ) const
{
	return Vec_4<T>( _x - v._x, _y - v._y, _z - v._z, _w - v._w );
}
/*===============================================================================================================================*/
template <class T>
Vec_4<T> Vec_4<T>::operator * ( const Vec_4<T> &v ) const
{
	return Vec_4<T>( _x * v._x, _y * v._y, _z * v._z, _w * v._w );
}
/*===============================================================================================================================*/
template <class T>
Vec_4<T> Vec_4<T>::operator + ( const Vec_3<T> &v ) const
{
	return Vec_4<T>( _x + v._x, _y + v._y, _z + v._z, _w );
}
/*===============================================================================================================================*/
template <class T>
Vec_4<T> Vec_4<T>::operator - ( const Vec_3<T> &v ) const
{
	return Vec_4<T>( _x - v._x, _y - v._y, _z - v._z, _w );
}
/*===============================================================================================================================*/
template <class T>
Vec_4<T> Vec_4<T>::operator * ( const Vec_3<T> &v ) const
{
	return Vec_4<T>( _x * v._x, _y * v._y, _z * v._z, _w );
}
/*===============================================================================================================================*/
template <class T>
Vec_4<T> Vec_4<T>::operator + ( const T c ) const
{
	return Vec_4<T>( _x + c, _y + c, _z + c, _w + c );
}
/*===============================================================================================================================*/
template <class T>
Vec_4<T> Vec_4<T>::operator - ( T c ) const
{
	return Vec_4<T>( _x - c, _y - c, _z - c, _w - c );
}
/*===============================================================================================================================*/
template <class T>
Vec_4<T> Vec_4<T>::operator * ( T c ) const
{
	return Vec_4<T>( _x * c, _y * c, _z * c, _w * c );
}
/*===============================================================================================================================*/
template <class T>
Vec_4<T> Vec_4<T>::operator / ( T c ) const
{
	c = T(1) / c;
	return Vec_4<T>( _x * c, _y * c, _z * c, _w * c );
}
/*===============================================================================================================================*/
template <class T>
Vec_4<T>& Vec_4<T>::operator = ( const Vec_4<T> &v )
{
	memcpy( coord, v.coord, sizeof(T) * 4 );
	
	return *this;
}
/*===============================================================================================================================*/
template <class T>
Vec_4<T>& Vec_4<T>::operator += ( const Vec_4<T> &v )
{
	_x += v._x;
	_y += v._y;
	_z += v._z;
	_w += v._w;
	
	return *this;
}
/*===============================================================================================================================*/
template <class T>
Vec_4<T>& Vec_4<T>::operator -= ( const Vec_4<T> &v )
{
	_x -= v._x;
	_y -= v._y;
	_z -= v._z;
	_w -= v._w;
	
	return *this;
}
/*===============================================================================================================================*/
template <class T>
Vec_4<T>& Vec_4<T>::operator *= ( const Vec_4<T> &v )
{
	_x *= v._x;
	_y *= v._y;
	_z *= v._z;
	_w *= v._w;
	
	return *this;
}
/*===============================================================================================================================*/
template <class T>
Vec_4<T>& Vec_4<T>::operator += ( T c )
{
	_x += c;
	_y += c;
	_z += c;
	_w += c;
	
	return *this;
}
/*===============================================================================================================================*/
template <class T>
Vec_4<T>& Vec_4<T>::operator -= ( T c )
{
	_x -= c;
	_y -= c;
	_z -= c;
	_w -= c;
	
	return *this;
}
/*===============================================================================================================================*/
template <class T>
Vec_4<T>& Vec_4<T>::operator *= ( T c )
{
	_x *= c;
	_y *= c;
	_z *= c;
	_w *= c;
	
	return *this;
}
/*===============================================================================================================================*/
template <class T>
Vec_4<T>& Vec_4<T>::operator /= ( T c )
{
	c = T(1) / c;
	
	_x *= c;
	_y *= c;
	_z *= c;
	_w *= c;
	
	return *this;
}
/*===============================================================================================================================*/
template <class T>
Vec_4<T> operator + ( const Vec_4<T> &v )
{
	return Vec_4<T>( +v._x, +v._y, +v._z, +v._w );
}
/*===============================================================================================================================*/
template <class T>
Vec_4<T> operator - ( const Vec_4<T> &v )
{
	return Vec_4<T>( -v._x, -v._y, -v._z, -v._w );
}
/*===============================================================================================================================*/
template <class T> Vec_4<T> operator + ( T c, const Vec_4<T> &v )
{
	return Vec_4<T>( c + v._x, c + v._y, c + v._z, c + v._w );
}
/*===============================================================================================================================*/
template <class T> Vec_4<T> operator - ( T c, const Vec_4<T> &v )
{
	return Vec_4<T>( c - v._x, c - v._y, c - v._z, c - v._w );
}
/*===============================================================================================================================*/
template <class T>
Vec_4<T> operator * ( T c, const Vec_4<T> &v ) {
	return Vec_4<T>( c * v._x, c * v._y, c * v._z, c * v._w );
}
/*===============================================================================================================================*/
template <class T>	
Vec_4<T>& operator << ( Vec_4<T> &vet, T dado ) {
	
	vet._x = dado;
	
	return vet;
}
/*===============================================================================================================================*/
template <class T>	
Vec_4<T>& operator , ( Vec_4<T> &vet, T dado ) {
	static size_t indice   = 1;
	static auto   id_vetor = &vet;
	
	if ( id_vetor != &vet ) {
		indice = 1;
		id_vetor = &vet;
	}
	
	switch ( indice ) {
		case 1: vet._y = dado; indice++  ; break;
		case 2: vet._z = dado; indice++  ; break;
		case 3: vet._w = dado; indice = 1; break;
		default: break;
	}
	
	return vet;
}
/*===============================================================================================================================*/
template <class T>
std::ostream& operator << (std::ostream &os, const Vec_4<T> &v ) {
	return os << "[ " << v._x << ", " << v._y << ", " << v._z << ", " << v._w << " ]";
}
/*===============================================================================================================================*/
template <class T> Vec_4<T> operator + ( const Vec_3<T> &v3, const Vec_4<T> &v4 )
{
	return Vec_4<T>( v3._x + v4._x, v3._y + v4._y, v3._z + v4._z, v4._w );
}
/*===============================================================================================================================*/
template <class T> Vec_4<T> operator - ( const Vec_3<T> &v3, const Vec_4<T> &v4 )
{
	return Vec_4<T>( v3._x - v4._x, v3._y - v4._y, v3._z - v4._z, v4._w );
}
/*===============================================================================================================================*/
template <class T> Vec_4<T> operator * ( const Vec_3<T> &v3, const Vec_4<T> &v4 )
{
	return Vec_4<T>( v3._x * v4._x, v3._y * v4._y, v3._z * v4._z, v4._w );
}
/*===============================================================================================================================*/


}

#endif
