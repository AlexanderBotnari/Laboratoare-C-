#include <iostream>
using namespace std;
struct Cintec {

    int numar;
    string denumire;
    string gen;
    string interpret;
    double durata;
    string autorVersuri;
    string autorMuzica;
    int an;

    Cintec* urmator;
};
 Cintec* cap = NULL;

void creare (){
     Cintec *c = new Cintec();

     cout << "\nIntroduceti numarul cintecului :" ;
     cin >> c->numar;
     cout << "Introduceti denumirea cintecului :" ;
     cin >> c->denumire;
     cout << "Introduceti genul cintecului :" ;
     cin >> c->gen;
     cout << "Introduceti interpretul cintecului :";
     cin >> c->interpret;
     cout << "Introduceti durata cintecului :";
     cin >> c->durata;
     cout << "Introduceti autorul versurilor : ";
     cin >> c->autorVersuri;
     cout << "Introduceti autorul muzicii : ";
     cin >> c->autorMuzica;
     cout << "Introduceti anul : ";
     cin >> c->an;
     c->urmator = cap;
     cap = c;

 }
void afisareLista(){
    Cintec* c = cap;
    while (c != NULL){
        cout << "\nNumarul de ordine : " <<c->numar;
        cout << "\nDenumire : " << c->denumire;
        cout << "\nGen : " << c->gen;
        cout << "\nInterpret : " << c->interpret;
        cout << "\nDurata : " << c->durata;
        cout << "\nAutor versuri : " << c->autorVersuri;
        cout << "\nAutor muzica : " << c->autorMuzica;
        cout << "\nAnul : " << c->an <<"\n\n";
        c = c->urmator;         // Mutam elementul curent la urmatorul element din lista
    }
}

void adaugare(){
    Cintec *c = new Cintec();

    cout << "\nIntroduceti numarul cintecului care va fi adaugat :" ;
    cin >> c->numar;
    cout << "Introduceti denumirea cintecului care va fi adaugat :" ;
    cin >> c->denumire;
    cout << "Introduceti genul cintecului care va fi adaugat :" ;
    cin >> c->gen;
    cout << "Introduceti interpretul cintecului care va fi adaugat :";
    cin >> c->interpret;
    cout << "Introduceti durata cintecului care va fi adaugat :";
    cin >> c->durata;
    cout << "Introduceti autorul versurilor care va fi adaugat : ";
    cin >> c->autorVersuri;
    cout << "Introduceti autorul muzicii care va fi adaugat : ";
    cin >> c->autorMuzica;
    cout << "Introduceti anul care va fi adaugat : ";
    cin >> c->an;
    c->urmator = cap;
    cap = c;
}
void modificare(){
    int n = 0;
    cout<<"\nIntroduceti numarul filmului ce doriti sa modificati : ";
    cin>>n;

    n--;
    Cintec *c = cap;
    int i = 0;
    while(c){
        if(i == n){
            cout << "\nIntroduceti numarul cintecului :" ;
            cin >> c->numar;
            cout << "Introduceti denumirea cintecului :" ;
            cin >> c->denumire;
            cout << "Introduceti genul cintecului :" ;
            cin >> c->gen;
            cout << "Introduceti interpretul cintecului :";
            cin >> c->interpret;
            cout << "Introduceti durata cintecului :";
            cin >> c->durata;
            cout << "Introduceti autorul versurilor : ";
            cin >> c->autorVersuri;
            cout << "Introduceti autorul muzicii : ";
            cin >> c->autorMuzica;
            cout << "Introduceti anul : ";
            cin >> c->an;

            cout<<"Cintec modificat cu succes ! ";

            afisareLista();//afisam lista cu cintecul modificat

            i++;
            c = c->urmator;
        }
    }
 }

 void eliminare(){
    int n = 0;
    cout<<"\nIntroduceti numarul cintecului care va fi eliminat : ";
    cin>>n;

    n--;
    int i = 0;
    Cintec *c = cap;

    bool eliminat = false;

    if(n == 0){
        Cintec *temp = cap;
        cap = cap->urmator;
        free(temp);
        eliminat = true;
    }else if (n>0){
        while(c){
            if(i == n){
                Cintec *temp = c->urmator;
                c->urmator = c->urmator->urmator;
                free(temp);
                eliminat = true;
            }
            i++;
            c = c->urmator;
        }
    }
    if(eliminat){
        cout<<"\nCintec eliminat cu succes ! "<<endl;
    }else{
        cout<<"\nCintecul cu asa numar nu exista !"<<endl;
    }

}

void cautareDupaNr(){
    int n = 0;
    cout<<"\nIntroduceti numarul cintecului pe care doriti sal cautati : "<<endl;
    cin>>n;

    Cintec *c = cap;

    cout<<"Rezultatele cautarii : "<<endl;
    while(c){
        if(n == c->numar){
            cout<<"Filmul "<<c->numar<<" are urmatoarele date :"<<endl;
            cout << "Denumire : " << c->denumire;
            cout << "\nGen : " << c->gen;
            cout << "\nInterpret : " << c->interpret;
            cout << "\nDurata : " << c->durata;
            cout << "\nAutor versuri : " << c->autorVersuri;
            cout << "\nAutor muzica : " << c->autorMuzica;
            cout << "\nAnul : " << c->an <<"\n\n";
        }
        c = c->urmator;
    }
}
bool compara(Cintec x, Cintec y) {
    return x.numar > y.numar;
}
void sortare() {
    sort(cap, cap + 100, compara);
}

int main() {

     //Cream
     creare();

     //adaugam 2 elemente
    for(int i=0; i<=2 ;i++) {
        adaugare();
    }

    // eliminare element dupa numar
    //    eliminare();

    //sortarea datelor din lista dupa nr de ordine
    //    sortare();

        afisareLista();

    //    cautareDupaNr();


    // MODIFICARE si afisare
    //    modificare();

    return 0;
}
