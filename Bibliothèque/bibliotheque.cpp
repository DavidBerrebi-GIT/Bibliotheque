#include "bibliotheque.h"

#include <iostream>

#include "livre.h"

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
int Bibliotheque::get_nblivres() {
  return nb_livres;
}
int Bibliotheque::get_capacite_livres() {
  return capacite_livres;
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
  cout << endl;
}
void Bibliotheque::afficher_livres(Categorie categorie) {
  int compteur = 0;
  for (int i = 0; i < nb_livres; i++) {
    if (liste_livres[i]->get_categorie() == categorie) {
      compteur++;
    }
  }
  if (compteur == 0) {
    cout << "Aucun livre de la catégorie '" << categorie << "' dans la bibliotheque." << endl;
    return;
  }
  cout << "Nombre de livres de la catégorie '" << categorie << "' dans la bibliotheque : " << compteur << " / " << nb_livres << endl;
  cout << "Liste des livres:" << endl;
  for (int i = 0; i < nb_livres; i++) {
    if (liste_livres[i]->get_categorie() == categorie) {
      liste_livres[i]->affiche();
      cout << "------------------------" << endl;
    }
  }
}

bool Bibliotheque::possede_livre(int code) {
  for (int i = 0; i < nb_livres; i++) {
    if (liste_livres[i]->get_code() == code) {
      return true;
    }
  }
  return false;
}
void Bibliotheque::supprimer_livre(int code) {
  if (!possede_livre(code)) {
    return;
  }
  Livre** nouvelle_liste = new Livre*[capacite_livres];
  int j = 0;
  for (int i = 0; i < nb_livres; i++) {
    if (liste_livres[i]->get_code() != code) {
      nouvelle_liste[j] = liste_livres[i];
      j++;
    }
  }
  delete[] liste_livres;

  liste_livres = nouvelle_liste;
  nb_livres = j;
}
void Bibliotheque::emprunter_livre(Bibliotheque& autre, string ISBN) {
  for (int i = 0; i < autre.nb_livres; i++) {
    if (autre.liste_livres[i]->get_ISBN() == ISBN) {
      Livre* livre_emprunte = autre.liste_livres[i];
      // peut etre dire que le livre est emprunte a une autre bibliotheque
      ajouter_livre(livre_emprunte);
      autre.supprimer_livre(livre_emprunte->get_code());
      return;
    }
  }
}
Livre* Bibliotheque::emprunt_adherant(int code) {
  for (int i = 0; i < nb_livres; i++) {
    if (liste_livres[i]->get_code() == code && liste_livres[i]->est_disponible()) {
      Livre* livre_emprunte = liste_livres[i];
      livre_emprunte->emprunte();
      return livre_emprunte;
    }
  }
  return nullptr;
}
