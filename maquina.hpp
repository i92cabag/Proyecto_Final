
#ifndef maquina_hpp
#define maquina_hpp

#include <iostream>

class maquina{

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

		inline void modificar_cpu( int nueva_cpu ){

					cpu_disponible = nueva_cpu;
				}

		inline void modificar_cluster( int nuevo_cluster ){

					cluster_id = nuevo_cluster;
				}

		inline void modificar_id_maquina( int nueva_maquina ){

					maquina_id = nueva_maquina;
				}

};


#endif

