#include<stdlib.h>
#include<stdio.h>
#include<graph.h>
#include"bouton.h"


struct parametres{
	int grille;
	int ia;
	int hard;
};


struct parametres menu_options(int i, struct parametres o) {
	couleur orange = 16344064;
	couleur dark_grey = 2697513;
	int hauteur_fenetre = 600;
	int largeur_fenetre = 800;
	short int options = 1;

	int enable_IA;
	int taille_grille;
	int hard_mod;

	short int cliquee;

	couleur lite_black = 2039583;
	couleur lite_white = 15592941;




	while(options == 1) { 


		if(i==0) {
			enable_IA = 1;
			taille_grille = 6;
			hard_mod = 1;
		} else {
			taille_grille = o.grille;
			enable_IA = o.ia;
			hard_mod = o.hard;
		}


		ChargerImageFond("image/muraille.jpg");

		ChoisirCouleurDessin(orange);
		EcrireTexte(largeur_fenetre*0.45, hauteur_fenetre*0.10, "Blocus !", 2);

		ChoisirCouleurDessin(dark_grey);
		EcrireTexte(largeur_fenetre*0.05, hauteur_fenetre*0.20, "Options :", 2);


		if(hard_mod == 1) {
			bouton_options("Mode : Difficile", 5);
		} else {
			bouton_options("Mode : Normal", 5);
		}


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

		bouton_options("Reset", 8);
		bouton_options("Enregistrer", 9);


		do{
			SourisPosition();
			bouton_options_hover(3);
			bouton_options_hover(5);
			bouton_options_hover(4);
			bouton_options_hover(8);
			bouton_options_hover(9);


			cliquee = SourisCliquee();
			if(cliquee == 1) {

				if(_X > largeur_fenetre*0.05 && _X < largeur_fenetre*0.05 + 350 && _Y > hauteur_fenetre*0.5 - 30 && _Y < hauteur_fenetre*0.50 + 10) {
					if(hard_mod == 1) {
						bouton_options("Mode : Normal", 5);
						hard_mod = 0;
					} else {
						bouton_options("Mode : Difficile", 5);
						hard_mod = 1;
					}
				}

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

				if(_X > largeur_fenetre*0.05 && _X < largeur_fenetre*0.05 + 350 && _Y > hauteur_fenetre*0.8 - 30 && _Y < hauteur_fenetre*0.8 + 10) {
					i=0;
					puts("Reset");
					break;
				}


				if(_X > largeur_fenetre*0.05 && _X < largeur_fenetre*0.05 + 350 && _Y > hauteur_fenetre*0.9 - 30 && _Y < hauteur_fenetre*0.9 + 10) {
					options = 0;
					puts("Enregistrer");
					o.grille = taille_grille;
					o.ia = enable_IA;
					o.hard = hard_mod;

					return o;
				}
			}



		} while (options == 1);
	}


	

}