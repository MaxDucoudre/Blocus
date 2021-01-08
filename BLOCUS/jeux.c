#include<stdlib.h>
#include<stdio.h>
#include<graph.h>
#include"grille.h"
#include"sourisjeux.h"



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
	int test = 1;

	int num_sprite_bleu, num_sprite_orange;

	dessiner_grille(taille_grille);
	num_sprite_bleu = charger_pion(taille_grille, "bleu");
	printf("%d\n", num_sprite_bleu);
	num_sprite_orange = charger_pion(taille_grille, "orange");
	printf("%d\n", num_sprite_orange);


	while(test == 1) {
		jeux_clique(taille_grille);
	}
	bouton_notification("Le joueur orange doit placer son pion", 30, "orange");

	
	AfficherSprite(num_sprite_orange, hauteur_fenetre/2, largeur_fenetre/2);


	bouton_notification("Le joueur bleu doit placer son pion", 40, "bleu");

	AfficherSprite(num_sprite_bleu, hauteur_fenetre/3, largeur_fenetre/3);


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
	int taille_grille = 6;

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

	/*Dessiner la grille */


	debut_jeux(taille_grille);

	/* entrée dans le jeux */
	while(quitter_jeux != 1) {

	}
}



