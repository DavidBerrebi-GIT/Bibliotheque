#include "interface.h"
#include "Noeud.h"
#include <iostream>
using namespace std;

Interface::Interface(){
  bibliotheques = nullptr;
  adherants = nullptr;

};
Interface::~Interface() {
  if (bibliotheques != nullptr) {
	delete bibliotheques;
  }
  if (adherants != nullptr) {
    delete adherants;
  }
}

void Interface::ajouterBibliotheque() {
  string nom, adresse;
  int code;
  cout << "Nom de la bibliotheque : " << endl;
  cin >> nom;
  cout << "Adresse de la bibliotheque : " << endl;
  cin >> adresse;
  cout << "Code de la bibliotheque : " << endl;
  cin >> code;
  Bibliotheque* nouvelleBiblio = new Bibliotheque(nom, adresse, code);
  bibliotheques.ajouterTete(nouvelleBiblio);
}

void Interface::ajouterAdherant() {
  string nom, prenom, adresse;
  int numero, max_emprunts;
  cout << "Nom de l'adherant : " << endl;
  cin >> nom;
  cout << "Prenom de l'adherant : " << endl;
  cin >> prenom;
  cout << "Adresse de l'adherant : " << endl;
  cin >> adresse;
  cout << "Numero d'adherant : " << endl;
  cin >> numero;
  cout << "Nombre maximum d'emprunts : " << endl;
  cin >> max_emprunts;
  // Pour simplifier, on assigne la premiere bibliotheque disponible
  Bibliotheque* biblio = bibliotheques.getHead();
  Adherant* nouvelAdherant = new Adherant(nom, prenom, adresse, numero, biblio, max_emprunts);
  adherants.ajouterTete(nouvelAdherant);
}

void Interface::afficherBibliotheques() {
  Noeud<Bibliotheque>* current = &bibliotheques;
  while (current != nullptr) {
	Bibliotheque* biblio = current->getHead();
    biblio->afficher();
	current = current->getNext();
  }
}


