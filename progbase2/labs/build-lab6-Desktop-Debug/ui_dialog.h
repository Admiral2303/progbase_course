/********************************************************************************
** Form generated from reading UI file 'dialog.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_H
#define UI_DIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Dialog
{
public:
    QDialogButtonBox *buttonBox;
    QWidget *formLayoutWidget;
    QFormLayout *formLayout;
    QLabel *profnameLabel;
    QLineEdit *profnameLineEdit;
    QLabel *salaryLabel;
    QLabel *scoreLabel;
    QLabel *nameLabel;
    QLineEdit *nameLineEdit;
    QLabel *surnameLabel;
    QLineEdit *surnameLineEdit;
    QLabel *yearLabel;
    QSpinBox *spinBox;
    QDoubleSpinBox *doubleSpinBox;
    QSpinBox *spinBox_2;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName(QStringLiteral("Dialog"));
        Dialog->resize(400, 300);
        buttonBox = new QDialogButtonBox(Dialog);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(-90, 260, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        formLayoutWidget = new QWidget(Dialog);
        formLayoutWidget->setObjectName(QStringLiteral("formLayoutWidget"));
        formLayoutWidget->setGeometry(QRect(79, 70, 191, 191));
        formLayout = new QFormLayout(formLayoutWidget);
        formLayout->setObjectName(QStringLiteral("formLayout"));
        formLayout->setContentsMargins(0, 0, 0, 0);
        profnameLabel = new QLabel(formLayoutWidget);
        profnameLabel->setObjectName(QStringLiteral("profnameLabel"));

        formLayout->setWidget(0, QFormLayout::LabelRole, profnameLabel);

        profnameLineEdit = new QLineEdit(formLayoutWidget);
        profnameLineEdit->setObjectName(QStringLiteral("profnameLineEdit"));

        formLayout->setWidget(0, QFormLayout::FieldRole, profnameLineEdit);

        salaryLabel = new QLabel(formLayoutWidget);
        salaryLabel->setObjectName(QStringLiteral("salaryLabel"));

        formLayout->setWidget(1, QFormLayout::LabelRole, salaryLabel);

        scoreLabel = new QLabel(formLayoutWidget);
        scoreLabel->setObjectName(QStringLiteral("scoreLabel"));

        formLayout->setWidget(2, QFormLayout::LabelRole, scoreLabel);

        nameLabel = new QLabel(formLayoutWidget);
        nameLabel->setObjectName(QStringLiteral("nameLabel"));

        formLayout->setWidget(3, QFormLayout::LabelRole, nameLabel);

        nameLineEdit = new QLineEdit(formLayoutWidget);
        nameLineEdit->setObjectName(QStringLiteral("nameLineEdit"));

        formLayout->setWidget(3, QFormLayout::FieldRole, nameLineEdit);

        surnameLabel = new QLabel(formLayoutWidget);
        surnameLabel->setObjectName(QStringLiteral("surnameLabel"));

        formLayout->setWidget(4, QFormLayout::LabelRole, surnameLabel);

        surnameLineEdit = new QLineEdit(formLayoutWidget);
        surnameLineEdit->setObjectName(QStringLiteral("surnameLineEdit"));

        formLayout->setWidget(4, QFormLayout::FieldRole, surnameLineEdit);

        yearLabel = new QLabel(formLayoutWidget);
        yearLabel->setObjectName(QStringLiteral("yearLabel"));

        formLayout->setWidget(5, QFormLayout::LabelRole, yearLabel);

        spinBox = new QSpinBox(formLayoutWidget);
        spinBox->setObjectName(QStringLiteral("spinBox"));
        spinBox->setMaximum(10000);

        formLayout->setWidget(1, QFormLayout::FieldRole, spinBox);

        doubleSpinBox = new QDoubleSpinBox(formLayoutWidget);
        doubleSpinBox->setObjectName(QStringLiteral("doubleSpinBox"));
        doubleSpinBox->setMaximum(10);

        formLayout->setWidget(2, QFormLayout::FieldRole, doubleSpinBox);

        spinBox_2 = new QSpinBox(formLayoutWidget);
        spinBox_2->setObjectName(QStringLiteral("spinBox_2"));
        spinBox_2->setMaximum(2017);

        formLayout->setWidget(5, QFormLayout::FieldRole, spinBox_2);


        retranslateUi(Dialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), Dialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), Dialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QApplication::translate("Dialog", "Dialog", 0));
        profnameLabel->setText(QApplication::translate("Dialog", "profname", 0));
        salaryLabel->setText(QApplication::translate("Dialog", "salary", 0));
        scoreLabel->setText(QApplication::translate("Dialog", "score", 0));
        nameLabel->setText(QApplication::translate("Dialog", "name", 0));
        surnameLabel->setText(QApplication::translate("Dialog", "surname", 0));
        yearLabel->setText(QApplication::translate("Dialog", "year", 0));
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_H
