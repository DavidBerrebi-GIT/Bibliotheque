#ifndef BIBLIOTHEQUE_H
#define BIBLIOTHEQUE_H

#include <string>
#include "livre.h"
using namespace std;

class Bibliotheque
{
private:
	string nom;
	string adresse;
	int code;
	Livre** liste_livres;
	int nb_livres;
	int capacite_livres;
public:
	Bibliotheque(string,string,int);
	virtual ~Bibliotheque();

	void set_nom(string);
	string get_nom();
	void set_adresse(string);
	string get_adresse();
	void set_code(int);
	int get_code();


	void ajouter_livre(Livre*);
	void afficher_livres();

};

#endif

