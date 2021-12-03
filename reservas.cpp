#include "reservas.hpp"
#include <fstream>
#include <vector>

using namespace std;


void rellenar_reservas( vector< Reserva > &reversas ){

	string nombrefichero = "reservas.txt";
	string f_inicio, f_final, maquina_reservada, nombre_usuario, motivo ;
	ifstream fichero;
	fichero.open( nombrefichero, ifstream::in );

	if( fichero.is_open() == false ){

		cout << "Error al abrir el archivo de reservas.txt" << endl;
		abort();
	}

	Reserva aux;
	while( !fichero.eof() ){

		fichero >> f_inicio;
		fichero >> f_final;
		fichero >> maquina_reservada;
		fichero >> nombre_usuario;
		fichero >> motivo;

		aux.modificar_fecha_inicio( stoi( f_inicio ) );
		aux.modificar_fecha_final( stoi( f_final ) );
		aux.modificar_maquina_reserva( stoi( maquina_reservada ) );
		aux.modificar_usuario_reserva( stoi( nombre_usuario ) );
		aux.modificar_motivo_reserva( stoi( motivo ) );

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

		fichero << reservas[i].get_fecha_inicio() << " " << reservas[i].get_fecha_final() << " " << reservas[i].get_maquina_reserva() << " " << reservas[i].get_usuario_reserva() << reservas[i].get_motivo_reserva() << " " << endl ;
		}
	fichero.close();

}
