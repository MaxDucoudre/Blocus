#include<stdlib.h>
#include<stdio.h>
#include<graph.h>



int main(void) {
	int initialisation_graphique;
	int hauteur_fenetre = 600;
	int largeur_fenetre = 800;
	couleur blue = 3093129;
	couleur orange = 16344064;
	couleur grey = 7697781;
	couleur lite_black = 2039583;
	couleur lite_white = 15592941;
	couleur white = 14803425;


	short int cliquee = 0;

	short int quitter = 0;
	short int lancer_partie = 0;
	short int bouton_options = 0;
	short int bouton_statistiques = 0;
	short int bouton_regles = 0;
	short int quitter_menu = 0;

	short int enable_IA = 1;


	

	initialisation_graphique = InitialiserGraphique();
	if(initialisation_graphique = 0) {
		puts("Mode graphique non initialisé");
		return EXIT_FAILURE;
	}



    CreerFenetre(0, 0, largeur_fenetre, hauteur_fenetre);
	ChoisirTitreFenetre("BLOCUS");


	ChargerImageFond("image/muraille.jpg");

	ChoisirCouleurDessin(orange);
	EcrireTexte(largeur_fenetre*0.45, hauteur_fenetre*0.10, "Blocus !", 2);


	ChoisirCouleurDessin(grey);
	RemplirRectangle(largeur_fenetre*0.05, hauteur_fenetre*0.30 - 30, 235, 40);
	ChoisirCouleurDessin(white);
	EcrireTexte(largeur_fenetre*0.05 + 5, hauteur_fenetre*0.30, "Lancer la partie", 2);
	ChoisirCouleurDessin(lite_black);
	DessinerRectangle(largeur_fenetre*0.05, hauteur_fenetre*0.30 - 30, 235, 40);

	ChoisirCouleurDessin(grey);	
	RemplirRectangle(largeur_fenetre*0.05, hauteur_fenetre*0.40 - 30, 235, 40);
	ChoisirCouleurDessin(white);
	EcrireTexte(largeur_fenetre*0.05 + 5,  hauteur_fenetre*0.40, "Statistiques", 2);
	ChoisirCouleurDessin(lite_black);
	DessinerRectangle(largeur_fenetre*0.05, hauteur_fenetre*0.40 - 30, 235, 40);


	ChoisirCouleurDessin(grey);
	RemplirRectangle(largeur_fenetre*0.05, hauteur_fenetre*0.50 - 30, 235, 40);
	ChoisirCouleurDessin(white);
	EcrireTexte(largeur_fenetre*0.05 + 5,  hauteur_fenetre*0.50, "Options", 2);
	ChoisirCouleurDessin(lite_black);
	DessinerRectangle(largeur_fenetre*0.05, hauteur_fenetre*0.50 - 30, 235, 40);

	ChoisirCouleurDessin(grey);
	RemplirRectangle(largeur_fenetre*0.05, hauteur_fenetre*0.60 - 30, 235, 40);
	ChoisirCouleurDessin(white);
	EcrireTexte(largeur_fenetre*0.05 + 5,  hauteur_fenetre*0.60, "Quitter", 2);
	ChoisirCouleurDessin(lite_black);
	DessinerRectangle(largeur_fenetre*0.05, hauteur_fenetre*0.60 - 30, 235, 40);
	

	ChoisirCouleurDessin(grey);
	RemplirRectangle(largeur_fenetre*0.08, hauteur_fenetre*0.80 - 30, 390, 100);
	ChoisirCouleurDessin(lite_black);
	DessinerRectangle(largeur_fenetre*0.08, hauteur_fenetre*0.80 - 30, 390, 100);
	ChoisirCouleurDessin(white);	
	EcrireTexte(largeur_fenetre*0.08 + 5,  hauteur_fenetre*0.80, "Recapitulatif de la partie :", 2);

	EcrireTexte(largeur_fenetre*0.08 + 5,  hauteur_fenetre*0.85, "Joueurs :", 1);

	EcrireTexte(largeur_fenetre*0.08 + 5,  hauteur_fenetre*0.90, "Taille de la grille :", 1);



	ChoisirCouleurDessin(grey);
	RemplirRectangle(largeur_fenetre*0.80, hauteur_fenetre*0.93 - 30, 95, 18);
	ChoisirCouleurDessin(white);
	EcrireTexte(largeur_fenetre*0.80 + 5,  hauteur_fenetre*0.90, "Comment jouer ?", 0);
	ChoisirCouleurDessin(lite_black);
	DessinerRectangle(largeur_fenetre*0.80, hauteur_fenetre*0.93 - 30, 95, 18);


	ChoisirCurseur(40);

	do {
		SourisPosition();
		if(_X > largeur_fenetre*0.05 && _X < largeur_fenetre*0.05 + 235 && _Y > hauteur_fenetre*0.30 - 30 && _Y < hauteur_fenetre*0.30 + 10) {
			ChoisirCouleurDessin(lite_white);
			DessinerRectangle(largeur_fenetre*0.05, hauteur_fenetre*0.30 - 30, 235, 40);
		} else {
			ChoisirCouleurDessin(lite_black);
			DessinerRectangle(largeur_fenetre*0.05, hauteur_fenetre*0.30 - 30, 235, 40);
		}

		if(_X > largeur_fenetre*0.05 && _X < largeur_fenetre*0.05 + 235 && _Y > hauteur_fenetre*0.40 - 30 && _Y < hauteur_fenetre*0.40 + 10) {
			ChoisirCouleurDessin(lite_white);
			DessinerRectangle(largeur_fenetre*0.05, hauteur_fenetre*0.40 - 30, 235, 40);
		} else {
			ChoisirCouleurDessin(lite_black);
			DessinerRectangle(largeur_fenetre*0.05, hauteur_fenetre*0.40 - 30, 235, 40);
		}

		if(_X > largeur_fenetre*0.05 && _X < largeur_fenetre*0.05 + 235 && _Y > hauteur_fenetre*0.50 - 30 && _Y < hauteur_fenetre*0.50 + 10) {

			ChoisirCouleurDessin(lite_white);
			DessinerRectangle(largeur_fenetre*0.05, hauteur_fenetre*0.50 - 30, 235, 40);
		} else {
			ChoisirCouleurDessin(lite_black);
			DessinerRectangle(largeur_fenetre*0.05, hauteur_fenetre*0.50 - 30, 235, 40);
		}

		if(_X > largeur_fenetre*0.05 && _X < largeur_fenetre*0.05 + 235 && _Y > hauteur_fenetre*0.60 - 30 && _Y < hauteur_fenetre*0.60 + 10) {
			ChoisirCouleurDessin(lite_white);
			DessinerRectangle(largeur_fenetre*0.05, hauteur_fenetre*0.60 - 30, 235, 40);
		} else {
			ChoisirCouleurDessin(lite_black);
			DessinerRectangle(largeur_fenetre*0.05, hauteur_fenetre*0.60 - 30, 235, 40);
		}




		cliquee = SourisCliquee();
		printf("%d\n", cliquee);
		if(cliquee == 1)  {
			if(_X > largeur_fenetre*0.05 && _X < largeur_fenetre*0.05 + 235 && _Y > hauteur_fenetre*0.30 - 30 && _Y < hauteur_fenetre*0.30 + 10) {
				printf("Lancer la partie\n");
				lancer_partie = 1;
				quitter_menu = 1;
			}
		
			if(_X > largeur_fenetre*0.05 && _X < largeur_fenetre*0.05 + 235 && _Y > hauteur_fenetre*0.40 - 30 && _Y < hauteur_fenetre*0.40 + 10) {
				printf("Statistiques\n");
				bouton_statistiques = 1;
				quitter_menu = 1;
			}

			if(_X > largeur_fenetre*0.05 && _X < largeur_fenetre*0.05 + 235 && _Y > hauteur_fenetre*0.50 - 30 && _Y < hauteur_fenetre*0.50 + 10) {
				printf("Options\n");
				bouton_options = 1;
				quitter_menu = 1;
			}

			if(_X > largeur_fenetre*0.05 && _X < largeur_fenetre*0.05 + 235 && _Y > hauteur_fenetre*0.60 - 30 && _Y < hauteur_fenetre*0.60 + 10) {
				printf("Quitter\n");
				CacherFenetre();
				Touche();
	   			FermerGraphique();
	   			return EXIT_SUCCESS;
			}
		}

	} while(quitter_menu != 1);


/* Les options */
	enable_IA = 1;

/* Le jeux */

	if(lancer_partie = 1) {


	}





	CacherFenetre();
	Touche();
	FermerGraphique();

	return EXIT_SUCCESS;

}