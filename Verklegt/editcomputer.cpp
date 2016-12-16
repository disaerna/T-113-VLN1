#include "editcomputer.h"
#include "ui_editcomputer.h"

#include <QMessageBox>

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

    typeList();

    QString textToFind = qType;
    int typeIndex = ui->typeSelection->findText(qType);
    ui->typeSelection->setCurrentIndex(typeIndex);

    if(getBuilt == true)
    {
        ui->yesButton->setChecked(true);
    }
    else if(getBuilt == false)
    {
        ui->noButton->setChecked(true);
    }
}

void editComputer::typeList()
{
    //ui->typeSelection->activateWindow();
    vector<string> types = _domain.getComputersTypes();
    ui->typeSelection->clear();
    for(unsigned int i=0; i<types.size(); i++)
    {
        QString Qtype = QString::fromStdString(types[i]);
        ui->typeSelection->addItem(Qtype);
    }

    ui->typeSelection->addItem("Other");
}

void editComputer::on_submitButton_clicked()
{
    int index = getPath();

    string editName = ui->nameEdit->text().toStdString();

    string editYearBuilt = ui->buildEdit->text().toStdString();

    string editType = ui->typeSelection->currentText().toStdString();
    if(ui->typeSelection->currentText().toStdString() == "Other")
    {
        editType = ui->newTypeInput->text().toStdString();
    }

    bool editBuilt;
    if(ui->yesButton->isChecked())
    {
        editBuilt = true;
        qDebug() << "TRUE";
    }
    else if(ui->noButton->isChecked())
    {
        editBuilt = false;
        qDebug() << "FALSE";
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

void editComputer::on_typeSelection_currentIndexChanged(const QString &arg1)
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
