#include <iostream>
const int MAX = 100;
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
        T aux;

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
template<typename T>
void CrearUrnas(T** Urnas, int m) {
    for (int i = 0; i < m; ++i) {
        Urnas[i][0] = 0;  // Inicializar el contador de elementos en la urna i a 0
    }
}

template<typename T>
bool EsVacia(T** Urnas, int i) {
    return Urnas[i][0] == 0;
}

template<typename T>
void agregarEnUrna(T** Urnas, int clave, T valor) {
    int& count = Urnas[clave][0];
    Urnas[clave][++count] = valor;
}

template<typename T>
void EnlazarUrna(T** Urnas, int desde, int hasta) {
    int& desdeCount = Urnas[desde][0];
    int& hastaCount = Urnas[hasta][0];
    for (int i = 1; i <= desdeCount; ++i) {
        Urnas[hasta][++hastaCount] = Urnas[desde][i];
    }
    Urnas[desde][0] = 0;
}

template<typename T>
void bucketSort(T vector[], int n, int m) {
    T** Urnas = new T*[m];
    for (int i = 0; i < m; ++i) {
        Urnas[i] = new T[MAX]();
    }

    CrearUrnas(Urnas, m);

    for (int j = 0; j < n; ++j) {
        agregarEnUrna(Urnas, vector[j], vector[j]);
    }

    int i = 1;
    while (EsVacia(Urnas, i) && i < m - 1) {
        i = i + 1;
    }

    for (int j = i + 1; j < m; ++j) {
        EnlazarUrna(Urnas, j, i);
    }

    int j = 0;
    int dir = 1;

    while (dir != 0) {
        for (int k = 1; k <= Urnas[i][0]; ++k) {
            vector[j++] = Urnas[i][k];
        }
        dir = 0;
    }
    for (int i = 0; i < m; ++i) {
        delete[] Urnas[i];
    }
    delete[] Urnas;
}
template <typename T>
void mezclar(T arr[], int izquierda, int medio, int derecha) {
    int n1 = medio - izquierda + 1;
    int n2 = derecha - medio;

    T* L = new T[n1];
    T* R = new T[n2];

    for (int i = 0; i < n1; ++i) L[i] = arr[izquierda + i];
    for (int j = 0; j < n2; ++j) R[j] = arr[medio + 1 + j];

    int i = 0, j = 0, k = izquierda;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k++] = L[i++];
        } else {
            arr[k++] = R[j++];
        }
    }
    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];

    delete[] L;
    delete[] R;
}

template <typename T>
void mezclaDirecta(T arr[], int izquierda, int derecha) {
    if (izquierda < derecha) {
        int medio = izquierda + (derecha - izquierda) / 2;

        mezclaDirecta(arr, izquierda, medio);
        mezclaDirecta(arr, medio + 1, derecha);

        mezclar(arr, izquierda, medio, derecha);
    }
}

template <typename T>
void mezclaNatural(T arr[], int n) {
    int* inicios = new int[n + 1];
    int numInicios = 0;

    inicios[numInicios++] = 0;

    for (int i = 1; i < n; ++i) {
        if (arr[i] < arr[i - 1]) {
            inicios[numInicios++] = i;
        }
    }
    inicios[numInicios++] = n;

    for (int i = 1; i < numInicios; ++i) {
        int izquierda = inicios[i - 1];
        int derecha = inicios[i];
        int medio = izquierda + (derecha - izquierda) / 2 - 1;

        mezclar(arr, izquierda, medio, derecha - 1);
    }

    delete[] inicios;
}

template <typename T>
int maximo(T a[], int n){
    double mayor = a[0].getPromedio();
    for(int i = 1; i <n; i++){
        if(mayor < a[i].getPromedio()){
            mayor = a[i].getPromedio();
        }
    }
    return mayor;
}

template <typename T>
void ordenamientoPorConteo(T a[], int n, int exp) {
    int salida[n];
    int conteo[10] = {0};

    for (int i = 0; i < n; i++) {
        int indice = (a[i].getPromedio() / exp) % 10;
        conteo[indice]++;
    }


    for (int i = 1; i < 10; i++) {
        conteo[i] += conteo[i - 1];
    }


    for (int i = n - 1; i >= 0; i--) {
        int indice = (a[i].getPromedio() / exp) % 10;
        salida[conteo[indice] - 1] = a[i];
        conteo[indice]--;
    }

    for (int i = 0; i < n; i++) {
        a[i] = salida[i];
    }
}

template <typename T>
void ordenarRadix(T a[], int n){
    double max1=maximo(a,n);
    int exp = 1;
    while ((max1/exp)>=1){
        ordenamientoPorConteo(a,n,exp);
        exp*=10;
    }
}




