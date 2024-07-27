#include <iostream>
#include <string>

using namespace std;

template <int N>
class Estudiante{
private:
    string nombre;
    string apellido;
    double notas[N];
    double promedio;

public:

    Estudiante(string nom, string ape): nombre(nom), apellido(ape){}

    void calcularPromedio(){
        suma = 0;
        for(int i = 0, i<N, i++){
            suma = suma + notas[i];
        }
        promedio = suma/N;
    }

};
