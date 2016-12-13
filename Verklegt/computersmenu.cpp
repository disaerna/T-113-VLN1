#include "computersmenu.h"
#include "ui_computersmenu.h"

ComputersMenu::ComputersMenu(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ComputersMenu)
{
    ui->setupUi(this);
}

ComputersMenu::~ComputersMenu()
{
    delete ui;
}

void ComputersMenu::on_list_computer_clicked(const QModelIndex &index)
{
    ui->Button_remove_computer->setEnabled(true);
}

void ComputersMenu::on_Button_remove_computer_clicked()
{
    int currentlySelectedComputerIndex = ui->list_computers->currentIndex().row();
    Persons currentlySelectedComputer = currentlyDisplayedComputer.at(currentlySelectedComputerIndex);

    bool success = _domain.deleteComputerFromDatabase(currentlySelectedComputer);

    if(success)
    {
        displayAllScientists();
        ui->Button_remove_computer->setEnabled(false);

    }

    else
    {
        QMessageBox::warning(this("Error, not able to remove this scientist");
        // Sorry, not able to remove selected scientist
    }
}

void displayAllComputers()
{
    vector<Computers> comp = _domain.getComputers("name", true);
    displayScientists(person);
}

void displayComputer(vector<Computers> comp)
{
    ui->list_computer->clear();

    for(unsigned int i = 0; i<comp.size();i++)
    {
        Computers currentComputer = comp.at(i);

        ui->list_computer->addItem(QString::fromStdString(currentComputer.getName()));
    }


}
