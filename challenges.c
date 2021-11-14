#include "challenges.h"

char* resp[12] = {"entendido\n", "itba\n", "M4GFKZ289aku\n", "fk3wfLCm3QvS\n", "too_easy\n", ".RUN_ME\n", "K5n2UFfpFMUN\n", 
				"BUmyYq5XxXGt\n", "u^v\n", "chin_chu_lan_cha\n", "gdb_rules\n", "normal\n"};

void messageCh(char* challenge){
	printf("------------- DESAFIO -------------\n");
	printf("%s\n", challange);
	printf("\n\n");
}

void messageQ(char* question){
	printf("----- PREGUNTA PARA INVESTIGAR -----\n");
	printf("%s\n", question);
}

void ch1(){
	messageCh("Bienvenidos al TP3 y felicitaciones, ya resolvieron el primer acertijo.\n\nEn este TP deberán finalizar el juego que ya comenzaron resolviendo los desafíos de cada nivel.\n
	Además tendrán que investigar otras preguntas para responder durante la defensa.\n
	El desafío final consiste en crear un programa que se comporte igual que yo, es decir, que provea los mismos desafíos y que sea necesario hacer lo mismo para resolverlos. No basta con esperar la respuesta.\n
	Además, deberán implementar otro programa para comunicarse conmigo.\n\n
	Deberán estar atentos a los easter eggs.\n\n
	Para verificar que sus respuestas tienen el formato correcto respondan a este desafío con la palabra 'entendido\\n'");
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
	messageCh("EBADF...\n\nwrite: Bad file descriptor");
	messageQ("¿Qué útil abstracción es utilizada para comunicarse con sockets? ¿se puede utilizar read(2) y write(2) para operar?");
}

void ch5(){
	messageCh("respuesta = strings:277");
	messageQ("¿Cómo garantiza TCP que los paquetes llegan en orden y no se pierden?");
}

void ch6(){
	messageCh(".data .bss .comment ? .shstrtab .symtab .strtab");
	messageQ("Un servidor suele crear un nuevo proceso o thread para atender las conexiones entrantes. ¿Qué conviene más?");
}

void ch7(){
	messageCh("Filter error\n\n" + filter("La respuesta es K5n2UFfpFMUN"));
	messageQ("¿Cómo se puede implementar un servidor que atienda muchas conexiones sin usar procesos ni threads?");
}

void ch8(){
	messageCh("¿?\n" + pinttBlack("La respuesta es BUmyYq5XxXGt"));
	messageQ("¿Qué aplicaciones se pueden utilizar para ver el tráfico por la red?");
}

void ch9(){
	messageCh("Latexme\n\n
	Si
	 \\mathrm{d}y = u^v{\\cdot}(v'{\\cdot}\\ln{(u)}+v{\\cdot}\\frac{u'}{u})
	entonces
	y =");
	messageQ("sockets es un mecanismo de IPC. ¿Qué es más eficiente entre sockets y pipes?");
}

void ch10(){
	messageCh("quine");
	messageQ("¿Cuáles son las características del protocolo SCTP?");
}

void ch11(){
	messageCh("b gdbme y encontrá el valor mágico");
	messageQ("¿Qué es un RFC?");

}

void ch12(){
	messageCh("Me conoces");
	messageQ("¿Fue divertido?");

}

//Felicitaciones, finalizaron el juego. Ahora deberán implementar el servidor que se comporte como el servidor provisto
