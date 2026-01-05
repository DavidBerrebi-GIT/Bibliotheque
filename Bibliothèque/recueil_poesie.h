#ifndef RECUEIL_POESIE_H
#define RECUEIL_POESIE_H
#include "livre.h"
class Recueil_poesie : public Livre {
 private:
  bool vers;
  bool prose;

 public:
  Recueil_poesie();
  Recueil_poesie(string, string, string, string, TypeLecteur, bool, bool);
  ~Recueil_poesie();
  void set_vers(bool);
  bool get_vers();
  void set_prose(bool);
  bool get_prose();
  void affiche() override;
};

#endif
