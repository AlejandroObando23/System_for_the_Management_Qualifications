#include <iostream>
#include <conio.h>
#define ANSI_BACKGROUND_BLUE "\033[44m"
#define ANSI_BACKGROUND_RESET "\033[0m"
using namespace std;
void mostrarMenuPrincipal(int opcionActual)
{
    cout << "\n\tSeleccione una opcion:\n" << endl;
    cout << "\t===========================" << endl;
    for(int i=1; i<=5; i++)
    {
        if(i==opcionActual)
        {
            printf("%s",ANSI_BACKGROUND_BLUE);
        }
        else
        {
            printf("%s",ANSI_BACKGROUND_RESET);
        }

        switch(i)
        {
        case 1:
            cout << "\t1. Ingresar Materia y Nrc" << endl;
            break;
        case 2:
            cout << "\t2. Ingresar estudiantes y notas a registrar" << endl;
            break;
        case 3:
            cout << "\t3. Ingreso de notas por estudiante" << endl;
            break;
        case 4:
            cout << "\t4. Ver Reporte de calificanes del NRC" << endl;
            break;
        case 5:
            cout << "\t5. Salir" << endl;
            break;
        case 6:
            cout << "\t6. Ver Doctores"<< endl;
            break;
        case 7:
            cout << "\t7. Doctores en turno" << endl;
            break;
        case 8:
            cout << "\t8. Terminar dia" << endl;
            break;
        case 9:
            cout << "\t9. Salir" << endl;
            break;

        }
    }
    printf("%s",ANSI_BACKGROUND_RESET);
    cout << "\t===========================" << endl;
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
            opcionActual=(opcionActual>1)?opcionActual-1:5;
            break;
        case 80:
            opcionActual=opcionActual<5?opcionActual+1:1;
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

            };
            break;
        }
    }
}
int main()
{

    bool salir = false;
    int opcion, op, op1;
    do
    {
        opcion = escogerOpcion();

        switch(opcion)
        {
        case 1:
            cout<<"Hola";
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
            cout<<"Saliendo del programa...";
            salir = true;
            break;


        }
    }
    while(!salir);

    return 0;
}
