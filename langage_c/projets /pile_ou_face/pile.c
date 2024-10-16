#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#define PILE 1
#define FACE 2

//FONCTIONS :
  
void ortho(char * lettres,char*mot) {                    // tout convertir en minuscules.
    
for(int i = 0; i < strlen(lettres); i++) {
    if(lettres[i] < 90) {
        mot[i]= lettres[i]+32;
} else {
    mot[i] = lettres[i];
}
}
}



int main () {


srand(time(NULL));
    
char saisie[255]; 
printf("~~~PILE OU FACE ~~~\n");
printf("- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -\n");
printf("Pile ou face ?\n");

    for(int tour = 0; tour < 12; tour++) {
        char score[255];
        int defaite = 0;
        
        
        fgets(saisie,sizeof(saisie), stdin);
        int piece = rand()%2 + 1;
        int reponse = 0;

        printf("%d\n", piece);
        printf("loading");
        fflush(stdout);
        sleep(1);
        printf(".");
        fflush(stdout);
        sleep(1);
        printf(".");
        fflush(stdout);
        sleep(1);
        printf(".\n");
        reponse = atoi(saisie);
        
        if(piece == reponse) {
            printf("gagné\n");
        
        }else{
            printf("perdu\n");
            defaite ++;
        }
        if(defaite = 9) {
            return 0;
        }

        char buf[255];
        
        fgets(reponse,255, stdin);
        reponse[strlen(reponse)-1] = 0;
        ortho( reponse,buf);
        printf("%s",buf);





    }
    







    return 0;
}