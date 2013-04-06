#include <stdio.h>
#include <stdlib.h>

#include "plateau.h"
#include "fichier.h"
#include "clavier.h"


int main(){
	
    Plateau p = creationPlateau();


	char *fic = "test.ab";
	char *coups = malloc(sizeof(char)*9);
	int i = fichierConfig(fic, &p);
	int **coordonnee;
	printf("\033[0m");
	if(i==0)affichagePlateau(&p);
	do{
		scanf("%s" , coups);

		coordonnee = decoupageCoups(coups);
		if (coordonnee != NULL){
			affichagePlateauColor(&p,coordonnee[0][0],coordonnee[0][1] );
		}
		else printf("Connard\n");
	}while(coups[0] != 'z');
	
    return 0;
}
