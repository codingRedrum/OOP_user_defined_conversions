// konwersje definiowane przez uzytkownika

#include <iostream>

using namespace std;

class Tzespolona
{
    double rzeczywsita;
    double urojona;
public:
    Tzespolona(double r, double u)
    : rzeczywsita(r), urojona(u)
    {}
    
    Tzespolona(double r)    // konstruktor konwertujacy
    {
        this->rzeczywsita = r;
        this->urojona = 0;
    }
    friend auto dodaj(Tzespolona a, Tzespolona b) -> Tzespolona;
    
};

class Zespolona
{
    double rzeczywista;
    double urojona;
public:
    // bylby konwertujacy, gdyby nie slowo explicit - zabrania niejawnej konwersji
    explicit Zespolona(double r = 0, double u = 0) : rzeczywista(r), urojona(u)
    {}
    friend auto pokaz(const Zespolona z) -> void;
};

auto dodaj(Tzespolona a, Tzespolona b) -> Tzespolona;
auto pokaz(const Zespolona z) -> void;

int main(int argc, const char * argv[]) {
   
    Zespolona a;
    pokaz(a);
    Zespolona b(2, 4);
    pokaz(b);
//  Zespolona c = 2.55;
    
    Zespolona d = Zespolona(2.6);
    pokaz(d);
    Zespolona *ptrOnZesp = new Zespolona(2.7);
    pokaz(*ptrOnZesp);
    
    Zespolona g = static_cast<Zespolona>(2.9);
    pokaz(g);
    
    delete ptrOnZesp;
    
    
    
    return 0;
}

auto dodaj(Tzespolona a, Tzespolona b) -> Tzespolona
{
    Tzespolona suma(0,0);
    suma.rzeczywsita = a.rzeczywsita + b.rzeczywsita;
    suma.urojona = a.urojona + b.urojona;
    return suma;
}

auto pokaz(const Zespolona z) -> void
{
    cout <<"Liczba zespolona: ["<<z.rzeczywista <<", " <<z.urojona <<"]" <<xendl;
}
