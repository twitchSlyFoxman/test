#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

   dannietablicirol();
   otrisovkamodelroli();


    //dannietablicipostavchik();
   // otrisovkamodelpostavshik();
    //connect(model2, SIGNAL(itemChanged(QStandardItem*)), this, SLOT(ItemChangeCallback(QStandardItem*)));
   // disconnect(model2, SIGNAL(itemChanged(QStandardItem*)), this, SLOT(ItemChangeCallback(QStandardItem*)));
  }



MainWindow::~MainWindow()
{
    delete ui;
    delete item;
    delete item2;
    delete model;
    delete model2;
}






void MainWindow::dannietablicirol(){
    model->clear();
    model2->clear();
    Verticalheder.clear();
    Verticalheder2.clear();
    try{
        if(DD.qq.open())
        {
            ui->label_6->setText("bd is open");
            ui->pushButton->setStyleSheet("background-color: rgba(0, 255, 0, 1);");

            Query.exec("SELECT count(*) FROM public.rolepolzovatel");
            Query.seek(0);
            s=Query.value(0).toInt();
            Query.exec("SELECT count(*) FROM public.rolepostavchika");
            Query.seek(0);
            s2=Query.value(0).toInt();

            Query.exec("SELECT * FROM public.rolepolzovatel");
            int i=0;
            while(Query.next()){
                for(int j=0;j<kolatribROL;j++){
                    item = new QStandardItem(QString(Query.value(j).toString()));
                    model->setItem(i, j, item);

                }
                Verticalheder.append(">");
                i++;
            }

            Query.exec("SELECT * FROM public.rolepostavchika");
            i=0;
            while(Query.next()){
                for(int j=0;j<kolatribROL;j++){
                    item2 = new QStandardItem(QString(Query.value(j).toString()));
                    model2->setItem(i, j, item2);

                }
                Verticalheder2.append(">");
                i++;
            }

            DD.qq.close();

        }
        else{
            ui->label_6->setText("bd not open");
            ui->pushButton->setStyleSheet("background-color: rgba(255, 0, 0, 1);");}
    }
    catch(QException ex) {
        QMessageBox::information(0, "Information", "<b>Ошибка обработки операции</b>");
        ui->pushButton->setStyleSheet("background-color: rgba(0, 0, 0, 1);");
    }



}


void MainWindow::otrisovkamodelroli(){

    model->setVerticalHeaderLabels(Verticalheder);
    model->setHeaderData(0, Qt::Horizontal, tr("id"));
    model->setHeaderData(1, Qt::Horizontal, tr("Opisanie"));



    model2->setVerticalHeaderLabels(Verticalheder2);
    model2->setHeaderData(0, Qt::Horizontal, tr("id"));
    model2->setHeaderData(1, Qt::Horizontal, tr("Opisanie"));



    ui-> tableView_rolpolzov-> horizontalHeader () -> setSectionResizeMode (QHeaderView :: Stretch);
   // ui-> tableView_rolpolzov-> verticalHeader () -> setSectionResizeMode (QHeaderView :: Stretch);

    ui-> tableView_rolpostavchika-> horizontalHeader () -> setSectionResizeMode (QHeaderView :: Stretch);
   // ui-> tableView_rolpostavchika-> verticalHeader () -> setSectionResizeMode (QHeaderView :: Stretch);

    ui->tableView_rolpolzov->setModel(model);
    ui->tableView_rolpostavchika->setModel(model2);
    }


