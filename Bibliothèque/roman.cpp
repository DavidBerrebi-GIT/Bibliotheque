#include "roman.h"

#include <iostream>
Roman::Roman() : Livre() {
	genre = "";
}
Roman::Roman(string auteur, string titre, string editeur, string ISBN, int type_lecteur, int etat, string genre)
	: Livre(auteur, titre, editeur, ISBN, type_lecteur, etat) {
	this->genre = genre;
}
Roman::~Roman() {
	compteur--;
}
void Roman::set_genre(string genre) {
	this->genre = genre;
}
string Roman::get_genre() {
	return genre;
}
void Roman::affiche() {
	Livre::affiche();
	std::cout << "Genre: " << genre << std::endl;
}

