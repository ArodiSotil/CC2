#include <iostream>
 using namespace std;
void PrintArray(int *array, int n) {
  for (int i = 0; i < n; ++i)
    cout << array[i] << " " ;
  cout << endl;
}
//radix sort---------------------------------------------------------------
// una funcion para obtener el valor maximo de un arreglo
int getMax(int arr[], int n)
{
    int mx = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > mx)
            mx = arr[i];
    return mx;
}


// Una función para hacer el conteo de arr [] de acuerdo con
// el dígito representado por exp.
void countSort(int arr[], int n, int exp)
{
    int output[n]; // arreglo de salida
    int i, count[10] = {0};

    // almacenar la cuenta de ocureencias en count[]
    for (i = 0; i < n; i++)
        count[ (arr[i]/exp)%10 ]++;


// Cambiar count [i] para que count[i] ahora contenga la real
    // posición de este dígito en la salida []
    for (i = 1; i < 10; i++)
        count[i] += count[i - 1];

    // constrir el arreglo de salida
    for (i = n - 1; i >= 0; i--)
    {
        output[count[ (arr[i]/exp)%10 ] - 1] = arr[i];
        count[ (arr[i]/exp)%10 ]--;
    }


// Copie el arreglo de salida a arr [], para que arr [] ahora
    // contenga números ordenados según el dígito actual
    for (i = 0; i < n; i++)
        arr[i] = output[i];
}


// La función principal para eso ordena arr [] de tamaño n usando
// Radix Sort
void radixsort(int arr[], int n)
{

// Encuentra el número máximo para saber el número de dígitos
    int m = getMax(arr, n);

   // Contar ordenando para cada dígito. Tenga en cuenta que en su lugar
    // de pasar el número de dígitos, se pasa la exp. exp es 10 ^ i
    // donde i es el número de dígito actual
    for (int exp = 1; m/exp > 0; exp *= 10)
        countSort(arr, n, exp);
}

int main(){
    int array[]={3,5,7,3,8,11,32,34,65,23};
    int n=10;
    cout << "Lista ordenada =D" << endl;
    radixsort(array,n);
    PrintArray(array,n);
    return 0;
}
