#include "typingGame.h"

int main() {
    char *word;
    printf("Enter a word: ");
    fflush(stdout);

    word = timeOut(3);
    if (word) {
	printf("sup\n");
    } else {
	printf("Didnt work\n");
    }

    return 0;
}
