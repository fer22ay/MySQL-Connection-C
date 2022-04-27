#include "Database.h"
#include <iostream>
#include <string>

using namespace std;

DB::Database::Database() {
}

DB::Database::~Database() {

}

/**
 * Metodo encargado de recibir el nombre de la base de datos que utilizara para conectarse a MySQL
 *
 * @param DBname Representa el nombre de la BD tipo String
 */
void DB::Database::SetDatabase(std::string DBname) {
	try{
		this->conn->setSchema(DBname);
		cout << "Conectado a la base de datos: " << DBname << endl;
	} catch(sql::SQLException &e) {
		cout << "Error name database: " << e.what() << endl;
	}
}

/**
 * Metodo para conectarse a la base de datos con las credenciales del usuario
 *
 * @param ip Representa la direccion IP del servidor de MySQL
 * @param port Representa el puerto configurado para la conexion por defecto 3306
 * @param username Representa el nombre de usuario para la conexion
 * @password Representa la contrase;a del usuario
 */
void DB::Database::Connect(std::string ip, std::string port, std::string username, std::string password) {
	try {
		this->driver = sql::mysql::get_mysql_driver_instance();
		this->conn = this->driver->connect("tcp://" + ip + ":" + port + "", username, password);
		cout << "Conexion establecida" << endl;
	} catch(sql::SQLException &e) {
		cout << "Error validate username or password" << e.what() << endl;
	}
}

/**
 * Metodo para cerrar las operaciones con la base de datos
 */
void DB::Database::Close() {
	try {
		delete this->Res;
		delete this->Stmt;
		delete this->conn;
	} catch(sql::SQLException &e) {
		cout << "Error closed session" << e.what();
	}
}

/**
 * Metodo para ejectura un query de la base de datos (SELECT * FROM productos)
 *
 * @param query Representa los datos de una tabla a consultar en la base de datos de tipo String
 * @param rowSize Representa la cantidad de columnas que tiene la tabla
 */
void DB::Database::Execute(std::string query, int rowSize) {
	try {
		this->Stmt = this->conn->createStatement();
		this->Res = this->Stmt->executeQuery(query);
		while(Res->next()) {
			for (int a = 1; a != rowSize + 1; a++) {
				cout << Res->getString(a) << endl;
			}
		}
	} catch (sql::SQLException &e) {
		cout << "Error in excute query" << e.what();
	}
}

/**
 * Metodo para insertar en una tabla de la base de datos
 *
 * @param query Representa el query de la tabla que se va insertar
 */
void DB::Database::Insert(std::string query) {
	try {
		this->Pstmt = this->conn->prepareStatement(query);
		this->Pstmt->executeQuery();	
		cout << "Datos registrados con exito" << endl;
	} catch (sql::SQLException &e) {
		cout << "Error al actualizar registro" << e.what();
	}
}

/**
 * Metodo para actualizar datos de una tabla en la base de datos
 *
 * @param Representa el query de la tabla que se va actulizar los datos
 */
void DB::Database::Update(std::string query) {
	try {
		this->Pstmt = this->conn->prepareStatement(query);
		this->Pstmt->executeQuery();
		cout << "Registro actualizado con exito" << endl;
	} catch (sql::SQLException &e) {
		cout << "Error al actualizar registro" << e.what();
	}
}

/**
 * Metodo para eliminar un registro de la base de datos
 *
 * @param query Representa el query de la tabla del registro o los registros que se van a eliminar
 */
void DB::Database::Delete(std::string query) {
	try{
		this->Pstmt = this->conn->prepareStatement(query);
		this->Res = this->Pstmt->executeQuery();
		cout << "Registro eliminado con exito" << endl;
	} catch (sql::SQLException &e) {
		cout << "Error al eliminar registro en la BD" << e.what();
	}
}

int main(void) {
	return 0;
}
