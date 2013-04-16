#include "option.h"



int optionGlobales(char *option[], int nbArgs, Plateau *p){

		int i;
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
					int v = fichierConfig(option[i+1], p);

				}
			}
		}	 	





		return 0;
}


/*
	Tableau de 4 cases 
*/


int optionNB(char *options[], Plateau *p){
	
	int i;
	for(i=1; i<2; i++){

		if (strcomp(options[i], "-N")){
			if(strcomp(options[i+1],"human")){
				p->typeBlanc = 1;
			}
			else {
				p->typeBlanc = 2;	
			}
		}
		else {
			if(strcomp(options[i+1],"human")) {
				p->typeNoir = 1;
			}
			else {
				p->typeNoir = 2;	
			}
		}
	}

	return 0;

}