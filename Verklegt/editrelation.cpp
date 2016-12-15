#include "editrelation.h"
#include "ui_editrelation.h"

editRelation::editRelation(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::editRelation)
{
    ui->setupUi(this);
}

editRelation::~editRelation()
{
    delete ui;
}
