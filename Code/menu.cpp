#include <iostream>
#include <conio.h>
#define ANSI_BACKGROUND_BLUE "\033[44m"
#define ANSI_BACKGROUND_RESET "\033[0m"
using namespace std;
void mostrarMenuPrincipal(int opcionActual)
{
    cout << "\n\tSeleccione una opcion:\n" << endl;
    cout << "\t===========================" << endl;
    for(int i=1; i<=7; i++)
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
            cout << "\t4. Ordenamieto" << endl;
            break;
        case 5:
            cout << "\t5. Busqueda" << endl;
            break;
        case 6:
            cout << "\t6. Salir"<< endl;
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
        cout<<"Hola";
            break;
        case 6:
            cout<<"Hola";
        case 7:

            salir = true;
            break;


        }
    }
    while(!salir);


}
int main(){
int repetir;
bool secion=true;
string nom;
string cedu;

do{
    cout<<"Bienvenido al sistema de notas"<<endl;
    cout<<"Ingrese su nombre"<<endl;
    cin>>nom;
    cout<<"Ingrese su cedula"<<endl;
    cin>>cedu;
    if(cedu.size()>=10){
        menu();
        secion=false;

    }else{
        secion=true;
    }
    system("cls");

}while(secion);
    cout<<"Saliendo del programa...";

   return 0;


}
