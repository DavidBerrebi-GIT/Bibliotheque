#ifndef ADHERANT_H
#define ADHERANT_H

#include <string>
#include "bibliotheque.h"	
#include "livre.h"
using namespace std;
class Adherant
{
private:
	string nom;
	string prenom;
	string adresse;
	int id;
	Bibliotheque* bibliotheques;
	Livre** livres_empruntes;
	int nb_livres_empruntes;
	int autorisation_livres_empruntes;
public:
	Adherant(string, string, string, int, Bibliotheque*, int);
	virtual ~Adherant();
	void set_nom(string);
	string get_nom();
	void set_prenom(string);
	string get_prenom();
	void set_adresse(string);
	string get_adresse();
	int get_id();
	Bibliotheque* get_bibliotheques();
	int get_nb_livres_empruntes();
	void set_autorisation_livres_empruntes(int);
	int get_autorisation_livres_empruntes();
	void emprunter_livre(int);
	void retourner_livre(int);
	void afficher_livres_empruntes();
	void changer_bibliotheque(Bibliotheque*);

};
#endif

