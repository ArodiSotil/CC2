#include <iostream>
using namespace std;

int mcm(int val1 , int val2){
    int mini=min(val1,val2),mcd;
    for (int i = 1;i<=mini;i++){
        if (val1%i==0 & val2%i==0){
            mcd=i;
        }
    }
    return ((val1*val2)/mcd);
}

int main(){
    int num=1;
    for(int i=1;i<20;i++){
        num=mcm(num,i);
        cout <<num<<endl;
    }
    return 0;
}
