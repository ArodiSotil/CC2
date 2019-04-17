#include <iostream>

using namespace std;
long fibonaci(int a){
    int f=0,x=0,y=1;
    long cont=0;
    while(cont<a){
        f = y;
        y +=x;
        x = f;
        if (y%2==0){
            cont +=y;
        }
    }
    return cont;

}
int main(){
    cout << fibonaci(4000000);
    return 0;
}
