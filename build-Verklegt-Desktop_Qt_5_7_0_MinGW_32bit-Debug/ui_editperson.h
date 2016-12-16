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
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_editPerson
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *editText;
    QLabel *nameText;
    QLineEdit *nameEdit;
    QLabel *genderText;
    QHBoxLayout *horizontalLayout_2;
    QRadioButton *maleButton;
    QRadioButton *femaleButton;
    QLabel *dobText;
    QLineEdit *dobEdit;
    QLabel *deceasedText;
    QHBoxLayout *horizontalLayout;
    QRadioButton *aliveButton;
    QRadioButton *deadButton;
    QLabel *dodText;
    QLineEdit *dodEdit;
    QSpacerItem *horizontalSpacer;
    QPushButton *submitButton;
    QPushButton *cancelButton;
    QButtonGroup *buttonGroup_2;
    QButtonGroup *buttonGroup;

    void setupUi(QDialog *editPerson)
    {
        if (editPerson->objectName().isEmpty())
            editPerson->setObjectName(QStringLiteral("editPerson"));
        editPerson->resize(375, 454);
        editPerson->setMinimumSize(QSize(375, 454));
        editPerson->setToolTipDuration(0);
        verticalLayout = new QVBoxLayout(editPerson);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        editText = new QLabel(editPerson);
        editText->setObjectName(QStringLiteral("editText"));
        QFont font;
        font.setPointSize(12);
        font.setBold(true);
        font.setWeight(75);
        editText->setFont(font);
        editText->setToolTipDuration(0);

        verticalLayout->addWidget(editText, 0, Qt::AlignHCenter);

        nameText = new QLabel(editPerson);
        nameText->setObjectName(QStringLiteral("nameText"));
        nameText->setToolTipDuration(0);

        verticalLayout->addWidget(nameText);

        nameEdit = new QLineEdit(editPerson);
        nameEdit->setObjectName(QStringLiteral("nameEdit"));
        nameEdit->setToolTipDuration(0);

        verticalLayout->addWidget(nameEdit);

        genderText = new QLabel(editPerson);
        genderText->setObjectName(QStringLiteral("genderText"));
        genderText->setToolTipDuration(0);

        verticalLayout->addWidget(genderText);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        maleButton = new QRadioButton(editPerson);
        buttonGroup = new QButtonGroup(editPerson);
        buttonGroup->setObjectName(QStringLiteral("buttonGroup"));
        buttonGroup->addButton(maleButton);
        maleButton->setObjectName(QStringLiteral("maleButton"));
        maleButton->setToolTipDuration(0);

        horizontalLayout_2->addWidget(maleButton);

        femaleButton = new QRadioButton(editPerson);
        buttonGroup->addButton(femaleButton);
        femaleButton->setObjectName(QStringLiteral("femaleButton"));
        femaleButton->setToolTipDuration(0);

        horizontalLayout_2->addWidget(femaleButton);


        verticalLayout->addLayout(horizontalLayout_2);

        dobText = new QLabel(editPerson);
        dobText->setObjectName(QStringLiteral("dobText"));
        dobText->setToolTipDuration(0);

        verticalLayout->addWidget(dobText);

        dobEdit = new QLineEdit(editPerson);
        dobEdit->setObjectName(QStringLiteral("dobEdit"));
        dobEdit->setToolTipDuration(0);

        verticalLayout->addWidget(dobEdit);

        deceasedText = new QLabel(editPerson);
        deceasedText->setObjectName(QStringLiteral("deceasedText"));
        deceasedText->setToolTipDuration(0);

        verticalLayout->addWidget(deceasedText);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        aliveButton = new QRadioButton(editPerson);
        buttonGroup_2 = new QButtonGroup(editPerson);
        buttonGroup_2->setObjectName(QStringLiteral("buttonGroup_2"));
        buttonGroup_2->addButton(aliveButton);
        aliveButton->setObjectName(QStringLiteral("aliveButton"));
        aliveButton->setToolTipDuration(0);

        horizontalLayout->addWidget(aliveButton);

        deadButton = new QRadioButton(editPerson);
        buttonGroup_2->addButton(deadButton);
        deadButton->setObjectName(QStringLiteral("deadButton"));
        deadButton->setToolTipDuration(0);

        horizontalLayout->addWidget(deadButton);


        verticalLayout->addLayout(horizontalLayout);

        dodText = new QLabel(editPerson);
        dodText->setObjectName(QStringLiteral("dodText"));
        dodText->setToolTipDuration(0);

        verticalLayout->addWidget(dodText);

        dodEdit = new QLineEdit(editPerson);
        dodEdit->setObjectName(QStringLiteral("dodEdit"));
        dodEdit->setToolTipDuration(0);

        verticalLayout->addWidget(dodEdit);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        verticalLayout->addItem(horizontalSpacer);

        submitButton = new QPushButton(editPerson);
        submitButton->setObjectName(QStringLiteral("submitButton"));
        submitButton->setToolTipDuration(0);

        verticalLayout->addWidget(submitButton);

        cancelButton = new QPushButton(editPerson);
        cancelButton->setObjectName(QStringLiteral("cancelButton"));
        cancelButton->setToolTipDuration(0);

        verticalLayout->addWidget(cancelButton);

        QWidget::setTabOrder(nameEdit, maleButton);
        QWidget::setTabOrder(maleButton, femaleButton);
        QWidget::setTabOrder(femaleButton, dobEdit);
        QWidget::setTabOrder(dobEdit, aliveButton);
        QWidget::setTabOrder(aliveButton, deadButton);
        QWidget::setTabOrder(deadButton, dodEdit);
        QWidget::setTabOrder(dodEdit, submitButton);
        QWidget::setTabOrder(submitButton, cancelButton);

        retranslateUi(editPerson);

        QMetaObject::connectSlotsByName(editPerson);
    } // setupUi

    void retranslateUi(QDialog *editPerson)
    {
        editPerson->setWindowTitle(QApplication::translate("editPerson", "Dialog", 0));
        editText->setText(QApplication::translate("editPerson", "Edit person", 0));
        nameText->setText(QApplication::translate("editPerson", "Name:", 0));
        nameEdit->setText(QString());
        genderText->setText(QApplication::translate("editPerson", "Gender: ", 0));
        maleButton->setText(QApplication::translate("editPerson", "Male", 0));
        femaleButton->setText(QApplication::translate("editPerson", "Female", 0));
        dobText->setText(QApplication::translate("editPerson", "Year of birth:", 0));
        deceasedText->setText(QApplication::translate("editPerson", "Deceased: ", 0));
        aliveButton->setText(QApplication::translate("editPerson", "Yes", 0));
        deadButton->setText(QApplication::translate("editPerson", "No", 0));
        dodText->setText(QApplication::translate("editPerson", "Year of death:", 0));
        submitButton->setText(QApplication::translate("editPerson", "Submit", 0));
        cancelButton->setText(QApplication::translate("editPerson", "Cancel", 0));
    } // retranslateUi

};

namespace Ui {
    class editPerson: public Ui_editPerson {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EDITPERSON_H
