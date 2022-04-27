#include "Producto.h"
#include <iostream>
#include <string>

using namespace std;

Producto::Producto() {
}

Producto::~Producto(){
}

/**
 * Sobre carga del metodo constructor de Producto
 * @param codigo
 * @param nombre
 * @param descripcion
 * @param categoria
 * @param estado
 * @param precio
 */
Producto::Producto(int _codigo, std::string _nombre, std::string _descripcion, std::string _categoria, char _estado, float _precio) {
	this->codigo = _codigo;
	this->nombre = _nombre;
	this->descripcion = _descripcion;
	this->categoria = _categoria;
	this->estado = _estado;
	this->precio =_precio;
}

/**
 * @param codigo
 */
void Producto::setCodigo(int codigo) {
	this->codigo = codigo;
}

int Producto::getCodigo() {
	return this->codigo;
}

/**
 * @param nombre
 */
void Producto::setNombre(std::string nombre) {
	this->nombre = nombre;
}

string Producto::getNombre() {
	return this->nombre;
}

/**
 * @param descripcion
 */
void Producto::setDescripcion(std::string descripcion) {
	this->descripcion = descripcion;
}

string Producto::getDescripcion() {
	return this->descripcion;
}

/**
 * @param categoria
 */
void Producto::setCategoria(std::string categoria) {
	this->categoria = categoria;
}

string Producto::getCategoria() {
	return this->categoria;
}

/**
 * Metodo para asignar el estado del producto 1 = ACTIVO, 0 = INACTIVO
 * @param estado tipo Char
 */
void Producto::setEstado(char estado) {
	this->estado = estado;
}

/**
 * Metodo para obtener el estado del producto
 * @return Retorna el estado del producto
 */
char Producto::getEstado() {
	return this->estado;
}

/**
 * Metodo para asignar precio al producto
 * @param precio tipo Double
 */
void Producto::setPrecio(float precio) {
	this->precio = precio;
}

/**
 * Metodo para obtener el precio del producto
 * @return Precio del producto
 */
float Producto::getPrecio() {
	return this->precio;
}

int main() {

	return 0;
}
