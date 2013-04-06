#include <stdio.h>
#include <stdlib.h>
#include "plateau.h"

Plateau creationPlateau(){
	Plateau plateau;
	
    plateau.tableau = malloc( sizeof(char *)  *  9);

	plateau.tableau[0] = malloc(sizeof(char) * 5);
	plateau.tableau[1] = malloc (sizeof(char) * 6);
	plateau.tableau[2] = malloc (sizeof(char) * 7);
	plateau.tableau[3] = malloc (sizeof(char) * 8);
	plateau.tableau[4] = malloc (sizeof(char) * 9);
	plateau.tableau[5] = malloc (sizeof(char) * 8);
	plateau.tableau[6] = malloc (sizeof(char) * 7);
	plateau.tableau[7] = malloc (sizeof(char) * 6);
	plateau.tableau[8] = malloc (sizeof(char) * 5);
	plateau.billesBlachesperdues = 0;
	plateau.billesNoiresperdues = 0;
	plateau.JoueurSuivant= 'Z';



    return plateau;
}

void affichagePlateau(Plateau *p){
	int j =0, i = 0;/*i = la ligne et j la colonne */
	printf("       -----------\n    I / ");
	
	while (i < 9 ){
		printf("%c ", p->tableau[i][j]);
        j++;
        	switch (i){
				case 0:
					if (j >= 5 ){
						i++;
         	  	     	j =0;
             		   	printf("\\ \n   H / ");
					}
					break;
				case 1:
					if (j >= 6 ){
						i++;
               			j =0;
              			printf("\\ \n  G / ");
					}
					break;
				case 2:
					if (j >= 7 ){
						i++;
                		j =0;
                		printf("\\ \n F / ");
					}
					break;
				case 3:
					if (j >= 8 ){
						i++;
                		j =0;
                		printf("\\ \nE | ");
					}
					break;
				case 4:
					if (j >= 9 ){
						i++;
                		j =0;
                		printf("| \n D \\ ");
					}
					break;
				case 5:
					if (j >=8 ){
						i++;
            		    j =0;
            		    printf("/ \n  C \\ ");
					}
					break;
				case 6:
					if (j >= 7 ){
						i++;
            		    j =0;
            		    printf("/ 9\n   B \\ ");
					}
					break;
				case 7:
					if (j >= 6 ){
						i++;
            		    j =0;
            		    printf("/ 8\n    A \\ ");
					}
					break;
				case 8:
					if (j >= 5 ){
						i++;
            		    j =0;
					}			
					break;
			}
    }

	printf("/ 7\n       ----------- 6\n          1 2 3 4 5\n");

	
}

/*cette fo,ction affiche le plateau mais met en vert une case passé en argument 
A finir pour pouvoir mettree en couleur plusieur case*/
void affichagePlateauColor(Plateau *p, int pionX, int pionY){ 
	int j =0, i = 0;/*i = la ligne et j la colonne */
	printf("       -----------\n    I / ");
	
	while (i < 9 ){
		if (pionX == i && pionY == j){
			printf("\033[42m%c\033[0m ", p->tableau[i][j]);
		}
		else printf("%c ", p->tableau[i][j]);
        j++;
        	switch (i){
				case 0:
					if (j >= 5 ){
						i++;
         	  	     	j =0;
             		   	printf("\\ \n   H / ");
					}
					break;
				case 1:
					if (j >= 6 ){
						i++;
               			j =0;
              			printf("\\ \n  G / ");
					}
					break;
				case 2:
					if (j >= 7 ){
						i++;
                		j =0;
                		printf("\\ \n F / ");
					}
					break;
				case 3:
					if (j >= 8 ){
						i++;
                		j =0;
                		printf("\\ \nE | ");
					}
					break;
				case 4:
					if (j >= 9 ){
						i++;
                		j =0;
                		printf("| \n D \\ ");
					}
					break;
				case 5:
					if (j >=8 ){
						i++;
            		    j =0;
            		    printf("/ \n  C \\ ");
					}
					break;
				case 6:
					if (j >= 7 ){
						i++;
            		    j =0;
            		    printf("/ 9\n   B \\ ");
					}
					break;
				case 7:
					if (j >= 6 ){
						i++;
            		    j =0;
            		    printf("/ 8\n    A \\ ");
					}
					break;
				case 8:
					if (j >= 5 ){
						i++;
            		    j =0;
					}			
					break;
			}
    }

	printf("/ 7\n       ----------  6\n          1 2 3 4 5\n");

	
}