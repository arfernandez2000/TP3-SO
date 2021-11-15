#include "client.h"

#define PORT 8080
#define LOCALHOST "127.0.0.1"
#define TOTAL_CH 12

extern int errno;
typedef struct sockaddr_in server_addr;

static void getAns(int serverFd);
void closeS(int socketFd);
int openS(server_addr *addr);
void connectS(int sock, server_addr *addr, int addrLen);
int waitConnection(int serverFd, server_addr *addr, int addrLen);
int createServ(server_addr *addr);


int main(int argc, char const *argv[]) {
    int sock;
    server_addr serverAddr;

    sock = openS(&serverAddr);
    connectS(sock, &serverAddr, sizeof(serverAddr));

    getAns(sock);

    return 0;
}

static void getAns(int serverFd) {
    char *buffer;
    size_t bufferLen = MAX_INPUT;
    if ((buffer = calloc(bufferLen, sizeof(char))) == NULL) {
        myError("alloc failed");
    }

    int playing = 1;
    while (playing) {
        memset(buffer, 0, bufferLen);

        int previousErrno = errno;
        if (getline(&buffer, &bufferLen, stdin) == ERROR) {
            if (previousErrno == errno) {
                playing = 0;
            } else {
                myError("getline failed");
            }
        }

        if (playing) {
            int readChars = strlen(buffer);
            if (readChars > 0) {
                int sentChars = write(serverFd, buffer, readChars);
                if (sentChars == ERROR) {
                    myError("write failed");
                }
                if (sentChars == 0) {
                    playing = 0;
                }
            }
        }
    }

    closeS(serverFd);
    free(buffer);
}

int openS(server_addr *addr) {
    int serverFd;

    memset(addr, 0, sizeof(server_addr));

    // Creating socket file descriptor
    if ((serverFd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        myError("socket failed");
    }

    addr->sin_family = AF_INET;
    addr->sin_port = htons(PORT);

    return serverFd;
}

int createServ(server_addr *addr) { //también se podría manejar con un flag en openS
    int serverFd = openS(addr);
    addr->sin_addr.s_addr = INADDR_ANY;

    int opt = 1;

    // Forcefully attaching socket to the port 8080
    if (setsockopt(serverFd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        myError("setsockopt failed");
    }

    return serverFd;
}

int waitConnection(int serverFd, server_addr *addr, int addrLen) {
    // Forcefully attaching socket to the port 8080
    int connectedFd;

    if (bind(serverFd, (struct sockaddr *) addr, addrLen) < 0) {
        myError("bind failed");
    }

    if (listen(serverFd, 3) < 0) {
        myError("listen failed");
    }

    if ((connectedFd = accept(serverFd, (struct sockaddr *) addr, (socklen_t * ) & addrLen)) < 0) {
        myError("accept failed");
    }

    return connectedFd;
}

void connectS(int sock, server_addr *addr, int addrLen) {
    if (inet_pton(AF_INET, LOCALHOST, &addr->sin_addr) <= 0) {
        myError("Invalid address");
    }

    if(connect(sock, (struct sockaddr *) addr, addrLen) < 0) {
        myError("connect Failed");
    }
}

void closeS(int socketFd) {
    if (close(socketFd) == ERROR) {
        myError("close failed");
    }
    printf("cerrando sockets\n");
}


