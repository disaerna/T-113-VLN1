#ifndef MAINMENU_H
#define MAINMENU_H
#include "ui_mainMenu.h"
#include "persons.h"
#include "computers.h"
#include "domain.h"
#include "addscientist.h"
#include "addcomputer.h"
#include "editperson.h"
#include "editcomputer.h"
#include "editrelation.h"
#include "addrelations.h"
#include <QMainWindow>
#include <QWidget>
#include <QDialog>
#include <vector>
#include <QMessageBox>

namespace Ui
{
class MainMenu;
}

class MainMenu : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainMenu(QWidget *parent = 0);
    ~MainMenu();

    void displaySecondtable_RelationComputers(int id);
    void displaySecondtable_RelationScientists(int id);

private slots:

    void on_Input_Search_Person_textChanged();

    void on_pushButton_AddPerson_clicked();

    void on_table_Scientists_cellPressed(int row);

    void on_pushButton_EditPerson_clicked();

    int getRow();

    void on_pushButton_RemovePerson_clicked();

    void on_pushButton_AddComputer_clicked();
    void on_Input_Search_Computer_textChanged();

    void on_pushButton_RemoveComputer_clicked();

    void on_table_Computers_cellPressed(int row);

    void on_pushButton_EditComputer_clicked();

    void on_Input_RelationScienSearch_textChanged();

    void on_Input_RelationCompSearch_textChanged();

    void on_table_RelationComputers_cellPressed(int row);
    
    void on_table_RelationScientists_cellPressed(int row);
    void on_table_RelationsComputerScientists_cellPressed(int row);

    void on_Input_RelationsScientistComputers_cellPressed(int row);

    void on_pushButton_editSciRelation_clicked();

    void on_pushButton_removeSciRelation_clicked();

    void on_pushButton_removeCompRelation_clicked();

    void on_pushButton_addSciRelation_clicked();

    void on_pushButton_addCompRelation_clicked();

    void on_pushButton_editCompRelation_clicked();

    void on_Mainmenu_tabs_tabBarClicked(int index);

private:

    void displayScientists();
    void displayComputers();
    void displayScientistRelations();
    void displayComputersRelations();    

    std::vector<Persons> ScientistsDisplay;
    std::vector<Persons> ScientistsRelationDisplay;
    std::vector<Computers> ComputersDisplay;
    std::vector<Computers> ComputersRelationDisplay;
    int SciRelSci;
    int SciRelComp;

    int CompRelSci;
    int CompRelComp;


    Ui::MainMenu *ui;

    Domain _domain;

    int _row;
};

#endif // MAINMENU_H
