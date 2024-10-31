#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#define BUF_SIZE 255

//Exercice du matin :

//Enregistrer le prix, nom et quantité de trois produits différents dans un fichier.
//Les produits sont :
//Pomme 3€ 10
//Cerise 1,50€ 17
//Poire 5€ 2

//1. Enregistrer les infos de chaque produit dans un fichier.   
//2. Lisez le fichier au démarrage du programme puis affichez chaque produit.     
//3. Mettez en place un enregistrement de type append à partir de la fin du fichier pour enregistrer de nouveaux produits.
//4. A l'aide de fgets demander a l'utilisateur les données du produit qu'il souhaite ajouter pour que l'application soit dynamique.


typedef struct produit {
    char* nom;
    float prix;
    int qté;    
} t_produit;

int main () {    
   
    FILE *file = fopen("fruit.txt", "w");
    fprintf (file, "pomme x10 : 3€\ncerise x17 : 1.50€\npoire x2 : 5€\n");
    fclose (file);

    t_produit fruit1;
        fruit1.nom = "pomme";
        fruit1.prix = 3.0;
        fruit1.qté = 10;
        printf ("\n%s\n%f€\n%d\n", fruit1.nom, fruit1.prix, fruit1.qté);
        printf ("_____________________________________________________\n");

    t_produit fruit2;
        fruit2.nom = "cerise";
        fruit2.prix = 1.50;
        fruit2.qté = 17;
        printf ("%s\n%f€\n%d\n", fruit2.nom, fruit2.prix, fruit2.qté);
        printf ("_____________________________________________________\n");

    t_produit fruit3;
        fruit3.nom = "poire";
        fruit3.prix = 5.0;
        fruit3.qté = 2;
        printf ("%s\n%f€\n%d\n", fruit3.nom, fruit3.prix, fruit3.qté);    
        printf ("_____________________________________________________\n");
    
    FILE* fd = fopen(fruit3.nom, "a");
    fclose (fd);

    FILE * fdnew = fopen(fruit3.nom, "r+");
    fclose (fd);

    fwrite (&fruit3, sizeof(t_produit), 1, fd);
    char buf[255];
    printf ("\nVous pouvez maintenant enregistrer de nouveaux produits\n"); // fprintf ???
    fgets (buf,BUF_SIZE,stdin);                                             // sscanf ???

    return 0;
}
