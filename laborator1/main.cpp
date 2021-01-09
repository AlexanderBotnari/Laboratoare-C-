#include <iostream>
using namespace std;
int main() {

    unsigned int n;
    unsigned long factorial = 1;

    cout << "Introduceti un numar positiv : ";
    cin >> n;

    for(int i = 1; i <=n; ++i){
        factorial *= i;
    }
    cout << "Factorialul lui " << n << " = " << factorial;
    return 0;
}
