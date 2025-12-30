#include "adherant.h"

#include <iostream>
Adherant::Adherant(string nom, string prenom, string adresse, int id, Bibliotheque* bibliotheques, int autorisation_livres_empruntes) {
	this->nom = nom;
	this->prenom = prenom;
	this->adresse = adresse;
	this->id = id;
	this->bibliotheques = bibliotheques;
	this->autorisation_livres_empruntes = autorisation_livres_empruntes;
	nb_livres_empruntes = 0;
	livres_empruntes = new Livre * [autorisation_livres_empruntes];
}
Adherant::~Adherant() {
	delete[] livres_empruntes;
}
void Adherant::set_nom(string nom) {
	this->nom = nom;
}
string Adherant::get_nom() {
	return nom;
}
void Adherant::set_prenom(string prenom) {
	this->prenom = prenom;
}
string Adherant::get_prenom() {
	return prenom;
}
void Adherant::set_adresse(string adresse) {
	this->adresse = adresse;
}
string Adherant::get_adresse() {
	return adresse;
}
int Adherant::get_id() {
	return id;
}
Bibliotheque* Adherant::get_bibliotheques() {
	return bibliotheques;
}
int Adherant::get_nb_livres_empruntes() {
	return nb_livres_empruntes;
}
void Adherant::set_autorisation_livres_empruntes(int autorisation_livres_empruntes) {
	this->autorisation_livres_empruntes = autorisation_livres_empruntes;
}
int Adherant::get_autorisation_livres_empruntes() {
	return autorisation_livres_empruntes;
}


void Adherant::emprunter_livre(int code) {
	if (nb_livres_empruntes >= autorisation_livres_empruntes) {
		std::cout << "Limite d'emprunt atteinte." << std::endl;
		return;
	}
	if (!bibliotheques->possede_livre(code)) {
		std::cout << "Le livre n'est pas disponible dans cette bibliotheque." << std::endl;
		return;
	}
	Livre* livre_emprunte = bibliotheques->emprunt_adherant(code);
	if (livre_emprunte != nullptr) {
		livres_empruntes[nb_livres_empruntes] = livre_emprunte;
		nb_livres_empruntes++;
		std::cout << "Livre emprunte avec succes." << std::endl;
	}
	
}
