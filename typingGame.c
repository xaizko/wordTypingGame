#include "typingGame.h"

int main() {
    char *word;
    int timer;

    //Api Request Tools
    CURL *curl;
    CURLcode res;
    char *response = NULL;
    
    curl = curl_easy_init();
    if (!curl) {
	fprintf(stderr, "%s\n", "Failed to create CURL object");
	return 1;
    } else {
	//setting url
	curl_easy_setopt(curl, CURLOPT_URL, "https://random-word-api.herokuapp.com/word");
    }

    sampleCurlCall(curl, res, response);
    


   // printf("Enter preferred time you'd like to be given to type 1 word: ");
   // scanf("%d", &timer);


   // printf("Enter a word: ");
   // fflush(stdout);

   // word = timeOut(timer);
   return 0;
}
