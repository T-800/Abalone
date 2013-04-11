#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "option.h"
#include "plateau.h"




/*
	Tableau de 4 cases 
*/
int optionNB(char *options[], Plateau *p){
	int i;
	for(i=0; i<2; i++){

		if (!strcmp(options[i], "-N")){
			if(!strcmp(options[i+1],"human")){
				p->typeBlanc = 1;
			}
			else {
				p->typeBlanc = 2;	
			}
		}
		else {
			if(!strcmp(options[i+1],"human")) {
				p->typeNoir = 1;
			}
			else {
				p->typeNoir = 2;	
			}
		}
	}

	return 0;

}