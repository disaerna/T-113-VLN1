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
        ui->deadButton->setChecked(true);
        ui->dodEdit->setText("-");
    }
    else if(getYOD != "-")
    {
        ui->aliveButton->setChecked(true);
        ui->dodEdit->setText(qYOD);
    }
}

//Submiting the users edited changes.
void editPerson::on_submitButton_clicked()
{
    int index = getPath();

    string editName = ui->nameEdit->text().toStdString();

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

    string editDOD = "";
    if(ui->aliveButton->isChecked())
    {
        editDOD = ui->dodEdit->text().toStdString(); // Alive means he is deceased
    }
    else if(ui->deadButton->isChecked())
    {
        editDOD = "-";
    }

    QString qName = QString::fromStdString(editName);
    QString prompt = "Are you sure you want to edit " + qName + "?";
    int askingUser = QMessageBox::question(this, "Edit person", prompt);
    if (askingUser == QMessageBox::No)
    {
        this->done(0);
    }

    _domain.updatePerson(index, editName, editGender, editDOB, editDOD);

    this->done(0);
}
//Canceling users edited changes.
void editPerson::on_cancelButton_clicked()
{
    this->done(0);
}
