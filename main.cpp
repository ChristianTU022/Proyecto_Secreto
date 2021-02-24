#include <iostream>
#include <stdlib.h>
#include <fstream>
using namespace std;

int menu();                                             //Menu principal
int opciones_base(string entidad);                      //Opciones base para todos los menus
void escribir_archivo(string entidad, string registro); //Funcion dedicada a escribir archivos
fstream leer_archivo(string entidad);                   //Funcion dedicada para leer archivos


int funcion_admin();          //Funcion para los admin
int administrar_estudiante(); //Crud para los estudiantes
void crear_estudiante();
void leer_estudiante();
void editar_estudiante();
void eliminar_estudiante();


int administrar_profesor(); //Crud para los profesores
void crear_profesor();
void leer_profesor();
void editar_profesor();
void eliminar_profesor();


int administrar_materia(); //Crud para las materias
void crear_materia();
void leer_materias();
void editar_materia();
void eliminar_materia();

int administrar_grupo(); //Menu para administrar los grupos.
void crear_grupo();
void agregar_estudiantes();
void eliminar_estudiantes_grupo();
// void editar_grupo();
string buscar_materia(string codigo_materia);

int funcion_profesor();
void agregar_materia_a_estudiante(string codigo_materia);
void buscar_materia_profesor();
void agregar_nota_estudiante();
void buscar_materias_estudiante(string codigo_estudiante);
void funcion_estudiante();
void buscar_notas_estudiante();
string buscar_nombre_materia_por_grupo(string codigo_grupo);

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
    string grupo1;
    string grupo2;
    string grupo3;
    string grupo4;
    string grupo5;
    string grupo6;
};
struct profesor //estructura para los profesores
{
    string codigo;
    string nom_profesor;
    string ape_profesor;
};
struct grupo //estructura para los grupos
{
    string codigo;
    string cod_profesor;
    string cod_estudiante;
    string cod_materia;
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
        new_file << "\n"
                 << registro;
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
        cout << "El archivo no se encuentra diponible." << endl;
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
    cout << "==\t\tDigite 4: |\tSi quiere administrar los grupos.\t==" << endl;
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
        system("cls");
        administrar_grupo();
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

int administrar_estudiante()
{
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

void crear_estudiante()
{
    struct estudiante dat_estu;
    cout << "================================================================" << endl;
    cout << "\t\tDigite el codigo del estudiante: " << endl;
    cin >> dat_estu.codigo;
    cout << "----------------------------------------------------------------" << endl;
    cout << "\t\tDigite el nombre del estudiante: " << endl;
    cin >> dat_estu.nom_estudiante;
    cout << "----------------------------------------------------------------" << endl;
    cout << "\t\tDigite el apellido del estudiante: " << endl;
    cin >> dat_estu.ape_estudiante;
    cout << "----------------------------------------------------------------" << endl;
    cout << "\t\tDigite el semestre del estudiante: " << endl;
    cin >> dat_estu.semestre;
    cout << "----------------------------------------------------------------" << endl;
    string registro = dat_estu.codigo + " " + dat_estu.nom_estudiante + " " + dat_estu.ape_estudiante + " Semestre_" + dat_estu.semestre + " " + "0 0 0 0 0 0";
    escribir_archivo("estudiante.txt", registro);
    cout << "================================================================" << endl;
    system("pause");
    system("cls");
    administrar_estudiante();
}

void leer_estudiante()
{
    struct estudiante estu;
    fstream leer = leer_archivo("estudiante.txt");
    cout << "==========================================================" << endl;
    while (!leer.eof())
    {
        leer >> estu.codigo;
        leer >> estu.nom_estudiante;
        leer >> estu.ape_estudiante;
        leer >> estu.semestre;
        leer >> estu.grupo1;
        leer >> estu.grupo2;
        leer >> estu.grupo3;
        leer >> estu.grupo4;
        leer >> estu.grupo5;
        leer >> estu.grupo6;
        cout << "" << estu.codigo << "\t " << estu.nom_estudiante << "\t" << estu.ape_estudiante << "\t" << estu.semestre << "   " << estu.grupo1 << " " << estu.grupo2 << " " << estu.grupo3 << " " << estu.grupo4 << " " << estu.grupo5 << " " << estu.grupo6 << " " << endl;
        cout << "-----------------------------------------------------" << endl;
    }
    leer.close();
    cout << "==========================================================" << endl;
    system("pause");
    system("cls");
    administrar_estudiante();
}

void editar_estudiante()
{
    string comparar, nuevo_nombre, nuevo_apellido, nuevo_semestre;
    struct estudiante estu;

    fstream leer = leer_archivo("estudiante.txt");
    cout << "==========================================================================" << endl;
    cout << "\t\tDigite el codigo del estudiante que desea actualizar." << endl;
    cin >> comparar;
    cout << "---------------------------------------------------------------------------" << endl;
    cout << "\t\tQue nombre desea colocarle al estudiante. " << comparar << "?" << endl;
    cin >> nuevo_nombre;
    cout << "---------------------------------------------------------------------------" << endl;
    cout << "\t\tQue apellido desea al estudiante " << comparar << "?" << endl;
    cin >> nuevo_apellido;
    cout << "---------------------------------------------------------------------------" << endl;
    cout << "\t\tQue semestre quiere colocarle al estudiante. " << comparar << "?" << endl;
    cin >> nuevo_semestre;
    cout << "---------------------------------------------------------------------------" << endl;
    while (!leer.eof())
    {
        leer >> estu.codigo;
        leer >> estu.nom_estudiante;
        leer >> estu.ape_estudiante;
        leer >> estu.semestre;
        leer >> estu.grupo1;
        leer >> estu.grupo2;
        leer >> estu.grupo3;
        leer >> estu.grupo4;
        leer >> estu.grupo5;
        leer >> estu.grupo6;
        if (comparar == estu.codigo)
        {
            estu.nom_estudiante = nuevo_nombre;
            estu.ape_estudiante = nuevo_apellido;
            estu.semestre = "Semestre_" + nuevo_semestre;
        }

        string registro = estu.codigo + " " + estu.nom_estudiante + " " +
                          estu.ape_estudiante + " " + estu.semestre + " " + estu.grupo1 + " " +
                          estu.grupo2 + " " + estu.grupo3 + " " + estu.grupo4 + " " + estu.grupo5 + " " + estu.grupo6;
        escribir_archivo("temp.txt", registro);
    }
    leer.close();
    remove("estudiante.txt");
    rename("temp.txt", "estudiante.txt");
    cout << "==========================================================================" << endl;
    system("pause");
    administrar_estudiante();
}

void eliminar_estudiante()
{
    string comparar, respuesta;
    struct estudiante estu;
    fstream leer = leer_archivo("estudiante.txt");
    cout << "==========================================================================" << endl;
    cout << "\t\tDigite el codigo del estudiante que desea eliminar." << endl;
    cin >> comparar;
    cout << "---------------------------------------------------------------------------" << endl;
    while (!leer.eof())
    {
        leer >> estu.codigo;
        leer >> estu.nom_estudiante;
        leer >> estu.ape_estudiante;
        leer >> estu.semestre;
        leer >> estu.grupo1;
        leer >> estu.grupo2;
        leer >> estu.grupo3;
        leer >> estu.grupo4;
        leer >> estu.grupo5;
        leer >> estu.grupo6;
        if (comparar != estu.codigo)
        {
            string registro = estu.codigo + " " + estu.nom_estudiante + " " + estu.ape_estudiante + " " + estu.semestre + " " + estu.grupo1 + " " + estu.grupo2 + " " + estu.grupo3 + " " +
                              estu.grupo4 + " " + estu.grupo5 + " " + estu.grupo6;
            escribir_archivo("temp.txt", registro);
        }
    }
    cout << "---------------------------------------------------------------------------" << endl;
    cout << "\t\tDesee eliminar algun otro registro?" << endl;
    cin >> respuesta;
    leer.close();
    remove("estudiante.txt");
    rename("temp.txt", "estudiante.txt");
    if (respuesta == "si")
    {
        system("cls");
        eliminar_estudiante();
    }
    else if (respuesta == "no")
    {
        system("cls");
        administrar_estudiante();
    }
    system("cls");
    administrar_estudiante();
}

void agregar_materia_a_estudiante(string codigo_estudiante, string codigo_materia)
{
    struct estudiante estu;
    fstream leer = leer_archivo("estudiante.txt");
    while (!leer.eof())
    {
        leer >> estu.codigo;
        leer >> estu.nom_estudiante;
        leer >> estu.ape_estudiante;
        leer >> estu.semestre;
        leer >> estu.grupo1;
        leer >> estu.grupo2;
        leer >> estu.grupo3;
        leer >> estu.grupo4;
        leer >> estu.grupo5;
        leer >> estu.grupo6;
        if (codigo_estudiante == estu.codigo)
        {
            if (estu.grupo1 == "0")
            {
                estu.grupo1 = codigo_materia;
            }
            else if (estu.grupo2 == "0")
            {
                estu.grupo2 = codigo_materia;
            }
            else if (estu.grupo3 == "0")
            {
                estu.grupo3 = codigo_materia;
            }
            else if (estu.grupo4 == "0")
            {
                estu.grupo4 = codigo_materia;
            }
            else if (estu.grupo5 == "0")
            {
                estu.grupo5 = codigo_materia;
            }
            else if (estu.grupo6 == "0")
            {
                estu.grupo6 = codigo_materia;
            }
        }
        string registro = estu.codigo + " " + estu.nom_estudiante + " " +
                          estu.ape_estudiante + " " + estu.semestre + " " + estu.grupo1 +
                          " " + estu.grupo2 + " " + estu.grupo3 + " " + estu.grupo4 + " " + estu.grupo5 + " " + estu.grupo6;
        escribir_archivo("temp.txt", registro);
    }
    leer.close();
    remove("estudiante.txt");
    rename("temp.txt", "estudiante.txt");
}

int administrar_profesor()
{
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

void crear_profesor()
{
    struct profesor dat_profe;
    cout << "================================================================" << endl;
    cout << "\t\tDigite el codigo del profesor: " << endl;
    cin >> dat_profe.codigo;
    cout << "----------------------------------------------------------------" << endl;
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

void leer_profesor()
{
    struct profesor profe;
    fstream leer = leer_archivo("profesor.txt");
    cout << "==========================================================" << endl;
    while (!leer.eof())
    {
        leer >> profe.codigo;
        leer >> profe.nom_profesor;
        leer >> profe.ape_profesor;
        cout << "\t\t" << profe.codigo << "\t " << profe.nom_profesor << "\t" << profe.ape_profesor << "\t\t" << endl;
        cout << "-----------------------------------------------------" << endl;
    }
    leer.close();
    cout << "==========================================================" << endl;
    system("pause");
    system("cls");
    administrar_profesor();
}

void editar_profesor()
{
    struct profesor profe;
    string nuevo_nombre, nuevo_apellido, comparar, registro;
    fstream leer = leer_archivo("profesor.txt");
    cout << "==========================================================================" << endl;
    cout << "\t\tDigite el codigo del profesor que desea actualizar." << endl;
    cin >> comparar;
    cout << "---------------------------------------------------------------------------" << endl;
    cout << "\t\tQue nombre desea colocarle al profesor de codigo: " << comparar << "?" << endl;
    cin >> nuevo_nombre;
    cout << "---------------------------------------------------------------------------" << endl;
    cout << "\t\tQue apellido desea colocarle al profesor de codigo: " << comparar << "?" << endl;
    cin >> nuevo_apellido;
    cout << "---------------------------------------------------------------------------" << endl;
    while (!leer.eof())
    {
        leer >> profe.codigo;
        leer >> profe.nom_profesor;
        leer >> profe.ape_profesor;
        if (comparar == profe.codigo)
        {
            profe.nom_profesor = nuevo_nombre;
            profe.ape_profesor = nuevo_apellido;
        }

        registro = profe.codigo + " " + profe.nom_profesor + " " + profe.ape_profesor;
        escribir_archivo("temp.txt", registro);
    }
    leer.close();
    remove("profesor.txt");
    rename("temp.txt", "profesor.txt");
    cout << "==========================================================================" << endl;
    system("pause");
    system("cls");
    administrar_profesor();
}

void eliminar_profesor()
{
    struct profesor profe;
    string respuesta, comparar;
    fstream leer = leer_archivo("profesor.txt");
    cout << "==========================================================================" << endl;
    cout << "\t\tDigite el codigo del profesor que desea eliminar." << endl;
    cin >> comparar;
    cout << "---------------------------------------------------------------------------" << endl;
    while (!leer.eof())
    {
        leer >> profe.codigo;
        leer >> profe.nom_profesor;
        leer >> profe.ape_profesor;
        if (comparar != profe.codigo)
        {
            string registro = profe.codigo + " " + profe.nom_profesor + " " + profe.ape_profesor;
            escribir_archivo("temp.txt", registro);
        }
    }
    cout << "---------------------------------------------------------------------------" << endl;
    cout << "\t\tDesee eliminar algun otro registro?" << endl;
    cin >> respuesta;
    leer.close();
    remove("profesor.txt");
    rename("temp.txt", "profesor.txt");
    if (respuesta == "si")
    {
        system("cls");
        eliminar_profesor();
    }
    else if (respuesta == "no")
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
    cout << "----------------------------------------------------------------" << endl;
    cout << "\t\tDigite el nombre de la materia: " << endl;
    cin >> dat_materia.nom_materia;
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
    struct materia mate;
    fstream leer = leer_archivo("materia.txt");
    cout << "================================================================" << endl;
    while (!leer.eof())
    {
        leer >> mate.codigo;
        leer >> mate.nom_materia;
        cout << "\t\t" << mate.codigo << "\t " << mate.nom_materia << "\t\t" << endl;
        cout << "----------------------------------------------------------------" << endl;
    }
    leer.close();
    cout << "================================================================" << endl;
    system("pause");
    system("cls");
    administrar_materia();
}

void editar_materia()
{
    struct materia mate;
    string nuevo_nombre, comparar;
    fstream leer = leer_archivo("materia.txt");
    cout << "==========================================================================" << endl;
    cout << "\t\tDigite el codigo de la materia que desea actualizar." << endl;
    cin >> comparar;
    cout << "---------------------------------------------------------------------------" << endl;
    cout << "\t\tQue nombre desea colocarle a la materia de codigo " << comparar << "?" << endl;
    cin >> nuevo_nombre;
    cout << "---------------------------------------------------------------------------" << endl;
    while (!leer.eof())
    {
        leer >> mate.codigo;
        leer >> mate.nom_materia;
        if (comparar == mate.codigo)
        {
            mate.nom_materia = nuevo_nombre;
        }

        string registro = mate.codigo + " " + mate.nom_materia;
        escribir_archivo("temp.txt", registro);
    }
    leer.close();
    remove("materia.txt");
    rename("temp.txt", "materia.txt");
    cout << "==========================================================================" << endl;
    system("pause");
    system("cls");
    administrar_materia();
}

void eliminar_materia()
{
    struct materia mate;
    string respuesta, comparar;
    fstream leer = leer_archivo("materia.txt");
    cout << "==========================================================================" << endl;
    cout << "\t\tDigite el codigo de la materia que desea eliminar." << endl;
    cin >> comparar;
    cout << "---------------------------------------------------------------------------" << endl;
    while (!leer.eof())
    {
        leer >> mate.codigo;
        leer >> mate.nom_materia;
        if (comparar != mate.codigo)
        {
            string registro = mate.codigo + " " + mate.nom_materia;
            escribir_archivo("temp.txt", registro);
        }
    }
    cout << "---------------------------------------------------------------------------" << endl;
    cout << "\t\tDesee eliminar algun otro registro?" << endl;
    cin >> respuesta;
    leer.close();
    remove("materia.txt");
    rename("temp.txt", "materia.txt");
    if (respuesta == "si")
    {
        system("cls");
        eliminar_materia();
    }
    else if (respuesta == "no")
    {
        system("cls");
        administrar_materia();
    }
    system("cls");
    administrar_materia();
}

int administrar_grupo()
{
    int opc;
    string nombre;
    cout << "==========================================================================" << endl;
    cout << "==\t\tDigite 1: |\tSi quiere crear un grupo." << endl;
    cout << "==\t\tDigite 2: |\tSi quiere agregar estudiantes a un grupo." << endl;
    cout << "==\t\tDigite 3: |\tSi quiere eliminar estudiantes del grupo" << endl;
    cout << "==\t\tDigite 4: |\tSi quiere agregar notas a un estudiante." << endl;
    // cout << "==\t\tDigite 5: |\tSi quiere eliminar " << endl;
    cout << "==\t\tDigite 6: |\tSi quiere volver al menu anterior." << endl;
    cout << "==\t\tDigite 0: |\tpara salir" << endl;
    cout << "==========================================================================" << endl;
    cin >> opc;
    string comparar = "000";
    switch (opc)
    {
    case 1:
        system("cls");
        crear_grupo();
        break;
    case 2:
        system("cls");
        agregar_estudiantes();
        break;
    case 3:
        system("cls");
        eliminar_estudiantes_grupo();
        break;
    case 4:
        // system("cls");
        // editar_grupo();
        break;
    case 10:
        nombre = buscar_materia(comparar);
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
        administrar_grupo();
        break;
    }
}

void crear_grupo()
{
    struct grupo dat_grupo;
    cout << "================================================================" << endl;
    cout << "\t\tDigite el codigo del grupo a crear: " << endl;
    cin >> dat_grupo.codigo;
    cout << "----------------------------------------------------------------" << endl;
    cout << "\t\tDigite el codigo del profesor a cargo de este grupo: " << endl;
    cin >> dat_grupo.cod_profesor;
    cout << "----------------------------------------------------------------" << endl;
    cout << "\t\tDigite el codigo de la materia en este grupo: " << endl;
    cin >> dat_grupo.cod_materia;
    cout << "----------------------------------------------------------------" << endl;
    string codigo_grupo = dat_grupo.codigo + ".txt";
    escribir_archivo(codigo_grupo, "");
    string registro = dat_grupo.codigo + " " + dat_grupo.cod_profesor + " " + dat_grupo.cod_materia;
    escribir_archivo("grupos.txt", registro);
    cout << "================================================================" << endl;
    system("pause");
    system("cls");
    administrar_grupo();
}

void agregar_estudiantes()
{
    struct grupo dat_grupo;
    cout << "================================================================" << endl;
    cout << "Digite el codigo del grupo al que desea agregar estudiantes: " << endl;
    cin >> dat_grupo.codigo;
    cout << "----------------------------------------------------------------" << endl;
    cout << "\t\tDigite el codigo del estudiante a agregar a este grupo: " << endl;
    cin >> dat_grupo.cod_estudiante;
    cout << "----------------------------------------------------------------" << endl;
    string registro = dat_grupo.cod_estudiante + " " + "0";
    string codigo_grupo = dat_grupo.codigo + ".txt";
    escribir_archivo(codigo_grupo, registro);
    agregar_materia_a_estudiante(dat_grupo.cod_estudiante, dat_grupo.codigo);
    cout << "================================================================" << endl;
    system("pause");
    system("cls");
    administrar_grupo();
}

void eliminar_estudiantes_grupo()
{
    string cod_grupo, codigo, cero, comparar;
    string respuesta;
    cout << "==========================================================================" << endl;
    cout << "\tDigite el numero del grupo del que desea eliminar estudiantes." << endl;
    cin >> cod_grupo;
    cout << "---------------------------------------------------------------------------" << endl;
    string juntar = cod_grupo + ".txt";
    fstream leer = leer_archivo(juntar);
    cout << "\tDigite el codigo del estudiante que desea quitar:" << endl;
    cin >> comparar;
    cout << "---------------------------------------------------------------------------" << endl;
    while (!leer.eof())
    {
        leer >> codigo;
        leer >> cero;
        if (comparar != codigo)
        {
            string registro = codigo + " " + cero;
            escribir_archivo("temp.txt", registro);
        }
    }
    cout << "---------------------------------------------------------------------------" << endl;
    cout << "\t\tDesee eliminar algun otro registro?" << endl;
    cin >> respuesta;
    leer.close();
    remove(juntar.c_str());
    rename("temp.txt", juntar.c_str());
    if (respuesta == "si")
    {
        system("cls");
        eliminar_estudiantes_grupo();
    }
    else if (respuesta == "no")
    {
        system("cls");
        administrar_grupo();
    }
    system("cls");
    administrar_grupo();
}

string buscar_materia(string codigo_materia)
{
    string codigo, nombre, nombre_materia;
    bool encontrado = false;
    fstream leer = leer_archivo("materia.txt");
    while (!leer.eof() && !encontrado)
    {
        leer >> codigo;
        leer >> nombre;
        if (codigo_materia == codigo)
        {
            nombre_materia = nombre;
            encontrado = true;
        }
    }
    leer.close();
    return nombre_materia;
}

void buscar_materias_estudiante(string codigo_estudiante)
{
    struct estudiante estu;
    struct grupo grup;
    bool encontrado = false;
    fstream leer = leer_archivo("estudiante.txt");
    while (!leer.eof() && !encontrado)
    {
        leer >> estu.codigo;
        leer >> estu.nom_estudiante;
        leer >> estu.ape_estudiante;
        leer >> estu.semestre;
        leer >> estu.grupo1;
        leer >> estu.grupo2;
        leer >> estu.grupo3;
        leer >> estu.grupo4;
        leer >> estu.grupo5;
        leer >> estu.grupo6;
        if (codigo_estudiante == estu.codigo)
        {
            fstream leer2 = leer_archivo("grupos.txt");
            while (!leer2.eof())
            {
                leer2 >> grup.codigo;
                leer2 >> grup.cod_profesor;
                leer2 >> grup.cod_materia;
                if (estu.grupo1 != "0")
                {
                    if (estu.grupo1 == grup.codigo)
                    {
                        string nombre_materia = buscar_materia(grup.cod_materia);
                        cout << grup.codigo + " " + nombre_materia << endl;
                    }
                }
                if (estu.grupo2 != "0")
                {
                    if (estu.grupo2 == grup.codigo)
                    {
                        string nombre_materia = buscar_materia(grup.cod_materia);
                        cout << grup.codigo + " " + nombre_materia << endl;
                    }
                }
                if (estu.grupo3 != "0")
                {
                    if (estu.grupo3 == grup.codigo)
                    {
                        string nombre_materia = buscar_materia(grup.cod_materia);
                        cout << grup.codigo + " " + nombre_materia << endl;
                    }
                }
                if (estu.grupo4 != "0")
                {
                    if (estu.grupo4 == grup.codigo)
                    {
                        string nombre_materia = buscar_materia(grup.cod_materia);
                        cout << grup.codigo + " " + nombre_materia << endl;
                    }
                }
                if (estu.grupo5 != "0")
                {
                    if (estu.grupo5 == grup.codigo)
                    {
                        string nombre_materia = buscar_materia(grup.cod_materia);
                        cout << grup.codigo + " " + nombre_materia << endl;
                    }
                }
                if (estu.grupo6 != "0")
                {
                    if (estu.grupo6 == grup.codigo)
                    {
                        string nombre_materia = buscar_materia(grup.cod_materia);
                        cout << grup.codigo + " " + nombre_materia << endl;
                    }
                }
            }
            leer2.close();
        }
    }
    leer.close();
}

int funcion_profesor()
{
    int opc;
    cout << "==========================================================================" << endl;
    cout << "==\t\tBienvenido a la zona de profesor.\t\t\t==" << endl;
    cout << "==========================================================================" << endl;
    cout << "==\t\tDigite 1: |\tSi quiere buscar las materias que dicta.\t==" << endl;
    cout << "==\t\tDigite *: |\tSi quiere volver al menu anterior.\t==" << endl;
    cout << "==\t\tDigite 0: |\tpara salir.\t\t\t\t==" << endl;
    cin >> opc;
    switch (opc)
    {
    case 1:
        agregar_nota_estudiante();
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
    //buscar_materia_profesor();
}

void agregar_nota_estudiante(){
    string cod_grupo, cod_estudiante, nueva_nota, codigo, nota;
    string respuesta;
    bool encontrado = false;
    cout << "==========================================================================" << endl;
        cout << "\tDigite el codigo del grupo del que desea agregar una nota."<<endl;
        cin >> cod_grupo;
        cout <<"---------------------------------------------------------------------------" << endl;
        cout << "\tDigite el codigo del estudiante al que quiere agregar la nota."<<endl;
        cin >> cod_estudiante;
        cout <<"---------------------------------------------------------------------------" << endl;
        cout << "\tDigite la nota que desea." << endl;
        cin >> nueva_nota;
        cout <<"---------------------------------------------------------------------------" << endl;
        string juntar = cod_grupo + ".txt";
        fstream leer = leer_archivo(juntar);
        while (!leer.eof())
        {
            leer >> codigo;
            leer >> nota;
            if (codigo == cod_estudiante)
            {
                nota = nueva_nota;
            }
            
            string registro = codigo + " " + nota;
            escribir_archivo("temp.txt", registro);
        }
        leer.close();
        remove(juntar.c_str());
        rename("temp.txt", juntar.c_str());
    cout << "================================================================" << endl;
        
}

void buscar_materia_profesor()
{
    string codigo, codigo_grupo, codigo_profesor, codigo_materia;
    cout << "================================================================" << endl;
    cout << "\t\tDigite el codigo del profesor: " << endl;
    cin >> codigo;
    cout << "----------------------------------------------------------------" << endl;
    fstream leer = leer_archivo("grupos.txt");
    while (!leer.eof())
    {
        leer >> codigo_grupo;
        leer >> codigo_profesor;
        leer >> codigo_materia;
        if (codigo == codigo_profesor)
        {
            string nombre_materia = buscar_materia(codigo_materia);
            cout << codigo_grupo + " " + nombre_materia << endl;
        }
    }
    leer.close();
    cout << "================================================================" << endl;
}

void funcion_estudiante()
{
    int opc;
    cout << "==========================================================================" << endl;
    cout << "==\t\tBienvenido a la zona de estudiantes.\t\t\t==" << endl;
    cout << "==========================================================================" << endl;
    //buscar_materias_estudiante("Estudiante_2");
    buscar_notas_estudiante();
}

void buscar_notas_estudiante()
{
    struct estudiante estu;
    string codigo, nota;

    bool encontrado = false;
    string codigo_estudiante;
    cout << "================================================================" << endl;
    cout << "\t\tDigite el codigo del estudiante: " << endl;
    cin >> codigo_estudiante;
    cout << "----------------------------------------------------------------" << endl;
    fstream leer = leer_archivo("estudiante.txt");
    while (!leer.eof() && !encontrado)
    {
        leer >> estu.codigo;
        leer >> estu.nom_estudiante;
        leer >> estu.ape_estudiante;
        leer >> estu.semestre;
        leer >> estu.grupo1;
        leer >> estu.grupo2;
        leer >> estu.grupo3;
        leer >> estu.grupo4;
        leer >> estu.grupo5;
        leer >> estu.grupo6;
        if (codigo_estudiante == estu.codigo)
        {
            if (estu.grupo1 != "0")
            {
                fstream leer = leer_archivo(estu.grupo1 + ".txt");
                while (!leer.eof())
                {
                    leer >> codigo;
                    leer >> nota;
                    if (codigo == codigo_estudiante)
                    {
                        cout << buscar_nombre_materia_por_grupo(estu.grupo1) + " " + nota << endl;
                    }
                }
            }
            if (estu.grupo2 != "0")
            {
                fstream leer = leer_archivo(estu.grupo2 + ".txt");
                while (!leer.eof())
                {
                    leer >> codigo;
                    leer >> nota;
                    if (codigo == codigo_estudiante)
                    {
                        cout << estu.grupo2 + " " + nota << endl;
                    }
                }
            }
            if (estu.grupo3 != "0")
            {
                fstream leer = leer_archivo(estu.grupo3 + ".txt");
                while (!leer.eof())
                {
                    leer >> codigo;
                    leer >> nota;
                    if (codigo == codigo_estudiante)
                    {
                        cout << estu.grupo3 + " " + nota << endl;
                    }
                }
            }
            if (estu.grupo4 != "0")
            {
                fstream leer = leer_archivo(estu.grupo4 + ".txt");
                while (!leer.eof())
                {
                    leer >> codigo;
                    leer >> nota;
                    if (codigo == codigo_estudiante)
                    {
                        cout << estu.grupo4 + " " + nota << endl;
                    }
                }
            }
            if (estu.grupo5 != "0")
            {
                fstream leer = leer_archivo(estu.grupo5 + ".txt");
                while (!leer.eof())
                {
                    leer >> codigo;
                    leer >> nota;
                    if (codigo == codigo_estudiante)
                    {
                        cout << estu.grupo5 + " " + nota << endl;
                    }
                }
            }
            if (estu.grupo6 != "0")
            {
                fstream leer = leer_archivo(estu.grupo6 + ".txt");
                while (!leer.eof())
                {
                    leer >> codigo;
                    leer >> nota;
                    if (codigo == codigo_estudiante)
                    {
                        cout << estu.grupo6 + " " + nota << endl;
                    }
                }
            }
        }
    }
}

string buscar_nombre_materia_por_grupo(string codigo_grupo)
{
    struct grupo grup;
    fstream leer = leer_archivo("grupos.txt");
    while (!leer.eof())
    {
        leer >> grup.codigo;
        leer >> grup.cod_profesor;
        leer >> grup.cod_materia;
        if (codigo_grupo == grup.codigo)
        {
            return buscar_materia(grup.cod_materia);
        }
    }
}