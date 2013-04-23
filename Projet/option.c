#include "option.h"



int optionGlobales(char const *option[], int nbArgs, Plateau *p){

		int i;
		printf("nb arg = %d\n", nbArgs);
		for(i = 1; i<nbArgs; i++){
			if(strcomp(option[i],"-N")){
				if((i+1) == nbArgs){
					printf("Argument obligatoire : N\n");
					return 1;
				}
				if (strcomp("IA",option[i+1])||strcomp("ia",option[i+1])||strcomp("robot",option[i+1])){
					p->typeBlanc = 1;
				}
				else if(strcomp("human",option[i+1])||strcomp("h",option[i+1])||strcomp("H",option[i+1])|| strcomp("Humain",option[i+1])){
					p->typeBlanc = 2;	
				}
				else {
					printf("erreur N : \n");
					return 1;
				}
			}
			else if(strcomp(option[i],"-B")){
				if((i+1) == nbArgs){
					printf("Argument obligatoire : B\n");
					return 1;
				}
				if (strcomp("IA",option[i+1])||strcomp("ia",option[i+1])||strcomp("robot",option[i+1])){
					p->typeNoir = 1;
				}
				else if(strcomp("human",option[i+1])||strcomp("h",option[i+1])||strcomp("H",option[i+1])
						|| strcomp("Humain",option[i+1])){
					p->typeNoir = 2;	
				}
				else {
					printf("erreur B : \n");
					return 1;
				}
			}
			else if(strcomp(option[i],"-c")){
				if((i+1) == nbArgs){
					printf("Argument obligatoire : C\n");
					return 1;
				}
				else {
					if(fichierConfig(option[i+1], p) != 0) {
						printf("ERREUR fichier config option.c\n");
					}

				}
			}
			else if (strcomp(option[i],"-t")){
				if( nbArgs != 2){
					printf("l'Option -t ne prend ni argument ni autre option\n");
					return 1;
				}
				
			}
		}	 	





		return 0;
}
