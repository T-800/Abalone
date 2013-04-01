#ifndef FICHIER_H_INCLUDED
#define FICHIER_H_INCLUDED

/*
Fonction Globale qui gere toute les options que l'on peut passé au programme :
	-N <type> et -B <type>
	-c fichier.ab (donne une configuration initial au plateau)
	-t < test.txt 
*/
int optionGlobales(char *);



int optionC(char *);

int optionT(char *);

int optionNB(char *);

#endif