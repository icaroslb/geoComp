#ifndef VEC_2_H
#define VEC_2_H

#include <iostream>
#include <cstring>

namespace lito {

template <class T>
class Vec_2 {
public:

	union
	{
		T coord[2];
		struct { T _x, _y; };
	};
	
	Vec_2<T> ( T x = 0, T y = 0 );
	
	T&       x  ();
	const T& x  () const;
	T&       y  ();
	const T& y  () const;
	
	T&       operator [] ( int i );
	const T& operator [] ( int i ) const;
	
	Vec_2<T>  operator + ( const Vec_2<T> &v ) const;
	Vec_2<T>  operator - ( const Vec_2<T> &v ) const;
	Vec_2<T>  operator * ( const Vec_2<T> &v ) const;
	Vec_2<T>  operator + ( T c ) const;
	Vec_2<T>  operator - ( T c ) const;
	Vec_2<T>  operator * ( T c ) const;
	Vec_2<T>  operator / ( T c ) const;
	
	Vec_2<T>& operator  = ( const Vec_2<T> &v );
	Vec_2<T>& operator += ( const Vec_2<T> &v );
	Vec_2<T>& operator -= ( const Vec_2<T> &v );
	Vec_2<T>& operator *= ( const Vec_2<T> &v );
	Vec_2<T>& operator += ( T c );
	Vec_2<T>& operator -= ( T c );
	Vec_2<T>& operator *= ( T c );
	Vec_2<T>& operator /= ( T c );
};

typedef Vec_2<float>  Vec_2f;
typedef Vec_2<double> Vec_2d;

template <class T> Vec_2<T> operator + ( const Vec_2<T> &v );
template <class T> Vec_2<T> operator - ( const Vec_2<T> &v );
template <class T> Vec_2<T> operator + ( T c, const Vec_2<T> &v );
template <class T> Vec_2<T> operator - ( T c, const Vec_2<T> &v );
template <class T> Vec_2<T> operator * ( T c, const Vec_2<T> &v );
template <class T> Vec_2<T>& operator << ( Vec_2<T> &vet, T dado );
template <class T> Vec_2<T>& operator ,  ( Vec_2<T> &vet, T dado );
template <class T> std::ostream& operator << ( std::ostream &os, const Vec_2<T> &v );

/*********************************************************************************************************************************/
/*********************************************************************************************************************************/
/*********************************************************************************************************************************/
/*********************************************************************************************************************************/
/*********************************************************************************************************************************/

template <class T>
Vec_2<T>::Vec_2 ( T x, T y )
: _x( x )
, _y( y )
{}
/*===============================================================================================================================*/
template <class T>
T& Vec_2<T>::x () { return _x; }
/*===============================================================================================================================*/
template <class T>
const T& Vec_2<T>::x () const { return _x; }
/*===============================================================================================================================*/
template <class T>
T& Vec_2<T>::y () { return _y; }
/*===============================================================================================================================*/
template <class T>
const T& Vec_2<T>::y () const { return _y; }
/*===============================================================================================================================*/
template <class T>
T& Vec_2<T>::operator[] ( int i ) { return coord[i]; }
/*===============================================================================================================================*/
template <class T>
const T& Vec_2<T>::operator[] ( int i ) const { return coord[i]; }
/*===============================================================================================================================*/
template <class T>
Vec_2<T> Vec_2<T>::operator + ( const Vec_2<T> &v ) const
{
	return Vec_2<T>( _x + v._x, _y + v._y );
}
/*===============================================================================================================================*/
template <class T>
Vec_2<T> Vec_2<T>::operator - ( const Vec_2<T> &v ) const
{
	return Vec_2<T>( _x - v._x, _y - v._y );
}
/*===============================================================================================================================*/
template <class T>
Vec_2<T> Vec_2<T>::operator * ( const Vec_2<T> &v ) const
{
	return Vec_2<T>( _x * v._x, _y * v._y );
}
/*===============================================================================================================================*/
template <class T>
Vec_2<T> Vec_2<T>::operator + ( T c ) const
{
	return Vec_2<T>( _x + c, _y + c );
}
/*===============================================================================================================================*/
template <class T>
Vec_2<T> Vec_2<T>::operator - ( T c ) const
{
	return Vec_2<T>( _x - c, _y - c );
}
/*===============================================================================================================================*/
template <class T>
Vec_2<T> Vec_2<T>::operator * ( T c ) const
{
	return Vec_2<T>( _x * c, _y * c );
}
/*===============================================================================================================================*/
template <class T>
Vec_2<T> Vec_2<T>::operator / ( T c ) const
{
	c = T(1) / c;
	
	return Vec_2<T>( _x * c, _y * c );
}
/*===============================================================================================================================*/
template <class T>
Vec_2<T>& Vec_2<T>::operator = ( const Vec_2<T> &v )
{
	memcpy( coord, v.coord, sizeof(T) * 2 );
	
	return *this;
}
/*===============================================================================================================================*/
template <class T>
Vec_2<T>& Vec_2<T>::operator += ( const Vec_2<T> &v )
{
	_x += v._x;
	_y += v._y;
	
	return *this;
}
/*===============================================================================================================================*/
template <class T>
Vec_2<T>& Vec_2<T>::operator -= ( const Vec_2<T> &v )
{
	_x -= v._x;
	_y -= v._y;
	
	return *this;
}
/*===============================================================================================================================*/
template <class T>
Vec_2<T>& Vec_2<T>::operator *= ( const Vec_2<T> &v )
{
	_x *= v._x;
	_y *= v._y;
	
	return *this;
}
/*===============================================================================================================================*/
template <class T>
Vec_2<T>& Vec_2<T>::operator += ( T c )
{
	_x += c;
	_y += c;
	
	return *this;
}
/*===============================================================================================================================*/
template <class T>
Vec_2<T>& Vec_2<T>::operator -= ( T c )
{
	_x -= c;
	_y -= c;
	
	return *this;
}
/*===============================================================================================================================*/
template <class T>
Vec_2<T>& Vec_2<T>::operator *= ( T c )
{
	_x *= c;
	_y *= c;
	
	return *this;
}
/*===============================================================================================================================*/
template <class T>
Vec_2<T>& Vec_2<T>::operator /= ( T c )
{
	c = T(1) / c;
	
	_x *= c;
	_y *= c;
	
	return *this;
}
/*===============================================================================================================================*/
template <class T>
Vec_2<T> operator + ( const Vec_2<T> &v ) {
	return Vec_2<T>( +v._x, +v._y );
}
/*===============================================================================================================================*/
template <class T>
Vec_2<T> operator - ( const Vec_2<T> &v ) {
	return Vec_2<T>( -v._x , -v._y );
}
/*===============================================================================================================================*/
template <class T>
Vec_2<T> operator + ( T c, const Vec_2<T> &v ) {
	return Vec_2<T>( c + v._x, c + v._y );
}
/*===============================================================================================================================*/
template <class T>
Vec_2<T> operator - ( T c, const Vec_2<T> &v ) {
	return Vec_2<T>( c - v._x, c - v._y );
}
/*===============================================================================================================================*/
template <class T>
Vec_2<T> operator * ( T c, const Vec_2<T> &v ) {
	return Vec_2<T>( c * v._x, c * v._y );
}
/*===============================================================================================================================*/
template <class T>	
Vec_2<T>& operator << ( Vec_2<T> &vet, T dado ) {
	vet._x = dado;
	
	return vet;
}
/*===============================================================================================================================*/
template <class T>	
Vec_2<T>& operator , ( Vec_2<T> &vet, T dado ) {
	vet._y = dado;
	
	return vet;
}
/*===============================================================================================================================*/
template <class T>
std::ostream& operator << (std::ostream &os, const Vec_2<T> &v ) {
	return os << "[ " << v._x << ", " << v._y << " ]";
}
/*===============================================================================================================================*/


}

#endif
