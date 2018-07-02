#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "profecional.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();


private slots:
    void on_pushButton_clicked();



    void on_listWidget_itemSelectionChanged();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();



    void on_pushButton_4_clicked();
    void closeEvent (QCloseEvent *event);



    void on_actionfind_triggered();

private:
    Ui::MainWindow *ui;
    vector<profecional*> prof;
    int count = 0;

};

#endif // MAINWINDOW_H
