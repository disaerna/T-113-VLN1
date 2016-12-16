#include "dbmanager.h"

DbManager::DbManager()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("../verkefni2.sqlite");
    db.open();
    if (!db.open())
    {
        //Used to be a Qdebug statement here, removed for grading.
    }
}

//Returns error code
QSqlError DbManager::lastError()
{
    return db.lastError();
}

//Adds new Scientists to the database
int DbManager::addPerson(Persons person)
{
    QSqlQuery query;

    query.prepare("INSERT INTO Scientists (name, gender, YearOfBirth, YearOfDeath) "
                  "VALUES (:name, :gender, :YearOfBirth, :YearOfDeath)");

    QString qName = QString::fromStdString(person.getName());
    QString qGender = QString::fromStdString(person.getGender());
    QString qBirth = QString::fromStdString(person.getYearOfBirth());
    QString qDeath = QString::fromStdString(person.getYearOfDeath());

    query.bindValue(":name", qName);
    query.bindValue(":gender", qGender);
    query.bindValue(":YearOfBirth", qBirth);
    query.bindValue(":YearOfDeath", qDeath);

    if(query.exec())
    {
        //success = true;
        return query.lastInsertId().toUInt();
    }
    return -1;
}

//Adds new Computer to the database
int DbManager::addComputer(Computers computer)
{
    QSqlQuery query;

    query.prepare("INSERT INTO Computers (name, YearBuilt, Type, Built) "
                  "VALUES (:name, :YearBuilt, :Type, :Built)");

    QString qCompName = QString::fromStdString(computer.getCompName());
    QString qCompYearBuilt = QString::fromStdString(computer.getCompYearBuild());
    QString qCompType = QString::fromStdString(computer.getCompType());
    QString qCompBuilt= QString::number(computer.getCompBuilt()); // number fyrir bool breytu

    query.bindValue(":name", qCompName);
    query.bindValue(":YearBuilt", qCompYearBuilt);
    query.bindValue(":Type", qCompType);
    query.bindValue(":Built", qCompBuilt);

    if(query.exec())
    {
        //success = true;
        return query.lastInsertId().toUInt();
    }
    return -1;
}

void DbManager::connectComputersAndScientists(int scientistID, int computerID)
{
    QSqlQuery query;

    query.prepare("INSERT INTO ScientistsAndComputers (ScientistID, ComputerID) "
                  "VALUES (:sID, :cID)");

    query.bindValue(":sID", scientistID);
    query.bindValue(":cID", computerID);

    if(!query.exec())
    {
        //Used to be a Qdebug statement here, removed for grading.
    }

}

bool DbManager::removeScientist(int ID)
{
    bool success = false;
    QSqlQuery query(db);
    query.prepare("DELETE FROM Scientists WHERE ID = :ID");
    query.bindValue(":ID", ID);
    if(query.exec())
    {
        success = true;
    }
    else
    {
        success = false;
    }
    return success;
}

