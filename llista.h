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

Llista llistaBIORDcrea(); 
void llistaBIORDdestrueix (Llista * l);
void llistaBIORDvesInici (Llista * l);
void llistaBIORDvesFinal (Llista * l);
void llistaBIORDesborra (Llista * l);
void llistaBIORDavanca (Llista * l);
void llistaBIORDretrocedeix (LLista * l);
Element llistaBIORDconsulta (Llista  l);
void llistaBIORDinsereixOrdenada (Llista * l, Element e);
int llistaBIORDfi (Llista l);
int llistaBIORDbuida (Llista l);
int llistaBIORDinici (Llista l);
