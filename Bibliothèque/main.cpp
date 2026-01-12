#include <iostream>

#include "adherant.h"
#include "bibliotheque.h"
#include "livres/album.h"
#include "livres/bd.h"
#include "livres/recueil_poesie.h"
#include "livres/roman.h"
#include "livres/theatre.h"

int main() {
  /*
   * le main sert a tester les differentes fonctionnalites des classes
   */

  Bibliotheque biblio = Bibliotheque("Bibliotheque Centrale", "123 Rue Principale", 1);

  BD bd1 = BD("AuteurBD1", "TitreBD1", "EditeurBD1", "ISBNBD1", ENFANT, "Dessinateur1");
  Roman roman1 = Roman("AuteurRoman1", "TitreRoman1", "EditeurRoman1", "ISBNRoman1", TOUS, "Genre1");
  Recueil_poesie recueil1 =
      Recueil_poesie("AuteurRecueil1", "TitreRecueil1", "EditeurRecueil1", "ISBNRecueil1", ADULTE, true, false);
  Theatre theatre1 = Theatre("AuteurTheatre1", "TitreTeatre1", "EditeurTheatre1", "ISBNTheatre1", TOUS, 18);
  Album album1 = Album("AuteurAlbum1", "TitreAlbum1", "EditeurTheatre1", "ISBNTheatre1", ENFANT, true, false);

  biblio.ajouter_livre(&bd1);
  biblio.ajouter_livre(&roman1);
  biblio.ajouter_livre(&recueil1);
  biblio.ajouter_livre(&theatre1);
  biblio.ajouter_livre(&album1);

  Bibliotheque biblio2 = Bibliotheque("Bibliotheque Secondaire", "456 Rue Secondaire", TOUS);
  BD bd2 = BD("AuteurBD2", "TitreBD2", "EditeurBD2", "ISBNBD2", ENFANT, "Dessinateur2");
  Roman roman2 = Roman("AuteurRoman2", "TitreRoman2", "EditeurRoman2", "ISBNRoman2", TOUS, "Genre2");
  Roman roman3 = Roman("AuteurRoman3", "TitreRoman3", "EditeurRoman3", "ISBNRoman3", TOUS, "Genre3");

  biblio2.ajouter_livre(&bd2);
  biblio2.ajouter_livre(&roman2);
  biblio2.ajouter_livre(&roman3);

  cout << "Premier affichage :" << endl;
  biblio.afficher_livres();
  cout << "deuxieme affichage : romans:" << endl;
  biblio.afficher_livres(ROMAN);

  biblio.supprimer_livre(roman1.get_code());
  cout << "Troisième affichage :  apres suppression" << endl;
  biblio.afficher_livres();

  cout << "Affichage avant emprunt " << endl;
  biblio.afficher_livres();
  biblio2.afficher_livres();
  biblio.emprunter_livre(biblio2, bd2.get_ISBN());
  cout << "------------------------\n"
       << endl;
  cout << "Affichage après emprunt du livre BD2 de la bibliotheque secondaire:" << endl;

  cout << "Nb livres dans biblio principale: " << biblio.get_nblivres() << endl;
  cout << "Nb livres dans biblio secondaire: " << biblio2.get_nblivres() << endl;

  biblio.afficher_livres();
  biblio2.afficher_livres();

  Adherant adherant1 = Adherant("Dupont", "Jean", "789 Rue Adherant", 1, &biblio, 2);

  adherant1.emprunter_livre(bd2.get_code());
  cout << adherant1.get_nb_livres_empruntes() << endl;

  adherant1.retourner_livre(bd2.get_code());
  cout << adherant1.get_nb_livres_empruntes() << endl;

  biblio.retourner_livres();

  adherant1.emprunter_livre(bd2.get_code());
  cout << adherant1.get_nb_livres_empruntes() << endl;

  adherant1.retourner_livre(bd2.get_code());
  cout << adherant1.get_nb_livres_empruntes() << endl;

  adherant1.emprunter_livre(bd1.get_code());
  adherant1.emprunter_livre(theatre1.get_code());
  adherant1.emprunter_livre(recueil1.get_code());

  Adherant adherant2 = Adherant("Martin", "Sophie", "321 Rue Adherant2", 2, &biblio, 3);
  adherant2.emprunter_livre(bd1.get_code());
  cout << adherant2.get_nb_livres_empruntes() << endl;
}
