#include<stdlib.h>
#include<stdio.h>
#include<graph.h>
#include"options.h"
#include"bouton.h"
#include"jeux.h"



short int menu(int i, struct parametres o) {
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


	while(lancer_menu == 1) {
		ChargerImageFond("image/muraille.jpg");
		ChoisirCouleurDessin(orange);
		EcrireTexte(largeur_fenetre*0.45, hauteur_fenetre*0.10, "Blocus !", 2);


		dessin_bouton("Lancer la partie", 3);
		dessin_bouton("Statistiques", 4);
		dessin_bouton("Options", 5);
		dessin_bouton("Quitter", 8);

		lancer_bouton = 1;

		do {
			SourisPosition();
			bouton_hover(3);
			bouton_hover(4);
			bouton_hover(5);
			bouton_hover(8);

			cliquee = SourisCliquee();
			if(cliquee == 1) {
				lancer_partie = bouton_clique("Lancer la partie", 3);
				if (lancer_partie == 1) {
					printf("Lancer la partie\n");
					jeux(o);
					return 0;
				}

			/* statistiques */

				statistiques = bouton_clique("Statistiques", 4);
				if (statistiques == 1) {
					printf("Statistiques\n");
				}

			/* Options */
				options = bouton_clique("Options", 5); 
				if (options == 1) {
					printf("Options\n");
					o = menu_options(i, o);
					i=1;
					lancer_bouton = 0;
				}
			/*


			/* Quitter */
				quitter = bouton_clique("Quitter", 8);
				if (quitter == 1) {
					printf("Quitter\n");


					return 2;
				}
			}
		} while(lancer_bouton == 1);
	}
}


