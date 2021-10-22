#include <stdio.h>
#include <stdlib.h>
#include "vehcule_h.h"


// tester c'est um mouvemnt et possible
int test_mouvement(int M[6][6],vehcule T[8] ,int id,int pas,char direction){

    if(direction=='d'||direction=='b'){

        if(T[id].sup+pas>5) return 0;
    }

    else {

        if(T[id].inf-pas<0) return 0;
    }


    switch(direction){

		int i;
        case 'd' : {
                for( i=T[id].sup+1;i<=T[id].sup+pas;i++) if(M[T[id].position][i]!=-1) return 0;
                break;
        }

        case 'g' : {

                for(i=T[id].inf-1;i>=T[id].inf-pas;i--) if(M[T[id].position][i]!=-1) return 0;
                break;
        }

        case 'b': {
                for(i=T[id].sup+1;i<=T[id].sup+pas;i++) if(M[i][T[id].position]!=-1) return 0;
                break;
            }

        case 'h': {
            for(i=T[id].inf-1;i>=T[id].inf-pas;i--) if(M[i][T[id].position]!=-1) return 0;
            break;
        }

        default: return 0;
                  break;

    }

    return 1;

}


// faire un mouvement
etat mouvement(int M[6][6],vehcule T[8] ,int id,int pas,char direction){


	int i;
    if(direction=='d'||direction=='b'){


        for(i=T[id].inf; i<T[id].inf+pas; i++){

                if(T[id].h) M[T[id].position][i]=-1;
                else  M[i][T[id].position]=-1;
            }

        T[id].inf += pas;
        T[id].sup += pas ;
    }

    else{

            for(i=T[id].sup; i>T[id].sup-pas; i--){

                if(T[id].h) M[T[id].position][i]=-1;
                else  M[i][T[id].position]=-1;
            }

            T[id].inf -= pas;
            T[id].sup -= pas ;

    }

    for(i=T[id].inf;i<=T[id].sup;i++){

        if(T[id].h) M[T[id].position][i]=id;
        else  M[i][T[id].position]=id;

    }

	etat e;

	int k,j;
	for(k=0;k<6;k++){
		for(j=0;j<6;j++){
			e.E[k][j] = M[k][j];
		}

	}
    return e;

}



