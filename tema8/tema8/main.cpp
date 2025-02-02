#include <iostream>

using namespace std;

/*
	Folosind clasa friend implementati o aplicatie in care sa aveti calculati volumul unei cutii:
		-clasa cutie sa contina initializarea constructorului si metoda de afisare a dimensiunilor cutiei
		-clasa freind o sa contina metoda caluleaza volum si afisaza volumul si metoda care modifica dimensiunea cutiei
		- in main cream obictuel cutiamica calculam volumul si modificam cutiei si afisam dimensiunile
*/

class Cutie {
private:
	double l; //lungime
	double w; //latime
	double h; //inaltime

public:
	Cutie(double l, double w, double h) : l(l), w(w), h(h) {}

	void display() const {
		cout << "Dim cutie: " << l << " x " << w << " x " << h << endl;
	}

	friend class OperatiiCutie;
};

class OperatiiCutie {
public:
	static void volum(const Cutie& c) {
		double volum = c.l * c.w * c.h;
		cout << "Volumul cutiei este: " << volum << endl;
	}

	static void modify(Cutie& c, double l, double w, double h) {
		c.l = l;
		c.w = w;
		c.h = h;
	}
};

/*
	Implementati clasa “persoana” care contine metoda de afisare a varstei si numelui,
	 clasa child  “angajat” ne spune ce functie ocupa angajatul, si metoda care afisaza numele jobului.

*/

class Person {
private:
	string name;
	int age;
public:
	Person(string name, int age) : name(name), age(age) {
	}

	void display() const {
		cout << "Name: " << name << ", Age: " << age << endl;
	}
};

class Angajat : public Person {
private:
	string job;
public:
	Angajat(string name, int age, string job) : Person(name, age), job(job) {}

	void displayJob() const {
		cout << "job: " << job << endl;
	}

};

int main() {

	Cutie c1(2.0, 2.0, 2.0);
	c1.display();
	OperatiiCutie::volum(c1);
	OperatiiCutie::modify(c1, 3.0, 3.0, 4.0);
	cout << endl;
	c1.display();
	OperatiiCutie::volum(c1);
	cout << endl << endl;

	Angajat a1("Gabi", 22, "Studenta");
	a1.display();
	a1.displayJob();

	return 0;
}