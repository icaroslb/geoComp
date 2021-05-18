template <class T>
Camera<T>::Camera ( Vec_3<T> posicao, Vec_3<T> lookAt, Vec_3<T> viewUp, T esq, T dir, T baixo, T cima, T near, T far, int tipo,  T velocidade )
: _camera_posicao( posicao )
, _look_at( lookAt )
, _view_up( viewUp )
, _projecao( Matriz_tipo::ZEROS )
, _velocidade_camera( velocidade )
, _dir( dir )
, _esq( esq )
, _baixo( baixo )
, _cima( cima )
, _near( near )
, _far( far )
, _tipo( tipo )
{
	atualizar_matriz ( tipo );
}
/*===============================================================================================================================*/
template <class T>
Matriz_4<T> Camera<T>::gerar_matriz_camera ()
{
	return look_at( _camera_posicao, ( _look_at + _camera_posicao ), _view_up );
}
/*===============================================================================================================================*/
template <class T>
Matriz_4<T> Camera<T>::obter_matriz_projecao ()
{
	return _projecao;
}
/*===============================================================================================================================*/
template <class T>
Vec_3<T> Camera<T>::obter_posicao_camera ()
{
	return _camera_posicao;
}
/*===============================================================================================================================*/
template <class T>
void Camera<T>::andar_frente ()
{
	_camera_posicao += _look_at * _velocidade_camera;
}
/*===============================================================================================================================*/
template <class T>
void Camera<T>::andar_tras ()
{
	_camera_posicao -= _look_at * _velocidade_camera;
}
/*===============================================================================================================================*/
template <class T>
void Camera<T>::andar_direita ()
{
	_camera_posicao += unitario( produto_vetorial( _look_at, _view_up ) ) * _velocidade_camera;
}
/*===============================================================================================================================*/
template <class T>
void Camera<T>::andar_esquerda ()
{
	_camera_posicao -= unitario( produto_vetorial( _look_at, _view_up ) ) * _velocidade_camera;
}
/*===============================================================================================================================*/
template <class T>
void Camera<T>::atualizar_matriz ( int tipo )
{
	switch (tipo) {
	case ORTHO:
		_projecao( 0, 0 ) =   T(2.0) / ( _dir - _esq );
		_projecao( 1, 1 ) =   T(2.0) / ( _cima- _baixo );
		_projecao( 2, 2 ) = - T(2.0) / ( _far - _near );
		_projecao( 3, 0 ) = - ( _dir + _esq ) / ( _dir - _esq );
		_projecao( 3, 1 ) = - ( _cima + _baixo ) / ( _cima - _baixo );
		_projecao( 3, 2 ) = - ( _far + _near ) / ( _far - _near );
		_projecao( 3, 3 ) =   T(1);
	break;
	case FRUSTUM:
		_projecao( 0, 0 ) =   ( T(2.0) * _near ) / ( _dir - _esq );
		_projecao( 1, 1 ) =   ( T(2.0) * _near ) / ( _cima- _baixo );
		_projecao( 2, 0 ) =   ( _dir + _esq ) / ( _dir - _esq );
		_projecao( 2, 1 ) =   ( _cima + _baixo ) / ( _cima - _baixo );
		_projecao( 2, 2 ) = - ( _far + _near ) / ( _far - _near );
		_projecao( 2, 3 ) = - T(1);
		_projecao( 3, 2 ) = - ( T(2.0) * _far * _near ) / ( _far - _near );
	break;
	}
}
/*===============================================================================================================================*/
template <class T>
void Camera<T>::redmensionar_camera ( const Vec_2<T> &vetor_distancia, T valor_distancia )
{
	Vec_2<T> vetor_valor_distancia = unitario( vetor_distancia ) * valor_distancia;
	
	
	if ( std::abs( vetor_valor_distancia._x ) > T(0) ) {
		T horizontal = _dir - _esq,
		  vertical = _cima - _baixo,
		  //prop_horizontal = horizontal / vetor_distancia._x,
		  nova_horizontal = ( horizontal * valor_distancia ) / norma( vetor_distancia ),
		  nova_vertical = ( vertical * valor_distancia ) / norma( vetor_distancia );
		
		_dir = nova_horizontal / T(2);
		_esq = -_dir;
		_cima = nova_vertical / T(2);
		_baixo = -_cima;
	} else if ( std::abs( vetor_valor_distancia._y ) > T(0) ) {
		T horizontal = _dir - _esq,
		  vertical = _cima - _baixo,
		  prop_vertical = vertical / vetor_distancia._y,
		  nova_vertical = prop_vertical * vetor_valor_distancia._y,
		  nova_horizontal = ( horizontal / vertical ) * prop_vertical;
		
		_dir = nova_horizontal / T(2);
		_esq = -_dir;
		_cima = nova_vertical / T(2);
		_baixo = -_cima;
	}

	  atualizar_matriz( _tipo );
}
/*===============================================================================================================================*/
/*void Camera::rodar ( glm::vec3 ponto_rotacao, glm::vec3 vetor, float angulo )
{
	vetor = glm::normalize( vetor );
	glm::tquat<float> quaternio = glm::angleAxis( angulo, vetor ),
	          conjugado = glm::conjugate( quaternio );
	camera_posicao = ( quaternio * glm::vec4( ( camera_posicao - ponto_rotacao ), 1.0 ) * conjugado ) + glm::vec4( ponto_rotacao, 1.0 );
	look_at = quaternio * glm::vec4( look_at, 0.0f ) * conjugado;
	view_up = quaternio * glm::vec4( view_up, 0.0f ) * conjugado;
}
/*===============================================================================================================================*/
/*void Camera::rodar ( glm::vec3 ponto_rotacao, float x, float y, float angulo )
{
	rodar( ponto_rotacao, ( view_up * x ) + ( glm::cross( look_at, view_up ) * y ), angulo );
}
/*===============================================================================================================================*/
/*void Camera::rodar ( glm::vec3 vetor, float angulo, float distancia )
{
	rodar( ( look_at * distancia ) + camera_posicao, vetor, angulo );
}
/*===============================================================================================================================*/
/*void Camera::rodar ( float x, float y, float angulo, float distancia )
{
	rodar( ( look_at * distancia ) + camera_posicao, ( view_up * x ) + ( glm::cross( look_at, view_up ) * y ), angulo );
}
/*===============================================================================================================================*/
template <class T>
Vec_2<T> Camera<T>::pick ( T x, T y, T janela_largura, T janela_altura )
{
	Vec_2<T> coord_camera;
	
	T tam_pix_x = ( _dir - _esq ) / janela_largura,
	  tam_pix_y = ( _cima - _baixo ) / janela_altura;
	
	y = janela_altura - y;
	
	coord_camera.x() = ( _esq + _camera_posicao.x() )   + ( tam_pix_x / T(2) ) + ( tam_pix_x * x );
	coord_camera.y() = ( _baixo + _camera_posicao.y() ) + ( tam_pix_y / T(2) ) + ( tam_pix_y * y );
	
	return coord_camera;
}
/*===============================================================================================================================*/
template <class T>
Vec_2<T> Camera<T>::relative_pick ( T x, T y, T janela_largura, T janela_altura )
{
	Vec_2<T> coord_camera;
	
	T tam_pix_x = ( _dir - _esq ) / janela_largura,
	  tam_pix_y = ( _cima - _baixo ) / janela_altura;
	
	coord_camera.x() = tam_pix_x *  x;
	coord_camera.y() = tam_pix_y * -y;
	
	return coord_camera;
}
/*===============================================================================================================================*/
template <class T>
Matriz_4<T> Camera<T>::look_at ( const Vec_3<T> &pos, const Vec_3<T> &olha, const Vec_3<T> &cima )
{
	Matriz_4<T> matriz_info( Matriz_tipo::IDENTIDADE );
	Matriz_4<T> matriz_movimento( Matriz_tipo::IDENTIDADE );
	
	const Vec_3<T> vetor_f    = ( pos - olha ),
	               unita_f    = unitario( vetor_f ),
	               unita_cima = unitario( cima ),
	               direita    = produto_vetorial( unita_f, unita_cima ),
	               vetor_cima = produto_vetorial( unitario( direita ), unita_f );
	
	matriz_movimento( 0, 0 ) =  direita.x();
	matriz_movimento( 0, 1 ) =  direita.y();
	matriz_movimento( 0, 2 ) =  direita.z();
	
	matriz_movimento( 1, 0 ) =  vetor_cima.x();
	matriz_movimento( 1, 1 ) =  vetor_cima.y();
	matriz_movimento( 1, 2 ) =  vetor_cima.z();
	
	matriz_movimento( 2, 0 ) = -unita_f.x();
	matriz_movimento( 2, 1 ) = -unita_f.y();
	matriz_movimento( 2, 2 ) = -unita_f.z();
	
	matriz_info( 0, 3 ) = -olha.x();
	matriz_info( 1, 3 ) = -olha.y();
	matriz_info( 2, 3 ) = -olha.z();
	
	return matriz_movimento * matriz_info;
}
/*===============================================================================================================================*/