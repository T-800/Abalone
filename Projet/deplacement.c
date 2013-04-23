#include "deplacement.h"


int deplacementAutoriser(Plateau* p, int ** coor){

	if(coor[0][0]==2){
		printf("t2\n");


		switch(coor[1][0]){
			case 0:
			case 1:
			case 2:
			case 3:
			printf("AAAAA\n");
				if(coor[2][0] > coor[1][0]+1 ||coor[2][0] < coor[1][0]-1){
					printf("ERREUR COORD 001\n");
					return -1;
				}

				else {
					if(coor[2][0] == coor[1][0]-1){
			
						if(coor[2][1] == coor[1][1]-1 ||coor[2][1] == coor[1][1]){
							printf(" COORD 001 ok\n");
							if (p->tableau[coor[2][0]][coor[2][1]]=='.'){
								p->tableau[coor[2][0]][coor[2][1]] = p->tableau[coor[1][0]][coor[1][1]];
								p->tableau[coor[1][0]][coor[1][1]] = '.';
							}
				
						}else {
							printf("ERREUR COORD 002\n");	
						}
				
					}
					else if(coor[2][0] == coor[1][0]) {
						if(coor[2][1] == coor[1][1]-1 ||coor[2][1] == coor[1][1]+ 1){
							printf(" COORD 003 ok\n");
							if (p->tableau[coor[2][0]][coor[2][1]]=='.'){
								p->tableau[coor[2][0]][coor[2][1]] = p->tableau[coor[1][0]][coor[1][1]];
								p->tableau[coor[1][0]][coor[1][1]] = '.';
							}
				
						}else {
							printf("ERREUR COORD 004\n");	
						}
					}
					else if(coor[2][0] == coor[1][0]+1) {
						if(coor[1][1] == coor[2][1] ||coor[2][1] == coor[1][1]+ 1){
							printf(" COORD 005 ok\n");
							if (p->tableau[coor[2][0]][coor[2][1]]=='.'){
								p->tableau[coor[2][0]][coor[2][1]] = p->tableau[coor[1][0]][coor[1][1]];
								p->tableau[coor[1][0]][coor[1][1]] = '.';
							}
				
						}else {
							printf("ERREUR COORD 006\n");	
						}
					}
				}
				break;
			case 4:
				printf("BBBBB\n");
				break;
			case 5:
			case 6:
			case 7:
			case 8:
				printf("CCCCCCC\n");
				break;
			
			
		}

	}
	else if(coor[0][0]==3){
		printf("T3\n");
	}
	else {
		printf("ERREUR COORD\n");
	}

	return 0;

}

int coordonneesValides(int * coor){
	return 0;
}