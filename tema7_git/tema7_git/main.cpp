#include <iostream>
#include <vector>
#include <string>

using namespace std;

/*
	1.Sa se implementeze o aplicatie cu 2 atribute
		private:
		std::string name;
		std::vector<int> data;
	O sa avem un constructor standard
		MyClass(const std::string& n, int size) : name(n), data(size, 0) ; care va printa : “"Constructor standard apelat”

	A.Implementati constructorul de delegare care va delaga construcorul standard si cu o valoare default 10
	B.implementati move constructor
	c.metoda de afisare
*/

class MyClass {
private:
	string name;
	vector<int> data;

public:
	//constructor standard
	MyClass(const string& n, int size) : name(n), data(size, 0) {
		cout << "Constructor standard apelat" << endl;
	}

	//constructor delegat
	MyClass(const string& n) : MyClass(n, 10) {
		cout << "Constructor delegat apelat" << endl;
	}

	//move constructor
	MyClass(MyClass&& other) : name(move(other.name)), data(move(other.data)) {
		cout << "Move constructor apelat" << endl;
	}

	//display
	void print() {
		cout << "Name: " << name << "  Data: ";
		for (int& i : data) {
			cout << i << " ";
		}
		cout << endl;
	}
};

/*
	2.Implementati o clasă Point cu doi membri x și y, care reprezintă coordonatele unui punct într-un sistem 2D.
	Suprascrieti operatorul + pentru a adăuga două obiecte de tip Point. Când folosim operatorul + între două obiecte Point,
se creează un nou punct cu coordonatele adunate
	Operatorul + returnează un nou obiect de tip Point, care conține suma coordonatelor celor două puncte.
*/

class Point {
private:
	int x, y;
public:
	Point(int x = 0, int y = 0) : x(x), y(y) {}
	Point operator+(const Point& other) const {
		return Point(x + other.x, y + other.y);
	}
	void print() const {
		cout << "P(" << x << ", " << y << ")" << endl;
	}
};


/*
	3. Implementati o aplicatie unde sa folosim copy constructor avand membrul:  int* value;
		a.constructorul default MyClass(int v) va seta valoarea lui *value =v;
		b.implementati constructorul de copiere
		c.Implementati metoda  de afisare
*/

class CopyClass {
private:
	int* value;
public:
	CopyClass(int value) : value(new int(value)) {
		cout << "Constructor standard apelat" << endl;
	}

	//copy constructor
	CopyClass(const CopyClass& other) :value(new int(*other.value)) {
		cout << "Copy constructor apelat" << endl;
	}

	//destructor
	~CopyClass() {
		delete value;
	}

	//display
	void print() const {
		cout << "Value: " << *value << endl;
	}
};


int main() {

	MyClass obj1("Test", 5);
	obj1.print();

	MyClass obj2("AnotherTest");
	obj2.print();

	MyClass obj3 = move(obj1);
	obj3.print();

	cout << endl << endl;

	Point p1(1, 1);
	Point p2(2, 4);
	Point p3 = p1 + p2;
	p3.print();

	cout << endl << endl;

	CopyClass c1(10);
	c1.print();

	CopyClass c2 = c1;
	c2.print();

	return 0;
}