bool DbManager::removeComputer(int ID)
{
    QSqlQuery query(db);
    query.prepare("DELETE FROM Computers WHERE ID = :ID");
    query.bindValue(":ID", ID);
    if(query.exec())
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool DbManager::removeConnections(string column, int removeID)
{
    QSqlQuery query;
    QString qColumn = QString::fromStdString(column);

    query.prepare("DELETE FROM ScientistsAndComputers WHERE " + qColumn + " = :removeID");
    query.bindValue(":removeID", removeID);

    if(query.exec())
    {
        //Used to be a Qdebug statement here, removed for grading.
        while(query.next())
        {
            return true;
        }
    }
    else
    {
        return false;
    }
    return false;
}

vector<int> DbManager::getComputerToScientist(int ID)
{
    vector<int> scientistId;
    QSqlQuery query(db);
    query.prepare("SELECT ScientistID FROM ScientistsAndComputers WHERE ComputerID = :ID");
    query.bindValue(":ID", ID);
    if(query.exec())
    {
        while(query.next())
        {
            scientistId.push_back(query.value("ScientistID").toUInt());
        }
    }
    return scientistId;
}

vector<int> DbManager::getScientistToComputer(int ID)
{
    vector<int> computerId;
    QSqlQuery query(db);
    query.prepare("SELECT ComputerID FROM ScientistsAndComputers WHERE ScientistID = :ID");
    query.bindValue(":ID", ID);
    if(query.exec())
    {
        while(query.next())
        {
            computerId.push_back(query.value("ComputerID").toUInt());
        }
    }
    return computerId;
}
vector<Persons> DbManager::readPersons(QSqlQuery query)
{
    Persons _persons;
    vector<Persons> printPersonsData;

    while (query.next())
    {
        int id = query.value("id").toUInt();
        string name = query.value("name").toString().toStdString();
        string gender = query.value("gender").toString().toStdString();
        string YearOfBirth = query.value("YearOfBirth").toString().toStdString();
        string YearOfDeath = query.value("YearOfDeath").toString().toStdString();

        _persons.setPersons(id, name, gender, YearOfBirth, YearOfDeath);

        printPersonsData.push_back(_persons);
    }
    return printPersonsData;
}

vector<Computers> DbManager::readComputers(QSqlQuery query)
{
    Computers _computer;
    vector<Computers> printComputersData;

    while (query.next())
    {
        int id = query.value("id").toUInt();
        string name = query.value("name").toString().toStdString();
        string yearBuilt = query.value("yearBuilt").toString().toStdString();
        string type = query.value("type").toString().toStdString();
        bool built  = query.value("built").toBool();

        _computer.setComputers(id, name, yearBuilt, type, built);

        printComputersData.push_back(_computer);
    }
    return printComputersData;
}

vector<Persons> DbManager::getSinglePerson(int ID)
{
    QSqlQuery query(db);
    query.prepare("SELECT * FROM Scientists WHERE ID = :ID");
    query.bindValue(":ID", ID);

    if(query.exec())
    {
        //Used to be a Qdebug statement here, removed for grading.
    }

    vector<Persons> person = readPersons(query);

    return person;
}

vector<Computers> DbManager::getSingleComputer(int ID)
{
    QSqlQuery query(db);
    query.prepare("SELECT * FROM Computers WHERE ID = :ID");
    query.bindValue(":ID", ID);

    if(query.exec())
    {
        //Used to be a Qdebug statement here, removed for grading.
    }

    vector<Computers> computer = readComputers(query);

    return computer;
}

vector<string> DbManager::readComputersTypes()
{
    QSqlQuery query(db);
    vector<string> types;
    query.exec("SELECT DISTINCT Type FROM Computers");
    while(query.next())
    {
        string type = query.value("Type").toString().toStdString();
        types.push_back(type);
    }
    return types;
}

vector<Persons> DbManager::printAllPersons()
{
    QSqlQuery query(db);
    query.exec("SELECT * FROM Scientists");

    return readPersons(query);
}

vector<Computers> DbManager::printAllComputers()
{
    QSqlQuery query(db);
    query.exec("SELECT * FROM Computers");

    return readComputers(query);
}

vector<Persons> DbManager::printPersonsResults(string searchTerm, int gender)
{
    QSqlQuery query;
    QString qSearchTerm = QString::fromStdString(searchTerm);

    if(gender == 1)
    {
        query.exec("SELECT * FROM Scientists WHERE gender LIKE '" + qSearchTerm + "'");
    }
    else if(gender == 2)
    {
        query.exec("SELECT * FROM Scientists WHERE name LIKE '%" + qSearchTerm + "%'""OR gender LIKE '" + qSearchTerm + "'"" OR YearOfBirth LIKE '%" + qSearchTerm + "%'""OR YearOfDeath LIKE '%" + qSearchTerm + "%'");
    }
    return readPersons(query);
}

vector<Computers> DbManager::printComputersResults(string searchTerm, bool trueOrFalse, int type)
{
    QSqlQuery query;
    QString qSearchTerm = QString::fromStdString(searchTerm);
    QString qBuilt = QString::number(trueOrFalse);

    if(type == 1)
    {
        query.exec("SELECT * FROM Computers WHERE Built LIKE '" + qBuilt + "'");
    }
    else if(type == 2)
    {
        query.exec("SELECT * FROM Computers WHERE name LIKE '%" + qSearchTerm + "%' "
                                                                                "OR YearBuilt LIKE '%" + qSearchTerm + "%' "
                                                                                                                       "OR Type LIKE '%" + qSearchTerm + "%' ");
    }

    return readComputers(query);
}

bool DbManager::updateScientist(int ID, string name, string gender, string yob, string yod)
{
    QSqlQuery query(db);
    QString qName = QString::fromStdString(name);
    QString qGender = QString::fromStdString(gender);
    QString qYob = QString::fromStdString(yob);
    QString qYod = QString::fromStdString(yod);

    query.prepare("UPDATE Scientists SET name = '" + qName + "', gender = '" + qGender + "', YearOfBirth = '" + qYob + "', YearOfDeath = '" + qYod + "' WHERE id = :ID");
    query.bindValue(":ID", ID);

    if(query.exec())
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool DbManager::updateComputer(int ID,string name, string yearbuilt, string type, bool built)
{
    QSqlQuery query(db);
    QString qName = QString::fromStdString(name);
    QString qYearBuilt = QString::fromStdString(yearbuilt);
    QString qType = QString::fromStdString(type);
    QString qBuilt = QString::number(built);

    query.prepare("UPDATE Computers SET name = '" + qName + "', YearBuilt = '" + qYearBuilt + "', Type = '" + qType + "', Built = '" + qBuilt + "' WHERE id = :ID");
    query.bindValue(":ID", ID);

    if(query.exec())
    {
        return true;
    }
    else
    {
        return false;
    }
}

void DbManager::updateRelations(int oldScientist,int oldComputer,int newScientist,int newComputer)
{

    QSqlQuery query(db);
    QString _oldScientist = QString::number(oldScientist);
    QString _oldComputer = QString::number(oldComputer);
    QString _newScientist = QString::number(newScientist);
    QString _newComputer = QString::number(newComputer);

    query.prepare("UPDATE ScientistsAndComputers SET ScientistId = '"+ _newScientist + "',ComputerID = '"+ _newComputer + "' WHERE ScientistID = :OldScientistID and ComputerID = :OldComputerID");
    query.bindValue(":OldScientistID",_oldScientist);
    query.bindValue(":OldComputerID",_oldComputer);

    query.exec();
}

void DbManager::removeRelation(int sciId, int compId)
{
    QSqlQuery query(db);
    query.prepare("DELETE FROM ScientistsAndComputers WHERE ScientistID = :SciID and ComputerID = :CompID");
    query.bindValue(":SciID", sciId);
    query.bindValue(":CompID",compId);
    query.exec();
}
