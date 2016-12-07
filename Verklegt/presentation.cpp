#include "presentation.h"
#include "persons.h"

using namespace std;

Presentation::Presentation()
{

}

void Presentation::startProgram()
{
    int input;
    cout << "Hello!" << endl;
    cout << "Please select one of the options below: " << endl;
    cout << "1. Scientists" << endl;
    cout << "2. Computers" << endl;
    cout << "3. Scientists and computers" << endl;
    cin >> input;
    if(input == 1)
    {
        addScientist();
    }
    else if(input == 2)
    {
        addComputer();
    }
    else if(input == 3)
    {
        // báðar töflur !
    }

}
// Adds person to file.
void Presentation::newPersonsInFile()
{
    Persons newPerson;
    int number = 0;
    string name;
    string gender;
    string yearOfBirth;
    string yearOfDeath;
    string answer;
    string currentYear;
    string userInput;
    bool valid = false;

    currentYear = _domain.currentYear(); // sets currentYear to the current year

    do
    {
        cout << "How many persons would you like to input: ";
        cin >> userInput;

        for (int i = 0; i < userInput.length(); i++)
        {
            if (isdigit(userInput[i]) == false)
            {
                cout << "You must enter an integer." << endl;
                break;
            }
            else
            {
                valid = true;
                number = stoi(userInput);
            }
        }

    }while(!valid);

    for(int i=0; i<number; i++)
    {
        cout << "-------------" << endl;
        cout << "Person " << i+1 << " of " << number << endl;
        cout << "-------------" << endl;
        cout << "Enter name: ";
        cin.ignore();
        getline(cin, name); // TODO ! Passa að ekki sé leyfilegt að slá inn tómt nafn !
        while (_domain.validNameCheck(name))
        {
            cout << "Name must only contain alphabet characters A-Z. \n Please enter a valid name." << endl;
            cin >> name;
        }

        cout << "Enter gender M/F: ";
        cin >> gender;
        while(!_domain.validGenderCheck(gender))
        {
            cout << "Please enter either 'M' for male or 'F' for female: ";
            cin >> gender;
        }

        gender = _domain.setGender(gender); // setur M/m = male & F/f = female

        cout << "Enter year of birth: ";
        cin >> yearOfBirth;

        while (_domain.validYearCheck(yearOfBirth))
        {
            cout << "Wrong input! Please enter 4 digits: ";
            cin >> yearOfBirth;
        }

        cout << "Is the person deceased? Y/N: ";
        cin >> answer;

        while(_domain.yesOrNoCheck(answer) == 2)
        {
            cout << "Wrong input! Please enter Y/N" << endl;
            cin >> answer;
        }

        if(_domain.yesOrNoCheck(answer) == 1)
        {
            cout << "Enter year of death: ";
            cin >> yearOfDeath;

            while( _domain.validDeathYearCheck(yearOfBirth, yearOfDeath))
            {
                cout << "Wrong input! Please enter 4 digits." << endl;
                cout << "Enter year of death: ";
                cin >> yearOfDeath;
            }
        }
        else if(_domain.yesOrNoCheck(answer) == 0)
        {
            yearOfDeath = '-'; // If not dead
        }

        cout << endl;

        newPerson.setPersons(3, name, gender, yearOfBirth, yearOfDeath);
        _domain.addPersons(newPerson);

    }

    cout << "Your input has been saved..." << endl;
    cout << endl;

    vector<Persons> getPerson;
    getPerson = _domain.getPersons();
    int databaseSize = getPerson.size();

    /*cout << "You added these people to the database: " << endl;
    cout << endl;
    for(int i = 0; i < number; i++)
    {
        cout << i+1 << ". " << getPerson[databaseSize-number+i].getName() << endl;
    }
    cout << endl;
    */
    cout << "Going back to main screen..." << endl;
    cout << endl;
}

