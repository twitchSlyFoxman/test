#ifndef MANAGER_H
#define MANAGER_H

#include <QObject>
#include "startform.h"
#include "mainwindow.h"

class manager : public QObject
{
    Q_OBJECT
public:
    manager();
    StartForm* form;
    MainWindow* mainw;
private slots:
    void StartFormclick();
    void mainwclick();
};

#endif // MANAGER_H
