#include "llista.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void main () {
	Llista l1;
	int i;
	Element e [10];
	Element element_aux;
	strcpy (e[0].nom_persona,"Josep");
	e[0].edat = 18;
	strcpy (e[2].nom_persona,"Torres");
	e[2].edat = 84;
	strcpy (e[1].nom_persona, "Roig");
	e[1].edat = 22;
	strcpy (e[3].nom_persona, "klk");
	e[3].edat = 33;
	strcpy (e[4].nom_persona,"LSnom");
	e[4].edat = 89;
	l1 = llistaBIORDcrea();
	llistaBIORDinsereixOrdenada (&l1,e[0]);
	if (llistaBIORDinici (l1)) {
		printf ("\nAra estic al principi de la llista\n");
	}
	llistaBIORDinsereixOrdenada (&l1,e[1]);
	llistaBIORDinsereixOrdenada (&l1,e[2]);
	llistaBIORDinsereixOrdenada (&l1,e[3]);
	llistaBIORDinsereixOrdenada (&l1, e[4]);
	llistaBIORDvesInici (&l1);
	i = 0;
	llistaBIORDesborra(&l1);
	while (i < 4) {
		element_aux = llistaBIORDconsulta (l1);
		printf ("Nom: %s - Edat: %d\n", element_aux.nom_persona, element_aux.edat);
		//Per evitar que surti l'error que estem accedint al fantasma
		if (i < 3) {								
			llistaBIORDavanca (&l1);
		}
		i++;
	}
	if (llistaBIORDfi (l1)) {
		printf ("\nAra estic al final de la llista\n");
	}
	llistaBIORDdestrueix (&l1);

}
