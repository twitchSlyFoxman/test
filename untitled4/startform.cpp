#include "startform.h"
#include "ui_startform.h"

StartForm::StartForm(QWidget *parent) :
    QWidget(parent),   ui(new Ui::StartForm)
{
    ui->setupUi(this);

}

StartForm::~StartForm()
{
    delete ui;

}


void StartForm::on_pushButton_clicked()
{


    try{

        QString login="",password="";

        if(DD2.qq.open()){
            if(ui->lineEdit_6->text()!=""&&ui->lineEdit_3->text()!="")
            {

                Query.exec("SELECT login FROM public.polzovatel where login='"+ui->lineEdit_6->text()+"'");
                Query.seek(0);
                login+=Query.value(0).toString();
                Query.exec("SELECT pass FROM public.polzovatel where pass='"+ui->lineEdit_3->text()+"' and login='"+ui->lineEdit_6->text()+"'");
                Query.seek(0);
                password+=Query.value(0).toString();
                if(password!=""&&login!=""){
                    DD2.qq.close();
                    emit click();
                }
                else{

                    QMessageBox::information(0, "Information", "<b>Неправильный логин или пароль</b>");
                }

            }

            else{
                QMessageBox::information(0, "Information", "<b>Необходимо заполнить все поля ввода данных!</b>");
            }
        DD2.qq.close();
        }

        else{

            QMessageBox::information(0,  "Information", "bd not open");
        }
    }



    catch(QException ex){

        QMessageBox::information(0, "Information", "<b>Ошибка обработки операции</b>");
    }
}

void StartForm::on_pushButton_2_clicked()
{
    try{

        QString login="",password="";
        int id=0;
        if(DD2.qq.open()){
            if(ui->lineEdit_4->text()!=""&&ui->lineEdit->text()!=""&&ui->lineEdit_2->text()!="")
            {
                if(ui->lineEdit->text()!=ui->lineEdit_2->text())
                    QMessageBox::information(0, "Information","<b>Пароли не совпадают</b>");
                else{

                    Query.exec("SELECT count(*) FROM public.polzovatel");
                    Query.seek(0);
                    id=Query.value(0).toString().toInt();

                    Query.exec("SELECT login FROM public.polzovatel where login='"+ui->lineEdit_4->text()+"'");
                    Query.seek(0);
                    login+=Query.value(0).toString();

                    if(login==""){
                         login+=ui->lineEdit_4->text();password+=ui->lineEdit->text();
                        if(ui->lineEdit_5->text()==""){
                            QMessageBox::information(0, "Information", QString::number(id)+",1,null,"+login+","+password);
                            Query.exec("INSERT INTO public.polzovatel (id,rolpolzov,\"FIO\",login,pass) values ("+QString::number(id)+",1,null,"+login+","+password+")");
}
                        else{
                            QMessageBox::information(0, "Information", QString::number(id)+",1,null,"+login+","+password);
                            Query.exec("INSERT INTO public.polzovatel (id,rolpolzov,\"FIO\",login,pass) values ("+QString::number(id)+",1,"+ui->lineEdit_5->text()+","+login+","+password+")");
                        }
                        QMessageBox::information(0, "Information", "<b>Уcпешная регистрация пользователя</b>");
                        DD2.qq.close();
                        emit click();
                    }

                    else{
                        QMessageBox::information(0, "Information", "<b>Данный логин присутствует в базе данных</b>");
                    }

                }
            }

            else{
                QMessageBox::information(0, "Information", "<b>Необходимо заполнить все поля ввода данных со *!</b>");
            }
        DD2.qq.close();
        }

        else{

            QMessageBox::information(0,  "Information", "bd not open");
        }
    }



    catch(QException ex){

        QMessageBox::information(0, "Information", "<b>Ошибка обработки операции</b>");
    }
}
