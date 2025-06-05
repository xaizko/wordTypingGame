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

//Function headers
char *timeOut(int timeout); //Function to give user input a timer
size_t write_callback(void *contents, size_t size, size_t nmemb, void *userp); //Function to write response to a string
char* CurlCall(CURL *curl, CURLcode res, char *response); //Test api call function
int checkEqual(char* temp);
