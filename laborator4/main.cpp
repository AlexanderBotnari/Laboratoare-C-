#include <iostream>
#include<ctype.h>
#include<stdio.h>
#include<string.h>
#include<fstream>
using namespace std;

struct Cintec{
    int numar;
    char denumire[50];
    string gen;
    string interpret;
    double durata;
    string autorVersuri;
    string autorMuzica;
    int an;

    void setData(){
        cout<<"\nIntroduceti numarul de ordine : ";
        cin>>numar;
        cout<<"Introduceti denumirea : ";
        cin>>denumire;
        cout<<"Introduceti genul :";
        cin>>gen;
        cout<<"Introduceti interpretul :";
        cin>>interpret;
        cout<<"Introduceti durata :";
        cin>>durata;
        cout<<"Introduceti autorul versurilor : ";
        cin>>autorVersuri;
        cout<<"Introduceti autorul muzicii : ";
        cin>>autorMuzica;
        cout<<"Introduceti anul: ";
        cin>>an;
    }

    void showData(){
        cout << "\nNumarul de ordine : " <<numar;
        cout << "\nDenumire : " << denumire;
        cout << "\nGen : " << gen;
        cout << "\nInterpret : " << interpret;
        cout << "\nDurata : " << durata;
        cout << "\nAutor versuri : " << autorVersuri;
        cout << "\nAutor muzica : " << autorMuzica;
        cout << "\nAnul : " << an <<"\n\n";
    }
    int retNumar(){
        return numar;
    }
};

void scrieInFisier(const string &filename){
    ofstream outFile;
    outFile.open(filename, ios::binary | ios::app);

    Cintec obj;
    obj.setData();

    outFile.write((char*)&obj, sizeof(obj));

    outFile.close();
}
void citesteDinFisier(const string &filename) {
    ifstream inFile;
    inFile.open(filename, ios::binary);

    Cintec obj;

    while(inFile.read((char*)&obj, sizeof(obj))){
        obj.showData();
    }

    inFile.close();
}

void modificareFisier(const string filename,int n){
    Cintec obj;
    fstream fio(filename, ios::in | ios::out);
    long pos;
    while(!fio.eof()){
        pos = fio.tellg() ;
        fio.read((char *) & obj, sizeof(obj));
        if(obj.retNumar() == n){
            cout<<"Introduceti noile date ale inregistrarii cu numarul >> "<<n<<endl;
            obj.setData();
            fio.seekg(pos);
            fio.write((char *) & obj, sizeof(obj));
        }
    }
    fio.close();
}

void stergetiDateleDinFisier(const string &filename){
    ofstream file(filename, ios::trunc);
}

void  cautareDupaNumar(const string &filename, int n) {
    ifstream inFile;
    inFile.open(filename, ios::binary);
    Cintec obj;

    while(inFile.read((char*)&obj, sizeof(obj))){
        if(obj.retNumar() == n){
            cout<<"Rezultate gasite : "<<endl;
            obj.showData();
        }
    }
    inFile.close();
}

void sort(){
    FILE *fp;
    Cintec c;
    if ((fp = fopen("fisier.bin", "rb+")) != NULL) {
        size_t itemSize = sizeof(c);
        Cintec data1, data2;
        int flag = 1;

        while(flag) {
            flag = 0;
            fread(&data1, itemSize, 1, fp);
            fread(&data2, itemSize, 1, fp);
            while (!feof(fp)) {
                if (data2.numar < data1.numar) {
                    fseek(fp, (itemSize * -2), SEEK_CUR);
                    fwrite(&data2, itemSize, 1, fp);
                    fwrite(&data1, itemSize, 1, fp);
                    flag = 1;
                } else {
                    data1 = data2;
                }
                fread(&data2, itemSize, 1, fp);
            }
            if (flag) { rewind(fp); }
        }
        fclose(fp);
    }
}

int main() {

    const string fisier = "fisier.bin";

//    //inscriem in fisier 3 valori
//    for(int i = 1; i <= 3; i++) {
//        scrieInFisier(fisier);
//    }

//sortarea datelor dupa numar
//sort();

//modificam inregistrarea nr 1
// modificareFisier(fisier,1);

//stergere date din fisier
//stergetiDateleDinFisier(fisier);

//    cautareDupaNumar(fisier,3);


citesteDinFisier(fisier);
    return 0;
}


