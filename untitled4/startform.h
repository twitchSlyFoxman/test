#ifndef STARTFORM_H
#define STARTFORM_H

#include <QWidget>
#include <QMainWindow>
#include <QtSql>
#include <QApplication>
#include <QTextStream>
#include "QStandardItemModel"
#include "QStandardItem"
#include "connection.h"
#include <QMessageBox>
#include "mainwindow.h"

namespace Ui {
class StartForm;
}

class StartForm : public QWidget
{
    Q_OBJECT

public:
    explicit StartForm(QWidget *parent = nullptr);
    ~StartForm();

private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();

private:
    Ui::StartForm *ui;
    connection DD2;
    QSqlQuery Query;
signals:
    void click();
  // Сигнал для первого окна на открытие
};

#endif // STARTFORM_H
