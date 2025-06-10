//standard libraries
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

//timer libraries
#include <sys/types.h>
#include <sys/time.h>

//Api libraries
#include <curl/curl.h>

// Text Colors
#define AC_BLACK "\x1b[30m"
#define AC_RED "\x1b[31m"
#define AC_GREEN "\x1b[32m"
#define AC_YELLOW "\x1b[33m"
#define AC_BLUE "\x1b[34m"
#define AC_MAGENTA "\x1b[35m"
#define AC_CYAN "\x1b[36m"
#define AC_WHITE "\x1b[37m"
#define AC_NORMAL "\x1b[m"

//Function headers
char *timeOut(int timeout); //Function to give user input a timer
size_t write_callback(void *contents, size_t size, size_t nmemb, void *userp); //Function to write response to a string
char* CurlCall(CURL *curl, CURLcode res, char *response); //Test api call function
int checkEqual(char* temp, int timer);
void printMenu();
void loadHighscore();
void printHighscore();
void setHighscore(int newScore, int *locationToChange);
