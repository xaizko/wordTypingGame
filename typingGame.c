#include "typingGame.h"

int main() {
    char *word;
    int timer;

    printf("Enter preferred time you'd like to be given to type 1 word: ");
    scanf("%d", &timer);


    printf("Enter a word: ");
    fflush(stdout);

    word = timeOut(timer);
    return 0;
}
