#ifndef SO_TP3_SOCKETS_CHALLENGES_H
#define SO_TP3_SOCKETS_CHALLENGES_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TOTAL_CH 12

typedef int (*ch)(char *, size_t, FILE *);

int ch1(char *ans, size_t len, FILE *serverIn);

int ch2(char *ans, size_t len, FILE *serverIn);

int ch3(char *ans, size_t len, FILE *serverIn);

int ch4(char *ans, size_t len, FILE *serverIn);

int ch5(char *ans, size_t len, FILE *serverIn);

int ch6(char *ans, size_t len, FILE *serverIn);

int ch7(char *ans, size_t len, FILE *serverIn);

int ch8(char *ans, size_t len, FILE *serverIn);

int ch9(char *ans, size_t len, FILE *serverIn);

int ch10(char *ans, size_t len, FILE *serverIn);

int ch11(char *ans, size_t len, FILE *serverIn);

int ch12(char *ans, size_t len, FILE *serverIn);

#endif //SO_TP3_SOCKETS_CHALLENGES_H