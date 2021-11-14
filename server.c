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


ch challenges[TOTAL_CH] = {ch1, ch2, ch3, ch4, ch5,
                           ch6, ch7, ch8, ch9,
                           ch10, ch11, ch12};

char* resp[12] = {"entendido\n", "itba\n", "M4GFKZ289aku\n", "fk3wfLCm3QvS\n", "too_easy\n", ".RUN_ME\n", "K5n2UFfpFMUN\n", 
				"BUmyYq5XxXGt\n", "u^v\n", "chin_chu_lan_cha\n", "gdb_rules\n", "normal\n"};


int checkAns(char* answer, char* resp){

}

int main(int argc, char const *argv[]) {

    return 0;
} 