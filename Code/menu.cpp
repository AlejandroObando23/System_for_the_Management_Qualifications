#include <iostream>
#include <conio.h>
#include <cctype>
#include <windows.h>
#include <fstream>
#include "EstudianteNota.h"
#include "Busquedas.h"
#include "Ordenamientos.h"
#define ANSI_BACKGROUND_BLUE "\033[44m"
#define ANSI_BACKGROUND_RESET "\033[0m"
using namespace std;

struct Materia
{
    string nombre;
    string NRC;
};
string nombremaestra;
string cedulamaestra;

Materia materia;
void menuBienvenida();
void mostrarInformacionMateria();
int escogerMetodoOrdenacion();
int escogerMetodoBusqueda();

int busquedaLineal(Estudiante arr[], int size, const Estudiante& key);

bool esSoloLetras(const string& cadena)
{
    for (char c : cadena)
    {
        if (!isalpha(c))
        {
            return false;
        }
    }
    return true;
}



int validarNumero(char numero[])
{
    int i;
    for(i = 0; i<strlen(numero); i++)
    {
        if(!isdigit(numero[i]))
        {
            if(numero[i] != '.')
            {
                MessageBeep(MB_ICONHAND);
                cout << "Ingrese un valor valido" << endl;
                return 0;
            }
        }
    }
    return 1;
}

