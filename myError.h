#ifndef MYERROR_H
#define MYERROR_H

#define myError(msg) do{ perror(msg); exit(EXIT_FAILURE); } while(0)

#define MAX_INPUT 100
#define ERROR -1

#endif 

// static char *ans[] = {
//     "entendido\n","itba\n","M4GFKZ289aku\n",
//     "fk3wfLCm3QvS\n","too_easy\n",".RUN_ME\n",
//     "K5n2UFfpFMUN\n","BUmyYq5XxXGt\n","u^v\n",
//     "chin_chu_lan_cha\n","gdb_rules\n","normal\n"}; 

// int main(int argc, char **argv) {
//     struct sockaddr_in server_addr;
//     int socketFd = 0 ;

//     if ((socketFd = socket(PF_INET, SOCK_STREAM, IPPROTO_IP)) < 0) {
//         printf("\n Socket creation error \n");
//         return -1;
//     }
//     printf("vas a frenar?\n");

//     server_addr.sin_family = AF_INET;
//     server_addr.sin_port = htons(PORT);

//     if(inet_pton(AF_INET, "127.0.0.1", &server_addr.sin_addr)<=0) {
//         printf("\nInvalid address/ Address not supported \n");
//         return -1;
//     }
//     if (( connect(socketFd, (struct sockaddr *)&server_addr, sizeof(server_addr))) < 0) {
//         printf("\nConnection Failed \n");
//         return -1;
//     }

//     printf("no...?fuck you\n");

//     int i;
//     for (i=0; i < TOTAL_CH; i++) {
//         if (write(socketFd , ans[i] , strlen(ans[i])) == -1) {
//             perror("write");
//             return -1;
//         }
//     }
//     printf("aaahhhhahahahahah\n");
//     close(socketFd);
//     return 0;
// }