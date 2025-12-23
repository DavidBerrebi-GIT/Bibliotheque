#include "theatre.h"

#include <iostream>
Theatre::Theatre() : Livre() {
	siecle = 0;
	categorie = "Theatre";

}
Theatre::Theatre(string auteur, string titre, string editeur, string ISBN, int type_lecteur, int etat, int siecle)
	: Livre(auteur, titre, editeur, ISBN, type_lecteur, etat) {
	this->siecle = siecle;
	categorie = "Theatre";

}
Theatre::~Theatre() {
	compteur--;
}
void Theatre::set_siecle(int siecle) {
	this->siecle = siecle;
}
int Theatre::get_siecle() {
	return siecle;
}
void Theatre::affiche() {
	Livre::affiche();
	std::cout << "Siècle: " << siecle << std::endl;
}
