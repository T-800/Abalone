#include "deplacement.h"



/*Renvoi le nombre de boule a deplacer pour la meme couleur*/
int nbBouleDeplace(Plateau *p, int **coor){
	if (coor[0][0]==2){
		return 1;
	}else {/* A finir */
		return 2;
	}
}

/*renvoi les coordonnées de la case suivante null si en dehors du plateau*/
int* caseSuivant(Plateau *p, int *coor, int direction){
	int *casuiv = malloc((sizeof(int)*2));
	casuiv[0] = -1;
	casuiv[1] = -1;
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
					default :
						printf("ff\n");
						return NULL;
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
		if (casuiv[0] != -1 && casuiv[1] != -1){
			printf("ff\n");
			return casuiv;
		}
		else return NULL;
		

}

/*deplace une boule */
int deplaceBoule(Plateau *p, int *depart, int *arrivee){ /*FINI*/
		p->tableau[arrivee[0]][arrivee[1]] = p->tableau[depart[0]][depart[1]];
		p->tableau[depart[0]][depart[1]] = '.';
		return 0;
}

/*affiche les codes erreurs*/
void codeErreur(int code){
	
	switch(code){
		case 1:
			printf("case suivante NULL (deplace 1 boule)\n" );
			break;
		case 2:
			printf("case suivante NON VIDE (deplace 1 boule)\n" );
			break;
		case 3:
			printf("coordonnées non valide\n" );
			break;
	}

	return;
}

/*fonction gobale du deplacement*/
int deplacement(Plateau *p, int **coor){
	
	int *caseSuiv;
	int dir;

	switch(nbBouleDeplace(p,coor)){
		case 1:
			dir = direction(coor[1],coor[2]);
			caseSuiv = caseSuivant(p,coor[1], dir);
			/*printf("arrivee %d %d\n",caseSuiv[0], caseSuiv[1] );*/
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
		case 2:/*si on deplace 2 boules*/
			caseSuiv = caseSuivant(p,coor[1], direction(coor[1],coor[3]));
			printf("arrivee %d %d\n",caseSuiv[0], caseSuiv[1] );


			

			break;
		case 3: /*si on en deplace 3*/
			break;
	}
	return 0;
}

/*int coordonneesValides(int coorA, int coorB){

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
	codeErreur(3)	coordonnées non valide
	return -1;
}
*/
char** listeToutDeplacement(Plateau *p, char color);

int directionBoules(int **coor){
	return 0;
}


int direction(int *depart, int *arrivee){

	printf("/* direction deplacement */\n");

	printf("depart 0 %d, depart 1 %d\n", depart[0],depart[1]);
	printf("arrivee 0 %d, arrivee 1 %d\n", arrivee[0],arrivee[1]);


	printf("/* direction deplacement */\n");


	switch(depart[0]){
		case 0 :
		case 1 :
		case 2 :
		case 3 :
			printf("case -4\n");			
			if (depart[0]+1==arrivee[0] && depart[1]+1==arrivee[1]){
				printf("dir 0");			
				return 0;
			}

			else if (depart[0]+1==arrivee[0] && depart[1]==arrivee[1]){
				printf("dir 1\n");			
				return 1;
			}
			else if (depart[0]==arrivee[0] && depart[1]-1==arrivee[1]){
				printf("dir 2\n");			
				return 2;
			}
			else if (depart[0]-1==arrivee[0] && depart[1]-1==arrivee[1]){
				printf("dir 3\n");			
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