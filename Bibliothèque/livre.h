#ifndef LIVRE_H
#define LIVRE_H

#include <string>
using namespace std;

enum Etat { DISPONIBLE,
            EMPRENTE };
enum TypeLecteur { ENFANT,
                   ADULTE,
                   TOUS };
class Livre {
 protected:
  static int compteur;
  int code;
  string auteur;
  string titre;
  string editeur;
  string ISBN;
  TypeLecteur type_lecteur;
  Etat etat;
  Etat proprietaire;
  string categorie;

 public:
  Livre();
  Livre(string, string, string, string, TypeLecteur);
  virtual ~Livre();

  void set_code(int);
  int get_code();
  void set_auteur(string);
  string get_auteur();
  void set_titre(string);
  string get_titre();
  void set_editeur(string);
  string get_editeur();
  void set_ISBN(string);
  string get_ISBN();
  void set_type_lecteur(TypeLecteur);
  int get_type_lecteur();
  void set_etat(Etat);
  Etat get_etat();
  void set_categorie(string);
  string get_categorie();

  virtual void affiche() = 0;
  bool est_disponible();

  void emprunte();
  void retourne();
};

#endif
