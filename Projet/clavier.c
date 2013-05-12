#include "clavier.h"

int syntaxeCoups(char * coups){

	int taille;
	taille = strlen(coups);
	if (taille == 5){
		
		if(coups[2]=='-')return 2;
		else return-1;
	}
	else if (taille == 8){
		
		if(coups[2]=='-' && coups[5]=='-')return 3;
		else return  -1;
        
		
	}
	else {
		printf ("%s est un coups non valide de taille : %d\n", coups, taille);
		return -1;
	}


	return 0;

}


int** decoupageCoups(char *coups){ /* version Test ne prend qu'une coordonnée*/
	

	



	int **coordonnee;
	/*int nombreCoordonne = strlen(coups);*/
	int syntaxe = syntaxeCoups(coups);
	/*int index=1;*/
	char substring [3] = "  ";
	
	if (syntaxe == 2){
		coordonnee = malloc( sizeof(int *)  *  3);
		coordonnee[0] = malloc( sizeof(int)  *  1);
		coordonnee[1] = malloc( sizeof(int)  *  2);
		coordonnee[2] = malloc( sizeof(int)  *  2);
		coordonnee[0][0] = 2;
		strncpy(substring, coups+0, 2);
		a1ToCoor(coordonnee[1], substring);
		strncpy(substring, coups+3, 2);
		a1ToCoor(coordonnee[2], substring);

	}else if (syntaxe == 3){
		coordonnee = malloc( sizeof(int *)  *  4);
		coordonnee[0] = malloc( sizeof(int)  *  1);
		coordonnee[1] = malloc( sizeof(int)  *  2);
		coordonnee[2] = malloc( sizeof(int)  *  2);
		coordonnee[3] = malloc( sizeof(int)  *  2);
		coordonnee[0][0] = 3;
		strncpy(substring, coups+0, 2);
		a1ToCoor(coordonnee[1], substring);
		strncpy(substring, coups+3, 2);
		a1ToCoor(coordonnee[2], substring);
		strncpy(substring, coups+6, 2);
		a1ToCoor(coordonnee[3], substring);
	}else {
		printf("ERROR : Syntax non valide \n");
		return NULL;
	}
	
	

	

	return coordonnee;


}



void a1ToCoor(int *tab, char * lettre){

	switch (lettre[0]){
		case 'A':
		case 'a': 
			tab[0] = 8;
			tab[1] = 0;
			break;
		case 'B':
		case 'b': 
			tab[0] = 7;
			tab[1] = 0;
			break;
		case 'C':
		case 'c': 
			tab[0] = 6;
			tab[1] = 0;
			break;
		case 'D':
		case 'd': 
			tab[0] = 5;
			tab[1] = 0;
			break;
		case 'E':
		case 'e': 
			tab[0] = 4;
			tab[1] = 0;
			break;
		case 'F':
		case 'f': 
			tab[0] = 3;
			tab[1] = -1;
			break;
		case 'G':
		case 'g': 
			tab[0] = 2;
			tab[1] = -2;
			break;
		case 'H':
		case 'h': 
			tab[0] = 1;
			tab[1] = -3;
			break;
		case 'I':
		case 'i': 
			tab[0] = 0;
			tab[1] = -4;
			break;
	}
	

	tab[1] +=(int) (lettre[1]-'0');
	tab[1] -=1;
}
