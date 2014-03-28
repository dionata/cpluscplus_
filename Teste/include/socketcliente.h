/*
 * socketcliente.h
 *
 *  Created on: 07/02/2014
 *      Author: dionata
 */

#ifndef SOCKETCLIENTE_H_
#define SOCKETCLIENTE_H_

#include <sys/socket.h>
#include <arpa/inet.h>
#include <sys/types.h>

namespace std {

class socket_cliente {
private:
	int e_socket;
	char resposta[100];
public:
	struct sockaddr_in {
		short int sin_family; //familia socket
		unsigned short int sin_porte;	//numero da porta UDP ou TCP
		struct in_addr sin_addr; //ip host de destino
		unsigned  char  sin_zero[8];//zera estrura do socket
	}socket_config;

	socket_cliente();
	virtual ~socket_cliente();
	bool cliente();
};

} /* namespace std */
#endif /* SOCKETCLIENTE_H_ */
