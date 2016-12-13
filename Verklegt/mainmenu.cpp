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

void MainMenu::on_ButtonQuit_clicked()
{
    close();
    qApp->quit();
}

void MainMenu::on_ButtonScientists_clicked()
{
    personsMenu = new PersonsMenu(this);
    personsMenu->setModal(true);
    personsMenu->exec();

}

void MainMenu::on_ButtonComputers_clicked()
{
    computersMenu = new ComputersMenu(this);
    computersMenu->setModal(true);
    computersMenu->exec();
}
