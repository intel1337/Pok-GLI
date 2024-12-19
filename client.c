#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include <time.h>

#include "kiwi.h"
#include "config.h" // Contains the server port
#include "loadmenu.c"

#define CLIENT_PORT 4001
#define REGISTER_PORT 4002 
#define PLAY_PORT 4003
#define LOGIN_PORT 4004// Define a port for registration

int main() {
    int client_fd = socket(AF_INET, SOCK_STREAM, 0);perror("socket");
    if (client_fd == -1) {
        return EXIT_FAILURE;
    }

    struct sockaddr_in register_addr = {
        .sin_addr.s_addr = INADDR_ANY,
        .sin_family = AF_INET,
        .sin_port = htons(REGISTER_PORT) 
    };

    struct sockaddr_in play_addr = {
        .sin_addr.s_addr = INADDR_ANY,
        .sin_family = AF_INET,
        .sin_port = htons(PLAY_PORT) 
    };

    struct sockaddr_in login_addr = {
        .sin_addr.s_addr = INADDR_ANY,
        .sin_family = AF_INET,
        .sin_port = htons(LOGIN_PORT) 
    };

    int error = connect(client_fd, (struct sockaddr*)&register_addr, sizeof(register_addr));perror("connect");
    if (error == -1) {
        close(client_fd);
        return EXIT_FAILURE;
    }

    while (1) {
        char input[BUFSIZ];
        system("clear");
        loadmenu(); // LOAD MENU FUNC
        fgets(input, BUFSIZ, stdin);
        input[strcspn(input, "\n")] = 0; 

        if (strcspn(input, "0") == 0) {
            // Exit 
            close(client_fd);
            exit(0);

        } else if (strcspn(input, "1") == 0) {
            // register
            printf("Create a new account? Y/n \n");
            fgets(input, BUFSIZ, stdin);
            input[strcspn(input, "\n")] = 0; 

            if (strcspn(input, "Y") == 0) {
                system("clear");
                printf("Username: ");
                char username[BUFSIZ];
                fgets(username, BUFSIZ, stdin);
                username[strcspn(username, "\n")] = 0; 

                system("clear");
                printf("Password: ");
                char password[BUFSIZ];
                fgets(password, BUFSIZ, stdin);
                password[strcspn(password, "\n")] = 0; 

                // concatenation user:mdp
                char credentials[BUFSIZ];
                strcpy(credentials, username);
                strcat(credentials, ":");
                strcat(credentials, password);

                //send
                int request_length = send(client_fd, credentials, strlen(credentials), 0);
                perror("send");
                if (request_length == -1) {
                    close(client_fd);
                    return EXIT_FAILURE;
                }
                printf("Registration request sent\n");
            }
        } else {
            printf("Bad command\n");
        }
    }

    close(client_fd);
    return 0;
}