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

    void imprimirDatostxt(ofstream& impresion){

        impresion<< nombre;
        if(nombre.size()<7){
            impresion<<"\t\t"<<apellido;
        }else{
            impresion<<"\t"<<apellido;
        }
        if(apellido.size()<7){
            impresion<<"\t\t"<<correo;
        }else{
            impresion<<"\t"<<correo;
        }
        if(correo.size()<7){
            impresion<<"\t\t";
        }else{
            impresion<<"\t";
        }

        for(int i = 0; i<N; i++){
            impresion<< notas[i]<<"\t";
        }
        impresion << promedio << endl;


    }

        void imprimirDatos(){

        cout<< nombre;
        if(nombre.size()<10){
            cout<<"\t\t"<<apellido;
        }else{
            cout<<"\t"<<apellido;
        }
<<<<<<< HEAD
        if(apellido.size()<10){
            cout<<"\t\t" << correo;
=======
        if(apellido.size()<7){
            cout<<"\t\t"<<correo;
        }else{
            cout<<"\t"<<correo;
        }
        if(correo.size()<7){
            cout<<"\t\t";
>>>>>>> 5e50d1a67c563c84dc5d418847ebfe6e6d9bf86c
        }else{
            cout<<"\t" << correo<<"\t";
        }

        for(int i = 0; i<N; i++){
            cout<<"\t"<< notas[i]<<"\t";
        }
        cout << promedio << endl;


    }
};
