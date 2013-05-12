#ifndef CLAVIER_H_INCLUDED
#define CLAVIER_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <regex.h>

#define strcomp(arg1,arg2) (strcmp(arg1,arg2)==0)

/*
Cette fonction vérifie la syntaxe des coups entré par l'utilisateur
la taille est de min 5 et max 8 
composé de lettre et d'un chiffre séparé par des tiret (-)
*/
int verifSyntaxeCoups(char *);


/*
cette fonction decoupe le coup en tableau.
elle prend le "string" de coup et la transforme en tableau de coordonnées 
la 1ere ligne est la taille 2ou 3
les lignes suivantes sont les coordonnées 
*/
int** decoupageCoups(char *);


/**/
void a1ToCoor(int *tab, char * lettre);




#endif