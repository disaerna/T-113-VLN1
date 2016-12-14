#include "mainmenu.h"
#include "ui_mainmenu.h"
#include "addscientist.h"
#include "addcomputer.h"
#include "editperson.h"
#include "iostream"
#include <QDialog>
#include <QDebug>
#include <QMessageBox>

using namespace std;

MainMenu::MainMenu(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainMenu)
{
    ui->setupUi(this);

    displayScientists();
    displayComputers();
}

MainMenu::~MainMenu()
{
    delete ui;
}

void MainMenu::displayScientists()
{
    string PersonSearch = "";
    PersonSearch = ui->Input_Search_Person->text().toStdString();

    ScientistsDisplay = _domain.getPersonsSearch(PersonSearch);


    ui->table_Scientists->setSortingEnabled(false);
    ui->table_Scientists->clearContents();
    ui->table_Scientists->setRowCount(ScientistsDisplay.size());

    qDebug() << ScientistsDisplay.size();

    for(size_t i = 0; i < ScientistsDisplay.size(); i++)
    {
        Persons person_ = ScientistsDisplay.at(i);

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

void MainMenu::displayComputers()
{

    QString ComputerBuilt;
    string ComputerSearch = "";

    ComputerSearch = ui->Input_Search_Computer->text().toStdString();

    ComputersDisplay = _domain.getComputersSearch(ComputerSearch);


    ui->table_Computers->setSortingEnabled(false);
    ui->table_Computers->clearContents();
    ui->table_Computers->setRowCount(ComputersDisplay.size());

    qDebug() << ComputersDisplay.size();

    for(size_t i = 0; i < ComputersDisplay.size(); i++)
    {
        Computers computer_ = ComputersDisplay.at(i);

        QString ComputerName = QString::fromStdString(computer_.getCompName());
        QString ComputerType = QString::fromStdString(computer_.getCompType());
        bool ComputerBuiltTF = computer_.getCompBuilt();


        if ( ComputerBuiltTF )
        {
            ComputerBuilt = QString::fromStdString("True");
        } else
        {
            ComputerBuilt = QString::fromStdString("False");
        }


        ui->table_Computers->setItem(i, 0, new QTableWidgetItem(ComputerName));
        ui->table_Computers->setItem(i, 2, new QTableWidgetItem(ComputerType));
        ui->table_Computers->setItem(i, 3, new QTableWidgetItem(ComputerBuilt));
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

    }
}

void MainMenu::on_Input_Search_Person_textChanged()
{
    displayScientists();
}

void MainMenu::on_Input_Search_Computer_textChanged()
{
    displayComputers();
}

void MainMenu::on_pushButton_AddPerson_clicked()
{
    addScientist _addScientist;
    _addScientist.exec();

    displayScientists();
}



void MainMenu::on_table_Scientists_cellPressed(int row)
{
    _row = row + 1;
}

void MainMenu::on_pushButton_clicked()
{
    editPerson _editPerson;

    int index = _row;
    _editPerson.setPath(index);
    _editPerson.initializeFields();

    _editPerson.exec();

    displayScientists();
}

int MainMenu::getRow()
{
    return _row;
}

void MainMenu::on_pushButton_RemovePerson_clicked()
{
    int row = _row;

    Persons removePerson;
    removePerson = _domain.getSinglePerson(row);
    string personName = removePerson.getName();
    QString removedPerson = QString::fromStdString(personName);

    QString removal = "About to remove\n" + removedPerson + "\nAre you sure?";
    int confirmRemoval = QMessageBox::question(this, "Confirm", removal);
    if (confirmRemoval == QMessageBox::No)
    {
        return;
    }

    _domain.deletePersonFromFile(row);

    displayScientists();
}

void MainMenu::on_pushButton_AddComputer_clicked()
{
    addComputer _addComputer;
    _addComputer.typeList();

    _addComputer.exec();

    displayComputers();


}

void MainMenu::on_table_Computers_cellPressed(int row)
{
    _row = row + 1;
}

void MainMenu::on_pushButton_RemoveComputer_clicked()
{
    int row = _row;

    Computers RemoveComputer;
    RemoveComputer = _domain.getSingleComputer(row);
    string ComputerName = RemoveComputer.getCompName();
    QString RemovedComputer = QString::fromStdString(ComputerName);

    QString Removal = "About to remove\n" + RemovedComputer + "\nAre you sure?";
    int ConfirmRemoval = QMessageBox::question(this, "Confirm", Removal);
    if (ConfirmRemoval == QMessageBox::No)
    {
        return;
    }

    _domain.deleteComputerFromDatabase(row);

    displayComputers();
}


