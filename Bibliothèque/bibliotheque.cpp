#include "livre.h" 
#include "bibliotheque.h"
#include <iostream>


Bibliotheque::Bibliotheque(string nom, string adresse, int code) {
	this->nom = nom;
	this->adresse = adresse;
	this->code = code;
	nb_livres = 0;
	capacite_livres = 10;
	liste_livres = new Livre*[capacite_livres];

}
Bibliotheque::~Bibliotheque() {
	delete[] liste_livres;
}
void Bibliotheque::set_nom(string nom) {
	this->nom = nom;
}
string Bibliotheque::get_nom() {
	return nom;
}
void Bibliotheque::set_adresse(string adresse) {
	this->adresse = adresse;
}
string Bibliotheque::get_adresse() {
	return adresse;
}
void Bibliotheque::set_code(int code) {
	this->code = code;
}
int Bibliotheque::get_code() {
	return code;
}

void Bibliotheque::ajouter_livre(Livre* livre) {
    if (nb_livres >= capacite_livres) {
        capacite_livres *= 2;
        Livre** nouvelle_liste = new Livre*[capacite_livres];
        for (int i = 0; i < nb_livres; i++) {
            nouvelle_liste[i] = liste_livres[i];
        }
        delete[] liste_livres;
        liste_livres = nouvelle_liste;
    }
    liste_livres[nb_livres] = livre;
    nb_livres++;
}

void Bibliotheque::afficher_livres() {
	if (nb_livres == 0) {
		cout << "Aucun livre dans la bibliotheque." << endl;
		return;
	}
	cout << "Nombre de livres dans la bibliotheque: " << nb_livres << "/" << capacite_livres << endl;
	cout << "Liste des livres:" << endl;
	for (int i = 0; i < nb_livres; i++) {

		liste_livres[i]->affiche();
		cout << "------------------------" << endl;
	}
}
