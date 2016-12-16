#include "addcomputer.h"
#include "ui_addcomputer.h"

addComputer::addComputer(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::addComputer)
{
    ui->setupUi(this);
}

addComputer::~addComputer()
{
    delete ui;
}

//Function to confirm adding a computer.
void addComputer::on_submitButton_clicked()
{
    QMessageBox messageBox;
    bool valid = true;

    string addName = ui->nameInput->text().toStdString();
    if(ui->nameInput->text().isEmpty())
    {
        messageBox.critical(0,"Error", "Name cannot be empty!");
        messageBox.setFixedSize(500,200);
        valid = false;
    }

    string addDOB = ui->yobInput->text().toStdString();
    if(ui->yobInput->text().isEmpty())
    {
        messageBox.critical(0,"Error", "Year built cannot be empty!");
        messageBox.setFixedSize(500,200);
        valid = false;
    }
    else if(_domain.validYearCheck(addDOB))
    {
        messageBox.critical(0,"Error", "Year built must be valid and four integers!");
        messageBox.setFixedSize(500,200);
        valid = false;
    }

    string type = ui->typeDropDown->currentText().toStdString();
    if(ui->typeDropDown->currentText().toStdString() == "Other")
    {
        type = ui->newTypeInput->text().toStdString();
    }

    bool success;

    if(ui->yesButton->isChecked())
    {
        success = true;
    }
    if(ui->noButton->isChecked())
    {
        success = false;
    }
    if(!ui->yesButton->isChecked() && !ui->noButton->isChecked())
    {
        messageBox.critical(0,"Error", "You must select either yes or no if built successful");
        messageBox.setFixedSize(500,200);
        valid = false;
    }

    if(valid == true)
    {
        Computers computer;
        computer.setComputers(1, addName, addDOB, type, success);
        int returnedId = _domain.addComputer(computer);

        QString prompt = "Do you wish to add another Computer? ";

        int askingUser = QMessageBox::question(this, "Add another computer", prompt);
        if (askingUser == QMessageBox::No)
        {
            this->done(returnedId);
        }
    }
}

//Show options of computer types user can choose from.
void addComputer::on_typeDropDown_activated()
{
    ui->typeDropDown->activateWindow();
}

//Options of computer types user can choose from.
void addComputer::typeList()
{
    ui->typeDropDown->activateWindow();
    vector<string> types = _domain.getComputersTypes();
    ui->typeDropDown->clear();
    for(unsigned int i=0; i<types.size(); i++)
    {
        QString Qtype = QString::fromStdString(types[i]);
        ui->typeDropDown->addItem(Qtype);
    }

    ui->typeDropDown->addItem("Other");
}

void addComputer::on_typeDropDown_currentIndexChanged(const QString &arg1)
{
    if(arg1 == "Other")
    {
        ui->newTypeInput->setDisabled(0);
    }
    else
    {
        ui->newTypeInput->setDisabled(1);
    }
}

//If user wants to cancel adding a computer.
void addComputer::on_cancelButton_clicked()
{
    this->done(0);
}
