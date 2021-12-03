#ifndef reserva_hpp
#define reserva_hpp

#include <iostream>
#include <vector>

using namespace std;

class Reserva {

	private:

		string fecha_inicio;
		string fecha_final;
		int maquina_reserva;
		int usuario_reserva;
		string motivo_reserva;

	public:

		inline string get_fecha_inicio() {
			return fecha_inicio;
		}
		inline string get_fecha_final() {
			return fecha_final;
		}
		inline int get_maquina_reserva() {
			return maquina_reserva;
		}
		inline int get_usuario_reserva() {
			return usuario_reserva;
		}
		inline string get_motivo_reserva() {
			return motivo_reserva;
		}
		inline void modificar_fecha_inicio( string nueva_fecha_inicio ) {
			fecha_inicio = nueva_fecha_inicio;
		}
		inline void modificar_fecha_final ( string nueva_fecha_final ) {
			fecha_final = nueva_fecha_final;
		}
		inline void modificar_maquina_reserva (int nueva_maquina_reserva ) {
			maquina_reserva = nueva_maquina_reserva;
		}
		inline void modificar_usuario_reserva ( int nuevo_usuario_reserva ) {
			usuario_reserva = nuevo_usuario_reserva;
		}
		inline void modificar_motivo_reserva ( string nuevo_motivo_reserva ) {
			motivo_reserva = nuevo_motivo_reserva;
		}
};

#endif
