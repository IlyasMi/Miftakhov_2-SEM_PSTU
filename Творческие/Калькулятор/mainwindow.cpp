#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QString>
#include<QPushButton>
#include <QMessageBox>
#include<QPixmap>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    ui->setupUi(this);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_Calculate_clicked()
{
   QString tmp;
   double Stavka,Sum,Months;double Pay_Months;
   tmp=ui->Stavka->text(); Stavka=tmp.toDouble();
   tmp=ui->Sum->text();Sum=tmp.toDouble();
   tmp=ui->Months->text();Months=tmp.toDouble();
   Stavka=(Stavka/100)+1;
   Pay_Months=((Sum*Stavka)/(Months));

   QString new_Pay;
   new_Pay.setNum(Pay_Months);

   ui->Pay->setText(new_Pay);
}





void MainWindow::on_Delete_all_clicked()
{
    ui->Sum->clear();
    ui->Months->clear();
    ui->Stavka->clear();
    ui->Pay->clear();
}







void MainWindow::on_plata_clicked()
{
   ui->label_SUM->setText("Сумма кредита(руб): ");
   ui->label_ST->setText("Годовая ставка(%)");
   ui->label_SROK->setText("На какой срок(мес): ");
   ui->label_ITOG->setText("Ежемесячный платеж: ");
}


void MainWindow::on_stavvvka_clicked()
{
    ui->label_SUM->setText("Сумма кредита(руб): ");
    ui->label_ST->setText("Ежемесячный платеж: ");
    ui->label_SROK->setText("На какой срок(мес): ");
    ui->label_ITOG->setText("Годовая ставка(%)");
}


void MainWindow::on_Calculate_2_clicked()
{
    QMessageBox::information(this,"Всплывающее окно", "Пасхалка найдена!");
}


void MainWindow::on_Summa_clicked()
{
    ui->label_SUM->setText("Ежемесячный платеж:");
    ui->label_ST->setText("Годовая ставка(%)");
    ui->label_SROK->setText("На какой срок(мес): ");
    ui->label_ITOG->setText("Сумма кредита(руб):");
}


void MainWindow::on_Srok_clicked()
{
    ui->label_SUM->setText("Сумма кредита(руб): ");
    ui->label_ST->setText("Годовая ставка(%)");
    ui->label_SROK->setText("Ежемесячный платеж: ");
    ui->label_ITOG->setText("На какой срок(мес): ");
}


void MainWindow::on_Calculate_ST_clicked()
{
    QString tmp;
    double Stavka,Sum,Months, Pay_Months;
    tmp=ui->Stavka->text(); Stavka=tmp.toDouble();
    tmp=ui->Sum->text();Sum=tmp.toDouble();
    tmp=ui->Months->text();Months=tmp.toDouble();

    Pay_Months=(((Stavka*Months)/Sum)-1)*100;
    QString new_Pay;
    new_Pay.setNum(Pay_Months);

    ui->Pay->setText(new_Pay);
}


void MainWindow::on_Calculate_SUM_2_clicked()
{
    QString tmp;
    double Sum,Months, Pay_Months;
    tmp=ui->Sum->text();Sum=tmp.toDouble();
    tmp=ui->Months->text();Months=tmp.toDouble();
    Pay_Months=Sum*Months;
    QString new_Pay;
    new_Pay.setNum(Pay_Months);

    ui->Pay->setText(new_Pay);
}


void MainWindow::on_Calculate_srok_clicked()
{
    QString tmp;
    double Stavka,Sum,Months, Pay_Months;
    tmp=ui->Stavka->text(); Stavka=tmp.toDouble();
    tmp=ui->Sum->text();Sum=tmp.toDouble();
    tmp=ui->Months->text();Months=tmp.toDouble();

    Stavka=(Stavka)/100;
    Pay_Months=((Stavka*Sum)+Sum)/Months;

    QString new_Pay;
    new_Pay.setNum(Pay_Months);

    ui->Pay->setText(new_Pay);
}

