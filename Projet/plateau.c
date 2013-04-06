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
	int modulo = 0;
	printf("       -----------\n    I / ");
	
	while (i < 9 ){
		if (modulo == 1){
			printf("\033[44m%c\033[0m ", p->tableau[i][j]);
		}
		else printf("%c ", p->tableau[i][j]);
        j++;
        	switch (i){
				case 0:
					if (j >= 5 ){
						i++;
         	  	     	j =0;
             		   	printf("\\ \n   H / ");
             		   	if(j%2 == 1) modulo = 0;
         	  	    	else modulo = 1;
					}
					else{
						if(j%2 == 0) modulo = 0;
         	  	    	else modulo = 1;
         	  	    }
					break;
				case 1:
					if (j >= 6 ){
						i++;
               			j =0;
              			printf("\\ \n  G / ");
              			if(j%2 == 0) modulo = 0;
         	  	    	else modulo = 1;
					}
					else{
						if(j%2 == 1) modulo = 0;
         	  	    	else modulo = 1;
         	  	    }
					break;
				case 2:
					if (j >= 7 ){
						i++;
                		j =0;
                		printf("\\ \n F / ");
                		if(j%2 == 1) modulo = 0;
         	  	    	else modulo = 1;
					}
					else{
						if(j%2 == 0) modulo = 0;
         	  	    	else modulo = 1;
         	  	    }
					break;
				case 3:
					if (j >= 8 ){
						i++;
                		j =0;
                		printf("\\ \nE | ");
                		if(j%2 == 0) modulo = 0;
         	  	    	else modulo = 1;
					}
					else{	
						if(j%2 == 1) modulo = 0;
         	  	    	else modulo = 1;
					}
					break;
				case 4:
					if (j >= 9 ){
						i++;
                		j =0;
                		printf("| \n D \\ ");
					}
					if(j%2 == 0) modulo = 0;
         	  	    else modulo = 1;
					break;
				case 5:
					if (j >=8 ){
						i++;
            		    j =0;
            		    printf("/ \n  C \\ ");
					}
					if(j%2 == 0) modulo = 0;
         	  	    else modulo = 1;
					break;
				case 6:
					if (j >= 7 ){
						i++;
            		    j =0;
            		    printf("/ 9\n   B \\ ");
					}
					if(j%2 == 0) modulo = 0;
         	  	    else modulo = 1;
					break;
				case 7:
					if (j >= 6 ){
						i++;
            		    j =0;
            		    printf("/ \033[44m8\033[0m\n    A \\ ");
					}
					if(j%2 == 0) modulo = 0;
         	  	    else modulo = 1;
					break;
				case 8:
					if (j >= 5 ){
						i++;
            		    j =0;
					}
					if(j%2 == 0) modulo = 0;
         	  	    else modulo = 1;
					break;
			}
    }

	printf("/ 7\n       ----------- \033[44m6\033[0m\n          1 \033[44m2\033[0m 3 \033[44m4\033[0m 5\n");

}



/*cette fo,ction affiche le plateau mais met en vert une case passé en argument 
A finir pour pouvoir mettree en couleur plusieur case*/
void affichagePlateauColor(Plateau *p, int pionX, int pionY){ 
		int j =0, i = 0;/*i = la ligne et j la colonne */
	int modulo = 0;
	printf("       -----------\n    I / ");
	
	while (i < 9 ){
		if (modulo == 1 && !(pionX == i && pionY == j)){
			printf("\033[44m%c\033[0m ", p->tableau[i][j]);
		}
		else if (pionX == i && pionY == j){
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
             		   	if(j%2 == 1) modulo = 0;
         	  	    	else modulo = 1;
					}
					else{
						if(j%2 == 0) modulo = 0;
         	  	    	else modulo = 1;
         	  	    }
					break;
				case 1:
					if (j >= 6 ){
						i++;
               			j =0;
              			printf("\\ \n  G / ");
              			if(j%2 == 0) modulo = 0;
         	  	    	else modulo = 1;
					}
					else{
						if(j%2 == 1) modulo = 0;
         	  	    	else modulo = 1;
         	  	    }
					break;
				case 2:
					if (j >= 7 ){
						i++;
                		j =0;
                		printf("\\ \n F / ");
                		if(j%2 == 1) modulo = 0;
         	  	    	else modulo = 1;
					}
					else{
						if(j%2 == 0) modulo = 0;
         	  	    	else modulo = 1;
         	  	    }
					break;
				case 3:
					if (j >= 8 ){
						i++;
                		j =0;
                		printf("\\ \nE | ");
                		if(j%2 == 0) modulo = 0;
         	  	    	else modulo = 1;
					}
					else{	
						if(j%2 == 1) modulo = 0;
         	  	    	else modulo = 1;
					}
					break;
				case 4:
					if (j >= 9 ){
						i++;
                		j =0;
                		printf("| \n D \\ ");
					}
					if(j%2 == 0) modulo = 0;
         	  	    else modulo = 1;
					break;
				case 5:
					if (j >=8 ){
						i++;
            		    j =0;
            		    printf("/ \n  C \\ ");
					}
					if(j%2 == 0) modulo = 0;
         	  	    else modulo = 1;
					break;
				case 6:
					if (j >= 7 ){
						i++;
            		    j =0;
            		    printf("/ 9\n   B \\ ");
					}
					if(j%2 == 0) modulo = 0;
         	  	    else modulo = 1;
					break;
				case 7:
					if (j >= 6 ){
						i++;
            		    j =0;
            		    printf("/ \033[44m8\033[0m\n    A \\ ");
					}
					if(j%2 == 0) modulo = 0;
         	  	    else modulo = 1;
					break;
				case 8:
					if (j >= 5 ){
						i++;
            		    j =0;
					}
					if(j%2 == 0) modulo = 0;
         	  	    else modulo = 1;
					break;
			}
    }

	printf("/ 7\n       ----------- \033[44m6\033[0m\n          1 \033[44m2\033[0m 3 \033[44m4\033[0m 5\n");

}
