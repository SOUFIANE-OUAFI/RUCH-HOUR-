#include <stdio.h>
#include <stdlib.h>

#include "vehcule.c"
#include "game.c"

int main(int argc, char *argv[]) {

    int c;

    printf("choix de configuration: 1-configuration ,2-configuration\n");
    scanf("%d",&c);
    char* file_name;

    switch (c)
    {
        case 1: file_name="config2.txt";break;
        case 2: file_name="config3.txt";break;

         default:  break;
    }

	game g = init_game(file_name); 

	affiche(g);
	
	solution sol;
    int k,l;
    int M2[6][6];
    for(k=0;k<6;k++){
        for(l=0;l<6;l++) M2[k][l]=g.M[k][l];
    }

    vehcule T2[8];
    for(k=0;k<8;k++){
        T2[k]=g.T[k];
    }


    sol = jouer(M2,T2,0);
    
    printf("probleme est resolu ? %d\n",sol.resolu);

    if(sol.resolu==1){
        printf("voici la solution:\n");
        int i;
        for(i=0;i<sol.taille_pile;i++){
            printf("(%d,%d,%c)",sol.pile[i].v,sol.pile[i].pas,sol.pile[i].d);
        }
        printf("\n");
    }
    else printf("pas de solution avec au plus 9 mouvement");

    
    system("pause");
}

