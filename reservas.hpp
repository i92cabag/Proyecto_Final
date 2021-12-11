


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


void rellenar_reservas( vector< Reserva > &reservas );

void volcar_reservas_fichero( vector<Reserva> reservas );

Reserva rellenar_reserva( vector<Maquina> maquinas, vector<Usuario> usuarios );

void mostrar_reservas( vector<Reserva> reservas, int codigo_usuario );

bool comprobar_maquina_reservada( vector<Reserva> reservas, int codigo_usuario, int codigo_maquina );

void eliminar_reserva_usuario( vector<Reserva> &reservas, vector<Maquina> &maquinas, int codigo_usuario, int codigo_maquina );

#endif


