#include<stdlib.h>
#include<stdio.h>
#include<graph.h>




char verification_victoire(int taille_grille, int case_prise[taille_grille][taille_grille], int coord_largeur_orange, int coord_hauteur_orange, int coord_largeur_bleu, int coord_hauteur_bleu, int num_sprite_orange, int num_sprite_bleu) {

	if(case_prise[coord_largeur_orange+1][coord_hauteur_orange-1] == 1 && case_prise[coord_largeur_orange-1][coord_hauteur_orange] == 1 && case_prise[coord_largeur_orange-1][coord_hauteur_orange+1] == 1 && case_prise[coord_largeur_orange+1][coord_hauteur_orange-1] == 1 && case_prise[coord_largeur_orange][coord_hauteur_orange+1] == 1 && case_prise[coord_largeur_orange+1][coord_hauteur_orange-1] == 1 && case_prise[coord_largeur_orange+1][coord_hauteur_orange] == 1 && case_prise[coord_largeur_orange+1][coord_hauteur_orange+1] == 1) {
		LibererSprite(num_sprite_orange);
		LibererSprite(num_sprite_bleu);
		return 'b';
	} else {
		return 'n';
	}


	if(case_prise[coord_largeur_bleu+1][coord_hauteur_bleu-1] == 1 && case_prise[coord_largeur_bleu-1][coord_hauteur_bleu] == 1 && case_prise[coord_largeur_bleu-1][coord_hauteur_bleu+1] == 1 && case_prise[coord_largeur_bleu+1][coord_hauteur_bleu-1] == 1 && case_prise[coord_largeur_bleu][coord_hauteur_bleu+1] == 1 && case_prise[coord_largeur_bleu+1][coord_hauteur_bleu-1] == 1 && case_prise[coord_largeur_bleu+1][coord_hauteur_bleu] == 1 && case_prise[coord_largeur_bleu+1][coord_hauteur_bleu+1] == 1) {
		LibererSprite(num_sprite_orange);
		LibererSprite(num_sprite_bleu);
		return 'o';
	} else {
		return 'n';
	}

}




// /*

// char verification(int num_sprite_orange, int num_sprite_bleu, int coord_largeur_orange, int coord_hauteur_orange, int coord_hauteur_bleu, int coord_largeur_bleu, int taille_grille) {

// 	int case_prise[taille_grille][taille_grille];
// 		/* Haut gauche coin defaite */
// 	if(coord_largeur_bleu == 0 && coord_hauteur_bleu == 0) {
// 		if(case_prise[coord_largeur_bleu+1][coord_hauteur_bleu] == 1) {
// 			if(case_prise[coord_largeur_bleu+1][coord_hauteur_bleu+1] == 1) {
// 				if(case_prise[coord_largeur_bleu][coord_hauteur_bleu+1] == 1) {
// 					LibererSprite(num_sprite_orange);
// 					LibererSprite(num_sprite_bleu);
// 					return 'o';
// 				}
// 			}
// 		}
// 	}

// 		/* Haut droit coin defaite */

// 	if(coord_largeur_bleu == taille_grille-1 && coord_hauteur_bleu == taille_grille-1) {
// 		if(case_prise[coord_largeur_bleu-1][coord_hauteur_bleu] == 1) {
// 			if(case_prise[coord_largeur_bleu-1][coord_hauteur_bleu-1] == 1) {
// 				if(case_prise[coord_largeur_bleu][coord_hauteur_bleu-1] == 1) {
// 					LibererSprite(num_sprite_orange);
// 					LibererSprite(num_sprite_bleu);
// 					return 'o';
// 				}
// 			}
// 		}
// 	}

// 		/* coin bas gauche */

// 	if(coord_largeur_bleu == 0 && coord_hauteur_bleu == taille_grille-1) {
// 		if(case_prise[coord_largeur_bleu-1][coord_hauteur_bleu] == 1) {
// 			if(case_prise[coord_largeur_bleu-1][coord_hauteur_bleu-1] == 1) {
// 				if(case_prise[coord_largeur_bleu][coord_hauteur_bleu-1] == 1) {
// 					LibererSprite(num_sprite_orange);
// 					LibererSprite(num_sprite_bleu);
// 					return 'o';
// 				}
// 			}
// 		}
// 	}


