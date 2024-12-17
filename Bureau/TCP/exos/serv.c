#include "global.h"

#define SERV_PORT 1460


int main () {

    int serv_fd = socket (AF_INET, SOCK_STREAM, 0); perror ("socket");
    if (serv_fd == -1) return EXIT_FAILURE;

    struct sockaddr_in serv = {
        .sin_family = AF_INET, 
        .sin_port = htons (SERV_PORT),
        .sin_addr.s_addr = INADDR_ANY
    };

    int error = bind (serv_fd, (struct sockaddr *) &serv, sizeof serv); perror ("bind");
    if (error == -1) return EXIT_FAILURE;

    error = listen (serv_fd, BUFSIZ); perror ("listen");
    if (error == -1) return EXIT_FAILURE;

    struct sockaddr_in client;
    socklen_t len;
    int client_fd = accept (serv_fd, (struct sockaddr *) &client, &len); perror ("accept");
    if (client_fd == -1) return EXIT_FAILURE;

    // reception du message client

    char buf [BUF_SIZE];
    error = recv (client_fd, buf, BUFSIZ, 0); perror ("recv");
    printf ("%s \n", buf);  
    if (error == -1) return EXIT_FAILURE;


// ouverture tache dans un dossier 

    char filename [] = "list";
    FILE* fd = fopen (filename, "w+"); 
    time_t now = time (NULL);

    struct tm tm_now = *localtime (&now);

    char s_now[sizeof "JJ/MM/AAAA HH:MM:SS"];

    strftime (s_now, sizeof s_now, "%d/%m/%Y %H:%M:%S", &tm_now);

    fprintf (fd, "02/12/24 %d : %s \n", s_now, buf);

    fclose (fd);

    close (serv_fd); 
    close (client_fd);

    return 0;
}