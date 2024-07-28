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

    int buscarElementos(double n){
        int index = (int)n%(N-2);
        do{
            if(tabla[index].getPromedio() != n){
                index++;
            }else if (index == N-1){
                return -1;
            }
        }while(tabla[index].getPromedio() != n);
        return index;
    }

    T recuperarElemento(int index){
        return tabla[index];
    }

};


