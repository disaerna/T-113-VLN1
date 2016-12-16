/********************************************************************************
** Form generated from reading UI file 'editcomputer.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EDITCOMPUTER_H
#define UI_EDITCOMPUTER_H

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

class Ui_editComputer
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *editText;
    QLabel *nameText;
    QLineEdit *nameEdit;
    QLabel *buildYearText;
    QLineEdit *buildEdit;
    QLabel *typeText;
    QComboBox *typeSelection;
    QLabel *editNewTypeText;
    QLineEdit *newTypeInput;
    QLabel *successfulText;
    QHBoxLayout *horizontalLayout;
    QRadioButton *yesButton;
    QRadioButton *noButton;
    QSpacerItem *horizontalSpacer;
    QPushButton *submitButton;
    QPushButton *cancelButton;

    void setupUi(QDialog *editComputer)
    {
        if (editComputer->objectName().isEmpty())
            editComputer->setObjectName(QStringLiteral("editComputer"));
        editComputer->resize(375, 452);
        editComputer->setMinimumSize(QSize(375, 452));
        editComputer->setToolTipDuration(0);
        verticalLayout = new QVBoxLayout(editComputer);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        editText = new QLabel(editComputer);
        editText->setObjectName(QStringLiteral("editText"));
        QFont font;
        font.setPointSize(12);
        font.setBold(true);
        font.setWeight(75);
        editText->setFont(font);
        editText->setToolTipDuration(0);

        verticalLayout->addWidget(editText, 0, Qt::AlignHCenter);

        nameText = new QLabel(editComputer);
        nameText->setObjectName(QStringLiteral("nameText"));
        nameText->setToolTipDuration(0);

        verticalLayout->addWidget(nameText);

        nameEdit = new QLineEdit(editComputer);
        nameEdit->setObjectName(QStringLiteral("nameEdit"));
        nameEdit->setToolTipDuration(0);

        verticalLayout->addWidget(nameEdit);

        buildYearText = new QLabel(editComputer);
        buildYearText->setObjectName(QStringLiteral("buildYearText"));
        buildYearText->setToolTipDuration(0);

        verticalLayout->addWidget(buildYearText);

        buildEdit = new QLineEdit(editComputer);
        buildEdit->setObjectName(QStringLiteral("buildEdit"));
        buildEdit->setToolTipDuration(0);

        verticalLayout->addWidget(buildEdit);

        typeText = new QLabel(editComputer);
        typeText->setObjectName(QStringLiteral("typeText"));
        typeText->setToolTipDuration(0);

        verticalLayout->addWidget(typeText);

        typeSelection = new QComboBox(editComputer);
        typeSelection->setObjectName(QStringLiteral("typeSelection"));
        typeSelection->setToolTipDuration(0);

        verticalLayout->addWidget(typeSelection);

        editNewTypeText = new QLabel(editComputer);
        editNewTypeText->setObjectName(QStringLiteral("editNewTypeText"));
        editNewTypeText->setToolTipDuration(0);

        verticalLayout->addWidget(editNewTypeText);

        newTypeInput = new QLineEdit(editComputer);
        newTypeInput->setObjectName(QStringLiteral("newTypeInput"));
        newTypeInput->setToolTipDuration(0);

        verticalLayout->addWidget(newTypeInput);

        successfulText = new QLabel(editComputer);
        successfulText->setObjectName(QStringLiteral("successfulText"));
        successfulText->setToolTipDuration(0);

        verticalLayout->addWidget(successfulText);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        yesButton = new QRadioButton(editComputer);
        yesButton->setObjectName(QStringLiteral("yesButton"));
        yesButton->setToolTipDuration(0);

        horizontalLayout->addWidget(yesButton);

        noButton = new QRadioButton(editComputer);
        noButton->setObjectName(QStringLiteral("noButton"));
        noButton->setToolTipDuration(0);

        horizontalLayout->addWidget(noButton);


        verticalLayout->addLayout(horizontalLayout);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        verticalLayout->addItem(horizontalSpacer);

        submitButton = new QPushButton(editComputer);
        submitButton->setObjectName(QStringLiteral("submitButton"));
        submitButton->setToolTipDuration(0);

        verticalLayout->addWidget(submitButton);

        cancelButton = new QPushButton(editComputer);
        cancelButton->setObjectName(QStringLiteral("cancelButton"));
        cancelButton->setToolTipDuration(0);

        verticalLayout->addWidget(cancelButton);

        QWidget::setTabOrder(nameEdit, buildEdit);
        QWidget::setTabOrder(buildEdit, typeSelection);
        QWidget::setTabOrder(typeSelection, newTypeInput);
        QWidget::setTabOrder(newTypeInput, yesButton);
        QWidget::setTabOrder(yesButton, noButton);
        QWidget::setTabOrder(noButton, submitButton);
        QWidget::setTabOrder(submitButton, cancelButton);

        retranslateUi(editComputer);

        QMetaObject::connectSlotsByName(editComputer);
    } // setupUi

    void retranslateUi(QDialog *editComputer)
    {
        editComputer->setWindowTitle(QApplication::translate("editComputer", "Dialog", 0));
        editText->setText(QApplication::translate("editComputer", "Edit computer", 0));
        nameText->setText(QApplication::translate("editComputer", "Name:", 0));
        nameEdit->setText(QString());
        buildYearText->setText(QApplication::translate("editComputer", "Build Year:", 0));
        typeText->setText(QApplication::translate("editComputer", "Type:", 0));
        editNewTypeText->setText(QApplication::translate("editComputer", "New type: ", 0));
        successfulText->setText(QApplication::translate("editComputer", "Successful:", 0));
        yesButton->setText(QApplication::translate("editComputer", "Yes", 0));
        noButton->setText(QApplication::translate("editComputer", "No", 0));
        submitButton->setText(QApplication::translate("editComputer", "Submit", 0));
        cancelButton->setText(QApplication::translate("editComputer", "Cancel", 0));
    } // retranslateUi

};

namespace Ui {
    class editComputer: public Ui_editComputer {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EDITCOMPUTER_H
