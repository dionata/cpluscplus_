/*
 * teste03.h
 *
 *  Created on: 05/02/2014
 *  Exemplo de Herança
 *      Author: dionata
 */

#ifndef TESTE03_H_
#define TESTE03_H_
#include "../include/main.h"

namespace std {

class teste03 : public Teste02 {
private:
	int atributo_a_ser_alterado;

public:
	teste03();
	virtual ~teste03();
	int setNumero(int atributo_a_ser_alterado_);
};

} /* namespace std */
#endif /* TESTE03_H_ */
