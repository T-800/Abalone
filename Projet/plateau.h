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

*/
Plateau creationPlateau();

/*

*/
void affichagePlateau(Plateau *p);


#endif 


