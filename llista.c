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