// 		/* coin bas droite */

// 	if(coord_largeur_bleu == taille_grille-1 && coord_hauteur_bleu == 0) {
// 		if(case_prise[coord_largeur_bleu-1][coord_hauteur_bleu] == 1) {
// 			if(case_prise[coord_largeur_bleu-1][coord_hauteur_bleu-1] == 1) {
// 				if(case_prise[coord_largeur_bleu][coord_hauteur_bleu-1] == 1) {
// 					LibererSprite(num_sprite_orange);
// 					LibererSprite(num_sprite_bleu);
// 					return 'o';
// 				}
// 			}
// 		}
// 	}


// 		/* Haut defaite */

// 	if(coord_hauteur_bleu == 0) {
// 		if(case_prise[coord_largeur_bleu+1][coord_hauteur_bleu] == 1) {
// 			if(case_prise[coord_largeur_bleu+1][coord_hauteur_bleu+1] == 1) {
// 				if(case_prise[coord_largeur_bleu][coord_hauteur_bleu+1] == 1) {
// 					if(case_prise[coord_largeur_bleu-1][coord_hauteur_bleu-1] == 1) {
// 						if(case_prise[coord_largeur_bleu-1][coord_hauteur_bleu] == 1) {
// 							LibererSprite(num_sprite_orange);
// 							LibererSprite(num_sprite_bleu);
// 							return 'o';
// 						} 
// 					}
// 				}
// 			}
// 		}
// 	}


// 		/*  droit defaite */
// 	if(coord_largeur_bleu == 0) {
// 		if(case_prise[coord_largeur_bleu][coord_hauteur_bleu-1] == 1) {
// 			if(case_prise[coord_largeur_bleu+1][coord_hauteur_bleu-1] == 1) {
// 				if(case_prise[coord_largeur_bleu+1][coord_hauteur_bleu] == 1) {
// 					if(case_prise[coord_largeur_bleu+1][coord_hauteur_bleu+1] == 1) {
// 						if(case_prise[coord_largeur_bleu][coord_hauteur_bleu+1] == 1) {
// 							LibererSprite(num_sprite_orange);
// 							LibererSprite(num_sprite_bleu);
// 							return 'o';
// 						} 
// 					}
// 				}
// 			}
// 		}
// 	}

// 		/*  gauche defaite */
// 	if(coord_largeur_bleu == taille_grille-1) {
// 		if(case_prise[coord_largeur_bleu][coord_hauteur_bleu+1] == 1) {
// 			if(case_prise[coord_largeur_bleu-1][coord_hauteur_bleu+1] == 1) {
// 				if(case_prise[coord_largeur_bleu-1][coord_hauteur_bleu] == 1) {
// 					if(case_prise[coord_largeur_bleu-1][coord_hauteur_bleu-1] == 1) {
// 						if(case_prise[coord_largeur_bleu][coord_hauteur_bleu-1] == 1) {
// 							LibererSprite(num_sprite_orange);
// 							LibererSprite(num_sprite_bleu);
// 							return 'o';
// 						} 
// 					}
// 				}
// 			}
// 		}
// 	}

// 		/* bas defaite */
// 	if(coord_hauteur_bleu == taille_grille-1) {
// 		if(case_prise[coord_largeur_bleu-1][coord_hauteur_bleu] == 1) {
// 			if(case_prise[coord_largeur_bleu-1][coord_hauteur_bleu-1] == 1) {
// 				if(case_prise[coord_largeur_bleu][coord_hauteur_bleu-1] == 1) {
// 					if(case_prise[coord_largeur_bleu+1][coord_hauteur_bleu-1] == 1) {
// 						if(case_prise[coord_largeur_bleu+1][coord_hauteur_bleu] == 1) {
// 							LibererSprite(num_sprite_orange);
// 							LibererSprite(num_sprite_bleu);
// 							return 'o';
// 						} 
// 					}
// 				}
// 			}
// 		}
// 	}


