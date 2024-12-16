#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include <time.h>

#include "kiwi.h"
#include "config.h" // Contient le port du serveur
#include "loadmenu.c"
#define CLIENT_PORT 4001

int main(){
    
    

    system("clear");
    loadperc(20);
    loadmenu();
    etc();
    system("clear");
    
    
























    // int client_fd = socket(AF_INET,SOCK_STREAM,0);perror("socket");
    // if(client_fd == -1) return EXIT_FAILURE;
    // struct sockaddr_in client_addr = {
    //     .sin_addr.s_addr = INADDR_ANY,
    //     .sin_family = AF_INET,
    //     .sin_port = htons(CLIENT_PORT)
    // };
    // int error = bind(client_fd,(struct sockaddr*)&client_addr,sizeof client_addr);perror("bind");
    // if(error == -1) { close(client_fd); return EXIT_FAILURE; }
    // struct sockaddr_in server_addr = {
    //     .sin_addr.s_addr = INADDR_ANY,
    //     .sin_family = AF_INET,
    //     .sin_port = htons(SERVER_PORT)
    // };
    // error = connect(client_fd,(struct sockaddr*)&server_addr,sizeof server_addr);perror("connect");
    // if(error == -1) { close(client_fd); return EXIT_FAILURE; }
    // char reponse[BUFSIZ];memset(reponse,0,BUFSIZ);
    // int reponse_length = recv(client_fd,reponse,BUFSIZ,0);perror("recv");
    // if(reponse_length == -1) { close(client_fd); return EXIT_FAILURE; }

    // printf("[%d]$%s\n",time(NULL),reponse);    
    // int request_length = send(client_fd,"pong",5,0);perror("send");
    // if(request_length == -1){ close(client_fd); return EXIT_FAILURE;}
    // close(client_fd);

    // return 0;

}