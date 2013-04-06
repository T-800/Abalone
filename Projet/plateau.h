#ifndef PLATEAU_H_INCLUDED
#define PLATEAU_H_INCLUDED


/*
structure du plateau 
*/
typedef struct {
    char **tableau;
    int billesBlachesperdues;
    int billesNoiresperdues;
    char JoueurSuivant;

} Plateau;


/*
Création du plateau et initialisation du plateau de jeu (À faire) 
*/
Plateau creationPlateau();

/*
Cette fonction affiche le plateau tout simplement 
*/
void affichagePlateau(Plateau *p);

void affichagePlateauColor(Plateau *p, int pionX, int pionY);


#endif 


