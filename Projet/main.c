#include <stdio.h>
#include <stdlib.h>

#include "plateau.h"

#include "option.h"
#include "game.h"



int main(int argc, char const *argv[]){
	

	int mode; /*1 joueur 2 test*/
    Plateau p = creationPlateau();
   

    initPlateau(&p);



    mode = optionGlobales(argv,argc,&p);
    if (mode==2){
    	gameTest(&p);
    }
    else if (mode ==0){
    	
    	gamePIA(&p);
    }
    else{
        printf("ERROR\n");
    }
	

	
    return 0;
}
