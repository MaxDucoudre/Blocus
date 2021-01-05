#ifndef BOUTON_H
#define BOUTON_H

void dessin_bouton(char *nom, int emplacement);
short int bouton_clique(char *nom, int emplacement);
void bouton_hover(int emplacement);

void bouton_options(char *texte, int emplacement);
short int bouton_options_clique(int emplacement);
void bouton_options_hover(int emplacement);

#endif