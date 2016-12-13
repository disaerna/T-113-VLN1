#include "personsmenu.h"
#include "ui_personsmenu.h"

PersonsMenu::PersonsMenu(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PersonsMenu)
{
    ui->setupUi(this);
}

PersonsMenu::~PersonsMenu()
{
    delete ui;
}

void PersonsMenu::on_listWidget_activated(const QModelIndex &index)
{

}

void PersonsMenu::on_button_OK_Cancel_accepted()
{
    QListWidgetItem *item = ui->listWidget->currentItem();
    int row = ui->listWidget->row(item); // skilar í hvaða röð hann er
    qDebug() << row;
    ui->label->setText("MR.T");

    if(row == 0)
    {
        //kalla í add fall

    }
    if(row == 1)
    {

    }
}
