
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

/**
@brief funcion que vuelca del fichero donde se guardan los datos de las maquinas a un vector de maquinas con el que se va a trabajar.
@param maquinas el vector donde se van a guardar los datos de todas las maquinas.
*/
void rellenar_maquinas( vector< Maquina > &maquinas );

/**
@brief funcion que devuelve el vector de maquinas despues de haber trabajado con el al fichero de maquinas para su futura lectura cuando se vuelva a abrir el programa.
@param maquinas el vector del que se van a leer las maquinas que se van a pasar al fichero.
*/
void volcar_maquinas_fichero( vector< Maquina > maquinas );

/**
@brief funcion que muestra las maquinas que tienen todavía cpu sin utilizar.
@param maquinas vector de maquinas.
*/
void mostrar_maquinas_disponibles( vector<Maquina> maquinas );

/**
@brief funcion que modifica la cantidad libre de cpu de una maquina.
@param maquinas vector de todas las maquinas.
@param maquina entero identificativo de la maquina
@param cantidad_cpu cantidad de cpu que va a tener libre la nueva maquina.
*/
bool modificar_maquina( vector<Maquina> &maquinas, int maquina, int cantidad_cpu );

/**
@brief funcion que muestra las maquinas que se le recomiendasn al usuario para su uso con respecto a la cpu que pide el usuario.
@param cantidad_cpu cantidad de cpu que el usuario pide de una maquina.
*/
void mostrar_maquinas_recomendadas( vector<Maquina> maquinas, int maquina, int cantidad_cpu );

/**
@brief funcion que devuelve un booleano indicando si existe la maquina que el usuario ha indicado.
@param maquina entero identificativo de la maquina.
*/
bool maquina_existe( vector<Maquina> maquinas, int maquina );

/**
@brief funcion que devuelve el cluster en el que se encuentra una maquina.
@param maquina entero identificativo de la maquina.
*/
int get_cluster( vector<Maquina> maquinas, int maquina );

#endif
