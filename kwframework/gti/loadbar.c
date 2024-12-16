#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


void loadbar(int delay){
    printf("Loading -");
    printf("[");
    for(int i=0;i!=10;i++){
        printf("██");
        msleep(delay);
        fflush(stdout);
    }
    printf("]");
}