#include<stdlib.h>
#include<stdio.h>
#include<graph.h>


	short int menu() {
		short int menu_start = 0;

		while(menu_start != 1) {
			lancer_menu = menu_start();

			if(lancer_menu == 1) {

				while(lancer_menu == 1) {

				/* Lancer la partie */
				lancer_partie = bouton("Lancer la partie", 2);
				if (lancer_partie = 1) {
				}

				/* statistiques */
				statistiques = bouton("Statistiques", 2);
				if (statistiques = 1) {
					stastistiques();
				}

				/* Options */
				bouton("Options", 2);
				options(); /* edite un fichier texte */

				/* Quitter */
				bouton("Quitter", 2);
				if (quitter = 1) {
				CacherFenetre();
				Touche();
				FermerGraphique();
				return EXIT_SUCCESS

			}
		}
	}
}


