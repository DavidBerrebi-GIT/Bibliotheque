#ifndef BD_H
#define BD_H

#include "livre.h"
class BD : public Livre {
 protected:
  string dessinateur;

 public:
  BD();
  BD(string, string, string, string, TypeLecteur, string);
  ~BD();
  void set_dessinateur(string);
  string get_dessinateur();
  void affiche() override;
};

#endif
