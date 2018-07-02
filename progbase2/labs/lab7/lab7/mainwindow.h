#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <vector>
#include <QString>
#include "pokemon.h"
#include "tcp_client.h"
#include "jsonconvert.h"
#include <QDebug>
#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    vector<pokemon*> pokemons;
    vector<QString> type;

private slots:
void on_listWidget_itemSelectionChanged();

void on_pushButton_clicked();

void on_pushButton_2_clicked();
void closeEvent (QCloseEvent *event);

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
