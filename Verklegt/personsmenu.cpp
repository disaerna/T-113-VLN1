#include "personsmenu.h"
#include "ui_personsmenu.h"

PersonsMenu::PersonsMenu(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PersonsMenu)
{
    ui->setupUi(this);
}

PersonsMenu::~PersonsMenu()
{
    delete ui;
}
