		#include<stdlib.h>
		#include<stdio.h>
		#include<graph.h>
		#include"grille.h"
		#include"verification.h"
		#include"jeux.h"
		#include<time.h>

int charger_pion_ia(int taille_grille, char *couleur_pion) {
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
		printf("%s chargé\n", sprite_bleu);
		sprite_num = ChargerSprite(sprite_bleu);
		return sprite_num;


	} else if (couleur_pion == "orange") {

		caractere_taille_grille = '3';

		for(i = 3; i < taille_grille; i++) {
			caractere_taille_grille	= caractere_taille_grille + 1;
		}

		sprite_orange[13] = caractere_taille_grille;
		printf("%s chargé\n", sprite_orange);
		sprite_num = ChargerSprite(sprite_orange);

		return sprite_num;

	} else {

		puts("Pion non chargé");
		return EXIT_FAILURE;
	}
}

int ia_jeux(int taille_grille) {
	int hauteur_fenetre = 600;
	int largeur_fenetre = 800;

	couleur lite_white = 15592941;

	int num_sprite_bleu, num_sprite_orange;

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

	short int fin_partie = 0;

	int placer_mur_orange, placer_mur_bleu;
	int position_x_orange_mur, position_x_bleu_mur;
	int position_y_orange_mur, position_y_bleu_mur;
	int case_prise[taille_grille][taille_grille];

	float cote_grille = (hauteur_fenetre-(hauteur_fenetre*0.2));
	float cote_case = cote_grille/taille_grille;

	srand(time(NULL));

	printf("Taille grille : %dx%d\n", taille_grille, taille_grille);
	puts("IA activée\n");
	dessiner_grille(taille_grille);
	num_sprite_bleu = charger_pion_ia(taille_grille, "bleu");
	printf("%d\n", num_sprite_bleu);
	num_sprite_orange = charger_pion_ia(taille_grille, "orange");
	printf("%d\n", num_sprite_orange);


	for(i = 0; i < taille_grille; i++) {
		printf("\n");
		for(j = 0; j < taille_grille; j++) {
			case_prise[j][i] = 0;
			printf("%d ", case_prise[j][i]);
		}
	}
	printf("\n");




	bouton_notification("Placez votre pion", 5, "orange");
	while(placer_orange == 0) {
		cliquee = SourisCliquee();
		if(cliquee == 1) {
			if(_X > largeur_fenetre*0.2 && _X < largeur_fenetre*0.2 + (hauteur_fenetre - (hauteur_fenetre*0.2)) && _Y > hauteur_fenetre*0.1 && _Y < hauteur_fenetre*0.1 + hauteur_fenetre - (hauteur_fenetre*0.2)) {

				for(coord_hauteur = 0; coord_hauteur<taille_grille; coord_hauteur++) {
					for(coord_largeur = 0; coord_largeur<taille_grille; coord_largeur++) {
						if(_X > largeur_fenetre*0.2 + coord_largeur*(cote_grille/taille_grille) && _X < largeur_fenetre*0.2 + (coord_largeur+1)*(cote_grille/taille_grille) && _Y > hauteur_fenetre*0.1 + coord_hauteur*(cote_grille/taille_grille) && _Y < hauteur_fenetre*0.1 + (coord_hauteur+1)*(cote_grille/taille_grille)) {
							position_x_orange = largeur_fenetre*0.2 + coord_largeur*(cote_grille/taille_grille);
							position_y_orange = hauteur_fenetre*0.1 + coord_hauteur*(cote_grille/taille_grille);

							AfficherSprite(num_sprite_orange, position_x_orange, position_y_orange);

							case_prise[coord_largeur][coord_hauteur] = 1;

							coord_largeur_orange = coord_largeur;
							coord_hauteur_orange = coord_hauteur;

							placer_orange = 1;

							printf("Pion Joueur placé : %d %d\n", coord_largeur+1, coord_hauteur+1);

						}
					}
				}
			}
		}
	}

	bouton_notification("Tour de l'IA...", 20, "bleu");


	while(placer_bleu == 0) {
		while(1) {

			coord_largeur_bleu = (rand() % (taille_grille-1 - 0 + 1)) + 0;
			coord_hauteur_bleu = (rand() % (taille_grille-1 - 0 + 1)) + 0;


			position_x_bleu = largeur_fenetre*0.2 + coord_largeur_bleu*(cote_grille/taille_grille);
			position_y_bleu = hauteur_fenetre*0.1 + coord_hauteur_bleu*(cote_grille/taille_grille);

			if(coord_largeur_bleu == coord_largeur_orange && coord_hauteur_bleu == coord_hauteur_orange) {
				break;
			}

			case_prise[coord_largeur][coord_hauteur] = 1;

			AfficherSprite(num_sprite_bleu,position_x_bleu, position_y_bleu);

			placer_bleu = 1;
			printf("Pion IA placé : %d %d\n", coord_largeur, coord_hauteur_bleu);
			break;
		}
	}


	fin_partie = 0;
	while(fin_partie == 0) {


		bouton_notification("Deplacez votre pion", 5, "orange");
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
									bouton_notification("Deplacez-vous : La case est prise", 5, "orange");
									break;
								}
								if(position_x_orange == ancienne_pos_x_orange && position_y_orange == ancienne_pos_y_orange) {
									bouton_notification("Deplacez-vous : Vous etes deja sur cette case", 5, "orange");
									break;
								}
								if(case_prise[coord_largeur][coord_hauteur] == 1) {
									bouton_notification("Deplacez-vous : un mur vous bloque", 5, "orange");
									break;									
								}
								printf("Position orange : %d %d\n", coord_largeur_orange, coord_hauteur_orange);
								printf("Position clique : %d %d\n\n", coord_largeur, coord_hauteur);
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
								bouton_notification("Deplacez-vous d'une case maximum", 5, "orange");
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



		bouton_notification("Tour de l'IA...", 20, "bleu");
		placer_bleu = 0;
		i = 0;
		while(placer_bleu == 0) {
			while(1) {

				if(i == 0) {
					ancienne_pos_x_bleu = position_x_bleu;
					ancienne_pos_y_bleu = position_y_bleu;
					ancienne_coord_largeur_bleu = coord_largeur_bleu;
					ancienne_coord_hauteur_bleu = coord_hauteur_bleu; 
				}
				i = 1;
				coord_largeur_bleu = (rand() % (taille_grille+1 - 0 + 1)) + 0;
				coord_hauteur_bleu = (rand() % (taille_grille+1 - 0 + 1)) + 0;

				if (coord_largeur_bleu >= taille_grille || coord_largeur_bleu < 0 || coord_hauteur_bleu >= taille_grille || coord_hauteur < 0) {
					puts("L'IA tente de se déplacer hors des limites de la grille");
					break;
				}

				position_x_bleu = largeur_fenetre*0.2 + coord_largeur_bleu*(cote_grille/taille_grille);
				position_y_bleu = hauteur_fenetre*0.1 + coord_hauteur_bleu*(cote_grille/taille_grille);

				if(coord_largeur_bleu == coord_largeur_orange && coord_hauteur_bleu == coord_hauteur_orange) {
					puts("L'IA tente de se déplacer sur le joueur");
					break;
				}

				if(coord_largeur_bleu == ancienne_coord_largeur_bleu && coord_hauteur_bleu == ancienne_coord_hauteur_bleu) {
					puts("L'IA tente de se déplacer sur elle-même");					

					break;
				}

				if(case_prise[coord_largeur_bleu][coord_hauteur_bleu] == 1) {
					break;	
					puts("L'IA tente de se déplacer sur un mur");							
				}

				if(ancienne_coord_hauteur_bleu == coord_largeur_bleu-1 && ancienne_coord_hauteur_bleu == coord_hauteur_bleu+1 || ancienne_coord_largeur_bleu == coord_largeur_bleu && ancienne_coord_hauteur_bleu == coord_hauteur_bleu-1 || ancienne_coord_largeur_bleu == coord_largeur_bleu && ancienne_coord_hauteur_bleu == coord_hauteur_bleu+1 || ancienne_coord_largeur_bleu == coord_largeur_bleu-1 && ancienne_coord_hauteur_bleu == coord_hauteur_bleu-1 || ancienne_coord_largeur_bleu == coord_largeur_bleu+1 && ancienne_coord_hauteur_bleu == coord_hauteur_bleu || ancienne_coord_largeur_bleu == coord_largeur_bleu+1 && ancienne_coord_hauteur_bleu == coord_hauteur_bleu+1 || ancienne_coord_largeur_bleu == coord_largeur_bleu+1 && ancienne_coord_hauteur_bleu == coord_hauteur_bleu-1 || ancienne_coord_largeur_bleu == coord_largeur_bleu-1 && ancienne_coord_hauteur_bleu == coord_hauteur_bleu || ancienne_coord_largeur_bleu == coord_largeur_bleu-1 && ancienne_coord_hauteur_bleu == coord_hauteur_bleu-1) {
					ChoisirCouleurDessin(lite_white);
					RemplirRectangle(ancienne_pos_x_bleu+1,ancienne_pos_y_bleu+1,cote_grille/taille_grille-1,cote_grille/taille_grille-1);
					AfficherSprite(num_sprite_bleu,position_x_bleu, position_y_bleu);
					case_prise[ancienne_coord_largeur_bleu][ancienne_coord_hauteur_bleu] = 0;
					case_prise[coord_largeur_bleu][coord_hauteur_bleu] = 1;
					placer_bleu = 1;

					printf("Ancienne position IA : %d %d\n", coord_largeur_orange, coord_hauteur_orange);
					printf("         Position IA : %d %d\n\n", coord_largeur, coord_hauteur);
					break;
				}
				bouton_notification("L'IA réfléchit...", 20, "bleu");
			}
		}


	}






	while(1) {	}
}