#ifndef IA_H_INCLUDED
#define IA_H_INCLUDED
/*
#include <time.h>  
#include "deplacement.h"
#include "plateau.h"

int *** coupsPossibles;
void play(char color,Plateau *p);
void addToList(int ** coor);
void IA(Plateau *p, char couleur);
int deplacementIA(Plateau *p, int **coor,char couleur);
void affichageListe(); */


#include <stdio.h>
#include <stdlib.h>

#include <time.h>  
#include "deplacement.h"
#include "plateau.h"








int ** play(char color,Plateau *p);


void addToList(int ** coor);

void IA(Plateau *p, char couleur);



void affichageListe(); 
#endif