#include <stdio.h>
#include <string.h>
#include "utils.h"

// Fonction pour afficher les instructions du jeu
void afficherInstructions()
{
    printf("Tapez les mots aussi vite que possible pour gagner!\n");
}

// Fonction pour configurer les mots du jeu
void definirMots(char listeMots[][100], int *nombreMots)
{
    int nbMots;
    printf("Combien de mots voulez-vous entrer ? ");
    scanf("%d", &nbMots);
    getchar(); // Pour supprimer le retour à la ligne

    for (int i = 0; i < nbMots; i++)
    {
        printf("Entrez le mot %d : ", i + 1);
        fgets(listeMots[*nombreMots], 100, stdin);
        listeMots[*nombreMots][strcspn(listeMots[*nombreMots], "\n")] = '\0'; // Enlever le retour à la ligne
        (*nombreMots)++;
    }
}

