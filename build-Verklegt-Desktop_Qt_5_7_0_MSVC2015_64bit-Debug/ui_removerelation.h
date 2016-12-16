/********************************************************************************
** Form generated from reading UI file 'removerelation.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REMOVERELATION_H
#define UI_REMOVERELATION_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHeaderView>

QT_BEGIN_NAMESPACE

class Ui_removeRelation
{
public:
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *removeRelation)
    {
        if (removeRelation->objectName().isEmpty())
            removeRelation->setObjectName(QStringLiteral("removeRelation"));
        removeRelation->resize(400, 300);
        buttonBox = new QDialogButtonBox(removeRelation);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(30, 240, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        retranslateUi(removeRelation);
        QObject::connect(buttonBox, SIGNAL(accepted()), removeRelation, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), removeRelation, SLOT(reject()));

        QMetaObject::connectSlotsByName(removeRelation);
    } // setupUi

    void retranslateUi(QDialog *removeRelation)
    {
        removeRelation->setWindowTitle(QApplication::translate("removeRelation", "Dialog", 0));
    } // retranslateUi

};

namespace Ui {
    class removeRelation: public Ui_removeRelation {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REMOVERELATION_H
