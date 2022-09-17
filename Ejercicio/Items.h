#pragma once
#include <string>
#include <iostream>
using namespace std;

class Items
{
protected:
    string _nombreOpcion;
    int _posicion;
public:
    Items();
    Items(string, int);
    void SetPosision(int);
    void SetNombre(string);
    string GetNombre();
    int GetPosicion();
};

