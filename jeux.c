#include<stdlib.h>
#include<stdio.h>
#include<graph.h>

void jeux() {

	/* options */
	int taille_grille;
	int nombre_joueur;

	while (fin_jeux != 1) {

		menu_principal();

		while(lancer_partie = 1) {

			/* regarder les options  */


			grille(taille_grille); /* dessine la grille en fonction de sa taille entre 3 et 9 */

			debut_jeux(); /* Phase les deux pions */

			while(fin_partie != 1) {
				tours(numero_joueur); /* tour des joueurs 1 ou 2 ou Ia */

				if(numero_joueur == 1) {
					numero_joueur = 2;
				} else {
					numero_joueur = 1;
				}

				fin_partie = fin_partie();
			}
			if (fin_partie = 1) {
				ecran_de_fin();
			}
		}
	}
}
