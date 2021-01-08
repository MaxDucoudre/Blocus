#include<stdlib.h>
#include<stdio.h>
#include<graph.h>
#include"menu.h"
#include"jeux.h"


int main(void) {
	short int initialisation_graphique;
	short int quitter_jeux = 0;
	int largeur, hauteur;
	short int lancer_partie;

	int hauteur_fenetre = 600;
	int largeur_fenetre = 800;

	initialisation_graphique = InitialiserGraphique();
	if(initialisation_graphique = 0) {
		puts("Mode graphique non initialisé");
		return EXIT_FAILURE;
	}

	CreerFenetre(0, 0, largeur_fenetre, hauteur_fenetre);
	ChoisirTitreFenetre("BLOCUS");



	while(quitter_jeux != 1) {
		lancer_partie = menu();
		if(lancer_partie == 1) {
			jeux();
			lancer_partie = 0;
		}
	}
}