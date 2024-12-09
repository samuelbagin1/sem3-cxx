// Tema:    virtualna metoda, virtualny destruktor
// Priklad: Reprezentacia obrazu, skladajuceho sa z kruhov a polygonov. Moznost exportovania do formatu SVG.
//          Diagram tried je v prezentacii
// Autor:   Vladislav Novak

#include <iostream>
#include <list>
#include <fstream>
#include <sstream>

using namespace std;

// Bod v rovine
struct Point {
    int x;
    int y;
};

// Specifikacia grafickych elementov (metod, ktore musia implementovat) a definovanie spolocnych pomocnych funkcii
class Element {
protected:
    static string quoted(string value) {
        return "\"" + value + "\"";
    }
    static string quoted(int value)  {
        return quoted(to_string(value));
    }
public:
    virtual string toSvg() const = 0;
    virtual ~Element() { cout << "~Element()" << endl; } // nepotrebujeme, ale pre otestovanie volania destruktorov
};

// Spolocna implementacia pre jednofarebne elementy
class SingleColorElement : public Element {
private:
    string color; // farba elementu
protected:
    string colorAsSvg() const {
        return "fill=" + quoted(color) + "";
    }
public:
    explicit SingleColorElement(string color)
    : color(move(color)) { // std::move - aby sme nevytvarali dalsiu zbytocnu kopiu
    }
    ~SingleColorElement() override { cout << "~SingleColorElement()" << endl; }
};

// Kruh
class Circle: public SingleColorElement {
private:
    Point center; // pozicia stredu
    int radius; // polomer
public:
    explicit Circle(Point center, int radius, string color)
        : SingleColorElement(move(color))
        , center(center)
        , radius(radius) {
    }
    ~Circle() override { cout << "~Circle()" << endl; }
    string toSvg() const override {
        return "<circle cx=" + quoted(center.x) + " cy=" + quoted(center.y) + " r=" + quoted(radius) + " " + colorAsSvg() + "/>";
    }
};

// Mnohouholnik
class Polygon: public SingleColorElement {
private:
    list<Point> points;
public:
    Polygon(const initializer_list<Point> points, string color)
        : SingleColorElement(move(color))
        , points(points){
    }
    ~Polygon() override { cout << "~Polygon()" << endl; }
    string toSvg() const override {
        ostringstream out;
        out << "<polygon points=\"";
        for (const Point &point : points) {
            out << point.x << ", " << point.y << ", ";
        }
        out << "\" ";
        out << colorAsSvg();
        out << " />";
        return out.str();
    }
};

// Obraz
class Image {
private:
    list<const Element*> elements; // komponenty obrazu
public:
    void add(const Element *element) {
        elements.push_back(element);
    }
    string toSvg() const {
        ostringstream output;
        output << "<svg version=\"1.1\" width=\"100\" height=\"100\" xmlns=\"http://www.w3.org/2000/svg\" >" << endl;
        for(const Element *e: elements) {
            output << "    " << e->toSvg() << endl;
        }
        output << "</svg>" << endl;
        return output.str();
    }
    void save(const string & fileName) const { // export do suboru
        ofstream file(fileName);
        file.exceptions(fstream::badbit | fstream::failbit); // aby pri vyskyte nastavenych typoch chyb vyhodil vynimku
        file << toSvg();
    }
    ~Image(){
        for(const Element *e: elements) {
            delete e;
        }
    }
};

// ---------------------------------------------------------------------------------------------------------------------
//           Testovanie
// ---------------------------------------------------------------------------------------------------------------------

int main() {
    Element *circle = new Circle({25, 25}, 25, "yellow");
    cout << circle->toSvg() << endl;

    Polygon *polygon = new Polygon({{50, 0}, {100, 100}, {0, 100}}, "blue");
    cout << polygon->toSvg() << endl;

    // delete circle;
    // delete polygon;

    Image image;
    image.add(circle);
    image.add(polygon);
    image.save("output.svg");

    cout << "--------------------------------------------------------------------------------" << endl;
    return 0;
}
