ifndef _LLISTA_H
#define _LLISTA_H

typedef struct {
	char nom_persona [30];
	int edat;
} Element; 
typedef struct N {
	Element e;
	struct N * ant;
	struct N * seg;
} Node;
typedef struct {
	Node * pri;
	Node * ult;
	Node * pdi;
}Llista;

//PROCEDIMENTS I FUNCIONS

Llista llistaBIORDcrea ();
