#include "computersmenu.h"
#include "ui_computersmenu.h"

ComputersMenu::ComputersMenu(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ComputersMenu)
{
    ui->setupUi(this);
}

ComputersMenu::~ComputersMenu()
{
    delete ui;
}
