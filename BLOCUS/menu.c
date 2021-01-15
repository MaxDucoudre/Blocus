#include<stdlib.h>
#include<stdio.h>
#include<graph.h>
#include"options.h"
#include"bouton.h"
#include"jeux.h"


short int menu(int i, int j) {
	short int lancer_partie = 0;
	short int lancer_menu = 1;
	short int options = 0;
	short int lancer_options = 0;
	short int statistiques = 0;
	short int quitter = 0;
	short int lancer_bouton = 0;
	couleur orange = 16344064;
	int hauteur_fenetre = 600;
	int largeur_fenetre = 800;
	short int cliquee = 0;

	struct parametres o;

	if(j==0) {
		o.grille = 6;
		o.ia = 1;
		o.hard = 1;
	}

	lancer_menu = 1;
	while(lancer_menu == 1) {
		

		ChargerImageFond("image/menu_principal1.png");

		dessin_bouton("Options", 1);
		dessin_bouton("Statistics", 2.5);
		dessin_bouton("Exit", 4.25);
		dessin_bouton_lancer_partie('y');
		dessin_bouton_lancer_partie('n');

		lancer_bouton = 1;

		do {
			SourisPosition();
			bouton_hover("Options", 1);
			bouton_hover("Statistics", 2.5);
			bouton_hover("Exit", 4.25);
			hover_bouton_lancer_partie('y');
			hover_bouton_lancer_partie('n');


			cliquee = SourisCliquee();
			if(cliquee == 1) {
				lancer_partie = cliquee_bouton_lancer_partie();
				if (lancer_partie == 1) {
					printf("Lancer la partie\n");
					jeux(o);
					return 0;
				}
				if(lancer_partie == 2) {
					lancer_menu = 0;
					return 3;
					
				}

			/* statistiques */

				statistiques = bouton_clique("Statistics", 2.5);
				if (statistiques == 1) {
					printf("Statistiques\n");
				}

			/* Options */
				options = bouton_clique("Options", 1); 
				if (options == 1) {
					printf("Options\n");
					o = menu_options(i, o);
					i=1;
					lancer_bouton = 0;
				}
			/*


			/* Quitter */
				quitter = bouton_clique("Exit", 4.25);
				if (quitter == 1) {
					printf("Quitter\n");


					return 2;
				}
			}
		} while(lancer_bouton == 1);
	}
}


