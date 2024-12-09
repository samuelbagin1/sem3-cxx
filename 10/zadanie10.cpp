/*
Meno a priezvisko:  samuelbagin

POKYNY:
(1)  Implementujte funkcie tak, aby splnali popis pri ich deklaraciach.
(2)  Cela implementacia musi byt v tomto jednom subore.
(3)  Odovzdajte len tento zdrojovy subor (s vypracovanymi rieseniami).
(4)  Program musi byt kompilovatelny.
(5)  Globalne a staticke premenne su zakazane.
(6)  V ziadnom pripade nemente deklaracie funkcii, ktore mate za ulohu naprogramovat
     (nemente nazvy, navratove hodnoty, ani typ a pocet parametrov v zadanych funkciach).
     Nemente implementacie zadanych datovych typov, ani implementacie hotovych pomocnych funkcii
     (ak nie je v zadani ulohy uvedene inak).
(7)  V pripade potreby mozete kod doplnit o dalsie pomocne funkcie alebo datove typy.
(8)  Vase riesenie otestujte (vo funkcii 'main' a pomocou doplnenych pomocnych funkcii alebo datovych typov).
     Testovaci kod ale nebude hodnoteny.
(9)  Funkcia 'main' musi byt v zdrojovom kode posledna.
*/


#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <stack>
#include <set>
#include <deque>
#include <limits>
#include <vector>
#include <cctype> // For std::isupper

using namespace std;

//-------------------------------------------------------------------------------------------------
// 1. ULOHA (0.4 bodu)
//-------------------------------------------------------------------------------------------------
/*
    Upravte definiciu metody 'T::met()' tak, aby informovala, ze metoda nemeni stav objektu.

    Pre kontrolu odkomentujte riadok v testovacej funkcii. Odkomentovany riadok musi byt kompilovatelny.
*/

class T {
public:
    void met() const {}
};

void testUloha1() {
    cout << "----- 1. uloha (metoda nemeni stav objektu) ------------------------------------" << endl;
    const T o;
    // o.met(); // odkomentujte
}

//-------------------------------------------------------------------------------------------------
// 2. ULOHA (0.4 bodu)
//-------------------------------------------------------------------------------------------------
/*
    Upravte definiciiu konstruktora tak, aby bol konverznym konstruktorom.

    Zakomentovane riadky v testovacom kode musia byt kompilovatelne.
*/

class Number {
private:
    int number;
public:
    Number (int value) : number(value){
    }

    int getValue() const {
        return number;
    }
};

void fun(Number n) {
    cout << n.getValue() << endl;
}

void testUloha2() {
    cout << "----- 2. uloha (konverzny konstruktor) -----------------------------------------" << endl;

    // Number a = 10; // ak existuje zodpovedajuci konverzny konstruktor, tak je tento riadok kompilovatelny
    // cout << a.getValue() << endl;

    // fun(20); // ak existuje zodpovedajuci konverzny konstruktor, tak je tento riadok kompilovatelny
}

//-------------------------------------------------------------------------------------------------
// 3. ULOHA (0.4 bodu)
//-------------------------------------------------------------------------------------------------
/*
    Vytvorte triedu 'B', ktora je podtriedou triedy 'A'.
    Upravte definiciu metody 'A::met()' a definujte metodu 'B::met()' tak,
    aby bol testovaci kod po odkomentovani uspesne vykonany (aby bola vzdy volana spravna metoda).
*/

class A {
public:
    virtual char met() const {
        return 'a';
    }
};

class B: public A {
public:
    char met() const override{
        return 'b';
    }
};

void testUloha3() {
    cout << "----- 3. uloha (volanie spravnej metody) ---------------------------------------" << endl;

    A a;
    // B b;

    // A *pa  = &a;
    // A *pab = &b;
    // B* pb  = &b;

    // assert(pa->met()  == 'a'); // volanie A::met()
    // assert(pab->met() == 'b'); // volanie B::met()
    // assert(pb->met()  == 'b'); // volanie B::met()
}

