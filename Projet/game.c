#include "game.h"


int gameTest(Plateau *p){ /*FINI*/
	 char *coups = malloc(sizeof(char)*9);
	int **coordonnee;
	affichagePlateau(p);

	while(scanf("%s" ,coups) != EOF){
		clear();
		coordonnee = decoupageCoups(coups);
		if (coordonnee != NULL){
			deplacement(p,coordonnee,p->tableau[coordonnee[1][0]][coordonnee[1][0]],0);
			affichagePlateau(p);
		}
		else printf("coups invalide\n");
	};
	sauvegarde(p);
	exit(0);
}

int gamePIA(Plateau *p){
	int tour =0;
	char *coups = malloc(sizeof(char)*9);
	int **coordonnee;

	affichagePlateau(p);

	while(/*p->billesBlachesperdues < 6 && p->billesNoiresperdues < 6*/1){
		
		switch(tour%2){
			case 0 :
				printf("\n\nTOUR BLANC\n\n");
				if (p->typeBlanc == 1){/* IA*/
					printf("IA\n");
					play('B',p);

				}
				else  { /*HUMAIN*/
					printf("HUMAIN\n");
					scanf("%s" ,coups);
					if (strcomp(coups,"SAVE")||strcomp(coups,"save")){	
						char continueJouer;
						sauvegarde(p);
						printf("Continuer à jouer ? [Y/n]\n");
						
						scanf("%s" ,&continueJouer);
						if (continueJouer == 'y' || continueJouer == 'Y'){
							scanf("%s" ,coups);
						}
						else return -1;
					}
					printf("effefef\n");
					coordonnee = decoupageCoups(coups);
					printf("egegrgrgrgrgr\n");
					if (coordonnee != NULL){
						if(p->tableau[coordonnee[1][0]][coordonnee[1][1]]=='B'){
							if ( deplacement(p,coordonnee,'B',0) !=-1 ){
							 	/* code */
							 }
							 else {
							 	tour--;
							 }
						}else{
							printf("ERREUR Tu ne peux pas deplacer ce pion\n");
							tour--;
						}
						
					}
					else{
						printf("coordonnées INVALIDE\n");
						tour--;
					}
				}
				tour++;

			
				break;
			case 1 : 
				printf("\n\nTOUR NOIR\n");
				if (p->typeNoir == 1){/* IA*/
					printf("IA\n");
					play('N',p);
				}
				else  { /*HUMAIN*/
					printf("HUMAIN\n");
					scanf("%s" ,coups);
					if (strcomp(coups,"SAVE")||strcomp(coups,"save")){	
						char continueJouer;
						sauvegarde(p);
						printf("Continuer à jouer ? [Y/n]\n");
						
						scanf("%s" ,&continueJouer);
						if (continueJouer == 'y' || continueJouer == 'Y'){
							scanf("%s" ,coups);
						}
						else return -1;
					}
					coordonnee = decoupageCoups(coups);
					if (coordonnee != NULL){
						if(p->tableau[coordonnee[1][0]][coordonnee[1][1]]=='N'){
							if ( deplacement(p,coordonnee,'N',0) !=-1 ){
							 	/* code */
							 }
							 else {
							 	tour--;
							 }
						}else{
							printf("ERREUR Tu ne peux pas deplacer ce pion\n");
							tour--;
						}
						
					}
					else{
						printf("coordonnées INVALIDE\n");
						tour--;
					}
				}
				tour++;
				
				break;
		}
		clear();
		affichagePlateau(p);	
	}
	return 0;
}