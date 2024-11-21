// Tema: Range-based for cyklus
// Autor: Pavol Marak

// Poznamky:
//
// Range-based (alebo aj rozsahovy) for cyklus je alternativna
// skratena syntax pre for cyklus, ktory sluzi na prechod
// kontajnerom alebo polom.

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <utility>

using namespace std;

// testovacia funkcia pre range-based for cyklus
void test_range_based_for_cyklus() {
    int pole[]{1, 2, 3, 4, 5};
    vector<int> v{100, 200, 300, 400, 500};
    map<string, string> m{
            {"aaa", "AAA"},
            {"bbb", "BBB"},
            {"ccc", "CCC"},
    };

    // range-based for cyklus na prechod polom (by value)
    cout << "Range-based for cyklus na prechod polom (by value):" << endl;
    for (int i : pole) {
        cout << " " << i;
        // premennu 'i' mozeme zmenit, ale v poli sa ziadna hodnota nezmeni,
        // nakolko 'i' je kopia prvku pola
    }

    // range-based for cyklus na prechod vektorom (by value)
    cout << endl << endl << "Range-based for cyklus na prechod vektorom (by value):" << endl;
    for (int i : v) {
        cout << " " << i;
        // premennu 'i' mozeme zmenit, ale vo vektore sa ziadna hodnota nezmeni,
        // nakolko 'i' je kopia prvku kontajnera
    }

    // range-based for cyklus na prechod mapou (by value)
    cout << endl << endl << "Range-based for cyklus na prechod mapou (by value):" << endl;
    for (pair<const string, string> p : m) {
        cout << " (" << p.first << "," << p.second << ")";
        // premennu 'p' mozeme zmenit, ale v mape sa ziadna hodnota nezmeni,
        // nakolko 'p' je kopia prvku kontajnera
    }

    // range-based for cyklus na prechod braced-init-listom (by value)
    cout << endl << endl << "Range-based for cyklus na prechod braced-init-listom (by value):" << endl;
    for (int i : {5, 10, 15, 20}) {
        cout << " " << i;
        // premennu 'i' mozeme zmenit, ale v braced-init-liste sa ziadna hodnota nezmeni,
        // nakolko 'i' je kopia prvku braced-init-listu
    }

    // range-based for cyklus na prechod mapou (by reference)
    cout << endl << endl << "Range-based for cyklus na prechod mapou (by reference):" << endl;
    for (pair<const string, string> &p : m) {
        p.second = "---"; // modifikacia prvku kontajnera
        cout << " (" << p.first << "," << p.second << ")";
        // premennu 'p' mozeme zmenit a zmena sa prejavi aj v kontajneri
    }

    // range-based for cyklus a premenna typu 'auto'
    // ak sa chceme vyhnut pisaniu komplikovanych datovych typov
    // mozeme pouzit typ 'auto' a kompilator sam vydedukuje
    // datovy typ z inicializacneho zapisu
    for (auto &p : m) {
        // ... kod
    }

    cout << endl << endl;
}

int main() {
    cout << endl << "Range-based for cyklus" << endl;
    cout << "........................." << endl << endl;
    test_range_based_for_cyklus();
    return 0;
}
