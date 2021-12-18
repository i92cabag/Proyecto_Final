#include "reservas.cpp"
#include "maquina.cpp"
#include "usuario.cpp"
#include <gtest/gtest.h>
#include <vector>
#include <string>
#include <iostream>



TEST( comprobar_maquina_reservadaTest, positive ){

std::vector<Reserva> reservas;

Reserva aux;
aux.modificar_maquina_reserva( 1 );
aux.modificar_usuario_reserva( 100 );
aux.modificar_cantidad_reservada(5);
aux.modificar_motivo_reserva( "animal" );
reservas.push_back(aux);

aux.modificar_maquina_reserva( 3 );
aux.modificar_usuario_reserva( 200 );
aux.modificar_cantidad_reservada(6);
aux.modificar_motivo_reserva( "vegetal" );
reservas.push_back(aux);

ASSERT_EQ( true, comprobar_maquina_reservada( reservas, 200, 3 ) );
ASSERT_EQ( true, comprobar_maquina_reservada( reservas, 100, 1 ) );

}



TEST( comprobar_maquina_reservadaTest, negative ){

std::vector<Reserva> reservas;

Reserva aux;
aux.modificar_maquina_reserva( 1 );
aux.modificar_usuario_reserva( 100 );
aux.modificar_cantidad_reservada(5);
aux.modificar_motivo_reserva( "animal" );
reservas.push_back(aux);

aux.modificar_maquina_reserva( 3 );
aux.modificar_usuario_reserva( 200 );
aux.modificar_cantidad_reservada(6);
aux.modificar_motivo_reserva( "vegetal" );
reservas.push_back(aux);

ASSERT_EQ( false, comprobar_maquina_reservada( reservas, 500, 3 ) );
ASSERT_EQ( false, comprobar_maquina_reservada( reservas, 100, 2 ) );

}

TEST( maquina_existeTest, positive ){

std::vector<Maquina> maquinas;

Maquina aux;
aux.modificar_cpu_disp( 1 );
aux.modificar_cluster( 3 );
aux.modificar_cpu_maquina(4);
aux.modificar_id_maquina(5);
maquinas.push_back(aux);

aux.modificar_cpu_disp( 2 );
aux.modificar_cluster( 6 );
aux.modificar_cpu_maquina(5);
aux.modificar_id_maquina(9);
maquinas.push_back(aux);

ASSERT_EQ( true, maquina_existe( maquinas, 5) );
ASSERT_EQ( true, maquina_existe( maquinas, 9) );

}

TEST( maquina_existeTest, negative ){

std::vector<Maquina> maquinas;

Maquina aux;
aux.modificar_cpu_disp( 8 );
aux.modificar_cluster( 7 );
aux.modificar_cpu_maquina(6);
aux.modificar_id_maquina(6);
maquinas.push_back(aux);

aux.modificar_cpu_disp( 9 );
aux.modificar_cluster( 8 );
aux.modificar_cpu_maquina(10);
aux.modificar_id_maquina(10);
maquinas.push_back(aux);

ASSERT_EQ( false, maquina_existe( maquinas, 7) );
ASSERT_EQ( false, maquina_existe( maquinas, 11) );

}

int main(){

	testing::InitGoogleTest();
	return RUN_ALL_TESTS();

}