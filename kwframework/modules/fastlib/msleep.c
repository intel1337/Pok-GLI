#include <stdio.h>
#include <unistd.h>

void msleep(int milliseconds)
{

    usleep(milliseconds * 1000);
    fflush(stdout);
}