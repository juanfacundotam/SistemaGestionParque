#include "Empleado.h"
#include "funciones.h"

Empleado::Empleado() {
    strcpy(_cargo, "");
    *_password = ' ';
    _estado = false;
}
Empleado::Empleado(bool admin) {
    Persona::setNombre("admin");
    Persona::setApellido("admin");
    Persona::setDni(0);
    strcpy(_cargo, "admin");
    *_password = ' ';
    _estado = false;
}



///
void Empleado::CargarEmpleado() {
    string repetirPass;
    std::setlocale(LC_ALL, "");
    cargarPersona();
    cin.ignore();
    cout << "Cargo: ";
    cin.getline(_cargo, 29);
    do {
        cout << "Ingrese una clave: ";
        strcpy(_password, cinPassword().c_str());
        //cin.getline(_password, 30);
        cout << "Repita la clave: ";
        repetirPass = cinPassword();
        if (_password == repetirPass) {
            cout << "Clave creada correctamente" << endl;
        }
        else {
            cout << "Las claves no coinciden" << endl;
        }
    } while (_password != repetirPass);
    cout << endl << endl;
    _estado = true;
}


///
void Empleado::MostrarEmpleado(int x) {
    setlocale(LC_ALL, "");
    mostrarPersona(x);
    rlutil::locate(45, 7 + (x * 5));
    cout << "- Cargo: " << _cargo << endl;
    rlutil::locate(45, 8 + (x * 5));
    if (_estado) {
        cout << "- Estado: Activo" << endl;
    }
    else {
        cout << "- Estado: Inactivo" << endl;
    }

}

///
void Empleado::setCargo(string cargo) {
    strcpy(_cargo, cargo.c_str());
}

///
void Empleado::setEstado(bool estado) {
    _estado = estado;
}

void Empleado::setPassword(string pass)
{
    strcpy(_password, pass.c_str());
}

char *Empleado::getPassword()
{
    return _password;
}

///
string Empleado::getCargo() {
    return _cargo;
}

///
bool Empleado::getEstado() {
    return _estado;
}


///
void Empleado::eliminarEmpleado() {

}
