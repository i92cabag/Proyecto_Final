

#include "usuario.hpp"
#include <fstream>
#include <vector>

using namespace std;


void rellenar_usuarios( vector< Usuario > &usuarios ){

string nombrefichero = "usuarios.txt";
string idUsuario, nombre, contrasena, email, departamento, lim_reservas, lim_cpu;
ifstream fichero;
fichero.open( nombrefichero, ifstream::in );

if( fichero.is_open() == false ){
	
	cout << "error al abrir el archivo de usuarios.txt" << endl;
	abort();
	}
Usuario aux;
while( !fichero.eof() ){
	
	fichero >> idUsuario;
	fichero >> nombre;
	fichero >> contrasena;
	fichero >> email;
	fichero >> departamento;
	fichero >> lim_reservas;
	fichero >> lim_cpu;

	aux.cambiar_id( stoi( idUsuario) );
	aux.cambiar_nombre( nombre );
	aux.cambiar_contrasena( contrasena );
	aux.cambiar_email( email );
	aux.cambiar_departamento( departamento );
	aux.cambiar_lim_reservas( stoi( lim_reservas ) );
	aux.cambiar_lim_cpu( stoi(lim_cpu) );
	
	usuarios.push_back( aux );	
	
	}
fichero.close();
}


void volcar_usuarios_fichero( vector<Usuario> usuarios ){

string nombrefichero = "usuarios.txt";
ofstream fichero;
fichero.open( nombrefichero, ofstream::out );

if( fichero.is_open() == false ){

	cout << "el fichero usuarios.txt no se pudo abrir correctamente" << endl;
	abort();
	}
for( size_t i = 0; i < usuarios.size(); i++ ){
	
	fichero << usuarios[i].get_id() << " " << usuarios[i].get_nombre() << " " << usuarios[i].get_contrasena() << " " <<  usuarios[i].get_email() << " " << usuarios[i].get_departamento() << " " << usuarios[i].get_lim_reservas() << " " << usuarios[i].get_lim_cpu() << endl;
	}
fichero.close();

}




bool usuario_existe( vector<Usuario> usuarios, int usuario ){

for( size_t i = 0; i < usuarios.size(); i++ ){

	if( usuarios[i].get_id() == usuario ){
	
		return true;
		}
	}
return false;
}





