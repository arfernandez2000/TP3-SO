#include <stdio.h>
int main(){
char*s="#include <stdio.h>%cint mainn(){%cchar*s=%c%s%c;%cprintf(s,10,10,34,s,34,10);return 0;}";
printf(s,10,10,34,s,34,10);return 0;}
printf("chau\n");