#include "deplacement.h"




/*Renvoi le nombre de boule a deplacer pour la meme couleur*/
int nbBouleDeplace(Plateau *p, int **coor){



	if (coor[0][0]==2){
		return 1;
	}else {/* A finir */
		int dirBoules = direction(coor[1],coor[3]);
		int *caseSuivBoules = caseSuivant(p,coor[1], dirBoules);
		if (dirBoules!=-1 ){
			if(caseSuivBoules[0] == coor[2][0] && caseSuivBoules[1] == coor[2][1]){
				return 2;
			}
			else return 3;
		}
		return -1;
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
			if(coordonneesValides(casuiv[0], casuiv[1])!=-1){
				return casuiv;
			}
			else return NULL;
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
		case 4:
			printf("case suivante NON VIDE (deplace 2 boule)\n" );
			break;
		case 5:
			printf("case suivante NULL (deplace 1 boule)\n" );
			break;
	}

	return;
}

/*fonction gobale du deplacement*/
int deplacement(Plateau *p, int **coor,char couleur, int list){
	int *caseSuivDir; /*caseSuivBoule;*/
	int dirBoule, dirDep;


	switch(nbBouleDeplace(p,coor)){
		case 1:
			printf("DEPLACEMENT 1 boule s\n");

			dirDep = direction(coor[1],coor[2]);
			printf("%d\n",dirDep );
			if(dirDep!=-1){
		 		caseSuivDir = caseSuivant(p,coor[1], dirDep);
				if(caseSuivDir != NULL){
					if(p->tableau[caseSuivDir[0]][caseSuivDir[1]] == '.'){
						if (list==1){
							addToList(coor);
						}
						else {
							deplaceBoule(p,coor[1], caseSuivDir);
						}
						return 0;
					}
					else if (p->tableau[caseSuivDir[0]][caseSuivDir[1]] == couleur){/*Case suivante est de la meme couleur apel recursif*/
						int ** coordonnee = malloc( sizeof(int *)  *  4);
						coordonnee[0] = malloc( sizeof(int)  *  1);
						coordonnee[1] = malloc( sizeof(int)  *  2);
						coordonnee[2] = malloc( sizeof(int)  *  2);
						coordonnee[3] = malloc( sizeof(int)  *  2);

						coordonnee[0] = coor[0]+1;
						coordonnee[1] = coor[1];
						coordonnee[2] = caseSuivDir;
						coordonnee[3] = coor[2];


						if (list==1){
							int i;
							for (i = 0; i < 6; i++){
								int *casessuiv =caseSuivant(p,coor[1], i);
								coordonnee[2] = casessuiv;

									deplacement(p,coordonnee,couleur,list);
							}
						}
						else {
							deplacement(p,coordonnee,couleur,list);
						}
						free(coordonnee);
					}
					else {
						codeErreur(2); /*case suivante NON VIDE (deplace 1 boule)*/
						return -1;
					}

				}else {
					codeErreur(1); /*case suivante NULL (deplace 1 boule)*/
					return -1;
				}	
			}else{
				printf("Direction deplacement IMPOSSIBLE (1 boule)\n");
				return -1;
			}


			break;
		case 2:/*si on deplace 2 boules*/
			printf("DEPLACEMENT 2 boule s\n");
			dirBoule = direction(coor[1],coor[2]);
			dirDep = direction(coor[1],coor[3]);
			if (dirDep != -1 && dirBoule!=-1){

				if(couleur != p->tableau[coor[2][0]][coor[2][1]]){
					printf("err couleur \n");
					return -1;
				}


				if (dirDep == dirBoule){
					caseSuivDir = caseSuivant(p,coor[2], dirDep);
					if(caseSuivDir != NULL){
						if(p->tableau[caseSuivDir[0]][caseSuivDir[1]] == '.'){
							if (list==1){
								addToList(coor);
							}
							else {
								deplaceBoule(p,coor[2], caseSuivDir);
								deplaceBoule(p,coor[1], coor[2]);
							}


						}
						else if (couleur != p->tableau[caseSuivDir[0]][caseSuivDir[1]]){
							int * caseADeplacerD = caseSuivant(p,caseSuivDir, dirDep);
							if (caseADeplacerD != NULL){
								if(p->tableau[caseADeplacerD[0]][caseADeplacerD[1]] == '.'){
									if (list==1){
										addToList(coor);
									}
									else {
										deplaceBoule(p,caseSuivDir, caseADeplacerD);

										deplaceBoule(p,coor[2], caseSuivDir);
										deplaceBoule(p,coor[1], coor[2]);
									}


								}
								else {
									codeErreur(4); /*case suivante NON VIDE (deplace 1 boule)*/
									return -1;
								}	
							}
							else{
								if (list==1){
									addToList(coor);
								}
								else {
									deplaceBoule(p,coor[2], caseSuivDir);
									deplaceBoule(p,coor[1], coor[2]);
								}
							}	
						}
						else {
							printf("buguozhuo\n");

							if (list==1){
								int i;
								for (i = 0; i < 6; i++){
									int *casessuiv =caseSuivant(p,coor[1], i);
									coor[2] = casessuiv;
									deplacement(p,coor,couleur,list);
								}
							}
							else {
								coor[2] = caseSuivDir;
								deplacement(p,coor,couleur,list);
							}
						}	
					}else {
						codeErreur(5); /*case suivante NULL (deplace 1 boule)*/
						return -1;
					}
				}
				else{	
					int ** boule1, **boule2;
					boule1 = malloc( sizeof(int *)  *  3);
					boule1[0] = malloc( sizeof(int)  *  1);
					boule1[1] = malloc( sizeof(int)  *  2);
					boule1[2] = malloc( sizeof(int)  *  2);

					boule1[0][0] = 2;
					boule1[1] = coor[1];
					boule1[2] = coor[3];


					boule2 = malloc( sizeof(int *)  *  3);
					boule2[0] = malloc( sizeof(int)  *  1);
					boule2[1] = malloc( sizeof(int)  *  2);
					boule2[2] = malloc( sizeof(int)  *  2);


					boule2[0][0] = 2;
					boule2[1] = coor[2];
					boule2[2] = caseSuivant(p,coor[2], dirDep);



					deplacement(p,boule1,couleur,list );
					deplacement(p,boule2,couleur,list );
					free(coor);

				}




			}else {
				printf("Direction deplacement/Boule IMPOSSIBLE (2 boules)\n");
			}











			break;
		case 3: /*si on en deplace 3*/
			printf("DEPLACEMENT 3 BOULES\n");
			dirDep = direction(coor[1],coor[3]);
			dirBoule = directionTroisBoules(coor,p);

			if (dirDep == dirBoule){
				caseSuivDir = caseSuivant(p,coor[2], dirDep);
				if(caseSuivDir != NULL){
					if(p->tableau[caseSuivDir[0]][caseSuivDir[1]] == '.'){
							if (list==1){
								addToList(coor);
							}
							else {
								deplaceBoule(p,coor[2], caseSuivDir);
								caseSuivDir = caseSuivant(p,coor[1], dirDep);
								deplaceBoule(p,caseSuivDir, coor[2]);
								deplaceBoule(p,coor[1], coor[3]);
							}

					}
					else if (p->tableau[caseSuivDir[0]][caseSuivDir[1]] == couleur){
						codeErreur(5); /*case suivante NULL (deplace 1 boule)*/
						return -1;
					}
					else {
						int *caseSuivDir2 = caseSuivant(p,caseSuivDir, dirDep);
						if(caseSuivDir2 != NULL){
							if(p->tableau[caseSuivDir2[0]][caseSuivDir2[1]] == '.'){
								if (list==1){
									addToList(coor);
								}
								else {
									deplaceBoule(p,caseSuivDir, caseSuivDir2);
									deplaceBoule(p,coor[2], caseSuivDir);
									caseSuivDir = caseSuivant(p,coor[1], dirDep);
									deplaceBoule(p,caseSuivDir, coor[2]);
									deplaceBoule(p,coor[1], coor[3]);
								}


							}
							else if(p->tableau[caseSuivDir2[0]][caseSuivDir2[1]] == couleur){
								codeErreur(5); /*case suivante NULL (deplace 1 boule)*/
								return -1;
							}
							else {
								int *caseSuivDir3 = caseSuivant(p,caseSuivDir2, dirDep);
								if(caseSuivDir3 != NULL){
									if(p->tableau[caseSuivDir3[0]][caseSuivDir3[1]] == '.'){
										if (list==1){
											addToList(coor);
										}
										else {
											deplaceBoule(p,caseSuivDir2, caseSuivDir3);
												deplaceBoule(p,caseSuivDir, caseSuivDir2);
												deplaceBoule(p,coor[2], caseSuivDir);
												caseSuivDir = caseSuivant(p,coor[1], dirDep);
												deplaceBoule(p,caseSuivDir, coor[2]);
												deplaceBoule(p,coor[1], coor[3]);
										}	

									}
									else {
										codeErreur(5); /*case suivante NULL (deplace 1 boule)*/
										return -1;
									}
								}
								else {

									if (list==1){
										addToList(coor);
									}
									else {
										deplaceBoule(p,caseSuivDir, caseSuivDir2);
										deplaceBoule(p,coor[2], caseSuivDir);
										caseSuivDir = caseSuivant(p,coor[1], dirDep);
										deplaceBoule(p,caseSuivDir, coor[2]);
										deplaceBoule(p,coor[1], coor[3]);
									}	


								}

							}


						}
					}

				}
				else {
					codeErreur(5); /*case suivante NULL (deplace 1 boule)*/
					return -1;
				}
			}
			else if (dirBoule == -1 || dirDep == -1){
				printf("erreur rofjroforforjDCFVGBHNJ,IKOINBGVFCDXCFVGBHNJ,K\n");
				codeErreur(5);
				return -1;
			}
			else{


				printf("dirdep %d dirboule %d\n",dirDep,dirBoule);
				int ** boule1, **boule2, **boule3;
				boule1 = malloc( sizeof(int *)  *  3);
				boule1[0] = malloc( sizeof(int)  *  1);
				boule1[1] = malloc( sizeof(int)  *  2);
				boule1[2] = malloc( sizeof(int)  *  2);

				boule1[0][0] = 2;
				boule1[1] = coor[1];
				boule1[2] = coor[3];
				printf(" o = %d i = %d\n", coor[3][0],coor[3][1]);


				boule2 = malloc( sizeof(int *)  *  3);
				boule2[0] = malloc( sizeof(int)  *  1);
				boule2[1] = malloc( sizeof(int)  *  2);
				boule2[2] = malloc( sizeof(int)  *  2);

				printf("frfrfrfrfr\n");
				boule2[0][0] = 2;
				boule2[1] = caseSuivant(p,coor[1], dirBoule);
				boule2[2] = caseSuivant(p,boule2[1], dirDep);

				printf("efefzrgthyjrhtfzedszdfrteh\n");
				boule3 = malloc( sizeof(int *)  *  3);
				boule3[0] = malloc( sizeof(int)  *  1);
				boule3[1] = malloc( sizeof(int)  *  2);
				boule3[2] = malloc( sizeof(int)  *  2);

				boule3[0][0] = 2;
				boule3[1] = caseSuivant(p,boule2[1], dirBoule);
				boule3[2] = caseSuivant(p,boule3[1], dirDep);
				printf("ffffffffffffffffffffff\n");

				deplacement(p,boule3,couleur, list);
				printf("ggggggggggggg\n");
				deplacement(p,boule2,couleur,list);

				printf("tttttttttttttttt\n");
				deplacement(p,boule1,couleur,list);
				free(coor);
			}



			break;
		default : 
			printf("Deplacment impossible \n");
			return -1;
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
	codeErreur(3);/*	coordonnées non valide*/
	return -1;
}

char** listeToutDeplacement(Plateau *p, char color);




int direction(int *depart, int *arrivee){

	printf("START direction deplacement \n");

	printf("depart 0 %d, depart 1 %d\n", depart[0],depart[1]);
	printf("arrivee 0 %d, arrivee 1 %d\n", arrivee[0],arrivee[1]);


	printf("direction deplacement FIN\n");


	switch(depart[0]){
		case 0 :
		case 1 :
		case 2 :
		case 3 :
			/*printf("case -4\n");*/			
			if (depart[0]+1==arrivee[0] && depart[1]+1==arrivee[1]){
				/*printf("dir 0");			*/
				return 0;
			}

			else if (depart[0]+1==arrivee[0] && depart[1]==arrivee[1]){
				/*printf("dir 1\n");			*/
				return 1;
			}
			else if (depart[0]==arrivee[0] && depart[1]-1==arrivee[1]){
				/*printf("dir 2\n");			*/
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
int directionTroisBoules(int ** coor,Plateau *p){
	int ** dirrectionPossible = malloc(sizeof(int)*6);
	int i;
	for (i = 0; i < 6; i++){
		dirrectionPossible[i] = malloc(sizeof(int)*2);
		dirrectionPossible[i] = caseSuivant(p, coor[1], i);
		if(dirrectionPossible[i]!= NULL && direction(dirrectionPossible[i],coor[2]) != -1){
			printf("direction 3 boules = %d\n",i );
			return i;
		}

	}
	printf("ERREUR DIRECTION 3 BOULES\n");
	return -1;


}




int** pionsDeCouleur(Plateau *p, char couleur){
    /* Renvoi les coordonnées de tous les pions de couleur "couleur" présents sur le plateau */
    int i,j;
    int x = 0;
    int ** tab_pions;
    
    
    if(couleur == 'N')
        tab_pions = malloc( (14 - p->billesNoiresperdues) * sizeof(int));
    if(couleur == 'B')
        tab_pions = malloc( (14 - p->billesBlachesperdues) * sizeof(int));
    
    
    for(i = 0 ; i < 9 ; i++){
        for(j = 0 ; j < strlen(p->tableau[i]) ; j++){
            
            if(p->tableau[i][j] == couleur){
                
                tab_pions[x] = malloc( 2 * sizeof(int));
                tab_pions[x][0] = i;
                tab_pions[x][1] = j;
                x ++;
                
            }
            
        }
    }
    
    return tab_pions;
}

int* coord_random_pion(Plateau *p, int **coord_pions,char couleur){
    /* Renvoi les coordonnées d'un pion au hasard parmi un tableau de coordonnées*/
    int pions = 0;
    int *random = malloc(2 * sizeof(int));
    int **pions_possible = pionsDeCouleur(p, couleur);

    if(couleur == 'N')
        pions = 14 - p->billesNoiresperdues;
    if(couleur == 'B')
        pions = 14 - p->billesBlachesperdues;

    random = pions_possible[rand()%pions];
    
    return random;
}


int coupsPossible(Plateau *p, int *coord_depart, char couleur){
    /* Initialise les coups possible à partir d'un pion et les teste avec la fonction deplacement */
    int i, *caseSuivante;
    int y = 0;
    int ***deplacementPossible = malloc(6 * sizeof(int));
    
    for(i = 0 ; i <= 5 ; i++){
        y = 0;
        caseSuivante = caseSuivant(p, coord_depart, i);
        
        deplacementPossible[i] = malloc( 3 * sizeof(int));
        deplacementPossible[i][y] = malloc(sizeof(int));
        deplacementPossible[i][y][0] = 2;
        y +=1;
        
        deplacementPossible[i][y] = malloc( 2 * sizeof(int));
        
        deplacementPossible[i][y] = coord_depart;
	y+=1;
        deplacementPossible[i][y] = caseSuivante;
    }
    
    for(i = 0; i < 6 ; i++ ){
        deplacement(p,deplacementPossible[i],couleur,1);
    }
    
    return 0;
    
}



/*

si toute les boules son de la meme couleur 

si je deplace 1 boule 
	si la case suivante existe
		si la case suivante est vide 
			je deplace la boule

		si la case suivante est de la meme couleur
			RECURSION deplacement 2 boules
		si la case suivante est d'une couleur differente
			erreur deplacement impossible
	sinon 
		erreur
si je deplace 2 boules 
	si la direction des boules = direction des deplacements 
		si la case apres la 2 eme boule existe
			si la case est vide 
				je deplace les 2 boules 
			sinon si boule de la meme couleur 
				RECURSION deplacement 3 boules
			sinon 
				si la case apres est vide
					deplacement des 3 boules
				sinon 
					erreur
		sinon 
			je deplace les 2 boules (la boule tombe)
	sinon 
		REcursion deplacement 1boule pour les 2 boules 

si je deplace 3 boules
	si la direction des boules = direction des deplacements 
		si la case apres la 3 eme boules existe
			si case vide										
				je deplace les 2 boules 								BBB. 
			sinon si boule meme couleur 								BBBB
				erreur
			sinon 														BBBN
				si la case d'apres existe						
					si case vide 										BBBN.
						je deplace les 3 boules plus l'autre boule  
					sinon si boule meme couleur 						BBBNB
						erreur
					sinon 												BBBNN
						si la case d'apres existe						BBBNN
							si elle est vide 							BBBNN.
								deplace 5 boule
							sinon 
								erreur
						sinon 
							je deplace les 4 boules 1 boule tombe

				sinon
					je deplace les 3 boules (la boule tombe)


		sinon 
			erreur

	sinon 
		REcursion deplacement 1boule pour les 3 boules 



*/