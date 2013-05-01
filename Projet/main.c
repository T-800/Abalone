#include <stdio.h>
#include <stdlib.h>

#include "plateau.h"


#include "game.h"



int main(int argc, char const *argv[]){
	


	int j;
    Plateau p = creationPlateau();
   

    initPlateau(&p);



    optionGlobales(argv,argc,&p);

	/*gameTest(&p);*/
	gameTest(&p);
	

	for(j = 0 ; j< argc; j++){
		printf("arg % d : %s\n", j+1, argv[j]);
	}
	printf("BLANC type : %d\n",p.typeBlanc);
	printf("NOIR type : %d\n",p.typeNoir);
	

	
    return 0;
}
