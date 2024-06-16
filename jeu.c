#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "jeu.h"

// Fonction principale du jeu
int demarrerJeu(char listeMots[][100], int nombreMots, Participant participants[], int nbParticipants)
{
    char saisie[100];

    if (nombreMots == 0)
    {
        printf("Aucun mot n'est configuré.\n");
        return 1;
    }

    for (int i = 0; i < nbParticipants; i++)
    {
        printf("\n%s, êtes-vous prêt ? Appuyez sur Entrée pour commencer !\n", participants[i].nomParticipant);
        getchar(); // Attendre que le participant appuie sur Entrée

        srand(time(NULL)); // Générateur de nombres aléatoires
        int indexMot = rand() % nombreMots;

        printf("Tapez le mot suivant : %s\n", listeMots[indexMot]);

        time_t debut, fin;
        time(&debut); // Début du chronomètre

        do
        {
            fgets(saisie, sizeof(saisie), stdin); // Saisie de l'utilisateur
            saisie[strcspn(saisie, "\n")] = '\0'; // Supprimer le retour à la ligne

            if (strcmp(saisie, listeMots[indexMot]) != 0)
            {
                printf("Incorrect, réessayez : ");
            }
        }
        while (strcmp(saisie, listeMots[indexMot]) != 0);

        time(&fin); // Fin du chronomètre
        participants[i].tempsSaisi = difftime(fin, debut);
        printf("Bravo %s ! Vous avez tapé le mot en %.2f secondes.\n", participants[i].nomParticipant, participants[i].tempsSaisi);
    }

    // Tri des participants par temps (tri à bulles)
    for (int i = 0; i < nbParticipants - 1; i++)
    {
        for (int j = 0; j < nbParticipants - i - 1; j++)
        {
            if (participants[j].tempsSaisi > participants[j + 1].tempsSaisi)
            {
                Participant temp = participants[j];
                participants[j] = participants[j + 1];
                participants[j + 1] = temp;
            }
        }
    }

    // Affichage des scores des participants
    printf("\nScores :\n");
    for (int i = 0; i < nbParticipants; i++)
    {
        printf("%s : %.2f secondes\n", participants[i].nomParticipant, participants[i].tempsSaisi);
    }

    return 0;
}
