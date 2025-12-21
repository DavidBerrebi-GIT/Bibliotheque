#include <string>
#include "livre.h"
using namespace std;

class Bibliothèque
{
private:
	string nom;
	string adresse;
	int code;
	Livre* liste_livres;
public:
	Bibliothèque(string,string,int);
	virtual ~Bibliothèque();

	void set_nom(string);
	string get_nom();
	void set_adresse(string);
	string get_adresse();
	void set_code(int);
	int get_code();

};

