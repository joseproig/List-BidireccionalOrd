#include "llista.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
Llista llistaBIORDcrea () {
	Llista l;
	l.pri = (Node*) malloc (sizeof (Node));
	//Comprovem que no hi hagi cap error en la creacio en el malloc
	if ( l.pri != NULL) {
		l.ult = (Node*) malloc (sizeof(Node));
		//Tornem a comprovar-ho
		if (l.ult != NULL) {
			//Els punters dels fantasmes que no entrin dins la llista els fiquem a NULL
			(*(l.pri)).ant = NULL;
			(*(l.ult)).seg = NULL;
			l.pdi = l.pri;
			(*(l.pri)).seg = l.ult;
			(*(l.ult)).ant = l.pri;
		}
		else {
			printf ("\nError de memoria");
			//Com que s'haura creat el malloc de l.pri pero no el de l.ult l'eliminem
			free (l.pri);		
		}
	}
	else {
		printf ("\nError de memoria");	
	}
	//Retornem la llista creada
	return l;
}
void llistaBIORDdestrueix (Llista * l) {
        Node * aux;
	aux = (Node*) malloc (sizeof(Node));
        if (aux != NULL) {
                //Anem eliminant les diferents posicions de la llista, des del principi, fins arribar al final
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
	//El principi passara a ser la posicio posterior al nostre fantasma que es la que hi ha informacio
	(*l).pdi = (*(*l).pri).seg;
}
void llistaBIORDvesFinal (Llista * l) {
	//El final passara a ser la posicio anterior al nostre fantasma que es la que hi ha informacio
	(*l).pdi = (*(*l).ult).ant;
}
void llistaBIORDesborra (Llista * l) {
	Node * aux;
	aux = (Node*) malloc (sizeof(Node));
	if  (aux != NULL) {
		//Esborrarem caselles sempre i quan aquestes no siguin els fantasmes
		if ( (*l).pdi != (*l).pri && (*l).pdi != (*l).ult) { 
			aux = (*l).pdi;
			//Fem que la posicio anterior al PDI i la seguent s'enllacin
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
        //Avancarem sempre i quan la seguent posicio no sigui un fantasma
	if ( (*(*l).pdi).seg != (*l).ult && (*(*l).pdi).seg != NULL) {
                (*l).pdi = (*(*l).pdi).seg;
        }
        else {
                printf ("Error, estas intentant accedir a posicions no disponibles o al fantasma");
        }
} 
void llistaBIORDretrocedeix (Llista * l) {
        //Retrocedirem, sempre i quan la posicio anterior no sigui un fantasma
	if ((*(*l).pdi).ant != (*l).pri && (*(*l).pdi).ant != NULL) {
                (*l).pdi = (*(*l).pdi).ant;
        }
        else {
                printf ("\nError, estas intentant accedir a posicions no disponibles o al fantasma");
        }
}
Element llistaBIORDconsulta (Llista  l) {
	//Retornme el valor del PDI
	return (*l.pdi).e;

}
void llistaBIORDinsereixOrdenada (Llista * l, Element e) {
	Node * aux;
	int trobat;
	aux = (Node*) malloc (sizeof (Node));
	if (aux != NULL) {
		//Copiem la informacio a la variable auxiliar
		(*aux).e.edat = e.edat;
		strcpy ((*aux).e.nom_persona, e.nom_persona);
		//Passem el nostre PDI a la seguent
		(*l).pdi = (*(*l).pri).seg;
		trobat = 0;
		//Fins que no arribem al fantasma utlim o no trobessim un major, anirem passant
		while ((*l).pdi != (*l).ult && !trobat) {
			if ((*(*l).pdi).e.edat > e.edat) { 
				trobat = 1;
			}
			else {
				(*l).pdi = (*(*l).pdi).seg;
			}
		}
		//El lloc on haurem sortit sera el que anira despres de la nova inclusio, per tant crearem un vincle entre l'anterior del PDI actual, la nova inclusió i el PDI 
		(*aux).ant = (*(*l).pdi).ant; 
		(*aux).seg = (*l).pdi;
		(*(*(*l).pdi).ant).seg = aux;
		(*(*l).pdi).ant = aux;
		//Un cop passada la informacio, el que fem es passar el PDI a la nova inclusió
		(*l).pdi = aux;
	}

}
int llistaBIORDfi (Llista  l) {
	//Comprovem que no sigui el final, osigui que el seguent del PDI apunti al fantasma 
	return (*l.pdi).seg == l.ult;
}
int llistaBIORDbuida (Llista l) {
	//Comprovem que el primer fantasma no apunti al segon
	return (*l.pri).seg == l.ult;
}
int llistaBIORDinici (Llista l) {
	//Comprovem qsi el seguent del nostre primer fantasma es el nostre PDI
	return l.pdi == (*l.pri).seg;
}

