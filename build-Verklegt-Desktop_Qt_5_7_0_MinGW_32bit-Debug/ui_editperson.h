/********************************************************************************
** Form generated from reading UI file 'editperson.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EDITPERSON_H
#define UI_EDITPERSON_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_editPerson
{
public:
    QListView *listView;
    QLabel *nameText;
    QLabel *genderText;
    QLabel *dobText;
    QLabel *dodText;
    QLineEdit *nameEdit;
    QLineEdit *dobEdit;
    QLineEdit *dodEdit;
    QPushButton *submitButton;
    QPushButton *cancelButton;
    QLabel *editText;
    QLabel *deceasedText;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QRadioButton *aliveButton;
    QRadioButton *deadButton;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout_2;
    QRadioButton *maleButton;
    QRadioButton *femaleButton;

    void setupUi(QDialog *editPerson)
    {
        if (editPerson->objectName().isEmpty())
            editPerson->setObjectName(QStringLiteral("editPerson"));
        editPerson->resize(375, 321);
        editPerson->setToolTipDuration(0);
        listView = new QListView(editPerson);
        listView->setObjectName(QStringLiteral("listView"));
        listView->setGeometry(QRect(20, 40, 331, 221));
        listView->setToolTipDuration(0);
        nameText = new QLabel(editPerson);
        nameText->setObjectName(QStringLiteral("nameText"));
        nameText->setGeometry(QRect(40, 60, 55, 16));
        nameText->setToolTipDuration(0);
        genderText = new QLabel(editPerson);
        genderText->setObjectName(QStringLiteral("genderText"));
        genderText->setGeometry(QRect(40, 100, 55, 16));
        genderText->setToolTipDuration(0);
        dobText = new QLabel(editPerson);
        dobText->setObjectName(QStringLiteral("dobText"));
        dobText->setGeometry(QRect(40, 140, 55, 16));
        dobText->setToolTipDuration(0);
        dodText = new QLabel(editPerson);
        dodText->setObjectName(QStringLiteral("dodText"));
        dodText->setGeometry(QRect(40, 220, 55, 16));
        dodText->setToolTipDuration(0);
        nameEdit = new QLineEdit(editPerson);
        nameEdit->setObjectName(QStringLiteral("nameEdit"));
        nameEdit->setGeometry(QRect(120, 60, 201, 22));
        nameEdit->setToolTipDuration(0);
        dobEdit = new QLineEdit(editPerson);
        dobEdit->setObjectName(QStringLiteral("dobEdit"));
        dobEdit->setGeometry(QRect(120, 140, 201, 22));
        dobEdit->setToolTipDuration(0);
        dodEdit = new QLineEdit(editPerson);
        dodEdit->setObjectName(QStringLiteral("dodEdit"));
        dodEdit->setGeometry(QRect(120, 220, 201, 22));
        dodEdit->setToolTipDuration(0);
        submitButton = new QPushButton(editPerson);
        submitButton->setObjectName(QStringLiteral("submitButton"));
        submitButton->setGeometry(QRect(20, 280, 161, 28));
        submitButton->setToolTipDuration(0);
        cancelButton = new QPushButton(editPerson);
        cancelButton->setObjectName(QStringLiteral("cancelButton"));
        cancelButton->setGeometry(QRect(190, 280, 161, 28));
        cancelButton->setToolTipDuration(0);
        editText = new QLabel(editPerson);
        editText->setObjectName(QStringLiteral("editText"));
        editText->setGeometry(QRect(130, 5, 121, 31));
        QFont font;
        font.setPointSize(12);
        font.setBold(true);
        font.setWeight(75);
        editText->setFont(font);
        editText->setToolTipDuration(0);
        deceasedText = new QLabel(editPerson);
        deceasedText->setObjectName(QStringLiteral("deceasedText"));
        deceasedText->setGeometry(QRect(40, 180, 61, 16));
        deceasedText->setToolTipDuration(0);
        layoutWidget = new QWidget(editPerson);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(120, 180, 199, 22));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        aliveButton = new QRadioButton(layoutWidget);
        aliveButton->setObjectName(QStringLiteral("aliveButton"));
        aliveButton->setToolTipDuration(0);

        horizontalLayout->addWidget(aliveButton);

        deadButton = new QRadioButton(layoutWidget);
        deadButton->setObjectName(QStringLiteral("deadButton"));
        deadButton->setToolTipDuration(0);

        horizontalLayout->addWidget(deadButton);

        layoutWidget1 = new QWidget(editPerson);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(120, 100, 199, 22));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget1);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        maleButton = new QRadioButton(layoutWidget1);
        maleButton->setObjectName(QStringLiteral("maleButton"));
        maleButton->setToolTipDuration(0);

        horizontalLayout_2->addWidget(maleButton);

        femaleButton = new QRadioButton(layoutWidget1);
        femaleButton->setObjectName(QStringLiteral("femaleButton"));
        femaleButton->setToolTipDuration(0);

        horizontalLayout_2->addWidget(femaleButton);

        QWidget::setTabOrder(nameEdit, maleButton);
        QWidget::setTabOrder(maleButton, femaleButton);
        QWidget::setTabOrder(femaleButton, dobEdit);
        QWidget::setTabOrder(dobEdit, aliveButton);
        QWidget::setTabOrder(aliveButton, deadButton);
        QWidget::setTabOrder(deadButton, dodEdit);
        QWidget::setTabOrder(dodEdit, submitButton);
        QWidget::setTabOrder(submitButton, cancelButton);
        QWidget::setTabOrder(cancelButton, listView);

        retranslateUi(editPerson);

        QMetaObject::connectSlotsByName(editPerson);
    } // setupUi

    void retranslateUi(QDialog *editPerson)
    {
        editPerson->setWindowTitle(QApplication::translate("editPerson", "Dialog", 0));
        nameText->setText(QApplication::translate("editPerson", "Name:", 0));
        genderText->setText(QApplication::translate("editPerson", "Gender: ", 0));
        dobText->setText(QApplication::translate("editPerson", "DOB:", 0));
        dodText->setText(QApplication::translate("editPerson", "DOD:", 0));
        nameEdit->setText(QString());
        submitButton->setText(QApplication::translate("editPerson", "Submit", 0));
        cancelButton->setText(QApplication::translate("editPerson", "Cancel", 0));
        editText->setText(QApplication::translate("editPerson", "Edit person", 0));
        deceasedText->setText(QApplication::translate("editPerson", "Deceased: ", 0));
        aliveButton->setText(QApplication::translate("editPerson", "Yes", 0));
        deadButton->setText(QApplication::translate("editPerson", "No", 0));
        maleButton->setText(QApplication::translate("editPerson", "Male", 0));
        femaleButton->setText(QApplication::translate("editPerson", "Female", 0));
    } // retranslateUi

};

namespace Ui {
    class editPerson: public Ui_editPerson {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EDITPERSON_H
