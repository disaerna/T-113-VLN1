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
void editRelation::setIDs(int sci, int comp)
{
    _sci = sci;
    _comp = comp;
}
//Set information for user.
void editRelation::fillComboBoxes()
{
    vector<Persons> scientists = _domain.getPersons();
    vector<Computers> computers = _domain.getComputers();

    for(unsigned int i=0; i<scientists.size(); i++)
    {
        QString Qsci = QString::fromStdString(scientists[i].getName());
        ui->comboBox_scientist->addItem(Qsci);
    }

    for(unsigned int i=0; i<computers.size(); i++)
    {
        QString Qcomp = QString::fromStdString(computers[i].getCompName());
        ui->comboBox_computer->addItem(Qcomp);
    }
    QString findSciID = QString::fromStdString(_domain.getSinglePerson(_sci).getName());
    int sciIndex = ui->comboBox_scientist->findText(findSciID);
    ui->comboBox_scientist->setCurrentIndex(sciIndex);
    QString findCompID = QString::fromStdString(_domain.getSingleComputer(_comp).getCompName());
    int compIndex = ui->comboBox_computer->findText(findCompID);
    ui->comboBox_computer->setCurrentIndex(compIndex);
}
//Submiting users edited relation changes.
void editRelation::on_pushButton_submit_clicked()
{
        int currentSciIndex =  ui->comboBox_scientist->currentIndex();
        int currentCompIndex = ui->comboBox_computer->currentIndex();

        Persons Scientist;
        vector<Persons> allScientists = _domain.getPersons();
        QString personText = ui->comboBox_scientist->itemText(currentSciIndex);
        int newSci = 0;
        for(unsigned int i =0;i<allScientists.size();i++){

           if(personText.toStdString() == allScientists[i].getName()){
               newSci = allScientists[i].getID();
           }
        }

        Computers comp;
        vector<Computers> allComputers = _domain.getComputers();
        QString computersText = ui->comboBox_computer->itemText(currentCompIndex);
        int newComp = 0;
        for(unsigned int i =0;i<allComputers.size();i++){

           if(computersText.toStdString() == allComputers[i].getCompName()){
               newComp = allComputers[i].getCompID();
           }
        }

          qDebug() << QString::number(_sci) <<" "<<  QString::number(_comp) <<" "<< QString::number(newSci) <<" "<< QString::number(newComp);
        _domain.updateRelations(_sci,_comp,newSci,newComp);

        this->done(0);

}

void editRelation::on_pushButton_cancel_clicked()
{
    this->done(0);
}
