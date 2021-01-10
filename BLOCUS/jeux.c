#include<stdlib.h>
#include<stdio.h>
#include<graph.h>
#include"grille.h"
#include"souris_jeux.h"



int charger_pion(int taille_grille, char *couleur_pion) {
	char caractere_taille_grille;
	char sprite_num;
	char sprite_bleu[19] = "sprite/bleu3.png";
	char sprite_orange[19] = "sprite/orange3.png";

	int i;

	if(couleur_pion == "bleu") {

		caractere_taille_grille = '3';

		for(i = 3; i < taille_grille; i++) {
			caractere_taille_grille	= caractere_taille_grille + 1;
		}

		sprite_bleu[11] = caractere_taille_grille;
		printf("%s", sprite_bleu);
		sprite_num = ChargerSprite(sprite_bleu);
		return sprite_num;


	} else if (couleur_pion == "orange") {

		caractere_taille_grille = '3';

		for(i = 3; i < taille_grille; i++) {
			caractere_taille_grille	= caractere_taille_grille + 1;
		}

		sprite_orange[13] = caractere_taille_grille;
		printf("%s", sprite_orange);
		sprite_num = ChargerSprite(sprite_orange);

		return sprite_num;

	} else {

		puts("Pion non chargé");
		return EXIT_FAILURE;
	}
}

void bouton_notification(char *texte, int decalage, char *color) {
	int hauteur_fenetre = 600;
	int largeur_fenetre = 800;

	couleur blue = 3093129;
	couleur orange = 16344064;
	couleur red = 850606;
	couleur lite_black = 2039583;
	couleur grey = 7697781;


	ChoisirCouleurDessin(grey);
	RemplirRectangle(largeur_fenetre*0.25, hauteur_fenetre*0.92, 400, 40);

	ChoisirCouleurDessin(lite_black);
	DessinerRectangle(largeur_fenetre*0.25, hauteur_fenetre*0.92, 400, 40);

	if(color == "bleu") {
		ChoisirCouleurDessin(blue);
	} else if (color == "orange") {
		ChoisirCouleurDessin(orange);
	} else if (color == "rouge") {
		ChoisirCouleurDessin(red);
	}

	EcrireTexte(largeur_fenetre*0.25 + decalage, hauteur_fenetre*0.965, texte, 1);

}

