#include <stdio.h>
#include <sys/types.h>
#include <stdlib.h>
#include <sys/time.h>
#include <unistd.h>
#include <string.h>

//code taken from https://github.com/xaizko/UserInputTimer
char *timeOut(int timeout)  {
    static char buf[512];
    fd_set rfds;
    struct timeval tv;
}
