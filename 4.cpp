#include <iostream>
using namespace std;
int tam(int x){
    int cifra=1;
    while(x>=10){
        x /=10;
        cifra++;
    }
    return cifra;

}
bool palindromo(long num){
    long aux=num;
    bool v=true;
    int cifras=tam(num),div=10,primero,ultimo;

    while(tam(aux)!=1){
        for(int i=1;i<=cifras-2;i++){
            div *=10;

        }
        primero=aux/div;
        ultimo=aux%10;
        if(primero != ultimo && tam(aux)!=1){
            v=false;
            break;
        }
        else{
            aux =aux % (primero*div);
            aux/=10;
        }
        cifras-=2;
        div=10;
    }
    return v;

}
long producto(){
    long prod=0;
    int i=1,j=1;
    while(i!=10){
        while(j!=10){
            prod=i*j;
            cout << prod << endl;
            j++;
        }
        i++;
    }
}
int main(){

    cout << producto();

    return 0;
}
