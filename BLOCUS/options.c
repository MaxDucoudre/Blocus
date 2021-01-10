#include<stdlib.h>
#include<stdio.h>
#include<graph.h>
#include"bouton.h"


short int menu_options() {
	couleur orange = 16344064;
	couleur dark_grey = 2697513;
	int hauteur_fenetre = 600;
	int largeur_fenetre = 800;
	short int options = 1;
	int enable_IA = 1;
	int taille_grille = 3;
	short int cliquee;
	FILE* flux;
/*
	char carac_grille[25] = "Taille de la grille : 3x3";
*/
	while(options == 1) { 
	couleur lite_black = 2039583;
	couleur lite_white = 15592941;

		ChargerImageFond("image/muraille.jpg");

		ChoisirCouleurDessin(orange);
		EcrireTexte(largeur_fenetre*0.45, hauteur_fenetre*0.10, "Blocus !", 2);

		ChoisirCouleurDessin(dark_grey);
		EcrireTexte(largeur_fenetre*0.05, hauteur_fenetre*0.20, "Options :", 2);

		/*
		flux = fopen("options", "r");
		fread(&enable_IA, sizeof(int), 1, flux);
		fread(&taille_grille, sizeof(int), 1, flux);

/*
		carac_grille[22] = (char) taille_grille;
		carac_grille[24] = (char) taille_grille;
*/

		if(enable_IA == 1) {
			bouton_options("Mode de jeux : 1 joueur", 3);
		} else {
			bouton_options("Mode de jeux : 2 joueurs", 3);
		}


		if(taille_grille == 3) {
			bouton_options("Taille de la grille : 3x3", 4);
		} else if (taille_grille == 4) {
			bouton_options("Taille de la grille : 4x4", 4);
		} else if (taille_grille == 5) {
			bouton_options("Taille de la grille : 5x5", 4);
		} else if (taille_grille == 6) {
			bouton_options("Taille de la grille : 6x6", 4);
		} else if (taille_grille == 7) {
			bouton_options("Taille de la grille : 7x7", 4);
		} else if (taille_grille == 8) {
			bouton_options("Taille de la grille : 8x8", 4);
		} else if (taille_grille == 9) {
			bouton_options("Taille de la grille : 9x9", 4);
		}


		bouton_options("Retour", 9);


		do{
			SourisPosition();
			bouton_options_hover(3);
			bouton_options_hover(4);
			bouton_options_hover(9);


			cliquee = SourisCliquee();
			if(cliquee == 1) {

				if(_X > largeur_fenetre*0.05 && _X < largeur_fenetre*0.05 + 350 && _Y > hauteur_fenetre*0.30 - 30 && _Y < hauteur_fenetre*0.30 + 10) {
					if(enable_IA == 1) {
						bouton_options("Mode de jeux : 2 joueurs", 3);
						enable_IA = 0;
					} else {
						bouton_options("Mode de jeux : 1 joueur", 3);
						enable_IA = 1;
					}
				}

				if(_X > largeur_fenetre*0.05 && _X < largeur_fenetre*0.05 + 350 && _Y > hauteur_fenetre*0.4 - 30 && _Y < hauteur_fenetre*0.4 + 10) {
					if(taille_grille == 3) {
						bouton_options("Taille de la grille : 4x4", 4);
						taille_grille = 4;
					} else if(taille_grille == 4) {
						bouton_options("Taille de la grille : 5x5", 4);
						taille_grille = 5;
					} else if(taille_grille == 5) {
						bouton_options("Taille de la grille : 6x6", 4);
						taille_grille = 6;
					} else if(taille_grille == 6) {
						bouton_options("Taille de la grille : 7x7", 4);
						taille_grille = 7;
					} else if(taille_grille == 7) {
						bouton_options("Taille de la grille : 8x8", 4);
						taille_grille = 8;
					} else if(taille_grille == 8) {
						bouton_options("Taille de la grille : 9x9", 4);
						taille_grille = 9;
					} else if(taille_grille == 9) {
						bouton_options("Taille de la grille : 3x3", 4);
						taille_grille = 3;
					}
				}

				if(_X > largeur_fenetre*0.05 && _X < largeur_fenetre*0.05 + 350 && _Y > hauteur_fenetre*0.9 - 30 && _Y < hauteur_fenetre*0.9 + 10) {
					options = 0;
				}
			}
		} while (options == 1);

/*
		fclose(flux);
*/
	}

}