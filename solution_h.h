
#include "mvt_h.h"


#ifndef solution_h 
#define solution_h





typedef struct{
	mvt pile[11]; // la pile memorise la les chemin dans l'arbre de possibilité
	int taille_pile;
	int resolu; // pour savoir est ce que le contenu de la pile represente une solution

}solution;

#endif
