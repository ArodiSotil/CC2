#include <iostream>

using namespace std;

int diferencia(int a){
    int sumCua=0,cuaSum=0;
    for(int i = 1 ; i<=a;i++){
        sumCua +=(i*i);
    }
    for(int i=1;i<=a;i++){
        cuaSum +=i;
    }
    return (cuaSum*cuaSum)-sumCua;
}
int main(){
    cout << diferencia(100);
    return 0;
}
