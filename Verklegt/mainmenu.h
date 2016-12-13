#ifndef MAINMENU_H
#define MAINMENU_H

#include "persons.h"
#include "computers.h"
#include "domain.h"

#include "personsmenu.h"
#include "computersmenu.h"

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
    void MainMenu::DisplayScientists(vector<Persons> Person);
    ~MainMenu();

private slots:

//    void on_ButtonQuit_clicked();

//    void on_ButtonScientists_clicked();

//    void on_ButtonComputers_clicked();

    void on_Input_Search_Person_textChanged(const QString &arg1);

private:

    std::vector<Persons> Person;
    std::vector<Persons> PersonDisplay;

    Ui::MainMenu *ui;
    PersonsMenu *personsMenu;
    ComputersMenu *computersMenu;

    Domain _domain;
};

#endif // MAINMENU_H
