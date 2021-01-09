#include <iostream>
using namespace std;

class Cintec{
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
int main() {

    Cintec *c = new Cintec(1,"Dorule","Populara","Mihai Dolgan",4.56,
            "Mihai Dolgan","Mihai Dolgan",2001);

    cout<<c->getDenumire();//afisarea denumirii prin metoda getDenumire
    //celelate cimpuri la fel le putem afisa continutul prin metodele getter

    cout<<" "<<endl;

    c->convertInSecunde(c->getDurata());//convertirea in secunde a duratei cintecului cu numarul 1

    Cintec *c1 = new Cintec(2,"Love","Pop","David Wiliam",5.23,
                           "John Smith","John Smith",2012);

    cout<<" "<<endl;

    cout<<c+1<<endl;//ne este afisat pe ecran adresa in memorie

    //c == c1 // expresie gresita
    //c + c1 // expresie gresita

}
