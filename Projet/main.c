#include <stdio.h>
#include <stdlib.h>
#include "plateau.h"
#include "fichier.h"

int main(){
    Plateau p = creationPlateau();

	char *fic = "test.ab";

	int i = fichierConfig(fic, &p);
	if(i==0)affichagePlateau(&p);
    return 0;
}
