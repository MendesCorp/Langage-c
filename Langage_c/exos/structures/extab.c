#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

typedef struct student {
    char* name;
    int age;
    float grade;
} t_student;


int main () {

    t_student etudiant[3] = {
        {"Alice", 20, 15.5},
        {"Bob", 22, 14.0},
        {"Charlie", 19, 16.2}
    };

    for (int i = 0; i < 3; i++) {
        printf("%s : %d ans, %f de moyenne\n", etudiant[i].name, etudiant[i].age, etudiant[i].grade);
    }

    return 0;
}