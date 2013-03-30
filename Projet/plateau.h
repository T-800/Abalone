#ifndef PLATEAU_H_INCLUDED
#define PLATEAU_H_INCLUDED

typedef struct {
    char **tableau;
    int billesBlachesperdues;
    int billesNoiresperdues;
    char JoueurSuivant;

} Plateau;

Plateau creationPlateau();
void affichagePlateau(Plateau *p);


#endif 


