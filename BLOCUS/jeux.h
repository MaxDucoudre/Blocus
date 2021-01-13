#ifndef JEUX_H
#define JEUX_H


int jeux();
int charger_pion(int taille_grille, char *couleur_pion);
void bouton_notification(char *texte, int decalage, char *color);
int ecran_fin(char gagnant);

#endif