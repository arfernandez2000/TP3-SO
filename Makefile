CFLAGS = -Wall -std=gnu99 -pedantic -fsanitize=address -lm
CC = gcc

all: server client

server:  server.c challenges.c 
	$(CC) -o server server.c challenges.c  $(CFLAGS)

client: client.c 
	$(CC) -o client client.c  $(CFLAGS)

clean:
	rm -f server
	rm -f client
