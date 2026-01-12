#ifndef ALBUM_H
#define ALBUM_H
#include "livre.h"
class Album : public Livre {
 private:
  bool dessin;
  bool photo;

 public:
  Album();
  Album(string, string, string, string, TypeLecteur, bool, bool);
  ~Album();
  void set_dessin(bool);
  bool get_dessin();
  void set_photo(bool);
  bool get_photo();
  void affiche() override;
};
#endif