void MainWindow::on_AddonDB_btn_rolpolzov_clicked()
{
    try{
        dannietablicirol();

         if(DD.qq.open()){
            if(ui->lineEdit_9->text()!="")
            {
                Query.exec("SELECT count(*) FROM public.rolepolzovatel");
                Query.seek(0);
                s=Query.value(0).toInt();
                QString strokaproverkanapovtor;
                Query.exec("SELECT opisanie FROM public.rolepolzovatel where opisanie="+ui->lineEdit_9->text());
                Query.seek(0);
                strokaproverkanapovtor+=Query.value(0).toString();
                 if(strokaproverkanapovtor!=""){
                    otrisovkamodelroli();
                    QMessageBox::information(0, "Information", "<b>Дублирование роли недопустимо</b>");
                }
                else{
                    Query.exec("INSERT INTO public.rolepolzovatel (id,opisanie) values ("+QString::number(s)+","+ui->lineEdit_9->text()+")");

                    dannietablicirol();

                    ui->lineEdit_9->setText("");// обнуляем поля ввода


                    otrisovkamodelroli();

                    QMessageBox::information(0, "Information", "<b>Успешно добавление новых данных</b>");
                }
            }
            else{

                otrisovkamodelroli();
                QMessageBox::information(0, "Information", "<b>Необходимо заполнить все поля ввода данных!</b>");

            }

            DD.qq.close();
        }
        else{
            ui->label_6->setText("bd not open");
            ui->pushButton->setStyleSheet("background-color: rgba(255, 0, 0, 1);");}


    }
    catch(QException ex) {
        QMessageBox::information(0, "Information", "<b>Ошибка обработки операции</b>");
        ui->pushButton->setStyleSheet("background-color: rgba(0, 0, 0, 1);");

    }
}






void MainWindow::on_AddonDB_btn_rolpostavchika_clicked()
{
    try{
        dannietablicirol();

         if(DD.qq.open()){
            if(ui->lineEdit_11->text()!="")
            {
                Query.exec("SELECT count(*) FROM public.rolepostavchika");
                Query.seek(0);
                s=Query.value(0).toInt();
                QString strokaproverkanapovtor;
                Query.exec("SELECT opisanie FROM public.rolepostavchika where opisanie="+ui->lineEdit_11->text());
                Query.seek(0);
                strokaproverkanapovtor+=Query.value(0).toString();
                 if(strokaproverkanapovtor!=""){
                    otrisovkamodelroli();
                    QMessageBox::information(0, "Information", "<b>Дублирование роли недопустимо</b>");
                }
                else{
                    Query.exec("INSERT INTO public.rolepostavchika (id,opisanie) values ("+QString::number(s)+","+ui->lineEdit_11->text()+")");

                    dannietablicirol();

                    ui->lineEdit_11->setText("");// обнуляем поля ввода


                    otrisovkamodelroli();

                    QMessageBox::information(0, "Information", "<b>Успешно добавление новых данных</b>");
                }
            }
            else{

                otrisovkamodelroli();
                QMessageBox::information(0, "Information", "<b>Необходимо заполнить все поля ввода данных!</b>");

            }

            DD.qq.close();
        }
        else{
            ui->label_6->setText("bd not open");
            ui->pushButton->setStyleSheet("background-color: rgba(255, 0, 0, 1);");}


    }
    catch(QException ex) {
        QMessageBox::information(0, "Information", "<b>Ошибка обработки операции</b>");
        ui->pushButton->setStyleSheet("background-color: rgba(0, 0, 0, 1);");

    }
}





void MainWindow::on_Delete_btn_rolpolzovatel_clicked()
{
    try{
           if(DD.qq.open()){
            QItemSelectionModel *selectModel = ui->tableView_rolpolzov->selectionModel();
            if (!selectModel->hasSelection())
            {
                QMessageBox::information(0, "Information",  "Необходимо выделить строку для удаления");
            }
            else {
                Query.exec("DELETE FROM public.rolepolzovatel where id="+model->item(selectModel->selectedRows().first().row(),0)->text());
                dannietablicirol();
                otrisovkamodelroli();
                QMessageBox::information(0, "Information", "<b>Успешно удаление выделенных данных</b>");
            }

            DD.qq.close();
        }
        else{
            ui->label_6->setText("bd not open");
            ui->pushButton->setStyleSheet("background-color: rgba(255, 0, 0, 1);");}
          }
    catch(QException ex) {
        QMessageBox::information(0, "Information", "<b>Ошибка обработки операции</b>");
        ui->pushButton->setStyleSheet("background-color: rgba(0, 0, 0, 1);");
    }
}

