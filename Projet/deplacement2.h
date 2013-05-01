#ifndef FICHIER_H_INCLUDED
#define FICHIER_H_INCLUDED

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
int deplacement(Plateau *p, int **coor);


int coordonneesValides(int coorA, int corrB);


int directionDeplacement(int **coor);


char** listeToutDeplacement(Plateau *p, char color);



#endif