#pragma once
#include <iostream>
#include "Persona.h"

class Empleado :public Persona {

private:
    char _cargo[30];
    char _password[30];
    bool _estado;
public:
    Empleado();
    void CargarEmpleado();
    void MostrarEmpleado(int x);
    void eliminarEmpleado();
    void setCargo(string);
    void setEstado(bool);
    void setPassword(string pass);
    char *getPassword();
    string getCargo();
    bool getEstado();
    //~Empleado();
};