#include <iostream>
#include <string>
#include "Producto.h"
#include "Database.h"

using namespace std;
using namespace sql;

void mostrarMenu();
void listarProductos();

int main() {

	cout << "Hola desde archivo principal" << endl;
	mostrarMenu();
	return 0;

}

void listarProductos() {

	cout << "Listado de productos" << endl;
//	Producto p*;
	Database *database = new Database();

	database->Connect("127.0.0.1", "3306", "root", "mysql");
	database->SetDatabase("test");
	database->Execute("SELECT * FROM productos", 6);

	database->Close();

//	p.setCodigo(2675);
//	p.setNombre("Pepsi cola");
//	p.setDescripcion("BEBIDA CARBONATADA");
//	p.setCategoria("BEBIDAS");
//	p.setEstado('1');
//	p.setPrecio(4.50);

//	cout << "El codigo es: " << p.getCodigo() << endl;
//	cout << p.getNombre() << endl;
//	cout << p.getDescripcion() << endl;
//	cout << p.getCategoria() << endl;
//	cout << p.getEstado() << endl;
//	cout << p.getPrecio() << endl;

}

void mostrarMenu() {

	int exit = 0;
	do { 
	
		cout << endl;
		cout << "BIENVENIDO SELECIONA UNA OPCION" << endl;
		cout << endl;
		cout << "1. Listar datos de la BD" << endl;

		int response;
		cout << endl;
		cout << "Ingresa una opcion:";
		cin >> response;
		cout << endl;

		switch(response) {

			case 0:
				exit = 0;
				break;
			case 1:
				listarProductos();
				break;
			default:
				system("clear");
				exit = 0;
				break;
		
		}

	} while(exit != 0);
}
