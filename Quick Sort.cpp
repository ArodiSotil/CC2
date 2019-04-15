#include <iostream>
 using namespace std;
void PrintArray(int *array, int n) {
  for (int i = 0; i < n; ++i)
    cout << array[i] << " " ;
  cout << endl;
}
void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

/*
Esta función toma el último elemento como pivote,
 coloca el elemento de pivote en su posición correcta
 en la matriz ordenada y coloca todos los más pequeños
 (más pequeños que el pivote) a la izquierda del pivote y
  todos los elementos mayores a la derecha del pivote */
int partition (int arr[], int low, int high)
{
    int pivot = arr[high];    // pivote
    int i = (low - 1);  // Indice del elemento mas pequeño

    for (int j = low; j <= high- 1; j++)
    {
        // si el eelemento actual es menor o
        // igua al pivote
        if (arr[j] <= pivot)
        {
            i++;    // índice de incremento del elemento más pequeño
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

/*
 arr[] --> Array a ordenar,
  low  --> Indice de inicio,
  high  --> indice final */
void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        /* p está dividiendo el índice, arr [p] ahora está en el lugar correcto */
        int p = partition(arr, low, high);

        // Ordenar por separado los elementos antes
        // particion y despues particion
        quickSort(arr, low, p - 1);
        quickSort(arr, p + 1, high);
    }
}

int main(){
    int array[]={3,5,7,3,8,11,32,34,65,23};
    int n=10;
    cout << "Lista ordenada =D" << endl;
    quickSort(array,0,n-1);
    PrintArray(array,n);
    return 0;
}
