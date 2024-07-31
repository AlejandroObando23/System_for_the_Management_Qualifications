#ifndef ORDENAMIENTOS_H
#define ORDENAMIENTOS_H

#include <iostream>
#include <fstream>

const int MAX = 100;
using namespace std;

template <typename T>
void ordenamientoIntercambio(T a[], int n){
    T temp;
    for(int i = 0; i < n-1; i++){
        for(int j = i+1; j < n; j++){
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
    for(int i = 0; i < n; i++){
        min = i;
        for(int j = i+1; j < n; j++){
            if(a[j].getPromedio() < a[min].getPromedio()){
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
    for(int i = 0; i < n-1; i++){
        for(int j = 0; j < n-i-1; j++){
            if(a[j].getPromedio() > a[j+1].getPromedio()){
                aux = a[j];
                a[j] = a[j+1];
                a[j+1] = aux;
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

        central = (primero + ultimo) / 2;
        pivote = a[central].getPromedio();

        i = primero;
        j = ultimo;

        do{
            while(a[i].getPromedio() < pivote) i++;
            while(a[j].getPromedio() > pivote) j--;

            if(i <= j){
                aux = a[i];
                a[i] = a[j];
                a[j] = aux;
                i++;
                j--;
            }

        }while(i <= j);

        if(primero < j) ordenamientoQuicksort(a, primero, j);
        if(i < ultimo) ordenamientoQuicksort(a, i, ultimo);
    }
}

template <typename T>
void ordenamientoShellsort(T a[], int n){
    T aux;
    for(int salto = n / 2; salto > 0; salto /= 2){
        for(int i = salto; i < n; i++){
            int j = i - salto;
            while(j >= 0){
                int k = j + salto;
                if(a[j].getPromedio() <= a[k].getPromedio()) break;
                else{
                    aux = a[j];
                    a[j] = a[k];
                    a[k] = aux;
                    j -= salto;
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
void guardarArregloEnArchivo( T arr[], int inicio, int fin, const string& nombreArchivo) {
    ofstream archivo(nombreArchivo, ios::app);
    if (archivo.is_open()) {
        archivo<< "\n========================================================================================" << endl;

        for (int i = inicio; i <= fin; ++i) {
            archivo << "N°- " << "[" <<arr[i].getPromedio() << "]" << endl;
            archivo << "Alumno: " << arr[i].getNombre() << " " << arr[i].getApellido() << endl;
        }
        archivo << endl;
        archivo.close();
    } else {
        cout << "No se pudo abrir el archivo: " << nombreArchivo << endl;
    }
}

template <typename T>
void mezclar(T arr[], int izquierda, int medio, int derecha) {
    int n1 = medio - izquierda + 1;
    int n2 = derecha - medio;

    T* L = new T[n1];
    T* R = new T[n2];

    for (int i = 0; i < n1; ++i) L[i] = arr[izquierda + i];
    for (int j = 0; j < n2; ++j) R[j] = arr[medio + 1 + j];

    guardarArregloEnArchivo(arr, izquierda, medio, "particion1.txt");
    guardarArregloEnArchivo(arr, medio + 1, derecha, "particion2.txt");

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

    guardarArregloEnArchivo(arr, izquierda, derecha, "fusion.txt");

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
void secuencias(T arr[], int n, int secuencia[], int &cont) {
    cont = 0;
    int i = 0;

    while (i < n) {
        secuencia[cont++] = i;
        while (i < n - 1 && arr[i] <= arr[i + 1])
            i++;
        i++;
    }
}

template <typename T>
void mezclaNatural(T arr[], int n) {
    if (n <= 1)
        return;

    int* secuencia = new int[n + 1]; // Lista de índices de inicio de subsecuencias ordenadas
    int cont = 0;

    while (true) {
        secuencias(arr, n, secuencia, cont);

        // Si solo hay una subsecuencia, la lista ya está ordenada
        if (cont == 1)
            break;

        // Fusión de las subsecuencias
        for (int i = 0; i < cont - 1; i += 2) {
            int izq = secuencia[i];
            int med = secuencia[i + 1] - 1;
            int der = (i + 2 < cont) ? secuencia[i + 2] - 1 : n - 1;

            mezclar(arr, izq, med, der);
        }
    }

    delete[] secuencia;
}

template <typename T>
T maximo(T a[], int n){
    T mayor = a[0];
    for(int i = 1; i < n; i++){
        if(mayor.getPromedio() < a[i].getPromedio()){
            mayor = a[i];
        }
    }
    return mayor;
}

template <typename T>
void ordenamientoPorConteo(T a[], int n, int exp) {
    T* salida = new T[n];
    int conteo[10] = {0};

    for (int i = 0; i < n; i++) {
        int indice = static_cast<int>(a[i].getPromedio() / exp) % 10;
        conteo[indice]++;
    }

    for (int i = 1; i < 10; i++) {
        conteo[i] += conteo[i - 1];
    }

    for (int i = n - 1; i >= 0; i--) {
        int indice = static_cast<int>(a[i].getPromedio() / exp) % 10;
        salida[conteo[indice] - 1] = a[i];
        conteo[indice]--;
    }

    for (int i = 0; i < n; i++) {
        a[i] = salida[i];
    }
    delete[] salida;
}

template <typename T>
void ordenarRadix(T a[], int n){
    T max1 = maximo(a, n);
    int exp = 1;
    while ((static_cast<int>(max1.getPromedio()) / exp) >= 1){
        ordenamientoPorConteo(a, n, exp);
        exp *= 10;
    }
}

#endif





