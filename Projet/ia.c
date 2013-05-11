#include "ia.h"

int ***coupsPossibles;
int x = 0;


void play(char color,Plateau *p){
	int a;
	a = 0;
	int *pion_random = coord_random_pion(p, color);
	
	coupsPossible(p, pion_random, color);
	
	/*deplacement(p, coupsPossibles[x],color, 0);*/
}

void addToList(int ** coor){
	extern int x;
	extern int ***coupsPossibles;
	if( x == 0){
		coupsPossibles = malloc(6*sizeof(int));
	}
	coupsPossibles[x] = coor;
	x++;
}