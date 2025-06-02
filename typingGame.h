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
    int retval;

    FD_ZERO(&rfds);
    FD_SET(0, &rfds);

    tv.tv_sec = timeout;
    tv.tv_usec = 0;

    retval = select(1, &rfds, 0, 0, &tv);
    if (retval && FD_ISSET(0, &rfds)) {
	memset(buf, 0, 512);
	retval = read(0, buf, 511);
	if (retval < 1) {
	    return 0;
	}
	retval--;
	buf[retval] = 0;
	return buf;
    } else {
	return 0;
    }
}
