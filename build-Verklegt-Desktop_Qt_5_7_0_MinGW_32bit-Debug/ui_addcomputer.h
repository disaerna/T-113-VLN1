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
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_addComputer
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLabel *nameText;
    QLineEdit *nameInput;
    QLabel *yobText;
    QLineEdit *yobInput;
    QLabel *typeText;
    QComboBox *typeDropDown;
    QLabel *addNewTypeText;
    QLineEdit *newTypeInput;
    QLabel *successfulText;
    QHBoxLayout *horizontalLayout;
    QRadioButton *yesButton;
    QRadioButton *noButton;
    QSpacerItem *horizontalSpacer;
    QPushButton *submitButton;
    QPushButton *cancelButton;

    void setupUi(QDialog *addComputer)
    {
        if (addComputer->objectName().isEmpty())
            addComputer->setObjectName(QStringLiteral("addComputer"));
        addComputer->resize(271, 451);
        addComputer->setMinimumSize(QSize(271, 451));
        addComputer->setToolTipDuration(0);
        verticalLayout = new QVBoxLayout(addComputer);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label = new QLabel(addComputer);
        label->setObjectName(QStringLiteral("label"));
        QFont font;
        font.setPointSize(11);
        font.setBold(true);
        font.setWeight(75);
        label->setFont(font);
        label->setToolTipDuration(0);

        verticalLayout->addWidget(label, 0, Qt::AlignHCenter);

        nameText = new QLabel(addComputer);
        nameText->setObjectName(QStringLiteral("nameText"));
        nameText->setToolTipDuration(0);

        verticalLayout->addWidget(nameText);

        nameInput = new QLineEdit(addComputer);
        nameInput->setObjectName(QStringLiteral("nameInput"));
        nameInput->setToolTipDuration(0);

        verticalLayout->addWidget(nameInput);

        yobText = new QLabel(addComputer);
        yobText->setObjectName(QStringLiteral("yobText"));
        yobText->setToolTipDuration(0);

        verticalLayout->addWidget(yobText);

        yobInput = new QLineEdit(addComputer);
        yobInput->setObjectName(QStringLiteral("yobInput"));
        yobInput->setToolTipDuration(0);

        verticalLayout->addWidget(yobInput);

        typeText = new QLabel(addComputer);
        typeText->setObjectName(QStringLiteral("typeText"));
        typeText->setToolTipDuration(0);

        verticalLayout->addWidget(typeText);

        typeDropDown = new QComboBox(addComputer);
        typeDropDown->setObjectName(QStringLiteral("typeDropDown"));
        typeDropDown->setToolTipDuration(0);

        verticalLayout->addWidget(typeDropDown);

        addNewTypeText = new QLabel(addComputer);
        addNewTypeText->setObjectName(QStringLiteral("addNewTypeText"));
        addNewTypeText->setToolTipDuration(0);

        verticalLayout->addWidget(addNewTypeText);

        newTypeInput = new QLineEdit(addComputer);
        newTypeInput->setObjectName(QStringLiteral("newTypeInput"));
        newTypeInput->setToolTipDuration(0);

        verticalLayout->addWidget(newTypeInput);

        successfulText = new QLabel(addComputer);
        successfulText->setObjectName(QStringLiteral("successfulText"));
        successfulText->setToolTipDuration(0);

        verticalLayout->addWidget(successfulText);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        yesButton = new QRadioButton(addComputer);
        yesButton->setObjectName(QStringLiteral("yesButton"));
        yesButton->setToolTipDuration(0);

        horizontalLayout->addWidget(yesButton);

        noButton = new QRadioButton(addComputer);
        noButton->setObjectName(QStringLiteral("noButton"));
        noButton->setToolTipDuration(0);

        horizontalLayout->addWidget(noButton);


        verticalLayout->addLayout(horizontalLayout);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        verticalLayout->addItem(horizontalSpacer);

        submitButton = new QPushButton(addComputer);
        submitButton->setObjectName(QStringLiteral("submitButton"));
        submitButton->setToolTipDuration(0);

        verticalLayout->addWidget(submitButton);

        cancelButton = new QPushButton(addComputer);
        cancelButton->setObjectName(QStringLiteral("cancelButton"));
        cancelButton->setToolTipDuration(0);

        verticalLayout->addWidget(cancelButton);

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
        yobText->setText(QApplication::translate("addComputer", "Year when first built:", 0));
        typeText->setText(QApplication::translate("addComputer", "Type:", 0));
        addNewTypeText->setText(QApplication::translate("addComputer", "Add a new type: ", 0));
        successfulText->setText(QApplication::translate("addComputer", "Was the build successful ?", 0));
        yesButton->setText(QApplication::translate("addComputer", "Yes", 0));
        noButton->setText(QApplication::translate("addComputer", "No", 0));
        submitButton->setText(QApplication::translate("addComputer", "Submit", 0));
        cancelButton->setText(QApplication::translate("addComputer", "Cancel", 0));
    } // retranslateUi

};

namespace Ui {
    class addComputer: public Ui_addComputer {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDCOMPUTER_H
