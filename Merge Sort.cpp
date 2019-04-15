#include <iostream>
 using namespace std;
void PrintArray(int *array, int n) {
  for (int i = 0; i < n; ++i)
    cout << array[i] << " " ;
  cout << endl;
}

void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;

    /* creamos arrays temporales */
    int L[n1], R[n2];

    /* copiamos los datos a los arreglos temporales L y R */
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1+ j];

    /* combina los arreglos temporales de nuevo en arr[l..r]*/
    i = 0; // incdice inicial del primer subarreglo
    j = 0; // indice inicial del segundo subarreglo
    k = l; // indice inicial del subarreglo combinado
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    /* copia los elementos restantes de L[] si hay alguno */
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    /*Copia los elementos restantes de R[] si hay alguno*/
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

/*
l es para el índice izquierdo y r es el índice derecho del subarreglo de arr que se ordenará */
void mergeSort(int arr[], int l, int r)
{
    if (l < r)
    {
        // Igual que (l + r) / 2, pero evita el desbordamiento de
        // grandes l y h
        int m = l+(r-l)/2;

        // ordenar primera y segunda mitad
        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);

        merge(arr, l, m, r);
    }
}


int main(){
    int array[]={3,5,7,3,8,11,32,34,65,23};
    int n=10;
    cout << "Lista ordenada =D" << endl;
    mergeSort(array,0,n-1);
    PrintArray(array,n);
    return 0;
}
