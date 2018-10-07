/***********************************************
*
* @Proposit: Funcions necessaries per treballar amb les llistes
* @Autor/s: Josep Roig Torres
* @Data creacio: 05/10/2018
* @Data ultima modificacio: 07/10/2018
*
************************************************/
#ifndef _LLISTA_H
#define _LLISTA_H
//Definim els diferents tipus de registres necessaris
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
/****************************************************
 * 
 * @Finalitat: Crear la llista i definir el fantasma
 * @Parametres: ---
 * @Retorn: Retorna la llista ja definida
 * 
 ****************************************************/
Llista llistaBIORDcrea();
 /****************************************************
 * 
 * @Finalitat: Destruir la llista creada
 * @Parametres: in/out: l = Passem per referència la llista que volem destruir
 * @Retorn: ---
 * 
 ****************************************************/
void llistaBIORDdestrueix (Llista * l);
/****************************************************
 * 
 * @Finalitat: Torna al principi de la llista
 * @Parametres: in/out: l = Li passem la llista a la que li volem introduir els canvis (i com està per referència ens la retorna amb els canvis realitzats)
 * @Retorn: ---
 * 
 ****************************************************/
void llistaBIORDvesInici (Llista * l);
/****************************************************
 * 
 * @Finalitat: Va al final de la llista
 * @Parametres: in/out: l = Li passem la llista a la que li volem introduir els canvis (i com està per referència ens la retorna amb els canvis realitzats)
 * @Retorn: ---
 * 
 ****************************************************/
void llistaBIORDvesFinal (Llista * l);
/****************************************************
 * 
 * @Finalitat: Esborra l'element que esta en el nostre punt d'interes
 * @Parametres: in/out: l = Li passem la llista a la que li volem introduir els canvis (i com està per referència ens la retorna amb els canvis realitzats)
 * @Retorn: ---
 * 
 ****************************************************/
void llistaBIORDesborra (Llista * l);
/****************************************************
 * 
 * @Finalitat: Avancar a la seguent posició de la llista, sempre i quan es pugui
 * @Parametres: in/out: l = Llista en la que volem avançar 
 * @Retorn: ----
 * 
 ****************************************************/
void llistaBIORDavanca (Llista * l);
/****************************************************
 * 
 * @Finalitat: Retrocedeix a la anterior  posició de la llista, sempre i quan es pugui
 * @Parametres: in/out: l = Llista en la que volem retrocedir 
 * @Retorn: ---
 * 
 ****************************************************/
void llistaBIORDretrocedeix (Llista * l);
/****************************************************
 * 
 * @Finalitat: Extreu l'element que tenim al nostre punt d'interès
 * @Parametres: in: l = Li passem la llista de la que volem 
 * @Retorn: Retorna l'element que contenia el nostre punt d'interès
 * 
 ****************************************************/
Element llistaBIORDconsulta (Llista  l);
/****************************************************
 *
 * @Finalitat: Insereix nous elements a la llista, pero de forma ordenada
 * @Parametres: in/out: l = Li passem la llista a la que li volem introduir els canvis (i com està per referència ens la retorna amb els canvis realitzats)
 *              in: e = Element que volem introduir a la llista de forma ordenada
 * @Retorn: ---
 *
 ****************************************************/ 
void llistaBIORDinsereixOrdenada (Llista * l, Element e);
/****************************************************
 * 
 * @Finalitat: Indicar si estem al final de la llista
 * @Parametres: in: l = Llista sobre la qual volem realitzar la comprovació
 * @Retorn: Retorna si hem arribat al final
 * 
 ****************************************************/
int llistaBIORDfi (Llista l);
/****************************************************
 * 
 * @Finalitat: Indicar si la llista esta buida
 * @Parametres: in: l = Llista sobre la qual volem realitzar la comprovació
 * @Retorn: Retorna si esta buida
 * 
 ****************************************************/
int llistaBIORDbuida (Llista l);
/****************************************************
 * 
 * @Finalitat: Indicar si estem al inici  de la llista
 * @Parametres: in: l = Llista sobre la qual volem realitzar la comprovació
 * @Retorn: Retorna si hem arribat al inici
 * 
 ****************************************************/
int llistaBIORDinici (Llista l);

#endif
