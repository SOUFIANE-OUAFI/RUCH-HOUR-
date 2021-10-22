#include "game_h.h"
#include "etat_h.h"
#include<stdio.h>
#include<stdlib.h>



int test_resolu(int M[6][6]){

    return M[2][5]==0;
}

// la fonction recursive qui parcours tout les possibilité tant que aucune solution n'est trouvé
solution jouer(int M[6][6], vehcule T[8],int hauteur){

	static solution sol;

	if(sol.resolu==0){
		int* taille;
		mvt* mvtp = mvt_possible(M,T,&taille);


		int i;
		for(i=0;i<*taille;i++){
			 if(sol.resolu==0){
			 	sol.pile[sol.taille_pile].v= mvtp[i].v;
			 	sol.pile[sol.taille_pile].d= mvtp[i].d;
			 	sol.pile[sol.taille_pile].pas= mvtp[i].pas;
			 	sol.taille_pile++;

			 }
			etat e_suiv = mouvement(M,T,mvtp[i].v,mvtp[i].pas,mvtp[i].d);
			 if(test_resolu(e_suiv.E)) sol.resolu=1;
			 if(hauteur+1<8) sol = jouer(e_suiv.E,T,hauteur+1);

			 // reverse la derniere mouvement
			 etat e_curr;
			if(mvtp[i].d=='d') e_curr= mouvement(M,T,mvtp[i].v,mvtp[i].pas,'g');
			if(mvtp[i].d=='g') e_curr= mouvement(M,T,mvtp[i].v,mvtp[i].pas,'d');
			if(mvtp[i].d=='b') e_curr= mouvement(M,T,mvtp[i].v,mvtp[i].pas,'h');
			if(mvtp[i].d=='h') e_curr= mouvement(M,T,mvtp[i].v,mvtp[i].pas,'b');

			 if(sol.resolu==0) {
				sol.taille_pile--;

			 	sol.pile[sol.taille_pile].v=-1;
			 	sol.pile[sol.taille_pile].d='/0';
			 	sol.pile[sol.taille_pile].pas=0;

			 }
		}

	}


	return sol;

}

// fonction qui liste les mouvement possible dans une situation mais on exclu les mouvement de la derniere voiture
// qui a été en mouvement,car il ya aucun reson de faire deplacer une voiture deux fois successive
mvt* mvt_possible(int M[6][6], vehcule T[8],int *taille ){

    mvt* l = malloc(32*sizeof(mvt));
    int cmp=0;
    int v;
    for(v=0;v<8;v++){



        if(T[v].h==1){
            int p;
            for(p=1;p<=4;p++){
                if(test_mouvement(M,T,v,p,'g')){
                    mvt m; m.v=v;m.pas=p;m.d='g';
                    l[cmp] = m;
                    cmp++;
                }
                if(test_mouvement(M,T,v,p,'d')){
                    mvt m; m.v=v;m.pas=p;m.d='d';
                    l[cmp] = m;
                    cmp++;
                }
            }
        }
        else{
            int p;
            for(p=1;p<=4;p++){
                if(test_mouvement(M,T,v,p,'h')){
                    mvt m; m.v=v;m.pas=p;m.d='h';
                    l[cmp] = m;
                    cmp++;
                }

                if(test_mouvement(M,T,v,p,'b')){
                    mvt m; m.v=v;m.pas=p;m.d='b';
                    l[cmp] = m;
                    cmp++;
                }
            }
        }

    }
    *taille=cmp;
    return l;
}




// affichage de la situation
void affiche(game g){

	int i;
	for( i=0;i<6;i++){

		printf("=============\n");
		printf("|");
		int j;
		for( j=0;j<6;j++){

			if(g.M[i][j]!=-1) printf("%i",g.M[i][j]);
			else printf(" ");
			if(i!=2||j!=5) printf("|");
		}
		printf("\n");


	}
	printf("=============\n");


}


// les configuration initial des parties
game init_game(char* file_name){

	game g;
    g.nb=8;

    vehcule T[8];
	FILE* f;
	int i;
	if((f = fopen(file_name,"r"))!=NULL){
		i=0;
		while(!feof(f)){
			fscanf(f,"%d %d %d %d %d",&T[i].h,&T[i].position,&T[i].inf,&T[i].sup,&T[i].id);
			i++;
		}

	}
	else{
		printf("Impossible d'ouvrir le fichier données en lecture\n");
   		exit(1);
	}
	fclose(f);

	for(i=0;i<6;i++){
        int j;
        for(j=0;j<6;j++){
            g.M[i][j]=-1;
        }

	}

	int inf,sup,h,position;

	for(i=0;i<8;i++){

		inf = T[i].inf;
		sup = T[i].sup;
		position = T[i].position;
		h = T[i].h;

		if(h){

			int j;
			for(j=inf;j<=sup;j++){


				g.M[position][j]=T[i].id;

			}

		}

		else {
			int j;
			for(j=inf;j<=sup;j++){
				g.M[j][position]=T[i].id;
			}
		}
	}

	for(i=0;i<8;i++) g.T[i]=T[i];
	return g;

}

