# MySQL-Connection-C++
Connection to MySQL with C++ from to terminal linux Debian 10, configuration environment and Makefile

## Required Software
### 🖥️ Machine Virtual Vbox (VirtualBox) Debian 10 Buster ISO
 - `# lsb_realease -a`
 - `# apt update`
 - `# apt install build-essential dkms linux-headers-$(uname -r)`
 - `# apt install wget`
### 🐬 Install MySQL server version: 8.0.28
 - `wget https://dev.mysql.com/get/mysql-apt-config_0.8.22-1_all.deb`
 - `sudo apt install ./mysql-apt-config_0.8.22-1_all.deb`
 - `sudo apt update`
 - `sudo apt install mysql-server`
 - `sudo service mysql status`
#### Connection to MySQL server:
 - `mysql -u root -p`
    + username = root; password = test
#### Version MySQL from to terminal
 - `SELECT VERSION();`
#### Create DB in MySQL:
 - `SHOW DATABASES;`
 - `CREATE DATABASE test;`
#### Connect to DB:
 - `USE database_name`
#### Create table:
 - `CREATE TABLE products (code int not null auto_increment primary key, name varchar(100), description varchar(100), category varchar(50), state char(1), price decimal(5,2));`
Show tables in DB:
 - `SHOW TABLES;`
#### Describe table name in DB
 - `DESCRIBE products`
### 🔗 Install C++
- `apt install build-essential`
- `g++ --version`
- `gcc --version`
#### Execute Makefile to run program
- `make mySqlConn`
- `apt install cmake`
- `cmake --version`
### Library Mysql Connector/C++
- `apt install libmysqlcppconn-dev`
#### Path installation
- `cd /usr/include`
- `ls -l *cppconn*`
- `cd /usr/lib/x86_64-linux-gnu`

## Create file .cpp to the connection with MySQL
Create filename mySqlConn.cpp
  + `touch mySqlConn.cpp`
  + `touch Makefile`
#### Execute command to run program
- `make mySqlConn`
