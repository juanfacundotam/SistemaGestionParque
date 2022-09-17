//Nombre: Juan Facundo Tam
//TP N°: 
//EJ N°: 
//Comentarios:
/*

*/
#include<iostream>
#include<clocale>
#include<string.h>

using namespace std;
#include"menu.h"
#include"Parque.h"
#include"visuales.h"
#include"rlutil.h"
#include"funciones.h"
#include"Empleado.h"
#include"Cliente.h"
#include"opcion_admin.h"
#include"opcion_cliente.h"




int main(void) {
    setlocale(LC_ALL, "Spanish");

    int opcion;
    Menu menuInicio;
    Parque parque;

    parque.Abrir();
    pantalla_presentacion();
    rlutil::cls();
    char salir ='N';
    config_menu_inicio(menuInicio);
    
    if (!parque.InicioSesion()) {
        salir = 'S';
    }
    else {
        rlutil::cls();
        ovni();
        rlutil::locate(75, 12);
        std::cout << "Byeeeee!";
        rlutil::locate(55, 27);
        return 0;
    }

    while (salir != 'S') {
        
        opcion = menuInicio.MostrarMenu();
        
        switch (opcion) {
        case 1:/// ////////////////////// MENÚ CLIENTES /////////////////////////////////
            rlutil::cls();
            opcion_1(parque);
            rlutil::anykey();
            break;
        case 2:/// //////////////////////////// MENÚ EMPRESA ////////////////////////////
            rlutil::cls();
            opcion_2(parque);
            rlutil::anykey();
            break;
        case 0:
            rlutil::cls();
            opcion_salir(salir);
            break;
        default:
            rlutil::cls();
            rlutil::locate(55, 12);
            std::cout << "SELECCIONE UNA OPCIÓN VÁLIDA.";
            rlutil::anykey();
            break;
        }
       ///SALIR DEL PROGRAMA:
        if (salir != 'S') {
            rlutil::cls();
            salir = 'N';
        }
    }//fin del menú inicial
     
    
    rlutil::cls();
    ovni();
    rlutil::locate(75, 12);
    std::cout << "Byeeeee!";
    rlutil::locate(55, 27);
            
    
        
//
//
    //rlutil::locate(55, 25);
    return 0;
}