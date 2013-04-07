#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <regex.h>
#include "clavier.h"

int syntaxeCoups(char * coups){

	int taille;
	taille = strlen(coups);
	printf("taille de la chaine %d\n", taille);


	return 0;

}


int** decoupageCoups(char *coups){ /* version Test ne prend qu'une coordonnée*/
	
	int **coordonnee;
	/*int nombreCoordonne = strlen(coups);*/
	
	if(syntaxeCoups(coups) != 0){
		printf("ERROR : Syntax non valide \n");
		return NULL;
	}
	
	coordonnee = malloc( sizeof(int *)  *  1);
	coordonnee[0] = malloc( sizeof(int)  *  2);
	

	switch (coups[0]){
		case 'A':
		case 'a': 
			coordonnee[0][0] = 8;
			coordonnee[0][1] = 0;
			break;
		case 'B':
		case 'b': 
			coordonnee[0][0] = 7;
			coordonnee[0][1] = 0;
			break;
		case 'C':
		case 'c': 
			coordonnee[0][0] = 6;
			coordonnee[0][1] = 0;
			break;
		case 'D':
		case 'd': 
			coordonnee[0][0] = 5;
			coordonnee[0][1] = 0;
			break;
		case 'E':
		case 'e': 
			coordonnee[0][0] = 4;
			coordonnee[0][1] = 0;
			break;
		case 'F':
		case 'f': 
			coordonnee[0][0] = 3;
			coordonnee[0][1] = -1;
			break;
		case 'G':
		case 'g': 
			coordonnee[0][0] = 2;
			coordonnee[0][1] = -2;
			break;
		case 'H':
		case 'h': 
			coordonnee[0][0] = 1;
			coordonnee[0][1] = -3;
			break;
		case 'I':
		case 'i': 
			coordonnee[0][0] = 0;
			coordonnee[0][1] = -4;
			break;
	}
	

	coordonnee[0][1] +=(int) (coups[1]-'0');
	coordonnee[0][1] -=1;

	return coordonnee;


}