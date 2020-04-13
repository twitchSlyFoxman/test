
#include "manager.h"

manager::manager()
{
    form = new StartForm;
    form->show();
    QObject::connect(form, SIGNAL(click()), this, SLOT(StartFormclick()));
}
void manager::StartFormclick(){
    mainw = new MainWindow;
    mainw->show();
    QObject::connect(mainw, SIGNAL(click()), this, SLOT(mainwclick()));
    QObject::disconnect(form, SIGNAL(click()), this, SLOT(StartFormclick()));
    delete form;
}
void manager::mainwclick(){
    form = new StartForm;
    form->show();
    QObject::disconnect(mainw, SIGNAL(click()), this, SLOT(mainwclick()));
    QObject::connect(form, SIGNAL(click()), this, SLOT(StartFormclick()));
    delete mainw;
}
