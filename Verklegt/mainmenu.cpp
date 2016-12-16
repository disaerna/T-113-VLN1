#include "mainmenu.h"
#include "ui_mainmenu.h"

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

    ui->Mainmenu_tabs->setTabEnabled(0, true);
    ui->Mainmenu_tabs->setCurrentIndex(0);
    SciRelComp = 0;
    SciRelSci = 0;
    CompRelComp = 0;
    CompRelSci = 0;
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
    ui->table_Scientists->setColumnWidth(0,220);
    ui->table_Scientists->horizontalHeader()->setSectionResizeMode(QHeaderView::Fixed);
    ui->Input_RelationsScientistComputers->hideColumn(1);
    ui->table_RelationsComputerScientists->hideColumn(1);

    for(unsigned int i = 0; i < ScientistsDisplay.size(); i++)
    {
        Persons person_ = ScientistsDisplay.at(i);

        QString ScientistName = QString::fromStdString(person_.getName());
        QString ScientistGender = QString::fromStdString(person_.getGender());
        QString ScientistYoB = QString::fromStdString(person_.getYearOfBirth());
        QString ScientistYoD = QString::fromStdString(person_.getYearOfDeath());
        int ScientistID = person_.getID();
        QString ScId = QString::number(ScientistID);

        ui->table_Scientists->setItem(i, 0, new QTableWidgetItem (ScientistName));
        ui->table_Scientists->setItem(i, 1, new QTableWidgetItem(ScientistGender));
        ui->table_Scientists->setItem(i, 2, new QTableWidgetItem(ScientistYoB));
        ui->table_Scientists->setItem(i, 3, new QTableWidgetItem(ScientistYoD));
        ui->table_Scientists->setItem(i, 4,new QTableWidgetItem(ScId));
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
    ui->table_Computers->setColumnWidth(0,220);
    ui->table_Computers->horizontalHeader()->setSectionResizeMode(QHeaderView::Fixed);

    for(unsigned int i = 0; i < ComputersDisplay.size(); i++)
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
        }
        else
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

//Shows scientist relations with computers.
void MainMenu::displayScientistRelations()
{
    string PersonSearch = "";
    PersonSearch = ui->Input_RelationScienSearch->text().toStdString();
    ScientistsRelationDisplay = _domain.getPersonsSearch(PersonSearch);

    ui->table_RelationScientists->setSortingEnabled(false);
    ui->table_RelationScientists->clearContents();
    ui->table_RelationScientists->setRowCount(ScientistsRelationDisplay.size());
    ui->table_RelationScientists->horizontalHeader()->setVisible(true);
    ui->table_RelationScientists->verticalHeader()->setVisible(false);

    for(unsigned int i = 0; i < ScientistsRelationDisplay.size(); i++)
    {
        Persons person_ = ScientistsRelationDisplay.at(i);

        QString ScientistName = QString::fromStdString(person_.getName());

        ui->table_RelationScientists->setItem(i, 0, new QTableWidgetItem(ScientistName));
        ui->table_RelationScientists->setItem(i, 1, new QTableWidgetItem(QString::number(person_.getID())));

        ui->table_RelationScientists->hideColumn(1);
    }

    ui->table_RelationScientists->setSortingEnabled(true);

}

//Shows computer relations with scientists.
void MainMenu::displayComputersRelations()
{
    string ComputerSearch = "";

    ComputerSearch = ui->Input_RelationCompSearch->text().toStdString();

    ComputersRelationDisplay = _domain.getComputersSearch(ComputerSearch);

    ui->table_RelationComputers->setSortingEnabled(false);
    ui->table_RelationComputers->clearContents();
    ui->table_RelationComputers->setRowCount(ComputersRelationDisplay.size());
    ui->table_RelationComputers->horizontalHeader()->setVisible(true);
    ui->table_RelationComputers->verticalHeader()->setVisible(false);

    for(unsigned int i = 0; i < ComputersRelationDisplay.size(); i++)
    {
        Computers computer_ = ComputersRelationDisplay.at(i);

        QString ComputerName = QString::fromStdString(computer_.getCompName());

        ui->table_RelationComputers->setItem(i, 0, new QTableWidgetItem(ComputerName));
        ui->table_RelationComputers->setItem(i, 1, new QTableWidgetItem(QString::number(computer_.getCompID())));
        ui->table_RelationComputers->hideColumn(1);
    }

    ui->table_RelationComputers->setSortingEnabled(true);
}

