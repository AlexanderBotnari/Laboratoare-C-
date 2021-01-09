#include <iostream>
using namespace std;

class Cintec{
public:
    int numar;
    string denumire;
    string gen;
    string interpret;
    double durata;
    string autorVersuri;
    string autorMuzica;
    int an;

public:
    Cintec() {}

    Cintec(int numar,const string &denumire, const string &gen
            ,const string &interpret, double durata,const string &autorVersuri,const string &autorMuzica ,
           int an) : numar(numar) ,denumire(denumire) ,gen(gen),interpret(interpret),durata(durata),autorVersuri(autorVersuri),
                     autorMuzica(autorMuzica),an(an){}

    Cintec(int numar,const string &denumire, int an): numar(numar),denumire(denumire),an(an){}

    int getNumar() const {
        return numar;
    }

    const string &getDenumire() const {
        return denumire;
    }

    const string &getGen() const {
        return gen;
    }

    const string &getInterpret() const {
        return interpret;
    }

    double getDurata() const {
        return durata;
    }

    const string &getAutorVersuri() const {
        return autorVersuri;
    }

    const string &getAutorMuzica() const {
        return autorMuzica;
    }

    int getAn() const {
        return an;
    }

    void convertInSecunde(double durata){
        double res = durata * 60;
        cout<<"Durata de "<<durata<<" minute in secunde este de : "<<res<<"s";
    }
};

class CinteceShowBusiness: virtual public Cintec{
    string popularitate;

public:
    CinteceShowBusiness(){}

    CinteceShowBusiness(int numar, const string &denumire, const string &gen, const string &interpret, double durata,
                        const string &autorVersuri, const string &autorMuzica, int an, const string &popularitate)
            : Cintec(numar, denumire, gen, interpret, durata, autorVersuri, autorMuzica, an), popularitate(popularitate) {}

    CinteceShowBusiness(const string &popularitate) : popularitate(popularitate) {}

    const string &getPopularitate() const {
        return popularitate;
    }

};

class CinteceRap : virtual public CinteceShowBusiness{

    int descarcari;

public:
    CinteceRap(){}
    CinteceRap(int numar, const string &denumire, const string &gen, const string &interpret, double durata,
               const string &autorVersuri, const string &autorMuzica, int an, const string &popularitate,
               int descarcari) : CinteceShowBusiness(numar, denumire, gen, interpret, durata, autorVersuri, autorMuzica,
                                                     an, popularitate), descarcari(descarcari) {}

    int getDescarcari() const {
        return descarcari;
    }


};

int main() {

    CinteceRap cr ;
    cr.denumire = "Nigga";

    cout<<"Denumire >> "<<cr.getDenumire();//metoda getDenumire se mosteneste de la clasa Cintec

    return 0;
}
