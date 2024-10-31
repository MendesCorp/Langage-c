#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

typedef struct film {
    char * titre;
    int sortie;
    float note;
} t_film;

int saisie (struct film *f) {
    char buf[255];
    printf("Veuillez saisir un titre :");
    fgets(buf, sizeof(buf), stdin);
    int entree;
    f->titre = buf;
    printf("%s ", f->titre);

    if (strlen(f->titre) < 1) {
        printf("erreur, le titre doit comprendre plus d'un caractère\n");
        return 0;
    }
    
    printf("Veuillez saisir une date :");
    fgets(buf, sizeof(buf), stdin);
    entree = atoi(buf);
    f->sortie = buf;

    if (f->sortie < 1895) {
        return 0;
    }

    printf("%d : ", f->sortie);

    printf("Veuillez saisir une note :");
    fgets(buf, sizeof(buf), stdin);
    entree = atoi(buf);
    f->note = entree;
    
    if (f->note < 0 || f->note > 10) {
        printf("erreur, la note doit être comprise entre 0 et 10\n");
        return 0;
    } 
    
}

int main () {

    t_film myMovie;
    myMovie.titre = "Inception";
    myMovie.sortie = 2010;
    myMovie.note = 8.8;
    printf("%s %d %f\n", myMovie.titre, myMovie.sortie, myMovie.note);
    saisie (&myMovie);
    return 0;
}