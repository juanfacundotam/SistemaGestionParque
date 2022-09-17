#include <iostream>
#include "Parque.h"
#include "rlutil.h"
#include "funciones.h"
using namespace std;

Parque::Parque() {
    _cantidadActividades = 0;
    _cantidadEmpleados = 0;
    _estado = false;
}

///
void Parque::Abrir() {
    _estado = true;
}

///
bool Parque::agregarActividad() {
    Actividad registro;
    int escribir;
    FILE* p;

    p = fopen("Actividades.dat", "ab");
    if (p == NULL) {
        cout << "No se pudo encontrar el archivo." << endl;
        rlutil::anykey();
        return false;
    }

    registro.CargarActividad();
    escribir = fwrite(&registro, sizeof(Actividad), 1, p);
    if (escribir == 0) {
        fclose(p);
        cout << "No se pudo guardar la actividad." << endl;
        rlutil::anykey();
        return false;
    }

    fclose(p);
    cout << "Actividad cargada correctamente.";

    rlutil::anykey();
    return true;
}

///
void Parque::mostrarActividades() {
    Actividad registro;
    FILE* p;
    p = fopen("Actividades.dat", "rb");
    if (p == NULL) {
        cout << "No se encuentran registros" << endl;
        rlutil::anykey();
        return;
    }
    rlutil::locate(45, 3);
    cout << "- ACTIVIDADES DISPONIBLES -" << endl;
    rlutil::locate(30, 4);
    cout << "-------------------------------------------------------" << endl;
    int pos = 0;
    while (fread(&registro, sizeof(Actividad), 1, p) == 1) {
        registro.mostrarDescripcion(pos);
        cout << endl;
        pos++;
    }
    fclose(p);
    rlutil::anykey();
}

///
bool Parque::crearClaveMaestra() {
    bool admin = true;
    Empleado primerRegistro(admin);
    int escribir;
    string repetirPass;
    FILE* p;
    p = fopen("Empleados.dat", "ab");
    if (p == NULL) {
        cout << "No se pudo acceder al archivo..." << endl;
        rlutil::anykey();
        return false;
    }
    else {
        do {
            cout << "Ingrese una clave: ";
            primerRegistro.setPassword(cinPassword().c_str());
            //cin.getline(_password, 30);
            cout << "Repita la clave: ";
            repetirPass = cinPassword();
            if (primerRegistro.getPassword() != repetirPass) {
                cout << "Las claves no coinciden" << endl;
            }
        } while (primerRegistro.getPassword() != repetirPass);
        cout << endl << endl;
    }
    escribir = fwrite(&primerRegistro, sizeof(Empleado), 1, p);
    if (escribir == 0) {
        fclose(p);
        cout << "Error: La clave no fue registrada correctamente." << endl;
        rlutil::anykey();
        return false;
    }

    fclose(p);
    cout << "CLAVE MAESTRA creada correctamente.";
    rlutil::anykey();
    return true;

}

bool Parque::validarClaveMaestra() {
    Empleado registro;
    string password;
    int escribir, intentos = 2, cont = 0;
    FILE* p;
    p = fopen("Empleados.dat", "rb");
    if (p == NULL) {
        cout << "No se pudo acceder al archivo..." << endl;
        rlutil::anykey();
        return false;
    }
    while (fread(&registro, sizeof(Empleado), 1, p) == 1) {
        if (registro.getDni() == 0) {
            rlutil::locate(40, 15);
            cout << "Solicitar permiso" << registro.getNombre() << "!" << endl;

            do {
                rlutil::locate(40, 17 + cont);
                cout << "INGRESE LA CLAVE ADMIN: ";
                //getline(cin, password);
                password = cinPassword();
                if (registro.getPassword() == password) {
                    rlutil::locate(40, 25);
                    cout << "Permiso habilitado" << endl;
                    Sleep(1000);
                }
                else {
                    rlutil::locate(40, 22);
                    cout << "SU CLAVE ES INCORRECTA" << endl;
                    cont++;
                    rlutil::locate(40, 23);
                    cout << "Le quedan " << --intentos << " intentos..." << endl;
                    if (intentos == 0) {
                        Sleep(1000);
                        fclose(p);
                        return false;
                    }
                }
            } while (registro.getPassword() != password);
        }
    }
    fclose(p);
    return true;
}

bool Parque::agregarEmpleado() {
    Empleado registro;
    int escribir;
    FILE* p;

    p = fopen("Empleados.dat", "ab");
    if (p == NULL) {
        cout << "No se pudo encontrar el archivo." << endl;
        rlutil::anykey();
        return false;
    }

    registro.CargarEmpleado();
    escribir = fwrite(&registro, sizeof(Empleado), 1, p);
    if (escribir == 0) {
        fclose(p);
        cout << "No se pudo guardar el registro." << endl;
        rlutil::anykey();
        return false;
    }

    fclose(p);
    cout << "Empleado cargada correctamente.";
    rlutil::anykey();
    return true;
}

