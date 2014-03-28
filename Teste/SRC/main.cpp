/*
 * main.cpp
 *
 *  Created on: 03/02/2014
 *      Author: Dionata Nunes
 */

#include "../include/main.h"

int main(int argc, char *argv[]){

	std::Teste01 *obj_teste01;
	std::Teste02 *obj_teste02;
	std::teste03 *obj_teste03;

	std::socket_server *obj_socket_server;
	std::string teste_de_string;

	printf("Iniciando aplicacao de Teste C++ (Orientado a Objeto)\n");

	obj_teste01 = new std::Teste01();
	if(!obj_teste01->init_teste01())
		printf("ok\n");

	obj_teste02 = new std::Teste02();
	if(!obj_teste02->init_teste2())
		printf("ok\n");

	obj_teste03 = new std::teste03();
	if(!obj_teste03->init_teste2()) //exemplo de herança
		printf("exemplo herança ok\n\n");

	printf("Valor de retorno objeto teste03 %d\n", obj_teste03->setNumero(50));

	obj_socket_server = new std::socket_server();

	if(obj_socket_server->setIp(argv[1])){
			perror("Erro ao acessar objeto");
			return NOK;
	}

	if(obj_socket_server->setPort(atoi(argv[2]))){
		perror("Erro ao acessar objeto\n");
		return NOK;
	}

	if(obj_socket_server->server()){
		perror("Erro ao acessar objeto\n");
		return NOK;
	}

	return OK;
}
