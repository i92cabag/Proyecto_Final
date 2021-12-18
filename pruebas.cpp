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

TEST( usuario_existeTest, positive ) {

	std::vector<Usuario> usuarios;

	Usuario aux;
	aux.cambiar_id( 1001 );
	aux.cambiar_nombre( juan );
	aux.cambiar_contrasena( juanillo123 );
	aux.cambiar_email( juan@gmail.com );
	aux.cambiar_departamento( animales );
	aux.cambiar_lim_reservas( 3 );
	aux.cambiar_lim_cpu( 16 );
	usuarios.push_back(aux);

	aux.cambiar_id( 1004 )
	aux.cambiar_nombre( alfonso );
	aux.cambiar_contrasena( alfonsillo123 );
	aux.cambiar_email( alfonso@gmail.com );
	aux.cambiar_departamento( bacterias );
	aux.cambiar_lim_reservas( 3 );
	aux.cambiar_lim_cpu( 16 );
	usuarios.push_back(aux);

	ASSERT_EQ(true, usuario_existe( usuarios, 1001) );
	ASSERT_EQ(true, usuario_existe( usuarios, 1004) );

}

TEST( usuario_existeTest, negative ) {

	std::vector<Usuario> usuarios;

	Usuario aux;
	aux.cambiar_id( 1007 );
	aux.cambiar_nombre( antonio );
	aux.cambiar_contrasena( antonillo123 );
	aux.cambiar_email( antonio@gmail.com );
	aux.cambiar_departamento( animales );
	aux.cambiar_lim_reservas( 3 );
	aux.cambiar_lim_cpu( 16 );
	usuarios.push_back(aux);

	aux.cambiar_id( 1002 )
	aux.cambiar_nombre( laura );
	aux.cambiar_contrasena( laurilla123 );
	aux.cambiar_email( laura@gmail.com );
	aux.cambiar_departamento( virus );
	aux.cambiar_lim_reservas( 3 );
	aux.cambiar_lim_cpu( 16 );
	usuarios.push_back(aux);

	ASSERT_EQ(false, usuario_existe( usuarios, 1007) );
	ASSERT_EQ(false, usuario_existe( usuarios, 1002) );

}

int main(){

	testing::InitGoogleTest();
	return RUN_ALL_TESTS();

}
