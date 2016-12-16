/********************************************************************************
** Form generated from reading UI file 'editrelation.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EDITRELATION_H
#define UI_EDITRELATION_H

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

class Ui_editRelation
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *label_editRelationTitle;
    QLabel *label_chooseScientist;
    QComboBox *comboBox_scientist;
    QLabel *label_chooseComputer;
    QComboBox *comboBox_computer;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton_submit;
    QPushButton *pushButton_cancel;

    void setupUi(QDialog *editRelation)
    {
        if (editRelation->objectName().isEmpty())
            editRelation->setObjectName(QStringLiteral("editRelation"));
        editRelation->resize(374, 328);
        verticalLayout = new QVBoxLayout(editRelation);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label_editRelationTitle = new QLabel(editRelation);
        label_editRelationTitle->setObjectName(QStringLiteral("label_editRelationTitle"));
        QFont font;
        font.setPointSize(11);
        font.setBold(true);
        font.setWeight(75);
        label_editRelationTitle->setFont(font);

        verticalLayout->addWidget(label_editRelationTitle);

        label_chooseScientist = new QLabel(editRelation);
        label_chooseScientist->setObjectName(QStringLiteral("label_chooseScientist"));

        verticalLayout->addWidget(label_chooseScientist);

        comboBox_scientist = new QComboBox(editRelation);
        comboBox_scientist->setObjectName(QStringLiteral("comboBox_scientist"));

        verticalLayout->addWidget(comboBox_scientist);

        label_chooseComputer = new QLabel(editRelation);
        label_chooseComputer->setObjectName(QStringLiteral("label_chooseComputer"));

        verticalLayout->addWidget(label_chooseComputer);

        comboBox_computer = new QComboBox(editRelation);
        comboBox_computer->setObjectName(QStringLiteral("comboBox_computer"));

        verticalLayout->addWidget(comboBox_computer);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        verticalLayout->addItem(horizontalSpacer);

        pushButton_submit = new QPushButton(editRelation);
        pushButton_submit->setObjectName(QStringLiteral("pushButton_submit"));

        verticalLayout->addWidget(pushButton_submit);

        pushButton_cancel = new QPushButton(editRelation);
        pushButton_cancel->setObjectName(QStringLiteral("pushButton_cancel"));

        verticalLayout->addWidget(pushButton_cancel);

        QWidget::setTabOrder(comboBox_scientist, comboBox_computer);
        QWidget::setTabOrder(comboBox_computer, pushButton_submit);
        QWidget::setTabOrder(pushButton_submit, pushButton_cancel);

        retranslateUi(editRelation);

        QMetaObject::connectSlotsByName(editRelation);
    } // setupUi

    void retranslateUi(QDialog *editRelation)
    {
        editRelation->setWindowTitle(QApplication::translate("editRelation", "Dialog", 0));
        label_editRelationTitle->setText(QApplication::translate("editRelation", "Edit relations", 0));
        label_chooseScientist->setText(QApplication::translate("editRelation", "Choose scientist:", 0));
        label_chooseComputer->setText(QApplication::translate("editRelation", "Choose computer:", 0));
        pushButton_submit->setText(QApplication::translate("editRelation", "Submit", 0));
        pushButton_cancel->setText(QApplication::translate("editRelation", "Cancel", 0));
    } // retranslateUi

};

namespace Ui {
    class editRelation: public Ui_editRelation {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EDITRELATION_H
