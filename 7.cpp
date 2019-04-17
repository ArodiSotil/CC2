#include <iostream>
using namespace std;

int primo(int a){
    int i=2,p=0,k=0;
    while(a!=0){
        bool x=true;
        for(int j=2;j<i;j++){
            if (i%j==0){
                x=false;
                break;
            }
        }
        if(x){
            p=i;
            a--;


        }
        i++;

    }
    return p;
}

int main(){
    cout <<primo(10001);

    return 0;
}
