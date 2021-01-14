#include<stdlib.h>
#include<stdio.h>
#include<graph.h>
#include"menu.h"
#include"options.h"

int main(void) {
	short int initialisation_graphique;
	int largeur, hauteur;
	short int action = 0;

	int i = 0;

	int hauteur_fenetre = 600;
	int largeur_fenetre = 800;

	struct parametres o = {6, 1, 1};



	initialisation_graphique = InitialiserGraphique();
	if(initialisation_graphique = 0) {
		puts("Mode graphique non initialisé");
		return EXIT_FAILURE;
	}

	CreerFenetre(0, 0, largeur_fenetre, hauteur_fenetre);
	ChoisirTitreFenetre("BLOCUS");

/*
	ChargerImageFond("image/start1.jpg");
	do {
		SourisPosition();
		printf("%d %d\n", _X, _Y);
		if(_X > 90 && _X < 715 && _Y > 118 && _Y < 370) {
			ChargerImageFond("image/start2.jpg");
		} else {
			ChargerImageFond("image/start1.jpg");
		}

	} while(1);
	*/


	while(action == 0) {

		action = menu(i, o);
		i=1;
		
		if(action == 2) {
			CacherFenetre();
			Touche();
			FermerGraphique();
			return EXIT_SUCCESS;
		}
	}

}