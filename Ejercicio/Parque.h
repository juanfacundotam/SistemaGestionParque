#pragma once
#include "Actividad.h"
#include "Cliente.h"
#include "Empleado.h"


class Parque {
private:
    int _cantidadActividades;
    int _cantidadEmpleados;
    bool _estado;
public:
    Parque();
    void Abrir();
    bool agregarActividad();
    void mostrarActividades();
    bool agregarEmpleado();
    void mostrarEmpleados();
    bool crearClaveMaestra();
    bool validarClaveMaestra();
    int InicioSesion();
    /*
    //Para mí estos tres van en la parte de ventas. Porque el cliente se registra cuando hace la compra. Si no el usuario tendria que estar yendo y viniendo de un menú al otro para concretar la venta de un pase.
    void agregarCliente();
    bool archivarcliente(Cliente);
    void mostrarClientes();
    */
    ~Parque();
};


