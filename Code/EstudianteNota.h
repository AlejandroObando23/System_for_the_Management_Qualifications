#include <iostream>
#include <string>

using namespace std;

class Estudiante{
private:
    string nombre;
    string apellido;
    string correo;
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

    void setCorreo(string c) {
        correo = c;
    }

    bool validarCorreo() {
        string patron = nombre + "@espe.edu.ec";
        return correo == patron;
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

    void setPromedio(double n){
        promedio = n;
    }

    double getPromedio(){
        return promedio;
    }

    string getNombre(){
        return nombre;
    }

    string getApellido(){
        return apellido;
    }

    string getCorreo() {
        return correo;
    }

    void imprimirDatos(){

        cout<< nombre;
        if(nombre.size()<7){
            cout<<"\t\t"<<apellido;
        }else{
            cout<<"\t"<<apellido;
        }
        if(apellido.size()<7){
            cout<<"\t\t";
        }else{
            cout<<"\t";
        }

        for(int i = 0; i<N; i++){
            cout<< notas[i]<<"\t";
        }
        cout << promedio << endl;
        cout << correo << endl;

    }
};
