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
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>

QT_BEGIN_NAMESPACE

class Ui_addScientist
{
public:
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout_2;
    QRadioButton *maleButton;
    QRadioButton *femaleButton;
    QLineEdit *nameInput;
    QLabel *nameText;
    QLabel *genderText;
    QLabel *label_6;
    QLineEdit *yobInput;
    QLabel *yobText;
    QLabel *yodText;
    QLabel *yodText_2;
    QPushButton *cancelButton;
    QLineEdit *yodInput;
    QSpacerItem *horizontalSpacer;
    QPushButton *okButton;
    QHBoxLayout *horizontalLayout;
    QRadioButton *deadButton;
    QRadioButton *aliveButton;
    QButtonGroup *buttonGroup;
    QButtonGroup *buttonGroup_2;

    void setupUi(QDialog *addScientist)
    {
        if (addScientist->objectName().isEmpty())
            addScientist->setObjectName(QStringLiteral("addScientist"));
        addScientist->resize(360, 468);
        addScientist->setMinimumSize(QSize(272, 451));
        addScientist->setToolTipDuration(0);
        gridLayout = new QGridLayout(addScientist);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        maleButton = new QRadioButton(addScientist);
        buttonGroup = new QButtonGroup(addScientist);
        buttonGroup->setObjectName(QStringLiteral("buttonGroup"));
        buttonGroup->addButton(maleButton);
        maleButton->setObjectName(QStringLiteral("maleButton"));
        maleButton->setToolTipDuration(0);
        maleButton->setChecked(true);

        horizontalLayout_2->addWidget(maleButton);

        femaleButton = new QRadioButton(addScientist);
        buttonGroup->addButton(femaleButton);
        femaleButton->setObjectName(QStringLiteral("femaleButton"));
        femaleButton->setToolTipDuration(0);

        horizontalLayout_2->addWidget(femaleButton);


        gridLayout->addLayout(horizontalLayout_2, 4, 0, 1, 1);

        nameInput = new QLineEdit(addScientist);
        nameInput->setObjectName(QStringLiteral("nameInput"));
        nameInput->setToolTipDuration(0);

        gridLayout->addWidget(nameInput, 2, 0, 1, 1);

        nameText = new QLabel(addScientist);
        nameText->setObjectName(QStringLiteral("nameText"));
        nameText->setToolTipDuration(0);

        gridLayout->addWidget(nameText, 1, 0, 1, 1);

        genderText = new QLabel(addScientist);
        genderText->setObjectName(QStringLiteral("genderText"));
        genderText->setToolTipDuration(0);

        gridLayout->addWidget(genderText, 3, 0, 1, 1);

        label_6 = new QLabel(addScientist);
        label_6->setObjectName(QStringLiteral("label_6"));
        QFont font;
        font.setPointSize(11);
        font.setBold(true);
        font.setWeight(75);
        label_6->setFont(font);
        label_6->setToolTipDuration(0);

        gridLayout->addWidget(label_6, 0, 0, 1, 1);

        yobInput = new QLineEdit(addScientist);
        yobInput->setObjectName(QStringLiteral("yobInput"));
        yobInput->setToolTipDuration(0);

        gridLayout->addWidget(yobInput, 6, 0, 1, 1);

        yobText = new QLabel(addScientist);
        yobText->setObjectName(QStringLiteral("yobText"));
        yobText->setToolTipDuration(0);

        gridLayout->addWidget(yobText, 5, 0, 1, 1);

        yodText = new QLabel(addScientist);
        yodText->setObjectName(QStringLiteral("yodText"));
        yodText->setToolTipDuration(0);

        gridLayout->addWidget(yodText, 7, 0, 1, 1);

        yodText_2 = new QLabel(addScientist);
        yodText_2->setObjectName(QStringLiteral("yodText_2"));
        yodText_2->setToolTipDuration(0);

        gridLayout->addWidget(yodText_2, 9, 0, 1, 1);

        cancelButton = new QPushButton(addScientist);
        cancelButton->setObjectName(QStringLiteral("cancelButton"));
        cancelButton->setToolTipDuration(0);

        gridLayout->addWidget(cancelButton, 13, 0, 1, 1);

        yodInput = new QLineEdit(addScientist);
        yodInput->setObjectName(QStringLiteral("yodInput"));
        yodInput->setToolTipDuration(0);

        gridLayout->addWidget(yodInput, 10, 0, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 11, 0, 1, 1);

        okButton = new QPushButton(addScientist);
        okButton->setObjectName(QStringLiteral("okButton"));
        okButton->setToolTipDuration(0);

        gridLayout->addWidget(okButton, 12, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        deadButton = new QRadioButton(addScientist);
        buttonGroup_2 = new QButtonGroup(addScientist);
        buttonGroup_2->setObjectName(QStringLiteral("buttonGroup_2"));
        buttonGroup_2->addButton(deadButton);
        deadButton->setObjectName(QStringLiteral("deadButton"));
        deadButton->setToolTipDuration(0);
        deadButton->setChecked(true);

        horizontalLayout->addWidget(deadButton);

        aliveButton = new QRadioButton(addScientist);
        buttonGroup_2->addButton(aliveButton);
        aliveButton->setObjectName(QStringLiteral("aliveButton"));
        aliveButton->setToolTipDuration(0);
        aliveButton->setChecked(false);

        horizontalLayout->addWidget(aliveButton);


        gridLayout->addLayout(horizontalLayout, 8, 0, 1, 1);

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
        maleButton->setText(QApplication::translate("addScientist", "Male", 0));
        femaleButton->setText(QApplication::translate("addScientist", "Female", 0));
        nameText->setText(QApplication::translate("addScientist", "Name: ", 0));
        genderText->setText(QApplication::translate("addScientist", "Gender: ", 0));
        label_6->setText(QApplication::translate("addScientist", "Add person", 0));
        yobText->setText(QApplication::translate("addScientist", "Year of birth:", 0));
        yodText->setText(QApplication::translate("addScientist", "Deceased: ", 0));
        yodText_2->setText(QApplication::translate("addScientist", "Year of death:", 0));
        cancelButton->setText(QApplication::translate("addScientist", "Cancel", 0));
        okButton->setText(QApplication::translate("addScientist", "Submit", 0));
        deadButton->setText(QApplication::translate("addScientist", "Yes", 0));
        aliveButton->setText(QApplication::translate("addScientist", "No", 0));
    } // retranslateUi

};

namespace Ui {
    class addScientist: public Ui_addScientist {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDSCIENTIST_H
