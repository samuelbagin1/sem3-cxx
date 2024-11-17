// STRUCNY POPIS:
//
// V tejto ukazke su naprogramovane 2 triedy:
//
//    Trieda 'Movie'
//
//    Reprezentuje film v databaze filmov.
//
//    Jej atributmi su:
//       * nazov filmu 'title' (C++ retazec, trieda std::string)
//       * rok vydania 'year'
//       * hodnotenie filmu 'rating'
//
//    Jej metodami su:
//       * konstruktory (default, parametricky a kopirovaci)
//       * destruktor
//       * nastavovacie metody, tzv. setters
//       * metody na vratenie atributov, tzv. getters
//       * metoda 'print' na vypis informacii o filme
//
// -----------------------------------------------------------------
//
//    Trieda 'MovieDB'
//
//    Reprezentuje databazu filmov a k nej asociovane operacie.
//
//    Jej atributmi su:
//       * vektor filmov 'db' (obsahuje objekty typu 'Movie')
//
//    Jej metodami su:
//       * metoda 'add' na pridanie filmu do
//       * metoda 'remove' na odstranenie filmu z databazy
//       * metoda 'search' na vyhladanie filmu v databaze podla klucoveho slova
//       * metoda 'print' na vypis databazy filmov

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>

using namespace std;

// definicia triedy 'Movie'
class Movie {
private:
    string title; // nazov filmu
    int year; // rok vydania filmu
    int rating; // percentualne hodnotenie filmu 0 az 100 %

public:
    // default a zaroven parametricky konstruktor
    // poznamka: vytvori sa hlboka kopia nazvu filmu
    Movie(const string title = "", const int year = -1, const int rating = -1) :
            year(year),
            rating(rating),
            title(title){
    }

    // copy konstruktor - hlboka kopia objektu 'other'
    Movie(const Movie &other) :
            year(other.year),
            rating(other.rating),
            title(other.title){
    }

    // set metoda pre atribut 'title'
    void setTitle(const string title) {
        this->title = title;
    }

    // set metoda pre atribut 'year'
    void setYear(const int year) {
        this->year = year;
    }

    // set metoda pre atribut 'rating'
    void setRating(const int rating) {
        this->rating = rating;
    }

    // get metoda pre atribut 'title'
    string getTitle() const {
        return this->title;
    }

    // get metoda pre atribut 'year'
    int getYear() const {
        return this->year;
    }

    // get metoda pre atribut 'rating'
    int getRating() const {
        return this->rating;
    }

    // metoda na vytlacenie informacii o filme do konzoly
    void print() const {
        cout << left << setw(25) << this->title;
        cout << setw(7) << this->year;
        cout << this->rating << " %";
        cout << endl;
    }
};

// definicia triedy 'MovieDB'
class MovieDB {
private:
    vector<Movie> db; // vektor filmov, t.j. databaza

public:
    // metoda na pridavanie noveho filmu do DB
    void add(const Movie& movie) {
        this->db.push_back(movie);
    }

    // metoda na odstranenie filmov z DB podla klucoveho slova
    void remove(const string& keyword) {
        vector<Movie>::iterator it;
        for(it = this->db.begin(); it!=db.end(); it++){
            if((*it).getTitle().find(keyword) != string::npos){
                it = this->db.erase(it);
                it--;
            }
        }
    }

    // metoda na vyhladavanie filmov v DB podla klucoveho slova
    vector<Movie> searchByTitle(const string keyword) const {
        vector<Movie> results;
        vector<Movie>::const_iterator it;
        for(it = this->db.cbegin(); it!=db.cend(); it++){
            if((*it).getTitle().find(keyword) != string::npos){
                results.push_back(*it);
            }
        }
        return results;
    }

    // metoda na vypis DB filmov do konzoly
    void print() const {
        cout << endl << "Movie DB" << endl;
        cout << "-----------------------------------------" << endl;
        for (std::size_t i = 0; i < this->db.size(); i++) {
            this->db[i].print();
        }
        cout << endl;
    }
};


// funkcia na testovanie prace s triedou 'MovieDB'
void test_movie_db() {
    MovieDB db;

    Movie m1("Lion King", 2019, 77);
    Movie m2("Finding Nemo", 2003, 86);
    Movie m3("Interstellar", 2014, 86);
    Movie m4("Shutter Island", 2010, 88);

    // Test metody 'add'
    db.add(m1);
    db.add(m2);
    db.add(m3);
    db.add(m4);

    // Test metody 'print' na vypis databazy filmov
    db.print();

    // Interaktivny test metody 'search' na vyhladanie filmu v databaze
    string keyword;
    cout << "Hladaj film podla klucoveho slova: ";
    cin >> keyword;
    vector<Movie> results = db.searchByTitle(keyword);
    if (!results.empty()) {
        for(size_t i = 0; i< results.size();i++){
            results.at(i).print();
        }
    } else {
        cout << "Nic sa nenaslo" << endl;
    }
    cout << endl;

    // Interaktivny test metody 'remove'
    cout << "Vymaz film podla klucoveho slova: ";
    cin >> keyword;
    db.remove(keyword);
    db.print();
}

// testovanie
int main() {
    test_movie_db();
    return 0;
}

