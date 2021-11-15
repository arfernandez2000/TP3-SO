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
#include "../myError.h"

#define PORT 8080
#define SO_REUSEPORT 15


ch_t challenges[TOTAL_CH] = {{&ch1,"entendido\n"}, {&ch2,"itba\n"}, {&ch3, "M4GFKZ289aku\n"}, {&ch4, "fk3wfLCm3QvS\n"}, {&ch5, "too_easy\n"},
                           {&ch6, ".RUN_ME\n"}, {&ch7, "K5n2UFfpFMUN\n"}, {&ch8, "BUmyYq5XxXGt\n"}, {&ch9, "u^v\n"},
                           {&ch10, "chin_chu_lan_cha\n"}, {&ch11, "gdb_rules\n"}, {&ch12, "normal\n"}};

int checkAns(char* answer, char* resp){
	if (strcmp(answer,resp)!=0) {
        printf("\nWrong answer: %s\n",resp);
        sleep(2);
        return 0;
    }
    return 1;
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
    if((*serverFd = socket(AF_INET, SOCK_STREAM, 0)) == ERROR){
	   myError("socket failed");
    }
    if(setsockopt(*serverFd, SOL_SOCKET, SO_REUSEADDR, opt, sizeof(*opt)) == ERROR){
       myError("setsockopt failed");
    }

    sAddress->sin_family = AF_INET;
    sAddress->sin_addr.s_addr = INADDR_ANY;
    sAddress->sin_port = htons(PORT);

    if(bind(*serverFd, (struct sockaddr *)sAddress, sizeof(*sAddress)) == ERROR){
       myError("bind failed");
    }
    if(listen(*serverFd, 1) == ERROR){
       myError("listen failed");
    }
    if((*socketFd = accept(*serverFd, (struct sockaddr *)sAddress, (socklen_t *) aLen)) == ERROR){
       myError("accept failed");
    }


    if ((*socketFile = fdopen(*socketFd, "r")) == NULL) {
        myError("fdopen failed");
    }
}

int main(int argc, char const *argv[]) {
	int serverFd, socketFd, opt = 1;
	struct sockaddr_in sAddress;
	int aLen = sizeof(sAddress);
	FILE* socketFile;

	init(&serverFd, &opt, &sAddress, &aLen, &socketFd, &socketFile);

	int count = 0;
    char *buffer = NULL;
    size_t buffSize = 0;

    system("clear");

    while (count < TOTAL_CH ) {
        ch_t challenge = challenges[count];
        (challenge.func)();
 
        if (getline(&buffer,&buffSize,socketFile) > 0){
            count += checkAns(challenge.ans,buffer);
        } else {
            perror("getline");
            return -1;
        }
        system("clear");        
    }

    if (count >= TOTAL_CH)
        printf("Felicitaciones, finalizaron el juego. Ahora deberán implementar el servidor que se comporte como el servidor provisto\n");

    free(buffer);

    if (fclose(socketFile) == EOF) {
        myError("fclose failed");
    }

    if (close(serverFd) == ERROR) {
        myError("close1 failed");
    }

    printf("%d\n", socketFd);

    if (close(socketFd) == ERROR) {
        myError("close2 failed");
    }

    return 0;
}