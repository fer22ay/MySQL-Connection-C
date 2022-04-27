#include <stdlib.h>
#include <iostream>
#include <string>
#include <mysql/jdbc.h>

using namespace std;
using namespace sql;

int main() {

	try {
	
		sql::mysql::MySQL_Driver 	*myDriver;
		sql::Connection 		*myConn;
		sql::Statement 			*myStmt;
		sql::ResultSet 			*myRes;

		cout << "Connecting to MySQL server" << endl;

		myDriver = sql::mysql::get_mysql_driver_instance();

		// Connection: ip, username, password
		myConn = myDriver->connect("tcp://127.0.0.1:3306", "root", "mysql");
		
		// Name database
		myConn->setSchema("test");

		myStmt = myConn->createStatement();

		// Query example
		myRes = myStmt->executeQuery("SELECT codigo, nombre, descripcion, categoria, CASE estado WHEN 1 THEN 'ACTIVO' ELSE 'INACTIVO' END as estado_producto, precio FROM productos WHERE estado = 1");

		while (myRes->next()) {
		
			cout << myRes->getString("codigo") << " " << myRes->getString("nombre") << " " << myRes->getString("descripcion") << endl;
			cout << myRes->getString("categoria") << endl;
			cout << myRes->getString("estado_producto") << endl;
			cout << myRes->getString("precio") << endl;
		}

		delete myRes;
		delete myStmt;
		cout << "Connected...!" << endl;
		delete myConn;

	} catch(sql::SQLException &e) {
	
		cout << "Error: " << e.what() << endl;
		cout << "Error code: " << e.getErrorCode() << endl;
		cout << "SQLState: " << e.getSQLState() << endl;
	}

	return 0;
}
