#include "fichier.h"


int fichierConfig(const char* fic, Plateau *plateau){
    FILE *fichier = NULL;
    char caractereActuel;
    int compteurCharFichier=0,compteauCharPlateau =0;
    int i=0,j=0, blanc = 0, noir = 0;
    fichier = fopen(fic, "r");

    if (fichier != NULL){
        printf("Le fichier %s à bien été ouvert\n", fic);


        while ((caractereActuel = fgetc(fichier)) != EOF){
             
            if (compteurCharFichier > 2){
                
                if (caractereActuel=='B' || caractereActuel=='b' || 
                    caractereActuel=='N' || caractereActuel=='n' || 
                    caractereActuel=='.'){


                    if(compteauCharPlateau >61){
                        printf("il y a trop de pion sur le plateau : %d\n", compteauCharPlateau);
                        return 3;
                    }

                    if (caractereActuel=='B'){
                        blanc++;
                    }
                    else if(caractereActuel=='N'){
                        noir++;
                    }
                    

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
                plateau->billesBlachesperdues = caractereActuel;
                printf("bille blanche %d\n",plateau->billesBlachesperdues);
                compteurCharFichier++;
            }
            else if(compteurCharFichier == 2){
                plateau->billesNoiresperdues = caractereActuel;
                printf("bille Noires %d\n",plateau->billesNoiresperdues);
                compteurCharFichier++;
            }
            
            
        }
        fclose(fichier);

        if ( blanc != 14){
            printf("il n'y a pas assez de pions Blancs sur le plateau : %d\n", blanc);
            return 3;
        }
        if ( noir != 14){
            printf("il n'y a pas assez de pions Noirs sur sur le plateau : %d\n", noir);
            return 3;
        }
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


int sauvegarde(char* fic, Plateau *plateau){
    FILE *fichier = NULL;
    int i=0,j=0;
    
    fichier = fopen(fic, "w");
    fputc(plateau->JoueurSuivant, fichier);
     printf("\n\n%d\n%d\n%d\n%d\n%d\n%d\n\n\n",'1','2','3','4','5','6' );
     char un= plateau->billesBlachesperdues+2; 
    fputc(un,fichier);
    /*fputc((plateau->billesNoiresperdues),fichier);*/
    fputc('\n',fichier);
    for(i = 0; i < 9; i++){
        for (j = 0; j < strlen(plateau->tableau[i]);j++){
            fputc(plateau->tableau[i][j],fichier);
            printf("%c",plateau->tableau[i][j] );
        }
        fputc('\n',fichier);
    }
    fclose(fichier);
    
    return 0;
}