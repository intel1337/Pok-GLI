#ifndef KIWI_H
#define KIWI_H
#define KW_VERSION "1.0.0"
#define INPUT "kwframework/modules/input.c"

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
// #include TEST
#include "kwframework/modules/fastlib.h"
#include "kwframework/gti/loadbar.c"
#include "kwframework/gti/loadperc.c"
#include "kwframework/gti/etc.c"


void kw_init() {
    FILE *config_file = fopen("kiwi.conf", "r");
    if (config_file == NULL) {
        fprintf(stderr, "Error: Configuration file 'kiwi.conf' not found.\n");
        fprintf(stderr, "Please create the file with necessary settings before using the framework.\n");
        exit(EXIT_FAILURE);
    } else {
        printf("Configuration file found: 'kiwi.conf'.\n");
        fclose(config_file);
        system("clear");
    }

    const char *temp_dir = "./kwframework/tmp";
    const char *modules_dir = "./kwframework/modules";
    const char *gti_dir = "./kwframework/gti";
    if (access(temp_dir, F_OK) == -1) {
        fprintf(stderr, "[⚠️] - Warning: Temporary directory '%s' does not exist.\n", temp_dir);
    } else {
        printf("[✅] - Temporary directory '%s' is accessible.\n", temp_dir);
    }
    
    if (access(temp_dir, F_OK) == -1) {
        fprintf(stderr, "[⚠️] - Warning: Modules directory '%s' does not exist.\n", modules_dir);
    } else {
        printf("[✅] - Modules directory '%s' is accessible.\n", temp_dir);
    }
     if (access(gti_dir, F_OK) == -1) {
        fprintf(stderr, "[⚠️] - Warning: GTI directory '%s' does not exist.\n", modules_dir);
    } else {
        printf("[✅] - GTI directory '%s' is accessible.\n", temp_dir);
    }
}

#endif 
