#ifndef FICHIER_H_INCLUDED
#define FICHIER_H_INCLUDED

/*
Cette fonction vérifie la syntaxe des coups entré par l'utilisateur
la taille est de min 5 et max 8 
composé de lettre et d'un chiffre séparé par des tiret (-)
*/
int verifSyntaxeCoups(char *);


/*

*/
int** decoupageCoups(char *);

int regexSyntaxeCoups(char *chaineTest, char *regex);

void a1ToCoor(int *tab, char * lettre);




#endif