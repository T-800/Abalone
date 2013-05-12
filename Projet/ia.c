#include "ia.h"

	static int *** coupsPossibles;
	static int tailleDeplacement, tailleListe;

int ** play(char color,Plateau *p){
	
	/* Fonction générant un coup aléatoire :
	 * Recherche tous les mouvements possibles pour les pions de la couleur passé en argument,
	 * et renvoi une de ces possiilité choisi aléatoirement */
	
	int **coorRandom;
	int r;
	
	coupsPossibles = malloc(sizeof(int**)*10);
	tailleDeplacement=0;
	tailleListe = 10;
	IA(p,color);
	
	r = rand()%(tailleDeplacement-0) +0;
	
    coorRandom = coupsPossibles[r];
    
    return coorRandom;


}

void IA(Plateau *p, char couleur){
	
	/*Teste tous les pions de couleur "couleur" et stocke toutes les coordonnées de mouvements possibles pour ceux-ci */
	
	int i,j,k;
	int * caseSui;

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
        			caseSui = caseSuivant(p,coor[1], k);
        			 
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
	
	/* Ajoute une possibilité de deplacement à la liste coupsPossibles */
	
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