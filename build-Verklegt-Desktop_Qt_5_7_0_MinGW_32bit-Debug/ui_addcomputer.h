/********************************************************************************
** Form generated from reading UI file 'addcomputer.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDCOMPUTER_H
#define UI_ADDCOMPUTER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_addComputer
{
public:
    QLabel *label;
    QLabel *nameText;
    QLineEdit *nameInput;
    QPushButton *submitButton;
    QPushButton *cancelButton;
    QLabel *yobText;
    QLineEdit *yobInput;
    QLabel *typeText;
    QComboBox *typeDropDown;
    QLineEdit *newTypeInput;
    QLabel *addNewTypeText;
    QLabel *successfulText;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QRadioButton *yesButton;
    QRadioButton *noButton;

    void setupUi(QDialog *addComputer)
    {
        if (addComputer->objectName().isEmpty())
            addComputer->setObjectName(QStringLiteral("addComputer"));
        addComputer->resize(271, 420);
        addComputer->setToolTipDuration(0);
        label = new QLabel(addComputer);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(80, 20, 121, 61));
        QFont font;
        font.setPointSize(11);
        font.setBold(true);
        font.setWeight(75);
        label->setFont(font);
        label->setToolTipDuration(0);
        nameText = new QLabel(addComputer);
        nameText->setObjectName(QStringLiteral("nameText"));
        nameText->setGeometry(QRect(20, 80, 47, 13));
        nameText->setToolTipDuration(0);
        nameInput = new QLineEdit(addComputer);
        nameInput->setObjectName(QStringLiteral("nameInput"));
        nameInput->setGeometry(QRect(20, 100, 231, 20));
        nameInput->setToolTipDuration(0);
        submitButton = new QPushButton(addComputer);
        submitButton->setObjectName(QStringLiteral("submitButton"));
        submitButton->setGeometry(QRect(20, 370, 111, 31));
        submitButton->setToolTipDuration(0);
        cancelButton = new QPushButton(addComputer);
        cancelButton->setObjectName(QStringLiteral("cancelButton"));
        cancelButton->setGeometry(QRect(150, 370, 101, 31));
        cancelButton->setToolTipDuration(0);
        yobText = new QLabel(addComputer);
        yobText->setObjectName(QStringLiteral("yobText"));
        yobText->setGeometry(QRect(20, 140, 111, 16));
        yobText->setToolTipDuration(0);
        yobInput = new QLineEdit(addComputer);
        yobInput->setObjectName(QStringLiteral("yobInput"));
        yobInput->setGeometry(QRect(20, 160, 231, 20));
        yobInput->setToolTipDuration(0);
        typeText = new QLabel(addComputer);
        typeText->setObjectName(QStringLiteral("typeText"));
        typeText->setGeometry(QRect(20, 200, 47, 13));
        typeText->setToolTipDuration(0);
        typeDropDown = new QComboBox(addComputer);
        typeDropDown->setObjectName(QStringLiteral("typeDropDown"));
        typeDropDown->setGeometry(QRect(20, 220, 231, 22));
        typeDropDown->setToolTipDuration(0);
        newTypeInput = new QLineEdit(addComputer);
        newTypeInput->setObjectName(QStringLiteral("newTypeInput"));
        newTypeInput->setGeometry(QRect(20, 270, 231, 20));
        newTypeInput->setToolTipDuration(0);
        addNewTypeText = new QLabel(addComputer);
        addNewTypeText->setObjectName(QStringLiteral("addNewTypeText"));
        addNewTypeText->setGeometry(QRect(20, 250, 91, 16));
        addNewTypeText->setToolTipDuration(0);
        successfulText = new QLabel(addComputer);
        successfulText->setObjectName(QStringLiteral("successfulText"));
        successfulText->setGeometry(QRect(20, 300, 131, 21));
        successfulText->setToolTipDuration(0);
        layoutWidget = new QWidget(addComputer);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(20, 330, 84, 19));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        yesButton = new QRadioButton(layoutWidget);
        yesButton->setObjectName(QStringLiteral("yesButton"));
        yesButton->setToolTipDuration(0);

        horizontalLayout->addWidget(yesButton);

        noButton = new QRadioButton(layoutWidget);
        noButton->setObjectName(QStringLiteral("noButton"));
        noButton->setToolTipDuration(0);

        horizontalLayout->addWidget(noButton);

        QWidget::setTabOrder(nameInput, yobInput);
        QWidget::setTabOrder(yobInput, typeDropDown);
        QWidget::setTabOrder(typeDropDown, newTypeInput);
        QWidget::setTabOrder(newTypeInput, yesButton);
        QWidget::setTabOrder(yesButton, noButton);
        QWidget::setTabOrder(noButton, submitButton);
        QWidget::setTabOrder(submitButton, cancelButton);

        retranslateUi(addComputer);

        QMetaObject::connectSlotsByName(addComputer);
    } // setupUi

    void retranslateUi(QDialog *addComputer)
    {
        addComputer->setWindowTitle(QApplication::translate("addComputer", "Dialog", 0));
        label->setText(QApplication::translate("addComputer", "Add computer", 0));
        nameText->setText(QApplication::translate("addComputer", "Name:", 0));
        submitButton->setText(QApplication::translate("addComputer", "Submit", 0));
        cancelButton->setText(QApplication::translate("addComputer", "Cancel", 0));
        yobText->setText(QApplication::translate("addComputer", "Year when first built:", 0));
        typeText->setText(QApplication::translate("addComputer", "Type:", 0));
        addNewTypeText->setText(QApplication::translate("addComputer", "Add a new type: ", 0));
        successfulText->setText(QApplication::translate("addComputer", "Was the build successful ?", 0));
        yesButton->setText(QApplication::translate("addComputer", "Yes", 0));
        noButton->setText(QApplication::translate("addComputer", "No", 0));
    } // retranslateUi

};

namespace Ui {
    class addComputer: public Ui_addComputer {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDCOMPUTER_H
