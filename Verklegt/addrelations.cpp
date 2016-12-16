#include "addrelations.h"
#include "ui_addrelations.h"

addRelations::addRelations(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::addRelations)
{
    ui->setupUi(this);
}

addRelations::~addRelations()
{
    delete ui;
}
void addRelations::setIDs(int sci, int comp)
{
    _sci = sci;
    _comp = comp;
}

void addRelations::fillComboBoxes()
{
    vector<Persons> scientists = _domain.getPersons();
    vector<Computers> computers = _domain.getComputers();

    for(size_t i=0; i<scientists.size(); i++)
    {
        QString Qsci = QString::fromStdString(scientists[i].getName());
        ui->comboBox_scientist->addItem(Qsci);
    }

    for(size_t i=0; i<computers.size(); i++)
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

void addRelations::on_pushButton_submit_clicked()
{
        int currentSciIndex =  ui->comboBox_scientist->currentIndex();
        int currentCompIndex = ui->comboBox_computer->currentIndex();

        Persons Scientist;
        vector<Persons> allScientists = _domain.getPersons();
        QString personText = ui->comboBox_scientist->itemText(currentSciIndex);
        int newSci = 0;
        for(size_t i =0;i<allScientists.size();i++){

           if(personText.toStdString() == allScientists[i].getName()){
               newSci = allScientists[i].getID();
           }
        }

        Computers comp;
        vector<Computers> allComputers = _domain.getComputers();
        QString computersText = ui->comboBox_computer->itemText(currentCompIndex);
        int newComp = 0;
        for(size_t i =0;i<allComputers.size();i++){

           if(computersText.toStdString() == allComputers[i].getCompName()){
               newComp = allComputers[i].getCompID();
           }
        }

          qDebug() << QString::number(_sci) <<" "<<  QString::number(_comp) <<" "<< QString::number(newSci) <<" "<< QString::number(newComp);
        _domain.connectComputersAndScientists(newSci,newComp);
        this->done(0);
}
