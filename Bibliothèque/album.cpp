#include "album.h"
#include <iostream>

Album::Album() : Livre() {
	dessin = false;
	photo = false;
}

Album::Album(string auteur, string titre, string editeur, string ISBN, int type_lecteur, int etat, bool dessin, bool photo)
	: Livre(auteur, titre, editeur, ISBN, type_lecteur, etat) {
	this->dessin = dessin;
	this->photo = photo;
}
Album::~Album() {
	compteur--;
}
void Album::set_dessin(bool dessin) {
	this->dessin = dessin;
}
bool Album::get_dessin() {
	return dessin;
}
void Album::set_photo(bool photo) {
	this->photo = photo;
}
bool Album::get_photo() {
	return photo;
}
void Album::affiche() {
	Livre::affiche();
	std::cout << "Dessin: " << (dessin ? "Oui" : "Non") << std::endl;
	std::cout << "Photo: " << (photo ? "Oui" : "Non") << std::endl;
}
