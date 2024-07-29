#include <iostream>

using namespace std;

template <typename T>
class tablaHash{
private:
    int N;
    T *tabla;
public:
    tablaHash(int a):N(a){
        tabla = new T[N];
    }

    ~tablaHash(){
        delete []tabla;
    }

    void crearTabla(){
        for(int i = 0; i<N;i++){
            tabla[i].setPromedio(-1) ;
        }
    }

    void insertarElementos(T a[]){
        for(int i = 0; i<N-1;i++){
            int index = (int)a[i].getPromedio()%(N-2);

            if(tabla[index].getPromedio()==-1){
                tabla[index]= a[i];
            }else{
                while(tabla[index].getPromedio()!= -1){
                    index++;
                }
                tabla[index]= a[i];
            }
        }
    }

int buscarElementos(double n) {
    int index = (int)n % (N - 2);
    while (true) {
        if (tabla[index].getPromedio() == n) {
            return index;
        } else if (tabla[index].getPromedio() == -1 || index == N - 1) {
            return -1;
        }
        index++;
        if (index >= N) {
            return -1;
        }
    }
}


    T recuperarElemento(int index){
        return tabla[index];
    }

};

template <typename T>
int busquedaLineal(T arr[], int size, double valor) {
    for (int i = 0; i < size; ++i) {
        if (arr[i].getPromedio() == valor) {
            return i;
        }
    }
    return -1;
}

template <typename T>
int busquedaBinaria(T arr[], int izquierda, int derecha, double valor) {
    while (izquierda <= derecha) {
        int medio = izquierda + (derecha - izquierda) / 2;

        if (arr[medio].getPromedio() == valor) {
            return medio;
        }

        if (arr[medio].getPromedio() < valor) {
            izquierda = medio + 1;
        } else {
            derecha = medio - 1;
        }
    }
    return -1;
}

template <typename T>
void ordenarPorPromedio(T arr[], int tamano) {
    for (int i = 0; i < tamano - 1; ++i) {
        for (int j = 0; j < tamano - i - 1; ++j) {
            if (arr[j].getPromedio() > arr[j + 1].getPromedio()) {
                T temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}



