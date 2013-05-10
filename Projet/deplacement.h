#ifndef DEPLACEMENT_H_INCLUDED
#define DEPLACEMENT_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include "plateau.h"
#include "clavier.h"


/*Renvoi le nombre de boule a deplacer pour la meme couleur*/
int nbBouleDeplace(Plateau *p, int **coor);

/*renvoi les coordonnées de la case suivante null si en dehors du plateau*/
int* caseSuivant(Plateau *p, int *coor, int direction);

/*deplace une boule */
int deplaceBoule(Plateau *p, int *depart, int *arrivee);

/*affiche les codes erreurs*/
void codeErreur(int code);

/*fonction gobale du deplacement*/
int deplacement(Plateau *p, int **coor,char couleur);


int coordonneesValides(int coorA, int corrB);


int direction(int *depart,int  *arrivee);

int directionBoules(int **coor);

/*fonction qui liste tout les deplacements possible d'une couleur */
char** listeToutDeplacement(Plateau *p, char color);
int directionTroisBoules(int ** coor,Plateau *p);



#endif