/*
Meno a priezvisko:  Samuel Bagin

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
#include <cstring>

using namespace std;

//-------------------------------------------------------------------------------------------------
// DATOVE TYPY
//-------------------------------------------------------------------------------------------------

// Uzol zretazeneho zoznamu
struct Node {
    int data; // hodnota uzla
    Node* next; // smernik na dalsi uzol zoznamu
};

// Zretazeny zoznam
struct List {
    Node* first; // smernik na prvy uzol zoznamu
};

//-------------------------------------------------------------------------------------------------
// 1. ULOHA (0.8 bodu)
//-------------------------------------------------------------------------------------------------
/*
    Funkcia usporiada pole 'data' od najvacsieho prvku po najmensi prvok.
    Pouzite algoritmus insertion sort.

    PARAMETRE:
        [in, out] data - pole, ktore funkcia usporiada
        [in] length    - pocet prvkov pola

    VSTUPNE PODMIENKY:
        'length' moze mat lubovolnu hodnotu
        'data' ukazuje na platne pole

    PRIKLADY:
        (1, 3, 2) -> (3, 2, 1)
        (1, 2, 2, 1) -> (2, 2, 1, 1)
        (1) -> (1)
        () -> ()
*/
//od vacsieho po mensie
void insertionSort(int *data, const size_t length) {
    for (size_t i=1; i<length; i++) {   //for loop dlzky pola, zaciname od 1 aby sme sa mohli posunut na 0-ty index
        int tmp=data[i];    //nakopirovanie cisla
        size_t p=i;         //ulozenie terajsieho indexu

        while (p>0 && data[p-1]<tmp) {  //ak je index vacsi ako 0 - kvoli preteceniu, a ak je cislo vlavo mensie,
            data[p]=data[p-1];          //posunieme data doprava
            --p;                        //a indexom sa posunieme o jedno dolava
        }
                                        //ak uz je cislo vlavo vacsie,
        data[p]=tmp;                    //hodime nakopirovanu hodnotu vpravo od vacsieho
    }
}

//-------------------------------------------------------------------------------------------------
// 2. ULOHA (0.8 bodu)
//-------------------------------------------------------------------------------------------------
/*
    Funkcia usporiada textove retazce v poli 'data' od najvacsieho prvku po najmensi (lexikograficky).
    Preusporiadajte smerniky v poli.
    Pouzite algoritmus insertion sort.

    PARAMETRE:
        [in, out] data - pole, ktore funkcia usporiada.
                Pole obsahuje smerniky na textove retazce.
                Kazdy textovy retazec je ukonceny '\0'.
                Posledny smernik ma hodnotu 'nullptr'. Podla toho urcite pocet prvkov pola (pocet textovych retazcov).

    VSTUPNE PODMIENKY:
        'data' obsahuje minimalne jeden smernik.
        Posledny smernik ma hodnotu 'nullptr'.

    PRIKLADY:
        ("Juraj", "Peter", "Andrej", nullptr) -> ("Peter", "Juraj", "Andrej", nullptr)
        ("Juraj", "Anabela", "Peter", "Andrej", nullptr) -> ("Peter", "Juraj", "Andrej", "Anabela", nullptr)
        ("Andrej", "Juraj", "Andrej", nullptr) -> ("Juraj", "Andrej", "Andrej", nullptr)
        ("Andrej", nullptr) -> ("Andrej", nullptr)
        (nullptr) -> (nullptr)

    POZNAMKY:
        Pri testovani mozete jednoducho pole vytvorit nasledovnym sposobom:
        const char *mena[] = {"Juraj", "Peter", "Andrej", nullptr};

        Na porovnanie obsahu textovych retazcov vyuzite prislusnu funkciu zo standardnej kniznice.
*/
void insertionSort(const char *data[]) {
    size_t length=0;
    while (data[length]!=nullptr) length++;   //najdenie dlzky pola

    for (size_t i=1; i<length; i++) {
        const char* tmp=data[i];
        size_t p=i;

        while (p>0 && strcmp(data[p-1],tmp)<0) {
            data[p]=data[p-1];
            --p;
        }

        data[p]=tmp;
    }
}

