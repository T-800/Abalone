#include "ia.h"

/*int ***coupsPossibles;
int x = 0;


void play(char color,Plateau *p){
	int a,i,d;
	extern int x;
	a = 0;
	int *pion_random = coord_random_pion(p, color);
	
	coupsPossible(p, pion_random, color);
	
	
	
    for(i = 0; i < x ; i++){
		

		for(d = 1; d < 3; d++){
			if(d == 1){
				
				
			}
			else{
				
			}
		}
	
    }
	
	
}

void addToList(int ** coor){
	extern int x;
	extern int ***coupsPossibles;
	if( x == 0){
		coupsPossibles = malloc(6*sizeof(int));
	}
	
	
	if(coor[0][0] == 2){
		coupsPossibles[x] = malloc(sizeof(int)*3);
		coupsPossibles[x][0] = malloc(sizeof(int)*1);
		coupsPossibles[x][1] = malloc(sizeof(int)*2);
		coupsPossibles[x][2] = malloc(sizeof(int)*2);
		coupsPossibles[x][0] = coor[0];
		coupsPossibles[x][1] = coor[1];
		coupsPossibles[x][2] = coor[2];
	}
	
	else{
		coupsPossibles[x] = malloc(sizeof(int)*4);
		coupsPossibles[x][0] = malloc(sizeof(int)*1);
		coupsPossibles[x][1] = malloc(sizeof(int)*2);
		coupsPossibles[x][2] = malloc(sizeof(int)*2);
		coupsPossibles[x][3] = malloc(sizeof(int)*2);
		coupsPossibles[x][0] = coor[0];
		coupsPossibles[x][1] = coor[1];
		coupsPossibles[x][2] = coor[2];
		coupsPossibles[x][3] = coor[3];
	}

	x++;


}*/

	static int *** coupsPossibles;
	static int tailleDeplacement, tailleListe;

int ** play(char color,Plateau *p){
	int i;
	
	coupsPossibles = malloc(sizeof(int**)*10);
	tailleDeplacement=0;
	tailleListe = 10;
	IA(p,color);
	
	for (i = 0; i < tailleDeplacement; i++){
		
		
		
	}
	int **coorRandom;
	int r = rand()%(tailleDeplacement-0) +0;
	
    coorRandom = coupsPossibles[r];
    
    return coorRandom;


}

void IA(Plateau *p, char couleur){
	int i,j,k;

	for(i = 0; i < 9; i++){
        for (j = 0; j < strlen(p->tableau[i]);j++){
        	if (p->tableau[i][j]==couleur){
        		for (k = 0; k < 6; k++){
        			
        			int **coor = malloc(sizeof(int)*3);
        			coor[0] = malloc(sizeof(int)*1);
        			coor[1] = malloc(sizeof(int)*2);
        			coor[2] = malloc(sizeof(int)*2);
        			coor[0][0] = 2;
        			coor[1][0] = i;
        			coor[1][1] = j;
        			int * caseSui = caseSuivant(p,coor[1], k);
        			 
        			if(caseSui != NULL){
        				
        				coor[2] = caseSui;
        				deplacement(p, coor,couleur, 1);	
        			}

        			
        		}
        	}
        }
    }
}

void addToList(int ** coor){
	if (tailleListe==tailleDeplacement){
		 tailleListe*=2;
		 

		coupsPossibles = realloc(coupsPossibles, sizeof(int**)*tailleListe);
		
	}
	if( coor[0][0]==2){
		coupsPossibles[tailleDeplacement] = malloc(sizeof(int*)  *  3);
		coupsPossibles[tailleDeplacement][0] = malloc(sizeof(int)  *  1);
		coupsPossibles[tailleDeplacement][1] = malloc( sizeof(int)  *  2);
		coupsPossibles[tailleDeplacement][2] = malloc( sizeof(int)  *  2);

		coupsPossibles[tailleDeplacement][0][0] = coor[0][0];
		coupsPossibles[tailleDeplacement][1] = coor[1];
		coupsPossibles[tailleDeplacement][2] = coor[2];
		
	}
	else{
		coupsPossibles[tailleDeplacement] = malloc(sizeof(int*)  *  4);
		coupsPossibles[tailleDeplacement][0] = malloc(sizeof(int)  *  1);
		coupsPossibles[tailleDeplacement][1] = malloc( sizeof(int)  *  2);
		coupsPossibles[tailleDeplacement][2] = malloc( sizeof(int)  *  2);
		coupsPossibles[tailleDeplacement][3] = malloc( sizeof(int)  *  2);

		coupsPossibles[tailleDeplacement][0][0] = coor[0][0];
		coupsPossibles[tailleDeplacement][1] = coor[1];
		coupsPossibles[tailleDeplacement][2] = coor[2];
		coupsPossibles[tailleDeplacement][3] = coor[3];
	}
	

	
	tailleDeplacement++;
	

}