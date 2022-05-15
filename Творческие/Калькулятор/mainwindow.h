#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_Calculate_clicked();

    void on_Delete_all_clicked();

    void on_Calculate_2_clicked();

    void on_plata_clicked();

    void on_stavvvka_clicked();

    void on_Summa_clicked();

    void on_Srok_clicked();

    void on_Calculate_ST_clicked();

    void on_Calculate_SUM_2_clicked();

    void on_Calculate_srok_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
