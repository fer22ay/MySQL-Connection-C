#ifndef PRODUCTO_H
#define PRODUCTO_H

#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

struct Producto {

private:
	int codigo;
	std::string nombre;
	std::string descripcion;
	std::string categoria;
	char estado;
	float precio;

public:
	Producto();
	~Producto();
	Producto(int _codigo, std::string _nombre, std::string _descripcion, std::string _categoria, char _estado, float _precio);

	void setCodigo(int);
	int getCodigo();
	void setNombre(string);
	string getNombre();
	void setDescripcion(string);
	string getDescripcion();
	void setCategoria(string);
	string getCategoria();
	void setEstado(char);
	char getEstado();
	void setPrecio(float);
	float getPrecio();

};

#endif
