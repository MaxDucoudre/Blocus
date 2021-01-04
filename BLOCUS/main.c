#include<stdlib.h>
#include<stdio.h>
#include<graph.h>


void dessin_bouton(char *nom, int emplacement) {
	couleur grey = 7697781;
	couleur lite_black = 2039583;
	couleur white = 14803425;
	int hauteur_fenetre = 600;
	int largeur_fenetre = 800;

	ChoisirCouleurDessin(grey);	
	RemplirRectangle(largeur_fenetre*0.05, hauteur_fenetre*emplacement/10 - 30, 235, 40);
	ChoisirCouleurDessin(white);
	EcrireTexte(largeur_fenetre*0.05 + 5, hauteur_fenetre*emplacement/10, nom, 2);
	ChoisirCouleurDessin(lite_black);
	DessinerRectangle(largeur_fenetre*0.05, hauteur_fenetre*emplacement/10 - 30, 235, 40);
}

short int bouton_clique(char *nom, int emplacement) {
	int hauteur_fenetre = 600;
	int largeur_fenetre = 800;

	if(_X > largeur_fenetre*0.05 && _X < largeur_fenetre*0.05 + 235 && _Y > hauteur_fenetre*emplacement/10 - 30 && _Y < hauteur_fenetre*emplacement/10 + 10) {
		return 1;
	}
}

void bouton_hover(int emplacement) {

	couleur blue = 3093129;
	couleur orange = 16344064;
	couleur grey = 7697781;
	couleur lite_black = 2039583;
	couleur lite_white = 15592941;
	couleur white = 14803425;
	couleur dark_grey = 2697513;
	int hauteur_fenetre = 600;
	int largeur_fenetre = 800;



	if(_X > largeur_fenetre*0.05 && _X < largeur_fenetre*0.05 + 235 && _Y > hauteur_fenetre*emplacement/10 - 30 && _Y < hauteur_fenetre*0.30 + 10) {
		ChoisirCouleurDessin(lite_white);
		DessinerRectangle(largeur_fenetre*0.05, hauteur_fenetre*emplacement/10 - 30, 235, 40);
	} else {
		ChoisirCouleurDessin(lite_black);
		DessinerRectangle(largeur_fenetre*0.05, hauteur_fenetre*emplacement/10 - 30, 235, 40);
	}		
}



int menu_debut() {
	return 1;
}

short int menu() {
	short int menu_start = 0;
	short int lancer_partie = 0;
	short int lancer_menu = 0;
	short int options = 0;
	short int statistiques = 0;
	short int quitter = 0;
	short int lancer_bouton = 0;
	couleur orange = 16344064;
	int hauteur_fenetre = 600;
	int largeur_fenetre = 800;
	short int cliquee = 0;


	while(menu_start != 1) {
		lancer_menu = menu_debut();

		if(lancer_menu == 1) {
			ChoisirCouleurDessin(orange);


			while(lancer_menu == 1) {
				EcrireTexte(largeur_fenetre*0.45, hauteur_fenetre*0.10, "Blocus !", 2);

				ChargerImageFond("image/muraille.jpg");
				dessin_bouton("Lancer la partie", 3);
				dessin_bouton("Statistiques", 4);
				dessin_bouton("Options", 5);
				dessin_bouton("Quitter", 6);

				lancer_bouton = 1;

				while(lancer_bouton == 1) {
					SourisPosition();
					bouton_hover(4);
					bouton_hover(4);
					bouton_hover(5);
					bouton_hover(6);

					cliquee = SourisCliquee();
					if(cliquee == 1) {
						lancer_partie = bouton_clique("Lancer la partie", 3);
						if (lancer_partie == 1) {
							lancer_bouton = 0;
							printf("Lancer la partie\n");
							return 1;
						}

			/* statistiques */

						statistiques = bouton_clique("Statistiques", 4);
						if (statistiques == 1) {
							lancer_bouton = 0;
							printf("Statistiques\n");
				/*
				stastistiques(); */
						}

			/* Options */
						options = bouton_clique("Options", 5); 
						if (options == 1) {
							printf("Options\n");

					/*
					options();  edite un fichier texte */
							options = 0;
							lancer_bouton = 0;
						}
			/*


			/* Quitter */
						quitter = bouton_clique("Quitter", 6);
						if (quitter == 1) {
							printf("Quitter\n");
							CacherFenetre();
							Touche();
							FermerGraphique();

							return EXIT_SUCCESS;
						}
					}

				}
			}
		}
	}
}




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
			/* 	jeux(); */
			lancer_partie = 0;
		}

	}

}