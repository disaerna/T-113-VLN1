#include "presentation.h"
#include "persons.h"

using namespace std;

Presentation::Presentation()
{

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
        getline(cin, name); // tekur fullt nafn

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

        newPerson.setPersons(name, gender, yearOfBirth, yearOfDeath);
        _domain.addPersons(newPerson);
    }

    cout << "Your input has been saved..." << endl;
    cout << endl;

    vector<Persons> getPerson;
    getPerson = _domain.getPersons();
    int databaseSize = getPerson.size();

    cout << "You added these people to the database: " << endl;
    cout << endl;
    for(int i = 0; i < number; i++)
    {
        cout << i+1 << ". " << getPerson[databaseSize-number+i].getName() << endl;
    }
    cout << endl;

    cout << "Going back to main screen..." << endl;
    cout << endl;
}

/*void Presentation::newComputer()
{
    Computer newComp;
    int number = 0;
    string nameC;
    string yearOfBuild;
    string type;
    string didItWork;
    string currentYear;
    string userInput;
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

        while (_domain.validNameCheck(nameC))
        {
            cout << "Name must only contain alphabet characters A-Z. \n Please enter a valid name." << endl;
            cin >> name;
        }

        while (_domain.validYearCheck(yearOfBuild))
        {
            cout << "Wrong input! Please enter 4 digits: ";
            cin >> yearOfBuild;
        }

        while (_domain.type)
        {
            cout << "What type of computer is this?: ";
            cin >> type;
        }

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

            while( _domain.validBuiltCheck(yearOfBuild))
            {
                cout << "Wrong input! Please enter 4 digits." << endl;
                cout << "What year was it built: ";
                cin >> yearOfBuild;
            }
        }
        else if(_domain.wasBuiltCheck(answer) == 0)
        {
            yearOfBuild = NULL; // If not built.
        }

        cout << endl;

        //newComp.setComputers(name, yearOfBuild, type, didItWork);
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
        cout << i+1 << ". " << //nafn af vector af computer kalsa[databaseSize-number+i].//get fall í computerklasa() << endl;
    }
    cout << endl;

    cout << "Going back to main screen..." << endl;
    cout << endl;
}*/


// Removes person
void Presentation::removePerson()
{
    displayPersonsVector(_domain.getPersons());

    int numberOfPerson = 0;

    cout << "Enter the number of person you wish to delete from the database: ";
    cin >> numberOfPerson;
    cout << endl;

    if(cin.fail())
    {
        // clears the buffer
        cin.clear();
        cin.ignore(100, '\n');
    }
    while(!_domain.validDeleteOfPerson(numberOfPerson))
    {
        cout << "Please enter a valid number from 1 - " << _domain.getPersons().size() << ": ";
        cin >> numberOfPerson;
    }

    string deletedName = _domain.deletePersonFromFile(numberOfPerson);
    cout << deletedName << " has been deleted from the database." << endl;
    cout << endl;

    displayPersonsVector(_domain.getPersons());
    inputToReturn();
}

// Removes computer
/*void Presentation::removeComputer()
{
    displayPersonsVector(_domain.//get fall úr computerkalsa());

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
    while(!_domain.validDeleteOfPerson(numberOfComputer))
    {
        cout << "Please enter a valid number from 1 - " << _domain.//get fall úr computer klasa().size() << ": ";
        cin >> numberOfComputer;
    }

   /* string deletedComputer = _domain.deleteComputerFromDatabase(numberOfComputer);
    cout << deleteComputer << " has been deleted from the database." << endl;
    cout << endl;

    displayPersonsVector(_domain. get computer fall());
    inputToReturn();
}*/



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

    displayPersonsVector(_domain.sortPersons(viewInput));
    inputToReturn();
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

    if(userChoice == 1)
    {
        searchByName();
    }
    else if(userChoice == 2)
    {
        searchByGender();
    }
    else if(userChoice == 3)
    {
        searchByBirthYear();
    }
    else if(userChoice == 4)
    {
        searchByDeathYear();
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

    if(userChoice == 1)
    {
        searchByComputerName();
    }
    else if(userChoice == 2)
    {
        searchByBuiltYear();
    }
    else if(userChoice == 3)
    {
        searchByType();
    }
    else if(userChoice == 4)
    {
        searchBySuccessfulBuilt();
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

void Presentation::searchByName()
{
    string nameInput = " ";

    cout << "Enter a name to search: ";
    cin >> nameInput;
    cout << endl;

    displayPersonsVector( _domain.searchName(nameInput));
    inputToReturn();
}

void Presentation::searchByGender()
{
    string genderInput = " ";

    cout << "Enter 'M' for male results" << endl;
    cout << "Enter 'F' for female results" << endl;
    cout << ": ";
    cin >> genderInput;

    displayPersonsVector(_domain.searchGender(genderInput));
    inputToReturn();
}

void Presentation::searchByBirthYear()
{
    string birthYear = " ";

    cout << "Enter birth year: ";
    cin >> birthYear;

    displayPersonsVector( _domain.searchBirthYear(birthYear));
    inputToReturn();
}

void Presentation::searchByDeathYear()
{
    string deathYear = " ";

    cout << "Enter death year: ";
    cin >> deathYear;

    displayPersonsVector(_domain.searchDeathYear(deathYear));
    inputToReturn();
}

void Presentation::searchByComputerName()
{
    string nameInput = " ";

    cout << "Enter a computer name to search: ";
    cin >> nameInput;
    cout << endl;
}
void Presentation::searchByBuiltYear()
{
    string builtYearInput = " ";

    cout << "Enter a year to search: ";
    cin >> builtYearInput;
    cout << endl;
}
void Presentation::searchByType()
{
    string typeInput = " ";

    cout << "Enter a type to search: ";
    cin >> typeInput;
    cout << endl;
}
void Presentation::searchBySuccessfulBuilt()
{
    string SBinput = " ";

    cout << "Enter Y/N to search: ";
    cin >> SBinput;
    cout << endl;
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

/*void Presentation::addComputer()
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
            viewComputerDatabase();
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
}*/


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
            cout << (i+1) << ".\t" << setw(34) << left << p[i].getName() << setw(15) << p[i].getGender() << setw(15) << p[i].getYearOfBirth() << setw(15) << p[i].getYearOfDeath()<< endl;
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
