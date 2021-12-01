
#ifndef cluster_hpp
#define cluster_hpp

#include <iostream>

using namespace std;

class cluster{

	private:

		int cluster_id;
		string localizacion;
		int propietario_id;

	public:

		inline int get_clusterId(){

			return cluster_id;
		}

		inline string get_localizacion(){

			return localizacion;
		}

		inline int get_propietario(){

			return propietario_id;
		}

		inline void cambiar_localizacion( string nueva_loc ){

			localizacion =  nueva_loc;
		}

		inline void cambiar_propietario( int nuevo_prop ){

			propietario_id = nuevo_prop;
		}

};



#endif
