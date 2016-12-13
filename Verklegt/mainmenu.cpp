#include "mainmenu.h"
#include "ui_mainmenu.h"
#include "addscientist.h"
#include "personsmenu.h"
#include "computersmenu.h"
#include "iostream"
#include <QDialog>
#include <QDebug>

using namespace std;

MainMenu::MainMenu(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainMenu)
{
    ui->setupUi(this);

    displayScientists();
}

MainMenu::~MainMenu()
{
    delete ui;
}

void MainMenu::displayScientists()
{
    string personSearch = "";
    personSearch = ui->Input_Search_Person->text().toStdString();

    scientistsDisplay = _domain.getPersonsSearch(personSearch);


    ui->table_Scientists->setSortingEnabled(false);
    ui->table_Scientists->clearContents();
    ui->table_Scientists->setRowCount(scientistsDisplay.size());

    qDebug() << scientistsDisplay.size();

    for(size_t i = 0; i < scientistsDisplay.size(); i++)
    {
        Persons person_ = scientistsDisplay.at(i);

        QString ScientistName = QString::fromStdString(person_.getName());
        QString ScientistGender = QString::fromStdString(person_.getGender());
        QString ScientistYoB = QString::fromStdString(person_.getYearOfBirth());
        QString ScientistYoD = QString::fromStdString(person_.getYearOfDeath());


        ui->table_Scientists->setItem(i, 0, new QTableWidgetItem(ScientistName));
        ui->table_Scientists->setItem(i, 1, new QTableWidgetItem(ScientistGender));
        ui->table_Scientists->setItem(i, 2, new QTableWidgetItem(ScientistYoB));
        ui->table_Scientists->setItem(i, 3, new QTableWidgetItem(ScientistYoD));
    }

}
//void MainMenu::on_ButtonQuit_clicked()
//{
//    close();
//    qApp->quit();
//}

//void MainMenu::on_ButtonScientists_clicked()
//{
//    personsMenu = new PersonsMenu(this);
//    personsMenu->setModal(true);
//    personsMenu->exec();

//}

//void MainMenu::on_ButtonComputers_clicked()
//{
//    computersMenu = new ComputersMenu(this);
//    computersMenu->setModal(true);
//    computersMenu->exec();
//}


void MainMenu::on_Mainmenu_tabs_currentChanged(int index)
{
    if (index == 0)
        {
            //displayScientists();
        }
        else if (index == 1)
        {
            //();
        }
}

void MainMenu::on_Input_Search_Person_textChanged()
{
    displayScientists();
}

void MainMenu::on_pushButton_AddPerson_clicked()
{
    addScientist _addScientist;
    _addScientist.exec();

    displayScientists();
}
