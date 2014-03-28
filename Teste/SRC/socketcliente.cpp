/*
 * socketcliente.cpp
 *
 *  Created on: 07/02/2014
 *      Author: dionata
 */

#include "../include/main.h"

namespace std {

socket_cliente::socket_cliente() {
	// TODO Auto-generated constructor stub
}

socket_cliente::~socket_cliente() {
	// TODO Auto-generated destructor stub
}
bool socket_cliente::cliente(){
	int pid;

	pid = fork();

	if(pid < 0){
		printf("Erro ao criar processo!\n");
	}
	else if(!pid){
		printf("socket: cliente %d\n", getpid());
		sleep(5);

		e_socket = socket(AF_INET,SOCK_STREAM,0);

		if(e_socket == -1) {
		  printf("Erro ao criar o socket!\n");
		  return 1;
		}
		socket_config.sin_family      = AF_INET;
		socket_config.sin_porte       = htons(1234);
		socket_config.sin_addr.s_addr = inet_addr("127.0.0.1");

		memset(&socket_config.sin_zero,0,sizeof(socket_config.sin_zero));

		printf("Tentando se conectar...\n");

		if(connect(e_socket,(struct sockaddr*)&socket_config,sizeof(socket_config)) == -1) {
		  printf("Erro ao se conectar!\n");
		  return 1;
		}

		printf("Conectado!\nEnviando dados...\n");

		send(e_socket,"sou o cliente",13,0);
		recv(e_socket,resposta,100,0);
		printf("cliente: ");
		puts(resposta);

		close(e_socket);
	for(;;);
	}
	else if(pid>0){
		//printf("PAI MORTO - cliente\n");
		sleep(2);
		exit(EXIT_SUCCESS);
	}
	return OK;
}
} /* namespace std */
