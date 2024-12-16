#include <stdio.h>
#include <string.h>

char* input(char prompt[], char* var, int size) {
    printf("%s", prompt);
    fgets(var, size, stdin);
    var[strcspn(var, "\n")] = 0; 
}
