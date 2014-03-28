/*
 * socketserver.h
 *
 *  Created on: 07/02/2014
 *      Author: dionata
 */

#ifndef SOCKETSERVER_H_
#define SOCKETSERVER_H_

#include <sys/socket.h>
#include <arpa/inet.h>
#include <sys/types.h>

namespace std {

class socket_server {
private:
	int e_socket;
	int cliente_socket;
	int conexao;
	int porta;
	char *ip;
    char resposta[100];
    char *SRV;


public:
    socket_server();
    void *new_socket(void *arg);
	virtual ~socket_server();
	bool server();
	bool setPort(int porta_recebida);
	bool setIp(char *ip_recebido);

	struct sockaddr_in {
		short int sin_family; //familia socket
		unsigned short int sin_porte;	//numero da porta UDP ou TCP
		struct in_addr sin_addr; //ip host de destino
		unsigned  char  sin_zero[8];//zera estrura do socket
	}socket_config;

};

} /* namespace std */
#endif /* SOCKETSERVER_H_ */