//-------------------------------------------------------------------------------------------------
// 4. ULOHA (0.4 bodu)
//-------------------------------------------------------------------------------------------------
/*
    Upravte definicie destruktorov tried 'C' a 'D' tak, aby sa v testovacej funkcii zavolal spravny destruktor.
    Testovacia funkcia musi namiesto:
        C::~C()
    po uprave vypisat:
        D::~D()
        C::~C()
*/

class C {
public:
    virtual ~C() {
        cout << "C::~C()" << endl;
    }
};

class D : public C {
public:
    ~D() override{
        cout << "D::~D()" << endl;
    }
};

void testUloha4() {
    cout << "----- 4. uloha (volanie spravneho destruktora) ---------------------------------" << endl;
    C *obj = new D;
    delete obj; // aby sa zavolal spravny detruktor
}

//-------------------------------------------------------------------------------------------------
// 5. ULOHA (0.4 bodu)
//-------------------------------------------------------------------------------------------------
/*
    Vytvorte operator +=, ktory bude sluzit pre pripocitanie druheho komplexneho cisla ku prvemu.
    Operator definujte ako clena triedy.

    Pre kontrolu odkomentujte riadky v testovacom kode, kde je priklad pouzitia operatora.
*/

class Complex {
private:
    int real;
    int imaginary;
public:
    Complex(int realPart, int imaginaryPart) : real(realPart), imaginary(imaginaryPart) {
    }

    int getRealPart() const {
        return real;
    }
    int getImaginaryPart() const {
        return imaginary;
    }

    Complex& operator+=(const Complex& other) {
        real+=other.real;
        imaginary+=other.imaginary;
        return *this;
    }
};

void testUloha5() {
    cout << "----- 5. uloha (operator +=) ---------------------------------------------------" << endl;

    Complex a(1,2);
    Complex b(10, 20);
    Complex c(100, 200);

    // c += b += a;

    // assert(a.getRealPart() == 1);
    // assert(a.getImaginaryPart() == 2);
    // assert(b.getRealPart() == 11);
    // assert(b.getImaginaryPart() == 22);
    // assert(c.getRealPart() == 111);
    // assert(c.getImaginaryPart() == 222);
}

//-------------------------------------------------------------------------------------------------
// 6. ULOHA (0.4 bodu)
//-------------------------------------------------------------------------------------------------
/*
    Vytvorte operator <<, ktory zapise hodnotu objektu triedy 'Complex' (z predchadzajuceho prikladu)
    do textoveho prudu dat.
    Poznamka: Operator musi byt definovany ako globalny.

    Pre kontrolu odkomentujte riadky v testovacom kode.
*/

ostream& operator<<(ostream& os, const Complex& c) {
    int real=c.getRealPart();
    int imaginary=c.getImaginaryPart();

    os << real;

    if (imaginary >= 0) {
        os << "+";
    }

    os << imaginary << "i";
    return os;
}

void testUloha6() {
    cout << "----- 6. uloha (operator << ) --------------------------------------------------" << endl;

    Complex a( 1, 2);
    Complex b(-3,-4);
    // cout << "a = " << a << ", b = " << b << endl;

    // ostringstream stream;
    // stream << a << " " << b;
    // assert(stream.str() == "1+2i -3-4i");
}

//=================================================================================================
// STROM - definicia pre dalsie ulohy
//=================================================================================================

// Uzol stromu
struct Node {
    char value; // hodnota uzla
    list<Node*> children; // zoznam nasledovnikov

    explicit Node(char value) : value(value) {}
};

// Strom
struct Tree {
    Node * root; // koren stromu

    explicit Tree(Node *root = nullptr) : root(root) {}
};

//-------------------------------------------------------------------------------------------------
// 7. ULOHA (0.4 bodu)
//-------------------------------------------------------------------------------------------------
/*
    Funkcia vrati zoznam vsetkych hodnot uzlov v strome 'tree', ktorych hodnotou je velke pismeno.
    Pouzite algoritmus hladania DO HLBKY.
    Pouzite iterativnu implementaciu.
    Doporucenie: pre identifikaciu velkych pismen pouzite funkciu 'std::isupper'

    VSTUPNA HODNOTA:
        [in] tree - prehladavany strom

    NAVRATOVA HODNOTA:
        zoznam velkych pismen, ktore su hodnotami uzlov v strome 'tree'

    VYSTUPNA PODMIENKA:
        Poradie vo vystupnom zozname musi zodpovedat postupnosti prehladavania algoritmom DO HLBKY.

    PRIKLAD:
        na obrazku
*/


