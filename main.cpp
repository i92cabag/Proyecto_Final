
#include "maquina.hpp"
#include "cluster.hpp"

#include <iostream>
#include <vector>

using namespace std;


int main(){

	cout << "Bienvenido al software de reserva de maquinas de la Universidad de Cordoba" << endl;
	cout << endl;

vector< Maquina > maquinas;
rellenar_maquinas( maquinas );

remove("maquinas.txt");
remove("reservas.txt");
remove("usuarios.txt");

for( size_t i = 0; i < maquinas.size(); i++  ){

	cout << "Maquina: " << i << endl;
	cout << "id_cluster: " << maquinas[i].getCluster_id() << " id_maquina: " << maquinas[i].getMaquina_id() << " Cpu de la maquina: " << maquinas[i].getCpu_maquina() << " Cpu disponible: " << maquinas[i].getCpu_disponible() << endl ;	
	}

vector< Usuario > usuarios;
rellenar_usuarios( usuarios );

vector< Reserva > reservas;
rellenar_reservas( reservas );






volcar_maquinas_fichero( maquinas );

volcar_usuarios_fichero( usuarios );

volcar_reservas_fichero( reservas );

}


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

	aux.cambiar_id( idUsuario );
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
for( size_t i = 0; i < usuarios.size() -1; i++ ){
	
	fichero << usuarios[i].get_id() << " " << usuarios[i].get_nombre << " " << usuarios[i].get_contraseña << " " <<  usuarios[i].get_email() << " " << usuarios[i].get_departamento() << " " << usuarios[i].get_lim_reservas() << " " << usuarios[i].get_lim_cpu() << endl;
	}
fichero.close();

}



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







