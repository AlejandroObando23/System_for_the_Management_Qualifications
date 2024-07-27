#include <iostream>
#include <conio.h>
#include <cctype>
#include <windows.h>
#define ANSI_BACKGROUND_BLUE "\033[44m"
#define ANSI_BACKGROUND_RESET "\033[0m"
using namespace std;

struct Materia{
    string nombre;
    string NRC;
};

Materia materia;
void menuBienvenida();
void mostrarMenuPrincipal(int opcionActual) {

    SetConsoleOutputCP(CP_UTF8);
    cout << "\tMateria:" << materia.nombre << endl;
    cout << "\tNRC:\t" << materia.NRC << endl;
    cout << "\n\tSeleccione una opción:\n" << endl;
    cout << "\t╔═════════════════════════════════╗" << endl;
    for (int i = 1; i <= 6; i++) {
        if (i == opcionActual) {
            printf("%s", ANSI_BACKGROUND_BLUE);
        } else {
            printf("%s", ANSI_BACKGROUND_RESET);
        }

        cout << "\t║ ";
        switch (i) {
        case 1:
            cout << "1. Ingresar Materia y Nrc       ";
            break;
        case 2:
            cout << "2. Ingresar estudiantes y notas ";
            break;
        case 3:
            cout << "3. Ingreso de notas por estud.  ";
            break;
        case 4:
            cout << "4. Ordenamiento                 ";
            break;
        case 5:
            cout << "5. Búsqueda                     ";
            break;
        case 6:
            cout << "6. Salir                        ";
            break;
        }
        cout << "║" << endl;
    }
    printf("%s", ANSI_BACKGROUND_RESET);
    cout << "\t╚═════════════════════════════════╝" << endl;
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

    bool salir = false;
    int opcion, op, op1;
    do
    {
        opcion = escogerOpcion();

        switch(opcion)
        {
        case 1:
            cout<<"═════════════════════════════════" << endl;
            cout << "\tINGRESO MATERIA Y NRC" << endl;
            cout<<"═════════════════════════════════" << endl;
            cout << "\nIngrese el NRC: ";
            cin>> materia.NRC;
            cout <<"\nIngrese la maetria: ";
            cin>> materia.nombre;

            break;
        case 2:

             cout<<"Hola";
            break;
        case 3:
            cout<<"Hola";
            break;
        case 4:
     cout<<"Hola";
            break;
        case 5:
        cout<<"Hola";
            break;
        case 6:
            cout<<"Saliendo del programa....";
        case 7:

            salir = true;
            break;


        }
    }
    while(!salir);


}
int main(){
    materia.nombre = "- aun no ingresado -";
    materia.NRC = "- aun no ingresado -";

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
            cout << "Cédula no válida. Debe ingresar una cedula correcta.\n";
        }
    }
}



