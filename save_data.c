#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    // Ouvre le fichier en mode écriture
    FILE *fptr;
    fptr = fopen("data.txt", "a");

    if (fptr == NULL)
    {
        printf("Erreur lors de l'ouverture du fichier.\n");
        exit(1);
    }

    // Récupère les données envoyées par le formulaire
    char *data = getenv("QUERY_STRING");

    // Traitement des données
    char *phone = strtok(data, "&");
    char *email = strtok(NULL, "&");

    phone = strchr(phone, '=') + 1;
    email = strchr(email, '=') + 1;

    // Enregistre les données dans le fichier
    fprintf(fptr, "Numéro de téléphone : %s, Adresse e-mail : %s\n", phone, email);

    printf("Content-type:text/html\n\n");
    printf("<html><body>");
    printf("<h1>Données enregistrées avec succès!</h1>");
    printf("</body></html>");

    fclose(fptr);

    return 0;
}
