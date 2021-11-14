#ifndef CHALLENGES_H
#define CHALLENGES_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TOTAL_CH 12
#define ANS_SIZE 20
#define LOWER 70
#define UPPER 100
#define MIN_CHAR 33
#define MAX_CHAR 126

typedef struct {
    void (*number)();
    char ans[ANS_SIZE];
} ch_t;

int ch1();

int ch2();

int ch3();

int ch4();

int ch5();

int ch6();

int ch7();

int ch8();

int ch9();

int ch10();

int ch11();

int ch12();

#endif //SO_TP3_SOCKETS_CHALLENGES_H