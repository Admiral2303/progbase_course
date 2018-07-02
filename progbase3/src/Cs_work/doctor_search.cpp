#include "doctor_search.h"
#include "ui_doctor_search.h"
#include <QDesktopWidget>

Doctor_search::Doctor_search(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Doctor_search)
{
    ui->setupUi(this);
    QDesktopWidget desktop;
    QRect rect = desktop.availableGeometry(desktop.primaryScreen());
    QPoint center = rect.center();
    int x = center.x() - (this->width()/2);
    int y = center.y() - (this->height()/2);
    center.setX(x);
    center.setY(y);
    this->move(center);

}

Doctor_search::~Doctor_search()
{
    delete ui;
}
