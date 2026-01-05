#include "roman.h"

#include <iostream>
Roman::Roman() : Livre() {
  genre = "";
  categorie = "Roman";
}
Roman::Roman(string auteur, string titre, string editeur, string ISBN, TypeLecteur type_lecteur, string genre)
    : Livre(auteur, titre, editeur, ISBN, type_lecteur) {
  this->genre = genre;
  categorie = "Roman";
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
