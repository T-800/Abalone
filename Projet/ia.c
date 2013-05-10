#include "ia.h"

int*** coupsPossibles;
int x = 0;


void play(char color,Plateau *p){
	return;
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