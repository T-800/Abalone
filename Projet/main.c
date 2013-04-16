#include <stdio.h>
#include <stdlib.h>

#include "plateau.h"
#include "fichier.h"
#include "clavier.h"
#include "option.h"

int main(int argc, char const *argv[]){
	


	int j,i;
    Plateau p = creationPlateau();

    optionGlobales(argv,argc,&p);

	
	char *coups = malloc(sizeof(char)*9);
	int **coordonnee;

	for(j = 0 ; j< argc; j++){
		printf("arg % d : %s\n", j+1, argv[j]);
	}
	printf("BLANC type : %d\n",p.typeBlanc);
	printf("NOIR type : %d\n",p.typeNoir);
	

	



	printf("\033[0m");
	if(i==0)affichagePlateau(&p);
	do{

		if(scanf("%s" ,coups) == EOF){
			return 1;
		}
		printf("\033[2J\033[1;1H");
		coordonnee = decoupageCoups(coups);
		if (coordonnee != NULL){
			affichagePlateauColor(&p,coordonnee[0][0],coordonnee[0][1] );
		}
		else printf("Connard\n");
	}while(coups[0] != 'z');
	
    return 0;
}
