// C program to read a file using fgetc()
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void loadmenu() {
  
    // Opening file
    FILE *file_ptr;

    // Character buffer that stores the read character
    // till the next iteration
    char ch;

    // Opening file in reading mode
    file_ptr = fopen("menu.txt", "r");

    if (NULL == file_ptr) {
        printf("file can't be opened \n");
          exit(0);
    }
    // Printing what is written in file
    // character by character using loop.
    while ((ch = fgetc(file_ptr)) != EOF) {
        printf("%c", ch);
    }
    fclose(file_ptr);
}