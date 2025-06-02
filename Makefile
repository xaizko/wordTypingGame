CC=gcc
OUTPUT=-o typingGame
FLAGS=-lcurl
SRC=typingGame.c typingGameFunctions.c

all:
	$(CC) $(SRC) $(OUTPUT) $(FLAGS)

clean:
	rm -f typingGame

.PHONY: all clean
