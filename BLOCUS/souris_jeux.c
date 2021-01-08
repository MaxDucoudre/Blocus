#include<stdlib.h>
#include<stdio.h>
#include<graph.h>

void jeux_hover() {

}

/* _X LARGEUR et _Y HAUTEUR */


void jeux_clique(int taille_grille) {
	int hauteur_fenetre = 600;
	int largeur_fenetre = 800;
	int cliquee;
	int i, j;

	float cote_grille = (hauteur_fenetre-(hauteur_fenetre*0.2));

	cliquee = SourisCliquee();
	printf("_X = %d _Y = %d\n", _X, _Y);

	if(cliquee == 1)
		if(_X > largeur_fenetre*0.2 && _X < largeur_fenetre*0.2 + (hauteur_fenetre - (hauteur_fenetre*0.2)) && _Y > hauteur_fenetre*0.1 && _Y < hauteur_fenetre*0.1 + hauteur_fenetre - (hauteur_fenetre*0.2)) {
			printf("Dans la grille\n");
	for(i = 0; i < taille_grille; i++) {
		for(j = 0; j < taille_grille; j++) { 
			if(_X > largeur_fenetre*0.2 + (i*(cote_grille/taille_grille)) && _X < (largeur_fenetre*0.2 + (i*(cote_grille/taille_grille))) + (hauteur_fenetre-(hauteur_fenetre*0.2)) && _Y > hauteur_fenetre*0.1 +(j*(cote_grille/taille_grille)) && _Y < (hauteur_fenetre*0.1 +(j*(cote_grille/taille_grille))) + (hauteur_fenetre-(hauteur_fenetre*0.2)));
				printf("Dans la case %d %d\n", i, j);

				
			
		}

}