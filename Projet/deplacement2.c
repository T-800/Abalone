#include "deplacement2.h"



/*Renvoi le nombre de boule a deplacer pour la meme couleur*/
int nbBouleDeplace(Plateau *p, int **coor){
	return 1;
}

/*renvoi les coordonnées de la case suivante null si en dehors du plateau*/
int* caseSuivant(Plateau *p, int *coor, int direction){
	int *casuiv = malloc((sizeof(int)*2));
	switch(coor[0]){
			case 0:
			case 1:
			case 2:
			case 3:
				printf("-4 direction %d\n",direction);
				switch(direction){
					case 0:
						casuiv[0] = coor[0]+1;
						casuiv[1] = coor[1]+1;
						break;
					case 1:
						casuiv[0] = coor[0]+1;
						casuiv[1] = coor[1];
						break;
					case 2:
						casuiv[0] = coor[0];
						casuiv[1] = coor[1]-1;
							break;
					case 3:
						casuiv[0] = coor[0]-1;
						casuiv[1] = coor[1]-1;
						break;
					

					case 4:
						casuiv[0] = coor[0]-1;
						casuiv[1] = coor[1];
						break;
					case 5:
						casuiv[0] = coor[0];
						casuiv[1] = coor[1]+1;
						break;	
				}
				break;
			case 4:
			printf("4 direction %d\n",direction);
				switch(direction){
					case 0:
						casuiv[0] = coor[0]+1;
						casuiv[1] = coor[1];
						break;
					case 1:
						casuiv[0] = coor[0]+1;
						casuiv[1] = coor[1]-1;
						break;
					case 2:
						casuiv[0] = coor[0];
						casuiv[1] = coor[1]-1;
							break;
					case 3:
						casuiv[0] = coor[0]-1;
						casuiv[1] = coor[1]-1;
						break;
					

					case 4:
						casuiv[0] = coor[0]-1;
						casuiv[1] = coor[1];
						break;
					case 5:
						casuiv[0] = coor[0];
						casuiv[1] = coor[1]+1;
						break;	
				}
				break;

			case 5:
			case 6:
			case 7:
			case 8:
			printf("+4 direction %d\n",direction);
				switch(direction){
					case 0:
						casuiv[0] = coor[0]+1;
						casuiv[1] = coor[1];
						break;
					case 1:
						casuiv[0] = coor[0]+1;
						casuiv[1] = coor[1]-1;
						break;
					case 2:
						casuiv[0] = coor[0];
						casuiv[1] = coor[1]-1;
							break;
					case 3:
						casuiv[0] = coor[0]-1;
						casuiv[1] = coor[1];
						break;
					

					case 4:
						casuiv[0] = coor[0]-1;
						casuiv[1] = coor[1]+1;
						break;
					case 5:
						casuiv[0] = coor[0];
						casuiv[1] = coor[1]+1;
						break;	
				}
				break;
			
			
		}
		return casuiv;

}

/*deplace une boule */
int deplaceBoule(Plateau *p, int *depart, int *arrivee){ /*FINI*/
		printf("fff\n");
		p->tableau[arrivee[0]][arrivee[1]] = p->tableau[depart[0]][depart[1]];
		p->tableau[depart[0]][depart[1]] = '.';
		printf("uytf\n");
		return 0;
}

/*affiche les codes erreurs*/
void codeErreur(int code){
	return;
}

/*fonction gobale du deplacement*/
int deplacement(Plateau *p, int **coor){
	
	int *caseSuiv;

	switch(nbBouleDeplace(p,coor)){
		case 1:
			caseSuiv = caseSuivant(p,coor[1], directionDeplacement(coor));
			printf("arrivee %d %d\n",caseSuiv[0], caseSuiv[1] );
			if(caseSuiv != NULL){
				if(p->tableau[caseSuiv[0]][caseSuiv[1]] == '.'){
					deplaceBoule(p,coor[1], caseSuiv);
					return 0;
				}else {
					codeErreur(2); /*case suivante NON VIDE (deplace 1 boule)*/
					return -1;
				}

			}else {
				codeErreur(1); /*case suivante NULL (deplace 1 boule)*/
				return -1;
			}


			break;
		case 2:

			break;
		case 3:
			break;
	}
	return 0;
}

