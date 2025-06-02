CC=gcc
OUTPUT=-o typingGame

all: typingGame

typingGame: typingGame.c
	$(CC) typingGame.c $(OUTPUT)

clean:
	rm -f typingGame
