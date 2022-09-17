#pragma once
#include "Items.h"
#include "rlutil.h"


class Menu {

private:
    string _nombre;
    int _cantidadItems;
    Items _opciones[10];
protected:

public:
    Menu();
    int MostrarMenu();
    void SetNombre(string);
    void SetCantItems(int);
    void AddItem(string, int);
    int GetCantItems();
    string GetNombre();
    ~Menu();

};
