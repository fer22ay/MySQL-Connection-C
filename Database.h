#ifndef DATABASE_H
#define DATABASE_H

#include <iostream>
#include <stdlib.h>
#include <mysql/jdbc.h>

using namespace std;
using namespace sql;

namespace DB {
class Database {

protected:
	sql::mysql::MySQL_Driver	*driver;
	sql::Connection			*conn;
	sql::Statement			*Stmt;
	sql::ResultSet			*Res;
	sql::PreparedStatement		*Pstmt;
	
public:
	Database();
	~Database();
	Database(std::string,std::string, std::string, std::string);
	void Execute(std::string, int);
	void Close();
	void SetDatabase(std::string);
	void Connect(std::string, std::string, std::string, std::string);
	void Insert(std::string);
	void Update(std::string);
	void Delete(std::string);

};
};
#endif
