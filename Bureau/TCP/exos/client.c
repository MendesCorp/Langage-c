#include "global.h"

#define SERV_PORT 1460
#define CLIENT_PORT 2500

int main () {

    int client_fd = socket (AF_INET, SOCK_STREAM, 0); perror ("socket");
    if (client_fd == -1) return EXIT_FAILURE;

    struct sockaddr_in client = {
        .sin_family = AF_INET,
        .sin_port = htons (CLIENT_PORT),
        .sin_addr.s_addr = INADDR_ANY
    };

    int error = bind (client_fd, (struct sockaddr *) &client, sizeof client); perror ("bind");
    if (error == -1) return EXIT_FAILURE;

    struct sockaddr_in serv = {
        .sin_family = AF_INET, 
        .sin_port = htons (SERV_PORT),
        .sin_addr.s_addr = INADDR_ANY
    };

    error = connect (client_fd, (struct sockaddr *) &serv, sizeof serv); perror ("connect");
    if (error == -1) return EXIT_FAILURE;

    // send au serveur
    char entree [BUF_SIZE]; memset (entree, 0, BUF_SIZE); 
    printf ("Entrez une tâche à ajouter dans votre ToDoList \n");
    fgets (entree, BUF_SIZE, stdin);

    error = send (client_fd, entree, strlen (entree), 0); perror ("send");
    if (error == -1) return EXIT_FAILURE;

    close (client_fd);

    return 0;
}
