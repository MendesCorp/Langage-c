#include <stdio.h>
#include <string.h>
#include <stdio.h>
#include <time.h>

#define PIERRE 1
#define FEUILLE 2
#define CISEAUX 3

//FONCTIONS :

int estEgal(char *entree, const char *mot){
    return strcmp(entree, mot) == 0;
}

// Fonction de comparaison des choix


int CF (int main1, int main2) {

    if (main1 == PIERRE && main2 == PIERRE) {
        return 2;
    }

    if (main1 == PIERRE && main2 == FEUILLE) {
        return 0;
    }

    if (main1 == PIERRE && main2 == CISEAUX) {
        return 1;
    }

    if (main1 == FEUILLE && main2 == PIERRE) {
        return 1;
    }

    if (main1 == FEUILLE && main2 == FEUILLE) {
        return 2;
    }

    if (main1 == FEUILLE && main2 == CISEAUX) {
        return 0;
    } 

    if (main1 == CISEAUX && main2 == PIERRE) {
        return 0;
    }

    if (main1 == CISEAUX && main2 == FEUILLE) {
        return 1;
    }

    if (main1 == CISEAUX && main2 == CISEAUX) {
        return 2;
    }

    return -1;  

}

int convertirSaisie(char *saisie) {
    ///PIERRE
    if(estEgal(saisie, "pierre\n") || estEgal(saisie, "1\n") || estEgal(saisie, "rock\n")) {
        return PIERRE;
    }
    ///PAPIER
    if (estEgal(saisie, "feuille\n") || estEgal(saisie, "2\n") || estEgal(saisie, "papier\n")) {
        return FEUILLE;
    }
    ///CISEAUX
    if(estEgal(saisie, "ciseaux\n") || estEgal(saisie, "3\n") || estEgal(saisie, "cissor\n")) {
        return CISEAUX;
    }
}

int main () {

    printf("---------------------- PIERRE, FEUILLE, PAPIER, CISEAUX --------------------\n");

    char saisie1[255];
    char saisie2[255];
    srand(time(NULL));
    int mains = (float) rand() / RAND_MAX * 3 + 1;
    int hand1 = 0;
    int hand2 = 0;
    int score = 0;
    int victoirej1 = 0;
    int victoirej2 = 0;

    char joueur1[255];
    char joueur2[255];
    printf("Qui est le premier joueur ?\n");
    fgets(joueur1, sizeof(joueur1), stdin);
    printf("Qui est le deuxième joueur ?\n");
    fgets(joueur2, sizeof(joueur2), stdin);
    printf("joueur 1: %s\njoueur 2: %s",joueur1,joueur2);


    for (int i = 0; i < 4; i++ ) {

        printf("%s ?", joueur1);
        printf("1. Pierre\n");
        printf("2. Feuille\n");
        printf("3. Ciseaux\n");
        fgets(saisie1, sizeof(saisie1), stdin);
    
        hand1 = gethand(saisie1);
           
        
    return 0;
}