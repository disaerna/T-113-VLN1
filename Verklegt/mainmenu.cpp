#include "mainmenu.h"
#include "ui_mainmenu.h"
#include "addscientist.h"
#include "addcomputer.h"
#include "editperson.h"
#include "editcomputer.h"
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
    displayScientistRelations();
    displayComputersRelations();
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
    ui->table_Scientists->setSortingEnabled(true);
    ui->table_Scientists->clearContents();
    ui->table_Scientists->setRowCount(ScientistsDisplay.size());
    ui->table_Scientists->horizontalHeader()->setVisible(true);
    ui->table_Scientists->verticalHeader()->setVisible(false);

    //qDebug() << ScientistsDisplay.size();

    for(size_t i = 0; i < ScientistsDisplay.size(); i++)
    {
        Persons person_ = ScientistsDisplay.at(i);

        QString ScientistName = QString::fromStdString(person_.getName());
        QString ScientistGender = QString::fromStdString(person_.getGender());
        QString ScientistYoB = QString::fromStdString(person_.getYearOfBirth());
        QString ScientistYoD = QString::fromStdString(person_.getYearOfDeath());
        int ScientistID = person_.getID();
        IDScientistManagement(1, ScientistID);

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
    ui->table_Computers->setSortingEnabled(true);
    ui->table_Computers->clearContents();
    ui->table_Computers->setRowCount(ComputersDisplay.size());
    ui->table_Computers->horizontalHeader()->setVisible(true);
    ui->table_Computers->verticalHeader()->setVisible(false);

    //qDebug() << ComputersDisplay.size();

    for(size_t i = 0; i < ComputersDisplay.size(); i++)
    {
        Computers computer_ = ComputersDisplay.at(i);

        QString ComputerName = QString::fromStdString(computer_.getCompName());
        QString ComputerYear = QString::fromStdString(computer_.getCompYearBuild());
        QString ComputerType = QString::fromStdString(computer_.getCompType());
        bool ComputerBuiltTF = computer_.getCompBuilt();
        int ComputerID = computer_.getCompID();
        IDComputerManagement(1, ComputerID);


        if ( ComputerBuiltTF )
        {
            ComputerBuilt = QString::fromStdString("True");
        } else
        {
            ComputerBuilt = QString::fromStdString("False");
        }

        ui->table_Computers->setItem(i, 0, new QTableWidgetItem(ComputerName));
        ui->table_Computers->setItem(i, 1, new QTableWidgetItem(ComputerYear));
        ui->table_Computers->setItem(i, 2, new QTableWidgetItem(ComputerType));
        ui->table_Computers->setItem(i, 3, new QTableWidgetItem(ComputerBuilt));
    }
}

void MainMenu::displayScientistRelations()
{
    string PersonSearch = "";
    PersonSearch = ui->RelationScienSearch->text().toStdString();
    ScientistsRelationDisplay = _domain.getPersonsSearch(PersonSearch);


    ui->RelationScientists->setSortingEnabled(false);
    ui->RelationScientists->setSortingEnabled(true);
    ui->RelationScientists->clearContents();
    ui->RelationScientists->setRowCount(ScientistsRelationDisplay.size());
    ui->RelationScientists->horizontalHeader()->setVisible(true);
    ui->RelationScientists->verticalHeader()->setVisible(false);

    qDebug() << ScientistsRelationDisplay.size();

    for(size_t i = 0; i < ScientistsRelationDisplay.size(); i++)
    {
        Persons person_ = ScientistsRelationDisplay.at(i);

        QString ScientistName = QString::fromStdString(person_.getName());

        ui->RelationScientists->setItem(i, 0, new QTableWidgetItem(ScientistName));
    }

}
void MainMenu::displayComputersRelations()
{
    string ComputerSearch = "";

    ComputerSearch = ui->RelationCompSearch->text().toStdString();

    ComputersRelationDisplay = _domain.getComputersSearch(ComputerSearch);

    ui->RelationComputers->setSortingEnabled(false);
    ui->RelationComputers->setSortingEnabled(true);
    ui->RelationComputers->clearContents();
    ui->RelationComputers->setRowCount(ComputersRelationDisplay.size());
    ui->RelationComputers->horizontalHeader()->setVisible(true);
    ui->RelationComputers->verticalHeader()->setVisible(false);

    qDebug() << ComputersRelationDisplay.size();

    for(size_t i = 0; i < ComputersRelationDisplay.size(); i++)
    {
        Computers computer_ = ComputersRelationDisplay.at(i);

        QString ComputerName = QString::fromStdString(computer_.getCompName());

        ui->RelationComputers->setItem(i, 0, new QTableWidgetItem(ComputerName));
    }
}


