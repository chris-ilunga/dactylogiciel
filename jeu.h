#ifndef JEU_H
#define JEU_H

// Structure pour stocker les informations sur les participants
typedef struct
{
    char nomParticipant[50];
    double tempsSaisi;
} Participant;

// Fonction principale du jeu
int demarrerJeu(char listeMots[][100], int nombreMots, Participant participants[], int nbParticipants);

#endif