void MainWindow::on_Delete_btn_rolpostavchika_clicked()
{
    try{
        if(DD.qq.open()){
         QItemSelectionModel *selectModel = ui->tableView_rolpostavchika->selectionModel();
         if (!selectModel->hasSelection())
         {
             QMessageBox::information(0, "Information",  "Необходимо выделить строку для удаления");
         }
         else {
             Query.exec("DELETE FROM public.rolepostavchika where id="+model2->item(selectModel->selectedRows().first().row(),0)->text());
             dannietablicirol();
             otrisovkamodelroli();
             QMessageBox::information(0, "Information", "<b>Успешно удаление выделенных данных</b>");
         }

         DD.qq.close();
     }
     else{
         ui->label_6->setText("bd not open");
         ui->pushButton->setStyleSheet("background-color: rgba(255, 0, 0, 1);");}
       }
 catch(QException ex) {
     QMessageBox::information(0, "Information", "<b>Ошибка обработки операции</b>");
     ui->pushButton->setStyleSheet("background-color: rgba(0, 0, 0, 1);");
 }

}



void MainWindow::dannietablicipostavchik(){

    model->clear();
    Verticalheder.clear();


    try{
        if(DD.qq.open())
        {
            ui->label_6->setText("bd is open");
            ui->pushButton->setStyleSheet("background-color: rgba(0, 255, 0, 1);");

            Query.exec("SELECT count(*) FROM public.postavshiki");
            Query.seek(0);
            s=Query.value(0).toInt();


            //            QSqlQueryModel *model = new QSqlQueryModel;
            //            model->setQuery("SELECT * FROM public.postavshiki");
            //            ui->tableView->setModel(model);
            //            ui->tableView->resizeRowsToContents();
            //            ui->tableView->resizeColumnsToContents();



            Query.exec("SELECT * FROM public.postavshiki");
            int i=0;
            while(Query.next()){
                for(int j=0;j<kr;j++){
                    item = new QStandardItem(QString(Query.value(j).toString()));
                    model->setItem(i, j, item);

                }
                Verticalheder.append(">");
                i++;
            }
            DD.qq.close();

        }
        else{
            ui->label_6->setText("bd not open");
            ui->pushButton->setStyleSheet("background-color: rgba(255, 0, 0, 1);");}
    }
    catch(QException ex) {
        QMessageBox::information(0, "Information", "<b>Ошибка обработки операции</b>");
        ui->pushButton->setStyleSheet("background-color: rgba(0, 0, 0, 1);");
    }
}


void MainWindow::otrisovkamodelpostavshik(){
    model->setVerticalHeaderLabels(Verticalheder);
    model->setHeaderData(0, Qt::Horizontal, tr("id"));
    model->setHeaderData(1, Qt::Horizontal, tr("role"));
    model->setHeaderData(2, Qt::Horizontal, tr("opisanie"));


    ui-> tableView-> horizontalHeader () -> setSectionResizeMode (QHeaderView :: Stretch);
  //  ui-> tableView-> verticalHeader () -> setSectionResizeMode (QHeaderView :: Stretch);
    //        ui->tableView->resizeRowsToContents();
    //        ui->tableView->resizeColumnsToContents();

    ui->tableView->setModel(model);

}







