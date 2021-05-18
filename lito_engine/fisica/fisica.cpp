template <class T>
bool teste_colisao ( const Vec_2<T> &p_1_1, const Vec_2<T> &p_1_2
                   , const Vec_2<T> &p_2_1, const Vec_2<T> &p_2_2
                   , const Vec_2<T> &normal, T &dist )
{
	const Vec_2<T> v_1 = p_1_2 - p_1_1;
	const Vec_2<T> v_2 = p_2_2 - p_2_1;

	const T valor_1 = produto_vetorial( v_1, p_2_1 - p_1_1 ) * produto_vetorial( v_1, p_2_2 - p_1_1 );
	const T valor_2 = produto_vetorial( v_2, p_1_1 - p_2_1 ) * produto_vetorial( v_2, p_1_2 - p_2_1 );

	if ( valor_1 <= T(0) && valor_2 <= T(0) ){
		dist = produto_escalar( p_2_1 - p_1_1, normal ) / produto_escalar( v_1, normal );

		return true;
	} else {
		return false;
	}
}
/*===============================================================================================================================*/
#if 0
template <class T>
bool teste_colisao ( const AABB_2d<T> &aabb_1, const AABB_2d<T> &aabb_2 )
{
	T teste_x = T( fabs( aabb_1._pos._x - aabb_2._pos._x ) );
	T teste_y = T( fabs( aabb_1._pos._y - aabb_2._pos._y ) );

	if ( teste_x > aabb_1._largura + aabb_2._largura
	||   teste_y > aabb_1._altura  + aabb_2._altura  )
		return false;
	else
		return true;
}
/*===============================================================================================================================*/
template <class T>
bool teste_colisao ( const Circulo_2d<T> &circ_1, const Circulo_2d<T> &circ_2 )
{
	T teste = norma( circ_1._pos - circ_2._pos );

	if ( teste > circ_1._raio + circ_2._raio )
		return false;
	else
		return true;
}
/*===============================================================================================================================*/
template <class T>
bool teste_colisao ( const AABB_2d<T> &aabb, const Circulo_2d<T> &circ )
{
	Vec_2<T> v_projetado;
	Vec_2<T> vetor_dist = circ._pos - aabb._pos;

	T raio_quadrado = circ._raio * circ._raio;

	for ( int i = 0; i < 4; i++ ) {
		v_projetado = projecao_inv( vetor_dist, aabb._array_vec[( i + 1) % 4] - aabb._array_vec[i] );
					  
		if ( raio_quadrado <= norma_quadrada( aabb._array_vec[i] + v_projetado - circ._pos ) )
			return true;
	}

	return false;
}
/*===============================================================================================================================*/
template <class T>
bool teste_colisao ( const Circulo_2d<T> &circ, const AABB_2d<T> &aabb )
{
	return teste_colisao( aabb, circ );
}
/*===============================================================================================================================*/
template <class T>
bool teste_colisao ( const AABB_2d<T> &aabb, const Vec_2<T> &pos )
{
	T x = T( fabs( aabb._pos._x - pos._x ) );
	T y = T( fabs( aabb._pos._y - pos._y ) );

	if ( x > aabb._largura
	||   y > aabb._altura )
		return false;
	else
		return true;
}
/*===============================================================================================================================*/
template <class T>
bool teste_colisao ( const Circulo_2d<T> &circ, const Vec_2<T> &pos )
{
	T raio_quadrado = circ._raio * circ._raio;
	T dist_quadrada = norma_quadrada( circ._pos - pos );
	
	if ( dist_quadrada > raio_quadrado )
		return false;
	else
		return true;
}
#endif
/*===============================================================================================================================*/
template <class T>
bool teste_colisao ( Poligono_convexo_2d<T> *p_1, Poligono_convexo_2d<T> *p_2 )
{
	int qtd_eixo_1 = p_1->quantidade_eixos();
	int qtd_eixo_2 = p_2->quantidade_eixos();

	Vec_2<T> eixo;

	if ( qtd_eixo_1 > 0 && qtd_eixo_2 > 0 ) {

		for ( int i = 0; i < qtd_eixo_1; i++ ) {
			eixo = p_1->eixo( i );

			Vec_2<T> p_1_projetado = p_1->projetar_eixo( eixo );
			Vec_2<T> p_2_projetado = p_2->projetar_eixo( eixo );

			if ( p_1_projetado._x > p_2_projetado._y
			||   p_1_projetado._y < p_2_projetado._x ) {
				return false;
			}
		}

		return true;

	} else {
		if ( qtd_eixo_1 == 0 && qtd_eixo_2 == 0 ) {
			
			Circulo_2d<T> circulo_1 = (Circulo_2d<T>*)p_1;
			Circulo_2d<T> circulo_2 = (Circulo_2d<T>*)p_2;

			eixo = circulo_2->pontos[0] - circulo_1->pontos[0];

			if ( norma( eixo ) > circulo_1->raio + circulo_2->raio )
				return false;
			else
				return true;

		} else {
			
			Circulo_2d<T> circulo;
			Poligono_convexo_2d<T> *n_circulo;
			bool n_dentro = false;

			if ( qtd_eixo_1 == 0 ) {
				circulo = (Circulo_2d<T>*)p_1;
				n_circulo = p_2;
			} else {
				circulo = (Circulo_2d<T>*)p_2;
				n_circulo = p_1;
			}

			T raio_quadrado = circulo->raio * circulo->raio;

			for ( int i = 0; i < qtd_eixo_1; i++ ) {
				eixo = p_1->eixo( i );

				Vec_2<T> p_c_projetado = circulo->projetar_eixo( eixo );

				if ( p_c_projetado._y < T(0)
				&&   norma_quadrada( eixo * p_c_projetado._x ) <= raio_quadrado )
					return true;
				else if ( p_c_projetado._y > T(4) ) {
					n_dentro = true;
				
			}

			if ( n_dentro )
				return false;
			else
				return true;

		}
	}
}
/*===============================================================================================================================*/
template <class T>
bool teste_colisao ( Poligono_convexo_2d<T> *p, const Vec_2d<T> &ponto )
{
	int qtd_eixos = p->quantidade_eixos();
	Vec_2<T> eixo;

	if ( qtd_eixos > 0 ) {
		
		for ( int i = 0; i < qtd_eixo; i++ ) {
			eixo = p->eixo( i );

			if ( pseudoangulo( eixo, ponto - p->pontos[i] ) < T(4) )
				return false;
		}

		return true;

	} else {

		Circulo_2d<T> *circulo = (Circulo_2d<T>*)p;
		T raio_quadrado = circulo->raio * circulo->raio;

		if ( raio_quadrado < norma_quadrada( ponto - circulo->pontos[0] ) )
			return false;
		else
			return true;

	}
}
/*===============================================================================================================================*/
template <class T>
Vec_2<T> colisao ( const Vec_2<T> &v, const Vec_2<T> &normal, T alfa, T beta )
{
	const Vec_2<T> vn = -projecao_unitario( v, normal ),
	               vp =  v + vn;
	return ( alfa * vp ) + ( beta * vn );
}
/*===============================================================================================================================*/
template <class T>
Vec_3<T> colisao ( const Vec_3<T> &v, const Vec_3<T> &normal, T alfa, T beta )
{
	const Vec_3<T> vn = -projecao_unitario( v, normal ),
	               vp =  v + vn;
	return ( alfa * vp ) + ( beta * vn );
}
/*===============================================================================================================================*/
template <class T>
Vec_4<T> colisao ( const Vec_4<T> &v, const Vec_4<T> &normal, T alfa, T beta )
{
	const Vec_4<T> vn = -projecao_unitario( v, normal ),
	               vp =  v + vn;
	return ( alfa * vp ) + ( beta * vn );
}
/*===============================================================================================================================*/
