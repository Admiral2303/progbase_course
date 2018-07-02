#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "doctor.h"
#include "maindoctor.h"
#include <QHideEvent>
#include <QTimer>
#include <QTime>
#include "patient.h"
#include "conection.h"
#include <QPushButton>
#include <QBrush>
#include <QDesktopWidget>
#include "help.h"
#include "smtp.h"
#include "report.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QPixmap pixmap(":/data/index.png");
    ui->label->setPixmap(pixmap);

    QPixmap pixmap1(":/clock/clock1.png");
    QBrush *brush = new QBrush;
    QPalette *palette = new QPalette;
    brush->setTextureImage(QImage(":/firstWindow/background.png"));
    palette->setBrush(QPalette::Window, *brush);
    this->autoFillBackground();
    this->setPalette(*palette);
    QDesktopWidget desktop;
    QRect rect = desktop.availableGeometry(desktop.primaryScreen());
    QPoint center = rect.center();
    int x = center.x() - (this->width()/2);
    int y = center.y() - (this->height()/2);
    center.setX(x);
    center.setY(y);
    this->move(center);


}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_pushButton_clicked()
{
    this->hide();
    maindoctor *frm = new maindoctor();
    frm->reload_table();
    frm->show();
}

void MainWindow::on_pushButton_2_clicked()
{
    this->hide();
    conection* frm = new conection();

    frm->set_name("Doctor");
    frm->set_regist(false);
    frm->show();
}



void MainWindow::on_pushButton_3_clicked()
{
        this->hide();
        conection *frm = new conection();
        frm->set_name("Patient");
        frm->set_regist(true);
        frm->show();
}



void MainWindow::on_pushButton_4_clicked()
{
    Help frm;
    if(frm.exec()){
        char email[] = "admiral230399@gmail.com";
        char password[] = "Vadim2303";

        QString report = help_report(frm.get_name() , frm.get_surname(), frm.get_report());
        Smtp * smtp = new Smtp(email, password, "smtp.gmail.com");

        smtp->sendMail(email, "vadimv41@gmail.com" , "Допомога",report);
    }
}
