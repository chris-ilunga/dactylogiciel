#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "jeu.h"
#include "utils.h"

int main()
{
    int option;
    char listeMots[100][100]; // Tableau pour stocker les mots
    int nombreMots = 0; // Compteur de mots
    Participant participants[10]; // Tableau pour stocker les participants
    int nbParticipants = 0; // Nombre de participants
    printf("\n\nUDBL - DACTYLOGICIEL\n\n");
    sleep(5);
    printf("\nILUNGA SIMBI CHRISTIAN\n");
    printf("\nKABASELE MUTOMBO HUGUES\n");
    printf("\nKILIPUNDA KISULA GLODI\n");
    printf("\nKASONGO MENA JOSUE\n");
    sleep(5);

    system("clear");

    do
    {
        printf("\n\tMENU PRINCIPAL\n");
        printf("\n\t1. Démarrer\n");
        printf("\n\t2. Configurer\n");
        printf("\n\t3. Aide\n");
        printf("\n\t0. Quitter\n");
        printf("\n\tSélectionner une option : ");
        scanf("%d", &option);
        getchar(); // Pour consommer le '\n' laissé par scanf

        switch (option)
        {
        case 1:
            if (nombreMots == 0)
            {
                printf("Aucun mot n'est configuré.\n");
                break;
            }
            printf("Entrez le nombre de participants : ");
            scanf("%d", &nbParticipants);
            getchar(); // Pour supprimer le retour à la ligne

            for (int i = 0; i < nbParticipants; i++)
            {
                printf("Entrez le nom du participant %d : ", i + 1);
                fgets(participants[i].nomParticipant, sizeof(participants[i].nomParticipant), stdin);
                participants[i].nomParticipant[strcspn(participants[i].nomParticipant, "\n")] = '\0'; // Enlever le retour à la ligne
            }

            system("clear");
            printf("\nDÉMARRER\n");
            demarrerJeu(listeMots, nombreMots, participants, nbParticipants);
            break;

        case 2:
            system("clear");
            printf("\n\tCONFIGURATION\n");
            definirMots(listeMots, &nombreMots);
            break;

        case 3:
            system("clear");
            printf("\n\tAIDE\n");
            afficherInstructions();
            break;

        case 0:
            system("clear");
            printf("\n\tVOUS AVEZ QUITTÉ LE JEU\n");
            printf("\tAPPUYER SUR ENTRER POUR FERMER\n");
            break;

        default:
            system("clear");
            printf("\nVeuillez choisir une option valide\n");
            break;
        }
    }
    while (option != 0);

    return 0;
}
