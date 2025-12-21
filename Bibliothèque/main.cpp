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
	biblio.afficher_livres();
}

