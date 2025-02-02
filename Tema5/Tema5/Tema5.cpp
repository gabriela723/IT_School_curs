#include <iostream>

using namespace std;

struct biblioteca {
	string categorie;
	string carte;
	int rand;
};

struct Elev {
	string nume;
	string prenume;
	int varsta;
	int notaR; //romana
	int notaI; //istorie
	int notaM; //mate
	float media;
};

void citire(Elev &elev) {
	cout << "Introduceti numele: ";
	cin >> elev.nume;
	cout << "\nIntroduceti prenumele: ";
	cin >> elev.prenume;
	cout << "\nIntroduceti varsta: ";
	cin >> elev.varsta;
	cout << "\nIntroduceti nota la romana: ";
	cin >> elev.notaR;
	cout << "\nIntroduceti nota la mate: ";
	cin >> elev.notaM;
	cout << "\nIntroduceti nota la istorie: ";
	cin >> elev.notaI;
}

void media(Elev &elev) {
	elev.media = (float)(elev.notaI + elev.notaM + elev.notaR) / 3;
}

void afisare(Elev elev) {
	cout << "Nume: " << elev.nume << endl;
	cout << "Prenume: " << elev.prenume << endl;
	cout << "Varsta: " << elev.varsta << endl;
	cout << "Nota la romana: " << elev.notaR << endl;
	cout << "Nota la mate: " << elev.notaM << endl;
	cout << "Nota la istorie: " << elev.notaI << endl;
	cout << "Media notelor: "<<elev.media << endl;
}

int main()
{
	Elev elev;
	citire(elev);
	media(elev);
	afisare(elev);
	return 0;
}

