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
void leer_archivo(string entidad);
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
void leer_materias()
{
    leer_archivo("materia.txt");
}
void leer_archivo(string entidad)
{
    string codigo, materia;
    fstream leer;
    leer.open(entidad);
    if (leer.is_open())
    {
        while (!leer.eof())
        {
            leer >> codigo;
            leer >> materia;
            cout << codigo << "\t " << materia << endl;
        }
    }
    else
    {
        cout << "El archivo no se encuentra diponible" << endl;
    }
    leer.close();
}
void crear_materia()
{
    struct materia dat_materia;
    cout << "Digite el codigo de la materia. " << endl;
    cin >> dat_materia.codigo;
    cout << "Digite el nombre de la materia." << endl;
    cin >> dat_materia.nom_materia;
    string registro = dat_materia.codigo + " " + dat_materia.nom_materia;
    escribir_archivo("materia.txt", registro);
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

        cout << "registro agregado." << endl;
        new_file << registro << "\n";
        new_file.close();
    }
}
int opciones_base(string entidad)
{
    int opc;
    cout << "Digite 1: Si quiere crear " << entidad << endl;
    cout << "Digite 2: Si quiere leer " << entidad << endl;
    cout << "Digite 3: Si quiere actualizar " << entidad << endl;
    cout << "Digite 4: Si quiere eliminar " << entidad << endl;
    cout << "Digite 5: Si quiere volver al menu anterior." << endl;
    cin >> opc;
    return opc;
}
int administrar_materia()
{
    int opc = opciones_base("materia");
    switch (opc)
    {
    case 1:
        crear_materia();
        break;
    case 2:
        leer_materias();
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
    cout << "==\t\tDigite 0: |\tpara salir:\t\t\t\t==" << endl;
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