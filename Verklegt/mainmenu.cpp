#include "mainmenu.h"
#include "ui_mainmenu.h"

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

void MainMenu::on_ButtonScientists_clicked()
{
    personsMenu = new PersonsMenu(this);
    personsMenu->setWindowTitle("Scientists");
    personsMenu->setMinimumSize(500,300);
    personsMenu->setModal(true);
    personsMenu->exec();

}
