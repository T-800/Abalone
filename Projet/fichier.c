#include <stdio.h>
#include <stdlib.h>
#include "fichier.h"
#include "plateau.h"


int fichierConfig(char* fic, Plateau *plateau){
    
    FILE *fichier = NULL;
    char caractereActuel;
    int compteurCharFichier=0,compteauCharPlateau =0;
    int i=0,j=0;
    fichier = fopen(fic, "r");
   	
    

    if (fichier != NULL){
        printf("Le fichier %s à bien été ouvert\n", fic);


        while ((caractereActuel = fgetc(fichier)) != EOF){
             
            if (compteurCharFichier > 2){
                
                if (caractereActuel=='B' || /*caractereActuel=='b' ||*/ 
                    caractereActuel=='N' || /*caractereActuel=='n' || */
                    caractereActuel=='.'){
                    
                    plateau->tableau[i][j] = caractereActuel;
                    compteauCharPlateau++;
                    if (i==0&& j >=4 ){
                        
                        i++;

                        j =0;
                    }
                    else if ((i==1 || i == 7) && j >= 5 ){
                        i++;
                        j =0;
                    }
                    else if ((i==2 || i == 6) && j >= 6 ){
                        i++;
                        j =0;
                    }
                    else if ((i==3 || i == 5) && j >= 7 ){
                        i++;
                        j =0;
                    }
                    else if (i==4 && j >= 8 ){
                        i++;
                        j =0;
                    }
                     else if (i==8 && j >=4){
                        return 0;
                    }
                    else {
                        j++;
                    }
                }

            

            }
            else if(compteurCharFichier == 0){
                if (caractereActuel=='N'){
                    plateau->JoueurSuivant = 'N';
                    compteurCharFichier++;
                }
                else if (caractereActuel=='B'){
                    plateau->JoueurSuivant = 'B';
                    compteurCharFichier++;
                }
                else return 2;
                printf("Le joueur suivant est le %c\n",plateau->JoueurSuivant);
            }
            else if(compteurCharFichier == 1){
                compteurCharFichier++;
            }
            else if(compteurCharFichier == 2){
                compteurCharFichier++;
            }
            
            
        }
        fclose(fichier);

        if (compteauCharPlateau<61){
            printf("il n'y a pas assez de char sur le plateau : %d\n", compteauCharPlateau);
            return 3;
        }

        return 0;
    }
    else{
        printf("Impossible d'ouvrir le fichier de config\n");
        return 1;
    }
        
}
