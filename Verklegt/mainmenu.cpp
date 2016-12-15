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

    displayComputers();
    displayScientistRelations();
    displayComputersRelations();
    displayScientists();
    ui->Mainmenu_tabs->setTabEnabled(0, true);
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
        QString ScId = QString::number(ScientistID);
       // IDScientistManagement(1, ScientistID);

        ui->table_Scientists->setItem(i, 0, new QTableWidgetItem(ScientistName));
        ui->table_Scientists->setItem(i, 1, new QTableWidgetItem(ScientistGender));
        ui->table_Scientists->setItem(i, 2, new QTableWidgetItem(ScientistYoB));
        ui->table_Scientists->setItem(i, 3, new QTableWidgetItem(ScientistYoD));
        ui->table_Scientists->setItem(i, 4,new QTableWidgetItem(ScId));
       // qDebug() << ScId;
        ui->table_Scientists->hideColumn(4);
    }
    ui->table_Scientists->setSortingEnabled(true);
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
        ui->table_Computers->setItem(i, 4,new QTableWidgetItem(QString::number(ComputerID)));
        ui->table_Computers->hideColumn(4);
    }
    ui->table_Computers->setSortingEnabled(true);
}

void MainMenu::displayScientistRelations()
{
    string PersonSearch = "";
    PersonSearch = ui->RelationScienSearch->text().toStdString();
    ScientistsRelationDisplay = _domain.getPersonsSearch(PersonSearch);


    ui->RelationScientists->setSortingEnabled(false);

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
    ui->RelationScientists->setSortingEnabled(true);

}
void MainMenu::displayComputersRelations()
{
    string ComputerSearch = "";

    ComputerSearch = ui->RelationCompSearch->text().toStdString();

    ComputersRelationDisplay = _domain.getComputersSearch(ComputerSearch);

    ui->RelationComputers->setSortingEnabled(false);

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
        ui->RelationComputers->setItem(i, 1, new QTableWidgetItem(computer_.getCompID()));
        ui->RelationComputers->hideColumn(1);
    }
    ui->RelationComputers->setSortingEnabled(true);
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
    int id = _addScientist.exec();

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
    QString scientistId = ui->table_Scientists->item(index,4)->text();
    _editPerson.setPath(scientistId.toUInt());
    _editPerson.initializeFields();

    _editPerson.exec();

    displayScientists();
}


void MainMenu::on_pushButton_EditComputer_clicked()
{
    editComputer _editComputer;

    int index = _row;
    QString computerId = ui->table_Computers->item(index,4)->text();
    _editComputer.setPath(computerId.toUInt());
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
    int ID = ui->table_Scientists->item(row,4)->text().toUInt();
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

    int id = _addComputer.exec();

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
    int ID = ui->table_Computers->item(row,4)->text().toUInt();
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
    ui->pushButton_editCompRelation->setEnabled(true);
    ui->pushButton_removeCompRelation->setEnabled(true);
    _row = row;
}

void MainMenu::on_RelationScientists_cellPressed(int row, int column)
{
    ui->pushButton_editSciRelation->setEnabled(true);
    ui->pushButton_removeSciRelation->setEnabled(true);
    _row = row;
}
