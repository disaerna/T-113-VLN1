#include "editperson.h"
#include "ui_editperson.h"
#include <iostream>
#include <QMessageBox>

editPerson::editPerson(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::editPerson)
{
    ui->setupUi(this);
}

editPerson::~editPerson()
{
    delete ui;
}
//User input.
void editPerson::setPath(const int &index)
{
    _index = index;
}
//Getting the users input.
int editPerson::getPath()
{
    return _index;
}
//Showing the persons information to the user when editing.
void editPerson::initializeFields()
{
    Persons person;
    int index = getPath();
    person = _domain.getSinglePerson(index);
    string getName = person.getName();
    string getGender = person.getGender();
    string getYOB = person.getYearOfBirth();
    string getYOD = person.getYearOfDeath();

    QString qName = QString::fromStdString(getName);
    QString qYOB = QString::fromStdString(getYOB);
    QString qYOD = QString::fromStdString(getYOD);
    qDebug() << qYOD;

    ui->nameEdit->setText(qName);

    qDebug() << qName;

    if(getGender == "Male")
    {
        ui->maleButton->setChecked(true);
    }
    else if(getGender == "Female")
    {
        ui->femaleButton->setChecked(true);
    }

    ui->dobEdit->setText(qYOB);

    if(getYOD == "-")
    {
        ui->deadButton->setChecked(true); // If alive
        //ui->dodEdit->setText("-");
        ui->dodEdit->setDisabled(1);
    }
    else if(getYOD != "-")
    {
        ui->aliveButton->setChecked(true); // If dead
        ui->dodEdit->setText(qYOD);
    }
}

//Submiting the users edited changes.
void editPerson::on_submitButton_clicked()
{
    int index = getPath();
    bool valid = true;
    QMessageBox messageBox;


    string editName = ui->nameEdit->text().toStdString();
    if(ui->nameEdit->text().isEmpty() || _domain.validComputerNameCheck(editName))
    {
        messageBox.critical(0,"Error", "Name cannot be empty!");
        messageBox.setFixedSize(500,200);
        valid = false;
    }
    else if (_domain.validNameCheck(editName))
    {
        messageBox.critical(0,"Error", "Name must be alphabetical characters!");
        messageBox.setFixedSize(500,200);
        valid = false;
    }

    string editGender = "";
    if(ui->maleButton->isChecked())
    {
        editGender = "Male";
    }
    else if(ui->femaleButton->isChecked())
    {
        editGender = "Female";
    }

    string editDOB = ui->dobEdit->text().toStdString();
    if(_domain.validYearCheck(editDOB) )
    {
        messageBox.critical(0,"Error", "Year of birth must be valid and four integers!");
        messageBox.setFixedSize(500,200);
        valid = false;
    }
    else if(ui->dobEdit->text().isEmpty())
    {
        messageBox.critical(0,"Error", "Year of birth cannot be empty!");
        messageBox.setFixedSize(500,200);
        valid = false;
    }

    string editDOD = "";

    if(ui->aliveButton->isChecked()) // If dead
    {

        editDOD = ui->dodEdit->text().toStdString(); // Alive means he is deceased
        if(ui->dodEdit->text().isEmpty())
        {
            messageBox.critical(0,"Error", "Year of death cannot be empty!");
            messageBox.setFixedSize(500,200);
            valid = false;
        }
        else if(_domain.validDeathYearCheck(editDOB, editDOD))
        {
            messageBox.critical(0,"Error", "Year of death must be valid and four integers!");
            messageBox.setFixedSize(500,200);
            valid = false;
        }
    }
    else if(ui->deadButton->isChecked()) // If alive
    {
        editDOD = "-";
    }
    if( valid == true)
    {
        QString qName = QString::fromStdString(editName);
        QString prompt = "Are you sure you want to edit " + qName + "?";
        int askingUser = QMessageBox::question(this, "Edit person", prompt);
        if (askingUser == QMessageBox::No)
        {
            this->done(0);
        }
        else
        {
            _domain.updatePerson(index, editName, editGender, editDOB, editDOD);

            this->done(0);
        }

    }

}
//Canceling users edited changes.
void editPerson::on_cancelButton_clicked()
{
    this->done(0);
}

void editPerson::on_aliveButton_clicked()
{
    ui->dodEdit->setEnabled(1);
}


void editPerson::on_deadButton_clicked()
{
    ui->dodEdit->setEnabled(0);
}
