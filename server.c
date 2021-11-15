#include "server.h"

#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <math.h>
#include <unistd.h>
#include "challenges.h"

#define PORT 8080
#define SO_REUSEPORT 15


ch_t challenges[TOTAL_CH] = {{&ch1,"entendido\n"}, {&ch2,"itba\n"}, {&ch3, "M4GFKZ289aku\n"}, {&ch4, "fk3wfLCm3QvS\n"}, {&ch5, "too_easy\n"},
                           {&ch6, ".RUN_ME\n"}, {&ch7, "K5n2UFfpFMUN\n"}, {&ch8, "BUmyYq5XxXGt\n"}, {&ch9, "u^v\n"},
                           {&ch10, "chin_chu_lan_cha\n"}, {&ch11, "gdb_rules\n"}, {&ch12, "normal\n"}};

int checkAns(char* answer, char* resp){
	return 0;
}

void checkError(int resp, char* func){
	if (resp == -1){
        perror(func);
        exit(-1);
    }
}

static const char* surprise = "too_easy";

static const char* easter_egg =  
"_______________________\n"
"< ESTO ES UN EASTER_EGG >\n"
".------..------..------..------.\n"
"|I.--. ||T.--. ||B.--. ||A.--. |\n"
"| (\\/) || :/\\: || :(): || (\\/) |\n"
"| :\\/: || (__) || ()() || :\\/: |\n"
"| '--'I|| '--'T|| '--'B|| '--'A|\n"
"`------'`------'`------'`------'\n";

void foo() __attribute__((section(".RUN_ME")));

void foo() {
	return;
}

void init(int *serverFd, int *opt, struct sockaddr_in *sAddress, int *aLen, int *socketFd, FILE **socketFile){
	checkError(*serverFd = socket(AF_INET, SOCK_STREAM, 0),"socket");
	checkError(setsockopt(*serverFd, SOL_SOCKET, SO_REUSEADDR, opt, sizeof(*opt)),"setsockopt");

    sAddress->sin_family = AF_INET;
    sAddress->sin_addr.s_addr = INADDR_ANY;
    sAddress->sin_port = htons(PORT);

    checkError(bind(*serverFd, (struct sockaddr *)sAddress, sizeof(*sAddress)), "bind");
    checkError(listen(*serverFd, 1),"listen");
    checkError(*socketFd = accept(*serverFd, (struct sockaddr *)sAddress, (socklen_t *) aLen),"accept");

    if ((*socketFile = fdopen(*socketFd, "r")) == NULL) {
        checkError(-1,"fdopen");
    }
}

int main(int argc, char const *argv[]) {
	int serverFd, socketFd, opt = 1;
	struct sockaddr_in sAddress;
	int aLen = sizeof(sAddress);
	FILE* socketFile;

	init(&serverFd, &opt, &sAddress, &aLen, &socketFd, &socketFile);

	int count = 0;
    
    while (count < TOTAL_CH ) {
        ch_t challenge = challenges[count++];
        (challenge.number)();
        //ver como conseguir la resp 
        //con read??
        //checkAns(challange.ans)
        sleep(5);
        system("clear");
    }

    if (count >= TOTAL_CH)
        printf("Felicitaciones, finalizaron el juego. Ahora deberán implementar el servidor que se comporte como el servidor provisto\n");

    if (fclose(socketFile) == EOF) {
        checkError(-1,"fclose");
    }
    checkError(close(serverFd), "close");
    checkError(close(socketFd), "close");

    return 0;
}