///
void Parque::mostrarEmpleados() {
    Empleado registro;
    FILE* p;
    p = fopen("Empleados.dat", "rb");
    if (p == NULL) {
        cout << "No se encuentran registros" << endl;
        rlutil::anykey();
        return;
    }
    rlutil::locate(45, 3);
    cout << "- EMPLEADOS REGISTRADOS -" << endl;
    rlutil::locate(30, 4);
    cout << "-------------------------------------------------------" << endl;
    int pos = 0;
    while (fread(&registro, sizeof(Empleado), 1, p) == 1) {
        registro.MostrarEmpleado(pos);
        cout << endl;
        pos++;
    }
    fclose(p);
    rlutil::anykey();
}

///
bool Parque::InicioSesion() {
    Empleado registro;
    bool cargo, encontro = false;
    FILE* p;
    int opcion_ingreso;
    int dni, cont = 0, intentos = 3;;
    string password;
    

    p = fopen("Empleados.dat", "rb");
    if (p == NULL) {
        rlutil::locate(30, 13);
        cout << "No se encuentran empleados registrados..." << endl;
        rlutil::locate(26, 17);
        cout << "Presione 1 para crear la clave administrador" << endl;
        rlutil::locate(24, 20);
        cout << "Presione cualquier otra tecla para salir del programa" << endl;
        //cin >> continuar;// Tengo que forzar un ingreso por teclado previo al método "agregarEmpleado()" porque está hecho para ejecutarse luego de un cin>>. Si no, me come la primera letra con el cin.ignore().
        int key = rlutil::getkey();
        if (key != 49) {
            return false;
        }
        
        //fclose(p);//si no hay registros, cierro el file para abrirlo en modo escritura con el método "agregarEmpleado()"
        //rlutil::anykey();
        rlutil::cls();
        cargo = crearClaveMaestra();
        if (cargo) {
            rlutil::cls();
            rlutil::locate(45, 15);
            cout << "¡Bienvenid@!" << endl;
        }
        else {
            rlutil::cls();
            rlutil::locate(45, 15);
            cout << "¡Ups! No pudimos cargar el registro." << endl;
        }
        rlutil::anykey();
        return cargo;

    }

    rlutil::locate(30, 13);
    cout << "INGRESAR (presione 1) - REGISTRARSE (presione 2)";
    //cin >> opcion_ingreso;
    int key2 = rlutil::getkey();
    while (key2 != 49 && key2 != 50) {
        rlutil::cls();
        rlutil::locate(30, 13);
        cout << "INGRESAR (presione 1) - REGISTRARSE (presione 2)";
        //cin >> opcion_ingreso;
        int key2 = rlutil::getkey();
    }

    rlutil::cls();
    if (key2 == 49) {
        rlutil::locate(40, 13);
        cout << "INGRESE SU DNI PARA ACCEDER: ";
        cin >> dni;
        cin.ignore();

        while (fread(&registro, sizeof(Empleado), 1, p) == 1) {
            if (registro.getDni() == dni) {
                rlutil::locate(40, 15);
                cout << "¡HOLA " << registro.getNombre() << "!" << endl;
                
                do {
                    rlutil::locate(40, 17+cont);
                    cout << "INGRESE SU CLAVE PERSONAL: ";
                    //getline(cin, password);
                    password = cinPassword();
                    if (registro.getPassword() == password) {
                        rlutil::locate(40, 25);
                        cout << "SU CLAVE ES CORRECTA" << endl;
                        Sleep(3000);
                        encontro = true;
                    }
                    else{
                        rlutil::locate(40, 22);
                        cout << "SU CLAVE ES INCORRECTA" << endl;
                        cont++;
                        rlutil::locate(40, 23);
                        cout << "Le quedan " << --intentos << " intentos..." << endl;
                        if (intentos == 0) {
                            Sleep(1000);
                            fclose(p);
                            return false;
                        } 
                    }
                } while (registro.getPassword() != password);
            }
                
        }
        if (encontro == false) {
            rlutil::locate(30, 14);
            cout << "El DNI ingresado no corresponde a un usuario registrado." << endl;
            rlutil::anykey();
            return encontro;
        }
    }
    else {
        fclose(p);
        
        if(!validarClaveMaestra()) {
            return false;
        }
        rlutil::cls();
        cargo = agregarEmpleado();
        if (cargo) {
            rlutil::cls();
            rlutil::locate(45, 15);
            cout << "¡Bienvenid@!" << endl;
        }
        else {
            rlutil::cls();
            rlutil::locate(45, 15);
            cout << "¡Ups! No pudimos cargar el registro." << endl;
        }
        rlutil::anykey();
        return cargo;
    }

    fclose(p);
    rlutil::anykey();
    return true;
}

///
Parque::~Parque() {
}