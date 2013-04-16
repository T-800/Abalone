#ifndef FICHIER_H_INCLUDED
#define FICHIER_H_INCLUDED



#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "plateau.h"
#define strcomp(arg1,arg2) (strcmp(arg1,arg2)==0)


/*
Fonction Globale qui gère et découpe toutes les options que l'on peut passé au programme :
	-N <type> et -B <type>
	-c fichier.ab (donne une configuration initial au plateau)
	-t < test.txt 
*/
int optionGlobales(char **,int nbArgs, Plateau *p);


/*
Option -c "fic" passée en argument du programme 
*/
int optionC(char *, Plateau *p);


/*
Option -t passée en ragument du programmme 
*/
int optionT(char *, Plateau *p);


/*
Option -N <type> et -B <type> passée en argument du programme 
*/
int optionNB(char ** option, Plateau *p);

#endif