//Displaying scientists for search
void MainMenu::on_Input_Search_Person_textChanged()
{
    displayScientists();
}
//Displaying computer for search
void MainMenu::on_Input_Search_Computer_textChanged()
{
    displayComputers();
}
//Adding a scientist
void MainMenu::on_pushButton_AddPerson_clicked()
{
    addScientist _addScientist;
    _addScientist.exec();

    displayScientists();
}

//User has to select a scientist to edit or remove
void MainMenu::on_table_Scientists_cellPressed(int row)
{
    ui->pushButton_RemovePerson->setEnabled(true);
    ui->pushButton_EditPerson->setEnabled(true);
    _row = row;
}

//Option to edit scientist.
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

//Option to edit computer.
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

//Option to remove scientist
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
    _domain.deleteConnections("ScientistID", ID);

    displayScientists();
}

//Option to add a computer
void MainMenu::on_pushButton_AddComputer_clicked()
{
    addComputer _addComputer;
    _addComputer.typeList();

    _addComputer.exec();

    displayComputers();
}

//User has to select a computer to edit or remove
void MainMenu::on_table_Computers_cellPressed(int row)
{
    ui->pushButton_RemoveComputer->setEnabled(true);
    ui->pushButton_EditComputer->setEnabled(true);
    _row = row;

}

//Option to remove computer selected
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
    _domain.deleteConnections("ComputerID", ID);

    displayComputers();
}

//Displaying relations of selected scientist
void MainMenu::on_Input_RelationScienSearch_textChanged()
{
    displayScientistRelations();
}

//Displaying relations of selected computer
void MainMenu::on_Input_RelationCompSearch_textChanged()
{
    displayComputersRelations();
}

//Selcting a computer to display connection to.
void MainMenu::on_table_RelationComputers_cellPressed(int row)
{
    _row = row;
    int ID = ui->table_RelationComputers->item(row,1)->text().toUInt();

    displaySecondtable_RelationScientists(ID);

    CompRelComp = ID;

    ui->pushButton_editCompRelation->setEnabled(false);
    ui->pushButton_removeCompRelation->setEnabled(false);
}

void MainMenu::on_table_RelationScientists_cellPressed(int row)
{    
    _row = row;
    int ID = ui->table_RelationScientists->item(row,1)->text().toUInt();

    displaySecondtable_RelationComputers(ID);

    SciRelSci = ID;

    ui->pushButton_editSciRelation->setEnabled(false);
    ui->pushButton_removeSciRelation->setEnabled(false);
}

void MainMenu::on_table_RelationsComputerScientists_cellPressed(int row)
{
    _row = row;
    int ID = ui->table_RelationsComputerScientists->item(row,1)->text().toUInt();

    CompRelSci = ID;

    if(CompRelComp != 0 && CompRelSci != 0)
    {
        ui->pushButton_editCompRelation->setEnabled(true);
        ui->pushButton_removeCompRelation->setEnabled(true);
    }
}

void MainMenu::on_Input_RelationsScientistComputers_cellPressed(int row)
{
    _row = row;
    int ID = ui->Input_RelationsScientistComputers->item(row,1)->text().toUInt();

    SciRelComp = ID;

    if(SciRelSci != 0 && SciRelComp != 0)
    {
        ui->pushButton_editSciRelation->setEnabled(true);
        ui->pushButton_removeSciRelation->setEnabled(true);
    }
}

void MainMenu::displaySecondtable_RelationComputers(int id)
{

    vector<Computers> comps = _domain.getScientistToComputer(id);

    ui->Input_RelationsScientistComputers->setSortingEnabled(false);
    ui->Input_RelationsScientistComputers->clearContents();
    ui->Input_RelationsScientistComputers->setRowCount(comps.size());
    ui->Input_RelationsScientistComputers->horizontalHeader()->setVisible(true);
    ui->Input_RelationsScientistComputers->verticalHeader()->setVisible(false);

    for(unsigned int i = 0; i < comps.size(); i++)
    {
        Computers computer_ = comps.at(i);
        QString ComputerName = QString::fromStdString(computer_.getCompName());

        ui->Input_RelationsScientistComputers->setItem(i, 0, new QTableWidgetItem(ComputerName));
        ui->Input_RelationsScientistComputers->setItem(i, 1, new QTableWidgetItem(QString::number(computer_.getCompID())));
        ui->Input_RelationsScientistComputers->hideColumn(1);
    }

    ui->Input_RelationsScientistComputers->setSortingEnabled(true);
}