// 	if(case_prise[coord_largeur_bleu+1][coord_hauteur_bleu+1] == 1) {
// 		if(case_prise[coord_largeur_bleu+1][coord_hauteur_bleu] == 1) {
// 			if(case_prise[coord_largeur_bleu+1][coord_hauteur_bleu-1] == 1) {
// 				if(case_prise[coord_largeur_bleu][coord_hauteur_bleu+1] == 1) {
// 					if(case_prise[coord_largeur_bleu+1][coord_hauteur_bleu-1] == 1) {
// 						if(case_prise[coord_largeur_bleu-1][coord_hauteur_bleu+1] == 1) {
// 							if(case_prise[coord_largeur_bleu-1][coord_hauteur_bleu] == 1) {
// 								if(case_prise[coord_largeur_bleu+1][coord_hauteur_bleu-1] == 1) {
// 									LibererSprite(num_sprite_orange);
// 									LibererSprite(num_sprite_bleu);
// 									return 'o';
// 								}
// 							}
// 						}
// 					}
// 				}
// 			}
// 		}
// 	}



// 		/* Haut gauche coin defaite */
// 	if(coord_largeur_orange == 0 && coord_hauteur_orange == 0) {
// 		if(case_prise[coord_largeur_orange+1][coord_hauteur_orange] == 1) {
// 			if(case_prise[coord_largeur_orange+1][coord_hauteur_orange+1] == 1) {
// 				if(case_prise[coord_largeur_orange][coord_hauteur_orange+1] == 1) {
// 					LibererSprite(num_sprite_bleu);
// 					LibererSprite(num_sprite_orange);
// 					return 'b';
// 				}
// 			}
// 		}
// 	}

// 		/* Haut droit coin defaite */

// 	if(coord_largeur_orange == taille_grille-1 && coord_hauteur_orange == taille_grille-1) {
// 		if(case_prise[coord_largeur_orange-1][coord_hauteur_orange] == 1) {
// 			if(case_prise[coord_largeur_orange-1][coord_hauteur_orange-1] == 1) {
// 				if(case_prise[coord_largeur_orange][coord_hauteur_orange-1] == 1) {
// 					LibererSprite(num_sprite_bleu);
// 					LibererSprite(num_sprite_orange);
// 					return 'b';
// 				}
// 			}
// 		}
// 	}

// 		/* coin bas gauche */

// 	if(coord_largeur_orange == 0 && coord_hauteur_orange == taille_grille-1) {
// 		if(case_prise[coord_largeur_orange-1][coord_hauteur_orange] == 1) {
// 			if(case_prise[coord_largeur_orange-1][coord_hauteur_orange-1] == 1) {
// 				if(case_prise[coord_largeur_orange][coord_hauteur_orange-1] == 1) {
// 					LibererSprite(num_sprite_bleu);
// 					LibererSprite(num_sprite_orange);
// 					return 'b';
// 				}
// 			}
// 		}
// 	}


// 		/* coin bas droite */

// 	if(coord_largeur_orange == taille_grille-1 && coord_hauteur_orange == 0) {
// 		if(case_prise[coord_largeur_orange-1][coord_hauteur_orange] == 1) {
// 			if(case_prise[coord_largeur_orange-1][coord_hauteur_orange-1] == 1) {
// 				if(case_prise[coord_largeur_orange][coord_hauteur_orange-1] == 1) {
// 					LibererSprite(num_sprite_bleu);
// 					LibererSprite(num_sprite_orange);
// 					return 'b';
// 				}
// 			}
// 		}
// 	}


// 		/* Haut defaite */

