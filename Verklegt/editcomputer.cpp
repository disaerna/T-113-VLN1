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

}

void editComputer::on_submitButton_clicked()
{
    int index = getPath();

    string editName = ui->nameEdit->text().toStdString();


}

void editComputer::on_cancelButton_clicked()
{
    this->done(0);
}