void MainMenu::displaySecondtable_RelationScientists(int id)
{

    vector<Persons> persons = _domain.getComputerToScientist(id);

    ui->table_RelationsComputerScientists->setSortingEnabled(false);
    ui->table_RelationsComputerScientists->clearContents();
    ui->table_RelationsComputerScientists->setRowCount(persons.size());
    ui->table_RelationsComputerScientists->horizontalHeader()->setVisible(true);
    ui->table_RelationsComputerScientists->verticalHeader()->setVisible(false);
    ui->table_RelationsComputerScientists->hideColumn(1);
    for(unsigned int i = 0; i < persons.size(); i++)
    {
        Persons person = persons.at(i);
        QString name = QString::fromStdString(person.getName());

        ui->table_RelationsComputerScientists->setItem(i, 0, new QTableWidgetItem(name));
        ui->table_RelationsComputerScientists->setItem(i, 1, new QTableWidgetItem(QString::number(person.getID())));
        ui->table_RelationsComputerScientists->hideColumn(1);
    }

    ui->table_RelationsComputerScientists->setSortingEnabled(true);
}

//Editing scientist relations
void MainMenu::on_pushButton_editSciRelation_clicked()
{
    editRelation _editRelation;

    _editRelation.setIDs(SciRelSci, SciRelComp);
    _editRelation.fillComboBoxes();

    _editRelation.exec();

    displaySecondtable_RelationScientists(SciRelComp);

}

//Removing scientist relations
void MainMenu::on_pushButton_removeSciRelation_clicked()
{
    string RemovedComp = _domain.getSingleComputer(SciRelComp).getCompName();
    string RemovedPerson = _domain.getSinglePerson(SciRelSci).getName();
    QString QremovedComp = QString::fromStdString(RemovedComp);
    QString QremovedPerson = QString::fromStdString(RemovedPerson);
    QString removal = "About to remove\n" + QremovedComp + " from " + QremovedPerson + "\nAre you sure?";

    int ConfirmRemoval = QMessageBox::question(this,"Confirm" , removal);
    if(ConfirmRemoval == QMessageBox::No)
    {
        return;

    }

    _domain.removeRelation(SciRelSci,SciRelComp);
    displaySecondtable_RelationScientists(SciRelComp);
}

//Removing computer relations
void MainMenu::on_pushButton_removeCompRelation_clicked()
{
    string RemovedComp = _domain.getSingleComputer(CompRelComp).getCompName();
    string RemovedPerson = _domain.getSinglePerson(CompRelSci).getName();
    QString QremovedComp = QString::fromStdString(RemovedComp);
    QString QremovedPerson = QString::fromStdString(RemovedPerson);
    QString removal = "About to remove\n" + QremovedPerson + " from " + QremovedComp + "\nAre you sure?";

    int ConfirmRemoval = QMessageBox::question(this,"Confirm" , removal);
    if(ConfirmRemoval == QMessageBox::No)
    {
        return;

    }

    _domain.removeRelation(CompRelSci,CompRelComp);
    displaySecondtable_RelationComputers(CompRelSci);
}

void MainMenu::on_pushButton_addSciRelation_clicked()
{
    addRelations _addRelations;

    _addRelations.setIDs(SciRelSci, SciRelComp);
    _addRelations.fillComboBoxes();
    _addRelations.exec();

    displayComputersRelations();
    displayScientistRelations();
}

void MainMenu::on_pushButton_addCompRelation_clicked()
{
    addRelations _addRelations;

    _addRelations.setIDs(CompRelSci,CompRelComp);
    _addRelations.fillComboBoxes();
    _addRelations.exec();

    displayScientistRelations();
    displayComputersRelations();
}

void MainMenu::on_pushButton_editCompRelation_clicked()
{
    editRelation _editRelation;

    _editRelation.setIDs(CompRelSci, CompRelComp);
    _editRelation.fillComboBoxes();
    _editRelation.exec();

    displaySecondtable_RelationComputers(CompRelComp);
}

void MainMenu::on_Mainmenu_tabs_tabBarClicked(int index)
{
    if(index == 2)
    {
        displayScientistRelations();
        displayComputersRelations();
    }
}
