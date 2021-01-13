		#include<stdlib.h>
		#include<stdio.h>
		#include<graph.h>
		#include"grille.h"
		#include"souris_jeux.h"
		#include"verification.h"
		#include<unistd.h>



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
	RemplirRectangle(largeur_fenetre*0.20, hauteur_fenetre*0.92, 480, 40);

	ChoisirCouleurDessin(lite_black);
	DessinerRectangle(largeur_fenetre*0.20, hauteur_fenetre*0.92, 480, 40);

	if(color == "bleu") {
		ChoisirCouleurDessin(blue);
	} else if (color == "orange") {
		ChoisirCouleurDessin(orange);
	} else if (color == "rouge") {
		ChoisirCouleurDessin(red);
	}

	EcrireTexte(largeur_fenetre*0.25 + decalage, hauteur_fenetre*0.965, texte, 1);

}



void ecran_fin(char gagnant) {
	int hauteur_fenetre = 600;
	int largeur_fenetre = 800;
	couleur grey = 7697781;
	couleur lite_black = 2039583;
	couleur white = 14803425;
	couleur blue = 3093129;
	couleur orange = 16344064;
	int num_v_o,num_d_b;
	int num_v_b,num_d_o;

	short int quitter_ecran_fin;

	ChoisirCouleurDessin(grey);
	RemplirRectangle(largeur_fenetre*0.15, hauteur_fenetre*0.03, 560, 42);
	ChoisirCouleurDessin(lite_black);
	DessinerRectangle(largeur_fenetre*0.15-1, hauteur_fenetre*0.03-1, 560+1, 42+1);
	DessinerRectangle(largeur_fenetre*0.15-2, hauteur_fenetre*0.03-2, 560+3, 42+3);


			/*
			ChoisirCouleurDessin(grey);
			RemplirRectangle(largeur_fenetre*0.25, hauteur_fenetre*0.15, 400, 420);
			ChoisirCouleurDessin(lite_black);
			DessinerRectangle(largeur_fenetre*0.25, hauteur_fenetre*0.15, 400, 420);
			DessinerRectangle(largeur_fenetre*0.25+1, hauteur_fenetre*0.15+1, 400-2, 420-2);
			DessinerRectangle(largeur_fenetre*0.25+2, hauteur_fenetre*0.15+2, 400-4, 420-4);
			DessinerRectangle(largeur_fenetre*0.25+3, hauteur_fenetre*0.15	+3, 400-6, 420-6);
			*/

	if(gagnant == 'o') {
		ChoisirCouleurDessin(orange);
		EcrireTexte(largeur_fenetre*0.15+24, hauteur_fenetre*0.08, "La victoire est au Royaume Orange !", 2);

		num_v_o = ChargerSprite("image/victoire_orange.png");
		AfficherSprite(num_v_o, 250, 110);

		num_d_b = ChargerSprite("image/defaite_bleu.png");
		AfficherSprite(num_d_b, 500, 380);	

		LibererSprite(num_d_b);
		LibererSprite(num_v_o);


	} else if(gagnant == 'b') {
		ChoisirCouleurDessin(blue);
		EcrireTexte(largeur_fenetre*0.15+27, hauteur_fenetre*0.08, "La victoire est au Royaume Bleu !", 2);

		num_v_b = ChargerSprite("image/victoire_bleu.png");
		AfficherSprite(num_v_b, 250, 110);

		num_d_o = ChargerSprite("image/defaite_orange.png");
		AfficherSprite(num_d_o, 500, 380);	

		LibererSprite(num_d_o);
		LibererSprite(num_v_b);
	}

	bouton_notification("Quitter la partie", 130, "rouge");
	do {
		SourisPosition();
		if(_X > largeur_fenetre*0.20 && _X < largeur_fenetre*0.20 + 480 && _Y > hauteur_fenetre*0.92 && _Y < hauteur_fenetre*92 + 40) {
			ChoisirCouleurDessin(white);
			DessinerRectangle(largeur_fenetre*0.20, hauteur_fenetre*0.92, 480, 40);
		} else {
			ChoisirCouleurDessin(lite_black);
			DessinerRectangle(largeur_fenetre*0.20, hauteur_fenetre*0.92, 480, 40);

		}
	} while(quitter_ecran_fin != 1);

}




