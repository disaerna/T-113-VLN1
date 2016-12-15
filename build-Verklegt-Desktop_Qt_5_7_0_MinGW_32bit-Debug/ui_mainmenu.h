/********************************************************************************
** Form generated from reading UI file 'mainmenu.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINMENU_H
#define UI_MAINMENU_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainMenu
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout_3;
    QTabWidget *Mainmenu_tabs;
    QWidget *Tab_Scientists;
    QVBoxLayout *verticalLayout;
    QLineEdit *Input_Search_Person;
    QSpacerItem *horizontalSpacer_2;
    QTableWidget *table_Scientists;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton_AddPerson;
    QPushButton *pushButton_EditPerson;
    QPushButton *pushButton_RemovePerson;
    QWidget *Tab_Computers;
    QVBoxLayout *verticalLayout_2;
    QLineEdit *Input_Search_Computer;
    QSpacerItem *horizontalSpacer_4;
    QTableWidget *table_Computers;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *pushButton_AddComputer;
    QPushButton *pushButton_EditComputer;
    QPushButton *pushButton_RemoveComputer;
    QWidget *Tab_Relations;
    QTabWidget *tabWidget;
    QWidget *tab;
    QTableWidget *RelationScientists;
    QLabel *imageScientist;
    QTableWidget *RelationsScientistComputers;
    QLabel *RelationScientistText;
    QWidget *tab_2;
    QLabel *RelationComputerText;
    QTableWidget *RelationComputers;
    QLabel *imageComputer;
    QTableWidget *RelationsComputerScientists;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainMenu)
    {
        if (MainMenu->objectName().isEmpty())
            MainMenu->setObjectName(QStringLiteral("MainMenu"));
        MainMenu->resize(611, 680);
        MainMenu->setMinimumSize(QSize(611, 680));
        MainMenu->setToolTipDuration(0);
        centralwidget = new QWidget(MainMenu);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        verticalLayout_3 = new QVBoxLayout(centralwidget);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        Mainmenu_tabs = new QTabWidget(centralwidget);
        Mainmenu_tabs->setObjectName(QStringLiteral("Mainmenu_tabs"));
        Mainmenu_tabs->setMinimumSize(QSize(530, 633));
        Mainmenu_tabs->setFocusPolicy(Qt::WheelFocus);
        Mainmenu_tabs->setToolTipDuration(0);
        Mainmenu_tabs->setUsesScrollButtons(true);
        Tab_Scientists = new QWidget();
        Tab_Scientists->setObjectName(QStringLiteral("Tab_Scientists"));
        verticalLayout = new QVBoxLayout(Tab_Scientists);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        Input_Search_Person = new QLineEdit(Tab_Scientists);
        Input_Search_Person->setObjectName(QStringLiteral("Input_Search_Person"));
        Input_Search_Person->setToolTipDuration(0);

        verticalLayout->addWidget(Input_Search_Person);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        verticalLayout->addItem(horizontalSpacer_2);

        table_Scientists = new QTableWidget(Tab_Scientists);
        if (table_Scientists->columnCount() < 4)
            table_Scientists->setColumnCount(4);
        QFont font;
        font.setBold(false);
        font.setWeight(50);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        __qtablewidgetitem->setText(QStringLiteral("Name"));
        __qtablewidgetitem->setFont(font);
        table_Scientists->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        table_Scientists->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        table_Scientists->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        table_Scientists->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        table_Scientists->setObjectName(QStringLiteral("table_Scientists"));
        table_Scientists->setMinimumSize(QSize(561, 0));
        table_Scientists->setContextMenuPolicy(Qt::PreventContextMenu);
        table_Scientists->setToolTipDuration(0);
        table_Scientists->setAutoFillBackground(false);
        table_Scientists->setEditTriggers(QAbstractItemView::NoEditTriggers);
        table_Scientists->setAlternatingRowColors(true);
        table_Scientists->setSelectionMode(QAbstractItemView::SingleSelection);
        table_Scientists->setSelectionBehavior(QAbstractItemView::SelectRows);
        table_Scientists->setShowGrid(false);
        table_Scientists->setSortingEnabled(true);
        table_Scientists->setCornerButtonEnabled(true);
        table_Scientists->setColumnCount(4);
        table_Scientists->horizontalHeader()->setVisible(false);
        table_Scientists->horizontalHeader()->setHighlightSections(true);
        table_Scientists->horizontalHeader()->setStretchLastSection(true);
        table_Scientists->verticalHeader()->setVisible(false);
        table_Scientists->verticalHeader()->setHighlightSections(true);

        verticalLayout->addWidget(table_Scientists);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        verticalLayout->addItem(horizontalSpacer);

        pushButton_AddPerson = new QPushButton(Tab_Scientists);
        pushButton_AddPerson->setObjectName(QStringLiteral("pushButton_AddPerson"));
        pushButton_AddPerson->setToolTipDuration(0);

        verticalLayout->addWidget(pushButton_AddPerson);

        pushButton_EditPerson = new QPushButton(Tab_Scientists);
        pushButton_EditPerson->setObjectName(QStringLiteral("pushButton_EditPerson"));
        pushButton_EditPerson->setEnabled(false);
        pushButton_EditPerson->setToolTipDuration(0);

        verticalLayout->addWidget(pushButton_EditPerson);

        pushButton_RemovePerson = new QPushButton(Tab_Scientists);
        pushButton_RemovePerson->setObjectName(QStringLiteral("pushButton_RemovePerson"));
        pushButton_RemovePerson->setEnabled(false);
        pushButton_RemovePerson->setToolTipDuration(0);

        verticalLayout->addWidget(pushButton_RemovePerson);

        Mainmenu_tabs->addTab(Tab_Scientists, QString());
        Tab_Computers = new QWidget();
        Tab_Computers->setObjectName(QStringLiteral("Tab_Computers"));
        verticalLayout_2 = new QVBoxLayout(Tab_Computers);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        Input_Search_Computer = new QLineEdit(Tab_Computers);
        Input_Search_Computer->setObjectName(QStringLiteral("Input_Search_Computer"));
        Input_Search_Computer->setToolTipDuration(0);

        verticalLayout_2->addWidget(Input_Search_Computer);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        verticalLayout_2->addItem(horizontalSpacer_4);

        table_Computers = new QTableWidget(Tab_Computers);
        if (table_Computers->columnCount() < 4)
            table_Computers->setColumnCount(4);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        __qtablewidgetitem4->setFont(font);
        table_Computers->setHorizontalHeaderItem(0, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        table_Computers->setHorizontalHeaderItem(1, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        table_Computers->setHorizontalHeaderItem(2, __qtablewidgetitem6);
        QFont font1;
        font1.setStrikeOut(false);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        __qtablewidgetitem7->setFont(font1);
        table_Computers->setHorizontalHeaderItem(3, __qtablewidgetitem7);
        table_Computers->setObjectName(QStringLiteral("table_Computers"));
        table_Computers->setContextMenuPolicy(Qt::PreventContextMenu);
#ifndef QT_NO_TOOLTIP
        table_Computers->setToolTip(QStringLiteral("<html><head/><body><p><br/></p></body></html>"));
#endif // QT_NO_TOOLTIP
        table_Computers->setToolTipDuration(0);
        table_Computers->setStyleSheet(QStringLiteral(""));
        table_Computers->setEditTriggers(QAbstractItemView::NoEditTriggers);
        table_Computers->setAlternatingRowColors(true);
        table_Computers->setSelectionMode(QAbstractItemView::SingleSelection);
        table_Computers->setSelectionBehavior(QAbstractItemView::SelectRows);
        table_Computers->setShowGrid(false);
        table_Computers->setSortingEnabled(true);
        table_Computers->horizontalHeader()->setProperty("showSortIndicator", QVariant(true));
        table_Computers->horizontalHeader()->setStretchLastSection(true);
        table_Computers->verticalHeader()->setHighlightSections(false);

        verticalLayout_2->addWidget(table_Computers);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        verticalLayout_2->addItem(horizontalSpacer_3);

        pushButton_AddComputer = new QPushButton(Tab_Computers);
        pushButton_AddComputer->setObjectName(QStringLiteral("pushButton_AddComputer"));
        pushButton_AddComputer->setToolTipDuration(0);

        verticalLayout_2->addWidget(pushButton_AddComputer);

        pushButton_EditComputer = new QPushButton(Tab_Computers);
        pushButton_EditComputer->setObjectName(QStringLiteral("pushButton_EditComputer"));
        pushButton_EditComputer->setEnabled(false);
        pushButton_EditComputer->setToolTipDuration(0);

        verticalLayout_2->addWidget(pushButton_EditComputer);

        pushButton_RemoveComputer = new QPushButton(Tab_Computers);
        pushButton_RemoveComputer->setObjectName(QStringLiteral("pushButton_RemoveComputer"));
        pushButton_RemoveComputer->setEnabled(false);
        pushButton_RemoveComputer->setToolTipDuration(0);

        verticalLayout_2->addWidget(pushButton_RemoveComputer);

        Mainmenu_tabs->addTab(Tab_Computers, QString());
        Tab_Relations = new QWidget();
        Tab_Relations->setObjectName(QStringLiteral("Tab_Relations"));
        tabWidget = new QTabWidget(Tab_Relations);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setGeometry(QRect(10, 10, 561, 581));
        tabWidget->setToolTipDuration(0);
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        RelationScientists = new QTableWidget(tab);
        if (RelationScientists->columnCount() < 1)
            RelationScientists->setColumnCount(1);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        RelationScientists->setHorizontalHeaderItem(0, __qtablewidgetitem8);
        RelationScientists->setObjectName(QStringLiteral("RelationScientists"));
        RelationScientists->setGeometry(QRect(15, 51, 261, 481));
        RelationScientists->setToolTipDuration(0);
        RelationScientists->horizontalHeader()->setStretchLastSection(true);
        imageScientist = new QLabel(tab);
        imageScientist->setObjectName(QStringLiteral("imageScientist"));
        imageScientist->setGeometry(QRect(350, 50, 161, 151));
        RelationsScientistComputers = new QTableWidget(tab);
        if (RelationsScientistComputers->columnCount() < 1)
            RelationsScientistComputers->setColumnCount(1);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        RelationsScientistComputers->setHorizontalHeaderItem(0, __qtablewidgetitem9);
        RelationsScientistComputers->setObjectName(QStringLiteral("RelationsScientistComputers"));
        RelationsScientistComputers->setGeometry(QRect(300, 260, 241, 271));
        RelationsScientistComputers->setToolTipDuration(0);
        RelationsScientistComputers->horizontalHeader()->setStretchLastSection(true);
        RelationScientistText = new QLabel(tab);
        RelationScientistText->setObjectName(QStringLiteral("RelationScientistText"));
        RelationScientistText->setGeometry(QRect(20, 20, 251, 21));
        RelationScientistText->setToolTipDuration(0);
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        RelationComputerText = new QLabel(tab_2);
        RelationComputerText->setObjectName(QStringLiteral("RelationComputerText"));
        RelationComputerText->setGeometry(QRect(20, 20, 251, 21));
        RelationComputerText->setToolTipDuration(0);
        RelationComputers = new QTableWidget(tab_2);
        if (RelationComputers->columnCount() < 1)
            RelationComputers->setColumnCount(1);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        RelationComputers->setHorizontalHeaderItem(0, __qtablewidgetitem10);
        RelationComputers->setObjectName(QStringLiteral("RelationComputers"));
        RelationComputers->setGeometry(QRect(20, 50, 261, 481));
        RelationComputers->setToolTipDuration(0);
        RelationComputers->horizontalHeader()->setStretchLastSection(true);
        imageComputer = new QLabel(tab_2);
        imageComputer->setObjectName(QStringLiteral("imageComputer"));
        imageComputer->setGeometry(QRect(370, 50, 161, 151));
        RelationsComputerScientists = new QTableWidget(tab_2);
        if (RelationsComputerScientists->columnCount() < 1)
            RelationsComputerScientists->setColumnCount(1);
        QTableWidgetItem *__qtablewidgetitem11 = new QTableWidgetItem();
        RelationsComputerScientists->setHorizontalHeaderItem(0, __qtablewidgetitem11);
        RelationsComputerScientists->setObjectName(QStringLiteral("RelationsComputerScientists"));
        RelationsComputerScientists->setGeometry(QRect(300, 260, 241, 271));
        RelationsComputerScientists->setToolTipDuration(0);
        RelationsComputerScientists->horizontalHeader()->setStretchLastSection(true);
        tabWidget->addTab(tab_2, QString());
        Mainmenu_tabs->addTab(Tab_Relations, QString());

        verticalLayout_3->addWidget(Mainmenu_tabs);

        MainMenu->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainMenu);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        MainMenu->setStatusBar(statusbar);
        QWidget::setTabOrder(Mainmenu_tabs, Input_Search_Person);
        QWidget::setTabOrder(Input_Search_Person, table_Scientists);
        QWidget::setTabOrder(table_Scientists, pushButton_AddPerson);
        QWidget::setTabOrder(pushButton_AddPerson, pushButton_EditPerson);
        QWidget::setTabOrder(pushButton_EditPerson, pushButton_RemovePerson);
        QWidget::setTabOrder(pushButton_RemovePerson, Input_Search_Computer);
        QWidget::setTabOrder(Input_Search_Computer, table_Computers);
        QWidget::setTabOrder(table_Computers, pushButton_AddComputer);
        QWidget::setTabOrder(pushButton_AddComputer, pushButton_EditComputer);
        QWidget::setTabOrder(pushButton_EditComputer, pushButton_RemoveComputer);

        retranslateUi(MainMenu);

        Mainmenu_tabs->setCurrentIndex(2);
        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(MainMenu);
    } // setupUi

    void retranslateUi(QMainWindow *MainMenu)
    {
        MainMenu->setWindowTitle(QApplication::translate("MainMenu", "MainWindow", 0));
#ifndef QT_NO_TOOLTIP
        Mainmenu_tabs->setToolTip(QApplication::translate("MainMenu", "<html><head/><body><p><br/></p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        Input_Search_Person->setText(QString());
        Input_Search_Person->setPlaceholderText(QApplication::translate("MainMenu", "Search", 0));
        QTableWidgetItem *___qtablewidgetitem = table_Scientists->horizontalHeaderItem(1);
        ___qtablewidgetitem->setText(QApplication::translate("MainMenu", "Gender", 0));
        QTableWidgetItem *___qtablewidgetitem1 = table_Scientists->horizontalHeaderItem(2);
        ___qtablewidgetitem1->setText(QApplication::translate("MainMenu", "Year of Birth", 0));
        QTableWidgetItem *___qtablewidgetitem2 = table_Scientists->horizontalHeaderItem(3);
        ___qtablewidgetitem2->setText(QApplication::translate("MainMenu", "Year of Death", 0));
        pushButton_AddPerson->setText(QApplication::translate("MainMenu", "Add a new scientist", 0));
        pushButton_EditPerson->setText(QApplication::translate("MainMenu", "Edit selected scientist", 0));
        pushButton_RemovePerson->setText(QApplication::translate("MainMenu", "Remove selected scientist", 0));
        Mainmenu_tabs->setTabText(Mainmenu_tabs->indexOf(Tab_Scientists), QApplication::translate("MainMenu", "Scientists", 0));
        Input_Search_Computer->setPlaceholderText(QApplication::translate("MainMenu", "Search", 0));
        QTableWidgetItem *___qtablewidgetitem3 = table_Computers->horizontalHeaderItem(0);
        ___qtablewidgetitem3->setText(QApplication::translate("MainMenu", "Name", 0));
        QTableWidgetItem *___qtablewidgetitem4 = table_Computers->horizontalHeaderItem(1);
        ___qtablewidgetitem4->setText(QApplication::translate("MainMenu", "Year Built", 0));
        QTableWidgetItem *___qtablewidgetitem5 = table_Computers->horizontalHeaderItem(2);
        ___qtablewidgetitem5->setText(QApplication::translate("MainMenu", "Type", 0));
        QTableWidgetItem *___qtablewidgetitem6 = table_Computers->horizontalHeaderItem(3);
        ___qtablewidgetitem6->setText(QApplication::translate("MainMenu", "Built", 0));
#ifndef QT_NO_WHATSTHIS
        table_Computers->setWhatsThis(QApplication::translate("MainMenu", "<html><head/><body><p><br/></p></body></html>", 0));
#endif // QT_NO_WHATSTHIS
        pushButton_AddComputer->setText(QApplication::translate("MainMenu", "Add a new computer", 0));
        pushButton_EditComputer->setText(QApplication::translate("MainMenu", "Edit selected computer", 0));
        pushButton_RemoveComputer->setText(QApplication::translate("MainMenu", "Remove selected computer", 0));
        Mainmenu_tabs->setTabText(Mainmenu_tabs->indexOf(Tab_Computers), QApplication::translate("MainMenu", "Computers", 0));
        QTableWidgetItem *___qtablewidgetitem7 = RelationScientists->horizontalHeaderItem(0);
        ___qtablewidgetitem7->setText(QApplication::translate("MainMenu", "Name", 0));
        imageScientist->setText(QString());
        QTableWidgetItem *___qtablewidgetitem8 = RelationsScientistComputers->horizontalHeaderItem(0);
        ___qtablewidgetitem8->setText(QApplication::translate("MainMenu", "Name", 0));
        RelationScientistText->setText(QApplication::translate("MainMenu", "Please select a scientist to see relations", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("MainMenu", "Scientist", 0));
        RelationComputerText->setText(QApplication::translate("MainMenu", "Please select a computer to see relations", 0));
        QTableWidgetItem *___qtablewidgetitem9 = RelationComputers->horizontalHeaderItem(0);
        ___qtablewidgetitem9->setText(QApplication::translate("MainMenu", "Name", 0));
        imageComputer->setText(QString());
        QTableWidgetItem *___qtablewidgetitem10 = RelationsComputerScientists->horizontalHeaderItem(0);
        ___qtablewidgetitem10->setText(QApplication::translate("MainMenu", "Name", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("MainMenu", "Computers", 0));
        Mainmenu_tabs->setTabText(Mainmenu_tabs->indexOf(Tab_Relations), QApplication::translate("MainMenu", "Relation", 0));
    } // retranslateUi

};

namespace Ui {
    class MainMenu: public Ui_MainMenu {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINMENU_H
