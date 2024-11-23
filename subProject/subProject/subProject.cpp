#include <iostream>
#include <iomanip>
#include <vector>
#include <string>

using namespace std;


//Sa se scrie o aplicatie care sa calculeze cine iasa presedinte 
// in functie de raspunsurile citite de la tastaura (o sa folosim 5 candidati) si 
// sa ne afiseze procentul castigat de fiecare.


void presedinte() {
    const char* candidati[]{ "candidat1", "candidat2", "candidat3", "candidat4", "candidat5" };
    int nrVoturi[5]{ 0 };
    int nrTotal = 0;
    cout << "Cu cine votati? Introduceti numele candidatului sau 'stop' pentru a opri:\n";
    for (int i = 0; i < 5; i++) {
        cout << candidati[i] << " ";
    }
    cout << endl;
    char raspuns[100];
    while (cin >> raspuns && strcmp(raspuns, "stop") != 0) {
        bool votValid = false;
        for (int i = 0; i < 5; i++) {
            if (strcmp(raspuns, candidati[i]) == 0) {
                nrVoturi[i]++;
                votValid = true;
                break;
            }
        }
        if (votValid) {
            nrTotal++;
        }
    }
    cout << "\nRezultate:\n";
    for (int i = 0; i < 5; i++) {
        cout << candidati[i] << " are urmatorul procent: ";
        if (nrTotal > 0) {
            float procent = (float)nrVoturi[i] / nrTotal * 100;
            cout << fixed << setprecision(2)<< procent << "%\n";
        }
        else {
            cout << "0%\n";
        }
    }
}

//Sa se scrie o aplicatie care sa aiba toate informatiile unei biblioteci:
//- sa fie impartita pe categorii beletristca / dezvoltare personala / programare
//- fiecare  categorie sa aiba cateva carti stabilite de voi si fiecare carte sa fie pe un rand si un raft
//Ex : beletristica randul 1, 2 si 3 cartea Dama cu camelii se afla pe randul 1 raftul 3

//Cand vreau sa imprumut o carte sa imi spuna exact unde se afla cartea categorie rand raft
//Sa verificam daca avem cartea in biblioteca(1.avem cartea / nu aveam aceasta carte, 2.este disponibila / cartea este la altcineva)
//Cand vreau sa returnez o carte pe care am imprumutat o sa imi spuna unde sa o las si sa apara din nou disponibila in biblioteca ca altcineva sa o poata lua.


struct Carte {
    string titlu;
    int rand;
    int raft;
    bool disponibila; 
};

struct Categorie {
    string nume;
    vector<Carte> carti;
};


vector<Categorie> biblioteca;

void addCat(string nume) {
    Categorie categorie;
    categorie.nume = nume;
    biblioteca.push_back(categorie);
}

void addBook(string categorie, string titlu, int rand, int raft) {
    Carte carte = { titlu,rand, raft,true };
    for (Categorie& cat : biblioteca) {
        if (cat.nume == categorie) {
            cat.carti.push_back(carte);
            return;
        }
    }
}

Carte* searchBook(string titlu) {
    for (Categorie& cat : biblioteca) {
        for (Carte& carte : cat.carti) {
            if (carte.titlu == titlu)
                return &carte;
        }
    }
    return nullptr;
}

void imprumutaCarte(string titlu) {
    Carte* carte = searchBook(titlu);
    if (carte) {
        if (carte->disponibila) {
            cout << "\nCartea "<<carte->titlu<<" este disponibila\n";
            cout << "Va rugam sa luati cartea de la randul " << carte->rand << " raftul " << carte->raft << "\n";
            carte->disponibila = false;
        }
        else
            cout << "\nCartea "<<carte->titlu<<" este imprumutata\n";
    }
    else {
        cout << "\nCartea "<<titlu<<" nu se afla in biblioteca\n";
    }
}


void returneazaCarte(string titlu) {
    Carte* carte = searchBook(titlu);
    if (carte) {
        if (!carte->disponibila) {
            cout << "\nCartea " << titlu << " a fost returnata.\n";
            cout << "Va rugam sa o asezati la randul " << carte->rand << " raftul " << carte->raft << "\n";
            carte->disponibila = true;
        }
        else {
            cout << "\nCartea " <<titlu<<" a fost returnata deja\n";
        }
    }
    else
    {
        cout << "\nCartea " << titlu << " nu se afla in biblioteca\n";
    }
}

int main()
{
   // presedinte();
    addCat("Beletristica");
    addCat("Dezvoltare Personala");
    addCat("Programare");

    addBook("Beletristica", "Dama cu camelii", 1, 3);
    addBook("Beletristica", "Ion", 1, 1);
    addBook("Dezvoltare Personala", "Atomic Habits", 2, 2);
    addBook("Programare", "Clean Code", 3, 1);

    imprumutaCarte("Ion");
    imprumutaCarte("Clean Code");

    returneazaCarte("Ion");
    imprumutaCarte("Cartea care nu exista");
    returneazaCarte("Dama cu camelii");

    return 0;
}

