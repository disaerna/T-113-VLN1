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
    int currentlySelectedComputerIndex = ui->list_computer->currentIndex().row();
            //= ui->list_computers->currentIndex().row();
    //Computers currentlySelectedComputer = currentlyDisplayedComputer.at(currentlySelectedComputerIndex);
    vector<Computers> computer = _domain.getComputers();
    int ID = computer[currentlySelectedComputerIndex].getCompID();
    bool success = _domain.deleteComputerFromDatabase(ID);

    if(success)
    {
        displayAllComputers();
        ui->Button_remove_computer->setEnabled(false);

    }

    else
    {
       // QMessageBox::warning(this("Error, not able to remove this scientist");
        // Sorry, not able to remove selected scientist
    }
}

void ComputersMenu::displayAllComputers()
{
    vector<Computers> comp = _domain.getComputers();
    displayComputer(comp);
}

void ComputersMenu::displayComputer(vector<Computers> comp)
{
    ui->list_computer->clear();

    for(unsigned int i = 0; i<comp.size();i++)
    {
        Computers currentComputer = comp.at(i);

        ui->list_computer->addItem(QString::fromStdString(currentComputer.getCompName()));
    }

}
