#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#define PIERRE 1
#define FEUILLE 2
#define CISEAUX 3
#define EGALITE
#define WIN
#define LOOSE

int CF(int main1, int main2){
        ////PIERRE
    if(main1 == PIERRE && main2 == PIERRE) return 2;
    if(main1 == PIERRE && main2 == FEUILLE) return 0;
    if(main1 == PIERRE && main2 == CISEAUX) return 1;
        ////FEUILLE
    if(main1 == FEUILLE && main2 == PIERRE) return 1;
    if(main1 == FEUILLE && main2 == FEUILLE) return 2;
    if(main1 == FEUILLE && main2 == CISEAUX) return 0;
        //////CISEAUX
    if(main1 == CISEAUX && main2 == PIERRE) return 0;
    if(main1 == CISEAUX && main2 == FEUILLE) return 1;
    if(main1 == CISEAUX && main2 == CISEAUX) return 2;

    return -1;  // En cas de saisie incorrecte
}


int main(){
    char buf1[255];
    char buf2[255];

    char joueur1[255];
    char joueur2[255];

    int victoire1 = 0, defaite1 = 0; ///Player one
    int victoire2 = 0, defaite2 = 0; ///l'autre
    
    printf("---------------------- PIERRE, FEUILLE, PAPIER, CISEAUX --------------------\n");
    printf("Qui est le premier joueur ?\n");
    fgets(joueur1, sizeof(joueur1), stdin);
    printf("Qui est le deuxième joueur ?\n");
    fgets(joueur2, sizeof(joueur2), stdin);

    for(int i=0;i<10;i++){

        printf("1. Pierre\n");
        printf("2. Feuille\n");
        printf("3. Ciseaux\n");

        printf("_______\n");
        printf("%s , à toi de jouer !\n",joueur1);
        fgets(buf1,sizeof(buf1),stdin);
        int saisie1 = atoi(buf1);

        printf("_______\n");
        printf("Maintenant c'est à ton tour %s \n",joueur2);
        fgets(buf2,sizeof(buf2),stdin);
        int saisie2 = atoi(buf2);
        int resultat = CF(saisie1,saisie2);

        if (resultat == -1){
            printf("saisie incorrect, veuillez réeseyer");
            i--;
            continue;
        }

        if (resultat == -3){
        printf("Pour commencer les joueurs comptent jusqu'à trois en mettant la main dans le dos. Une fois à trois les joueurs révèlent leur main (pierre, feuille ou ciseaux) en même temps.\nLa plus forte des formes l'emporte et le joueur marque le point gagnant.\nSi les deux joueurs utilisent la même forme c'est un match nul\n");
        }

        if(resultat == 1){
            printf("%s bien jouer!",joueur1);
            victoire1 ++;
            defaite2++;
        }

        if(resultat == 0){
            printf("%s bien jouer!*vieutricheurdecon* ",joueur2);
            victoire2 ++;
            defaite1++;
        }

        if(resultat == 2){
            printf("égalité... faite un effort..");
            i--;
        }

        printf("%s victoire: %d défaite: %d\n",joueur1,victoire1,defaite1);
        printf("%s victoire: %d défaite: %d\n",joueur2,victoire2,defaite2);

    }

    return 0;
}