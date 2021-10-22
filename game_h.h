
#include "vehcule_h.h"
#include "solution_h.h"



#include "etat_h.h"

#ifndef game_h
#define game_h





typedef struct {

	int nb ;
    vehcule T[8];
	int M[6][6];



}game;

mvt* mvt_possible(int M[6][6], vehcule T[8],int *taille);
game init_game(char* file_name);
void affiche_game();
solution jouer(int M[6][6], vehcule T[8],int hauteur);
#endif

