#include<iostream>
#include<stdlib.h>
using namespace std;

int menu ();
int funcion_admin ();
void funcion_profesor ();
void funcion_estudiante ();

int main()
{
    menu();

    
    return 0;
}
int funcion_admin (){
    int opc;
    cout<<"Bienvenido a la zona de administrador."<<endl;
    cout<<"Digite 1: Si quiere administrar estudiantes."<<endl;
    cout<<"Digite 2: Si quiere administrar profesores."<<endl; 
    cout<<"Digite 3: Si quiere administrar materias."<<endl;
    cout<<"Digite 4: Si quiere administrar nota."<<endl;
    cout<<"Digite 5: Si quiere volver al menu anterior."<<endl;
    cout<<"Ingrese 0 para salir:"<<endl; 
    cin>>opc;
    switch (opc)
    {
    case 1:
        
        break;
    case 2:
        
        break;
    case 3:
        
        break;
    case 4:
        
        break;
    case 5:
        menu();
        break;
    case 0:
        return 0;
        break;
    default:
        break;
    }
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
     cout<<"Ingrese 0 para salir:"<<endl; 
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
    case 0:
        return 0;
        break;
    default:
        cout<<"La opcion digitada no es valida.";
        menu();
        break;
    }
}