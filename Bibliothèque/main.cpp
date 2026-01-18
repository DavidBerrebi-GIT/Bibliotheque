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

  Adherant adherant1 = Adherant("Dupont", "Jean", "789 Rue Adherant", 1, &biblio, 2);

  adherant1.emprunter_livre(bd1.get_code());
  adherant1.emprunter_livre(theatre1.get_code());

  Adherant adherant2 = Adherant("Martin", "Sophie", "321 Rue Adherant2", 2, &biblio, 3);

  cout << endl
       << endl
       << "Bienvenue a la bibliotheque !" << endl;
  Adherant* current_adherant = nullptr;
  int adherant_choice;
  while (true) {
    cout << "Veuillez choisir votre numero d'adherent (1 ou 2), ou 0 pour quitter: ";
    cin >> adherant_choice;
    if (adherant_choice == 0) {
      break;
    } else if (adherant_choice == 1) {
      current_adherant = &adherant1;
    } else if (adherant_choice == 2) {
      current_adherant = &adherant2;
    } else {
      cout << "Numero d'adherent invalide. Veuillez reessayer." << endl;
      continue;
    }
    int action_choice;
    while (true) {
      cout << "\nQue souhaitez-vous faire ?" << endl;
      cout << "1. Voir la liste des livres disponibles" << endl;
      cout << "2. Emprunter un livre" << endl;
      cout << "3. Retourner un livre" << endl;
      cout << "4. Voir mes livres empruntes" << endl;
      cout << "5. Se deconnecter" << endl;
      cout << "Votre choix: ";
      cin >> action_choice;
      cout << endl;
      if (action_choice == 1) {
        current_adherant->get_bibliotheque()->afficher_livres();
      } else if (action_choice == 2) {
        int code_to_borrow;
        cout << "Entrez le code du livre a emprunter: ";
        cin >> code_to_borrow;
        current_adherant->emprunter_livre(code_to_borrow);

      } else if (action_choice == 3) {
        int code_to_return;
        cout << "Entrez le code du livre a retourner: ";
        cin >> code_to_return;
        current_adherant->retourner_livre(code_to_return);
      } else if (action_choice == 4) {
        current_adherant->afficher_livres_empruntes();
      } else if (action_choice == 5) {
        cout << "Déconnexion..." << endl;
        break;
      } else {
        cout << "Choix invalide. Veuillez réessayer." << endl;
      }
    }
  }
}