void Presentation::newComputer()
{
    Computers newComp;
    int number = 0;
    string name;
    string yearOfBuild;
    string type;
    string didItWork;
    string currentYear;
    string userInput;
    string answer;
    bool valid = false;

    currentYear = _domain.currentYear(); // sets currentYear to the current year

    do
    {
        cout << "How many computers would you like to input: ";
        cin >> userInput;

        for (int i = 0; i < userInput.length(); i++)
        {
            if (isdigit(userInput[i]) == false)
            {
                cout << "You must enter an integer." << endl;
                break;
            }
            else
            {
                valid = true;
                number = stoi(userInput);
            }
        }

    }while(!valid);

    for(int i=0; i<number; i++)
    {
        cout << "-------------" << endl;
        cout << "Computer " << i+1 << " of " << number << endl;
        cout << "-------------" << endl;
        cout << "Enter name: ";
        cin.ignore();
        getline(cin, name); // tekur fullt nafn

        while (_domain.validNameCheck(name))
        {
            cout << "Name must only contain alphabet characters A-Z. \n Please enter a valid name." << endl;
            cin >> name;
        }

        while (_domain.validYearCheck(yearOfBuild))
        {
            cout << "Wrong input! Please enter 4 digits: ";
            cin >> yearOfBuild;
        }


            cout << "What type of computer is this?: ";
            cin >> type;


        cout << "Was the build successful? Y/N: ";
        cin >> answer;

        while(_domain.wasBuiltCheck(answer) == 2)
        {
            cout << "Wrong input! Please enter Y/N" << endl;
            cin >> answer;
        }

        if(_domain.wasBuiltCheck(answer) == 1)
        {
            cout << "What year was it built: ";
            cin >> yearOfBuild;

            /*while( _domain.validBuiltCheck(yearOfBuild))
            {
                cout << "Wrong input! Please enter 4 digits." << endl;
                cout << "What year was it built: ";
                cin >> yearOfBuild;
            }*/
        }

        else if(_domain.wasBuiltCheck(answer) == 0)
        {
            yearOfBuild = '-'; // If not built.
        }

        cout << endl;

        newComp.setComputers(name, yearOfBuild, type, didItWork);
        _domain.addComputer(newComp);
    }

    cout << "Your input has been saved..." << endl;
    cout << endl;

     //vector<Persons> getPerson;
     //getPerson = _domain.getPersons();
    //int databaseSize = getPerson.size();
    // þurfum að hafa vector af computer klasa
    //þurfum að búa titl fall inní domain sem sækir tölvur úr database
    //þurfum að sækja stærð af computer klasa

    cout << "You added these computers to the database: " << endl;
    cout << endl;
    for(int i = 0; i < number; i++)
    {
        //cout << i+1 <<". " << //nafn af vector af computer kalsa[databaseSize-number+i].//get fall í computerklasa() << endl;
    }
    cout << endl;

    cout << "Going back to main screen..." << endl;
    cout << endl;
}


// Removes person
void Presentation::removePerson()
{
    displayPersonsVector(_domain.getPersons());

    int ID = 0;

    cout << "Enter the ID of the scientist you wish to delete from the database: ";
    cin >> ID;
    cout << endl;

    if(cin.fail())
    {
        // clears the buffer
        cin.clear();
        cin.ignore(100, '\n');
    }

    string personDeleted = _domain.getSinglePerson(ID).getName(); // TODO: Make sure to check if user inputs valid ID
    bool success =_domain.deletePersonFromFile(ID);
    while(!success)
    {
        cout << "Please enter a valid ID: ";
        cin >> ID;

        personDeleted = _domain.getSinglePerson(ID).getName();
        success = _domain.deletePersonFromFile(ID);
    }

    // string deletedName = _domain.deletePersonFromFile(numberOfPerson);
    cout << personDeleted << " has been deleted from the database." << endl;
    cout << endl;

    displayPersonsVector(_domain.getPersons());
    inputToReturn();
}

// Removes computer
void Presentation::removeComputer()
{
    //displayPersonsVector(_domain.//get fall úr computerkalsa());

    int numberOfComputer = 0;

    cout << "Enter the number of computer you wish to delete from the database: ";
    cin >> numberOfComputer;
    cout << endl;

    if(cin.fail())
    {
        // clears the buffer
        cin.clear();
        cin.ignore(100, '\n');
    }
    /*while(!_domain.validDeleteOfPerson(numberOfComputer))
    {
        cout << "Please enter a valid number from 1 - " << _domain.//get fall úr computer klasa().size() << ": ";
        cin >> numberOfComputer;
    }*/

   /* string deletedComputer = _domain.deleteComputerFromDatabase(numberOfComputer);
    cout << deleteComputer << " has been deleted from the database." << endl;
    cout << endl;

    displayPersonsVector(_domain. get computer fall());
    inputToReturn();*/
}



