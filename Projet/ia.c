#include "ia.h"

int ***coupsPossibles;
int x = 0;


void play(char color,Plateau *p){
	int a,i,d;
	extern int x;
	a = 0;
	int *pion_random = coord_random_pion(p, color);
	
	coupsPossible(p, pion_random, color);
	
	
	
    for(i = 0; i < x ; i++){
		printf("LOLOLO\n");
		/*printf("c = %d et nb coups = %d ",c, deplacementPossible[c][0][0]);*/
		for(d = 1; d < 3; d++){
			if(d == 1){
				printf("%d) nb de coup = %d,",i, coupsPossibles[i][0][0]);
				printf(" coord1 y = %d x = %d", coupsPossibles[i][d][0], coupsPossibles[i][d][1]);
			}
			else{
				printf(" / coord2 y = %d x = %d", coupsPossibles[i][d][0], coupsPossibles[i][d][1]);
			}
		}
	printf("\n");
    }
	
	/*deplacement(p, coupsPossibles[x],color, 0);*/
}

void addToList(int ** coor){
	extern int x;
	extern int ***coupsPossibles;
	if( x == 0){
		coupsPossibles = malloc(6*sizeof(int));
	}
	
	
	if(coor[0][0] == 2){
		coupsPossibles[x] = malloc(sizeof(int)*3);
		coupsPossibles[x][0] = malloc(sizeof(int)*1);
		coupsPossibles[x][1] = malloc(sizeof(int)*2);
		coupsPossibles[x][2] = malloc(sizeof(int)*2);
		coupsPossibles[x][0] = coor[0];
		coupsPossibles[x][1] = coor[1];
		coupsPossibles[x][2] = coor[2];
	}
	
	else{
		coupsPossibles[x] = malloc(sizeof(int)*4);
		coupsPossibles[x][0] = malloc(sizeof(int)*1);
		coupsPossibles[x][1] = malloc(sizeof(int)*2);
		coupsPossibles[x][2] = malloc(sizeof(int)*2);
		coupsPossibles[x][3] = malloc(sizeof(int)*2);
		coupsPossibles[x][0] = coor[0];
		coupsPossibles[x][1] = coor[1];
		coupsPossibles[x][2] = coor[2];
		coupsPossibles[x][3] = coor[3];
	}

	x++;


}