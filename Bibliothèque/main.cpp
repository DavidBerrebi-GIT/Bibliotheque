#include "bibliotheque.h"
#include "bd.h"
#include "roman.h"
#include "recueil_poesie.h"
#include "album.h"
#include "theatre.h"
#include <iostream>

int main()
{
	Bibliotheque biblio = Bibliotheque("Bibliotheque Centrale", "123 Rue Principale", 1);
	
	BD bd1 = BD("AuteurBD1", "TitreBD1", "EditeurBD1", "ISBNBD1", 2, 1, "Dessinateur1");
	Roman roman1 = Roman("AuteurRoman1", "TitreRoman1", "EditeurRoman1", "ISBNRoman1", 1, 1, "Genre1");
	Recueil_poesie recueil1 = Recueil_poesie("AuteurRecueil1", "TitreRecueil1", "EditeurRecueil1", "ISBNRecueil1", 3, 1, true, false);
	Theatre theatre1 = Theatre("AuteurTheatre1", "TitreTeatre1", "EditeurTheatre1", "ISBNTheatre1", 1, 1, 18);
	Album album1 = Album("AuteurAlbum1", "TitreAlbum1", "EditeurTheatre1", "ISBNTheatre1", 1, 1, true, false);

	biblio.ajouter_livre(&bd1);
	biblio.ajouter_livre(&roman1);
	biblio.ajouter_livre(&recueil1); 
	biblio.ajouter_livre(&theatre1);
	biblio.ajouter_livre(&album1);

	Bibliotheque  biblio2 = Bibliotheque("Bibliotheque Secondaire", "456 Rue Secondaire", 2);
	BD bd2 = BD("AuteurBD2", "TitreBD2", "EditeurBD2", "ISBNBD2", 2, 1, "Dessinateur2");
	Roman roman2 = Roman("AuteurRoman2", "TitreRoman2", "EditeurRoman2", "ISBNRoman2", 1, 1, "Genre2");

	biblio2.ajouter_livre(&bd2);
	biblio2.ajouter_livre(&roman2);

	

	cout << "Premier affichage :" << endl;
	biblio.afficher_livres();
	cout << "deuxieme affichage : romans:" << endl;
	biblio.afficher_categorie("Roman");

	biblio.supprimer_livre(roman1.get_code());
	cout << "Troisième affichage :  apres suppression" << endl;
	biblio.afficher_livres();
	biblio.emprunter_livre(biblio2, bd2.get_code());
	cout << "------------------------\n" << endl;
	cout << "Quatrième affichage : Après emprunt du livre BD2 de la bibliotheque secondaire:" << endl;

	biblio.afficher_livres();

	
}

