#include "mainmenu.h"
#include "ui_mainmenu.h"

#include "personsmenu.h"
#include "computersmenu.h"
#include "iostream"
#include <QDebug>

#include <QDialog>

using namespace std;

MainMenu::MainMenu(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainMenu)
{
    ui->setupUi(this);
    GetAllPersons();
}

MainMenu::~MainMenu()
{
    delete ui;
}

void MainMenu::GetAllPersons()
{
    Person = _domain.getPersons();
    qDebug() << "SIZE" << Person.size();
    for(int i=0; i<Person.size(); i++)
    {
        string check =  Person[i].getName();
    }

    DisplayScientists();
}

void MainMenu::DisplayScientists()
{
    //ui->table_Scientists->clear();

    ui->table_Scientists->setRowCount(Person.size());

    PersonDisplay.clear();

    for ( unsigned int i = 0; i < Person.size(); i++ )
    {
        Persons PersonRow = Person[i];

        string searchString = ui->Input_Search_Person->text().toStdString();

        if(1)
        {
            QString ScientistName = QString::fromStdString(PersonRow.getName());
            QString ScientistGender = QString::fromStdString(PersonRow.getGender());
            QString ScientistYoB = QString::fromStdString(PersonRow.getYearOfBirth());
            QString ScientistYoD = QString::fromStdString(PersonRow.getYearOfDeath());

            int currentRow = PersonDisplay.size();

            ui->table_Scientists->setItem(currentRow, 0, new QTableWidgetItem(ScientistName));
            ui->table_Scientists->setItem(currentRow, 1, new QTableWidgetItem(ScientistGender));
            ui->table_Scientists->setItem(currentRow, 2, new QTableWidgetItem(ScientistYoB));
            ui->table_Scientists->setItem(currentRow, 3, new QTableWidgetItem(ScientistYoD));

            PersonDisplay.push_back(PersonRow);
        }
    }

    ui->table_Scientists->setRowCount(PersonDisplay.size());

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


void MainMenu::on_Input_Search_Person_textChanged(const QString &arg1)
{
    DisplayScientists();
}
