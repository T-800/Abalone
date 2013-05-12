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
#define clear() printf("\033[2J\033[1;1H")



int gameTest(Plateau *p);

int gamePIA(Plateau *p);

int run(int, char *argv[]);



#endif