// View menu
void Presentation::viewPersonsDatabase()
{
    cout << "How would you like view the database? " << endl;
    cout << "1. Default" << endl;
    cout << "2. Name: A-Z" << endl;
    cout << "3. Name: Z-A" << endl;
    cout << "4. Gender: F-M" << endl;
    cout << "5. Gender: M-F" << endl;
    cout << "6. Birth Year: Desc." << endl;
    cout << "7. Birth Year: Asc." << endl;
    cout << "8. Death Year: Desc." << endl;
    cout << "9. Death Year: Asc." << endl;
    cout << endl;

    int viewInput = 0;
    cout << "Enter your choice: ";
    cin >> viewInput;

    if(cin.fail())
    {
        // clears the buffer
        cin.clear();
        cin.ignore(100, '\n');
    }
    while(viewInput < 1 || viewInput > 9)
    {
        cout << "Please enter a valid number!" << endl;
        cout << "Enter your choice: ";
        cin >> viewInput;

        if(cin.fail())
        {
            // clears the buffer
            cin.clear();
            cin.ignore(100, '\n');
        }
    }
    if(viewInput == 1)
    {
        vector<Persons> printPersons = _domain.getPersons();
        displayPersonsVector(printPersons);
    }
    else
    {
        displayPersonsVector(_domain.sortPersons(viewInput));
        inputToReturn();
    }

}
void Presentation::viewComputersDatabase()
{
    cout << "How would you like view the database? " << endl;
    cout << "1. Default" << endl;
    cout << "2. Name of computer: A-Z" << endl;
    cout << "3. Name of computer: Z-A" << endl;
    cout << "4. When built: Desc." << endl;
    cout << "5. When built: Asc." << endl;
    cout << "6. Type: Desc." << endl;
    cout << "7. Type: Year: Asc." << endl;
    cout << "8. Build successful: Y" << endl;
    cout << "9. Build successful: N" << endl;
    cout << endl;

    int viewInput = 0;
    cout << "Enter your choice: ";
    cin >> viewInput;

    if(cin.fail())
    {
        // clears the buffer
        cin.clear();
        cin.ignore(100, '\n');
    }
    while(viewInput < 1 || viewInput > 9)
    {
        cout << "Please enter a valid number!" << endl;
        cout << "Enter your choice: ";
        cin >> viewInput;

        if(cin.fail())
        {
            // clears the buffer
            cin.clear();
            cin.ignore(100, '\n');
        }
    }
    if(viewInput == 1)
    {
        displayComputersVector(_domain.getComputers());
    }

    // Kalla á fall í domain sem tekur inn val notenda(tölu) sem kallar á data & birtir einungis þær uppl.

    //displayPersonsVector(_domain.sortPersons(viewInput));
    //inputToReturn();
}

// Searches the database(file).
void Presentation::searchPersonDatabase()
{
    int userChoice = 0;
    cout << "Please enter one of the following commands: " << endl;
    cout << "1. Search by name" << endl;
    cout << "2. Search by gender" << endl;
    cout << "3. Search by year of birth" << endl;
    cout << "4. Search by year of death" << endl;
    cout << "5. Return to main menu" << endl;
    cout << endl;
    cout << "Enter your choice: ";
    cin >> userChoice;

    if(userChoice > 0 && userChoice < 5)
    {
        // fara í fall í domain, sem tekur við inputi, sendir inní dbManager.

    }
    else if(userChoice == 5)
    {
        cout << endl;
        cout << "Going back to main menu..." << endl;
        cout << endl;
        addScientist();
    }
    else
    {
        // clears the buffer
        cin.clear();
        cin.ignore(100, '\n');
        cout << "Wrong input!" << endl;
        cout << endl;
        searchPersonDatabase();
    }
}

void Presentation::searchComputerDatabase()
{
    int userChoice = 0;
    cout << "Please enter one of the following commands: " << endl;
    cout << "1. Search by name" << endl;
    cout << "2. Search by built year" << endl;
    cout << "3. Search by type" << endl;
    cout << "4. Search by if built was successful" << endl;
    cout << "5. Return to main menu" << endl;
    cout << endl;
    cout << "Enter your choice: ";
    cin >> userChoice;

    if(userChoice > 0 && userChoice < 5)
    {
        // fall í domain sem tekur við inntaki frá notenda og fer inní dbManager
    }
    else if(userChoice == 5)
    {
        cout << endl;
        cout << "Going back to main menu..." << endl;
        cout << endl;
        addScientist();
    }
    else
    {
        // clears the buffer
        cin.clear();
        cin.ignore(100, '\n');
        cout << "Wrong input!" << endl;
        cout << endl;
        searchComputerDatabase();
    }
}

// Main addScientist that gets called from main.
void Presentation::addScientist()
{
    int input = 0;
    do
    {   // Displays a menu for user

        cout << "Please enter one of the following commands: " << endl;
        cout << "1 - Add a new scientist to the database" << endl;
        cout << "2 - Delete a scientist from the database" << endl; // TODO - EXTRA
        cout << "3 - View the scientist database" << endl;
        cout << "4 - Search the scientist database" << endl;
        cout << "5 - Quit" << endl;
        cout << endl;
        cout << "Enter your choice: ";
        cin >> input;
        cout << endl;

        if(input == 1)
        {
            newPersonsInFile();
        }
        else if(input == 2)
        {
            removePerson();
        }
        else if(input == 3)
        {
            viewPersonsDatabase();
        }
        else if(input == 4)
        {
            searchPersonDatabase();
        }
        else if(cin.fail())
        {
            // clears the buffer
            cin.clear();
            cin.ignore(100, '\n');
        }
    }while (input != 5);
}

