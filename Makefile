CFLAGS = -Wall -std=gnu99 -pedantic -fsanitize=address -lm
CC = gcc

SOURCES_CLIENT := $(wildcard cliente/*.c)
SOURCES_SERVER := $(wildcard servidor/*.c)

all: server client

server:  servidor/server.c servidor/challenges.c 
	$(CC) -o servidor/server $(SOURCES_SERVER)  $(CFLAGS)

client: cliente/client.c 
	$(CC) -o cliente/client $(SOURCES_CLIENT)  $(CFLAGS)

clean:
	rm -f servidor/server
	rm -f cliente/client
