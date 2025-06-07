#include "typingGame.h"

int main() {
    char *word;
    int timer;
    int choice;
    int menuSelect;

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
    printf("+-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+%s\n", AC_NORMAL);

    printMenu();
    printf("Enter your choice: ");
    scanf("%d", &menuSelect);

    //Choose gamemode based on user input
    switch (menuSelect){
	case 1:
	    printf("Loading up Typing Game regular mode...\n");
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
    //printf("Enter preferred time you'd like to be given to type 1 word: ");
    //scanf("%d", &timer);

    //do {
    //    printf("Choice: ");
    //    scanf("%d", &choice);
    //    word = CurlCall(curl , res, response);
    //    checkEqual(word, timer);
    //} while (choice != 0);

    //curl_easy_cleanup(curl);

    return 0;
}
