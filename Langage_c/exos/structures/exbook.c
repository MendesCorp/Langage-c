#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

typedef struct book {
    char * titre;
    char * auteur;
    float prix;
} t_book;

int main () {

    t_book myBook;
    myBook.titre = "L'Alchimiste";
    myBook.auteur = "Paulo Coelho";
    myBook.prix = 12.99;
    printf("%s\n %s\n %f€\n", myBook.titre, myBook.auteur, myBook.prix);

    return 0;
}