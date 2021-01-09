#include <iostream>
using namespace std;
int main() {

    int n, i;
    float arr[50], sum=0, media;
    cout<<"Cite numere doriti sa introduceti ? ";
    cin>>n;
    cout<<"\nIntroduceti "<<n<<" numere : ";
    for(i=0; i<n; i++){
        cin>>arr[i];
        sum = sum+arr[i];
    }
    media = sum/n;
    cout<<"\nMedia aritmetica : "<<media;
    cout<<endl;

    return 0;
}
