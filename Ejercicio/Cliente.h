#pragma once
#include "Persona.h"
#include "rlutil.h"

class Cliente : public Persona {
private:
	int _edad;
	float _altura;
	bool _estado;
public:
	Cliente();
	void cargarCliente();
	void mostrarCliente(int x);
	void eliminarCliente();
	void realizarCompra();
	void setEdad(int);
	void setAltura(float);
	int getEdad();
	float getAltura();
	~Cliente();
};
