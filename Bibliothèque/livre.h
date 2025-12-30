#ifndef LIVRE_H
#define LIVRE_H

#include <string>
using namespace std;
class Livre {
protected:
	static int compteur;
	int code;
	string auteur;
	string titre;
	string editeur;
	string ISBN;
	int type_lecteur;
	int etat;
	string categorie;

public:
	Livre();
	Livre(string, string, string, string, int, int);
	virtual ~Livre();

	void set_code(int);
	int get_code();
	void set_auteur(string);
	string get_auteur();
	void set_titre(string);
	string get_titre();
	void set_editeur(string);
	string get_editeur();
	void set_ISBN(string);
	string get_ISBN();
	void set_type_lecteur(int);
	int get_type_lecteur();
	void set_etat(int);
	int get_etat();
	void set_categorie(string);
	string get_categorie();

	virtual void affiche() = 0;
	bool est_disponible();

	void emprunte();
	void retourne();

};

#endif 

