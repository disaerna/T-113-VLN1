/********************************************************************************
** Form generated from reading UI file 'addrelations.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDRELATIONS_H
#define UI_ADDRELATIONS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_addRelations
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *label_addRelationsTitle;
    QLabel *label_chooseScientist;
    QComboBox *comboBox_scientist;
    QLabel *label_chooseComputer;
    QComboBox *comboBox_computer;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton_submit;
    QPushButton *pushButton_cancel;

    void setupUi(QDialog *addRelations)
    {
        if (addRelations->objectName().isEmpty())
            addRelations->setObjectName(QStringLiteral("addRelations"));
        addRelations->resize(374, 328);
        verticalLayout = new QVBoxLayout(addRelations);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label_addRelationsTitle = new QLabel(addRelations);
        label_addRelationsTitle->setObjectName(QStringLiteral("label_addRelationsTitle"));
        QFont font;
        font.setPointSize(11);
        font.setBold(true);
        font.setWeight(75);
        label_addRelationsTitle->setFont(font);

        verticalLayout->addWidget(label_addRelationsTitle);

        label_chooseScientist = new QLabel(addRelations);
        label_chooseScientist->setObjectName(QStringLiteral("label_chooseScientist"));

        verticalLayout->addWidget(label_chooseScientist);

        comboBox_scientist = new QComboBox(addRelations);
        comboBox_scientist->setObjectName(QStringLiteral("comboBox_scientist"));

        verticalLayout->addWidget(comboBox_scientist);

        label_chooseComputer = new QLabel(addRelations);
        label_chooseComputer->setObjectName(QStringLiteral("label_chooseComputer"));

        verticalLayout->addWidget(label_chooseComputer);

        comboBox_computer = new QComboBox(addRelations);
        comboBox_computer->setObjectName(QStringLiteral("comboBox_computer"));

        verticalLayout->addWidget(comboBox_computer);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        verticalLayout->addItem(horizontalSpacer);

        pushButton_submit = new QPushButton(addRelations);
        pushButton_submit->setObjectName(QStringLiteral("pushButton_submit"));

        verticalLayout->addWidget(pushButton_submit);

        pushButton_cancel = new QPushButton(addRelations);
        pushButton_cancel->setObjectName(QStringLiteral("pushButton_cancel"));

        verticalLayout->addWidget(pushButton_cancel);

        QWidget::setTabOrder(comboBox_scientist, comboBox_computer);
        QWidget::setTabOrder(comboBox_computer, pushButton_submit);
        QWidget::setTabOrder(pushButton_submit, pushButton_cancel);

        retranslateUi(addRelations);

        QMetaObject::connectSlotsByName(addRelations);
    } // setupUi

    void retranslateUi(QDialog *addRelations)
    {
        addRelations->setWindowTitle(QApplication::translate("addRelations", "Dialog", 0));
        label_addRelationsTitle->setText(QApplication::translate("addRelations", "Add Relations", 0));
        label_chooseScientist->setText(QApplication::translate("addRelations", "Choose scientist:", 0));
        label_chooseComputer->setText(QApplication::translate("addRelations", "Choose computer:", 0));
        pushButton_submit->setText(QApplication::translate("addRelations", "Submit", 0));
        pushButton_cancel->setText(QApplication::translate("addRelations", "Cancel", 0));
    } // retranslateUi

};

namespace Ui {
    class addRelations: public Ui_addRelations {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDRELATIONS_H
