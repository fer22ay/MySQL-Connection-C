# Fernando test g++ Makefile on LInux
# 
#  -o output file
#  -c compile but not link
#  -L, -I include and lib paths
#  -l link a lib
#  -g insert debugging info in your exutable
#
#  /usr/lib/x86_64-linux-gnu
#  /usr/include/mysql-cppconn-8
#  /usr/include/boost

CC=g++ 
# -std=c++11
CFLAGS=-c -Wall -I/usr/include/mysql-cppconn-8 -I../include

LDFLAGS = -lm -L/usr/lib/x86_64-linux-gnu -lmysqlcppconn

all: mySqlConn Database main Producto

Producto: Producto.o Producto.h
	$(CC) $(LDFLAGS) Producto.o -o Producto
Producto.o: Producto.h

main: main.o
	$(CC) $(LDFLAGS) main.o -o main
main.o: main.cpp
	$(CC) $(CFLAGS) main.cpp -o main.o

Database: Database.o
	$(CC) $(LDFLAGS) $(CXXFLAGS) Database.o -o Database
Database.o: Database.cpp
	$(CC) $(CFLAGS) $(CXXFALGS) Database.cpp -o Database.o

mySqlConn: mySqlConn.o
	$(CC) $(LDFLAGS) mySqlConn.o -o mySqlConn
mySqlConn.o: mySqlConn.cpp
	$(CC) $(CFLAGS) mySqlConn.cpp -o mySqlConn.o

clean:
	rm -f *.o mySqlConn Database main
