#include <iostream>
#include <conio.h>
#include <cctype>
#include <windows.h>
#include "EstudianteNota.h"
#include "Ordenamientos.h"
#define ANSI_BACKGROUND_BLUE "\033[44m"
#define ANSI_BACKGROUND_RESET "\033[0m"
using namespace std;

struct Materia{
    string nombre;
    string NRC;
};

Materia materia;
void menuBienvenida();
void mostrarInformacionMateria();
int escogerMetodoOrdenacion();
int escogerMetodoBusqueda();

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

void mostrarMenuPrincipal(int opcionActual) {

    SetConsoleOutputCP(CP_UTF8);
    mostrarInformacionMateria();
    cout << "\n\tSeleccione una opción:\n" << endl;
    cout << "\t╔══════════════════════════════════╗" << endl;
    for (int i = 1; i <= 7; i++) {
        if (i == opcionActual) {
            printf("%s", ANSI_BACKGROUND_BLUE);
        } else {
            printf("%s", ANSI_BACKGROUND_RESET);
        }

        cout << "\t║ ";
        switch (i) {
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
void menu(){

    bool salir = false, notasIngresadas = false;
    int opcion,metodoOrdenacion,metodoBusqueda;
    int numEstudiantes=-1, numNotas=-1;
    Estudiante *estudiante;

    do
    {
        opcion = escogerOpcion();

        switch(opcion)
        {
        case 1:{
            cout<<"═════════════════════════════════" << endl;
            cout << "\tINGRESO MATERIA Y NRC" << endl;
            cout<<"═════════════════════════════════" << endl;

            char validar[10];
            int N;
            do{
                cout << "\nIngrese el NRC: ";
                cin>> validar;
                N = validarNumero(validar);
                if(N == 1){
                    materia.NRC = validar;
                }else{
                    MessageBeep(MB_ICONHAND);
                }
            }while(N == 0);
            cout <<"\nIngrese la materia: ";
            cin.ignore();
            getline(cin, materia.nombre);

            break;
        }
        case 2:
            if(materia.NRC != ""){
                cout<<"═════════════════════════════════" << endl;
                cout << "\tINGRESO #Estudiantes y #Notas" << endl;
                cout<<"═════════════════════════════════" << endl;
                cout << "\nCuantos estudiantes desea registrar: ";
                cin >>numEstudiantes;
                cout <<"\nCuantas notas por estudiante: ";
                cin >> numNotas;
                estudiante = new Estudiante[numEstudiantes];
            }else{
                MessageBeep(MB_ICONHAND);
                cout << "\n========================================================================================" << endl;
                cout << "Por favor Ingrese la materia y el NRC correspondientes" << endl;
                cout << "========================================================================================" << endl;
            }
            break;
        case 3:{
            if((materia.NRC != "") && (numNotas != -1)){
                cout<<"═════════════════════════════════════════" << endl;
                cout << "\tINGRESO de notas por estudiante" << endl;
                cout<<"═════════════════════════════════════════" << endl;

                for(int i=0; i< numEstudiantes;i++){
                    estudiante[i].setNotas(numNotas);
                    fflush(stdin);
                    string nombre, apellido;
                    cout << "\n=== ESTUDIANTE #" << i+1 << " ==="<< endl;
                    cout << "Ingrese el nombre del estudiante: ";
                    cin >> nombre;
                    estudiante[i].setNombre(nombre);
                    cout << "Ingrese el apellido del estudiante:";
                    cin >> apellido;
                    estudiante[i].setApellido(apellido);
                    cout << endl;
                    for(int j = 0; j< numNotas; j++){
                        fflush(stdin);
                        char validar[5];
                        int N;
                        double nota;
                        do{
                        cout << "Ingrese la nota #" << j+1 << ": ";
                        cin >> validar;
                        N=validarNumero(validar);

                        if( N != 0){
                            nota = atof(validar);
                            if((nota>= 0) && (nota <=20)){
                                estudiante[i].ingresoNota(j,nota);
                            }else{
                                N = 0;
                                cout << "==== Ingrese una nota entre 0 y 20 ====" << endl;
                                MessageBeep(MB_ICONHAND);
                            }
                        }
                        }while(N == 0);
                    }
                    estudiante[i].promediar();
                }
                notasIngresadas = true;
            }else{
                MessageBeep(MB_ICONHAND);
                cout << "\n========================================================================================" << endl;
                cout << "Por favor Ingrese la información de #alumnos y notas o registre correctamente la materia" << endl;
                cout << "========================================================================================" << endl;
            }
            break;
        }
        case 4:
            if(notasIngresadas){
                cout << "\n========================================================================================" << endl;
                cout << "                 UNIDAD EDUCATIVA GOTITAS DEL SABER" << endl;
                cout << "                 REPORTE DE CALIFICACIONES" << endl;
                cout << "PERIODO: Mayo 2024 - Septiembre 2024" << endl;
                cout << "Materia: " << materia.nombre<<endl;
                cout << "NRC: " << materia.NRC<<endl;
                cout<<"Nombre"<<"\t\t"<<"Apellido"<<"\t";

                for (int i = 1; i <= numNotas; i++) {
                    cout<<"N"<<i<<"\t";
                }
                cout<<"Promedio\n"<<endl;
                for (int i = 0; i < numEstudiantes; i++) {
                    estudiante[i].imprimirDatos();
                }
            }else{
                MessageBeep(MB_ICONHAND);
                cout << "\n========================================================================================" << endl;
                cout << "Aun no se han registrado calificaciones dentro del sistema, por favor registre los datos" << endl;
                cout << "========================================================================================" << endl;
            }
            break;
        case 5:{
            bool regresar = false;
            if(notasIngresadas){
                Estudiante estudiantesOrdenados[numEstudiantes];
                for(int i =0; i< numEstudiantes; i++){
                    estudiantesOrdenados[i]=estudiante[i];
                }
                metodoOrdenacion = escogerMetodoOrdenacion();
                switch (metodoOrdenacion) {
                case 1:
                    cout << "Método de Intercambio Simple seleccionado." << endl;
                    ordenamientoIntercambio(estudiantesOrdenados, numEstudiantes);
                    break;
                case 2:
                    cout << "Método de Selección seleccionado." << endl;
                    ordenamientoSeleccion(estudiantesOrdenados, numEstudiantes);
                    break;
                case 3:
                    cout << "Método de Burbuja seleccionado." << endl;
                    ordenamientoBurbuja(estudiantesOrdenados, numEstudiantes);
                    break;
                case 4:
                    cout << "Método de Quicksort seleccionado." << endl;
                    ordenamientoQuicksort(estudiantesOrdenados,0, numEstudiantes-1);
                    break;
                case 5:
                    cout << "Método de Shellsort seleccionado." << endl;
                    ordenamientoShellsort(estudiantesOrdenados, numEstudiantes);
                    break;
                case 6:
                    cout << "Método de BucketSort seleccionado." << endl;

                    break;
                case 7:
                    cout << "Método de Radixsort seleccionado." << endl;
                    //ordenarRadix(estudiantesOrdenados, numEstudiantes);
                    break;
                case 8:
                    cout <<"regresando al menu"<<endl;
                    regresar =true;
                    break;
                }

                if(!regresar){
                    cout << "Los datos ordenados son: " << endl;
                    cout<<"Nombre"<<"\t\t"<<"Apellido"<<"\t";

                    for (int i = 1; i <= numNotas; i++) {
                        cout<<"N"<<i<<"\t";

                    }
                    cout<<"Promedio\n"<<endl;
                    for (int i = 0; i < numEstudiantes; i++) {
                        estudiantesOrdenados[i].imprimirDatos();
                    }
                }
            }else{
                MessageBeep(MB_ICONHAND);
                cout << "\n========================================================================================" << endl;
                cout << "Aun no se han registrado calificaciones dentro del sistema, por favor registre los datos" << endl;
                cout << "========================================================================================" << endl;
            }
            break;
        }
        case 6:
            if(notasIngresadas){
                metodoBusqueda = escogerMetodoBusqueda();
                switch (metodoBusqueda) {
                case 1:
                    cout << "Método de Búsqueda Lineal seleccionado." << endl;
                    //funcion
                    break;
                case 2:
                    cout << "Método de Búsqueda Binaria seleccionado." << endl;
                    //fucion
                    break;
                case 3:
                    cout << "Método de Búsqueda Hash seleccionado." << endl;
                    //funcion
                    break;
                case 4:
                    cout << "Regresando al menú principal." << endl;
                    break;
                }
            }else{
                MessageBeep(MB_ICONHAND);
                cout << "\n========================================================================================" << endl;
                cout << "Aun no se han registrado calificaciones dentro del sistema, por favor registre los datos" << endl;
                cout << "========================================================================================" << endl;
            }
            break;
        case 7:
            salir = true;
            break;
        }
    system("pause");
   }while(!salir);


}

int main(){

    menuBienvenida();
    menu();

   return 0;

}


bool validarCedula(const string& cedula) {
    if (cedula.length() != 10) {
        return false;
    }
    for (char c : cedula) {
        if (!isdigit(c)) {
            return false;
        }
    }

    int suma =0;
    for(int i =0; i<9; i++){
        int digito = cedula[i]- '0';
        if(i%2==0){
            digito*=2;
            if(digito>9){
                digito-=9;
            }
        }
        suma += digito;
    }
    int verificar = cedula[9]- '0';
    int ultimodigito;
    if (suma % 10 == 0){
        ultimodigito =0;
    }else {
        ultimodigito = 10 - (suma % 10);
    }
    return ultimodigito == verificar;
}

void menuBienvenida() {
    string nombre;
    string cedula;
    SetConsoleOutputCP(CP_UTF8);

    cout << "╔═══════════════════════════════════╗\n";
    cout << "║                                   ║\n";
    cout << "║  UNIDAD EDUCATIVA DATA STRUCTURE  ║\n";
    cout << "║         SISTEMA DE NOTAS          ║\n";
    cout << "║                                   ║\n";
    cout << "╚═══════════════════════════════════╝\n";
    cout << "Por favor, ingrese sus datos" <<endl;
    cout << "\nIngrese su nombre: ";
    cin >> nombre ;
    fflush(stdin);
    while (true) {
        cout << "Ingrese su cédula: ";
        cin >> cedula;

        if (validarCedula(cedula)) {
            cout << "Acceso concedido.\n";
            system("cls");
            break;
        } else {
            MessageBeep(MB_ICONHAND);
            cout << "Cédula no válida. Debe ingresar una cedula correcta.\n";
        }
    }
}

void mostrarMenuOrdenacion(int opcionActual) {
    SetConsoleOutputCP(CP_UTF8);
    cout << "\t----ALGORITMOS DE ORDENACION----\n" << endl;
    cout << "\t╔═══════════════════════════════════╗" << endl;
    for (int i = 1; i <= 8; i++) {
        if (i == opcionActual) {
            printf("%s", ANSI_BACKGROUND_BLUE);
        } else {
            printf("%s", ANSI_BACKGROUND_RESET);
        }

        cout << "\t║ ";
        switch (i) {
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
            cout << "8. Regresar                       ";
            break;
        }
        cout << "║" << endl;
    }
    printf("%s", ANSI_BACKGROUND_RESET);
    cout << "\t╚═══════════════════════════════════╝" << endl;
}

int escogerMetodoOrdenacion() {
    int opcionActual = 1;
    while (1) {
        system("cls");
        mostrarMenuOrdenacion(opcionActual);
        char tecla = _getch();
        switch (tecla) {
        case 72:
            opcionActual = (opcionActual > 1) ? opcionActual - 1 : 8;
            break;
        case 80:
            opcionActual = (opcionActual < 8) ? opcionActual + 1 : 1;
            break;
        case 13:
            system("cls");
            return opcionActual;
        }
    }
}

void mostrarInformacionMateria() {
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

void mostrarMenuBusqueda(int opcionActual) {
    SetConsoleOutputCP(CP_UTF8);
    cout << "\t----MÉTODOS DE BÚSQUEDA----\n" << endl;
    cout << "\t╔═══════════════════════════════════╗" << endl;
    for (int i = 1; i <= 4; i++) {
        if (i == opcionActual) {
            printf("%s", ANSI_BACKGROUND_BLUE);
        } else {
            printf("%s", ANSI_BACKGROUND_RESET);
        }

        cout << "\t║ ";
        switch (i) {
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

int escogerMetodoBusqueda() {
    int opcionActual = 1;
    while (1) {
        system("cls");
        mostrarMenuBusqueda(opcionActual);
        char tecla = _getch();
        switch (tecla) {
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

