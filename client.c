#include <arpa/inet.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define PORT 8080

int main(int argc, char **argv) {
    struct sockaddr_in serv_addr;
    char *first = "entendido\n";
    char buff[1024];
    int sock = socket(PF_INET, SOCK_STREAM, IPPROTO_IP);

    serv_addr.sin_family = AF_INET;

    send(sock , first , strlen(first) , 0 );
    send(sock,"itba\n",5,0);
    send(sock,"M4GFKZ289aku\n",13,0);
    send(sock,"fk3wfLCm3QvS\n",13,0);
}