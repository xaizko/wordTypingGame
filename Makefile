CC=gcc
OUTPUT=-o typingGame
FLAGS=-lcurl

all: typingGame

typingGame: typingGame.c
	$(CC) typingGame.c typingGameFunctions.c $(OUTPUT) $(FLAGS)

clean:
	rm -f typingGame
