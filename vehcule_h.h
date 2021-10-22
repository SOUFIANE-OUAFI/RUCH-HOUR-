
#ifndef vehcule_h
#define vehcule_h


#include "etat_h.h"



typedef struct {
    int id ;

    int position;
    int inf;
    int sup ;
    int h ;
}vehcule;




int test_mouvement(int M[6][6], vehcule T[8] ,int id,int pas,char direction);

etat mouvement(int M[6][6],vehcule T[8] ,int id,int pas,char direction);



#endif

