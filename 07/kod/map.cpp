// Tema: STL
// Autor: Pavol Marak

#include <iostream>
#include <string>
#include <map>
using namespace std;


// testovanie
int main() {


    map<string, string> slovnik{
            {"nadej",  "hope"},
            {"pribeh", "story"},
            {"hra",    "game"},
            {"poklad", "treasure"},
            {"clovek", "man"},
            {"noc",    "night"},
            {"film",   "movie"}
    };

    // vypis
    for(auto it = slovnik.begin(); it!= slovnik.end(); it++){
        cout << it->first << " : " << it->second << endl;
    }

    // insert
    pair<string,string> p("pomoc","help");
    slovnik.insert(p);

    // pridanie duplikatu
    pair<map<string,string>::iterator, bool> result = slovnik.insert(p);
    if(result.second){
        cout << "Success" << endl;
    }
    else{
        cout << "Error duplicate" << endl;
    };

    // vymazavanie
    size_t res = slovnik.erase("film");

    // operator []
    // - pristup
    cout << slovnik["nadej"] << endl;
    // - update
    slovnik["nadej"] = "novy preklad";
    // - pridanie
    slovnik["domov"] = "home";

    string keyword = "noc";
    map<string,string>::iterator it = slovnik.find(keyword);
    if(it!=slovnik.end()){
        cout << "Found";
    }
    else{
        cout << "Not found.";
    }

    return 0;
}
