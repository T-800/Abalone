#ifndef PLATEAU_H_INCLUDED
#define PLATEAU_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

/*
structure du plateau 
*/
typedef struct {
    char **tableau;
    int billesBlachesperdues;
    int billesNoiresperdues;
    char JoueurSuivant;
    int typeBlanc ;
    int typeNoir;

} Plateau;


/*
Création du plateau et initialisation du plateau de jeu (À faire) 
*/
Plateau creationPlateau();

void initPlateau(Plateau *p);


/*
Cette fonction affiche le plateau tout simplement 
*/
void affichagePlateau(Plateau *p);

void affichagePlateauColor(Plateau *p, int pionX, int pionY);


#endif 


