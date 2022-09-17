#pragma once
#include <stdlib.h>
#include <string.h>

//using namespace std;
class Actividad {

private:
    char _nombre[30];
    int _codigo;
    int  _capacidad;
    int _disponibilidad;
    int _ocupacion;
    float _precio;
    float _alturaMin;
    int _edadMin;
    //int _cont_actividad;
    //int _indiceActividad;
    bool _estado;
public:
    Actividad();
    //Actividad(string, int, int, float, float, int);
    void CargarActividad();
    void ocuparLugar();
    void liberarLugar();
    void mostrarDescripcion(int x);
    void setCodigo(int);
    void setNombre(std::string);
    void setCapacidad(int);
    void setPrecio(float);
    void setAlturaMin(float);
    void setEdadMin(int);
    void setIndiceActividad(int);
    int getCapacidad();
    int getOcupacion();
    int getDisponibilidad();
    int getIndiceActividad();
    float getPrecio();
    float getAlturaMin();
    int getEdadMin();
    int getCodigo();
    std::string getNombre();
    //~Actividad();
};
