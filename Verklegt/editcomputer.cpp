#include "editcomputer.h"
#include "ui_editcomputer.h"

editComputer::editComputer(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::editComputer)
{
    ui->setupUi(this);
}

editComputer::~editComputer()
{
    delete ui;
}

void editComputer::setPath(const int &index)
{
    _index = index;
}

int editComputer::getPath()
{
    return _index;
}

void editComputer::initializeFields()
{
    Computers Computer;
    int index = getPath();
    Computer = _domain.getSingleComputer(index);
    string getName = Computer.getCompName();
    string getYearBuilt = Computer.getCompYearBuild();
    string getType = Computer.getCompType();
    bool getBuilt = Computer.getCompBuilt();


    QString qName = QString::fromStdString(getName);
    QString qYearBuilt = QString::fromStdString(getYearBuilt);
    QString qType = QString::fromStdString(getType);
    //qDebug() << qYOD;


    ui->nameEdit->setText(qName);
    ui->buildEdit->setText(qYearBuilt);
    //qDebug() << qName;

    if(getType == "Analog")
    {
        ui->typeSelection->setView("Analog");
    }
    else if(getType == "Electronic")
    {
        ui->typeSelection->setView("Electronic");
    }
    else if(getType == "Mechatronic")
    {
        ui->typeSelection->setView("Mechatronic");
    }
    else if(getType == "Micro")
    {
        ui->typeSelection->setView("Micro");
    }


    if(getBuilt == true)
    {
        ui->yesButton->setChecked(true);
    }
    else if(getBuilt == false)
    {
        ui->noButton->setChecked(true);
    }
}

void editComputer::on_submitButton_clicked()
{
    int index = getPath();

    string editName = ui->nameEdit->text().toStdString();

    string editYearBuilt = ui->buildEdit->text().toStdString();

    string editType = "";
    if(ui->typeSelection->text("Analog"))
    {
        editGender = "Analog";
    }
    else if(ui->typeSelection->text("Electronic"))
    {
        editGender = "Electronic";
    }
    else if(ui->typeSelection->text("Mechatronic"))
    {
        editGender = "Mechatronic";
    }
    else if(ui->typeSelection->text("Micro"))
    {
        editGender = "Micro";
    }



    bool editBuilt;
    if(ui->yesButton->isChecked())
    {
        editBuilt = true;
    }
    else if(ui->noButton->isChecked())
    {
        editBuilt = false;
    }

    QString qName = QString::fromStdString(editName);
    QString prompt = "Are you sure you want to edit " + qName + "?";
    int askingUser = QMessageBox::question(this, "Edit computer", prompt);
    if (askingUser == QMessageBox::No)
    {
        this->done(0);
    }

    _domain.updateComputer(index, editName, editYearBuilt, editType, editBuilt);

    this->done(0);
}

void editComputer::on_cancelButton_clicked()
{
    this->done(0);
}
