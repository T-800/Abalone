#include "game.h"


int gameTest(Plateau *p){
	 char *coups = malloc(sizeof(char)*9);
	int **coordonnee;
	affichagePlateau(p);

	do{

		if(scanf("%s" ,coups) == EOF){
			return 1;
		}
		
		clear();
		coordonnee = decoupageCoups(coups);
		if (coordonnee != NULL){
			printf("00000\n");
			if(/*deplacementAutoriser(p,coordonnee)==0*/1){
				printf("1111\n");
				deplacement(p,coordonnee);
				printf("452313\n");
			}
			affichagePlateau(p);
		}
		else printf("Connard\n");
	}while(coups[0] != 'z');
	exit(0);
}

/*int gamePIA(Plateau *p){
	int tour =0;
	char *coups = malloc(sizeof(char)*9);
	int **coordonnee;

	affichagePlateau(p);
	while(p->billesBlachesperdues < 6 && p->billesNoiresperdues < 6){
		scanf("%s" ,coups);
		coordonnee = decoupageCoups(coups);
		if (coordonnee != NULL){
			switch(tour%2){
			case 0 :
				if(deplacementAutoriser(p,coordonnee,'N')==0){
					printf("1111\n");
					deplacement2(p,coordonnee);
					printf("TOUR BLANC\n");
				}
			
				break;
			case 1 : 
				if(deplacementAutoriser(p,coordonnee,'B')==0){
					printf("1111\n");
					deplacement2(p,coordonnee);
					printf("452313\n");
					printf("TOUR NOIR\n");
				}
				
				break;
			}
			affichagePlateau(p);
		}
		else printf("Connard\n");

		
	}
}*/