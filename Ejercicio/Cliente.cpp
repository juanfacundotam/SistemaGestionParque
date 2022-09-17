#include "Cliente.h"


///
Cliente::Cliente() {
    _edad = 0;
    _altura = 0;
    _estado = false;
}

///
void Cliente::cargarCliente() {
    std::setlocale(LC_ALL, "");
    cout << "- Registrar cliente -" << endl;
    cargarPersona();
    cout << "Edad (numero entero): ";
    cin >> _edad;
    cout << "Altura (separando decimales con punto): ";
    cin >> _altura;
    cout << endl << endl;
    _estado = true;
}



///
void Cliente::mostrarCliente(int x) {
    setlocale(LC_ALL, "");
    mostrarPersona(x);
    rlutil::locate(45, 7 + (x * 7));
    cout << "- Edad" << _edad << endl;
    rlutil::locate(45, 8 + (x * 7));
    cout << "- Altura" << _altura << endl;
    cout << endl << endl;
}



///
void Cliente::eliminarCliente() {

}

///
void Cliente::setEdad(int edad) {
    _edad = edad;
}

///
void Cliente::setAltura(float altura) {
    _altura = altura;
}

///
int Cliente::getEdad() {
    return _edad;
}

///
float Cliente::getAltura() {
    return _altura;
}