#include "llista.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void main () {
	Llista l1;
	Element e1;
	Element e2;
	Element e3;
	Element e4;
	Element element_aux;
	strcpy (e1.nom_persona,"Josep");
	e1.edat = 18;
	strcpy (e3.nom_persona,"Torres");
	e3.edat = 84;
	strcpy (e2.nom_persona, "Roig");
	e2.edat = 22;
	strcpy (e4.nom_persona, "klk");
	e4.edat = 33;	
	llistaBIORDcrea();
	llistaBIORDinsereixOrdenada (&l1,e1);
	llistaBIORDinsereixOrdenada (&l1,e3);
	llistaBIORDinsereixOrdenada (&l1,e2);
	llistaBIORDinsereixOrdenada (&l1,e4);
	llistaBIORDavanca(&l1);
	llistaBIORDavanca (&l1);
	element_aux = llistaBIORDconsulta (l1);
	printf ("\n%s - %d", element_aux.nom_persona, element_aux.edat);
}
