#include <stdio.h>  
void loadperc(int speed){
    int j;  
    for (j = 0; j <= 100; j++) {  
        printf("Loading : %d％\r", j);  
        fflush(stdout);  
        msleep(speed);  
    }  
    printf("\n");  
}  