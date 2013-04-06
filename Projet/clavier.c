#include <stdio.h>
#include <stdlib.h>
#include "clavier.h"

int syntaxeCoups(char * coups){

	
	return 0;

}


int** decoupageCoups(char *coups){ /* version Test ne prend qu'une coordonnée*/
	
	int **coordonnee;
	printf("RRRRR \n");
	if(syntaxeCoups(coups) != 0){
		printf("ERROR : Syntax non valide \n");
		return NULL;
	}
	printf(" coups [0]%c  \n",coups[0] );
	
	coordonnee = malloc( sizeof(int *)  *  1);
	coordonnee[0] = malloc( sizeof(int)  *  2);
	

	switch (coups[0]){
		case 'A':
		case 'a': 
			printf("OK 0.5 : \n");
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
	printf(" x = %d   \n",coordonnee[0][0]);
	printf("OK 2 : \n");
	coordonnee[0][1] +=(int) (coups[1]-'0');
	coordonnee[0][1] -=1;
	printf("OK 3 : \n");
	printf(" x = %d  y =  %d \n",coordonnee[0][0],coordonnee[0][1] );

	return coordonnee;


}