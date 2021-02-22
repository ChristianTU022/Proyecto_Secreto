#include <iostream>
#include <stdlib.h>
#include <fstream>
using namespace std;

int menu(); //Menu principal
    int opciones_base(string entidad); //Opciones base para todos los menus
void escribir_archivo(string entidad, string registro); //Funcion dedicada a escribir archivos    
fstream leer_archivo(string entidad); //Funcion dedicada para leer archivos
int funcion_admin();
    int administrar_estudiante(); //Crud para los estudiantes
        void crear_estudiante();
        void leer_estudiante();
        void editar_estudiante();
        void eliminar_estudiante();

    int administrar_profesor();
        void crear_profesor();
        void leer_profesor();
        void editar_profesor();
        void eliminar_profesor();

    int administrar_materia(); //Crud para las materias
        void crear_materia();
        void leer_materias();
        void editar_materia();
        void eliminar_materia();



void funcion_profesor();
void funcion_estudiante();

struct materia //estructura para las materias
{
    string codigo;
    string nom_materia;
};
struct estudiante //estructura para los estudiantes
{
    string codigo;
    string nom_estudiante;
    string ape_estudiante;
    string semestre;  
};
struct profesor //estructura para los profesores
{
    string codigo;
    string nom_profesor;
    string ape_profesor; 
};


int main()
{
    menu();
    return 0;
}
int menu()
{
    int opc;
    system("cls");
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
        system("cls");
        funcion_admin();
        break;
    case 2:
        system("cls");
        funcion_profesor();
        break;
    case 3:
        system("cls");
        funcion_estudiante();
        break;
    case 0:
        return 0;
        break;
    default:
        cout << "\n\t\t-Error: La opcion digitada no es valida..." << endl;
        system("pause");
        system("cls");
        menu();
        break;
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
        system("cls");
        administrar_estudiante();
        break;
    case 2:
        system("cls");
        administrar_profesor();
        break;
    case 3:
        system("cls");
        administrar_materia();
        break;
    case 4:
 
        break;
    case 5:
        system("cls");
        menu();
        break;
    case 0:
        return 0;
        break;
    default:
        cout << "\n\t\t-Error: La opcion digitada no es valida..." << endl;
        system("pause");
        system("cls");
        funcion_admin();
        break;
    }
}


int administrar_estudiante(){
    int opc = opciones_base("estudiantes");
    switch (opc)
    {
    case 1:
        system("cls");
        crear_estudiante();
        break;
    case 2:
        system("cls");
        leer_estudiante();
        break;
    case 3:
        system("cls");
        editar_estudiante();
        break;
    case 4:
        system("cls");
        eliminar_estudiante();
        break;
    case 5:
        system("cls");
        funcion_admin();
        break;
    case 0:
        return 0;
        break;
    default:
        cout << "\n\t\t-Error: La opcion digitada no es valida..." << endl;
        system("pause");
        system("cls");
        administrar_estudiante();
        break;
    }   
}

void crear_estudiante(){
    struct estudiante dat_estu;
    cout << "================================================================" << endl;
    cout << "\t\tDigite el codigo del estudiante: " << endl;
    cin >> dat_estu.codigo;
    cout <<"----------------------------------------------------------------" << endl;
    cout << "\t\tDigite el nombre del estudiante: " << endl;
    cin >> dat_estu.nom_estudiante;
    cout << "----------------------------------------------------------------" << endl;
    cout << "\t\tDigite el apellido del estudiante: " << endl;
    cin >> dat_estu.ape_estudiante;
    cout << "----------------------------------------------------------------" << endl;
    cout << "\t\tDigite el semestre del estudiante: " << endl;
    cin >> dat_estu.semestre;
    cout << "----------------------------------------------------------------" << endl;
    string registro = dat_estu.codigo + " " + dat_estu.nom_estudiante + " " + dat_estu.ape_estudiante + " Semestre_" + dat_estu.semestre;
    escribir_archivo("estudiante.txt", registro);
    cout << "================================================================" << endl;
    system("pause");
    system("cls");
    administrar_estudiante();
}

void leer_estudiante(){
    string codigo, estudiante, apellido, semestre;
    fstream leer = leer_archivo("estudiante.txt");
     cout << "==========================================================" << endl;
     while (!leer.eof())
        {
            leer >> codigo;
            leer >> estudiante;
            leer >> apellido;
            leer >> semestre;
            cout <<  "\t\t" << codigo << "\t " << estudiante << "\t" << apellido << "\t"<< semestre <<"\t\t" <<endl;
            cout << "-----------------------------------------------------" << endl;
        }
        leer.close();
     cout << "==========================================================" << endl;
    system("pause");
    system("cls");
    administrar_estudiante();   
}

