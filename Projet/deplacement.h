#ifndef FICHIER_H_INCLUDED
#define FICHIER_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include "plateau.h"
#include "clavier.h"


int deplacementAutoriser(Plateau* p, int ** coor);

int ** listeDeplacements(char color);

int coordonneesValides(int *coor);

int deplacement2(Plateau* p, int ** coor);





#endif