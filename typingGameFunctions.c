#include "typingGame.h"

int score;

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
char* CurlCall(CURL *curl, CURLcode res, char *response) {

    if (response != NULL) {
	free(response);
	response = NULL;
    }

    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_callback);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response);

    //performs api request
    res = curl_easy_perform(curl);

    if (res != CURLE_OK) {
	fprintf(stderr, "failed to perform request: %s\n", curl_easy_strerror(res));
	return NULL;
    } else {
	size_t len = strlen(response);
	response[len-2] = '\0';
	return response+2;
    }

    free(response);
    curl_easy_cleanup(curl);

    return NULL;

}

//check if the words are equal
int checkEqual(char* temp, int timer) {
    //prints the word and ask the user to type it
    printf("%s\n", temp);
    printf("Type your word: ");
    fflush(stdout);
    char *typedWord = timeOut(timer);

    //if not typed fast enough end game
    if (typedWord == NULL) {
        printf("%sRan out of time: Your final score: %d%s\n", AC_RED, score, AC_NORMAL);
	return 0;
    }

    //logic to check if the word is correct
    if (!strcmp(temp, typedWord)) {
	int pointsAdd = strlen(temp);
	score += pointsAdd;
	printf("%sCorrect: +%d points%s\n", AC_GREEN, pointsAdd, AC_NORMAL);
    } else {
	printf("%sIncorrect: Your final score: %d%s\n", AC_RED, score, AC_NORMAL);
	return 0;
    }
    return 1;
}

void printMenu() {
    printf("%s=============================================\n", AC_BLUE);
    printf("|                 MAIN MENU                 |\n");
    printf("=============================================\n");
    printf("| [1] Play Regular Game                     |\n");
    printf("=============================================\n");
    printf("| [2] Special Modes                         |\n");
    printf("=============================================\n");
    printf("| [3] Show Highscores                       |\n");
    printf("=============================================\n");
    printf("| [4] Exit Game                             |\n");
    printf("=============================================%s\n", AC_NORMAL);

    return;
}


