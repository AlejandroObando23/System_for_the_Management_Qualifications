#include <iostream>

using namespace std;

template <typename T>
void ordenamientoIntercambio(T a[], int n){
    T temp;

    for(int i=0; i < n-1;i++){
        for(int j=i+1; j< n; j++){
            if(a[i].getPromedio() > a[j].getPromedio()){
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
}

template <typename T>
void ordenamientoSeleccion(T a[], int n){
    int min;
    T aux;
    for( int i=0; i<n; i++){
        min = i;
        for(int j=i+1; j<n; j++){
            if(a[j].getPromedio()<a[min].getPromedio()){
                min = j;
            }
        }
        aux = a[i];
        a[i] = a[min];
        a[min] = aux;
    }
}

template <typename T>
void ordenamientoBurbuja(T a[], int n){
    T aux;
    for(int i=0; i<n-1;i++){
        for(int j=0; j<n-i-1; j++){
            if(a[j].getPromedio()>a[j+1].getPromedio()){
                aux = a[j];
                a[j]=a[j+1];
                a[j+1]=aux;
            }
        }
    }
}

template <typename T>
void ordenamientoQuicksort(T a[], int primero, int ultimo){
    if(primero < ultimo){
        int i, j, central;
        double pivote;
        int aux;

        central = (primero + ultimo)/2;
        pivote = a[central].getPromedio();

        i = primero;
        j = ultimo;

        do{
            while(a[i].getPromedio() < pivote){
                i++;
            }
            while(a[j].getPromedio() > pivote){
                j--;
            }

            if(i<=j){
                aux = a[i];
                a[i] = a[j];
                a[j] = aux;
                i++;
                j--;
            }

        }while(i<j);

        if(primero < j){
            ordenamientoQuicksort(a, primero, j);
        }
        if(i<ultimo){
            ordenamientoQuicksort(a,i, ultimo);
        }

    }
}

template <typename T>
void ordenamientoShellsort(T a[], int n){
    T aux;
    for(int salto = n/2; salto >0; salto/=2){
        for(int i= salto; i<n; i++){
            int j = i- salto;
            while(j>= 0){
                int k = j+ salto;
                if(a[j].getPromedio()<= a[k].getPromedio()){
                    j--;
                }else{
                    aux = a[j];
                    a[j] = a[j+1];
                    a[j+1]=aux;
                    j-=salto;
                }
            }
        }
    }
}
