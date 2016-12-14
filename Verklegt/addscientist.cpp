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
    string addName = ui->nameInput->text().toStdString();

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

    string addDOD = "";
    if(ui->aliveButton->isChecked())
    {
        addDOD = ui->yodInput->text().toStdString();
    }
    else if(ui->deadButton->isChecked())
    {
        addDOD = "-";
    }

    Persons person;
    person.setPersons(1, addName, addGender, addDOB, addDOD);
    _domain.addPersons(person);

    QString prompt = "Do you wish to add another person? ";

    int askingUser = QMessageBox::question(this, "Add another person", prompt);
    if (askingUser == QMessageBox::No)
    {
        this->done(0);
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
