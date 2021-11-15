#include "challenges.h"

#define MAGIC_PID 0x12345678

static void messageCh(char* challenge){
	printf("------------- DESAFIO -------------\n");
	printf("%s\n\n", challenge);
}

static void messageQ(char* question){
	printf("----- PREGUNTA PARA INVESTIGAR -----\n");
	printf("%s\n", question);
}

static void filter(){
	char *str = "La respuesta es K5n2UFfpFMUN";
    int len = strlen(str);

    srand(time(NULL));

    for (int i = 0; i < len; i++) {
        int limit = (rand() % 11);
        for (int j = 0; j < limit; j++) {
            char toPrint[2] = {0};
            toPrint[0] = (rand() % (MAX_CHAR - MIN_CHAR + 1) + MIN_CHAR);
            write(STDERR_FILENO, toPrint, 1);
        }

        write(STDOUT_FILENO, str + i, 1);
    }
    printf("\n\n");
}

static void gdbme() {
    if (getpid() == MAGIC_PID) {
        printf("La respuesta es gdb_rules\n\n");
    } else {
        printf("ENTER para reintentar\n\n");
    }
}

void ch1(){
	messageCh("Bienvenidos al TP3 y felicitaciones, ya resolvieron el primer acertijo.\n\nEn este TP deberán finalizar el juego que ya comenzaron resolviendo los desafíos de cada nivel.\nAdemás tendrán que investigar otras preguntas para responder durante la defensa.\n El desafío final consiste en crear un programa que se comporte igual que yo, es decir, que provea los mismos desafíos y que sea necesario hacer lo mismo para resolverlos. No basta con esperar la respuesta.\nAdemás, deberán implementar otro programa para comunicarse conmigo.\n\nDeberán estar atentos a los easter eggs.\n\nPara verificar que sus respuestas tienen el formato correcto respondan a este desafío con la palabra 'entendido\\n'");
	messageQ("¿Cómo descubrieron el protocolo, la dirección y el puerto para conectarse?");
}

void ch2(){
	messageCh("The Wire S1E5\n\n5295 888 6288");
	messageQ("¿Qué diferencias hay entre TCP y UDP y en qué casos conviene usar cada uno?");
}

void ch3(){
	messageCh("https://ibb.co/tc0Hb6w");
	messageQ("¿El puerto que usaron para conectarse al server es el mismo que usan para mandar las respuestas? ¿Por qué?");
}

void ch4(){
	messageCh("EBADF...");

	char *str = "La respuesta es fk3wfLCm3QvS\n";
	if (write(13, str, strlen(str)) == -1)
        perror("write");
    printf("\n");
	messageQ("¿Qué útil abstracción es utilizada para comunicarse con sockets? ¿se puede utilizar read(2) y write(2) para operar?");
}

void ch5(){
	messageCh("respuesta = strings:194"); //PRESTAR ATENCION
	messageQ("¿Cómo garantiza TCP que los paquetes llegan en orden y no se pierden?");
}

void ch6(){
	messageCh(".plt.got .plt.sec .text ? .fini .rodata .eh_frame_hdr"); 
	messageQ("Un servidor suele crear un nuevo proceso o thread para atender las conexiones entrantes. ¿Qué conviene más?");
}

void ch7(){
	messageCh("Filter error");
	filter(); 
	messageQ("¿Cómo se puede implementar un servidor que atienda muchas conexiones sin usar procesos ni threads?");
}

void ch8(){
	messageCh("¿?");
	printf("\033[30;40mLa respuesta es BUmyYq5XxXGt\033[0m\n");
	messageQ("¿Qué aplicaciones se pueden utilizar para ver el tráfico por la red?");
}

void ch9(){
	messageCh("Latexme\n\nSi\n \\mathrm{d}y = u^v{\\cdot}(v\'{\\cdot}\\ln{(u)}+v{\\cdot}\\frac{u\'}{u})\nentonces\ny =");
	messageQ("sockets es un mecanismo de IPC. ¿Qué es más eficiente entre sockets y pipes?");
}

void ch10(){
	messageCh("quine");
	if (system("gcc quine.c -o quine") != 0){
        printf("\n\nENTER para reintentar.\n");
        return;
    }

    printf("¡Genial!, ya lograron meter un programa en quine.c, veamos si hace lo que corresponde.\n");

    if (system("./quine | diff - ./quine.c") != 0) {
        printf("\n%s\n", "diff encontró diferencias.");
        printf("\n\nENTER para reintentar.\n");
    } else{
        printf("La respuesta es chin_chu_lan_cha\n");
    }

	messageQ("¿Cuáles son las características del protocolo SCTP?");
}

void ch11(){
	messageCh("b gdbme y encontrá el valor mágico");

	gdbme();

	messageQ("¿Qué es un RFC?");
}

void ch12(){
	messageCh("Me conoces");

	int a = 0;
	int b = 1;
	int c = 1;
	for (int i = 0; i < 15; i++) {
		a = b;
		b = c;
		c = b + a;
		printf("%d  ",c);
	}
	printf("\n");

	messageQ("¿Fue divertido?");
}

