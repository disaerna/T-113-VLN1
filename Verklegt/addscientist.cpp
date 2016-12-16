#include "addscientist.h"
#include "ui_addscientist.h"
#include <iostream>
#include <QMessageBox>
#include <QButtonGroup>
#include <QFileDialog>

addScientist::addScientist(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::addScientist)
{
    ui->setupUi(this);
}

addScientist::~addScientist()
{
    delete ui;
}

void addScientist::on_okButton_clicked()
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
    else if(_domain.validNameCheck(addName))
    {
        messageBox.critical(0,"Error", "Name must be alphabetical characters!");
        messageBox.setFixedSize(500,200);
        valid = false;
    }
    string addGender = "";

    if(ui->maleButton->isChecked())
    {
        addGender = "Male";
    }
    else if(ui->femaleButton->isChecked())
    {
        addGender = "Female";
    }

    string addDOB = ui->yobInput->text().toStdString();
    if(ui->yobInput->text().isEmpty())
    {
        messageBox.critical(0,"Error", "Birth year cannot be empty!");
        messageBox.setFixedSize(500,200);
        valid = false;
    }
    else if(_domain.validYearCheck(addDOB))
    {
        messageBox.critical(0,"Error", "Birth year must be four integers!");
        messageBox.setFixedSize(500,200);
        valid = false;
    }

    string addDOD = "";


    if(ui->aliveButton->isChecked())
    {
        addDOD = "-";
    }
    else if(ui->deadButton->isChecked())
    {
        addDOD = ui->yodInput->text().toStdString();
        if(ui->yodInput->text().isEmpty())
        {
            messageBox.critical(0,"Error", "Death year cannot be empty!");
            messageBox.setFixedSize(500,200);
            valid = false;
        }
        else if (_domain.validDeathYearCheck((addDOB), (addDOD))) {
            messageBox.critical(0,"Error","Death year must be four integers!");
            messageBox.setFixedSize(500,200);
            valid = false;

        }
    }


    if(valid == true)
    {
        Persons person;
        person.setPersons(1, addName, addGender, addDOB, addDOD);
        int returnedId = _domain.addPersons(person);

        QString prompt = "Do you wish to add another person? ";

        int askingUser = QMessageBox::question(this, "Add another person", prompt);
        if (askingUser == QMessageBox::No)
        {
            this->done(returnedId);
        }
    }
}


void addScientist::on_cancelButton_clicked()
{
    this->done(0);
}

/*
void addScientist::on_chooseImage_clicked()
{
    QString filename = QFileDialog::getOpenFileName(this, tr("Choose"), "", tr("Images(*.png *.jpg *.bmp *.gif)"));

    if(QString::compare(filename, QString()) != 0)
    {
        QImage image;
        bool valid = image.load(filename);

        if(valid)
        {
            ui->image->setPixmap(QPixmap::fromImage(image));
        }
        else
        {
            //error
        }
    }
}
*/

void addScientist::on_deadButton_clicked()
{
    ui->yodInput->setDisabled(0);
}

void addScientist::on_aliveButton_clicked()
{
    ui->yodInput->setDisabled(1);
}
