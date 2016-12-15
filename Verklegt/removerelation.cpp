#include "removerelation.h"
#include "ui_removerelation.h"

removeRelation::removeRelation(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::removeRelation)
{
    ui->setupUi(this);
}

removeRelation::~removeRelation()
{
    delete ui;
}
