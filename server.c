#include "server.h"

#include <unistd.h>
#include <stdio.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <string.h>
#include "challenges.h"

#define PORT 8080
#define SO_REUSEPORT 15


ch_t challenges[TOTAL_CH] = {{&ch1,"entendido\n"}, {&ch2,"itba\n"}, {&ch3, "M4GFKZ289aku\n"}, {&ch4, "fk3wfLCm3QvS\n"}, {&ch5, "too_easy\n"},
                           {&ch6, ".RUN_ME\n"}, {&ch7, "K5n2UFfpFMUN\n"}, {&ch8, "BUmyYq5XxXGt\n"}, {&ch9, "u^v\n"},
                           {&ch10, "chin_chu_lan_cha\n"}, {&ch11, "gdb_rules\n"}, {&ch12, "normal\n"}};

int checkAns(char* answer, char* resp){
	return 0;
}

int main(int argc, char const *argv[]) {
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

    return 0;
}