void MainWindow::ItemChangeCallback(QStandardItem* item) {


    try{
        if(item->index().column()==0)
        {
            QMessageBox::information(0, "Information", "<b>Нельзя редактировать первый атрибут</b>");

        }
        else{
            if(DD.qq.open())
            {
                ui->label_6->setText("bd is open");
                ui->pushButton->setStyleSheet("background-color: rgba(0, 255, 0, 1);");

                if(item->index().column()==1){
                Query.exec("UPDATE public.postavshiki SET role='"+item->text()+"' WHERE id="+ model->item((item->index().row()),0)->text());
                }
                else{
                Query.exec("UPDATE public.postavshiki SET opisanie='"+item->text()+"' WHERE id="+ model->item((item->index().row()),0)->text());
                }
                QMessageBox::information(0, "Information", "<b>Данные успешно отредактированы</b>");
                DD.qq.close();
            }
        }
    }
    catch(QException ex) {
        QMessageBox::information(0, "Information", "<b>Ошибка обработки операции</b>");
        item->setBackground(Qt::GlobalColor::red);
    }

}




void MainWindow::on_AddonDB_btn_clicked()
{
    try{
        disconnect(model, SIGNAL(itemChanged(QStandardItem*)), this, SLOT(ItemChangeCallback(QStandardItem*)));
        dannietablicipostavchik();

        //
        if(DD.qq.open()){
            ui->label_6->setText("bd is open");
            ui->pushButton->setStyleSheet("background-color: rgba(0, 255, 0, 1);");

            if(ui->comboBox_Nrole->currentText()!=""&&ui->lineEdit_Nopisanie->text()!="")
            {
                Query.exec("SELECT count(*) FROM public.postavshiki");
                Query.seek(0);
                s=Query.value(0).toInt();

                QString strokaproverkanapovtor="";

                Query.exec("SELECT opisanie FROM public.postavshiki where opisanie='"+ui->lineEdit_Nopisanie->text()+"'");
                Query.seek(0);
                strokaproverkanapovtor+=Query.value(0).toString();

                if(strokaproverkanapovtor!=""){
                    otrisovkamodelpostavshik();
                    QMessageBox::information(0, "Information", "<b>Поле описание должно быть уникально</b>");
                }
                else{
                    Query.exec("INSERT INTO public.postavshiki (id,role,opisanie) values ("+QString::number(s)+","+ui->comboBox_Nrole->currentText()+","+ui->lineEdit_Nopisanie->text()+")");

                    dannietablicipostavchik();

                   // ui->comboBox_Nrole->currentText();// обнуляем поля ввода
                    ui->lineEdit_Nopisanie->setText("");// обнуляем поля ввода


                    otrisovkamodelpostavshik();
                    QMessageBox::information(0, "Information", "<b>Успешно добавление новых данных</b>");
                }
            }
            else{

                otrisovkamodelpostavshik();
                QMessageBox::information(0, "Information", "<b>Необходимо заполнить все поля ввода данных!</b>");

            }

            DD.qq.close();
        }
        else{
            ui->label_6->setText("bd not open");
            ui->pushButton->setStyleSheet("background-color: rgba(255, 0, 0, 1);");
        }
       connect(model, SIGNAL(itemChanged(QStandardItem*)), this, SLOT(ItemChangeCallback(QStandardItem*)));

    }
    catch(QException ex) {
        QMessageBox::information(0, "Information", "<b>Ошибка обработки операции</b>");
        ui->pushButton->setStyleSheet("background-color: rgba(0, 0, 0, 1);");

    }
}


void MainWindow::poiskpotablice(QString arg1){


    QModelIndex index;
    s=model->rowCount();


    stolbecpoiska = ui->spinBox->text().toInt();
  //  QMessageBox::information(0, "Information", QString::number(s)+QString::number(stolbecpoiska));
    if(strokapoiska==s){
        strokapoiska=0;
        goto metka;
    }
    else if(strokapoiska==0){
metka:
        for(int i=0;i<s;i++, strokapoiska++){

            if(model->item(i,stolbecpoiska)->text()==arg1)
            {
                index=model->index(i,0);
                break;
            }

        }
    }
    else{
        for(int i=strokapoiska;i<s; i++, strokapoiska++){
            if(model->item(i,stolbecpoiska)->text()==arg1)
            {
                index=model->index(i,0);
                break;
            }
        }
        if(!index.isValid())
        {
            strokapoiska=0;
            goto metka;
        }
    }



    if(index.isValid())
    {
        ui->tableView->selectionModel()->select(index,QItemSelectionModel::ClearAndSelect | QItemSelectionModel::Rows);
        ui->tableView->scrollTo(index,QAbstractItemView::PositionAtCenter);
    }
    else{
        index=model->index(0,0);
        ui->tableView->selectionModel()->select(index,QItemSelectionModel::ClearAndSelect | QItemSelectionModel::Rows);
        ui->tableView->scrollTo(index,QAbstractItemView::PositionAtTop);
    }

}

