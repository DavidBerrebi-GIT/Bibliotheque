#ifndef BIBLIOTHEQUE_H
#define BIBLIOTHEQUE_H

#include <string>

#include "livre.h"
using namespace std;

class Bibliotheque {
 private:
  string nom;
  string adresse;
  int code;
  Livre** liste_livres;
  int nb_livres;
  int capacite_livres;

 public:
  Bibliotheque(string, string, int);
  virtual ~Bibliotheque();

  void set_nom(string);
  string get_nom();
  void set_adresse(string);
  string get_adresse();
  void set_code(int);
  int get_code();
  int get_nblivres();
  int get_capacite_livres();

  void ajouter_livre(Livre*);
  void afficher_livres();
  void afficher_livres(Categorie);

  bool possede_livre(string);
  bool possede_livre(int);
  void supprimer_livre(int);
  void emprunter_livre(Bibliotheque&, string);
  Livre* emprunt_adherant(int);
};

#endif
