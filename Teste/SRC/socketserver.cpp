/*
 * socketserver.cpp
 *
 *  Created on: 07/02/2014
 *      Author: Dionata Nunes
 */

#include "../include/main.h"
#include <sys/resource.h>
namespace std {

socket_server::socket_server() {
	// TODO Auto-generated constructor stub
	SRV= "HTTP/1.1 200 Ok\n\n<p><b>Servidor Exemplo!</b></p><img src=\"http://i21.photobucket.com/albums/b256/rot_in_pieces/splatterhouse.gif\">\n";
}

socket_server::~socket_server() {
	// TODO Auto-generated destructor stub
}

bool socket_server::server(){
	pid_t pid;
	pid = fork();

	if(pid<0){
		printf("Erro ao criar o processo\n");
	}
	else if(!pid){
			printf("socket: servidor %d\n", getpid());
		   /*Criando um socket
		    *
		    * socket(sin_family, tipo_do_socket_desejado,número_do_protocolo);
		    *
		    * Número_do_protocolo pode ser:
		    *
		    * 0 - IP - INTERNET PROTOCOL
		    * 1 - ICMP - INTERNET CONTROL MESSAGE PROTOCOL
		    * 2 - IGMP - INTERNET GROUP MULTICAST PROTOCOL
		    * 3 - GGP - GATEWAY-GATEWAY PROTOCOL
		    * 6 - TCP - TRANSMISSION CONTROL PROTOCOL
		    * 17 - UDP - USER DATAGRAMA PROTOCOL
			*/

			e_socket = socket(AF_INET,SOCK_STREAM,0);
			if(e_socket < 0){
				perror("Error socket\n");
				exit(EXIT_FAILURE);
			}

			socket_config.sin_family = AF_INET;
			socket_config.sin_porte = htons(porta);
			/* Endereço para aceitar todas as mensagens recebidas:
			 * INADDR_ANY;
			 * Estipular IP:
			 * inet_addr(ip);
			 */
			socket_config.sin_addr.s_addr = INADDR_ANY;


			//bzero(&(socket_config.sin_zero), 8); //ou
			memset(&socket_config.sin_zero, 0, sizeof(socket_config));

			/* bind seta uma porta e ip do sistema levando em consideração socket_config.sin_addr.s_addr = INADDR_ANY;*/
			//A funcao bind () faz o papel de abrir a porta no sistema.
			if(bind(e_socket, (struct sockaddr*)&socket_config, sizeof(socket_config)) == -1){
				perror("Erro bind\n");
				return(EXIT_FAILURE);
			}
			/*
			 * Esperando uma conexão com a função listen
			 * */
			if(listen(e_socket,3)==-1){ //numero máximo de conexões: 1
				perror("Erro em listen\n");
				exit(EXIT_FAILURE);
			}
			std::cout<<"Esperando uma conexao...\n"<<endl;

			while(1){
				pthread_t id;
				int resp;
				const char *msn = "pthread";
				resp = pthread_create(&id, NULL ,socket_server::new_socket,this);
				pthread_join(id,NULL);							

			/*
			 * Estabelece conexoes em um socket. Ela cria um novo socket com as mesmas
			 * propriedades do socket anterior do seu programa e aloca um novo "int socket"
			 * para a nova conexao.
			 */
			cliente_socket = accept(e_socket,0,0);

			if(cliente_socket  == -1){
				perror("Erro no socket");
				exit(EXIT_FAILURE);
			}
			if(!fork()){
			//std::cout<<"Pedido atendido\n"<<endl;

			/*
			 * Envinado uma mensagem com a função send
			 *
			 * int send(int socket, const void * dados, int tamanho , int flags);
			 * socket:
			 * descritor do socket;
			 * dados:
			 * dados a serem enviados. Pode-se passar uma string ou variível como valor;
			 * tamanho:
			 * número de bytes a serem enviados;
			 * flags:
			 * valores opcionais normalmente passados como ZERO.
			 * */
			if(send(cliente_socket, SRV, strlen(SRV),0) ==-1){ //Pode ser usado a função write no lugar de send
				perror("Erro ao enviar a mensagem\n");
				exit(EXIT_FAILURE);
			}

			/*int recv(int socket, void * buffer, int tamanho , int flags);
			 * socket:
			 * descritor do socket;
			 * buffer:
			 * buffer no qual serão armazenados os dados recebidos. Geralmente passamos arrays de chars como parâmetros;
			 * tamanho:
			 * número míximo de bytes que podem ser recebidos;
			 * flags:
			 * valores opcionais normalmente passados como ZERO.
			 * A função retorna o número de bytes recebidos em situação normal. Por outro lado, caso ocorra algum erro, o valor retornado é -1.
			 * */
			recv(cliente_socket, resposta, 100,0); //pode ser usado a função read no lugar de recv
			printf("[RECV]: ");
			puts(resposta);
			close(cliente_socket);//finaliza o socket do cliente
			exit(EXIT_SUCCESS);
			}
			}
			close(e_socket);//finaliza o socket do servidor
//			/*
//			 * Realizando uma conexão
//			 *
//			 * prototype da função de connect:
//			 * int connect(socket,(struct sockaddr * )&destino, sizeof(destino));
//			 */
//			 conexao = connect(e_socket, (struct sockaddr *) &socket_config, sizeof(socket_config));
//			 if(conexao < 0){
//				 perror("Porta fechada\n");
//				 close(e_socket);
//				 exit(EXIT_SUCCESS);
//			 }
//
//			 std::cout << "Porta 22 esta aberta\n" <<endl;
//			 close(e_socket);
	         pthread_exit(NULL);
			sleep(2);
	for(;;);
	}
	else if(pid>0){
		//printf("MORTO PAI - SERVER\n");
		sleep(2);
		exit(EXIT_SUCCESS);
	}
	return OK;
}

bool socket_server::setPort(int porta_recebida){

	std::cout << "Porta Recebida: " <<porta_recebida<<endl;
	porta = porta_recebida;

	return OK;
}

bool socket_server::setIp(char *ip_recebido){

	std::cout << "IP Recebido: " << ip_recebido<<endl;
	ip = ip_recebido;

	return OK;
}

void *socket_server::new_socket(void *arg){
	printf("Oi\n");
	return 0;
}

} /* namespace std */
