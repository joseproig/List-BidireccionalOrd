include "llista.h"
#include <stdio.h>
#include <stdlib.h>
Llista llistaBIORDcrea () {
	Llista l;
	l.pri = (Node*) malloc (sizeof (Node));
	if ( l.pri != NULL) {
		l.ult = (Node*) malloc (sizeof(Node));
		if (l.ult != NULL) {
			(*(l.pri)).ant = NULL;
			(*(l.ult)).seg = NULL;
			l.pdi = l.pri;
			(*(l.pri)).seg = l.ult; 
		}
		else {
			printf ("\nError de memoria");
			free (l.pri);		
		}
	}
	else {
		printf ("\nError de memoria");	
	}
	return l;
}
void llistaBIORDdestrueix (Llista * l) {
        Node * aux;
        aux = (Node*) malloc (sizeof(Node));
        if (aux != NULL) {
                while ((*l).pri != NULL) {
                        aux = (*l).pri;
                        (*l).pri = (*(*l).pri).seg;
                        free (aux);
                }
        }
        else {
                printf ("\nError de memoria");
        }
}
void llistaBIORDvesInici (Llista * l) {
	(*l).pdi = (*(*l).pri).seg;
}
void llistaBIORDvesFinal (Llista * l) {
	(*l).pdi = (*(*l).ult).ant;
}
void llistaBIORDesborra (Llista * l) {
	aux = (Node*) malloc (sizeof(Node));
	if  (aux != NULL) {
		if ( (*l).pdi != (*l).pri && (*l).pdi != (*l).ult) { 
			aux = (*l).pdi;
			(*((*(*l).pdi).ant)).seg = (*(*l).pdi).seg;
			(*((*(*l).pdi).seg)).ant = (*(*l).pdi).ant;
			(*l).pdi = (*(*l).pdi).seg;
			free (aux);
		}
		else {
			printf ("\nError, el teu PDI no esta apuntant a un lloc correcte");
		}
	}
	else {
		printf ("Error de memoria");
	}
}
void llistaBIORDavanca (Llista * l) {
	(*l).pdi = (*(*l).pdi).seg;
}
void llistaBIORretrocedeix (Llista * l) {
	(*l).pdi = (*(*l).pdi).ant; 
}


