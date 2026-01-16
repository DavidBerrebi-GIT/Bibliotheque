#ifndef INTERFACE_H
#define INTERFACE_H
#include "bibliotheque.h"
#include "adherant.h"
#include "Noeud.h"
class Interface {
 private:
  Noeud<Bibliotheque> bibliotheques;
  Noeud<Adherant> adherants;

public:
  Interface();
  virtual ~Interface();
  void ajouterBibliotheque();
  void ajouterAdherant();
  void afficherBibliotheques();
  void afficherAdherants();
  void menuPrincipal();

};

#endif  // INTERFACE_H