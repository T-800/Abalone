#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <regex.h>
#include "clavier.h"

int syntaxeCoups(char * coups){

	int taille;
	taille = strlen(coups);
	printf("taille de la chaine %d\n", taille);
	if (taille == 5){
		
		int re = regexSyntaxeCoups(coups,"^[A-Ia-i]{1}[1-9]{1}-{1}[A-Ia-i]{1}[1-9]{1}$" );
		printf(" regex 5 = %d\n", re);
        
        return 2;
	}
	else if (taille == 8){
		
		int re = regexSyntaxeCoups(coups,"^[A-Ia-i]{1}[1-9]{1}-{1}[A-Ia-i]{1}[1-9]{1}-{1}[A-Ia-i]{1}[1-9]{1}$" );
		printf(" regex 8 = %d\n", re);
		return 3;
        
		
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
	int index=1;
	char substring [3] = "  ";
	
	if (syntaxe == 2){
		coordonnee = malloc( sizeof(int *)  *  2);
		coordonnee[0] = malloc( sizeof(int)  *  2);
		coordonnee[1] = malloc( sizeof(int)  *  2);
		printf("Asub1 : %s\n", substring);
		strncpy(substring, coups+0, 2);
		printf("Bsub1 : %s\n", substring);
		a1ToCoor(coordonnee[0], substring);
		printf("sub1 : %s\n", substring);
		strncpy(substring, coups+3, 2);
		a1ToCoor(coordonnee[1], substring);
		printf("sub2 : %s\n", substring);

	}else if (syntaxe == 3){
		coordonnee = malloc( sizeof(int *)  *  3);
		coordonnee[0] = malloc( sizeof(int)  *  2);
		coordonnee[1] = malloc( sizeof(int)  *  2);
		coordonnee[2] = malloc( sizeof(int)  *  2);
		strncpy(substring, coups+0, 2);
		a1ToCoor(coordonnee[0], substring);
		printf("sub1 : %s\n", substring);
		strncpy(substring, coups+3, 2);
		a1ToCoor(coordonnee[1], substring);
		printf("sub2 : %s\n", substring);
		strncpy(substring, coups+6, 2);
		a1ToCoor(coordonnee[2], substring);
		printf("sub3 : %s\n", substring);
	}else {
		printf("ERROR : Syntax non valide \n");
		return NULL;
	}
	
	

	

	return coordonnee;


}

int regexSyntaxeCoups(char *chaineTest, char *regex){

		int err = 0;
   		regex_t preg;
   		err = regcomp (&preg, regex, REG_NOSUB | REG_EXTENDED);

   		if (err == 0){
   			int match;
   			match = regexec (&preg, chaineTest, 0, NULL, 0);
   			regfree (&preg);
      		if (match == 0){
      			printf ("%s est un coups valide  \n", chaineTest);
      			return 0;
      		}
      		else if (match == REG_NOMATCH){
      			printf ("%s n\'est pas un coups valide\n", chaineTest);
      			return 1;
      		}
      		else{ /* EN cas d'erreur*/
      			
         		return 2;
         	}
        }
        else return 123;
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