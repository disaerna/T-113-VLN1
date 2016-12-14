#include "editperson.h"
#include "ui_editperson.h"
#include <iostream>

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

void editPerson::setPath(const int &index)
{
    _index = index;
}

int editPerson::getPath()
{
    return _index;
}

void editPerson::initializeFields()
{
    Persons person;
    int index = getPath();
    qDebug() << index;
    person = _domain.getSinglePerson(index);

    int getID = person.getID();
    string getName = person.getName();
    string getGender = person.getGender();
    string getYOB = person.getYearOfBirth();
    string getYOD = person.getYearOfDeath();


    QString qName = QString::fromStdString(getName);
    QString qYOB = QString::fromStdString(getYOB);
    QString qYOD = QString::fromStdString(getYOD);
    qDebug() << qYOD;


    ui->nameEdit->setText(qName);

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
        ui->aliveButton->setChecked(true);
        ui->dodEdit->setText("-");
    }
    else if(getYOD != "-")
    {
        ui->deadButton->setChecked(true);
        ui->dodEdit->setText(qYOD);
    }
}


void editPerson::on_submitButton_clicked()
{
    initializeFields();
}
