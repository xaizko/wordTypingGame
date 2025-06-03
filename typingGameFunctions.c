#include "typingGame.h"

//code taken from https://github.com/xaizko/UserInputTimer
//This function simply acts as a input timer
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

//This function writes the response to a string
size_t write_callback(void *contents, size_t size, size_t nmemb, void *userp) {
    size_t realsize = size * nmemb;
    char **response_ptr = (char **)userp;

    *response_ptr = strndup((const char*)contents, realsize);
    return realsize;
}

//api call
void CurlCall(CURL *curl, CURLcode res, char *response) {

    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_callback);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response);

    //performs api request
    res = curl_easy_perform(curl);

    if (res != CURLE_OK) {
	fprintf(stderr, "failed to perform request: %s\n", curl_easy_strerror(res));
    } else {
	size_t len = strlen(response);
	response[len-2] = '\0';
	printf("Reponse: %s\n", response+2);
    }

    free(response);
    curl_easy_cleanup(curl);

}