// 	if(coord_hauteur_orange == 0) {
// 		if(case_prise[coord_largeur_orange+1][coord_hauteur_orange] == 1) {
// 			if(case_prise[coord_largeur_orange+1][coord_hauteur_orange+1] == 1) {
// 				if(case_prise[coord_largeur_orange][coord_hauteur_orange+1] == 1) {
// 					if(case_prise[coord_largeur_orange-1][coord_hauteur_orange-1] == 1) {
// 						if(case_prise[coord_largeur_orange-1][coord_hauteur_orange] == 1) {
// 							LibererSprite(num_sprite_bleu);
// 							LibererSprite(num_sprite_orange);
// 							return 'b';
// 						} 
// 					}
// 				}
// 			}
// 		}
// 	}


// 		/*  droit defaite */
// 	if(coord_largeur_orange == 0) {
// 		if(case_prise[coord_largeur_orange][coord_hauteur_orange-1] == 1) {
// 			if(case_prise[coord_largeur_orange+1][coord_hauteur_orange-1] == 1) {
// 				if(case_prise[coord_largeur_orange+1][coord_hauteur_orange] == 1) {
// 					if(case_prise[coord_largeur_orange+1][coord_hauteur_orange+1] == 1) {
// 						if(case_prise[coord_largeur_orange][coord_hauteur_orange+1] == 1) {
// 							LibererSprite(num_sprite_bleu);
// 							LibererSprite(num_sprite_orange);
// 							return 'b';
// 						} 
// 					}
// 				}
// 			}
// 		}
// 	}

// 		/*  gauche defaite */
// 	if(coord_largeur_orange == taille_grille-1) {
// 		if(case_prise[coord_largeur_orange][coord_hauteur_orange+1] == 1) {
// 			if(case_prise[coord_largeur_orange-1][coord_hauteur_orange+1] == 1) {
// 				if(case_prise[coord_largeur_orange-1][coord_hauteur_orange] == 1) {
// 					if(case_prise[coord_largeur_orange-1][coord_hauteur_orange-1] == 1) {
// 						if(case_prise[coord_largeur_orange][coord_hauteur_orange-1] == 1) {
// 							LibererSprite(num_sprite_bleu);
// 							LibererSprite(num_sprite_orange);
// 							return 'b';
// 						} 
// 					}
// 				}
// 			}
// 		}
// 	}

// 		/* bas defaite */
// 	if(coord_hauteur_orange == taille_grille-1) {
// 		if(case_prise[coord_largeur_orange-1][coord_hauteur_orange] == 1) {
// 			if(case_prise[coord_largeur_orange-1][coord_hauteur_orange-1] == 1) {
// 				if(case_prise[coord_largeur_orange][coord_hauteur_orange-1] == 1) {
// 					if(case_prise[coord_largeur_orange+1][coord_hauteur_orange-1] == 1) {
// 						if(case_prise[coord_largeur_orange+1][coord_hauteur_orange] == 1) {
// 							LibererSprite(num_sprite_bleu);
// 							LibererSprite(num_sprite_orange);
// 							return 'b';
// 						} 
// 					}
// 				}
// 			}
// 		}
// 	}


// 	if(case_prise[coord_largeur_orange+1][coord_hauteur_orange+1] == 1) {
// 		if(case_prise[coord_largeur_orange+1][coord_hauteur_orange] == 1) {
// 			if(case_prise[coord_largeur_orange+1][coord_hauteur_orange-1] == 1) {
// 				if(case_prise[coord_largeur_orange][coord_hauteur_orange+1] == 1) {
// 					if(case_prise[coord_largeur_orange+1][coord_hauteur_orange-1] == 1) {
// 						if(case_prise[coord_largeur_orange-1][coord_hauteur_orange+1] == 1) {
// 							if(case_prise[coord_largeur_orange-1][coord_hauteur_orange] == 1) {
// 								if(case_prise[coord_largeur_orange+1][coord_hauteur_orange-1] == 1) {
// 									LibererSprite(num_sprite_bleu);
// 									LibererSprite(num_sprite_orange);
// 									return 'b';
// 								}
// 							}
// 						}
// 					}
// 				}
// 			}
// 		}
// 	}





// }

// */