void editar_estudiante(){
    string codigo, comparar, nuevo_nombre, nuevo_apellido, nuevo_semestre;
    string nombre, apellido, semestre;
    fstream leer = leer_archivo("estudiante.txt");
        cout << "==========================================================================" << endl;
        cout << "\t\tDigite el codigo del estudiante que desea actualizar." << endl;
        cin >> comparar;
        cout <<"---------------------------------------------------------------------------" << endl;
        cout << "\t\tQue nombre desea colocarle al estudiante. " << comparar << "?"<< endl;
        cin >> nuevo_nombre;
        cout <<"---------------------------------------------------------------------------" << endl;
        cout << "\t\tQue apellido desea al estudiante " << comparar << "?"<< endl;
        cin >> nuevo_apellido;
        cout <<"---------------------------------------------------------------------------" << endl;
        cout << "\t\tQue semestre quiere colocarle al estudiante. " << comparar << "?"<< endl;
        cin >> nuevo_semestre;
        cout <<"---------------------------------------------------------------------------" << endl;
        while (!leer.eof())
        {
            leer >> codigo;
            leer >> nombre;
            leer >> apellido;
            leer >> semestre;
            if (comparar == codigo)
            {
                nombre = nuevo_nombre;
                apellido = nuevo_apellido; 
                semestre = nuevo_semestre;
            }

            string registro = codigo + " " + nombre + " " + apellido + " Semestre_" + semestre;
            escribir_archivo("temp.txt", registro);
        }
        leer.close();
        remove ("estudiante.txt");
        rename ("temp.txt", "estudiante.txt");
        cout << "==========================================================================" << endl;
        system("pause");
        administrar_estudiante();
}

void eliminar_estudiante(){
    string codigo, comparar;
    string nom_estudiante, ape_estudiante, semestre;
    string respuesta;
    fstream leer = leer_archivo("estudiante.txt");
    cout << "==========================================================================" << endl;
        cout << "\t\tDigite el codigo del estudiante que desea eliminar."<<endl;
        cin >> comparar;
        cout <<"---------------------------------------------------------------------------" << endl;
        while (!leer.eof())
        {
            leer >> codigo;
            leer >> nom_estudiante;
            leer >> ape_estudiante;
            leer >> semestre;
            if (comparar != codigo)
            {
                string registro = codigo + " " + nom_estudiante + " " + ape_estudiante + " " + semestre;
                escribir_archivo("temp.txt", registro);
            } 
        }
        cout <<"---------------------------------------------------------------------------" << endl;
        cout << "\t\tDesee eliminar algun otro registro?"<<endl;
        cin >> respuesta;
        leer.close();
        remove ("estudiante.txt");
        rename ("temp.txt", "estudiante.txt");
        if (respuesta == "si")
        {
            system("cls");
            eliminar_estudiante();
        } else if (respuesta == "no")
        {
            system("cls");
            administrar_estudiante();
        }
        system("cls");
        administrar_estudiante();
}


int administrar_profesor(){
    int opc = opciones_base("profesores.");
    switch (opc)
    {
    case 1:
        system("cls");
        crear_profesor();
        break;
    case 2:
        system("cls");
        leer_profesor();
        break;
    case 3:
        system("cls");
        editar_profesor();
        break;
    case 4:
        system("cls");
        eliminar_profesor();
        break;
    case 5:
        system("cls");
        funcion_admin();
        break;
    case 0:
        return 0;
        break;
    default:
        cout << "\n\t\t-Error: La opcion digitada no es valida..." << endl;
        system("pause");
        system("cls");
        administrar_estudiante();
        break;
    }
}

void crear_profesor(){
    struct profesor dat_profe;
    cout << "================================================================" << endl;
    cout << "\t\tDigite el codigo del profesor: " << endl;
    cin >> dat_profe.codigo;
    cout <<"----------------------------------------------------------------" << endl;
    cout << "\t\tDigite el nombre del profesor: " << endl;
    cin >> dat_profe.nom_profesor;
    cout << "----------------------------------------------------------------" << endl;
    cout << "\t\tDigite el apellido del profesor: " << endl;
    cin >> dat_profe.ape_profesor;
    cout << "----------------------------------------------------------------" << endl;
    string registro = dat_profe.codigo + " " + dat_profe.nom_profesor + " " + dat_profe.ape_profesor;
    escribir_archivo("profesor.txt", registro);
    cout << "================================================================" << endl;
    system("pause");
    system("cls");
    administrar_profesor();
}

void leer_profesor(){
    string codigo, profesor, apellido;
    fstream leer = leer_archivo("profesor.txt");
     cout << "==========================================================" << endl;
     while (!leer.eof())
        {
            leer >> codigo;
            leer >> profesor;
            leer >> apellido;
            cout <<  "\t\t" << codigo << "\t " << profesor << "\t" << apellido << "\t\t" <<endl;
            cout << "-----------------------------------------------------" << endl;
        }
        leer.close();
     cout << "==========================================================" << endl;
    system("pause");
    system("cls");
    administrar_profesor();   
}

