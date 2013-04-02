#ifndef FICHIER_H_INCLUDED
#define FICHIER_H_INCLUDED

/*
Fonction Globale qui gère et découpe toutes les options que l'on peut passé au programme :
	-N <type> et -B <type>
	-c fichier.ab (donne une configuration initial au plateau)
	-t < test.txt 
*/
int optionGlobales(char *);


/*
Option -c "fic" passée en argument du programme 
*/
int optionC(char *);


/*
Option -t passée en ragument du programmme 
*/
int optionT(char *);


/*
Option -N <type> et -B <type> passée en argument du programme 
*/
int optionNB(char *);

#endif