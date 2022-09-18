#include <iostream>
#include "rlutil.h"
#include "visuales.h"
#include<conio.h>
#include<stdlib.h>
#include<string>
using namespace std;
#include "Menu.h"
#include "funciones.h"

// Ac� van las funciones del main y las que se utilicen a nivel general solamente.

///Men� inicio:
void config_menu_inicio(Menu& menu) {
    setlocale(LC_ALL, "");

    menu.SetCantItems(3);
    menu.SetNombre("- PARQUE JUR�SICO -");
    menu.AddItem("�REA CLIENTES", 1);
    menu.AddItem("�REA ADMINISTRATIVA", 2);
}

string cinPassword()
{
    int v;
    char clave[30];

    
    for (int i = 0; i < 30; i++) {
        do {
            v = getch();
        } while (v == 8);
        if (v != 13) {
            clave[i] = v;
            cout << "*";
        }
        else {
            clave[i] = '\0';
            cout << endl;
            break;
        }
        
        /*if (v == '\r') {
            clave[i] = '\0';
            break;
        }*/
    }

    return clave;
}



///funcion para confirmar salida del programa
void opcion_salir(char &salir) {
    
    rlutil::locate(55, 12);
    cout << "�Salir? S / N: ";
    cin >> salir;
    salir = toupper(salir);
    while (salir != 'S' && salir != 'N') {
        rlutil::cls();
        rlutil::locate(55, 12);
        cout << "�Salir? S / N: ";
        cin >> salir;
        salir = toupper(salir);
    }
}


///Funci�n provisoria "proximamente":
void proximamente() {
    rlutil::cls();
    rlutil::locate(30, 15);
    cout << "pr�ximamente";
    dino();
    rlutil::locate(2, 27);
    cout << "Presione una tecla para volver al men�.";
    rlutil::anykey();
}