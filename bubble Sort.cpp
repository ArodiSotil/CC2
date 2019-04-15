#include <iostream>
 using namespace std;
void PrintArray(int *array, int n) {
  for (int i = 0; i < n; ++i)
    cout << array[i] << " " ;
  cout << endl;
}

void bubbleSort(int arreglo[],int n){
    int i,j,temp;
    for(i=0;i<n-1;i++){
        for (j=n-1;j>=i+1;j--){
            if(arreglo[j]<arreglo[j-1]){
                temp=arreglo[j];
                arreglo[j]=arreglo[j-1];
                arreglo[j-1]=temp;
            }
        }
    }
}

int main(){
    int array[]={3,5,7,3,8,11,32,34,65,23};
    int n=10;
    cout << "Lista ordenada =D" << endl;
    bubbleSort(array,n);
    PrintArray(array,n);
    return 0;
}
