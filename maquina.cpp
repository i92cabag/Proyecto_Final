
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
	
for( size_t i = 0; i < maquinas.size() ; i++ ){
	
	fichero << maquinas[i].getCluster_id() << " " << maquinas[i].getMaquina_id() << " " << maquinas[i].getCpu_maquina() << " " << maquinas[i].getCpu_disponible() << endl ;
	}
fichero.close();

}



void mostrar_maquinas_disponibles( vector<Maquina> maquinas ){

for( size_t i = 0; i < maquinas.size(); i++ ){

	if( maquinas[i].getCpu_disponible() != 0 ){
		
		cout << endl;
		cout << "Maquina: " << maquinas[i].getMaquina_id() << " del cluster: " << maquinas[i].getCluster_id() << " tiene: " << maquinas[i].getCpu_disponible() << " unidades de cpu disponibles" << endl;
		}
	}
}


bool modificar_maquina( vector<Maquina> &maquinas, int maquina, int cantidad_cpu ){

for( size_t i = 0; i < maquinas.size(); i++ ){

	if( maquinas[i].getMaquina_id() == maquina ){
		
		if( maquinas[i].getCpu_disponible() >= cantidad_cpu ){
		
			maquinas[i].modificar_cpu_disp( maquinas[i].getCpu_disponible() - cantidad_cpu );
			return true;
			}
		return false;
		}
	}
return false;
}




void mostrar_maquinas_recomendadas( vector<Maquina> maquinas, int maquina, int cantidad_cpu ){

int cluster = get_cluster( maquinas, maquina);

for( size_t i = 0; i < maquinas.size(); i++ ){

	if( maquinas[i].getCluster_id() == cluster && maquinas[i].getCpu_disponible() >= cantidad_cpu ){
	
		cout << endl;
		cout << "Maquina: " << maquinas[i].getMaquina_id() << " del cluster: " << maquinas[i].getCluster_id() << " tiene: " << maquinas[i].getCpu_disponible() << " unidades de cpu disponibles" << endl;
		}
	}
}



bool maquina_existe( vector<Maquina> maquinas, int maquina ){

for( size_t i = 0; i < maquinas.size(); i++ ){

	if( maquinas[i].getMaquina_id() == maquina ){
		
		return true;
		}
	}
return false;

}


int get_cluster(vector<Maquina> maquinas, int maquina){

for( size_t i = 0; i < maquinas.size(); i++ ){

	if( maquinas[i].getMaquina_id() == maquina ){
	
		return maquinas[i].getCluster_id();
		}
	}	
}