void mostrarMenuPrincipal(int opcionActual)
{

    SetConsoleOutputCP(CP_UTF8);
    mostrarInformacionMateria();
    cout << "\n\tSeleccione una opción:\n" << endl;
    cout << "\t╔══════════════════════════════════╗" << endl;
    for (int i = 1; i <= 7; i++)
    {
        if (i == opcionActual)
        {
            printf("%s", ANSI_BACKGROUND_BLUE);
        }
        else
        {
            printf("%s", ANSI_BACKGROUND_RESET);
        }

        cout << "\t║ ";
        switch (i)
        {
        case 1:
            cout << "1. Ingresar Materia y Nrc        ";
            break;
        case 2:
            cout << "2. Ingresar #Estudiantes y #Notas";
            break;
        case 3:
            cout << "3. Ingreso de notas por estud.   ";
            break;
        case 4:
            cout << "4. ver notas                     ";
            break;
        case 5:
            cout << "5. Ordenamiento                  ";
            break;
        case 6:
            cout << "6. Búsqueda                      ";
            break;
        case 7:
            cout << "7. Salir                         ";
            break;
        }
        cout << "║" << endl;
    }
    printf("%s", ANSI_BACKGROUND_RESET);
    cout << "\t╚══════════════════════════════════╝" << endl;
}
int escogerOpcion()
{
    int opcionActual=1;
    while(1)
    {
        system("cls");
        mostrarMenuPrincipal(opcionActual);
        char tecla =_getch();
        switch(tecla)
        {
        case 72:
            opcionActual=(opcionActual>1)?opcionActual-1:7;
            break;
        case 80:
            opcionActual=opcionActual<7?opcionActual+1:1;
            break;
        case 13:
            system("cls");
            switch(opcionActual)
            {
            case 1:
                return 1;
                break;
            case 2:
                return 2;
                break;
            case 3:
                return 3;
                break;
            case 4:
                return 4;
                break;
            case 5:
                return 5;
                break;
            case 6:
                return 6;
                break;
            case 7:
                return 7;
                break;

            };
            break;
        }
    }
}
void menu()
{

    bool salir = false, notasIngresadas = false;
    int opcion,metodoOrdenacion,metodoBusqueda;
    int numEstudiantes=-1, numNotas=-1;
    Estudiante *estudiante;

    do
    {
        opcion = escogerOpcion();

        switch(opcion)
        {
        case 1:
        {
            cout<<"═════════════════════════════════" << endl;
            cout << "\tINGRESO MATERIA Y NRC" << endl;
            cout<<"═════════════════════════════════" << endl;

            char validar[10];
            int N;
            do
            {
                cout << "\nIngrese el NRC: ";
                cin>> validar;
                N = validarNumero(validar);
                if(N == 1)
                {
                    materia.NRC = validar;
                }
                else
                {
                    MessageBeep(MB_ICONHAND);
                }
            }
            while(N == 0);
            cout <<"\nIngrese la materia: ";
            cin.ignore();
            getline(cin, materia.nombre);

            break;
        }
        case 2:
            if(materia.NRC != "")
            {
                cout<<"═════════════════════════════════" << endl;
                cout << "\tINGRESO #Estudiantes y #Notas" << endl;
                cout<<"═════════════════════════════════" << endl;
                cout << "\nCuantos estudiantes desea registrar: ";
                cin >>numEstudiantes;
                cout <<"\nCuantas notas por estudiante: ";
                cin >> numNotas;
                estudiante = new Estudiante[numEstudiantes];
            }
            else
            {
                MessageBeep(MB_ICONHAND);
                cout << "\n========================================================================================" << endl;
                cout << "Por favor Ingrese la materia y el NRC correspondientes" << endl;
                cout << "========================================================================================" << endl;
            }
            break;
        case 3:
        {
            if((materia.NRC != "") && (numNotas != -1))
            {
                cout<<"═════════════════════════════════════════" << endl;
                cout << "\tINGRESO de notas por estudiante" << endl;
                cout<<"═════════════════════════════════════════" << endl;

                for(int i=0; i< numEstudiantes; i++)
                {
                    estudiante[i].setNotas(numNotas);
                    fflush(stdin);
                    string nombre, apellido, correo;
                    cout << "\n=== ESTUDIANTE #" << i+1 << " ==="<< endl;

                    while (true)
                    {
                        cout << "Ingrese el nombre del estudiante: ";
                        cin >> nombre ;



                        if (esSoloLetras(nombre))
                        {
                            break;
                        }
                        else
                        {
                            cout << "La entrada contiene caracteres no permitidos (Numeros). Porfavor ingrese correctamente su nombre" << endl;
                        }
                    }

                    estudiante[i].setNombre(nombre);

                    while (true)
                    {
                        cout << "Ingrese el apellido del estudiante:";
                        cin >> apellido ;
                        if (esSoloLetras(apellido))
                        {
                            break;
                        }
                        else
                        {
                            cout << "La entrada contiene caracteres no permitidos (Numeros). Porfavor ingrese correctamente su apellido" << endl;
                        }
                    }
                    estudiante[i].setApellido(apellido);
                    while (true)
                    {
                        cout << "Ingrese el correo del estudiante (ej. nombre@espe.edu.ec): ";
                        cin >> correo;
                        if (correo.find('@') != string::npos && correo.find('.') != string::npos)
                        {
                            break;
                        }
                        else
                        {
                            cout << "Correo electrónico no válido. Por favor, ingrese un correo válido." << endl;
                        }
                    }
                    estudiante[i].setCorreo(correo);
                    cout << endl;
                    for(int j = 0; j< numNotas; j++)
                    {
                        fflush(stdin);
                        char validar[5];
                        int N;
                        double nota;
                        do
                        {
                            cout << "Ingrese la nota #" << j+1 << ": ";
                            cin >> validar;
                            N=validarNumero(validar);

                            if( N != 0)
                            {
                                nota = atof(validar);
                                if((nota>= 0) && (nota <=20))
                                {
                                    estudiante[i].ingresoNota(j,nota);
                                }
                                else
                                {
                                    N = 0;
                                    cout << "==== Ingrese una nota entre 0 y 20 ====" << endl;
                                    MessageBeep(MB_ICONHAND);
                                }
                            }
                        }
                        while(N == 0);
                    }
                    estudiante[i].promediar();
                }
                notasIngresadas = true;
            }
            else
            {
                MessageBeep(MB_ICONHAND);
                cout << "\n========================================================================================" << endl;
                cout << "Por favor Ingrese la información de #alumnos y notas o registre correctamente la materia" << endl;
                cout << "========================================================================================" << endl;
            }
            break;
        }
        case 4:

            if(notasIngresadas)
            {
                string imprimirif;
                double promediocurso;
                int aprobados=0;
                int suspendidos=0;
                int reprobados=0;

                cout << "\n========================================================================================" << endl;
                cout << "                 UNIDAD EDUCATIVA GOTITAS DEL SABER" << endl;
                cout << "                 REPORTE DE CALIFICACIONES" << endl;
                cout << "PERIODO: Mayo 2024 - Septiembre 2024" << endl;
                cout << "Materia: " << materia.nombre<<endl;
                cout << "NRC: " << materia.NRC<<endl;
                cout<<"Nombre"<<"\t\t"<<"Apellido"<<"\t\t"<<"Correo"<<"\t\t";
                for (int i = 1; i <= numNotas; i++)
                {
                    cout<<"N"<<i<<"\t";
                }
                cout<<"Promedio"<<endl;

                for (int i = 0; i < numEstudiantes; i++)
                {

                    estudiante[i].imprimirDatos();
                    promediocurso=estudiante[i].getPromedio() + promediocurso;
                    if(14<estudiante[i].getPromedio())
                    {
                        aprobados++;
                    }
                    else if(14>estudiante[i].getPromedio() && 9<estudiante[i].getPromedio())
                    {
                        suspendidos++;

                    }
                    else
                    {
                        reprobados++;
                    }
                }
                promediocurso=promediocurso/numEstudiantes;
                cout<<endl<<"Promedio general del curso es: "<<promediocurso<<endl;
                cout<<"Aprobado: "<<aprobados<<endl;
                cout<<"Suspendidos: "<<suspendidos<<endl;
                cout<<"Reprobados: "<<reprobados<<endl;
                cout<<endl<<"\n\t\t---------------------------"<<endl;
                cout<<"\t\t\t"<<"Docente"<<endl;
                cout<<"\t\t\t"<<nombremaestra<<endl;
                cout<<"\t\t\t"<<cedulamaestra<<endl;


                cout<<endl<<"Desea imprimir en un txt.Para imprimir coloque [Y]"<<endl;
                cin>>imprimirif;
                if(imprimirif=="Y")
                {
                    ofstream impresion;
                    impresion.open("RegistroAsistencia.txt", ios::app);
                    impresion << "\n========================================================================================" << endl;
                    impresion << "                 UNIDAD EDUCATIVA GOTITAS DEL SABER" << endl;
                    impresion << "                 REPORTE DE CALIFICACIONES" << endl;
                    impresion << "PERIODO: Mayo 2024 - Septiembre 2024" << endl;
                    impresion << "Materia: " << materia.nombre<<endl;
                    impresion << "NRC: " << materia.NRC<<endl;
                    impresion<<"Nombre"<<"\t\t"<<"Apellido"<<"\t\t"<<"Correo"<<"\t\t";
                    for (int i = 1; i <= numNotas; i++)
                    {
                        impresion<<"N"<<i<<"\t";
                    }
                    impresion<<"Promedio"<<endl;
                    for (int i = 0; i < numEstudiantes; i++)
                    {
                        estudiante[i].imprimirDatostxt(impresion);
                    }
                    impresion<<endl<<"Promedio general del curso es: "<<promediocurso<<endl;
                    impresion<<"Aprobado: "<<aprobados<<endl;
                    impresion<<"Suspendidos: "<<suspendidos<<endl;
                    impresion<<"Reprobados: "<<reprobados<<endl;
                    impresion<<"\n\t\t---------------------------"<<endl;
                    impresion<<"\t\t\t"<<"Docente"<<endl;
                    impresion<<"\t\t\t"<<nombremaestra<<endl;
                    impresion<<"\t\t\t"<<cedulamaestra<<endl;

                    impresion.close();
                    cout<<"Imprimiendo TXT"<<endl;


                }
                else
                {
                    cout<<"Regresando al menu principal"<<endl;

                }

            }
            else
            {
                MessageBeep(MB_ICONHAND);
                cout << "\n========================================================================================" << endl;
                cout << "Aun no se han registrado calificaciones dentro del sistema, por favor registre los datos" << endl;
                cout << "========================================================================================" << endl;
            }
            break;
        case 5:
        {
            bool regresar = false;
            if(notasIngresadas)
            {
                ofstream impresion;
                impresion.open("ordenamiento.txt", ios::app);
                Estudiante estudiantesOrdenados[numEstudiantes];
                for(int i =0; i< numEstudiantes; i++)
                {
                    estudiantesOrdenados[i]=estudiante[i];
                }
                metodoOrdenacion = escogerMetodoOrdenacion();

                if((metodoOrdenacion != 10) && (metodoOrdenacion != 8) && (metodoOrdenacion != 9))
                {
                    impresion << "\n========================================================================================" << endl;
                    impresion << "                 UNIDAD EDUCATIVA GOTITAS DEL SABER" << endl;
                    impresion << "                 REPORTE DE CALIFICACIONES ORDENADAS" << endl;
                    impresion << "\nCalificaciones Ordenadas" << endl;
                }

                switch (metodoOrdenacion){
                case 1:
                    cout << "Método de Intercambio Simple seleccionado." << endl;
                    ordenamientoIntercambio(estudiantesOrdenados, numEstudiantes);
                    impresion<<"ALGORITMO: Intercambio Simple" <<endl;
                    break;
                case 2:
                    cout << "Método de Selección seleccionado." << endl;
                    ordenamientoSeleccion(estudiantesOrdenados, numEstudiantes);
                    impresion<<"ALGORITMO: Selección" <<endl;
                    break;
                case 3:
                    cout << "Método de Burbuja seleccionado." << endl;
                    ordenamientoBurbuja(estudiantesOrdenados, numEstudiantes);
                    impresion<<"ALGORITMO: Burbuja" <<endl;
                    break;
                case 4:
                    cout << "Método de Quicksort seleccionado." << endl;
                    ordenamientoQuicksort(estudiantesOrdenados,0, numEstudiantes-1);
                    impresion<<"ALGORITMO: QuickSort" <<endl;
                    break;
                case 5:
                    cout << "Método de Shellsort seleccionado." << endl;
                    ordenamientoShellsort(estudiantesOrdenados, numEstudiantes);
                    impresion<<"ALGORITMO: ShellSort" <<endl;
                    break;
                case 6:
                    cout << "Método de BucketSort seleccionado." << endl;
                    //bucketSort(estudiantesOrdenados, numEstudiantes, MAX);

                    break;
                case 7:
                    cout << "Método de Radixsort seleccionado." << endl;
                    ordenarRadix(estudiantesOrdenados, numEstudiantes);
                    impresion<<"ALGORITMO: RadixSort" <<endl;
                    break;
                case 8:
                    cout << "Método de Mezcla Directa seleccionado." << endl;
                    mezclaDirecta(estudiantesOrdenados, 0, numEstudiantes - 1);
                    break;
                case 9:
                    cout << "Método de Mezcla Natural seleccionado." << endl;
                    mezclaNatural(estudiantesOrdenados, numEstudiantes);
                    break;
                case 10:
                    cout <<"regresando al menu"<<endl;
                    regresar =true;
                    break;
                }

                if(!regresar)
                {
                    cout << "Los datos ordenados son: " << endl;
                    cout<<"Nombre"<<"\t\t"<<"Apellido"<<"\t";

                    for (int i = 1; i <= numNotas; i++)
                    {
                        cout<<"N"<<i<<"\t";

                    }
                    cout<<"Promedio\n"<<endl;

                    for (int i = 0; i < numEstudiantes; i++)
                    {
                        estudiantesOrdenados[i].imprimirDatos();
                    }
                    cout<<endl<<"\n\t\t---------------------------"<<endl;
                    cout<<"\t\t\t"<<"Docente"<<endl;
                    cout<<"\t\t\t"<<nombremaestra<<endl;
                    cout<<"\t\t\t"<<cedulamaestra<<endl;


                    if((metodoOrdenacion != 10) && (metodoOrdenacion != 8) && (metodoOrdenacion != 9))
                    {
                        for (int i = 0; i < numEstudiantes; i++)
                        {
                            impresion << "N°- " << "[" <<estudiantesOrdenados[i].getPromedio() << "]" << endl;
                            impresion << "Alumno: " << estudiantesOrdenados[i].getNombre() << " " << estudiantesOrdenados[i].getApellido() << endl;
                        }
                        impresion<<"\n\t\t---------------------------"<<endl;
                        impresion<<"\t\t\t"<<"Docente"<<endl;
                        impresion<<"\t\t\t"<<nombremaestra<<endl;
                        impresion<<"\t\t\t"<<cedulamaestra<<endl;
                        impresion.close();


                    }


                }
            }
            else
            {
                MessageBeep(MB_ICONHAND);
                cout << "\n========================================================================================" << endl;
                cout << "Aun no se han registrado calificaciones dentro del sistema, por favor registre los datos" << endl;
                cout << "========================================================================================" << endl;
            }
            break;
        }
        case 6:
        {
            tablaHash<Estudiante> tabla(numEstudiantes + 1);
            double calificacion;
            int index=-1;
            Estudiante estudianteEncontrado;
            ofstream impresion;
            impresion.open("busqueda.txt", ios::app);

            if(notasIngresadas)
            {
                metodoBusqueda = escogerMetodoBusqueda();
                if(metodoBusqueda != 4)
                {
                    cout << "Ingrese el promedio que desea buscar: ";
                    cin >> calificacion;
                    impresion << "\n========================================================================================" << endl;
                    impresion << "                 UNIDAD EDUCATIVA GOTITAS DEL SABER" << endl;
                    impresion << "                 REPORTE DE CALIFICACIONES ORDENADAS" << endl;

                    impresion << "\n Búqueda de calificaciones"<<endl;
                    impresion << "\n La calificación a buscar fue: " << calificacion << endl;

                }
                switch (metodoBusqueda)
                {
                case 1:
                {
                    cout << "Método de Búsqueda Lineal seleccionado." << endl;
                    index = busquedaLineal(estudiante, numEstudiantes, calificacion);
                    if (index != -1)
                    {
                        estudianteEncontrado = estudiante[index];
                        impresion << "\nALGORITMO: Busqueda Lineal" << endl;
                    }
                    break;
                }

                case 2:
                {
                    cout << "Método de Búsqueda Binaria seleccionado." << endl;
                    ordenarPorPromedio(estudiante, numEstudiantes);

                    index = busquedaBinaria(estudiante, 0, numEstudiantes - 1, calificacion);
                    if (index != -1)
                    {
                        estudianteEncontrado = estudiante[index];
                        impresion << "\nALGORITMO: Busqueda Binaria" << endl;
                    }
                    break;
                }

                case 3:
                {
                    cout << "Método de Búsqueda Hash seleccionado." << endl;
                    tabla.crearTabla();
                    tabla.insertarElementos(estudiante);
                    index = tabla.buscarElementos(calificacion);
                    if (index != -1)
                    {
                        estudianteEncontrado = tabla.recuperarElemento(index);
                        impresion << "\nALGORITMO: Busqueda Hash" << endl;
                    }
                    break;
                }
                case 4:
                    cout << "Regresando al menú principal." << endl;
                    break;
                }

                if((index != -1) && (metodoBusqueda != 4))
                {
                    cout << "La calificación a buscar fue de " << calificacion << ": " << endl;
                    cout << "\nCorresponde al estudiante: " << endl;
                    cout << "Alumno: " << estudianteEncontrado.getNombre() << " " << estudianteEncontrado.getApellido() << endl;
                    cout << "Promedio: " << estudianteEncontrado.getPromedio() << endl;
                    cout << "index: " << index << endl;

                    impresion << "\nCorresponde al estudiante: " << endl;
                    impresion << "Alumno: " << estudianteEncontrado.getNombre() << " " << estudianteEncontrado.getApellido() << endl;
                    impresion << "Promedio: " << estudianteEncontrado.getPromedio() << endl;
                    impresion << "index: " << index << endl;
                    cout<<endl<<"\t\t---------------------------"<<endl;
                    cout<<"\t\t\t"<<"Docente"<<endl;
                    cout<<"\t\t\t"<<nombremaestra<<endl;
                    cout<<"\t\t\t"<<cedulamaestra<<endl;
                }
                else if(metodoBusqueda !=4)
                {
                    cout << "Calificación no encontrada." << endl;
                    impresion << "Calificación no encontrada." << endl;
                }
                impresion.close();
            }
            else
            {
                MessageBeep(MB_ICONHAND);
                cout << "\n========================================================================================" << endl;
                cout << "Aun no se han registrado calificaciones dentro del sistema, por favor registre los datos" << endl;
                cout << "========================================================================================" << endl;
            }
            break;
        }
        case 7:
            salir = true;
            break;
        }
        system("pause");
    }
    while(!salir);


}

