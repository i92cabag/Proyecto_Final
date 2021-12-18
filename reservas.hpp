


#ifndef reserva_hpp
#define reserva_hpp

#include <iostream>
#include <vector>

using namespace std;

class Reserva {

	private:

		int maquina_reserva;
		int usuario_reserva;
		int cantidad_reservada;
		string motivo_reserva;

	public:

		
		inline int get_maquina_reserva() {
			return maquina_reserva;
		}
		inline int get_usuario_reserva() {
			return usuario_reserva;
		}
		
		inline int get_cantidad_reserva(){		
			return cantidad_reservada;
		}		
		inline string get_motivo_reserva() {
			return motivo_reserva;
		}		
		inline void modificar_maquina_reserva (int nueva_maquina_reserva ) {
			maquina_reserva = nueva_maquina_reserva;
		}
		inline void modificar_usuario_reserva ( int nuevo_usuario_reserva ) {
			usuario_reserva = nuevo_usuario_reserva;
		}
		inline void modificar_cantidad_reservada( int nueva_cantidad ){
			cantidad_reservada = nueva_cantidad;		
		}
		inline void modificar_motivo_reserva ( string nuevo_motivo_reserva ) {
			motivo_reserva = nuevo_motivo_reserva;
		}
};

/**
@brief funcion que vuelca del fichero donde se guardan los datos de las reservas a un vector de reservas con el que se va a trabajar.
@param reservas el vector donde se van a guardar los datos de todas las reservas.
*/
void rellenar_reservas( vector< Reserva > &reservas );

/**
@brief funcion que devuelve el vector de reservas despues de haber trabajado con el al fichero de reservas para su futura lectura cuando se vuelva a abrir el programa.
@param reservas el vector del que se van a leer las reservas que se van a pasar al fichero.
*/
void volcar_reservas_fichero( vector<Reserva> reservas );

/**
@brief funcion que devuelve una reserva que ha rellenado el usuario.
@param maquinas vector de maquinas que se le va a mostrar al usuario para que elija una de ellas para su utilizacion.
@param usuarios vector de usuarios que se va a utilizar para comprobar que usuario realiza la reserva.
*/
Reserva rellenar_reserva( vector<Maquina> maquinas, vector<Usuario> usuarios );

/**
@brief funcion que muestra todas las reservas de un usuario.
@param codigo_usuario id del usuario del que se van a mostrar las reservas.
*/
void mostrar_reservas( vector<Reserva> reservas, int codigo_usuario );

/**
@brief funcion que muestra todas las reservas de un usuario.
*/
void mostrar_reservas( vector<Reserva> reservas );

/**
@brief funcion que comprueba que una maquina esta reservada o no por un usuario.
@param codigo_maquina id de la maquina de la que se va a comprobar si esta reservada o no por el usuario.
*/
bool comprobar_maquina_reservada( vector<Reserva> reservas, int codigo_usuario, int codigo_maquina );

/**
@brief funcion que elimina una reserva de un usuario.
*/
void eliminar_reserva_usuario( vector<Reserva> &reservas, vector<Maquina> &maquinas, int codigo_usuario, int codigo_maquina );

#endif


