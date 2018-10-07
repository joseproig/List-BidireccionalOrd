#include "llista.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
			(*(l.ult)).ant = l.pri;
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
	Node * aux;
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
        if ( (*(*l).pdi).seg != (*l).ult && (*(*l).pdi).seg != NULL) {
                (*l).pdi = (*(*l).pdi).seg;
        }
        else {
                printf ("Error, estas intentant accedir a posicions no disponibles o al fantasma");
        }
} 
void llistaBIORDretrocedeix (Llista * l) {
        if ((*(*l).pdi).ant != (*l).pri && (*(*l).pdi).ant != NULL) {
                (*l).pdi = (*(*l).pdi).ant;
        }
        else {
                printf ("\nError, estas intentant accedir a posicions no disponibles o al fantasma");
        }
}
Element llistaBIORDconsulta (Llista  l) {
	return (*l.pdi).e;

}
void llistaBIORDinsereixOrdenada (Llista * l, Element e) {
	Node * aux;
	int trobat;
	aux = (Node*) malloc (sizeof (Node));
	if (aux != NULL) {
		(*aux).e.edat = e.edat;
		strcpy ((*aux).e.nom_persona, e.nom_persona);
		(*l).pdi = (*(*l).pri).seg;
		trobat = 0;
		while ((*l).pdi != (*l).ult && !trobat) {
			if ((*(*l).pdi).e.edat > e.edat) { 
				trobat = 1;
			}
			else {
				(*l).pdi = (*(*l).pdi).seg;
			}
		}
		(*aux).ant = (*(*l).pdi).ant; 
		(*aux).seg = (*l).pdi;
		(*(*(*l).pdi).ant).seg = aux;
		(*(*l).pdi).ant = aux;
		(*l).pdi = aux;
	}

}
int llistaBIORDfi (Llista  l) {
	return (*l.pdi).seg == l.ult;
}
int llistaBIORDbuida (Llista l) {
	return (*l.pri).seg == l.ult;
}
int llistaBIORDinici (Llista l) {
	return l.pdi == (*l.pri).seg;
}

