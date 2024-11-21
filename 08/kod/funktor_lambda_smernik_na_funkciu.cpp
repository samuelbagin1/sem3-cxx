// Temy:
//  * smernik na funkciu
//  * funktor
//  * lambda vyraz
//
// Autor: Pavol Marak
// Zdroj: https://docs.microsoft.com/en-us/cpp/cpp/lambda-expressions-in-cpp?view=vs-2019

// Poznamky:
//
// * Smernik na funkciu: je to premenna, ktora uchovava
//   adresu funkcie (tymto sposobom mozeme odovzdavat
//   funkcie ako parametre do inych funkcii)
// * Funktor: je to trieda, ktora sa chova ako funkcia, t.j.
//   ma pretazeny operator volania funkcie ()
// * Lambda vyraz: je to anonymny funktor (netreba kvoli nej
//   vytvarat definiciu triedy) a je schopny zachytavat premenne
//   z okolia (scope, v ktorom je pouzita). Tymto sposobom vieme
//   zadefinovat funktor priamo na mieste, kde je pouzity.

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>

using namespace std;

void moja_funkcia1(int a) {
    cout << "Moja funkcia 1 : " << a << endl;
}

void moja_funkcia2(int a) {
    cout << "Moja funkcia 2 : " << a << endl;
}

// definicia vlastneho funktora
class MyFunctor {
    int x;
public:
    MyFunctor() : x{} {} // default konstruktor
    MyFunctor(int val) : x{val} {} // param. konstruktor
    // pretazujeme operator volania funkcie ()
    int operator()(int y) {
        return x + y;
    }
};

// vstupom do tejto funkcie je smernik na funkciu
// s nazvom 'fun_ptr', ktory ukazuje na funkciu,
// ktora nic nevracia a ma jeden parameter typu int
void vykonaj_funkciu(int a, void(*fun_ptr)(int)) {
    fun_ptr(a);
}

// testovacia funkcia pre smernik na funkciu
void test_ptr_to_fun() {
    // do funkcie 'vykonaj_funkciu' mozeme
    // odovzdat adresu akejkolvek funkcie,
    // ktora je typu 'void' a vracia jeden 'int'
    vykonaj_funkciu(5, moja_funkcia1);
    vykonaj_funkciu(10, moja_funkcia2);

    cout << endl;

    // mozeme definovat aj pole smernikov na funkciu
    void (*fun_ptr_arr[])(int) = {moja_funkcia1, moja_funkcia2};
    for (size_t i = 0; i < sizeof(fun_ptr_arr) / sizeof(fun_ptr_arr[0]); i++) {
        vykonaj_funkciu(i, fun_ptr_arr[i]);
    }
}

// testovacia funkcia pre funktor
void test_functor() {
    // vytvorenie funktora
    MyFunctor mf{3};
    // pouzitie funktora
    cout << endl << "Zavolanie funktora: " << mf(4) << endl;
}

// testovacia funkcia pre lambda vyraz
void test_lambda() {
    int a{12};
    int b{4};
    int c{1};
    cout << endl;

    // lambda vyraz, ktory nic nerobi, nic nechyta a nema parametre
    auto lambda1 = []() {};
    lambda1();

    // lambda vyraz, ktory nema parametre a chyta vsetky okolite premenne by-value
    auto lambda2 = [=]() { cout << "Hello from lambda2: " << a << endl; };
    lambda2();

    // lambda vyraz, ktory nema parametre a chyta vsetky okolite premenne by-reference
    auto lambda3 = [&]() { cout << "Hello from lambda3: " << ++a << endl; };
    lambda3();

    // lambda vyraz, ktory ma jeden 'int' parameter a chyta premennu 'c' by-value, ostatne chyta by-reference
    auto lambda4 = [&, c](int arg) { cout << "Hello from lambda4: " << b + c + arg << endl; };
    lambda4(10);

    // lambda sa da taktiez odovzdat do funkcie ako parameter
    vykonaj_funkciu(2, [](int arg) { cout << "This is lambda with parameter: " << arg << endl; });
}

int main() {
    cout << endl << "Smernik na funkciu, funktor a lambda vyraz" << endl;
    cout << ".........................................." << endl << endl;
    test_ptr_to_fun();
    test_functor();
    test_lambda();

    return 0;
}
