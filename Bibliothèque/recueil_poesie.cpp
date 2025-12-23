#include "recueil_poesie.h"

#include <iostream>
Recueil_poesie::Recueil_poesie() : Livre() {
	vers = false;
	prose = false;
	categorie = "Recueil de poesie";

}
Recueil_poesie::Recueil_poesie(string auteur, string titre, string editeur, string ISBN, int type_lecteur, int etat, bool vers, bool prose)
	: Livre(auteur, titre, editeur, ISBN, type_lecteur, etat) {
	this->vers = vers;
	this->prose = prose;
	categorie = "Recueil de poesie";

}
Recueil_poesie::~Recueil_poesie() {
	compteur--;
}
void Recueil_poesie::set_vers(bool vers) {
	this->vers = vers;
}
bool Recueil_poesie::get_vers() {
	return vers;
}
void Recueil_poesie::set_prose(bool prose) {
	this->prose = prose;
}
bool Recueil_poesie::get_prose() {
	return prose;
}
void Recueil_poesie::affiche() {
	Livre::affiche();
	std::cout << "Vers: " << (vers ? "Oui" : "Non") << std::endl;
	std::cout << "Prose: " << (prose ? "Oui" : "Non") << std::endl;
}

