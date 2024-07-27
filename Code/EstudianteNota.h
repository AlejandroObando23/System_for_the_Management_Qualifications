#include <iostream>
#include <string>

using namespace std;

class Estudiante{
private:
    string nombre;
    string apellido;
    double *notas;
    double promedio;
    int N;

public:
    Estudiante(){}

    void setNotas(int n){
        notas = new double[n];
        N = n;
    }

    void setNombre(string n){
        nombre=n;
    }
    void setApellido(string a){
        apellido=a;
    }
    void ingresoNota(int i, double n){
        notas[i] = n;
    }

    void promediar(){
        double suma;
        for(int i = 0; i<N; i++){
            suma = suma + notas[i];
        }
        promedio = suma/N;
    }
};
