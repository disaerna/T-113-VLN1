#include "personsmenu.h"
#include "ui_personsmenu.h"

#include <QMessageBox>


PersonsMenu::PersonsMenu(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PersonsMenu)
{
    ui->setupUi(this);
}

PersonsMenu::~PersonsMenu()
{
    delete ui;
}

void PersonsMenu::on_Scientists_mainmenu_activated(const QModelIndex &index)
{

}

void PersonsMenu::on_list_scientists_clicked(const QModelIndex &index)
{
    ui->Button_remove_scientist->setEnabled(true);
}

void PersonsMenu::on_Button_remove_scientist_clicked()
{
    int currentlySelectedScientistIndex = ui->list_scientists->currentIndex().row();
    Persons currentlySelectedScientist = currentlyDisplayedScientists.at(currentlySelectedScientistIndex);

    bool success = _domain.deletePersonFromFile(currentlySelectedScientist);

    if(success)
    {
        displayAllScientists();
        ui->Button_remove_scientist->setEnabled(false);

    }

    else
    {
        QMessageBox::information(this, tr("Error"), tr("Error not able to remove this scientist"));
        // Sorry, not able to remove selected scientist
    }
}

void displayAllScientists()
{
    vector<Persons> person = _domain.getPersons();
    displayScientists(person);
}
/*
void displayScientist(std::vector<Persons> person)
{
    ui->list_scientists->clear();

    for(unsigned int i = 0; i<person.size();i++)
    {
        Persons currentPerson = person.at(i);

        ui->list_scientists->addItem(QString::fromStdString(currentPerson.getName()));
    }

}
*/
