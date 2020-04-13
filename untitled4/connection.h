#ifndef CONNECTION_H
#define CONNECTION_H
#include <QtSql>

class connection
{

public:
    QSqlDatabase qq;
    connection();

    int summa();
};

#endif // CONNECTION_H
