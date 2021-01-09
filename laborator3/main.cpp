#include "iostream"
#include "string.h"
using namespace std;

struct Cintec{
    string denumire;
    string gen;
    string interpret;
    double durata;
    string autorVersuri;
    string autorMuzica;
    int an;

    Cintec() {}

    Cintec(string denumire , string gen , string interpret, double durata, string autorVersuri, string autorMuzica
           ,int an ) {
        this->denumire = denumire;
        this->gen = gen;
        this->interpret = interpret;
        this->durata = durata;
        this->autorVersuri = autorVersuri;
        this->autorMuzica = autorMuzica;
        this->an = an;
    }

    const string &getDenumire() const {
        return denumire;
    }

    void setDenumire(const string &denumire) {
        Cintec::denumire = denumire;
    }

    const string &getInterpret() const {
        return interpret;
    }

    void setInterpret(const string &interpret) {
        Cintec::interpret = interpret;
    }

    const string &getGen() const {
        return gen;
    }

    void setGen(const string &gen) {
        Cintec::gen = gen;
    }

    double getDurata() const {
        return durata;
    }

    void setDurata(double durata) {
        Cintec::durata = durata;
    }

    const string &getAutorVersuri() const {
        return autorVersuri;
    }

    void setAutorVersuri(const string &autorVersuri) {
        Cintec::autorVersuri = autorVersuri;
    }

    const string &getAutorMuzica() const {
        return autorMuzica;
    }

    void setAutorMuzica(const string &autorMuzica) {
        Cintec::autorMuzica = autorMuzica;
    }

    int getAn() const {
        return an;
    }

    void setAn(int an) {
        Cintec::an = an;
    }
};Cintec arr[100];

void afisare(){
    cout<<"Lista de melodii : "<<endl;
      for(Cintec i : arr){
          if(i.getDenumire() != "" && i.getInterpret() != "" && i.getDurata() != 0 && i.getAn() >= 1950) {
              cout << "Denumire : " << i.denumire << " , "
                   << "Gen : " << i.gen << " , "
                   << "Interpret : " << i.interpret << " , "
                   << "Durata : " << i.durata << " min , "
                   << "Autor versuri : " << i.autorVersuri << " , "
                   << "Autor muzica : " << i.autorMuzica << " , "
                   << "An : " << i.an << "\n";
          }
      }
}

void adaugare(Cintec c){
       arr[0] = c;
}

void adaugareCuIndex(Cintec c,int index){
    arr[index] = c;
}

void creare(Cintec c){
    cout << "Introduceti denumirea cintecului : ";
    cin >> c.denumire;
    cout << "Introduceti genul carui apartine melodia : ";
    cin >> c.gen;
    cout << "Interpretul : ";
    cin >> c.interpret;
    cout << "Durata melodiei in minute: ";
    cin >> c.durata;
    cout << "Introduceti autorul versurilor : ";
    cin >> c.autorVersuri;
    cout << "Introduceti autorul melodiei :";
    cin >> c.autorMuzica;
    cout << "Introduceti anul fabricarii melodiei :";
    cin >> c.an;

    adaugare(c);
    cout<<">>>>>Cintecul a fost creat cu succes si adaugat \n";
}

void modificare(Cintec cintec , int index){
    arr[index].setDenumire(cintec.getDenumire());
    arr[index].setGen(cintec.getGen());
    arr[index].setInterpret(cintec.getInterpret());
    arr[index].setDurata(cintec.getDurata());
    arr[index].setAutorVersuri(cintec.getAutorVersuri());
    arr[index].setAutorMuzica(cintec.getAutorMuzica());
    arr[index].setAn(cintec.getAn());
}

void eliminare(int index ){
    arr[index].setDenumire(" ");
    arr[index].setGen(" ");
    arr[index].setInterpret(" ");
    arr[index].setDurata(0);
    arr[index].setAutorVersuri(" ");
    arr[index].setAutorMuzica(" ");
    arr[index].setAn(0);
}

void cautareDupaDenumire(string denumire){
    cout<<"Rezultatul cautarii dupa titlu : "<<endl;
    for(Cintec i : arr){
        if(i.getDenumire() != " " && i.getDenumire() == denumire){
            cout << "Denumire : " << i.denumire << " , "
                 << "Gen : " << i.gen << " , "
                 << "Interpret : " << i.interpret << " , "
                 << "Durata : " << i.durata << " min , "
                 << "Autor versuri : " << i.autorVersuri << " , "
                 << "Autor muzica : " << i.autorMuzica << " , "
                 << "An : " << i.an << "\n";
        }
    }
}
bool compara(Cintec x, Cintec y) {
    return x.an > y.an;
}
void sortare() {
    sort(arr, arr + 100, compara);
}

int main(){

    Cintec c;
    Cintec c1;
    c1.setDenumire("Hot");
    c1.setGen("Pop");
    c1.setInterpret("Ion");
    c1.setDurata(2.10);
    c1.setAutorMuzica("Mihai");
    c1.setAutorVersuri("Gheorge");
    c1.setAn(2019);

    Cintec c2 = *new Cintec("Inima","populara","Alex",3.52,
                "gheorghe","Sergiu",2018);
    Cintec c5 = *new Cintec("Inima","populara","Alex",3.52,
                            "gheorghe","Sergiu",2011);
    Cintec c6 = *new Cintec("Inima","populara","Alex",3.52,
                            "gheorghe","Sergiu",2025);


    Cintec c3;
        creare(c);
        creare(c3);
        adaugareCuIndex(c1,3);
        adaugareCuIndex(c2,5);
        adaugareCuIndex(c5,6);
        adaugareCuIndex(c6,7);

    Cintec c4 = *new Cintec("Dor","populara","Serghei",4.57,
                            "ana","Elene",2016);
        modificare(c4,3);

//        eliminare(5);

        sortare();

        afisare();

    cautareDupaDenumire("Inima");

}