int main()
{

    menuBienvenida();
    menu();

    return 0;

}


bool validarCedula(const string& cedula)
{
    if (cedula.length() != 10)
    {
        return false;
    }
    for (char c : cedula)
    {
        if (!isdigit(c))
        {
            return false;
        }
    }

    int suma =0;
    for(int i =0; i<9; i++)
    {
        int digito = cedula[i]- '0';
        if(i%2==0)
        {
            digito*=2;
            if(digito>9)
            {
                digito-=9;
            }
        }
        suma += digito;
    }
    int verificar = cedula[9]- '0';
    int ultimodigito;
    if (suma % 10 == 0)
    {
        ultimodigito =0;
    }
    else
    {
        ultimodigito = 10 - (suma % 10);
    }
    return ultimodigito == verificar;
}

void menuBienvenida()
{

    SetConsoleOutputCP(CP_UTF8);

    cout << "╔═══════════════════════════════════╗\n";
    cout << "║                                   ║\n";
    cout << "║  UNIDAD EDUCATIVA DATA STRUCTURE  ║\n";
    cout << "║         SISTEMA DE NOTAS          ║\n";
    cout << "║                                   ║\n";
    cout << "╚═══════════════════════════════════╝\n";
    cout << "Por favor, ingrese sus datos" <<endl;
    while (true)
    {
        cout << "\nIngrese su nombre: ";
        cin >> nombremaestra ;



        if (esSoloLetras(nombremaestra))
        {
            break;
        }
        else
        {
            cout << "La entrada contiene caracteres no permitidos. Porfavor ingrese correctamente su nombre" << endl;
        }
    }


    fflush(stdin);
    fflush(stdin);
    while (true)
    {
        cout << "Ingrese su cédula: ";
        cin >> cedulamaestra;

        if (validarCedula(cedulamaestra))
        {
            cout << "Acceso concedido.\n";
            system("cls");
            break;
        }
        else
        {
            MessageBeep(MB_ICONHAND);
            cout << "Cédula no válida. Debe ingresar una cedula correcta.\n";
        }
    }
}

