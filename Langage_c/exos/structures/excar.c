#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

typedef struct car {
    char * marque;
    int année;
    float prix;
} t_car;

int main () {
    t_car myCar;
    myCar.marque = "Toyota";
    myCar.année = 2015;
    myCar.prix = 15000.0;
    printf ("%s\n%d\n%f€\n", myCar.marque, myCar.année, myCar.prix);


    return 0;
}