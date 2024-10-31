#include <iostream>
using namespace std;

// funkcia s 2 standardnymi parametrami
void fn0(int first, char second) {
    cout << "fn0: " << first << " " << second << endl;
}

// funkcia s:
//   * 1 standardnym parametrom ('first')
//   * 1 default parametrom ('second')
void fn1(int first, char second = 'x') {
    cout << "fn1: " << first << " " << second << endl;
}

// funkcia, ktora ma len default parametre
void fn2(int first = 1, char second = 'x') {
    cout << "fn2: " << first << " " << second << endl;
}

int main() {
    fn0(0,'e');
    // fn0(); // nebude kompilovatelne
    // fn0(9); // nebude kompilovatelne

    fn1(1); // parameter 'second' ma default hodnotu 'x'
    fn1(1,'r');
    // fn1(); // nepojde skompilovat

    fn2(2); // parameter 'second' ma default hodnotu 'x'
    fn2(3, 'G'); // default parametre sa nepouziju
    fn2(); // obidva parametre maju default hodnoty
    return 0;
}