//-------------------------------------------------------------------------------------------------
// 3. ULOHA (0.8 bodu)
//-------------------------------------------------------------------------------------------------
/*
    Funkcia usporiada zretazeny zoznam 'list' od najvacsieho prvku po najmensi.
    Preusporiadajte uzly v zozname (nekopirujte hodnoty v uzloch).
    Pouzite algoritmus insertion sort.

    PARAMETRE:
        [in, out] list - zretazeny zoznam, ktory funkcia usporiada

    VSTUPNE PODMIENKY:
        'list' obsahuje lubovolny pocet uzlov (moze byt prazdny)
        'list' nie je 'nullptr'

    PRIKLADY:
        vstup: 2->1->3,        vystup: 3->2->1
        vstup: 1->2->2->1,     vystup: 2->2->1->1
        vstup: prazdny zoznam, vystup: prazdny zoznam
*/
void insertionSort(List * list) {
    //ak je list prazdny, dalej nepokracujeme
    if (list == nullptr || list->first == nullptr || list->first->next == nullptr) {
        return;
    }

    Node* sorted = nullptr; // sorted list / hlava listu
    Node* current = list->first; // node ktory nam sluzi na listovanie

    while (current != nullptr) {
        Node* next = current->next; // nakopirujeme si dalsi node

        if (sorted == nullptr || sorted->data <= current->data) {
            //ak je sorted list prazdny prida dalsie alebo ak sorted data su mensie ako current da na zaciatok
            current->next = sorted;
            sorted = current;

        } else {

            //najdi vyhovujuvu poziciu
            Node* search = sorted;
            while (search->next != nullptr && search->next->data > current->data) {
                //ak nasledujuce cislo je vacsie, ideme dalej v liste
                search = search->next;
            }

            current->next = search->next;
            search->next = current;
        }

        current = next; // Move to next node
    }

    list->first = sorted; // Update the head of the list
}

//-------------------------------------------------------------------------------------------------
// 4. ULOHA (0.8 bodu)
//-------------------------------------------------------------------------------------------------
/*
    Funkcia vykona algoritmus merge (cast algoritmu merge sort), ktory ma linearnu vypoctovu zlozitost.
    Kombinuje dve susedne, usporiadane casti v poli 'input', do jednej usporiadanej casti v poli 'output'.
    Usporiadanie je od najvacsieho prvku po najmensi prvok!

    PARAMETRE:
        [out] output - vystupne pole, ktoreho cast output[low]...output[high-1] bude po vykonani funkcie usporiadana
        [in]  input  - vstupne pole, ktoreho casti input[low]...input[middle-1] a input[middle]...input[high-1]
                         musia byt pri volani funkcie usporiadane od najvacsieho prvku po najmensi
        [in]  low    - index 1. prvku lavej usporiadanej casti pola 'input'
        [in]  middle - index 1. prvku pravej usporiadanej casti pola 'input'
        [in]  high   - index za poslednym prvkom pravej usporiadanej casti pola 'input'

    VYSTUPNE PODMIENKY:
        Obsah 'input' je nezmeneny.
        output[low] ... output[high-1] obsahuje usporiadane prvky z input[low] ... input[high-1].
        Prvky s indexami mensimi ako 'low' sa nemenia (ani v jednom poli).
        Prvky s indexami vacsimi alebo rovnymi ako 'high' sa nemenia (ani v jednom poli).

    PRIKLAD:
        low: 4
        middle: 8
        hight: 12
        input:                         (10, 10, 10, 10,  7,  5,  2,  0,  8,  4,  2,  1, 10, 10, 10, 10)
        output pred vykonanim funkcie: (20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20)
        output po vykonani funkcie:    (20, 20, 20, 20,  8,  7,  5,  4,  2,  2,  1,  0, 20, 20, 20, 20)
*/
void mergeNeighbours(int *output, const int *input, const size_t low, const size_t middle, const size_t high) {
    size_t in1=low;
    size_t in2=middle;
    size_t out=low;

    while (in1<middle && in2<high) {

        if (input[in1]>=input[in2]) {
            output[out]=input[in1];
            in1++;
        } else {
            output[out]=input[in2];
            in2++;
        }

        out++;
    }

    while (in1<middle) {
        output[out]=input[in1];
        out++;
        in1++;
    }
    while (in2<high) {
        output[out]=input[in2];
        out++;
        in2++;
    }
}

