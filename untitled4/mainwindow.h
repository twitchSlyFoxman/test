#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtSql>
#include <QApplication>
#include <QTextStream>
#include "QStandardItemModel"
#include "QStandardItem"
#include "connection.h"
#include <QMessageBox>



QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
   explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void dannietablicirol();
    void dannietablicipostavchik();
    void otrisovkamodelpostavshik();
    void otrisovkamodelroli();
    void poiskpotablice(QString arg1);

private slots:
    void on_AddonDB_btn_clicked();
    void on_lineEdit_znacheniepoiska_textEdited(const QString &arg1);
    void on_PoiskSled_btn_clicked();
    void on_spinBox_valueChanged(int arg1);
    void on_Delete_btn_clicked();
    void on_pushButton_2_clicked();
    void on_tabWidget_tabBarClicked(int index);
    void on_AddonDB_btn_rolpolzov_clicked();
    void on_AddonDB_btn_rolpostavchika_clicked();
    void on_Delete_btn_rolpolzovatel_clicked();
    void on_Delete_btn_rolpostavchika_clicked();

private:
    Ui::MainWindow *ui;
    connection DD;
    QStringList Verticalheder;
    QStringList Verticalheder2;
    QStandardItem *item;
    QStandardItem *item2;
    QSqlQuery Query;
    QStandardItemModel *model2 = new QStandardItemModel;
    QStandardItemModel *model = new QStandardItemModel;
    int kr=3, kolatribROL=2, s, s2, strokapoiska=0,stolbecpoiska;
    QString argpoiska="";


public slots:
void  ItemChangeCallback(QStandardItem* item);


signals:
void itemChanged ( QStandardItem * item );
void click();
};
#endif // MAINWINDOW_H
