/*
 * teste03.cpp
 *
 *  Created on: 05/02/2014
 *      Author: dionata
 */

#include "../include/teste03.h"

namespace std {

teste03::teste03() {
	// TODO Auto-generated constructor stub
	atributo_a_ser_alterado = 0;
}

teste03::~teste03() {
	// TODO Auto-generated destructor stub
}

int teste03::setNumero(int atributo_a_ser_alterado_){

	printf("Metodo teste03\nExemplo de Herança\n");
	atributo_a_ser_alterado =  atributo_a_ser_alterado_;
	atributo_a_ser_alterado +=10;

	return atributo_a_ser_alterado;
}

} /* namespace std */
