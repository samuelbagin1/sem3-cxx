// Tema: Uniformna inicializacia
// Autor: Pavol Marak

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

// Agregovany typ,
// Nesmie mat user-defined konstruktory
// a private/protected cleny.
struct S {
    int num;
};

// Ne-agregovany typ.
class C {
    int num;
public:
    C() : num(0) {}
    C(int a) : num(a) {}
};

// funkcia, ktora ma na vstupe objekt triedy C
void fn1(C c) {
}

// funkcia, ktora vracia objekt triedy C
C fn2() {
    // return C(1); // stara syntax
    return {1};
}

// funkcia, ktora vracia smernik na dynamicke pole objektov triedy C
C *fn3() {
    return new C[3]{{1},
                    {2},
                    {3}};
}

// POZNAMKA: tento program si otestujte v Debug rezime
// pretoze tento kod nie je vizualizovany vypisom do konzoly

int main() {

    // STARA SYNTAX pred jazykovym standardom C++11
    // .....................................................
    // Zmyslom tejto ukazky je poukazat, ze rozne datove typy mohli
    // byt inicializovane pomocou roznych (nejednotnych) zapisov

    // inicializacia zakladnych (built-in) typov
    int num1;
    int num2 = 10;
    int num3(10);

    // agregovany typ (pole a struktura)
    int pole[4] = {1, 2, 3, 4};
    S s1;
    S s2 = {5};
    S s3[] = {{1},
              {2}};

    // ne-agregovany typ (trieda s private clenom a konstruktorom)
    C c1; // default konstruktor
    C c2(3); // parametricky konstruktor
    C c3 = 4; // konverzny konstruktor
    C c4 = c3; // copy konstruktor


    // NOVA C++11 SYNTAX
    // Zmyslom tejto ukazky je demonstrovat konzistentny (uniformny)
    // zapis inicializacie roznych datovych typov v C++11 pomocou
    // zatvoriek { }

    // zakladny (built-in) typ
    int num1n{}; // zero-inicializacia
    int num2n{10};

    // agregovany typ (pole a struktura)
    int polen[4]{1, 2, 3, 4};
    S s1n{};
    S s2n{5};
    S s3n[]{{1},
            {2}};

    // neagregovany typ
    C c1n{};
    C c2n{3};
    C c4n{c3};

    // dynamicke pole
    C *dyn_pole = new C[3]{{1},
                           {2},
                           {3}};

    // inicializacia argumentov funkcie
    // fn1(C(1));
    fn1({1});

    // inicializacia pri navrate objektov
    C result{fn2()};
    C *result_array{fn3()};

    return 0;
}
