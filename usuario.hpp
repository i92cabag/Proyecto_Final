

#ifndef usuario_hpp
#define usuario_hpp

#include <iostream>
#include <vector>

using namespace std;

class Usuario{

	private:

		int usuario_id;
		string nombre_us;
		string contrasena_us;
		string email_us;
		string departamento_us;
		int lim_reservas_us;
		int lim_cpu_us;


	public:

		inline int get_id(){

					return usuario_id;
				}

		inline string get_nombre(){

					return nombre_us;
				}

		inline string get_contrasena(){

					return contrasena_us;
				}

		inline string get_email(){

					return email_us;
				}

		inline string get_departamento(){

					return departamento_us;
				}

		inline int get_lim_reservas(){

					return lim_reservas_us;
				}

		inline int get_lim_cpu(){

					return lim_cpu_us;
				}

		inline void cambiar_id( int nueva_id ){

					usuario_id = nueva_id;
				}

		inline void cambiar_nombre( string nuevo_nombre ){

					nombre_us = nuevo_nombre;
				}
			
		inline void cambiar_contrasena( string nueva_contrasena ){
		
					contrasena_us = nueva_contrasena;
				}

		inline void cambiar_email( string nuevo_email ){

					email_us = nuevo_email;
				}

		inline void cambiar_departamento( string nuevo_departamento ){

					departamento_us = nuevo_departamento;
				}
		
		inline void cambiar_lim_reservas( int nuevo_lim_reservas ){

					lim_reservas_us = nuevo_lim_reservas;
				}

		inline void cambiar_lim_cpu( int nuevo_lim_cpu ){

					lim_cpu_us = nuevo_lim_cpu;
				}


};

void rellenar_usuarios( vector< Usuario > &usuarios );

void volcar_usuarios_fichero( vector< Usuario > usuarios );

bool usuario_existe( vector<Usuario> usuarios, int usuario );


#endif



