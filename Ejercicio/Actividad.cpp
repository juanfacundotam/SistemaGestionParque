#include <iostream>
#include "Actividad.h"
#include "rlutil.h"



using namespace std;

Actividad::Actividad() {
    strcpy(_nombre, "Sin definir");
    _codigo = 0;
    _ocupacion = 0;
    _capacidad = 0;
    _precio = 0;
    _alturaMin = 0;
    _edadMin = 0;
    _estado = 0;
    //_cont_actividad = 0;
    //_indiceActividad = _cont_actividad;
}

/*Actividad::Actividad(string nombre, int codigo, int capacidad, float precio, float altura, int edad) {
    _nombre = nombre;
    _codigo = codigo;
    _ocupacion = 0;
    _capacidad = capacidad;
    _precio = precio;
    _alturaMin = altura;
    _edadMin = edad;
}*/


void Actividad::CargarActividad() {
    std::setlocale(LC_ALL, "");
    cout << "- Registrar actividad -" << endl;
    cout << "Nombre: ";
    cin.ignore();
    cin.getline(_nombre, 29);
    cout << "Código (4 dígitos numéricos): ";
    cin >> _codigo;
    cout << "Capacidad: ";
    cin >> _capacidad;
    cout << "Precio: ";
    cin >> _precio;
    cout << "Altura mínima: ";
    cin >> _alturaMin;
    cout << "Edad mínima: ";
    cin >> _edadMin;
    cout << endl << endl;
    _ocupacion = 0;
    _estado = true;
    //_indiceActividad = _cont_actividad;
    //_cont_actividad++;

}

void Actividad::ocuparLugar() {
    if (_disponibilidad >= 1) {
        _ocupacion++;
        _disponibilidad--;
    }
}

void Actividad::liberarLugar() {
    _ocupacion--;
    _disponibilidad++;
}

void Actividad::mostrarDescripcion(int x) {
    setlocale(LC_ALL, "");
    rlutil::locate(43, 5 + (x * 7));
    cout << ">> " << _nombre << endl;
    rlutil::locate(45, 6 + (x * 7));
    cout << "- Código: " << _codigo << endl;
    rlutil::locate(45, 7 + (x * 7));
    cout << "- Capacidad: " << _capacidad << " personas" << endl;
    if (_alturaMin == 0) {
        rlutil::locate(45, 8 + (x * 7));
        cout << "- Altura mínima: sin restricción" << endl;
    }
    else {
        rlutil::locate(45, 8 + (x * 7));
        cout << "- Altura mínima: " << _alturaMin << " m" << endl;
    }
    if (_edadMin == 0) {
        rlutil::locate(45, 9 + (x * 7));
        cout << "- Edad mínima: sin restricción" << endl;
    }
    else {
        rlutil::locate(45, 9 + (x * 7));
        cout << "- Edad mínima: " << _edadMin << " años" << endl;
    }
    rlutil::locate(45, 10 + (x * 7));
    cout << "- Precio: $" << _precio << endl;
    cout << endl;
}


void Actividad::setCodigo(int codigo) {
    if (codigo > 0) {
        _codigo = codigo;
    }
}

void Actividad::setNombre(std::string nombre) {
    strcpy(_nombre, nombre.c_str());
}


void Actividad::setCapacidad(int capacidad) {
    _capacidad = capacidad;
}


void Actividad::setPrecio(float precio) {
    _precio = precio;
}



void Actividad::setAlturaMin(float altura) {
    _alturaMin = altura;
}

void Actividad::setEdadMin(int edad) {
    _edadMin = edad;
}

/*void Actividad::setIndiceActividad(int numero)
{
    _indiceActividad = numero;
}*/

int Actividad::getCapacidad() {
    return _capacidad;
}

int Actividad::getOcupacion() {
    return _ocupacion;
}

int Actividad::getDisponibilidad() {
    return _disponibilidad;
}

/*int Actividad::getIndiceActividad()
{
    return _indiceActividad;
}*/

float Actividad::getPrecio() {
    return _precio;
}

float Actividad::getAlturaMin() {
    return _alturaMin;
}

int Actividad::getEdadMin() {
    return _edadMin;
}

int Actividad::getCodigo() {
    return _codigo;
}

string Actividad::getNombre() {
    return _nombre;
}