void Presentation::addComputer()
{
    int input = 0;
    do
    {   // Displays a menu for user

        cout << "Please enter one of the following commands: " << endl;
        cout << "1 - Add a new computer to the database" << endl;
        cout << "2 - Delete a computer from the database" << endl; // TODO - EXTRA
        cout << "3 - View the computer database" << endl;
        cout << "4 - Search the computer database" << endl;
        cout << "5 - Quit" << endl;
        cout << endl;
        cout << "Enter your choice: ";
        cin >> input;
        cout << endl;

        if(input == 1)
        {
            newComputer();
        }
        else if(input == 2)
        {
            removeComputer();
        }
        else if(input == 3)
        {
            viewComputersDatabase();
        }
        else if(input == 4)
        {
            searchComputerDatabase();
        }
        else if(cin.fail())
        {
            // clears the buffer
            cin.clear();
            cin.ignore(100, '\n');
        }
    }while (input != 5);
}


// Displays a table with file information.
void Presentation::displayPersonsVector(vector<Persons> p)
{
    cout << endl;
    cout << "Nr.\t" << setw(34) << left << "Name"  << setw(15) << "Gender" << setw(15) << "Born" << setw(15) << "Died" << endl;
    for(int i=0; i<80; i++)
    {
        cout << "-";
    }
    cout << endl;
    if(p.size() > 0){

        for(size_t i=0; i< p.size(); i++)
        {
            cout << p[i].getID() << ".\t" << setw(34) << left << p[i].getName() << setw(15) << p[i].getGender() << setw(15) << p[i].getYearOfBirth() << setw(15) << p[i].getYearOfDeath()<< endl;
        }
        cout << endl;
    }else{
        cout << "Operation returned no results!" << endl;
        cout << endl;
    }

}

void Presentation::displayComputersVector(vector<Computers> c)
{
    cout << endl;
    cout << "Nr.\t" << setw(34) << left << "Name"  << setw(15) << "Year of Building" << setw(15) << "Type" << setw(15) << "Was the built Successful" << endl;
    for(int i=0; i<80; i++)
    {
        cout << "-";
    }
    cout << endl;
    if(c.size() > 0){

        for(size_t i=0; i< c.size(); i++)
        {
            cout << c[i].getCompID() << ".\t" << setw(34) << left << c[i].getCompName() << setw(15) << c[i].getCompYearBuild() << setw(15) << c[i].getCompType() << setw(15) << c[i].getCompBuilt()<< endl;
        }
        cout << endl;
    }else{
        cout << "Operation returned no results!" << endl;
        cout << endl;
    }

}

// Asks user to return to main or quit the addScientist.
void Presentation::inputToReturn()
{
    string input = "";
    // the addScientist function will loop until user inputs the right command
    do
    {
        cout << "Enter 'R' to return to main menu or 'Q' to quit the addScientist: ";
        cin >> input;
    }
    while(input != "r" && input != "R" && input != "q" && input != "Q");
    cout << endl;

    // asking user if he is sure he wants to quit the addScientist
    if(input != "r" && input != "R")
    {
        string userQuitting = "";
        while(userQuitting != "N" && userQuitting != "n" && userQuitting != "Y" && userQuitting != "y") {
            cout << "Are you sure that you want to quit the addScientist?" << endl;
            cout << "Y/N: ";
            cin >> userQuitting;
        }
        if(userQuitting != "N" && userQuitting != "n")
        {
            // exit = quitting the addScientist
            exit(1);
        }
    }
    cout << endl;
}

// Message that prints out when addScientist begins.
void Presentation::splashMessage()
{
    cout << endl;
    for(int i = 0; i < 1; i++)
    {
        for(int j = 0; j < 40; j++)
        {
            cout << "*";
        }
        cout << endl;
    }

    for(int i = 0; i < 1; i++)
    {
        cout << "*" << "*";
        for(int j = 0; j < 5; j++)
        {
            cout << " ";
        }
        cout << "Computer Scientists v.1.0"; // 25
        for(int j = 0; j < 6; j++)
        {
            cout << " ";
        }
        cout << "*" << "*" << endl;
    }

    for(int i = 0; i < 1; i++)
    {
        for(int j = 0; j < 40; j++)
        {
            cout << "*";
        }
        cout << endl;
    }
    cout << endl;
}
