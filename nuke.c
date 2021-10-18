#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<unistd.h>

int main(void){
	struct sockaddr_in server;
	int sock;
	
	printf("Create Socket");
	sock = socket(AF_INET, SOCK_STREAM, 0);

	server.sin_family = AF_INET;
	server.sin_port = htons(139);
	server.sin_addr.s_addr = inet_addr("192.168.101.95");
	
	printf("Connecting...");
	connect(sock, (struct sockaddr *)&server, sizeof(server));
	
	void *message = malloc(65536);
	write(sock, message, sizeof(message));
	printf("message sent.");
}
