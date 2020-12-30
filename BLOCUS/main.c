#include<stdlib.h>
#include<stdio.h>
#include<graph.h>




int main(void) {
	short int initialisation_graphique;
	short int quitter_jeux = 0;
	
	initialisation_graphique = InitialiserGraphique();
	if(initialisation_graphique = 0) {
		puts("Mode graphique non initialisé");
		return EXIT_FAILURE;
	}

	CreerFenetre(0, 0, 600, 800);
	ChoisirTitreFenetre("BLOCUS");

	while(quitter_jeux != 1) {
		lancer_partie = menu();
		if(lancer_partie == 1) {
			jeux();
			lancer_partie = 0;
		}
	}
}