/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QWidget *formLayoutWidget;
    QFormLayout *formLayout;
    QLabel *nameLabel;
    QLineEdit *nameLineEdit;
    QLabel *weightLabel;
    QLineEdit *weightLineEdit;
    QLabel *heightLabel;
    QLineEdit *heightLineEdit;
    QLabel *abilitiesLabel;
    QLabel *typesLabel;
    QComboBox *comboBox;
    QComboBox *comboBox_2;
    QListWidget *listWidget;
    QPushButton *pushButton;
    QComboBox *comboBox_3;
    QPushButton *pushButton_2;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(613, 479);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        formLayoutWidget = new QWidget(centralWidget);
        formLayoutWidget->setObjectName(QStringLiteral("formLayoutWidget"));
        formLayoutWidget->setGeometry(QRect(29, 240, 251, 171));
        formLayout = new QFormLayout(formLayoutWidget);
        formLayout->setSpacing(6);
        formLayout->setContentsMargins(11, 11, 11, 11);
        formLayout->setObjectName(QStringLiteral("formLayout"));
        formLayout->setContentsMargins(0, 0, 0, 0);
        nameLabel = new QLabel(formLayoutWidget);
        nameLabel->setObjectName(QStringLiteral("nameLabel"));

        formLayout->setWidget(0, QFormLayout::LabelRole, nameLabel);

        nameLineEdit = new QLineEdit(formLayoutWidget);
        nameLineEdit->setObjectName(QStringLiteral("nameLineEdit"));
        nameLineEdit->setEnabled(false);

        formLayout->setWidget(0, QFormLayout::FieldRole, nameLineEdit);

        weightLabel = new QLabel(formLayoutWidget);
        weightLabel->setObjectName(QStringLiteral("weightLabel"));

        formLayout->setWidget(1, QFormLayout::LabelRole, weightLabel);

        weightLineEdit = new QLineEdit(formLayoutWidget);
        weightLineEdit->setObjectName(QStringLiteral("weightLineEdit"));
        weightLineEdit->setEnabled(false);

        formLayout->setWidget(1, QFormLayout::FieldRole, weightLineEdit);

        heightLabel = new QLabel(formLayoutWidget);
        heightLabel->setObjectName(QStringLiteral("heightLabel"));

        formLayout->setWidget(2, QFormLayout::LabelRole, heightLabel);

        heightLineEdit = new QLineEdit(formLayoutWidget);
        heightLineEdit->setObjectName(QStringLiteral("heightLineEdit"));
        heightLineEdit->setEnabled(false);

        formLayout->setWidget(2, QFormLayout::FieldRole, heightLineEdit);

        abilitiesLabel = new QLabel(formLayoutWidget);
        abilitiesLabel->setObjectName(QStringLiteral("abilitiesLabel"));

        formLayout->setWidget(3, QFormLayout::LabelRole, abilitiesLabel);

        typesLabel = new QLabel(formLayoutWidget);
        typesLabel->setObjectName(QStringLiteral("typesLabel"));

        formLayout->setWidget(4, QFormLayout::LabelRole, typesLabel);

        comboBox = new QComboBox(formLayoutWidget);
        comboBox->setObjectName(QStringLiteral("comboBox"));

        formLayout->setWidget(3, QFormLayout::FieldRole, comboBox);

        comboBox_2 = new QComboBox(formLayoutWidget);
        comboBox_2->setObjectName(QStringLiteral("comboBox_2"));

        formLayout->setWidget(4, QFormLayout::FieldRole, comboBox_2);

        listWidget = new QListWidget(centralWidget);
        listWidget->setObjectName(QStringLiteral("listWidget"));
        listWidget->setGeometry(QRect(30, 30, 256, 192));
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(480, 30, 99, 27));
        comboBox_3 = new QComboBox(centralWidget);
        comboBox_3->setObjectName(QStringLiteral("comboBox_3"));
        comboBox_3->setGeometry(QRect(350, 30, 101, 27));
        pushButton_2 = new QPushButton(centralWidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(340, 380, 110, 30));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 613, 25));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        nameLabel->setText(QApplication::translate("MainWindow", "name", 0));
        weightLabel->setText(QApplication::translate("MainWindow", "weight", 0));
        heightLabel->setText(QApplication::translate("MainWindow", "height", 0));
        abilitiesLabel->setText(QApplication::translate("MainWindow", "abilities", 0));
        typesLabel->setText(QApplication::translate("MainWindow", "types", 0));
        pushButton->setText(QApplication::translate("MainWindow", "Filter", 0));
        comboBox_3->clear();
        comboBox_3->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "ALL", 0)
        );
        pushButton_2->setText(QApplication::translate("MainWindow", "EXIT", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
