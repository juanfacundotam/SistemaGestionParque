#include "Items.h"

Items::Items() {
    _nombreOpcion = "opcion";
    _posicion = 1;
}

Items::Items(string nombre, int posicion) {
    _nombreOpcion = nombre;
    _posicion = posicion;
}

void Items::SetPosision(int posicion) {
    _posicion = posicion;
}

void Items::SetNombre(string nombre) {
    _nombreOpcion = nombre;
}

string Items::GetNombre() {
    return _nombreOpcion;
}
int Items::GetPosicion() {
    return _posicion;
}