#ifndef MAINMENU_H
#define MAINMENU_H

#include "persons.h"
#include "computers.h"

#include "personsmenu.h"
#include "computersmenu.h"

#include <QMainWindow>
#include <QWidget>
#include <QDialog>

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
    void on_ButtonQuit_clicked();

    void on_ButtonScientists_clicked();

    void on_ButtonComputers_clicked();

private:
    Ui::MainMenu *ui;
    PersonsMenu *personsMenu;
    ComputersMenu *computersMenu;
};

#endif // MAINMENU_H
