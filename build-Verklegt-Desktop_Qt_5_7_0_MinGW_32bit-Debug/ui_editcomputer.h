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
#include <QtWidgets/QListView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_editComputer
{
public:
    QListView *successfulView;
    QLabel *nameText;
    QLabel *buildYearText;
    QLabel *typeText;
    QLineEdit *nameEdit;
    QPushButton *submitButton;
    QPushButton *cancelButton;
    QLabel *editText;
    QLabel *successfulText;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QRadioButton *yesButton;
    QRadioButton *noButton;
    QLineEdit *buildEdit;
    QComboBox *typeSelection;

    void setupUi(QDialog *editComputer)
    {
        if (editComputer->objectName().isEmpty())
            editComputer->setObjectName(QStringLiteral("editComputer"));
        editComputer->resize(375, 300);
        editComputer->setToolTipDuration(0);
        successfulView = new QListView(editComputer);
        successfulView->setObjectName(QStringLiteral("successfulView"));
        successfulView->setGeometry(QRect(20, 40, 331, 191));
        successfulView->setToolTipDuration(0);
        nameText = new QLabel(editComputer);
        nameText->setObjectName(QStringLiteral("nameText"));
        nameText->setGeometry(QRect(40, 60, 55, 21));
        nameText->setToolTipDuration(0);
        buildYearText = new QLabel(editComputer);
        buildYearText->setObjectName(QStringLiteral("buildYearText"));
        buildYearText->setGeometry(QRect(40, 100, 71, 21));
        buildYearText->setToolTipDuration(0);
        typeText = new QLabel(editComputer);
        typeText->setObjectName(QStringLiteral("typeText"));
        typeText->setGeometry(QRect(40, 140, 55, 21));
        typeText->setToolTipDuration(0);
        nameEdit = new QLineEdit(editComputer);
        nameEdit->setObjectName(QStringLiteral("nameEdit"));
        nameEdit->setGeometry(QRect(120, 60, 201, 22));
        nameEdit->setToolTipDuration(0);
        submitButton = new QPushButton(editComputer);
        submitButton->setObjectName(QStringLiteral("submitButton"));
        submitButton->setGeometry(QRect(20, 250, 161, 28));
        submitButton->setToolTipDuration(0);
        cancelButton = new QPushButton(editComputer);
        cancelButton->setObjectName(QStringLiteral("cancelButton"));
        cancelButton->setGeometry(QRect(190, 250, 161, 28));
        cancelButton->setToolTipDuration(0);
        editText = new QLabel(editComputer);
        editText->setObjectName(QStringLiteral("editText"));
        editText->setGeometry(QRect(120, 5, 141, 31));
        QFont font;
        font.setPointSize(12);
        font.setBold(true);
        font.setWeight(75);
        editText->setFont(font);
        editText->setToolTipDuration(0);
        successfulText = new QLabel(editComputer);
        successfulText->setObjectName(QStringLiteral("successfulText"));
        successfulText->setGeometry(QRect(40, 180, 71, 21));
        successfulText->setToolTipDuration(0);
        layoutWidget = new QWidget(editComputer);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(120, 180, 199, 22));
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

        buildEdit = new QLineEdit(editComputer);
        buildEdit->setObjectName(QStringLiteral("buildEdit"));
        buildEdit->setGeometry(QRect(120, 100, 201, 22));
        buildEdit->setToolTipDuration(0);
        typeSelection = new QComboBox(editComputer);
        typeSelection->setObjectName(QStringLiteral("typeSelection"));
        typeSelection->setGeometry(QRect(120, 140, 201, 22));
        typeSelection->setToolTipDuration(0);
        QWidget::setTabOrder(nameEdit, buildEdit);
        QWidget::setTabOrder(buildEdit, typeSelection);
        QWidget::setTabOrder(typeSelection, yesButton);
        QWidget::setTabOrder(yesButton, noButton);
        QWidget::setTabOrder(noButton, submitButton);
        QWidget::setTabOrder(submitButton, cancelButton);
        QWidget::setTabOrder(cancelButton, successfulView);

        retranslateUi(editComputer);

        QMetaObject::connectSlotsByName(editComputer);
    } // setupUi

    void retranslateUi(QDialog *editComputer)
    {
        editComputer->setWindowTitle(QApplication::translate("editComputer", "Dialog", 0));
        nameText->setText(QApplication::translate("editComputer", "Name:", 0));
        buildYearText->setText(QApplication::translate("editComputer", "Build Year:", 0));
        typeText->setText(QApplication::translate("editComputer", "Type:", 0));
        nameEdit->setText(QString());
        submitButton->setText(QApplication::translate("editComputer", "Submit", 0));
        cancelButton->setText(QApplication::translate("editComputer", "Cancel", 0));
        editText->setText(QApplication::translate("editComputer", "Edit computer", 0));
        successfulText->setText(QApplication::translate("editComputer", "Successful:", 0));
        yesButton->setText(QApplication::translate("editComputer", "Yes", 0));
        noButton->setText(QApplication::translate("editComputer", "No", 0));
        typeSelection->clear();
        typeSelection->insertItems(0, QStringList()
         << QApplication::translate("editComputer", "Analog", 0)
         << QApplication::translate("editComputer", "Electronic", 0)
         << QApplication::translate("editComputer", "Mechatronic", 0)
         << QApplication::translate("editComputer", "Micro", 0)
        );
    } // retranslateUi

};

namespace Ui {
    class editComputer: public Ui_editComputer {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EDITCOMPUTER_H
