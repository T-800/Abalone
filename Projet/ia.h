#ifndef IA_H_INCLUDED
#define IA_H_INCLUDED

#include "deplacement.h"

void play(char color,Plateau *p);
void addToList(int ** coor);
void IA(Plateau *p, char couleur);
int deplacementIA(Plateau *p, int **coor,char couleur);
void affichageListe(); 

#endif