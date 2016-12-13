#include "mainmenu.h"
#include "ui_mainmenu.h"

#include "personsmenu.h"
#include "computersmenu.h"

#include <QDialog>

using namespace std;

MainMenu::MainMenu(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainMenu)
{
    ui->setupUi(this);
}

MainMenu::~MainMenu()
{
    delete ui;
}

void MainMenu::DisplayScientists()
{
    ui->table_Scientists->clear();

    ui->table_Scientists->setRowCount(Person.size());

    PersonDisplay.clear();

    for ( unsigned int i = 0; i < Person; i++ )
    {
        Persons Personrow = Person[i];

        std::string searchString = ui->Input_Search_Person->text().toStdString();

        if(Personrow.contains(searchString))
        {
            QString ScientistName = QString::fromStdString(Personrow.getName());
            QString ScientistGender = QString::fromStdString(Personrow.getGender());
            QString ScientistYoB = QString::fromStdString(Personrow.getYearOfBirth());
            QString ScientistYoD = QString::fromStdString(Personrow.getYearOfDeath());

            int currentRow = PersonDisplay.size();

            ui->table_Scientists->setItem(currentRow, 0, new QTableWidgetItem(ScientistName));
            ui->table_Scientists->setItem(currentRow, 1, new QTableWidgetItem(ScientistGender));
            ui->table_Scientists->setItem(currentRow, 2, new QTableWidgetItem(ScientistYoB));
            ui->table_Scientists->setItem(currentRow, 3, new QTableWidgetItem(ScientistYoD));

            Personrow.push_back(currentCar);
        }
    }

    ui->table_Scientists->setRowCount(PersonDisplay.size());

}

void MainMenu::GetAllPersons()
{
    Person = _domain.getPersons();

    DisplayScientists();
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
