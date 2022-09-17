#include "Menu.h"


Menu::Menu() {
    std::setlocale(LC_ALL, "");
    _cantidadItems = 10;
    _opciones[0] = Items("Salir", 0);
    _opciones[1] = Items("opci�n 1", 1);
    _opciones[2] = Items("opci�n 2", 2);
    _opciones[3] = Items("Opci�n 3", 3);
    _opciones[4] = Items("Opci�n 4", 4);
    _opciones[5] = Items("Opci�n 5", 5);
    _opciones[6] = Items("Opci�n 6", 6);
    _opciones[7] = Items("Opci�n 7", 7);
    _opciones[8] = Items("Opci�n 8", 8);
    _opciones[9] = Items("Opci�n 9", 9);
    _nombre = "MEN�";
}

int Menu::MostrarMenu() {
    int x;
    int eleccion;

    rlutil::locate(45, 10);
    std::cout << _nombre;
    rlutil::locate(40, 11);
    std::cout << "--------------------------------";

    for (x = 1; x < _cantidadItems; x++) {
        if (_opciones[x].GetPosicion() == x) {
            rlutil::locate(42, 11 + (x));
            std::cout << _opciones[x].GetPosicion() << " - " << _opciones[x].GetNombre();
        }
    }
    rlutil::locate(42, 11 + _cantidadItems + 1);
    std::cout << _opciones[0].GetPosicion() << " - " << _opciones[0].GetNombre();
    rlutil::locate(40, 11 + _cantidadItems + 2);
    std::cout << "--------------------------------";
    rlutil::locate(42, 11 + _cantidadItems + 3);
    std::cout << "Su elecci�n: ";
    std::cin >> eleccion;

    return eleccion;
}

void Menu::SetCantItems(int cant_items) {
    _cantidadItems = cant_items;
}

void Menu::AddItem(std::string nombre, int pos) {
    for (int i = 1; i < _cantidadItems; i++) {
        if (_opciones[i].GetPosicion() == pos) {
            _opciones[i].SetNombre(nombre);
            _opciones[i].SetPosision(pos);
        }
    }
}

void Menu::SetNombre(std::string nombre_menu) {
    _nombre = nombre_menu;
}



int Menu::GetCantItems() {
    return _cantidadItems;
}

std::string Menu::GetNombre() {
    return _nombre;
}

Menu::~Menu() {
    //dtor
}
