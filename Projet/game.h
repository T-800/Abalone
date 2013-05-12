#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED

#include "plateau.h"
#include "option.h"
#include "fichier.h"
#include "clavier.h"
#include "deplacement.h"
#include "ia.h"
#include <unistd.h>


#define strcomp(arg1,arg2) (strcmp(arg1,arg2)==0)


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