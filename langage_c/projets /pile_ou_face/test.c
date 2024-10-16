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

char buf[255];
char reponse[255];
fgets(reponse,255, stdin);
reponse[strlen(reponse)-1] = 0;
    ortho( reponse,buf);
    printf("%s",buf);

    return 0;
}