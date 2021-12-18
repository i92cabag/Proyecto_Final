
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



int main(){

	testing::InitGoogleTest();
	return RUN_ALL_TESTS();

}
