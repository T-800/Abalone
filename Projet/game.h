#ifndef FICHIER_H_INCLUDED
#define FICHIER_H_INCLUDED

#include "plateau.h"
#include "option.h"
#include "fichier.h"
#include "clavier.h"
#include "deplacement.h"


#ifdef __APPLE__
	#define s() printf("APPLE \n\n");

#elif __MINGW32__
	#define s() printf("WINDOWS \n\n");
#elif __GNUC__
	#define s() printf("LINUX \n\n");
	#define clear() printf("\033[2J\033[1;1H")
	
#endif


int gameTest(Plateau *p);

int gamePIA(Plateau *p);

int run(int, char *argv[]);



#endif