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
	if (p->JoueurSuivant == 'N'){
		tour=1;
	}

	affichagePlateau(p);

	while(p->billesBlachesperdues < 6 && p->billesNoiresperdues < 6){
		
		switch(tour%2){
			case 0 :
				printf("\n\nTOUR BLANC\n\n");
				if (p->typeBlanc == 1){/* IA*/
					int ** coor =play('B',p);
                    sleep(1); 
    				deplacement(p,coor,'B',0);
    				p->JoueurSuivant = 'N';
				}
				else  { /*HUMAIN*/
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
						if(p->tableau[coordonnee[1][0]][coordonnee[1][1]]=='B'){
							if ( deplacement(p,coordonnee,'B',0) !=-1 ){
							 	p->JoueurSuivant = 'N';
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
					int ** coor =play('N',p);
					sleep(1);
					deplacement(p,coor,'N',0);
					p->JoueurSuivant = 'B';
				}
				else  { /*HUMAIN*/
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
							 	p->JoueurSuivant = 'B';
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
	if (p->billesNoiresperdues==6){
		printf("bille blanche perdu %d\n",p->billesBlachesperdues);
		printf("bille Noir perdu %d\n",p->billesNoiresperdues);
		printf("Blanc gagne\n");
	}else{
		printf("bille blanche perdu %d\n",p->billesBlachesperdues);
		printf("bille Noir perdu %d\n",p->billesNoiresperdues);
		printf("Noir gagne\n");
	}
	return 0;
}