int MainMenu::IDScientistManagement(int x, int y)
{
    if ( x == 1 )
    {
        ScientistIDs.push_back(y);
        return 0;
    }
    else if ( x == 2 )
    {
        return ScientistIDs[y];
    }
    return 0;
}

int MainMenu::IDComputerManagement(int x, int y)
{
    if ( x == 1 )
    {
        ComputerIDs.push_back(y);
        return 0;
    }
    else if ( x == 2 )
    {
        return ComputerIDs[y];
    }
    return 0;
}

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
    ui->pushButton_RemovePerson->setEnabled(true);
    ui->pushButton_EditPerson->setEnabled(true);
    _row = row;
}

void MainMenu::on_pushButton_EditPerson_clicked()
{
    editPerson _editPerson;

    int index = _row;
    int ID = IDScientistManagement(2, index);
    _editPerson.setPath(ID);
    _editPerson.initializeFields();

    _editPerson.exec();

    displayScientists();
}



void MainMenu::on_pushButton_EditComputer_clicked()
{
    editComputer _editComputer;

    int index = _row;
    int ID = IDComputerManagement(2, index);
    _editComputer.setPath(ID);
    _editComputer.initializeFields();

    _editComputer.exec();

    displayComputers();
}

int MainMenu::getRow()
{
    return _row;
}

void MainMenu::on_pushButton_RemovePerson_clicked()
{
    int row = _row;
    int ID = IDScientistManagement(2, row);
    Persons removePerson;
    removePerson = _domain.getSinglePerson(ID);
    string personName = removePerson.getName();
    QString removedPerson = QString::fromStdString(personName);

    QString removal = "About to remove\n" + removedPerson + "\nAre you sure?";
    int confirmRemoval = QMessageBox::question(this, "Confirm", removal);
    if (confirmRemoval == QMessageBox::No)
    {
        return;
    }

    _domain.deletePersonFromFile(ID);

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
    ui->pushButton_RemoveComputer->setEnabled(true);
    ui->pushButton_EditComputer->setEnabled(true);
    _row = row;
}

void MainMenu::on_pushButton_RemoveComputer_clicked()
{
    int row = _row;
    int ID = IDComputerManagement(2, row);
    Computers RemoveComputer;

    RemoveComputer = _domain.getSingleComputer(ID);
    string ComputerName = RemoveComputer.getCompName();
    QString RemovedComputer = QString::fromStdString(ComputerName);

    QString Removal = "About to remove\n" + RemovedComputer + "\nAre you sure?";
    int ConfirmRemoval = QMessageBox::question(this, "Confirm", Removal);
    if (ConfirmRemoval == QMessageBox::No)
    {
        return;
    }

    _domain.deleteComputerFromDatabase(ID);

    displayComputers();
}

void MainMenu::on_RelationScienSearch_textChanged(const QString &arg1)
{
    displayScientistRelations();
}

void MainMenu::on_RelationCompSearch_textChanged(const QString &arg1)
{
    displayComputersRelations();
}

void MainMenu::on_RelationComputers_cellPressed(int row, int column)
{

}

void MainMenu::on_RelationScientists_cellPressed(int row, int column)
{

}
