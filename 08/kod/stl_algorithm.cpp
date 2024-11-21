// Tema: STL algoritmy
// Autor: Pavol Marak

#include <iostream>
#include <cctype>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

bool isNonEmpty(const string &str) {
    return !str.empty();
}

bool containsChar(const string &str, const char c) {
    return str.find(c) != string::npos;
}

// Pozn. Beh programu si kontrolujte v Debug rezime.
int main() {

    vector<string> v{"This", "is", "a", "beautiful", "day"};

    // std::all_of
    // 1. Su vsetky prvky kontajnera neprazdne retazce?
    cout << all_of(v.begin(), v.end(), isNonEmpty) << endl;
    // 2. Obsahuju vsetky prvky kontajnera zadane pismeno?
    char c = 'a';
    cout << all_of(v.begin(), v.end(), [=](const string &str) {
        return str.find(c) != string::npos;
    }) << endl;

    cout << all_of(v.begin() + 2, v.end(), [=](const string &str) {
        return str.find(c) != string::npos;
    }) << endl;

    // std::for_each
    // 1. Vypise kazdy prvok kontajnera.
    for_each(v.begin(), v.end(), [](const string &str) {
        cout << str << endl;
    });

    // std::count_if
    // 1. Vrati pocet prvkov kontajnera, ktore zacinaju velkym pismenom.
    cout << count_if(v.begin(), v.end(), [](const string &str) {
        if (str.empty()) return false;
        return isupper(str.front()) != 0;
    }) << endl;

    // std::find
    // 1. Vrati iterator na prvy prvok kontajnera, ktory sa rovna konkretnej hodnote.
    cout << (find(v.begin(), v.end(), "is") != v.end() ? "Found" : "Not found") << endl;

    // std::copy_if
    // 1. Do noveho vektora prekopiruje tie prvky, ktore maju konkretnu dlzku
    vector<string> v2{v.size()};
    size_t len = 4;
    copy_if(v.begin(), v.end(), v2.begin(), [len](const string &str) {
        return str.size() == len;
    });

    // std::transform
    // 1. Kazdy prvok transformuje na uppercase znaky.
    transform(v.begin(), v.end(), v.begin(), [](string &str) {
        transform(str.begin(), str.end(), str.begin(), [](const char &c) {
            return toupper(c);
        });
        return str;
    });

    // 2. Vytvori novy kontajner spojenim prvkov dvoch zdrojovych kontajnerov
    // spajame v + v3 a vysledky zapisujeme do v3
    vector<string> v3{"A", "B", "C", "D", "E"};
    transform(v.begin(), v.end(), v3.begin(), v3.begin(),[](const string &s1, const string &s2) {
        return s1 + "+" + s2;
    });

    // std::remove_if
    // 1. Odstranenie konkretnych prvkov
    // z 'va' odstranime prvky, ktore sa nachadzaju v 'vb'
    vector<int> vb{1, 3, 5};
    vector<int> va{1, 2, 3, 4, 5};
    remove_if(va.begin(), va.end(), [&](int c) {
        return find(vb.begin(), vb.end(), c) != vb.end();
    });

    // Pozn.: Odstranenie prebieha tak, ze sa prvky kontajnera len posuvaju tak,
    // aby vykryli miesto po odstranenych prvkoch.
    // Pozn. 2: STL algoritmy nemozu menit velkost kontajnerov.

    return 0;
}
