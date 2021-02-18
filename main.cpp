#include<iostream>
#include<stdlib.h>
using namespace std;

void funcion_admin (){
    cout<<"Bienvenido a la zona de administrador."<<endl;
}
void funcion_profesor (){
    cout<<"Bienvenido a la zona de profesor."<<endl;
}
void funcion_estudiante (){
    cout<<"Bienvenido a la zona de estudiante."<<endl;
}
int menu (){
    int opc;
    cout<<"Bienvenido a la plataforma"<<endl;
    cout<<"Ingrese 1 si es un administrador:"<<endl;
    cout<<"Ingrese 2 si es un profesor:"<<endl;
    cout<<"Ingrese 3 si es un estudiante:"<<endl; 
     cout<<"Ingrese 4 para salir:"<<endl; 
    cin>>opc;
    switch (opc)
    {
    case 1:
        funcion_admin();
        break;
    case 2:
        funcion_profesor();
        break;
    case 3:
        funcion_estudiante();
        break;
    case 4:
        return 0;
        break;
    default:
        cout<<"La opcion digitada no es valida.";
        menu();
        break;
    }
}

int main()
{
    menu();

    
    return 0;
}
