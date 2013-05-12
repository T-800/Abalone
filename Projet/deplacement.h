#ifndef DEPLACEMENT_H_INCLUDED
#define DEPLACEMENT_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include "plateau.h"
#include "clavier.h"
#include "ia.h"


/*Renvoi le nombre de boule a deplacer pour la meme couleur*/
int nbBouleDeplace(Plateau *p, int **coor);

/*renvoi les coordonnées de la case suivante null si en dehors du plateau*/
int* caseSuivant(Plateau *p, int *coor, int direction);

/*deplace une boule */
int deplaceBoule(Plateau *p, int *depart, int *arrivee);


/*fonction gobale du deplacement*/
int deplacement(Plateau *p, int **coor,char couleur, int list);

/*Verifie si les coordonnées son dans le plateau*/
int coordonneesValides(int coorA, int corrB);


/*en fonction des coordonéées de départ et d'arrivé on determine la direction a savoir 0 en bas a droite 1 en bas a gauche etc */
int direction(int *depart,int  *arrivee);



/*fonction qui liste tout les deplacements possible d'une couleur */

int directionTroisBoules(int ** coor,Plateau *p);



#endif