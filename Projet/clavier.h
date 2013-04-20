#ifndef FICHIER_H_INCLUDED
#define FICHIER_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <regex.h>

/*
Cette fonction vérifie la syntaxe des coups entré par l'utilisateur
la taille est de min 5 et max 8 
composé de lettre et d'un chiffre séparé par des tiret (-)
*/
int verifSyntaxeCoups(char *);


/*

*/
int** decoupageCoups(char *);

int regexSyntaxeCoups(char *chaineTest, char *regex);

void a1ToCoor(int *tab, char * lettre);




#endif