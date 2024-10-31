#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h> 
#include <time.h>

#define PIERRE 1
#define FEUILLE 2
#define CISEAUX 3
#define QUITTER 0

// Fonction qui retourne 1 si les deux chaînes sont égales, sinon 0

int estEgal(char *entree, const char *mot) {
    return strcmp(entree, mot) == 0;
}

// Fonction de comparaison des choix

int CF(int main1, int main2) {
    if (main1 == PIERRE && main2 == PIERRE) return 2;
    if (main1 == PIERRE && main2 == FEUILLE) return 0;
    if (main1 == PIERRE && main2 == CISEAUX) return 1;

    if (main1 == FEUILLE && main2 == PIERRE) return 1;
    if (main1 == FEUILLE && main2 == FEUILLE) return 2;
    if (main1 == FEUILLE && main2 == CISEAUX) return 0;

    if (main1 == CISEAUX && main2 == PIERRE) return 0;
    if (main1 == CISEAUX && main2 == FEUILLE) return 1;
    if (main1 == CISEAUX && main2 == CISEAUX) return 2;

    if (main1 == QUITTER || main2 == QUITTER) return 3;
    return -1;  // problème 
}

// Fonction pour convertir la saisie en choix

int convertirSaisie(char *saisie) {
    if (estEgal(saisie, "pierre\n") || estEgal(saisie, "1\n") || estEgal(saisie, "rock\n")) return PIERRE;
    if (estEgal(saisie, "feuille\n") || estEgal(saisie, "2\n") || estEgal(saisie, "papier\n")) return FEUILLE;
    if (estEgal(saisie, "ciseaux\n") || estEgal(saisie, "3\n") || estEgal(saisie, "cissor\n")) return CISEAUX;

    if (estEgal(saisie, "Q\n") || estEgal(saisie, "q\n") || estEgal(saisie, "0\n")) return QUITTER;
    return -1;  // problème 
}

// Fonction pour sauvegarder les résultats dans un fichier

void sauvegarderPartie(char *joueur1, char *joueur2, int victoire1, int defaite1, int victoire2, int defaite2) {
    FILE *f = fopen("sauvegarde.txt", "w"); /// crée automatiquement un f.sauvegarde.txt 
    if (f == NULL) {
        printf("Erreur lors de l'ouverture du fichier de sauvegarde.\n");
        return;
    }

    fprintf(f, "%s %d %d\n", joueur1, victoire1, defaite1);
    fprintf(f, "%s %d %d\n", joueur2, victoire2, defaite2); 
    fclose(f);

    printf("Partie sauvegardée avec succès.\n");
}

// Fonction pour charger une partie sauvegardée

int chargerPartie(char *joueur1, char *joueur2, int *victoire1, int *defaite1, int *victoire2, int *defaite2) {
    FILE *f = fopen("sauvegarde.txt", "r");
    if (f == NULL) {
        printf("Aucune partie sauvegardée trouvée.\n");
        return 0;  // Pas de sauvegarde trouvée
    }

    fscanf(f, "%s %d %d", joueur1, victoire1, defaite1);
    fscanf(f, "%s %d %d", joueur2, victoire2, defaite2);
    fclose(f);
    printf("Partie chargée avec succès.\n");
    return 1;  // Sauvegarde trouvée et chargée
}

