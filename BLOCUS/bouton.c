#include<stdlib.h>
#include<stdio.h>
#include<graph.h>



void bouton_options(char *texte, int emplacement) {
	couleur grey = 7697781;
	couleur lite_black = 2039583;
	couleur white = 14803425;
	int hauteur_fenetre = 600;
	int largeur_fenetre = 800;

	ChoisirCouleurDessin(grey);
	RemplirRectangle(largeur_fenetre*0.05, hauteur_fenetre*emplacement/10 - 30, 350, 40);
	ChoisirCouleurDessin(white);
	EcrireTexte(largeur_fenetre*0.05 + 5, hauteur_fenetre*emplacement/10, texte, 2);
	ChoisirCouleurDessin(lite_black);
	DessinerRectangle(largeur_fenetre*0.05, hauteur_fenetre*emplacement/10 - 30, 350, 40);
}

short int bouton_options_clique(int emplacement) {
	int hauteur_fenetre = 600;
	int largeur_fenetre = 800;
	short int cliquee;

	cliquee = SourisCliquee();
	if(cliquee == 1) {
		if(_X > largeur_fenetre*0.05 && _X < largeur_fenetre*0.05 + 350 && _Y > hauteur_fenetre*emplacement/10 - 30 && _Y < hauteur_fenetre*emplacement/10 + 10);
		return 1;
	}
}

void bouton_options_hover(int emplacement) {
	int hauteur_fenetre = 600;
	int largeur_fenetre = 800;
	couleur lite_black = 2039583;
	couleur lite_white = 15592941;

	if(_X > largeur_fenetre*0.05 && _X < largeur_fenetre*0.05 + 350 && _Y > hauteur_fenetre*emplacement/10 - 30 && _Y < hauteur_fenetre*emplacement/10 + 10) {
		ChoisirCouleurDessin(lite_white);
		DessinerRectangle(largeur_fenetre*0.05, hauteur_fenetre*emplacement/10 - 30, 350, 40);
	} else {
		ChoisirCouleurDessin(lite_black);
		DessinerRectangle(largeur_fenetre*0.05, hauteur_fenetre*emplacement/10 - 30, 350, 40);
	}


}




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



	if(_X > largeur_fenetre*0.05 && _X < largeur_fenetre*0.05 + 235 && _Y > hauteur_fenetre*emplacement/10 - 30 && _Y < hauteur_fenetre*emplacement/10 + 10) {
		ChoisirCouleurDessin(lite_white);
		DessinerRectangle(largeur_fenetre*0.05, hauteur_fenetre*emplacement/10 - 30, 235, 40);
	} else {
		ChoisirCouleurDessin(lite_black);
		DessinerRectangle(largeur_fenetre*0.05, hauteur_fenetre*emplacement/10 - 30, 235, 40);
	}		
}