void mostrarMenuOrdenacion(int opcionActual)
{
    SetConsoleOutputCP(CP_UTF8);
    cout << "\t----ALGORITMOS DE ORDENACION----\n" << endl;
    cout << "\t╔═══════════════════════════════════╗" << endl;
    for (int i = 1; i <= 10; i++)
    {
        if (i == opcionActual)
        {
            printf("%s", ANSI_BACKGROUND_BLUE);
        }
        else
        {
            printf("%s", ANSI_BACKGROUND_RESET);
        }

        cout << "\t║ ";
        switch (i)
        {
        case 1:
            cout << "1. Intercambio Simple             ";
            break;
        case 2:
            cout << "2. Seleccion                      ";
            break;
        case 3:
            cout << "3. Burbuja                        ";
            break;
        case 4:
            cout << "4. Quicksort                      ";
            break;
        case 5:
            cout << "5. Shellsort                      ";
            break;
        case 6:
            cout << "6. BucketSort                     ";
            break;
        case 7:
            cout << "7. Radixsort                      ";
            break;
        case 8:
            cout << "8. Mezcla Directa                 ";
            break;
        case 9:
            cout << "9. Mezcla Natural                 ";
            break;
        case 10:
            cout << "10. Regresar                       ";
            break;
        }
        cout << "║" << endl;
    }
    printf("%s", ANSI_BACKGROUND_RESET);
    cout << "\t╚═══════════════════════════════════╝" << endl;
}