list<char> depthFirstSearchUpperCases(const Tree *tree) {
    list<char> result;
    if(!tree || !tree->root) { return result; }

    stack<Node *> stackNode;
    stackNode.push(tree->root);


    // budeme listovat pokial nebude stack prazdny
    while(!stackNode.empty()){
        Node *current = stackNode.top();
        stackNode.pop();

        // ak je upper pridame do stacku
        if(std::isupper(current->value)){
            result.push_back(current->value);
        }

        // ak bude lsit v navrchu stacku prazdny, nebudeme loopovat
        for(Node *child : current->children) {
            stackNode.push(child);
        }
    }

    return result;
}

//-------------------------------------------------------------------------------------------------
// 8. ULOHA (0.4 bodu)
//-------------------------------------------------------------------------------------------------
/*
    Funkcia vrati zoznam vsetkych hodnot uzlov v strome 'tree', ktorych hodnotou je velke pismeno.
    Pouzite algoritmus hladania DO SIRKY.
    Pouzite iterativnu implementaciu.
    Doporucenie: pre identifikaciu velkych pismen pouzite funkciu 'std::isupper'

    VSTUPNA HODNOTA:
        [in] tree - prehladavany strom

    NAVRATOVA HODNOTA:
        zoznam velkych pismen, ktore su hodnotami uzlov v strome 'tree'

    VYSTUPNA PODMIENKA:
        Poradie vo vystupnom zozname musi zodpovedat postupnosti prehladavania algoritmom DO SIRKY.

    PRIKLAD:
        na obrazku
*/

list<char> breadthFirstSearchUpperCases(const Tree *tree) {
    // If the tree is empty, return an empty list
    if (!tree || !tree->root) {
        return list<char>();
    }

    // List to store uppercase letters
    list<char> uppercaseLetters;

    // Queue for iterative BFS
    queue<Node*> nodeQueue;
    nodeQueue.push(tree->root);

    // Iterative breadth-first search
    while (!nodeQueue.empty()) {
        // Get the front node from the queue
        Node* currentNode = nodeQueue.front();
        nodeQueue.pop();

        // Check if the current node's value is an uppercase letter
        if (std::isupper(currentNode->value)) {
            uppercaseLetters.push_back(currentNode->value);
        }

        // Add children to the queue
        for (Node* child : currentNode->children) {
            nodeQueue.push(child);
        }
    }

    return uppercaseLetters;
}

//=================================================================================================
// GRAF - definicia pre dalsie ulohy
//=================================================================================================
// Graf reprezentuje cestnu siet medzi obcami na planete.
// Uzol grafu reprezentuje obec.
// Hrana grafu reprezentuje "priame" cestne spojenie z jednej obce do druhej.
// Graf je orientovany - Hrana grafu reprezentuje moznost jazdy len jednym smerom.
//   Preto je moznost "priamej" jazdy medzi obcami oboma smermy reprezentovana dvoma hranami grafu.
// Graf je ohodnoteny - Mapa cestnej siete eviduje dlzky "priamych" cestnych spojeni medzi obcami.
// Obce nemusia byt prepojene cestnou sietou, napriklad ak sa nachadzaju na roznych pevninach.

// Forward deklaracie su potrebne, pretoze:
//  - definicie 'City' a 'RoadTo' su cyklicky zavisle:
//      - v definicii 'City' je pouzite 'RoadTo'
//      - a v definicii 'RoadTo' je pouzite 'City'
//  - definicie 'City' a 'SearchData' su cyklicky zavisle:
//      - v definicii 'City' je pouzite 'SearchData'
//      - a v definicii 'SearchData' je pouzite 'City'
struct RoadTo;
struct City;

// Udaje pouzite v algoritmoch hladania
struct SearchData {
    // Mozete si doplnit dalsie atributy a metody, ktore pouzijete v algoritmoch hladania
    bool discovered;
    unsigned distance;
    const City *previous;
    bool foundShortestPath;