void editar_profesor (){
    string codigo, nombre, apellido, registro;
    string nuevo_nombre, nuevo_apellido, comparar;
    fstream leer = leer_archivo("profesor.txt");
        cout << "==========================================================================" << endl;
        cout << "\t\tDigite el codigo del profesor que desea actualizar." << endl;
        cin >> comparar;
        cout <<"---------------------------------------------------------------------------" << endl;
        cout << "\t\tQue nombre desea colocarle al profesor de codigo: " << comparar << "?"<< endl;
        cin >> nuevo_nombre;
        cout <<"---------------------------------------------------------------------------" << endl;
        cout << "\t\tQue apellido desea colocarle al profesor de codigo: " << comparar << "?"<< endl;
        cin >> nuevo_apellido;
        cout <<"---------------------------------------------------------------------------" << endl;
        while (!leer.eof())
        {
            leer >> codigo;
            leer >> nombre;
            leer >> apellido;
            if (comparar == codigo)
            {
                nombre = nuevo_nombre;
                apellido = nuevo_apellido;
            }

            registro = codigo + " " + nombre + " " + apellido;
            escribir_archivo("temp.txt", registro);
        }
        leer.close();
        remove ("profesor.txt");
        rename ("temp.txt", "profesor.txt");
        cout << "==========================================================================" << endl;
        system("pause");
        system("cls");
        administrar_profesor();
}

void eliminar_profesor(){
    string codigo, comparar;
    string nom_profesor, ape_profesor;
    string respuesta;
    fstream leer = leer_archivo("profesor.txt");
    cout << "==========================================================================" << endl;
        cout << "\t\tDigite el codigo del profesor que desea eliminar."<<endl;
        cin >> comparar;
        cout <<"---------------------------------------------------------------------------" << endl;
        while (!leer.eof())
        {
            leer >> codigo;
            leer >> nom_profesor;
            leer >> ape_profesor;
            if (comparar != codigo)
            {
                string registro = codigo + " " + nom_profesor + " " + ape_profesor;
                escribir_archivo("temp.txt", registro);
            } 
        }
        cout <<"---------------------------------------------------------------------------" << endl;
        cout << "\t\tDesee eliminar algun otro registro?"<<endl;
        cin >> respuesta;
        leer.close();
        remove ("profesor.txt");
        rename ("temp.txt", "profesor.txt");
        if (respuesta == "si")
        {
            system("cls");
            eliminar_profesor();
        } else if (respuesta == "no")
        {
            system("cls");
            administrar_profesor();
        }
        system("cls");
        administrar_profesor();
}


int administrar_materia()
{
    int opc = opciones_base("materias.");
    switch (opc)
    {
    case 1:
        system("cls");
        crear_materia();
        break;
    case 2:
        system("cls");
        leer_materias();
        break;
    case 3:
        system("cls");
        editar_materia();
        break;
    case 4:
        system("cls");
        eliminar_materia();
        break;
    case 5:
        system("cls");
        funcion_admin();
        break;
    case 0:
        return 0;
        break;
    default:
        cout << "\n\t\t-Error: La opcion digitada no es valida..." << endl;
        system("pause");
        system("cls");
        administrar_materia();
        break;
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
    //cin.ignore(); getline(cin, dat_materia.nom_materia);
    cout << "----------------------------------------------------------------" << endl;
    string registro = dat_materia.codigo + " " + dat_materia.nom_materia;
    escribir_archivo("materia.txt", registro);
    cout << "================================================================" << endl;
    system("pause");
    system("cls");
    administrar_materia();
}

void leer_materias()
{
    string codigo, materia;
    fstream leer = leer_archivo("materia.txt");
    cout << "================================================================" << endl;
     while (!leer.eof())
        {
            leer >> codigo;
            leer >> materia;
            cout <<  "\t\t" << codigo << "\t " << materia <<"\t\t" <<endl;
            cout <<"----------------------------------------------------------------" << endl;
        }
        leer.close();
    cout << "================================================================" << endl;
    system("pause");
    system("cls");
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
        system("cls");
        administrar_materia();
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
            system("cls");
            eliminar_materia();
        } else if (respuesta == "no")
        {
            system("cls");
            administrar_materia();
        }
        system("cls");
        administrar_materia();
}


void funcion_profesor()
{
    int opc;
    cout << "==========================================================================" << endl;
    cout << "==\t\tBienvenido a la zona de profesor.\t\t\t==" << endl;
    cout << "==========================================================================" << endl;
}

void funcion_estudiante()
{
    int opc;
    cout << "==========================================================================" << endl;
    cout << "==\t\tBienvenido a la zona de estudiantes.\t\t\t==" << endl;
    cout << "==========================================================================" << endl;
}
