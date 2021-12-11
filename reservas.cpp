

#include "maquina.hpp"
#include "usuario.hpp"
#include "reservas.hpp"
#include <fstream>
#include <vector>

using namespace std;


void rellenar_reservas( vector< Reserva > &reservas ){

	string nombrefichero = "reservas.txt";
	string maquina_reservada, nombre_usuario, cantidad_reservada, motivo ;
	ifstream fichero;
	fichero.open( nombrefichero, ifstream::in );

	if( fichero.is_open() == false ){

		cout << "Error al abrir el archivo de reservas.txt" << endl;
		abort();
	}

	Reserva aux;
	while( !fichero.eof() ){

		fichero >> nombre_usuario;
		fichero >> maquina_reservada;
		fichero >> cantidad_reservada;
		fichero >> motivo;
		
		aux.modificar_maquina_reserva( stoi( maquina_reservada ) );
		aux.modificar_usuario_reserva( stoi( nombre_usuario ) );
		aux.modificar_cantidad_reservada( stoi( cantidad_reservada ) );
		aux.modificar_motivo_reserva( motivo );

		reservas.push_back( aux );

	}
	
fichero.close();
}



void volcar_reservas_fichero( vector<Reserva> reservas ){

	string nombrefichero = "reservas.txt";
	ofstream fichero;
	fichero.open( nombrefichero, ofstream::out );

	if( fichero.is_open() == false ){

		cout << "El fichero reservas.txt no se pudo abrir correctamente" << endl;
		abort();
	}

	for( size_t i = 0; i < reservas.size() ; i++ ) {

		fichero << reservas[i].get_usuario_reserva() << " " << reservas[i].get_maquina_reserva() << " " << reservas[i].get_cantidad_reserva() << " " << reservas[i].get_motivo_reserva() << endl;
		}
	fichero.close();

}


Reserva rellenar_reserva( vector<Maquina> maquinas, vector<Usuario> usuarios ){

int maquina, usuario, cantidad_cpu;
string descripcion;
Reserva aux;

cout << "Indique la maquina que quiere reservar: " << endl;
cin >> maquina;
while( !maquina_existe( maquinas, maquina ) ){

	cout << "Indique una maquina existente en el sistema" << endl;
	cin >> maquina;
	}
	
cout << "Indique el id_usuario que realiza la reserva:" << endl;
cin >> usuario;
while( !usuario_existe( usuarios, usuario ) ){

	cout << "Indique un id_usuario que exista en el sistema " << endl;
	cin >> usuario;
	}
	
cout << "indique la cantidad de cpu que quiere reservar de la maquina:" << endl;
cin >> cantidad_cpu;
while( cantidad_cpu < 1 || cantidad_cpu > 8 ){

	cout << "la cantidad de cpu tiene que ser menor que 8 y mayor que 0" << endl;
	cin >> cantidad_cpu;
	}

cout << "Indique la descripcion de la reserva con una palabra: " << endl;
cin >> descripcion;

aux.modificar_maquina_reserva( maquina );
aux.modificar_usuario_reserva( usuario );
aux.modificar_cantidad_reservada( cantidad_cpu );
aux.modificar_motivo_reserva( descripcion );

return aux;

}



void mostrar_reservas( vector<Reserva> reservas, int codigo_usuario ){

cout << endl;
cout << "Las reservas del usuario " << codigo_usuario << " son:" << endl;
cout << endl;

for( size_t i = 0; i< reservas.size(); i++ ){
	
	if( reservas[i].get_usuario_reserva() == codigo_usuario ){
		
		cout << "Maquina reservada: " << reservas[i].get_maquina_reserva() << " Cantidad reservada: " << reservas[i].get_cantidad_reserva() << " por el siguiente motivo: " << reservas[i].get_motivo_reserva() << endl;
		cout << endl;
		}
	}
}


bool comprobar_maquina_reservada( vector<Reserva> reservas, int codigo_usuario, int codigo_maquina ){

for( size_t i = 0; i < reservas.size() ; i++ ){

	if( reservas[i].get_usuario_reserva() == codigo_usuario  &&  reservas[i].get_maquina_reserva() == codigo_maquina ){
	
		return true;
		}
	}
return false;
}



void eliminar_reserva_usuario( vector<Reserva> &reservas, vector<Maquina> &maquinas, int codigo_usuario, int codigo_maquina ){

int cantidad_cpu;

for( size_t i = 0; i < reservas.size(); i++ ){

	if( reservas[i].get_usuario_reserva() == codigo_usuario  &&  reservas[i].get_maquina_reserva() == codigo_maquina ){
		
		cantidad_cpu = reservas[i].get_cantidad_reserva();
		reservas.erase( reservas.begin() + i );
		break;
		}
	}

for( size_t i = 0; i < maquinas.size(); i++ ){

	if( maquinas[i].getMaquina_id() == codigo_maquina ){
	
		maquinas[i].modificar_cpu_disp( maquinas[i].getCpu_disponible() + cantidad_cpu );
		break;
		}
	}
}








