#include "bd.h"

#include <iostream>

BD::BD() : Livre() {
  dessinateur = "";
  categorie = "BD";
}
BD::BD(string auteur, string titre, string editeur, string ISBN, TypeLecteur type_lecteur, string dessinateur)
    : Livre(auteur, titre, editeur, ISBN, type_lecteur) {
  this->dessinateur = dessinateur;
  categorie = "BD";
}
BD::~BD() {
  compteur--;
}
void BD::set_dessinateur(string dessinateur) {
  this->dessinateur = dessinateur;
}
string BD::get_dessinateur() {
  return dessinateur;
}
void BD::affiche() {
  Livre::affiche();
  cout << "Dessinateur: " << dessinateur << endl;
}
