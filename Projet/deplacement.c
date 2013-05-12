#include "deplacement.h"




/*Renvoi le nombre de boule a deplacer pour la meme couleur*/
int nbBouleDeplace(Plateau *p, int **coor){
	if (coor[0][0]==2){
		return 1;
	}else {
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


/*renvoi les coordonnées de la case suivante en fonction de la direction null si en dehors du plateau*/
int* caseSuivant(Plateau *p, int *coor, int direction){
	int *casuiv = malloc((sizeof(int)*2));
	casuiv[0] = -1;
	casuiv[1] = -1;
	
	switch(coor[0]){
			case 0:
			case 1:
			case 2:
			case 3:
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
						return NULL;
				}
				break;
			case 4:
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


/*fonction gobale du deplacement*/
int deplacement(Plateau *p, int **coor,char couleur, int list){
	int *caseSuivDir; /*caseSuivBoule;*/
	int dirBoule, dirDep;

	switch(nbBouleDeplace(p,coor)){
		case 1:/*SI je depplace une boule*/
			dirDep = direction(coor[1],coor[2]);
			if(dirDep!=-1){
		 		caseSuivDir = caseSuivant(p,coor[1], dirDep);
				if(caseSuivDir != NULL){
					if(p->tableau[caseSuivDir[0]][caseSuivDir[1]] == '.'){/*case d'arrivé libre deplacement*/
						if (list==1){
							addToList(coor);
							 
							
						}
						else {
							deplaceBoule(p,coor[1], caseSuivDir);
						}
						return 0;
					}
					else if (p->tableau[caseSuivDir[0]][caseSuivDir[1]] == couleur){/*Case suivante est de la meme couleur apel recursif avec 2 boules*/
						int ** coordonnee = malloc( sizeof(int *)  *  4);
						coordonnee[0] = malloc(sizeof(int)  *  1);
						coordonnee[1] = malloc( sizeof(int)  *  2);
						coordonnee[2] = malloc( sizeof(int)  *  2);
						coordonnee[3] = malloc( sizeof(int)  *  2);

						coordonnee[0][0] = coor[0][0]+1;/*3*/
						coordonnee[1] = coor[1];
						coordonnee[2] = caseSuivDir;
						coordonnee[3] = coor[2];

						deplacement(p,coordonnee,couleur,list);
						free(coordonnee);
					}
					else {
						printf("case arrivé NON VIDE boule adverse (deplace 1 boule)\n");
						return -1;
					}

				}else {
					printf("case arrivé NULL(en dehors du plateau) (deplace 1 boule)\n");
					return -1;
				}	
			}else{
				printf("Deplacement impssible cases non adjacente\n");
				return -1;
			}
			break;
		case 2:/*si on deplace 2 boules*/
			dirBoule = direction(coor[1],coor[2]);
			dirDep = direction(coor[1],coor[3]);
			if (dirDep != -1 && dirBoule!=-1){
				if(couleur != p->tableau[coor[2][0]][coor[2][1]]){ 
					printf("Les 2 boules à deplacer ne sont pas de la meme couleur\n");
					return -1;
				}
				if (dirDep == dirBoule){/*Si le sense de deplacement est egale au sense des boules */
					caseSuivDir = caseSuivant(p,coor[2], dirDep);
					if(caseSuivDir != NULL){
						if(p->tableau[caseSuivDir[0]][caseSuivDir[1]] == '.'){/*case d'arrivé libre deplacement*/
							if (list==1){
								addToList(coor);
							}
							else {
								deplaceBoule(p,coor[2], caseSuivDir);
								deplaceBoule(p,coor[1], coor[2]);
							}
						}
						else if (couleur != p->tableau[caseSuivDir[0]][caseSuivDir[1]]){/*case d'arrivé contien bille adverse*/
							int * caseADeplacerD = caseSuivant(p,caseSuivDir, dirDep);
							if (caseADeplacerD != NULL){/*si la case apres la bille averse est dansle plateau  */
								if(p->tableau[caseADeplacerD[0]][caseADeplacerD[1]] == '.'){/*si la case est vide on deplace */
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
									printf("Case apres la bille adverse non vide deplacement 2 boules \n"); /*case suivante NON VIDE (deplace 1 boule)*/
									return -1;
								}	
							}
							else{/*si la case apres la bille averse est en dehors du plateau on fait tomber la bille */
								if (list==1){
									addToList(coor);
								}
								else {
									deplaceBoule(p,coor[2], caseSuivDir);
									deplaceBoule(p,coor[1], coor[2]);
									if (couleur == 'B'){
										p->billesNoiresperdues++;
									}else{
										p->billesBlachesperdues++;
									}
								}
							}	
						}
						else {/*Case suivante est de la meme couleur apel recursif avec 3 boules*/
							coor[2] = caseSuivDir;
							deplacement(p,coor,couleur,list);
						}	
					}else {
						printf("case arrivé NULL(en dehors du plateau) (deplace 2 boule)\n");
						return -1;
					}
				}
				else{/*Si le sense de deplacement est different au sense des boules */	
					/*appel 2 fois deplacement 1boule pour les 2 boules */
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
				printf("Deplacement impssible cases non adjacente\n");
				return -1;
			}
			break;
		case 3: /*si on en deplace 3*/
			dirDep = direction(coor[1],coor[3]);
			dirBoule = directionTroisBoules(coor,p);
			if (dirBoule == -1 || dirDep == -1){
				
				printf("Deplacement impssible cases non adjacente ou boules trop eloigné\n");
				return -1;
			}
			else if (dirDep == dirBoule){/*Si le sense de deplacement est egale au sense des boules */
				caseSuivDir = caseSuivant(p,coor[2], dirDep);
				if(caseSuivDir != NULL){
					if(p->tableau[caseSuivDir[0]][caseSuivDir[1]] == '.'){/*case d'arrivé libre deplacement*/
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
					else if (p->tableau[caseSuivDir[0]][caseSuivDir[1]] == couleur){ /*Case suivante est de la meme deplacment 3 boules max*/
						printf("Case suivante est de la meme couleur deplacment 3 boules max\n");
						return -1;
					}
					else {/*case d'arrivé contien bille adverse*/
						int *caseSuivDir2 = caseSuivant(p,caseSuivDir, dirDep);
						if(caseSuivDir2 != NULL){
							if(p->tableau[caseSuivDir2[0]][caseSuivDir2[1]] == '.'){/*si la case est vide on deplace */
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
								printf("Case apres la bille adverse non vide deplacement 3 boules \n");
								return -1;
							}
							else {
								int *caseSuivDir3 = caseSuivant(p,caseSuivDir2, dirDep);
								if(caseSuivDir3 != NULL){
									if(p->tableau[caseSuivDir3[0]][caseSuivDir3[1]] == '.'){/*SI la case es libre on deplace les 5 boules*/
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
										printf("Case apres 2 billes adverse non vide deplacement 3 boules \n"); /*case suivante NON VIDE (deplace 1 boule)*/
										return -1;
									}
								}
								else {/*on fait tomnbé un boule adverse*/

									if (list==1){
										addToList(coor);
										
										
									}
									else {
										deplaceBoule(p,caseSuivDir, caseSuivDir2);
										deplaceBoule(p,coor[2], caseSuivDir);
										caseSuivDir = caseSuivant(p,coor[1], dirDep);
										deplaceBoule(p,caseSuivDir, coor[2]);
										deplaceBoule(p,coor[1], coor[3]);
										if (couleur == 'B'){
											p->billesNoiresperdues++;
										}else{
											p->billesBlachesperdues++;
										}
									}	


								}

							}


						}
						else {
							printf("case arrivé NULL(en dehors du plateau) (deplace 3 boule)\n");
							return -1;
						}

					}

				}
				else {
					printf("case arrivé NULL(en dehors du plateau) (deplace 3 boule)\n");
					return -1;
				}
			}
			
			else{


				
				int ** boule1, **boule2, **boule3;
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
				boule2[1] = caseSuivant(p,coor[1], dirBoule);
				boule2[2] = caseSuivant(p,boule2[1], dirDep);

				
				boule3 = malloc( sizeof(int *)  *  3);
				boule3[0] = malloc( sizeof(int)  *  1);
				boule3[1] = malloc( sizeof(int)  *  2);
				boule3[2] = malloc( sizeof(int)  *  2);

				boule3[0][0] = 2;
				boule3[1] = caseSuivant(p,boule2[1], dirBoule);
				boule3[2] = caseSuivant(p,boule3[1], dirDep);
				

				deplacement(p,boule3,couleur, list);
				
				deplacement(p,boule2,couleur,list);

				
				deplacement(p,boule1,couleur,list);
				free(coor);
			}



			break;
		default : 
			return -1;
			break;
	}
	return 0;
}

/*Verifie si les coordonnées son dans le plateau*/
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
	printf("Coodonnées en dehors du plateau\n");
	return -1;
}


/*en fonction des coordonéées de départ et d'arrivé on determine la direction a savoir 0 en bas a droite 1 en bas a gauche etc */
int direction(int *depart, int *arrivee){


	switch(depart[0]){
		case 0 :
		case 1 :
		case 2 :
		case 3 :
			
			if (depart[0]+1==arrivee[0] && depart[1]+1==arrivee[1]){
				
				return 0;
			}

			else if (depart[0]+1==arrivee[0] && depart[1]==arrivee[1]){
				
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

/*comme pour direction les coordonnées doiven etre adjacente et faut une autre fonction pour le cas ou on deplace trois*/
int directionTroisBoules(int ** coor,Plateau *p){
	int ** dirrectionPossible = malloc(sizeof(int)*6);
	int i;
	for (i = 0; i < 6; i++){
		dirrectionPossible[i] = malloc(sizeof(int)*2);
		dirrectionPossible[i] = caseSuivant(p, coor[1], i);
		if(dirrectionPossible[i]!= NULL && direction(dirrectionPossible[i],coor[2]) != -1){
			
			return i;
		}

	}
	
	return -1;


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