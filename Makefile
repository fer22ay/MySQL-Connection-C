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
CFLAGS=-c -Wall -I/usr/include/mysql-cppconn-8 -I../include

LDFLAGS = -lm -L/usr/lib/x86_64-linux-gnu -lmysqlcppconn

all: mySqlConn

mySqlConn: mySqlConn.o
	$(CC) $(LDFLAGS) mySqlConn.o -o mySqlConn
mySqlConn.o: mySqlConn.cpp
	$(CC) $(CFLAGS) mySqlConn.cpp -o mySqlConn.o

clean:
	rm -f *.o mySqlConn
