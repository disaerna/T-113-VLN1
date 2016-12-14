#ifndef MAINMENU_H
#define MAINMENU_H

#include "persons.h"
#include "computers.h"
#include "domain.h"

#include <QMainWindow>
#include <QWidget>
#include <QDialog>
#include <vector>

#include "ui_mainMenu.h"

namespace Ui {
class MainMenu;
}

class MainMenu : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainMenu(QWidget *parent = 0);
    ~MainMenu();

private slots:

//    void on_ButtonQuit_clicked();

//    void on_ButtonScientists_clicked();

//    void on_ButtonComputers_clicked();

    void on_Mainmenu_tabs_currentChanged(int index);
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

private:

    void displayScientists();
    void displayComputers();

    std::vector<Persons> ScientistsDisplay;
    std::vector<Computers> ComputersDisplay;


    Ui::MainMenu *ui;

    Domain _domain;



    int _row;
};

#endif // MAINMENU_H
