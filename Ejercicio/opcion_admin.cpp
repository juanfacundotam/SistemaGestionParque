#include <iostream>
#include "rlutil.h"
#include "visuales.h"
#include "funciones.h"
#include "Menu.h"
#include "opcion_admin.h"


using namespace std;


///Ocion 2 (admin):
void opcion_2(Parque& parque) {
    int opcion_menu_admin;
    Menu menu_dos;

    Actividad test;

    Ingresando_admin();
    rlutil::cls();
    config_menu_admin(menu_dos);
    opcion_menu_admin = menu_dos.MostrarMenu();

    while (true) {
        switch (opcion_menu_admin) {
        case 1:
            proximamente();
            break;
        case 2:
            rlutil::cls();
            parque.agregarEmpleado();
            break;
        case 3:
            rlutil::cls();
            parque.mostrarEmpleados();
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
            rlutil::cls();
            parque.agregarActividad();
            break;
        case 8:
            rlutil::cls();
            parque.mostrarActividades();
            break;
        case 9:
            proximamente();
            break;
        case 0:
            rlutil::cls();
            rlutil::locate(45, 12);
            std::cout << "VOLVIENDO AL MENÚ INICIAL...";
            return;
            break;
        default:
            rlutil::cls();
            rlutil::locate(55, 12);
            std::cout << "ELIJA UNA OPCIÓN VÁLIDA.";
            rlutil::anykey();
            break;

        }
        rlutil::cls();
        opcion_menu_admin = menu_dos.MostrarMenu();

    }
}



///Menú Administración:
void config_menu_admin(Menu& menu) {
    std::setlocale(LC_ALL, "");

    menu.SetCantItems(10);
    menu.SetNombre("- ÁREA ADMINISTRATIVA -");
    menu.AddItem("EDITAR EMPLEADO", 1);
    menu.AddItem("AGREGAR EMPLEADO", 2);
    menu.AddItem("MOSTRAR LISTADO DE EMPLEADOS", 3);
    menu.AddItem("EDITAR PASES", 4);
    menu.AddItem("AGREGAR PASE NUEVO", 5);
    menu.AddItem("EDITAR ACTIVIDADES", 6);
    menu.AddItem("AGREGAR ACTIVIDAD NUEVA", 7);
    menu.AddItem("MOSTRAR ACTIVIDADES DISPONIBLES", 8);
    menu.AddItem("ESTADÍSTICAS", 9);
    ///ESTOS TRES QUE SIGUEN LOS PASO PARA EL MENÚ DE VENTAS:
    // menu.AddItem("LISTADO DE RESERVAS", 1);
    // menu.AddItem("BUSCAR RESERVA", 2);
    //menu.AddItem("DEVOLUCIÓN DE RESERVAS DEL DIA", 3);
}

/// Pantalla transición al menú:
void Ingresando_admin() {
    rlutil::cls();
    rlutil::locate(20, 15);
    cout << "INGRESANDO AL ÁREA ADMINISTRATIVA.";
    dino();
    rlutil::locate(2, 27);
    std::cout << "Continuar...";
    rlutil::anykey();
}
