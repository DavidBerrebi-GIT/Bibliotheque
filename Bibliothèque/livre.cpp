#include "livre.h"

#include <iostream>
int Livre::compteur = 0;

Livre::Livre() {
  code = compteur;
  auteur = "";
  titre = "";
  editeur = "";
  ISBN = "";
  type_lecteur = TOUS;
  etat = DISPONIBLE;
  compteur++;
  categorie = "Livre";

}
Livre::Livre(string auteur, string titre, string editeur, string ISBN, TypeLecteur type_lecteur) {
  code = compteur;
  this->auteur = auteur;
  this->titre = titre;
  this->editeur = editeur;
  this->ISBN = ISBN;
  this->type_lecteur = type_lecteur;
  this->etat = DISPONIBLE;
  this->categorie = "Livre";
  compteur++;
}
Livre::~Livre() {
  compteur--;
}

void Livre::set_code(int code) {
  this->code = code;
}
int Livre::get_code() {
  return code;
}
void Livre::set_auteur(string auteur) {
  this->auteur = auteur;
}
string Livre::get_auteur() {
  return auteur;
}
void Livre::set_titre(string titre) {
  this->titre = titre;
}
string Livre::get_titre() {
  return titre;
}
void Livre::set_editeur(string editeur) {
  this->editeur = editeur;
}
string Livre::get_editeur() {
  return editeur;
}
void Livre::set_ISBN(string ISBN) {
  this->ISBN = ISBN;
}
string Livre::get_ISBN() {
  return ISBN;
}
void Livre::set_type_lecteur(TypeLecteur type_lecteur) {
  this->type_lecteur = type_lecteur;
}
int Livre::get_type_lecteur() {
  return type_lecteur;
}
void Livre::set_etat(Etat etat) {
  this->etat = etat;
}
Etat Livre::get_etat() {
  return etat;
}
void Livre::set_categorie(string categorie) {
  this->categorie = categorie;
}
string Livre::get_categorie() {
  return categorie;
}

void Livre::affiche() {
  string etat_str = (etat == DISPONIBLE) ? "Disponible" : "Emprunté";
  string type_lecteur_str[] = {"Enfant", "Adulte", "Tous"};
  cout << "Code: " << code << endl;
  cout << "Auteur: " << auteur << endl;
  cout << "Titre: " << titre << endl;
  cout << "Editeur: " << editeur << endl;
  cout << "ISBN: " << ISBN << endl;
  cout << "Type de lecteur: " << type_lecteur_str[type_lecteur] << endl;
  cout << "Etat: " << etat_str << endl;
}
bool Livre::est_disponible() {
  return etat == 0;
}
void Livre::emprunte() {
  etat = EMPRENTE;
}
void Livre::retourne() {
  etat = DISPONIBLE;
}
