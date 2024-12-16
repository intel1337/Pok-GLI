#include <stdio.h>
#include <stdlib.h>


float finput(char prompt[], float* var, int size) {
    printf("%s", prompt);
    char inqput[size];
    fgets(inqput, size, stdin);
    *var = atof(inqput);

}

