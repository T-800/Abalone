#ifndef FICHIER_H_INCLUDED
#define FICHIER_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include "plateau.h"

/*
Cette fonction initialise le plateau.
elle est appelé avec l'otopn -c donnée au programme 
*/
int fichierConfig(const char* fic, Plateau *plateau);

<<<<<<< HEAD
int sauvegarde(char* fic, Plateau *plateau);


=======
int sauvegarde(char* fic,Plateau *plateau);
>>>>>>> a0e19bd918cbd5ac79cfc58d95635e0d1323089a

#endif
