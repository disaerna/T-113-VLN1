/********************************************************************************
** Form generated from reading UI file 'addscientist.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDSCIENTIST_H
#define UI_ADDSCIENTIST_H

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
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_addScientist
{
public:
    QLabel *nameText;
    QLabel *genderText;
    QLabel *yobText;
    QLabel *yodText;
    QLabel *yodText_2;
    QLineEdit *nameInput;
    QLineEdit *yobInput;
    QLineEdit *yodInput;
    QPushButton *okButton;
    QPushButton *cancelButton;
    QLabel *label_6;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QRadioButton *maleButton;
    QRadioButton *femaleButton;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout_2;
    QRadioButton *deadButton;
    QRadioButton *aliveButton;

    void setupUi(QDialog *addScientist)
    {
        if (addScientist->objectName().isEmpty())
            addScientist->setObjectName(QStringLiteral("addScientist"));
        addScientist->resize(243, 421);
        addScientist->setToolTipDuration(0);
        nameText = new QLabel(addScientist);
        nameText->setObjectName(QStringLiteral("nameText"));
        nameText->setGeometry(QRect(20, 80, 55, 16));
        nameText->setToolTipDuration(0);
        genderText = new QLabel(addScientist);
        genderText->setObjectName(QStringLiteral("genderText"));
        genderText->setGeometry(QRect(20, 140, 55, 16));
        genderText->setToolTipDuration(0);
        yobText = new QLabel(addScientist);
        yobText->setObjectName(QStringLiteral("yobText"));
        yobText->setGeometry(QRect(20, 200, 81, 16));
        yobText->setToolTipDuration(0);
        yodText = new QLabel(addScientist);
        yodText->setObjectName(QStringLiteral("yodText"));
        yodText->setGeometry(QRect(20, 260, 91, 16));
        yodText->setToolTipDuration(0);
        yodText_2 = new QLabel(addScientist);
        yodText_2->setObjectName(QStringLiteral("yodText_2"));
        yodText_2->setGeometry(QRect(20, 320, 101, 16));
        yodText_2->setToolTipDuration(0);
        nameInput = new QLineEdit(addScientist);
        nameInput->setObjectName(QStringLiteral("nameInput"));
        nameInput->setGeometry(QRect(20, 100, 201, 22));
        nameInput->setToolTipDuration(0);
        yobInput = new QLineEdit(addScientist);
        yobInput->setObjectName(QStringLiteral("yobInput"));
        yobInput->setGeometry(QRect(20, 220, 201, 22));
        yobInput->setToolTipDuration(0);
        yodInput = new QLineEdit(addScientist);
        yodInput->setObjectName(QStringLiteral("yodInput"));
        yodInput->setGeometry(QRect(20, 340, 201, 22));
        yodInput->setToolTipDuration(0);
        okButton = new QPushButton(addScientist);
        okButton->setObjectName(QStringLiteral("okButton"));
        okButton->setGeometry(QRect(20, 380, 93, 28));
        okButton->setToolTipDuration(0);
        cancelButton = new QPushButton(addScientist);
        cancelButton->setObjectName(QStringLiteral("cancelButton"));
        cancelButton->setGeometry(QRect(130, 380, 93, 28));
        cancelButton->setToolTipDuration(0);
        label_6 = new QLabel(addScientist);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(70, 20, 191, 41));
        QFont font;
        font.setPointSize(11);
        font.setBold(true);
        font.setWeight(75);
        label_6->setFont(font);
        label_6->setToolTipDuration(0);
        layoutWidget = new QWidget(addScientist);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(20, 160, 199, 22));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        maleButton = new QRadioButton(layoutWidget);
        maleButton->setObjectName(QStringLiteral("maleButton"));
        maleButton->setToolTipDuration(0);
        maleButton->setChecked(true);

        horizontalLayout->addWidget(maleButton);

        femaleButton = new QRadioButton(layoutWidget);
        femaleButton->setObjectName(QStringLiteral("femaleButton"));
        femaleButton->setToolTipDuration(0);

        horizontalLayout->addWidget(femaleButton);

        layoutWidget1 = new QWidget(addScientist);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(20, 280, 199, 22));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget1);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        deadButton = new QRadioButton(layoutWidget1);
        deadButton->setObjectName(QStringLiteral("deadButton"));
        deadButton->setToolTipDuration(0);
        deadButton->setChecked(true);

        horizontalLayout_2->addWidget(deadButton);

        aliveButton = new QRadioButton(layoutWidget1);
        aliveButton->setObjectName(QStringLiteral("aliveButton"));
        aliveButton->setToolTipDuration(0);
        aliveButton->setChecked(false);

        horizontalLayout_2->addWidget(aliveButton);

        QWidget::setTabOrder(nameInput, maleButton);
        QWidget::setTabOrder(maleButton, femaleButton);
        QWidget::setTabOrder(femaleButton, yobInput);
        QWidget::setTabOrder(yobInput, deadButton);
        QWidget::setTabOrder(deadButton, aliveButton);
        QWidget::setTabOrder(aliveButton, yodInput);
        QWidget::setTabOrder(yodInput, okButton);
        QWidget::setTabOrder(okButton, cancelButton);

        retranslateUi(addScientist);

        QMetaObject::connectSlotsByName(addScientist);
    } // setupUi

    void retranslateUi(QDialog *addScientist)
    {
        addScientist->setWindowTitle(QApplication::translate("addScientist", "Dialog", 0));
        nameText->setText(QApplication::translate("addScientist", "Name: ", 0));
        genderText->setText(QApplication::translate("addScientist", "Gender: ", 0));
        yobText->setText(QApplication::translate("addScientist", "Year of birth:", 0));
        yodText->setText(QApplication::translate("addScientist", "Deceased: ", 0));
        yodText_2->setText(QApplication::translate("addScientist", "Year of death:", 0));
        okButton->setText(QApplication::translate("addScientist", "Submit", 0));
        cancelButton->setText(QApplication::translate("addScientist", "Cancel", 0));
        label_6->setText(QApplication::translate("addScientist", "Add person", 0));
        maleButton->setText(QApplication::translate("addScientist", "Male", 0));
        femaleButton->setText(QApplication::translate("addScientist", "Female", 0));
        deadButton->setText(QApplication::translate("addScientist", "Yes", 0));
        aliveButton->setText(QApplication::translate("addScientist", "No", 0));
    } // retranslateUi

};

namespace Ui {
    class addScientist: public Ui_addScientist {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDSCIENTIST_H
