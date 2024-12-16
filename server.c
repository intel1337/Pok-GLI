#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <time.h>

#include "config.h"  // Contient le port du serveur

char buf[BUFSIZ];

int main() {
    int server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd == -1) {
        perror("socket");
        return EXIT_FAILURE;
    }

    struct sockaddr_in server_addr = {
        .sin_addr.s_addr = INADDR_ANY,
        .sin_family = AF_INET,
        .sin_port = htons(SERVER_PORT)
    };
    if (bind(server_fd, (struct sockaddr*)&server_addr, sizeof(server_addr)) == -1) {
        perror("bind");
        close(server_fd);
        return EXIT_FAILURE;
    }

    if (listen(server_fd, BUFSIZ) == -1) {
        perror("listen");
        close(server_fd);
        return EXIT_FAILURE;
    }

    printf("Server listening on port: %d\n", SERVER_PORT);

    struct sockaddr_in client_addr;
    socklen_t len = sizeof(client_addr);
    int client_fd = accept(server_fd, (struct sockaddr*)&client_addr, &len);
    if (client_fd == -1) {
        perror("accept");
        close(server_fd);
        return EXIT_FAILURE;
    }

    if (send(client_fd, "ping", 5, 0) == -1) {
        perror("send");
        close(client_fd);
        close(server_fd);
        return EXIT_FAILURE;
    }

    int recv_length = recv(client_fd, buf, BUFSIZ, 0);
    if (recv_length == -1) {
        perror("recv");
        close(client_fd);
        close(server_fd);
        return EXIT_FAILURE;
    }

    printf("$%s\n", buf);
    close(client_fd);
    close(server_fd);
    return EXIT_SUCCESS;
}
