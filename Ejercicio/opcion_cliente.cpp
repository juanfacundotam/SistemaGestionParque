#include <iostream>
#include "rlutil.h"
#include "visuales.h"
#include "funciones.h"
#include "opcion_cliente.h"
#include "Menu.h"

using namespace std;


/// Men� opci�n 1 (clientes):
void opcion_1(Parque& parque) {
    int opcion_menu;
    Menu menu_ventas;


    Ingresando_ventas();
    rlutil::cls();

    config_menu_ventas(menu_ventas);
    opcion_menu = menu_ventas.MostrarMenu();


    while (true) {
        switch (opcion_menu) {
        case 1:
            proximamente();
            break;
        case 2:
            proximamente();
            break;
        case 3:
            proximamente();
            break;
        case 4:
            proximamente();
            break;
        case 5:
            proximamente();
            break;
        case 6:
            proximamente();
            break;
        case 7:
            proximamente();
            break;
        case 0:
            rlutil::cls();
            rlutil::locate(45, 12);
            std::cout << "VOLVIENDO AL MEN� INICIAL...";
            return;
            break;
        default:
            rlutil::cls();
            rlutil::locate(55, 12);
            std::cout << "SELECCIONE UNA OPCI�N V�LIDA.";
            rlutil::anykey();
            break;
        }
        rlutil::cls();
        opcion_menu = menu_ventas.MostrarMenu();

    }
}



///Funci�n para mostrar el men�:

void config_menu_ventas(Menu& menu) {
    std::setlocale(LC_ALL, "");

    menu.SetCantItems(8);
    menu.SetNombre("- �REA VENTAS -");
    menu.AddItem("COMPRAR PASE", 1);
    menu.AddItem("SELECCIONAR ACTIVIDAD", 2);
    menu.AddItem("COMPRAR UPGRADE", 3);
    menu.AddItem("CANCELAR PASE INDIVIDUAL", 4);
    menu.AddItem("LISTADO DE RESERVAS", 5);
    menu.AddItem("BUSCAR RESERVA", 6);
    menu.AddItem("DEVOLUCI�N DE RESERVAS DEL DIA", 7);
}

/// Pantalla transici�n al men�:
void Ingresando_ventas() {
    rlutil::cls();
    rlutil::locate(20, 15);
    cout << "INGRESANDO AL �REA DE VENTAS.";
    dino();
    rlutil::locate(2, 27);
    std::cout << "Continuar...";
    rlutil::anykey();
}
