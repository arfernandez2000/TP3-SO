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

void ch1();

void ch2();

void ch3();

void ch4();

void ch5();

void ch6();

void ch7();

void ch8();

void ch9();

void ch10();

void ch11();

void ch12();

#endif //SO_TP3_SOCKETS_CHALLENGES_H