int main() {
    
    char buf1[255], buf2[255], buf3[255];
    char joueur1[255], joueur2[255];
    int victoire1 = 0, defaite1 = 0;
    int victoire2 = 0, defaite2 = 0;
    int choix; // peut être clarifié avec struct (famille de variables) entre accolades

    printf("^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n");
    printf("---------------------- PIERRE, FEUILLE, CISEAUX --------------------\n");
    printf("1. Nouvelle partie\n");
    printf("2. Charger la dernière partie\n");
    printf("3. Règles du jeu\n");
    printf("-------------------------- 'ENTER' pour continuer ------------------\n");
    fgets(buf3, sizeof(buf3), stdin); //// trigger entrée (pour passer à la suite)
    printf("____________________________________________________________________\n");

    while (1) {
        printf("1. Nouvelle partie\n");
        printf("2. Charger la dernière partie\n");
        printf("3. Voir les règles du jeu\n");
        printf("Choisissez une option : ");
        
        memset(buf1,0,255);
        fgets(buf1,255,stdin);
        buf1[strlen(buf1)-1]= 0;
        choix = atoi(buf1);

        if (choix == 3) {
            printf("_______________________________________________________________________________________________________________\n");
            printf("\nLe Shifumi est un jeu où deux joueurs choisissent simultanément entre 'pierre', 'feuille' ou 'ciseaux'.\n");
            printf("La pierre bat les ciseaux, les ciseaux battent la feuille, et la feuille bat la pierre.\n");
            printf("Si les deux joueurs font le même choix, il y a égalité.\n\n");
            printf("Pour supprimer une sauvegarde: supprimez le fichier 'sauvegarde.txt' dans votre dossier shifumi.\n\n");
            printf("________________________________________________________________________________________________________________\n");
            continue;  // Revenir au menu après avoir affiché les règles
        }

        if (choix == 2) {
            if (!chargerPartie(joueur1, joueur2, &victoire1, &defaite1, &victoire2, &defaite2)) {
                printf("Impossible de charger une partie. Une nouvelle partie va commencer.\n");
                choix = 1;

            } else {
                break;  // Sortir de la boucle si une partie est chargée
            }
        }

        if (choix == 1) {
            printf("Qui est le premier joueur ?\n");
            fgets(joueur1, sizeof(joueur1), stdin);
            printf("Qui est le deuxième joueur ?\n");
            fgets(joueur2, sizeof(joueur2), stdin);
            break;  // Sortir de la boucle et démarrer la partie
        }

        printf("Choix invalide, veuillez sélectionner 1, 2 ou 3.\n");
    }

    // Boucle du jeu
    for (int i = 0; i < 10; i++) {
        printf("1. Pierre\n");
        printf("2. Feuille\n");
        printf("3. Ciseaux\n");

        printf("_______\n");
        printf("%s, à toi de jouer ! (pierre, feuille, ciseaux ou 1, 2, 3)\n", joueur1);
        fgets(buf1, sizeof(buf1), stdin);
        int saisie1 = convertirSaisie(buf1);

        printf("_______\n");
        printf("Maintenant c'est à ton tour %s (pierre, feuille, ciseaux ou 1, 2, 3)\n", joueur2);
        fgets(buf2, sizeof(buf2), stdin);
        int saisie2 = convertirSaisie(buf2);

        int resultat = CF(saisie1, saisie2);

        if (saisie1 == -1 || saisie2 == -1) {
            printf("Saisie incorrecte, réessayez.\n");
            i--;
            continue;
        }
        if (resultat == 3) {
            printf("--------------GAME OVER----------------\n");
            return 0;
        }
        if (resultat == 1) {
            printf("\n%s gagne ce tour !\n", joueur1);
            victoire1++;
            defaite2++;
        } else if (resultat == 0) {
            printf("\n%s gagne ce tour !\n", joueur2);
            victoire2++;
            defaite1++;
        } else if (resultat == 2) {
            printf("Égalité !\n");
            i--;  // Ne compte pas ce tour en cas d'égalité
        }

        printf("%s - Victoires: %d Défaites: %d\n", joueur1, victoire1, defaite1);
        printf("%s - Victoires: %d Défaites: %d\n", joueur2, victoire2, defaite2);

        // Sauvegarder la partie après chaque tour
        sauvegarderPartie(joueur1, joueur2, victoire1, defaite1, victoire2, defaite2);
        sleep(3);
    }

    return EXIT_SUCCESS;
}
