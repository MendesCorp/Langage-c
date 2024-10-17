#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#define PILE 1
#define FACE 2

//FONCTIONS :

//void ortho(char * lettres,char*mot) {                    // tout convertir en minuscules.
    
//for(int i = 0; i < strlen(lettres); i++) {
  //  if(lettres[i] < 90) {
    //    mot[i]= lettres[i]+32;
//} else {
  //  mot[i] = lettres[i];
//}
//}
//}

//int main () { 

//char buf[255];
//char reponse[255];
//fgets(reponse,255, stdin);
//reponse[strlen(reponse)-1] = 0;
  //  ortho( reponse,buf);
    //printf("%s",buf);

    ///return 0;
//}

//--------------------------------------------------------------------------------------------------------------------------


 //if (reponse == -1) {
        //    printf("erreur entrez soit pile soit face.\n");
      //      tour--; 

void quit (char * saisie) {                                 // quitter le jeu
if(saisie = 0) {
    return 0;
}
}

int main () {
int saisie;
quit(saisie);
printf("Vous quittez le jeu \n");
  return 0;
}




int transform(char * saisie){
    char mini[255];
    saisie[strlen(saisie)-1] = 0; 
    memset(mini,0,255);
    ortho(saisie,mini);
    printf("%s", mini);    
    if(strcmp(saisie, "pile") == 0) {
        return PILE;
    }
    if( strcmp(saisie, "face") == 0) {
        return FACE;
    }

    if(strcmp(saisie, "1") == 0) {
        return PILE;
    }
    if( strcmp(saisie, "2") == 0) {
        return FACE;
    }
    if(strcmp(saisie, "p") == 0) {
        return PILE;
    }
    if( strcmp(saisie, "f") == 0) {
        return FACE;
    
    }
        return -1;    // = erreur
    }


int chartoint(char *saisie) {
    char convMIN[255];
    // Enlever le saut de ligne s'il est présent
    saisie[strlen(saisie)-1] = 0;
    memset(convMIN, 0, 255); 
    ortho(saisie, convMIN);



    // Accepter "1" et "2"
    if (strcmp(convMIN, "p") == 0) {
        return PILE;
    } else if (strcmp(convMIN, "f") == 0) {
        return FACE;
    }
    if (strcmp(convMIN, "0") == 0) {
        return -2;
    }
    if (strcmp(convMIN, "1") == 0) {
        return PILE;
    } else if (strcmp(convMIN, "2") == 0) {
        return FACE;
    }

    // Vérifier si la saisie est "pile" ou "face"
    if (strcmp(convMIN, "pile") == 0) {
        return PILE;
    } else if (strcmp(convMIN, "face") == 0) {
        return FACE;
    }

    // Si la saisie n'est ni "pile", "face", "1" ou "2", retourner une erreur
    return -1;

    for victoire ++ && defaite ++
    mettre au pluriel 
    donc printf victoire%s, victoire
    idem pour defaite

    while(victoire > 1) {
        printf("victoires\n", victoire);
    }

    while(defaite > 1) {
        printf("défaites\n", defaite);
    }