    void clear() { // nastavi na implicitne hodnoty (tuto metodu mozete upravit (ale nie jej deklaracnu cast - nedoplnajte parametre))
        discovered = false;
        distance = numeric_limits<unsigned>::max();
        previous = nullptr;
        foundShortestPath = false;
    }
};

// Obec (uzol grafu)
struct City {
    string name; // nazov obce
    list<RoadTo> roads; // zoznam "priamych" jednosmernych cestnych spojeni do dalsich obci (zoznam vystupnych hran z tohto uzla grafu)

    SearchData searchData; // udaje pouzite v algoritmoch hladania

    // Mozete doplnit dalsi konstruktor alebo metody, ale tento konstruktor nemente
    explicit City(string name) : name(move(name)) {
        searchData.clear();
    };
};

// Jednosmerne "priame" cestne spojenie do dalsej obce (orientovana, ohodnotena hrana grafu)
struct RoadTo {
    City *city; // obec, do ktorej je toto "priame" cestne spojenie
    unsigned length; // dlzka tohto "priameho" spojenia

    // Mozete doplnit dalsi konstruktor alebo metody, ale tento konstruktor nemente
    RoadTo(City *city, unsigned length)
    : city(city)
    , length(length) {
    }
};

// Cestna mapa planety (orientovany, ohodnoteny graf)
struct Planet {
    list<City> cities; // zoznam obci na planete (zoznam vrcholov grafu)

    void clearSearchData() { // inicializuje atributy pouzite v algoritme hladania
        for(City &c : cities) {
            c.searchData.clear();
        }
    }
};

// Vyminka v pripade neexistencie obce so zadanym nazvom
class CityNotExistsException : exception {
    string cityName; // nazov obce
public:
    explicit CityNotExistsException(string name)
    : cityName(move(name)) {
    }
    const char * what() const noexcept override { // vrati nazov neexistujucej obce
        return cityName.c_str();
    }
};

//-------------------------------------------------------------------------------------------------
// 9. ULOHA (0.4 bodu)
//-------------------------------------------------------------------------------------------------
/*
    Funkcia vrati zoznam nazvov vsetkych obci na planete 'planet',
    ktore su z obce s nazvom 'startCity' dosiahnutelne pomocou cestnej siete.
    Pouzite algoritmus hladania DO SIRKY.

    VSTUPNA HODNOTA:
        [in] planet - cestna siet na planete
        [in] startCity - nazov obce

    NAVRATOVA HODNOTA:
        zoznam nazvov vsetkych obci, dosiahnutelnych z obce 'startCity'

    VYNIMKA:
        CityNotExistsException - ak na planete 'planet' neexistuje obec s nazvom 'startCity'.
        Metoda 'CityNotExistsException::what()' vrati nazov neexistujucej obce (hodnota 'startCity').

    VYSTUPNE PODMIENKY:
        Vystupny zoznam obsahuje aj 'startCity'.
        Poradie vo vystupnom zozname musi zodpovedat postupnosti prehladavania algoritmom DO SIRKY.

    PRIKLAD:
        na obrazku

    POZNAMKA:
        Ak v implementacii pouziteje 'City::searchData',
        tak bude pravdepodobne potrebne na zaciatku zavolat 'planet->clearSearchData()',
        aj aby bolo osetrene viacnasobne volanie algoritmu s tym istym objektom 'planet'.
*/

list<string> breadthFirstSearchReachable(Planet * planet, const string & startCity) {
    // Clear search data to ensure clean state
    planet->clearSearchData();

    // Find the start city
    auto startCityIt = find_if(planet->cities.begin(), planet->cities.end(),
                               [&startCity](const City& city) { return city.name == startCity; });

    // Throw exception if start city doesn't exist
    if (startCityIt == planet->cities.end()) {
        throw CityNotExistsException(startCity);
    }

    // List to store reachable city names
    list<string> reachableCities;

    // Queue for BFS
    queue<City*> cityQueue;

    // Mark and enqueue the start city
    startCityIt->searchData.discovered = true;
    cityQueue.push(&(*startCityIt));
    reachableCities.push_back(startCity);

    // Perform BFS
    while (!cityQueue.empty()) {
        City* currentCity = cityQueue.front();
        cityQueue.pop();

        // Explore all roads from current city
        for (const RoadTo& road : currentCity->roads) {
            // If the destination city hasn't been discovered
            if (!road.city->searchData.discovered) {
                // Mark as discovered
                road.city->searchData.discovered = true;

                // Add to queue and reachable cities list
                cityQueue.push(road.city);
                reachableCities.push_back(road.city->name);
            }
        }
    }

    return reachableCities;
}

