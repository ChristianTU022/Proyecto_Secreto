#include <iostream>
#include <stdlib.h>
#include <fstream>
using namespace std;

int menu();
int funcion_admin();
void funcion_profesor();
void funcion_estudiante();
int administrar_materia();
int opciones_base(string entidad);
void escribir_archivo(string entidad, string registro);
void crear_materia();
void leer_materias();
fstream leer_archivo(string entidad);
void editar_materia ();
void eliminar_materia();

struct materia
{
    string codigo;
    string nom_materia;
};


int main()
{
    menu();
    return 0;
}

void eliminar_materia (){
    string codigo, materia, comparar;
    string respuesta;
    fstream leer = leer_archivo("materia.txt");
    cout << "==========================================================================" << endl;
        cout << "\t\tDigite el codigo de la materia que desea eliminar."<<endl;
        cin >> comparar;
        cout <<"---------------------------------------------------------------------------" << endl;
        while (!leer.eof())
        {
            leer >> codigo;
            leer >> materia;
            if (comparar != codigo)
            {
                string registro = codigo + " " + materia;
                escribir_archivo("temp.txt", registro);
            } 
        }
        cout <<"---------------------------------------------------------------------------" << endl;
        cout << "\t\tDesee eliminar algun otro registro?"<<endl;
        cin >> respuesta;
        leer.close();
        remove ("materia.txt");
        rename ("temp.txt", "materia.txt");
        if (respuesta == "si")
        {
            eliminar_materia();
        } else if (respuesta == "no")
        {
            administrar_materia();
        }
        administrar_materia();
}

void editar_materia (){
    string codigo, materia, nom, comparar;
    fstream leer = leer_archivo("materia.txt");
        cout << "==========================================================================" << endl;
        cout << "\t\tDigite el codigo de la materia que desea actualizar." << endl;
        cin >> comparar;
        cout <<"---------------------------------------------------------------------------" << endl;
        cout << "\t\tQue nombre desea colocarle a la materia de codigo " << comparar << "?"<< endl;
        cin >> nom;
        cout <<"---------------------------------------------------------------------------" << endl;
        while (!leer.eof())
        {
            leer >> codigo;
            leer >> materia;
            if (comparar == codigo)
            {
                materia = nom;
            }

            string registro = codigo + " " + materia;
            escribir_archivo("temp.txt", registro);
        }
        leer.close();
        remove ("materia.txt");
        rename ("temp.txt", "materia.txt");
        cout << "==========================================================================" << endl;
        system("pause");
        administrar_materia();
}

void leer_materias()
{
    string codigo, materia;
    fstream leer = leer_archivo("materia.txt");
     cout << "==========================================================" << endl;
     while (!leer.eof())
        {
            leer >> codigo;
            leer >> materia;
            cout <<  "\t\t" << codigo << "\t " << materia <<"\t\t" <<endl;
            cout << "-----------------------------------------------------" << endl;
        }
        leer.close();
     cout << "==========================================================" << endl;
    system("pause");
    administrar_materia();   
}

fstream leer_archivo(string entidad)
{
    fstream leer;
    leer.open(entidad);
    if (leer.is_open())
    {
       return leer;
    }
    else
    {
        cout  << "El archivo no se encuentra diponible." << endl;
    }
}

void crear_materia()
{
    struct materia dat_materia;
    cout << "================================================================" << endl;
    cout << "\t\tDigite el codigo de la materia: " << endl;
    cin >> dat_materia.codigo;
    cout <<"----------------------------------------------------------------" << endl;
    cout << "\t\tDigite el nombre de la materia: " << endl;
    cin >> dat_materia.nom_materia;
    cout << "----------------------------------------------------------------" << endl;
    string registro = dat_materia.codigo + " " + dat_materia.nom_materia;
    escribir_archivo("materia.txt", registro);
    cout << "================================================================" << endl;
    system("pause");
    administrar_materia();
}

void escribir_archivo(string entidad, string registro)
{
    fstream new_file;
    new_file.open(entidad, ios::app);
    if (!new_file)
    {
        cout << "El archivo no se encuentra diponible" << endl;
    }
    else
    {

        cout << "\t\tregistro agregado." << endl;
        new_file <<"\n" << registro ;
        new_file.close();
    }
}

int opciones_base(string entidad)
{
    int opc;
    cout << "==========================================================================" << endl;
    cout << "==\t\tDigite 1: |\tSi quiere crear " << entidad << endl;
    cout << "==\t\tDigite 2: |\tSi quiere leer " << entidad << endl;
    cout << "==\t\tDigite 3: |\tSi quiere actualizar " << entidad << endl;
    cout << "==\t\tDigite 4: |\tSi quiere eliminar " << entidad << endl;
    cout << "==\t\tDigite 5: |\tSi quiere volver al menu anterior." << endl;
    cout << "==\t\tDigite 0: |\tpara salir" << endl;
    cout << "==========================================================================" << endl;
    cin >> opc;
    return opc;
}

int administrar_materia()
{
    int opc = opciones_base("materias");
    switch (opc)
    {
    case 1:
        crear_materia();
        break;
    case 2:
        leer_materias();
        break;
    case 3:
        editar_materia();
        break;
    case 4:
        eliminar_materia();
        break;
    case 5:
        funcion_admin();
        break;
    case 0:
        return 0;
        break;
    default:
        break;
    }
}

int funcion_admin()
{
    int opc;
    cout << "==========================================================================" << endl;
    cout << "==\t\tBienvenido a la zona de administrador.\t\t\t==" << endl;
    cout << "==========================================================================" << endl;
    cout << "==\t\tDigite 1: |\tSi quiere administrar estudiantes.\t==" << endl;
    cout << "==\t\tDigite 2: |\tSi quiere administrar profesores.\t==" << endl;
    cout << "==\t\tDigite 3: |\tSi quiere administrar materias.\t\t==" << endl;
    cout << "==\t\tDigite 4: |\tSi quiere administrar nota.\t\t==" << endl;
    cout << "==\t\tDigite 5: |\tSi quiere volver al menu anterior.\t==" << endl;
    cout << "==\t\tDigite 0: |\tpara salir.\t\t\t\t==" << endl;
    cout << "==========================================================================" << endl;
    cin >> opc;
    switch (opc)
    {
    case 1:

        break;
    case 2:

        break;
    case 3:
        administrar_materia();
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

void funcion_profesor()
{
    cout << "Bienvenido a la zona de profesor." << endl;
}

void funcion_estudiante()
{
    cout << "Bienvenido a la zona de estudiante." << endl;
}

int menu()
{
    int opc;
    cout << "==================================================================" << endl;
    cout << "==\t\tBienvenido a la plataforma\t\t\t==" << endl;
    cout << "==================================================================" << endl;

    cout << "==\t\tIngrese 1: |\t si es un administrador:\t==" << endl;
    cout << "==\t\tIngrese 2: |\t si es un profesor:\t\t==" << endl;
    cout << "==\t\tIngrese 3: |\t si es un estudiante:\t\t==" << endl;
    cout << "==\t\tIngrese 0: |\t para salir:\t\t\t==" << endl;
    cout << "==================================================================" << endl;

    cin >> opc;
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
        cout << "La opcion digitada no es valida.";
        menu();
        break;
    }

}