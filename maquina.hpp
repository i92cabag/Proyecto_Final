#ifndef maquina_hpp
#define maquina_hpp

#include <iostream>
#include <vector>

using namespace std;

class Maquina{

	private:

		int cluster_id;
		int maquina_id;
		int cpu_maquina;
		int cpu_disponible;

	public:

		inline int getCluster_id(){

					return cluster_id;
				}

		inline int getMaquina_id(){

					return maquina_id;
				}

		inline int getCpu_maquina(){

					return cpu_maquina;
				}

		inline int getCpu_disponible(){

					return cpu_disponible;
				}

		inline void modificar_cpu_disp( int nueva_cpu ){

					cpu_disponible = nueva_cpu;
				}

		inline void modificar_cluster( int nuevo_cluster ){

					cluster_id = nuevo_cluster;
				}
			
		inline void modificar_cpu_maquina( int nueva_cpu ){
		
					cpu_maquina = nueva_cpu;
				}

		inline void modificar_id_maquina( int nueva_maquina ){

					maquina_id = nueva_maquina;
				}

};

void rellenar_maquinas( vector< Maquina > &maquinas );

void volcar_maquinas_fichero( vector< Maquina > maquinas );

void mostrar_maquinas_disponibles( vector<Maquina> maquinas );

bool modificar_maquina( vector<Maquina> &maquinas, int maquina, int cantidad_cpu );

void mostrar_maquinas_recomendadas( vector<Maquina> maquinas, int maquina, int cantidad_cpu );

bool maquina_existe( vector<Maquina> maquinas, int maquina );

int get_cluster( vector<Maquina> maquinas, int maquina );

#endif
