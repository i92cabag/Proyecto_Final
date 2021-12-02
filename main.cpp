
#include "maquina.hpp"
#include "usuario.hpp"
#include "cluster.hpp"

#include <iostream>
#include <vector>

using namespace std;


int main(){

	cout << "Bienvenido al software de reserva de maquinas de la Universidad de Cordoba" << endl;
	cout << endl;

vector< Maquina > maquinas;
rellenar_maquinas( maquinas );
maquinas.resize( maquinas.size() - 1 );

vector< Usuario > usuarios;
rellenar_usuarios( usuarios );
usuarios.resize( usuarios.size() - 1 );

for( size_t i = 0; i < usuarios.size(); i++  ){

	cout << "Usuario: " << i << endl;
	cout << "Usuario id: " <<usuarios[i].get_id() << "  Usuario nombre: " << usuarios[i].get_nombre() << "  Usuario contraseña: " << usuarios[i].get_contrasena() << "  Usuario email: " <<  usuarios[i].get_email() << "  Usuario departamento: " << usuarios[i].get_departamento() << " Usuario limite res: " << usuarios[i].get_lim_reservas() << "  Usuario limite cpu: " << usuarios[i].get_lim_cpu() << endl;
	
	}

//vector< Reserva > reservas;
//rellenar_reservas( reservas );

remove("maquinas.txt");
remove("usuarios.txt");

do{

	cout << "Seleccinoa si eres un investigador o un administrador: " << endl;
	cout << endl;
	cout << "1. Investigador" << endl;
	cout << "2. Administrador" << endl;

	int estado;
	cin >> estado;
	if( estado != 1 || estaddo != 2 ){
	
		cout << "Selecciona una de las dos opciones." << endl;
		}
	}while( estado != 1 || estado != 2 );
	
if( estado == 1 ){

	cout << "Bienvenido a tu zona de trabajo investigador, selecciona que accion quieres llevar a cabo." << endl;
	
	cout << "1. realizar la reserva de una maquina" << endl;
	reserva();
	}

if( estado == 2 ){

	cout << "Bienvenido a tu zona de trabajo administrador, selecciona que accion quieres llevar a cabo." << endl;
	
	
	}


volcar_maquinas_fichero( maquinas );

volcar_usuarios_fichero( usuarios );

//volcar_reservas_fichero( reservas );

}




/*
void rellenar_reservas( vector< Maquina > &reservas ){

string nombrefichero = "reservas.txt";
string usuario_id, maquina, cpu_reservada, descripcion;
ifstream fichero;
fichero.open( nombrefichero, ifstream::in );

if( fichero.is_open() == false ){
	
	cout << "error al abrir el archivo de reservas.txt" << endl;
	abort();
	}
Maquina aux;
while( !fichero.eof() ){
	
	fichero >> usuario_id;
	fichero >> maquina;
	fichero >> cpu_reservada;
	getline( fichero, descripcion );
	
	aux.cambiar_usuario_id( stoi( usuario_id) );
	aux.cambiar_maquina( stoi( maquina ) );
	aux.cambiar_cpu_reservada( stoi( cpu_reservada ) );
	aux.cambiar_descripcion( descripcion );
	
	reservas.push_back( aux );	
	
	}
fichero.close();
}


void volcar_reservas_fichero( vector<Reserva> reservas ){

string nombrefichero = "reservas.txt";
ofstream fichero;
fichero.open( nombrefichero, ofstream::out );

if( fichero.is_open() == false ){

	cout << "el fichero reservas.txt no se pudo abrir correctamente" << endl;
	abort();
	}
for( size_t i = 0; i < maquinas.size() -1; i++ ){
	
	fichero << reservas[i].get_usuarioid() << " " << reservas[i].get_maquina() << " " << reservas[i].get_cantidad_reservada() << endl;
	fichero << reservas[i].get_descripcion() << endl;
	}
fichero.close();


}

*/





