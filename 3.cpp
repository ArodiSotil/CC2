#include <iostream>

using namespace std;
long factorPrimo(long valor){
    int fp;
    for(int i=2 ; valor > 1 ; i++){
        while (valor%i==0){
            fp=i;
            valor /= i;
        }
    }
    return fp;
}

int main(){
    //cout << factorPrimo(600851475143);
    cout << factorPrimo();
    return 0;
}
