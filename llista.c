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
llistaBIORDdestrueix (Llista * l) {
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


