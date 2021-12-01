
#include "maquina.hpp"
#include <fstream>
#include <vector>

using namespace std;


void rellenar_maquinas( vector< Maquina > &maquinas ){

string nombrefichero = "maquinas.txt";
string cluster, maquina, cpu_maquina, cpu_disponible;
ifstream fichero;
fichero.open( nombrefichero, ifstream::in );

if( fichero.is_open() == false ){
	
	cout << "error al abrir el archivo de maquinas.txt" << endl;
	abort();
	}
Maquina aux;
while( !fichero.eof() ){
	
	fichero >> cluster;
	fichero >> maquina;
	fichero >> cpu_maquina;
	fichero >> cpu_disponible;

	aux.modificar_cpu_disp( stoi( cpu_disponible ) );
	aux.modificar_cpu_maquina( stoi( cpu_maquina ) );
	aux.modificar_cluster( stoi( cluster ) );
	aux.modificar_id_maquina( stoi( maquina ) );
	
	maquinas.push_back( aux );	
	
	}
fichero.close();
}



void volcar_maquinas_fichero( vector<Maquina> maquinas ){

string nombrefichero = "maquinas.txt";
ofstream fichero;
fichero.open( nombrefichero, ofstream::out );

if( fichero.is_open() == false ){

	cout << "el fichero maquinas.txt no se pudo abrir correctamente" << endl;
	abort();
	}
for( size_t i = 0; i < maquinas.size() -1; i++ ){
	
	fichero << maquinas[i].getCluster_id() << " " << maquinas[i].getMaquina_id() << " " << maquinas[i].getCpu_maquina() << " " << maquinas[i].getCpu_disponible() << endl ;
	}
fichero.close();

}