int coordonneesValides(int coorA, int coorB){

	switch (coorA){

		case 0:
		case 8: 
			if (coorB < 5 && coorB>=0)return 0;
			break;
		case 1:
		case 7:
			if (coorB < 6 && coorB>=0)return 0;
			break;
		case 2: 
		case 6:
			if (coorB < 7 && coorB>=0)return 0;
			break;
		case 3:
		case 5: 
			if (coorB < 8 && coorB>=0)return 0;
			break;
		case 4: 
			if (coorB < 9 && coorB>=0)return 0;
			break;
	}
	return -1;
}
char** listeToutDeplacement(Plateau *p, char color);



int directionDeplacement(int **coor){
	int *depart, *arrivee;

	depart = coor[1];
	if(coor[0][0]==2)arrivee = coor[2];

	else arrivee= coor[3];


	printf("/* direction deplacement */\n");

	printf("depart 0 %d, depart 1 %d\n", depart[0],depart[1]);
	printf("arrivee 0 %d, arrivee 1 %d\n", arrivee[0],arrivee[1]);


	printf("/* direction deplacement */\n");


	switch(depart[0]){
		case 0 :
		case 1 :
		case 2 :
		case 3 :
			printf("case -4");			
			if (depart[0]+1==arrivee[0] && depart[1]+1==arrivee[1]){
				printf("dir 0");			
				return 0;
			}

			else if (depart[0]+1==arrivee[0] && depart[1]==arrivee[1]){
				printf("dir 1");			
				return 1;
			}
			else if (depart[0]==arrivee[0] && depart[1]-1==arrivee[1]){
				printf("dir 2");			
				return 2;
			}
			else if (depart[0]-1==arrivee[0] && depart[1]-1==arrivee[1]){
				printf("dir 3");			
				return 3;
			}
			else if (depart[0]-1==arrivee[0] && depart[1]==arrivee[1]){
				return 4;
			}
			else if (depart[0]==arrivee[0] && depart[1]+1==arrivee[1]){
				return 5;
			}
			break;
		


		case 4 :
			if (depart[0]+1==arrivee[0] && depart[1]==arrivee[1]){
				return 0;
			}
			else if (depart[0]+1==arrivee[0] && depart[1]-1==arrivee[1]){
				return 1;
			}
			else if (depart[0]==arrivee[0] && depart[1]-1==arrivee[1]){
				return 2;
			}
			else if (depart[0]-1==arrivee[0] && depart[1]-1==arrivee[1]){
				return 3;
			}
			else if (depart[0]-1==arrivee[0] && depart[1]==arrivee[1]){
				return 4;
			}
			else if (depart[0]==arrivee[0] && depart[1]+1==arrivee[1]){
				return 5;
			}
			break;
		
		case 5 :
		case 6 :
		case 7 :
		case 8 :
			if (depart[0]+1==arrivee[0] && depart[1]==arrivee[1]){
				return 0;
			}
			else if (depart[0]+1==arrivee[0] && depart[1]-1==arrivee[1]){
				return 1;
			}
			else if (depart[0]==arrivee[0] && depart[1]-1==arrivee[1]){
				return 2;
			}
			else if (depart[0]-1==arrivee[0] && depart[1]==arrivee[1]){
				return 3;
			}
			else if (depart[0]-1==arrivee[0] && depart[1]+1==arrivee[1]){
				return 4;
			}
			else if (depart[0]==arrivee[0] && depart[1]+1==arrivee[1]){
				return 5;
			}
			break;


			break;
	}


	return -1;



}