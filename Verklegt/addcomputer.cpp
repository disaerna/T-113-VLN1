#include "addcomputer.h"
#include "ui_addcomputer.h"
#include "addscientist.h"
#include "ui_addscientist.h"
#include <iostream>
#include <QMessageBox>
#include <QButtonGroup>
#include <QFileDialog>
#include <QDebug>


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
        messageBox.critical(0,"Error", "Year built must be four integers!");
        messageBox.setFixedSize(500,200);
        valid = false;
    }
    string type = ui->typeDropDown->currentText().toStdString();

    bool success;

    if(ui->yesButton->isChecked())
    {
        success = true;
    }
    if(ui->noButton->isChecked())
    {
        success = false;
    }

    if(valid == true)
    {
        Computers computer;
    computer.setComputers(1, addName, addDOB, type, success);
    _domain.addComputer(computer);

    QString prompt = "Do you wish to add another Computer? ";

    int askingUser = QMessageBox::question(this, "Add another computer", prompt);
    if (askingUser == QMessageBox::No)
    {
        this->done(0);
    }

    }


}

void addComputer::on_typeDropDown_activated()
{
    ui->typeDropDown->activateWindow();


}

void addComputer::typeList()
{
    ui->typeDropDown->activateWindow();
    vector<string> types = _domain.getComputersTypes();
    qDebug() << types.size();
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

void addComputer::on_cancelButton_clicked()
{
    this->done(0);
}