char debut_jeux(int taille_grille) {
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

	int ancienne_coord_largeur_orange, ancienne_coord_hauteur_orange;
	int ancienne_coord_largeur_bleu, ancienne_coord_hauteur_bleu;
	int coord_largeur_orange, coord_hauteur_orange;
	int coord_largeur_bleu, coord_hauteur_bleu;

	int placer_orange = 0;
	int placer_bleu = 0;
	int i, j;

	int orange_defaite = 0;
	int bleu_defaite = 0;
	int gagnant = 0;

	couleur orange = 16344064;
	couleur bleu = 4147404;

	short int fin_partie = 0;

	int num_sprite_bleu, num_sprite_orange;
	couleur lite_white = 15592941;

	int placer_mur_orange, placer_mur_bleu;
	int position_x_orange_mur, position_x_bleu_mur;
	int position_y_orange_mur, position_y_bleu_mur;
	int case_prise[taille_grille][taille_grille];
	int reset_tab;
	int a,b;

	printf("%d", taille_grille);

	dessiner_grille(taille_grille);
	num_sprite_bleu = charger_pion(taille_grille, "bleu");
	printf("%d\n", num_sprite_bleu);
	num_sprite_orange = charger_pion(taille_grille, "orange");
	printf("%d\n", num_sprite_orange);





	for(i = 0; i < taille_grille; i++) {
		printf("\n");
		for(j = 0; j < taille_grille; j++) {
			case_prise[j][i] = 0;
			printf("%d ", case_prise[j][i]);

		}
	}


	fflush(0);


	bouton_notification("Tour d'orange : Placer votre pion", 5, "orange");
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

							case_prise[coord_largeur][coord_hauteur] = 1;

							coord_largeur_orange = coord_largeur;
							coord_hauteur_orange = coord_hauteur;

							placer_orange = 1;

						}
					}
				}
			}
		}
	}


	bouton_notification("Tour de bleu : placer votre pion", 5, "bleu");

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
								bouton_notification("Tour de bleu : la case est prise", 20, "bleu");
								break;
							}

							case_prise[coord_largeur][coord_hauteur] = 1;

							AfficherSprite(num_sprite_bleu,position_x_bleu, position_y_bleu);
							coord_largeur_bleu = coord_largeur;
							coord_hauteur_bleu = coord_hauteur;

							placer_bleu = 1;
						}
					}
				}
			}
		}
	}



	fin_partie = 0;
	while(fin_partie == 0) {


			/* Deplacement */
		bouton_notification("Tour d'orange : Bougez votre tour", 5, "orange");
		placer_orange = 0;
		i = 0;
		while(placer_orange == 0) {

			cliquee = SourisCliquee();
			if(cliquee == 1) {
				if(_X > largeur_fenetre*0.2 && _X < largeur_fenetre*0.2 + (hauteur_fenetre - (hauteur_fenetre*0.2)) && _Y > hauteur_fenetre*0.1 && _Y < hauteur_fenetre*0.1 + hauteur_fenetre - (hauteur_fenetre*0.2)) {

					for(coord_hauteur = 0; coord_hauteur<taille_grille; coord_hauteur++) {
						for(coord_largeur = 0; coord_largeur<taille_grille; coord_largeur++) {

							if(_X > largeur_fenetre*0.2 + coord_largeur*(cote_grille/taille_grille) && _X < largeur_fenetre*0.2 + (coord_largeur+1)*(cote_grille/taille_grille) && _Y > hauteur_fenetre*0.1 + coord_hauteur*(cote_grille/taille_grille) && _Y < hauteur_fenetre*0.1 + (coord_hauteur+1)*(cote_grille/taille_grille)) {


								if(i == 0) {
									ancienne_pos_x_orange = position_x_orange;
									ancienne_pos_y_orange = position_y_orange;
									ancienne_coord_largeur_orange = coord_largeur;
									ancienne_coord_hauteur_orange = coord_hauteur;
								}

								i = 1;
								position_x_orange = largeur_fenetre*0.2 + coord_largeur*(cote_grille/taille_grille);
								position_y_orange = hauteur_fenetre*0.1 + coord_hauteur*(cote_grille/taille_grille);



								if(position_x_orange == position_x_bleu && position_y_orange == position_y_bleu) {
									bouton_notification("Tour d'orange : La case est prise", 5, "orange");
									break;
								}
								if(position_x_orange == ancienne_pos_x_orange && position_y_orange == ancienne_pos_y_orange) {
									bouton_notification("Tour d'orange : Vous devez vous deplacer", 5, "orange");
									break;
								}
								if(case_prise[coord_largeur][coord_hauteur] == 1) {
									bouton_notification("Tour d'orange : Deplacez-vous en dehors d'un mur", 5, "orange");
									break;									
								}


								printf("coord_largeur_orange :%d\n coord_largeur_orange %d\n\n", coord_largeur_orange, coord_hauteur_orange);

								printf("coord_largeur :%d\n coord_hauteur :%d\n", coord_largeur, coord_hauteur);




								if(coord_largeur_orange == coord_largeur-1 && coord_hauteur_orange == coord_hauteur+1 || coord_largeur_orange == coord_largeur && coord_hauteur_orange == coord_hauteur-1 || coord_largeur_orange == coord_largeur && coord_hauteur_orange == coord_hauteur+1 || coord_largeur_orange == coord_largeur-1 && coord_hauteur_orange == coord_hauteur-1 || coord_largeur_orange == coord_largeur+1 && coord_hauteur_orange == coord_hauteur || coord_largeur_orange == coord_largeur+1 && coord_hauteur_orange == coord_hauteur+1 || coord_largeur_orange == coord_largeur+1 && coord_hauteur_orange == coord_hauteur-1 || coord_largeur_orange == coord_largeur-1 && coord_hauteur_orange == coord_hauteur || coord_largeur_orange == coord_largeur-1 && coord_hauteur_orange == coord_hauteur-1) {
									ChoisirCouleurDessin(lite_white);
									RemplirRectangle(ancienne_pos_x_orange+1,ancienne_pos_y_orange+1,cote_grille/taille_grille-1,cote_grille/taille_grille-1);
									AfficherSprite(num_sprite_orange,position_x_orange, position_y_orange);
									placer_orange = 1;
									case_prise[coord_largeur_orange][coord_hauteur_orange] = 0;
									coord_largeur_orange = coord_largeur;
									coord_hauteur_orange = coord_hauteur;
									case_prise[coord_largeur_orange][coord_hauteur_orange] = 1;
									break;
								}


								bouton_notification("Tour d'Orange : Bougez d'une case maximum", 5, "orange");
								break;


							}
						}
						if(placer_orange == 1) {
							break;
						}
					}
				}
			}
		}




		gagnant = verification_victoire(taille_grille, case_prise, coord_largeur_orange, coord_hauteur_orange, num_sprite_orange, num_sprite_bleu);
		if (gagnant == 1) {
			return 'b';
		}

		gagnant = verification_victoire(taille_grille, case_prise, coord_largeur_bleu, coord_hauteur_bleu, num_sprite_orange, num_sprite_bleu);
		if (gagnant == 1) {
			return 'o';
		}


		bouton_notification("Tour de Orange : Placer un mur", 5, "orange");
		placer_mur_orange = 0;
		i = 0;
		while(placer_mur_orange == 0) {	

			cliquee = SourisCliquee();
			if(cliquee == 1) {
				if(_X > largeur_fenetre*0.2 && _X < largeur_fenetre*0.2 + (hauteur_fenetre - (hauteur_fenetre*0.2)) && _Y > hauteur_fenetre*0.1 && _Y < hauteur_fenetre*0.1 + hauteur_fenetre - (hauteur_fenetre*0.2)) {
					for(coord_hauteur = 0; coord_hauteur<taille_grille; coord_hauteur++) {

						for(coord_largeur = 0; coord_largeur<taille_grille; coord_largeur++) {

							if(_X > largeur_fenetre*0.2 + coord_largeur*(cote_grille/taille_grille) && _X < largeur_fenetre*0.2 + (coord_largeur+1)*(cote_grille/taille_grille) && _Y > hauteur_fenetre*0.1 + coord_hauteur*(cote_grille/taille_grille) && _Y < hauteur_fenetre*0.1 + (coord_hauteur+1)*(cote_grille/taille_grille)) {


								position_x_orange_mur = largeur_fenetre*0.2 + coord_largeur*(cote_grille/taille_grille);
								position_y_orange_mur = hauteur_fenetre*0.1 + coord_hauteur*(cote_grille/taille_grille);

								if(position_x_orange_mur == position_x_orange && position_y_orange_mur == position_y_orange) {
									bouton_notification("Tour de orange : choisissez une case sans tour", 5, "orange");
									puts("Choisissez une autre case");
									break;
								}

								if(position_x_orange_mur == position_x_bleu && position_y_orange_mur == position_y_bleu) {
									bouton_notification("Tour de orange : choisissez une case sans tour", 5, "orange");
									break;
								}

								if(case_prise[coord_largeur][coord_hauteur] == 1) {
									bouton_notification("Tour de orange : Choisissez une case sans mur", 5, "orange");
									puts("Choisissez une autre case");
									break;
								}

								ChoisirCouleurDessin(orange);
								RemplirRectangle(position_x_orange_mur+1,position_y_orange_mur+1,cote_grille/taille_grille-1,cote_grille/taille_grille-1);
								placer_mur_orange = 1;
								case_prise[coord_largeur][coord_hauteur] = 1;	


								for(i = 0; i < taille_grille; i++) {
									printf("\n");
									for(j = 0; j < taille_grille; j++) {
										printf("%d ", case_prise[j][i]);

									}
								}

							}
						}
					}
					if(placer_mur_orange == 1 ) {
						break;
					}
				}
			}
		}


			/*Verif defaite  orange */
		
		gagnant = verification_victoire(taille_grille, case_prise, coord_largeur_orange, coord_hauteur_orange, num_sprite_orange, num_sprite_bleu);
		if (gagnant == 1) {
			return 'b';
		}

		gagnant = verification_victoire(taille_grille, case_prise, coord_largeur_bleu, coord_hauteur_bleu, num_sprite_orange, num_sprite_bleu);
		if (gagnant == 1) {
			return 'o';
		}



		bouton_notification("Tour de bleu : Bougez votre tour", 5, "bleu");
		placer_bleu = 0;
		i = 0;

		while(placer_bleu == 0) {

			cliquee = SourisCliquee();
			if(cliquee == 1) {
				if(_X > largeur_fenetre*0.2 && _X < largeur_fenetre*0.2 + (hauteur_fenetre - (hauteur_fenetre*0.2)) && _Y > hauteur_fenetre*0.1 && _Y < hauteur_fenetre*0.1 + hauteur_fenetre - (hauteur_fenetre*0.2)) {

					for(coord_hauteur = 0; coord_hauteur<taille_grille; coord_hauteur++) {

						for(coord_largeur = 0; coord_largeur<taille_grille; coord_largeur++) {

							if(_X > largeur_fenetre*0.2 + coord_largeur*(cote_grille/taille_grille) && _X < largeur_fenetre*0.2 + (coord_largeur+1)*(cote_grille/taille_grille) && _Y > hauteur_fenetre*0.1 + coord_hauteur*(cote_grille/taille_grille) && _Y < hauteur_fenetre*0.1 + (coord_hauteur+1)*(cote_grille/taille_grille)) {


								if(i == 0) {
									ancienne_pos_x_bleu = position_x_bleu;
									ancienne_pos_y_bleu = position_y_bleu;
									ancienne_coord_hauteur_bleu = coord_hauteur; 
									ancienne_coord_largeur_bleu = coord_largeur;
								}

								i = 1;
								position_x_bleu = largeur_fenetre*0.2 + coord_largeur*(cote_grille/taille_grille);
								position_y_bleu = hauteur_fenetre*0.1 + coord_hauteur*(cote_grille/taille_grille);



								if(position_x_bleu == position_x_orange && position_y_bleu == position_y_orange) {
									bouton_notification("Tour de bleu : La case est prise", 5, "bleu");
									break;
								}
								if(position_x_bleu == ancienne_pos_x_bleu && position_y_bleu == ancienne_pos_y_bleu) {
									bouton_notification("Tour de bleu : Vous devez vous deplacer", 5, "bleu");
									break;
								}

								if(case_prise[coord_largeur][coord_hauteur] == 1) {
									bouton_notification("Tour de bleu : Choisissez une case sans mur", 5, "bleu");
									break;									
								}


								printf("coord_largeur :%d\n coord_hauteur :%d\n", coord_largeur, coord_hauteur);

								printf("coord_largeur_bleu :%d\n coord_largeur_bleu %d\n\n", coord_largeur_bleu, coord_hauteur_bleu);

										/* */
								if(coord_largeur_bleu == coord_largeur-1 && coord_hauteur_bleu == coord_hauteur+1 || coord_largeur_bleu == coord_largeur && coord_hauteur_bleu == coord_hauteur-1 || coord_largeur_bleu == coord_largeur && coord_hauteur_bleu == coord_hauteur+1 || coord_largeur_bleu == coord_largeur-1 && coord_hauteur_bleu == coord_hauteur-1 || coord_largeur_bleu == coord_largeur+1 && coord_hauteur_bleu == coord_hauteur || coord_largeur_bleu == coord_largeur+1 && coord_hauteur_bleu == coord_hauteur+1 || coord_largeur_bleu == coord_largeur+1 && coord_hauteur_bleu == coord_hauteur-1 || coord_largeur_bleu == coord_largeur-1 && coord_hauteur_bleu == coord_hauteur || coord_largeur_bleu == coord_largeur-1 && coord_hauteur_bleu == coord_hauteur-1) {
									ChoisirCouleurDessin(lite_white);
									RemplirRectangle(ancienne_pos_x_bleu+1,ancienne_pos_y_bleu+1,cote_grille/taille_grille-1,cote_grille/taille_grille-1);
									AfficherSprite(num_sprite_bleu,position_x_bleu, position_y_bleu);
									placer_bleu = 1;
									case_prise[coord_largeur_bleu][coord_hauteur_bleu] = 0;
									coord_largeur_bleu = coord_largeur;
									coord_hauteur_bleu = coord_hauteur;
									case_prise[coord_largeur_bleu][coord_hauteur_bleu] = 1;
									break;
								}


								bouton_notification("Tour de bleu : Bougez d'une case maximum", 5, "bleu");



							}
						}

						if(placer_bleu == 1 ) {
							break;
						}
					}
				}
			}
		}


			/*Verif defaite  orange */

		gagnant = verification_victoire(taille_grille, case_prise, coord_largeur_orange, coord_hauteur_orange, num_sprite_orange, num_sprite_bleu);
		if (gagnant == 1) {
			return 'b';
		}

		gagnant = verification_victoire(taille_grille, case_prise, coord_largeur_bleu, coord_hauteur_bleu, num_sprite_orange, num_sprite_bleu);
		if (gagnant == 1) {
			return 'o';
		}




		bouton_notification("Tour de bleu : placer un mur", 5, "bleu");
		placer_mur_bleu = 0;
		i = 0;
		while(placer_mur_bleu == 0) {	

			cliquee = SourisCliquee();
			if(cliquee == 1) {
				if(_X > largeur_fenetre*0.2 && _X < largeur_fenetre*0.2 + (hauteur_fenetre - (hauteur_fenetre*0.2)) && _Y > hauteur_fenetre*0.1 && _Y < hauteur_fenetre*0.1 + hauteur_fenetre - (hauteur_fenetre*0.2)) {
					for(coord_hauteur = 0; coord_hauteur<taille_grille; coord_hauteur++) {

						for(coord_largeur = 0; coord_largeur<taille_grille; coord_largeur++) {
							if(_X > largeur_fenetre*0.2 + coord_largeur*(cote_grille/taille_grille) && _X < largeur_fenetre*0.2 + (coord_largeur+1)*(cote_grille/taille_grille) && _Y > hauteur_fenetre*0.1 + coord_hauteur*(cote_grille/taille_grille) && _Y < hauteur_fenetre*0.1 + (coord_hauteur+1)*(cote_grille/taille_grille)) {


								position_x_bleu_mur = largeur_fenetre*0.2 + coord_largeur*(cote_grille/taille_grille);
								position_y_bleu_mur = hauteur_fenetre*0.1 + coord_hauteur*(cote_grille/taille_grille);


								if(position_x_bleu_mur == position_x_orange && position_y_bleu_mur == position_y_orange) {
									bouton_notification("Tour de orange : choisissez une case sans tour", 5, "bleu");
									puts("Choisissez une autre case");
									break;
								}

								if(position_x_bleu_mur == position_x_bleu && position_y_bleu_mur == position_y_bleu) {
									bouton_notification("Tour de orange : choisissez une case sans tour", 5, "bleu");
									break;
								}

								if(case_prise[coord_largeur][coord_hauteur] == 1) {
									bouton_notification("Tour de orange : choisissez une autre case", 5, "bleu");
									puts("Choisissez une autre case");
									break;
								}

								ChoisirCouleurDessin(bleu);
								RemplirRectangle(position_x_bleu_mur+1,position_y_bleu_mur+1,cote_grille/taille_grille-1,cote_grille/taille_grille-1);
								placer_mur_bleu = 1;
								case_prise[coord_largeur][coord_hauteur] = 1;	

								for(i = 0; i < taille_grille; i++) {
									printf("\n");
									for(j = 0; j < taille_grille; j++) {
										printf("%d ", case_prise[j][i]);



									}
								}
							}
						}

					}
					if(placer_mur_bleu == 1 ) {
						break;
					}
				}
			}
		}

	}

	/*Verif defaite  orange */

		gagnant = verification_victoire(taille_grille, case_prise, coord_largeur_orange, coord_hauteur_orange, num_sprite_orange, num_sprite_bleu);
		if (gagnant == 1) {
			return 'b';
		}

		gagnant = verification_victoire(taille_grille, case_prise, coord_largeur_bleu, coord_hauteur_bleu, num_sprite_orange, num_sprite_bleu);
		if (gagnant == 1) {
			return 'o';
		}



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

	char gagnant;

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


	gagnant = debut_jeux(taille_grille);
	ecran_fin(gagnant);



	tour_jeux(taille_grille);
	while(quitter_jeux != 1) {

	}
}