//-------------------------------------------------------------------------------------------------
// 5. ULOHA (0.8 bodu)
//-------------------------------------------------------------------------------------------------
/*
    Funkcia usporiada prvky v poli 'data' od najvacsieho prvku po najmensi.
    Pouzite algoritmus merge sort.
    Vytvorte jedno pomocne pole. Pre alokaciu a dealokaciu pomocneho pola pouzite new[] a delete[].

    PARAMETRE:
        [in, out] data - pole, ktore funkcia usporiada
        [in] length    - pocet prvkov pola

    VSTUPNE PODMIENKY:
        'data' ukazuje na platne pole

    PRIKLADY:
        (1, 3, 2) -> (3, 2, 1)
        (1, 2, 2, 1) -> (2, 2, 1, 1)
        (1) -> (1)
        () -> ()

    POZNAMKA:
        Ak pouzijete pristup top-down, tak
        - v tejto funkcii zabezpecte vytvorenie a kopirovanie dat do pomocneho pola,
        - vytvorte a zavolajte rekurzivnu funkciu, v ktorej implementujete hlavnu cast algoritmu merge sort.
*/

void swapPointers(int** a, int** b) {
    int* tmp=(*a);
    (*a)=(*b);
    (*b)=tmp;
}

void mergeSort(int *data, const size_t length) {
    int* tmp=new int[length];

    int* input=data;
    int* output=tmp;
    bool needCopy=false;

    for (size_t step=1; step<length; step*=2) {
        for (size_t i=0; i<length; i+=2*step) {
            size_t low=i;
            size_t middle=std::min(i+step, length);
            size_t high=std::min(i+2*step, length);
            ::mergeNeighbours(output, input, low, middle, high);
        }

        needCopy= !needCopy;
        swapPointers(&input, &output);
    }

    if (needCopy) {
        memcpy(data, tmp, length*sizeof(int));
    }
    delete[] tmp;
}

//-------------------------------------------------------------------------------------------------
// TESTOVANIE
//-------------------------------------------------------------------------------------------------

// tu mozete doplnit pomocne funkcie a struktury

void toPrint(List* list) {
    Node* current = list->first;

    while (current!= nullptr) {
        cout << current->data << " ";
        current=current->next;
    }
    cout << endl;
}

void toPrint(int* x, size_t length) {
    for (int i=0; i<length; i++) cout << x[i] << ' ';

    cout << endl;
}

List* createListFromArray(const int* data, const size_t n) {
    List* newList = new List;
    newList->first=nullptr;
    if (n==0 || data==nullptr || sizeof(data)==0) return newList;

    Node* newNode=new Node;

    newNode->data=data[0];
    newNode->next= nullptr;
    newList->first=newNode;

    if (n>1) {
        for (int i=1; i<n; i++) {
            newNode->next=new Node;
            newNode = newNode->next;
            newNode->data=data[i];
        }
    }

    return newList; // tento riadok zmente podla zadania, je tu len kvoli kompilacii
}

int main() {

    // tu mozete doplnit testovaci kod

    int x[]={1, 2, 2, 1};
    mergeSort(x,4);
    toPrint(x,4);



    return 0;
}
