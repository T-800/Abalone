#include "deplacement.h"


int deplacementAutoriser(Plateau* p, int ** coor){

	int i ;
	if(coor[0][0]==2){
		printf("t2\n");
		
		for (i = 1; i < 3; i++){
			if(coordonneesValides(coor[i])!=0){
			 	printf("Deplacement impossible 78952\n");
			 	return -1;
			}
		}

		if(coor[2][0] > coor[1][0]+1 ||coor[2][0] < coor[1][0]-1){
					printf("ERREUR COORD 001\n");
					return -1;
		}
		if(coor[2][1] > coor[1][1]+1 ||coor[2][1] < coor[1][1]-1){
					printf("ERREUR COORD 099\n");
					return -1;
		}

		switch(coor[1][0]){
			case 0:
			case 1:
			case 2:
			case 3:
				printf("AAAAA\n");
				if(coor[2][0] == coor[1][0]-1){
		
					if(coor[2][1] == coor[1][1]-1 ||coor[2][1] == coor[1][1]){
						printf(" COORD 001 ok\n");
						if (p->tableau[coor[2][0]][coor[2][1]]=='.'){
							return 0;
						}
						else {
							printf("Deplacement impossible\n");
						}
			
					}else {
						printf("ERREUR COORD 002\n");	
					}
			
				}
				else if(coor[2][0] == coor[1][0]) {
					if(coor[2][1] == coor[1][1]-1 ||coor[2][1] == coor[1][1]+ 1){
						printf(" COORD 003 ok\n");
						if (p->tableau[coor[2][0]][coor[2][1]]=='.'){
							return 0;
						}
						else {
							printf("Deplacement impossible\n");
						}
			
					}else {
						printf("ERREUR COORD 004\n");	
					}
				}
				else if(coor[2][0] == coor[1][0]+1) {
					if(coor[1][1] == coor[2][1] ||coor[2][1] == coor[1][1]+ 1){
						printf(" COORD 005 ok\n");
						if (p->tableau[coor[2][0]][coor[2][1]]=='.'){
							return 0;
						}
						else {
							printf("Deplacement impossible\n");
						}
			
					}else {
						printf("ERREUR COORD 006\n");	
					}
				}
				
				break;
			case 4:
				printf("BBBBB\n");


				
					if(coor[2][0] == coor[1][0]-1){
			
						if(coor[2][1] == coor[1][1]-1 ||coor[2][1] == coor[1][1]){
							printf(" COORD 008 ok\n");
							if (p->tableau[coor[2][0]][coor[2][1]]=='.'){
								return 0;
							}
							else {
								printf("Deplacement impossible\n");
							}
				
						}else {
							printf("ERREUR COORD 009\n");	
						}
				
					}
					else if(coor[2][0] == coor[1][0]) {
						if(coor[2][1] == coor[1][1]-1 ||coor[2][1] == coor[1][1]+ 1){
							printf(" COORD 003 ok\n");
							if (p->tableau[coor[2][0]][coor[2][1]]=='.'){
								return 0;
							}
							else {
								printf("Deplacement impossible\n");
							}
				
						}else {
							printf("ERREUR COORD 010\n");	
						}
					}
					else if(coor[2][0] == coor[1][0]+1) {
						if(coor[1][1] == coor[2][1] ||coor[2][1] == coor[1][1]- 1){
							printf(" COORD 005 ok\n");
							if (p->tableau[coor[2][0]][coor[2][1]]=='.'){
								return 0;
							}
							else {
								printf("Deplacement impossible\n");
							}
				
						}else {
							printf("ERREUR COORD 011\n");	
						}
					}
				

				
				break;
			case 5:
			case 6:
			case 7:
			case 8:
				printf("CCCCCCC\n");
				
					if(coor[2][0] == coor[1][0]-1){
			
						if(coor[2][1] == coor[1][1]+1 ||coor[2][1] == coor[1][1]){
							printf(" COORD 013 ok\n");
							if (p->tableau[coor[2][0]][coor[2][1]]=='.'){
								return 0;
							}
							else {
								printf("Deplacement impossible\n");
							}
				
						}else {
							printf("ERREUR COORD 014\n");	
						}
				
					}
					else if(coor[2][0] == coor[1][0]) {
						if(coor[2][1] == coor[1][1]-1 ||coor[2][1] == coor[1][1]+ 1){
							printf(" COORD 015 ok\n");
							if (p->tableau[coor[2][0]][coor[2][1]]=='.'){
								return 0;
							}
							else {
								printf("Deplacement impossible\n");
							}
				
						}else {
							printf("ERREUR COORD 016\n");	
						}
					}
					else if(coor[2][0] == coor[1][0]+1) {
						if(coor[1][1] == coor[2][1] ||coor[2][1] == coor[1][1]- 1){
							printf(" COORD 017 ok\n");
							if (p->tableau[coor[2][0]][coor[2][1]]=='.'){
								return 0;
							}
							else {
								printf("Deplacement impossible\n");
							}
				
						}else {
							printf("ERREUR COORD 018\n");	
						}
					}
				break;
			
			
		}

	}
	else if(coor[0][0]==3){
		printf("T3\n");
	}
	else {
		printf("ERREUR COORD\n");
	}

	return -1;
}

int coordonneesValides(int *coor){

	switch (coor[0]){

		case 0:
		case 8: 
			if (coor[1] < 5 && coor[1]>=0)return 0;
			break;

		case 1:
		case 7:
			if (coor[1] < 6 && coor[1]>=0)return 0;
			break;

		case 2: 
		case 6:
			if (coor[1] < 7 && coor[1]>=0)return 0;
			break;

		case 3:
		case 5: 
			if (coor[1] < 8 && coor[1]>=0)return 0;
			break;


		case 4: 
			if (coor[1] < 9 && coor[1]>=0)return 0;
			break;
	}
	return -1;
}

int deplacement2(Plateau* p, int ** coor){
	p->tableau[coor[2][0]][coor[2][1]] = p->tableau[coor[1][0]][coor[1][1]];
	p->tableau[coor[1][0]][coor[1][1]] = '.';
	return 0;
}