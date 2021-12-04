
#include "maquina.hpp"
#include "usuario.hpp"
#include "reservas.hpp"
#include "cluster.hpp"

#include <iostream>
#include <vector>

using namespace std;


void reserva_maquina( vector<Maquina> &maquinas, vector<Reserva> &reservas, vector<Usuario> usuarios ){

cout << "Las maquinas disponibles actualmente son las siguientes: " << endl;
mostrar_maquinas_disponibles( maquinas );
cout << endl;
cout << "Rellene los datos de la reserva que quiere llevar a cabo: " << endl;
Reserva aux = rellenar_reserva( maquinas, usuarios );
if( modificar_maquina( maquinas, aux.get_maquina_reserva(), aux.get_cantidad_reserva() ) == true ){

	reservas.push_back( aux );
	cout << "Reserva realizada" << endl;
	}
else{

	cout << "La reserva no se pudo completar debido a que exige una mayor cantidad de cpu que la que la maquina tiene disponible." << endl;
	cout << "Se le recomiendan las siguientes maquinas: " << endl;
	 
	mostrar_maquinas_recomendadas( maquinas, aux.get_maquina_reserva(), aux.get_cantidad_reserva() );
	}

}


int main(){

	cout << "Bienvenido al software de reserva de maquinas de la Universidad de Cordoba" << endl;
	cout << endl;

vector< Maquina > maquinas;
rellenar_maquinas( maquinas );
maquinas.resize( maquinas.size() - 1 );

vector< Usuario > usuarios;
rellenar_usuarios( usuarios );
usuarios.resize( usuarios.size() - 1 );

vector< Reserva > reservas;
rellenar_reservas( reservas );
reservas.resize( reservas.size() - 1 );

int estado;
do{

	cout << "Selecciona si eres un investigador o un administrador: " << endl;
	cout << endl;
	cout << "1. Investigador" << endl;
	cout << "2. Administrador" << endl;
	cout << "3. salir del sistema" << endl;

	cin >> estado;
	if( estado < 1 || estado > 3 ){
	
		cout << endl;
		cout << "Selecciona una de las dos opciones." << endl;
		}
	}while( estado < 1 || estado > 3 );
	
if( estado == 1 ){

	cout << "Bienvenido a tu zona de trabajo investigador, selecciona que accion quieres llevar a cabo." << endl;
	cout << endl;
	cout << "1. realizar la reserva de una maquina" << endl;
	
	int accion;
	
	cin >> accion;
	
	switch(accion){
	
		case 1:
			reserva_maquina( maquinas, reservas, usuarios );
		
		}
	}

if( estado == 2 ){

	cout << "Bienvenido a tu zona de trabajo administrador, selecciona que accion quieres llevar a cabo." << endl;
	
	
	}

remove("maquinas.txt");
remove("usuarios.txt");
remove("reservas.txt");

volcar_maquinas_fichero( maquinas );

volcar_usuarios_fichero( usuarios );

volcar_reservas_fichero( reservas );

}



