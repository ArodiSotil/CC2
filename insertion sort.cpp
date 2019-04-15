#include <iostream>
 using namespace std;
void PrintArray(int *array, int n) {
  for (int i = 0; i < n; ++i)
    cout << array[i] << " " ;
  cout << endl;
}
void InsertionSort(int arr[], int arr_size){
  if(arr_size > 1){
    int size = arr_size;
    for(int i = 1; i < size; ++i){
      int j = i - 1;
      int key = arr[i];
      while(j >= 0 && arr[j] > key){
        arr[j+1] = arr[j];
        --j;
      }
      arr[j+1] = key;
    }
  }
}
int main(){
    int array[]={3,5,7,3,8,11,32,34,65,23};
    int n=10;
    cout << "Lista ordenada =D" << endl;
    InsertionSort(array,n);
    PrintArray(array,n);
    return 0;
}