int escogerMetodoOrdenacion()
{
    int opcionActual = 1;
    while (1)
    {
        system("cls");
        mostrarMenuOrdenacion(opcionActual);
        char tecla = _getch();
        switch (tecla)
        {
        case 72:
            opcionActual = (opcionActual > 1) ? opcionActual - 1 : 10;
            break;
        case 80:
            opcionActual = (opcionActual < 10) ? opcionActual + 1 : 1;
            break;
        case 13:
            system("cls");
            return opcionActual;
        }
    }
}

void mostrarInformacionMateria()
{
    SetConsoleOutputCP(CP_UTF8);
    cout << "\t╔═════════════════════════════════════════╗" << endl;
    cout << "\t║ Materia: " << materia.nombre;
    for (int i = 0; i < 31 - materia.nombre.length(); ++i) cout << " ";
    cout << "║" << endl;
    cout << "\t║ NRC: " << materia.NRC;
    for (int i = 0; i < 35 - materia.NRC.length(); ++i) cout << " ";
    cout << "║" << endl;
    cout << "\t╚═════════════════════════════════════════╝" << endl;
}

void mostrarMenuBusqueda(int opcionActual)
{
    SetConsoleOutputCP(CP_UTF8);
    cout << "\t----MÉTODOS DE BÚSQUEDA----\n" << endl;
    cout << "\t╔═══════════════════════════════════╗" << endl;
    for (int i = 1; i <= 4; i++)
    {
        if (i == opcionActual)
        {
            printf("%s", ANSI_BACKGROUND_BLUE);
        }
        else
        {
            printf("%s", ANSI_BACKGROUND_RESET);
        }

        cout << "\t║ ";
        switch (i)
        {
        case 1:
            cout << "1. Búsqueda Lineal                ";
            break;
        case 2:
            cout << "2. Búsqueda Binaria               ";
            break;
        case 3:
            cout << "3. Búsqueda Hash                  ";
            break;
        case 4:
            cout << "4. Regresar                       ";
            break;
        }
        cout << "║" << endl;
    }
    printf("%s", ANSI_BACKGROUND_RESET);
    cout << "\t╚═══════════════════════════════════╝" << endl;
}

int escogerMetodoBusqueda()
{
    int opcionActual = 1;
    while (1)
    {
        system("cls");
        mostrarMenuBusqueda(opcionActual);
        char tecla = _getch();
        switch (tecla)
        {
        case 72:
            opcionActual = (opcionActual > 1) ? opcionActual - 1 : 4;
            break;
        case 80:
            opcionActual = (opcionActual < 4) ? opcionActual + 1 : 1;
            break;
        case 13:
            system("cls");
            return opcionActual;
        }
    }
}

