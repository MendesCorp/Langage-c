#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#define PILE 1
#define FACE 2
  
void transform(char * maj, char *  mot) {                    

    for(int i = 0; i < strlen(maj); i++) { 

    if (maj[i] >= 'A' && maj[i] <= 'Z') {
        mot[i] = maj[i]+32;

    } else {

    mot[i] = maj[i];
}
}
}

int ortho(char * saisie){

    char mini[255];
    saisie[strlen(saisie)-1] = 0;                           
    memset(mini,0,255);
    transform(saisie,mini);

    if(strcmp(mini, "0") == 0) {
        return -2;
    }

    if(strcmp(mini, "pile") == 0) {
        return PILE;

    }else if (strcmp(mini, "face") == 0) {
        return FACE;
    }
    
    if(strcmp(mini, "fAcE") == 0) {
        return FACE;
    }

    if(strcmp(mini, "1") == 0) {
        return PILE;

    }else if ( strcmp(mini, "2") == 0) {
        return FACE;
    }
    if(strcmp(mini, "p") == 0) {
        return PILE;

    }else if (strcmp(mini, "f") == 0) {
        return FACE;
    }
        return -1;   
    }

int main () {

srand(time(NULL));
    
char saisie[255]; // ajouter memset
printf("\n######## Pile ou Face ##########\n");

int reussite = 0;
int echec = 0;

    for(int tour = 0; tour < 10; tour++) {

        printf("\nPile ou face ?\n");
        printf("\n1. Pile\n");
        printf("\n2. Face\n");
        printf("\n0. Quitter le jeu\n");

        int piece = rand() %2 + 1;

        fgets(saisie,sizeof(saisie), stdin);
        int reponse = ortho(saisie);

        if (reponse == -2) {
            printf("\nVous quittez le jeu... snif :(\n");
            return 0;
        }

        if (reponse == -1) {
            printf("\nerreur entrez soit pile soit face.\n");
            continue;
        }

        printf("\nchargement\n");
        fflush(stdout);
        sleep(1);
        printf(".");
        fflush(stdout);
        sleep(1);
        printf(".");
        fflush(stdout);
        sleep(1);
        printf(".\n");
        
        if(piece == reponse) {
            printf("\ngagné\n");
            reussite ++;
        
        }else{
            printf("\nperdu\n");
            echec ++;
        }
        

        if(echec == 9) {
            printf("\nfin de partie\n");
            return 0;
        }
        // printf("\n%d Réussite%c\n", reussite, reussite > 1 ?'s': ' ');
        // printf("\n%d Echec%c\n", echec, echec > 1 ?'s': ' ');
        
        if(reussite < 2) {
            printf("\n%d Réussite\n", reussite);
        }

        if(reussite >= 2) {
            printf("\n%d Réussites\n", reussite);
        }

        if(echec < 2) {
            printf("\n%d Echec\n", echec);
        }

        if(echec >= 2) {
            printf("\n%d Echecs\n", echec);
        }
        
        printf("\n|==================================|\n");
       
    }
    
        return 0;
    
    }
