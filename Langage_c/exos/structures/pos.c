#include <stdio.h>
#include <string.h>

struct adresse {
    char rue[50];
    char ville[50];
    int codePostal;
};

struct user {
    char nom[50];
    int age;
    struct adresse adress;
};

int main() {

    char buf[255];
    buf[255] = atoi(buf);
    struct user main;

    printf("Entrez le nom: ");
    fgets(main.nom, sizeof(main.nom), stdin);
    main.nom[strlen(main.nom)-1] = 0;                           

    printf("Entrez l'âge: ");
    fgets (buf, 255, stdin) ;
    
    printf("Entrez la rue: ");
    fgets(main.adress.rue, sizeof(main.adress.rue), stdin);
    main.adress.rue[strlen(main.adress.rue) -1] = 0;

    printf("Entrez la ville: ");
    fgets(main.adress.ville, sizeof(main.adress.ville), stdin);
    main.adress.ville[strlen(main.adress.ville) - 1] = 0;

    printf("Entrez le code postal: ");
    fgets (buf, 255, stdin); 

    printf("\n Veuillez vérifier vos coordonées ci-dessous \n");
    printf("Nom: %s\n", main.nom);
    printf("Âge: %d\n", main.age);
    printf("adress: %s, %s %d\n", main.adress.rue, main.adress.ville, main.adress.codePostal);

    return 0;
}