//-------------------------------------------------------------------------------------------------
// 10. ULOHA (0.4 bodu)
//-------------------------------------------------------------------------------------------------
/*
    Funkcia najte dlzky najkratsich ciest z obce 'startCity' do vsetkych dosiahnutelnych obci.
    Pouzite Dijkstrov algoritmus.

    VSTUPNE HODNOTY:
        [in] planet - cestna siet na planete
        [in] startCity - nazov obce

    NAVRATOVA HODNOTA:
        Pre kazdu obec dosiahnutelnu zo 'startCity' (na planete 'planet') obsahuje dlzku najkratsej cesty zo 'startCity'.

    VYNIMKA:
        CityNotExistsException - ak na planete 'planet' neexistuje obec s nazvom 'startCity'.
        Metoda 'CityNotExistsException::what()' vrati nazov neexistujucej obce (hodnota 'startCity').

    VYSTUPNA PODMIENKA:
        Navratova hodnota obsahuje nazvy len tych miest, ktore su dosiahnutelne zo 'startCity'.
        Navratova hodnota obsahuje aj vzdialenost do 'startCity' (nula).

    PRIKLAD:
        na obrazku

    POZNAMKA:
        Ak v implementacii pouziteje 'City::searchData',
        tak bude pravdepodobne potrebne na zaciatku zavolat 'planet->clearSearchData()',
        aj aby bolo osetrene viacnasobne volanie algoritmu s tym istym objektom 'planet'.
*/

map<string, unsigned> dijkstra(Planet * planet, const string & startCity) {
    // Clear search data to ensure clean state
    planet->clearSearchData();

    // Find the start city
    auto startCityIt = find_if(planet->cities.begin(), planet->cities.end(),
                               [&startCity](const City& city) { return city.name == startCity; });

    // Throw exception if start city doesn't exist
    if (startCityIt == planet->cities.end()) {
        throw CityNotExistsException(startCity);
    }

    // Map to store shortest distances
    map<string, unsigned> shortestDistances;

    // Priority queue for Dijkstra's algorithm
    // Uses min-heap to always get the city with minimum distance
    priority_queue <pair<unsigned, City*>, vector<pair<unsigned, City*>>, greater<pair<unsigned, City*>>> pq;

    // Initialize start city
    startCityIt->searchData.distance = 0;
    pq.push({0, &(*startCityIt)});

    // Dijkstra's algorithm
    while (!pq.empty()) {
        // Get city with minimum distance
        unsigned currentDistance = pq.top().first;
        City* currentCity = pq.top().second;
        pq.pop();

        // Skip if we've already found a shorter path
        if (currentDistance > currentCity->searchData.distance) {
            continue;
        }

        // Add current city to shortest distances
        shortestDistances[currentCity->name] = currentDistance;

        // Explore roads from current city
        for (const RoadTo& road : currentCity->roads) {
            // Calculate potential new distance
            unsigned newDistance = currentDistance + road.length;

            // Update if new path is shorter
            if (newDistance < road.city->searchData.distance) {
                road.city->searchData.distance = newDistance;
                road.city->searchData.previous = currentCity;
                pq.push({newDistance, road.city});
            }
        }
    }

    return shortestDistances;
}

//-------------------------------------------------------------------------------------------------
// TESTOVANIE
//-------------------------------------------------------------------------------------------------

// tu mozete doplnit pomocne funkcie a struktury

int main() {
    testUloha1();
    testUloha2();
    testUloha3();
    testUloha4();
    testUloha5();
    testUloha6();

    // tu mozete doplnit testovaci kod

    return 0;
}
