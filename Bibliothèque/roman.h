#ifndef ROMAN_H
#define ROMAN_H

#include "livre.h"
class Roman : public Livre {
 private:
  string genre;

 public:
  Roman();
  Roman(string, string, string, string, TypeLecteur, string);
  ~Roman();
  void set_genre(string);
  string get_genre();
  void affiche() override;
};
#endif