void debut_jeux(int taille_grille) {
	int hauteur_fenetre = 600;
	int largeur_fenetre = 800;
	float cote_grille = (hauteur_fenetre-(hauteur_fenetre*0.2));
	float cote_case = cote_grille/taille_grille;
	int coord_hauteur, coord_largeur;
	int cliquee;

	float position_x_orange, position_y_orange;
	float position_x_bleu, position_y_bleu;
	float ancienne_pos_x_orange, ancienne_pos_y_orange;
	float ancienne_pos_y_bleu, ancienne_pos_x_bleu;

	int placer_orange = 0;
	int placer_bleu = 0;
	int i;

	int num_sprite_bleu, num_sprite_orange;
	couleur lite_white = 15592941;

	dessiner_grille(taille_grille);
	num_sprite_bleu = charger_pion(taille_grille, "bleu");
	printf("%d\n", num_sprite_bleu);
	num_sprite_orange = charger_pion(taille_grille, "orange");
	printf("%d\n", num_sprite_orange);


	bouton_notification("Tour d'orange : Placer votre pion", 45, "orange");
	while(placer_orange == 0) {
		cliquee = SourisCliquee();
		if(cliquee == 1) {
			if(_X > largeur_fenetre*0.2 && _X < largeur_fenetre*0.2 + (hauteur_fenetre - (hauteur_fenetre*0.2)) && _Y > hauteur_fenetre*0.1 && _Y < hauteur_fenetre*0.1 + hauteur_fenetre - (hauteur_fenetre*0.2)) {

				for(coord_hauteur = 0; coord_hauteur<taille_grille; coord_hauteur++) {
					for(coord_largeur = 0; coord_largeur<taille_grille; coord_largeur++) {
						if(_X > largeur_fenetre*0.2 + coord_largeur*(cote_grille/taille_grille) && _X < largeur_fenetre*0.2 + (coord_largeur+1)*(cote_grille/taille_grille) && _Y > hauteur_fenetre*0.1 + coord_hauteur*(cote_grille/taille_grille) && _Y < hauteur_fenetre*0.1 + (coord_hauteur+1)*(cote_grille/taille_grille)) {
							printf("%d %d\n", coord_largeur+1, coord_hauteur+1);
							position_x_orange = largeur_fenetre*0.2 + coord_largeur*(cote_grille/taille_grille);
							position_y_orange = hauteur_fenetre*0.1 + coord_hauteur*(cote_grille/taille_grille);

							AfficherSprite(num_sprite_orange,position_x_orange, position_y_orange);

							placer_orange = 1;
						}
					}
				}
			}
		}
	}

	bouton_notification("Tour de bleu : placer votre pion", 45, "bleu");

	while(placer_bleu == 0) {
		cliquee = SourisCliquee();
		if(cliquee == 1) {
			if(_X > largeur_fenetre*0.2 && _X < largeur_fenetre*0.2 + (hauteur_fenetre - (hauteur_fenetre*0.2)) && _Y > hauteur_fenetre*0.1 && _Y < hauteur_fenetre*0.1 + hauteur_fenetre - (hauteur_fenetre*0.2)) {

				for(coord_hauteur = 0; coord_hauteur<taille_grille; coord_hauteur++) {
					for(coord_largeur = 0; coord_largeur<taille_grille; coord_largeur++) {
						if(_X > largeur_fenetre*0.2 + coord_largeur*(cote_grille/taille_grille) && _X < largeur_fenetre*0.2 + (coord_largeur+1)*(cote_grille/taille_grille) && _Y > hauteur_fenetre*0.1 + coord_hauteur*(cote_grille/taille_grille) && _Y < hauteur_fenetre*0.1 + (coord_hauteur+1)*(cote_grille/taille_grille)) {
							printf("%d %d\n", coord_largeur+1, coord_hauteur+1);
							position_x_bleu = largeur_fenetre*0.2 + coord_largeur*(cote_grille/taille_grille);
							position_y_bleu = hauteur_fenetre*0.1 + coord_hauteur*(cote_grille/taille_grille);

							if(position_y_bleu == position_y_orange && position_x_bleu == position_x_orange) {
								bouton_notification("Tour de bleu : la case est prise", 45, "bleu");
								break;
							}

							AfficherSprite(num_sprite_bleu,position_x_bleu, position_y_bleu);

							placer_bleu = 1;
						}
					}
				}
			}
		}
	}
	/* Deplacement */
	bouton_notification("Tour d'orange : Bougez votre tour", 45, "orange");
	placer_orange = 0;
	i = 0;
	while(placer_orange == 0) {
		cliquee = SourisCliquee();
		if(cliquee == 1) {
			if(_X > largeur_fenetre*0.2 && _X < largeur_fenetre*0.2 + (hauteur_fenetre - (hauteur_fenetre*0.2)) && _Y > hauteur_fenetre*0.1 && _Y < hauteur_fenetre*0.1 + hauteur_fenetre - (hauteur_fenetre*0.2)) {

				for(coord_hauteur = 0; coord_hauteur<taille_grille; coord_hauteur++) {
					for(coord_largeur = 0; coord_largeur<taille_grille; coord_largeur++) {
						if(_X > largeur_fenetre*0.2 + coord_largeur*(cote_grille/taille_grille) && _X < largeur_fenetre*0.2 + (coord_largeur+1)*(cote_grille/taille_grille) && _Y > hauteur_fenetre*0.1 + coord_hauteur*(cote_grille/taille_grille) && _Y < hauteur_fenetre*0.1 + (coord_hauteur+1)*(cote_grille/taille_grille)) {
							printf("%d %d\n", coord_largeur+1, coord_hauteur+1);

							if(i == 0) {
								ancienne_pos_x_orange = position_x_orange;
								ancienne_pos_y_orange = position_y_orange;
							}
							i++;
							position_x_orange = largeur_fenetre*0.2 + coord_largeur*(cote_grille/taille_grille);
							position_y_orange = hauteur_fenetre*0.1 + coord_hauteur*(cote_grille/taille_grille);
							
							position_W = 
							position_O =
							position_S =
							position_N =
							position_NO =
							position_NW =
							position_SO =
							position_SW =


							if(position_x_orange == position_x_bleu && position_y_orange == position_y_bleu) {
								bouton_notification("Tour d'orange : La case est prise", 45, "orange");
								break;
							}
							if(position_x_orange == ancienne_pos_x_orange && position_y_orange == ancienne_pos_y_orange) {
								bouton_notification("Tour d'orange : Vous devez vous deplacer", 10, "orange");
								break;
							}
							if(_X > coord_largeur*cote_case && _X < (coord_largeur+1)*cote_case) {
								bouton_notification("Tour d'orange : Bougez d'une case maximum", 10, "orange");
								break;
							}
							if(_X > (coord_largeur-1)*cote_case && _X < (coord_largeur)*cote_case) {
								bouton_notification("Tour d'orange : Bougez d'une case maximum", 10, "orange");
								break;
							}


							ChoisirCouleurDessin(lite_white);
							RemplirRectangle(ancienne_pos_x_orange+1,ancienne_pos_y_orange+1,cote_grille/taille_grille-1,cote_grille/taille_grille-1);


							AfficherSprite(num_sprite_orange,position_x_orange, position_y_orange);

							placer_orange = 1;
						}
					}
				}
			}
		}
	}

	bouton_notification("Tour de bleu : Bougez votre tour", 45, "bleu");
	/* Bloquer */


}

void tour_jeux(int taille_grille) {


}

void jeux() {
	int hauteur_fenetre = 600;
	int largeur_fenetre = 800;
	couleur blue = 3093129;
	couleur orange = 16344064;
	couleur grey = 7697781;
	couleur lite_black = 2039583;
	couleur lite_white = 15592941;
	couleur white = 14803425;
	couleur dark_grey = 2697513;

	int enable_IA = 0;
	int taille_grille = 8;

	short int quitter_jeux = 0;

	/*
	FILE* flux;
	printf("%d\n", enable_IA);

	flux = fopen("options", "r");
	fread(&enable_IA, sizeof(int), 1, flux);

	printf("%d\n", enable_IA);
	
	fclose(flux);
	*/


	ChargerImageFond("image/muraille.jpg");
	ChoisirCouleurDessin(orange);
	EcrireTexte(largeur_fenetre*0.45, hauteur_fenetre*0.08, "Blocus !", 2);

	debut_jeux(taille_grille);

	tour_jeux(taille_grille);
	while(quitter_jeux != 1) {

	}
}