void MainWindow::on_lineEdit_znacheniepoiska_textEdited(const QString &arg1)
{
    argpoiska=arg1;
    poiskpotablice(argpoiska);
}

void MainWindow::on_PoiskSled_btn_clicked()
{
    strokapoiska++;
    if(argpoiska==""){
        QMessageBox::information(0, "Information", "<b>Введите ключ поиска</b>");
    }
    else{
        poiskpotablice(argpoiska);
    }

}

void MainWindow::on_spinBox_valueChanged(int arg1)
{
    stolbecpoiska = arg1;
    poiskpotablice(argpoiska);

}


void MainWindow::on_Delete_btn_clicked()
{

    try{
        disconnect(model, SIGNAL(itemChanged(QStandardItem*)), this, SLOT(ItemChangeCallback(QStandardItem*)));


        if(DD.qq.open()){
            QItemSelectionModel *selectModel = ui->tableView->selectionModel();
            if (!selectModel->hasSelection())
            {
                QMessageBox::information(0, "Information",  "Необходимо выделить строку для удаления");
            }
            else {
                Query.exec("DELETE FROM public.postavshiki where id="+model->item(selectModel->selectedRows().first().row(),0)->text());
                dannietablicipostavchik();
                otrisovkamodelpostavshik();
                QMessageBox::information(0, "Information", "<b>Успешно удаление выделенных данных</b>");
            }

            DD.qq.close();
        }
        else{
            ui->label_6->setText("bd not open");
            ui->pushButton->setStyleSheet("background-color: rgba(255, 0, 0, 1);");
        }
            connect(model, SIGNAL(itemChanged(QStandardItem*)), this, SLOT(ItemChangeCallback(QStandardItem*)));

    }
    catch(QException ex) {
        QMessageBox::information(0, "Information", "<b>Ошибка обработки операции</b>");
        ui->pushButton->setStyleSheet("background-color: rgba(0, 0, 0, 1);");
    }
}




void MainWindow::on_pushButton_2_clicked()
{
     emit click();

}

void MainWindow::on_tabWidget_tabBarClicked(int index)
{
    if(index==0){
        if(connect(model, SIGNAL(itemChanged(QStandardItem*)), this, SLOT(ItemChangeCallback(QStandardItem*))))
      disconnect(model, SIGNAL(itemChanged(QStandardItem*)), this, SLOT(ItemChangeCallback(QStandardItem*)));
      dannietablicirol();
      otrisovkamodelroli();
    }
    else if(index==1){
         dannietablicipostavchik();
         otrisovkamodelpostavshik();
         ui->comboBox_Nrole->clear();


         if(DD.qq.open()){
             Query.exec("SELECT count(*) FROM public.rolepolzovatel");
             Query.seek(0);
             s=Query.value(0).toInt();
             if(s!=0){
             Query.exec("SELECT id FROM public.rolepolzovatel");
             while(Query.next())
            {
               ui->comboBox_Nrole->addItem(Query.value(0).toString());

             }
            }
          }
       DD.qq.close();


         connect(model, SIGNAL(itemChanged(QStandardItem*)), this, SLOT(ItemChangeCallback(QStandardItem*)));
    }


}






