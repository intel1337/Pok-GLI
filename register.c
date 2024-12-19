#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <time.h>

#include "config.h"  // Contains the server port

#define REGISTER_PORT 4002 // Define the registration port

char buf[BUFSIZ];

void create_user_file(const char* credentials) {
    char username[BUFSIZ], password[BUFSIZ];
    sscanf(credentials, "%[^:]:%s", username, password);
    int user_id = 1;
    char filename[BUFSIZ];
    sprintf(filename, "user%d.txt", user_id);
    while (access(filename, F_OK) != -1) {
        user_id++;
        sprintf(filename, "user%d.txt", user_id); 
    }
    FILE *file = fopen(filename, "w");
    if (file) {
        fprintf(file, "%s:%s\n", username, password);
        fclose(file);
        printf("User  created: %s\n", filename);
    } else {
        perror("Failed to create user file");
    }
}

int main() {
    int server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd == -1) {
        perror("socket");
        return EXIT_FAILURE;
    }

    struct sockaddr_in server_addr = {
        .sin_addr.s_addr = INADDR_ANY,
        .sin_family = AF_INET,
        .sin_port = htons(REGISTER_PORT) // Listen on the registration port
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

    printf("Server listening on port: %d\n", REGISTER_PORT);

    while (1) {
        struct sockaddr_in client_addr;
        socklen_t len = sizeof(client_addr);
        int client_fd = accept(server_fd, (struct sockaddr*)&client_addr, &len);
        if (client_fd == -1) {
            perror("accept");
            continue;
        }

        int recv_length = recv(client_fd, buf, BUFSIZ, 0);
        if (recv_length == -1) {
            perror("recv");
            close(client_fd);
            continue; 
        }

        create_user_file(buf);

        printf("Received credentials: %s\n", buf);
        close(client_fd); // Close the client connection
    }

    close(server_fd);
    return EXIT_SUCCESS;
}