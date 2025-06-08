#include "typingGame.h"

int main() {
    char *word;
    int timer;
    int choice;
    int menuSelect;
    int running = 1;

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

    printf("%s+-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+\n", AC_CYAN);
    printf("| ██╗    ██╗███████╗██╗      ██████╗ ██████╗ ███╗   ███╗███████╗    ████████╗ ██████╗     ████████╗██╗   ██╗██████╗ ██╗███╗   ██╗ ██████╗      ██████╗  █████╗ ███╗   ███╗███████╗ |\n");
    printf("| ██║    ██║██╔════╝██║     ██╔════╝██╔═══██╗████╗ ████║██╔════╝    ╚══██╔══╝██╔═══██╗    ╚══██╔══╝╚██╗ ██╔╝██╔══██╗██║████╗  ██║██╔════╝     ██╔════╝ ██╔══██╗████╗ ████║██╔════╝ |\n");
    printf("| ██║ █╗ ██║█████╗  ██║     ██║     ██║   ██║██╔████╔██║█████╗         ██║   ██║   ██║       ██║    ╚████╔╝ ██████╔╝██║██╔██╗ ██║██║  ███╗    ██║  ███╗███████║██╔████╔██║█████╗   |\n");
    printf("| ██║███╗██║██╔══╝  ██║     ██║     ██║   ██║██║╚██╔╝██║██╔══╝         ██║   ██║   ██║       ██║     ╚██╔╝  ██╔═══╝ ██║██║╚██╗██║██║   ██║    ██║   ██║██╔══██║██║╚██╔╝██║██╔══╝   |\n");
    printf("| ╚███╔███╔╝███████╗███████╗╚██████╗╚██████╔╝██║ ╚═╝ ██║███████╗       ██║   ╚██████╔╝       ██║      ██║   ██║     ██║██║ ╚████║╚██████╔╝    ╚██████╔╝██║  ██║██║ ╚═╝ ██║███████╗ |\n");
    printf("|  ╚══╝╚══╝ ╚══════╝╚══════╝ ╚═════╝ ╚═════╝ ╚═╝     ╚═╝╚══════╝       ╚═╝    ╚═════╝        ╚═╝      ╚═╝   ╚═╝     ╚═╝╚═╝  ╚═══╝ ╚═════╝      ╚═════╝ ╚═╝  ╚═╝╚═╝     ╚═╝╚══════╝ |\n");
    printf("+-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+%s\n\n", AC_NORMAL);

    //Load highscore
    loadHighscore();

    //Choose gamemode based on user input
    while (running) {
	//print and get user choice
	printMenu();
	printf("Enter your choice: ");
	scanf("%d", &menuSelect);

	//react based on choice
	switch (menuSelect){
	    case 1:
		printf("Loading up Typing Game regular mode...\n");
		printf("Enter preferred time you'd like to be given to type 1 word: ");
		scanf("%d", &timer);
		do {
		    word = CurlCall(curl , res, response);
		} while (checkEqual(word, timer));

		break;
	    case 2:
		printf("Work in Progress!\n");
		break;
	    case 3:
		printf("Work in Progress!\n");
		break;
	    case 4:
		printf("Exiting Game. Thanks for playing!\n");
		break;
	    default:
		printf("Invalid Choice, try again");
	}
    }

    
    curl_easy_cleanup(curl);

    return 0;
}
