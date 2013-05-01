#ifndef FICHIER_H_INCLUDED
#define FICHIER_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include "plateau.h"
#include "clavier.h"

/*cette fonction verifie que le deplavement donné en argument est possible*/
int deplacementAutoriser(Plateau* p, int ** coor, char);

/*cette foction renvoi tout les deplacement possible pour un joureur */
int ** listeDeplacements(char color);

/**/
int coordonneesValides(int *coor);

int deplacement2(Plateau* p, int ** coor);

int caseSuivante(Plateau *p, int *coor, int direction);







#endif