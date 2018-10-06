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
        if ( (*(*l).pdi).seg != (*l).ult && (*(*l).pdi).seg != NULL) {
                (*l).pdi = (*(*l).pdi).seg;
        }
        else {
                printf ("Error, estas intentant accedir a posicions no disponibles o al fantasma");
        }
} 
void llistaBIORretrocedeix (Llista * l) {
        if ((*(*l).pdi).ant != (*l).pri && (*(*l).pdi).ant != NULL) {
                (*l).pdi = (*(*l).pdi).ant;
        }
        else {
                printf ("\nError, estas intentant accedir a posicions no disponibles o al fantasma");
        }
}
Element llistaBIORDconsulta (Llista  l) {
	return *(l.pdi).e;

}
void llistaBIORDinsereixOrdenat (Llista * l, Element e) {
	Node * aux;
	int trobat;
	if (aux != NULL) {
		(*aux).e.edat = e.edat
		strcpy ((*aux).e.nom_persona, e.nom_persona);
		(*l).pdi = (*l).pri);
		while ((*(*l).pdi).seg != (*l).ult && e.edat < (*(*l).pdi).e.edat) {	
			(*l).pdi = (*(*l).pdi).seg;
		}
		(*(*(*l).pdi).seg).ant = aux;
		(*(*l).pdi).seg = aux;
	}

}


