// Tema: std::initializer_list
// Autor: Pavol Marak

// Poznamky:
//
// Trieda 'initializer_list' reprezentuje zoznam
// objektov rovnakeho typu, ktory sa vytvori pomocou
// zatvoriek {...}. V triede si mozeme zadefinovat
// vlastny konstruktor akceptujuci inicializacny zoznam
// a pomocou neho vieme inicializovat atributy triedy.
// Je definovana v hlavickovom subore <initializer_list>.

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <string>
#include <initializer_list>

using namespace std;

// funkcia, ktora ma ako argument inicializacny zoznam stringov
void fn(const initializer_list<string> &init_list) {
    cout << endl << "Vypis inicializacneho zoznamu (vo funkcii):" << endl;
    for (string s : init_list) {
        cout << " " << s << endl;
    }
}

// trieda, ktora ma zadefinovany konstruktor s inicializacnym zoznamom
class MyVector {
    vector<string> v;
public:
    // parametricky konstruktor
    MyVector(string s) {}

    // initializer_list konstruktor
    MyVector(const initializer_list<string> &init_list)
            : v{init_list} {}
};

// testovacia funkcia pre initializer_list
void test_initializer_list() {

    // konstrukcia prazdneho initializer_listu
    initializer_list<string> init_list{"C++", "Python", "Java", "Fortran"};; // inicializacny zoznam stringov

    // ziskanie velkosti inicializacneho zoznamu
    cout << "Velkost inicializacneho zoznamu: " << init_list.size() << endl;

    // prechod inicializacnym zoznamom
    cout << endl << "Vypis inicializacneho zoznamu:" << endl;
    for (string s : init_list) {
        cout << " " << s << endl;
    }

    // alternativny prechod inicializacnym zoznamom

    //    for(auto it = init_list.begin();it!=init_list.end();it++){
    //        cout << " " << *it << endl;
    //    }

    // funkcia, ktora ma na vstupe initializer_list
    fn(init_list);
    fn({"str1", "str2", "str3"});

    // zavolanie konstruktora objektu, ktory ma na vstupe initializer_list
    MyVector my_vector{init_list};
    MyVector my_vector2{"s1", "s2", "s3", "s4"};
    MyVector my_vector3 = {"s1", "s2", "s3", "s4"};

    // ako zavolame parametricky konstruktor triedy MyVector?
    MyVector my_vector4("hodnota");
}

int main() {
    cout << endl << "Trieda initializer_list" << endl;
    cout << "........................." << endl << endl;
    test_initializer_list();
    cout << endl;
    return 0;
}
