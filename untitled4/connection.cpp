#include "connection.h"

connection::connection(){

    qq = QSqlDatabase::addDatabase("QPSQL");
    qq.setDatabaseName("drevesina");
    qq.setUserName("postgres");
    qq.setPassword("1");
    qq.setHostName("127.0.0.1");
    qq.setPort(5432);
}



int connection::summa(){
     return 2+3;
}


