#include <iostream>
#include <string>
#include <cmath>

using namespace std;

class Estudiante
{
private:
    string nombre;
    string apellido;
    string correo;
    double *notas;
    double promedio;
    int N;

public:
    Estudiante() {}

    void setNotas(int n)
    {
        notas = new double[n];
        N = n;
    }

    void setNombre(string n)
    {
        nombre=n;
    }
    void setApellido(string a)
    {
        apellido=a;
    }

    void setCorreo(string c)
    {
        correo = c;
    }

    bool validarCorreo()
    {
        string patron = nombre + "@espe.edu.ec";
        return correo == patron;
    }

    void ingresoNota(int i, double n)
    {
        notas[i] = n;
    }

    void promediar()
    {
        double suma=0;
        for(int i = 0; i<N; i++)
        {
            suma = suma + notas[i];
        }
        double valor = suma/N;
        promedio = round(valor * 100.0) / 100.0;
    }

    void setPromedio(double n)
    {
        promedio = n;
    }

    double getPromedio()const
    {
        return promedio;
    }

    string getNombre()
    {
        return nombre;
    }

    string getApellido()
    {
        return apellido;
    }

    string getCorreo()
    {
        return correo;
    }

    void imprimirDatostxt(ofstream& impresion)
    {

        impresion<< nombre;
        if(nombre.size()<7)
        {
            impresion<<"\t\t"<<apellido;
        }
        else
        {
            impresion<<"\t"<<apellido;
        }
        if(apellido.size()<7)
        {
            impresion<<"\t\t"<<correo;
        }
        else
        {
            impresion<<"\t"<<correo;
        }
        if(correo.size()<7)
        {
            impresion<<"\t\t";
        }
        else
        {
            impresion<<"\t";
        }

        for(int i = 0; i<N; i++)
        {
            impresion<< notas[i]<<"\t";
        }
        impresion << promedio << endl;


    }

    void imprimirDatos()
    {

        cout<< nombre;
        if(nombre.size()<7)
        {
            cout<<"\t\t"<<apellido;
        }
        else
        {
            cout<<"\t"<<apellido;
        }
        if(apellido.size()<7)
        {
            cout<<"\t\t"<<correo;
        }
        else
        {
            cout<<"\t"<<correo;
        }
        if(correo.size()<7)
        {
            cout<<"\t\t";
        }
        else
        {
            cout<<"\t";
        }

        for(int i = 0; i<N; i++)
        {
            cout<< notas[i]<<"\t";
        }
        cout << promedio << endl;


    }

    bool operator<=(const Estudiante& otro) const
    {
        return this->getPromedio() <= otro.getPromedio();
    }

};
