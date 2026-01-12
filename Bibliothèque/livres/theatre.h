#ifndef THEATRE_H
#define THEATRE_H
#include "livre.h"
class Theatre : public Livre {
 private:
  int siecle;

 public:
  Theatre();
  Theatre(string, string, string, string, TypeLecteur, int);
  ~Theatre();
  void set_siecle(int);
  int get_siecle();
  void affiche() override;
};

#endif
