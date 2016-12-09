#include "presentation.h"

using namespace std;

Presentation::Presentation()
{

}

void Presentation::startProgram()
{
    int input = 0;
    cout << endl;
    cout << "Verk Solutions v.2.0 -- Main menu: " << endl;
    cout << "---------------------------------------" << endl;
    cout << "Please select one of the options below" << endl;
    cout << "---------------------------------------" << endl;
    cout << "1. Scientists" << endl;
    cout << "2. Computers" << endl;
    cout << "3. Quit the program" << endl;
    cout << "---------------------------------------" << endl;
    cout << endl;

    cout << "Enter your command: ";
    cin >> input;
    cout << endl;


    if(cin.fail())
    {
        // clears the buffer
        cin.clear();
        cin.ignore(100, '\n');
    }

    while(input < 1 || input > 3)
    {
        cout << "Please enter a correct input: ";
        cin >> input;

        if(cin.fail())
        {
            // clears the buffer
            cin.clear();
            cin.ignore(100, '\n');
        }
    }

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
        quitDoubt();
    }
}
//Gives the user a chance to return to main menu or quit the program
void Presentation::quitDoubt()
{
    string quit = "";

    cout << "Are you sure you want to quit?" << endl;
    cout << "Enter 'n' to return to main menu, any other to quit: ";
    cin >> quit;

    if(quit == "N" || quit == "n")
    {
        cout << "Smart choice..\n\n";
        startProgram();
    }
    else
    {
        cout << "Quitting program....\n" << endl;
    }
}

// Adds new Scientists to the scientists database
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
        cout << "How many Scientists would you like to input: ";
        cin >> userInput;

        for (size_t i = 0; i < userInput.length(); i++)
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
        getline(cin, name);
        while (_domain.validNameCheck(name) || !_domain.emptyStringCheck(name))
        {
            cout << "Name must only contain alphabet characters A-Z. \nPlease enter a valid name: ";
            cin >> name;
        }


        cout << "Enter gender M/F: ";
        cin.clear();
        cin >> gender;
        while(!_domain.validGenderCheck(gender))
        {
            cout << "Please enter either 'M' for male or 'F' for female: ";
            cin >> gender;
        }

        gender = _domain.setGender(gender);

        cout << "Enter year of birth: ";
        cin.clear();
        cin >> yearOfBirth;

        while (_domain.validYearCheck(yearOfBirth))
        {
            cout << "Wrong input! Please enter 4 digits: ";
            cin >> yearOfBirth;
        }

        cout << "Is the Scientists deceased? Y/N: ";
        cin >> answer;

        while(_domain.yesOrNoCheck(answer) == 2)
        {
            cout << "Wrong input! Please enter Y/N";
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

    inputToReturn();
}
//Adds new Computer to the Computers database
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
    bool built = false;
    bool valid = false;

    currentYear = _domain.currentYear(); // sets currentYear to the current year

    do
    {
        cout << "How many computers would you like to input: ";
        cin >> userInput;

        for (size_t i = 0; i < userInput.length(); i++)
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
        getline(cin, name);

        while (!_domain.emptyStringCheck(name))
        {
            cout << "Name cannot be empty." << endl;
            cout << "Please enter a valid name." << endl;
            cin >> name;
        }

        cout << "Enter the year the computer was built: ";
        cin >> yearOfBuild;

        while (_domain.validYearCheck(yearOfBuild))
        {
            cout << "Wrong input! Please enter 4 digits: ";
            cin >> yearOfBuild;
        }

        vector<string> types = _domain.getComputersTypes();


        string compType;
        string answer;
        string typeAnswer;
        string newType;
        int chooseType;

        for(size_t i = 0; i<types.size(); i++)
        {
            cout << i+1 << ". " << types[i]<<endl;
        }
        cout << "Is the type of your computer in the list above? Please enter Y/N: " << endl;

        cin >> answer;
        while(_domain.yesOrNoCheck(answer) == 2)
        {
            cout << "Wrong input! Please enter Y/N: " << endl;
            cin >> answer;
        }
        if(_domain.yesOrNoCheck(answer) == 1)
        {
            cout << "Please enter the number for the type of computer you wish to register: " << endl;
            cin >> chooseType;

            while(chooseType < 0 && chooseType > (signed)types.size())
            {
                cout << "Please enter a valid number from 1 - "<<types.size()<<" : "<< endl;
                cin>>chooseType;
            }
            type = types[chooseType -1];
        }
        else if(_domain.yesOrNoCheck(answer) == 0)
        {
            cout << "Would you like to add a type on the list? Please enter Y/N: " << endl;
            cin >> typeAnswer;
            while(_domain.yesOrNoCheck(typeAnswer) == 2)
            {
                cout << "Wrong input! Please enter Y/N: " << endl;
                cin >> typeAnswer;
            }
            if(_domain.yesOrNoCheck(typeAnswer) == 1)
            {

                cout << "Enter the name of the new type: " << endl;
                cin >> newType;

                type = newType;
            }
            else if(_domain.yesOrNoCheck(typeAnswer) == 0)
            {
                inputToReturn();
            }
            types.push_back(newType);

        }

        cout << "Was the build successful? Y/N: ";
        cin >> answer;

        while(_domain.yesOrNoCheck(answer) == 2)
        {
            cout << "Wrong input! Please enter Y/N: " << endl;
            cin >> answer;
        }

        if(_domain.yesOrNoCheck(answer) == 1)
        {
            built = true;
        }

        else if(_domain.yesOrNoCheck(answer) == 0)
        {
            built = false;
        }

        cout << endl;

        newComp.setComputers(3, name, yearOfBuild, type, built);

        _domain.addComputer(newComp);
    }

    cout << "Your input has been saved..." << endl;
    cout << endl;

    cout << "You added these computers to the database: " << endl;
    cout << name << endl;
    cout << endl;

    inputToReturn();
}


// Allows the user to remove Scientists from the Scientists database and displays the Scientists table
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

    while(!_domain.validIDTwo(ID, "1"))
    {
        cout << "Error!\n";
        cout << "Enter correct ID: ";
        cin >> ID;

        if(cin.fail())
        {
            // clears the buffer
            cin.clear();
            cin.ignore(100, '\n');
        }
    }

    string personDeleted = _domain.getSinglePerson(ID).getName();

    while(!_domain.deletePersonFromFile(ID))
    {
        cout << "Please enter a valid ID: ";
        cin >> ID;

        if(cin.fail())
        {
            // clears the buffer
            cin.clear();
            cin.ignore(100, '\n');
        }
        personDeleted = _domain.getSinglePerson(ID).getName();
    }

    _domain.deleteConnections("ScientistID", ID);


    cout << personDeleted << " has been deleted from the database." << endl;
    cout << endl;

    displayPersonsVector(_domain.getPersons());
    inputToReturn();
}

// Allows the user to remove Computer from the Computers database and display Computers table
void Presentation::removeComputer()
{
    displayComputersVector(_domain.getComputers());

    int ID = 0;

    cout << "Enter the ID of the computer you wish to delete from the database: ";
    cin >> ID;

    if(cin.fail())
    {
        // clears the buffer
        cin.clear();
        cin.ignore(100, '\n');
    }

    while(!_domain.validIDTwo(ID, "2"))
    {
        cout << "Error!\n";
        cout << "Enter correct ID: ";
        cin >> ID;

        if(cin.fail())
        {
            // clears the buffer
            cin.clear();
            cin.ignore(100, '\n');
        }
    }
    cout << endl;

    string deletedComputer = _domain.getSingleComputer(ID).getCompName();

    while(! _domain.deleteComputerFromDatabase(ID))
    {
        cout << "Please enter a valid ID: ";
        cin >> ID;

        if(cin.fail())
        {
            // clears the buffer
            cin.clear();
            cin.ignore(100, '\n');
        }

        deletedComputer = _domain.getSingleComputer(ID).getCompName();
    }

    _domain.deleteConnections("ComputerID", ID);

    cout << deletedComputer << " has been deleted from the database." << endl;
    cout << endl;

    displayComputersVector(_domain.getComputers());
    inputToReturn();
}



// The main menu options when the user choose to view the Scientists database
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
        inputToReturn();
    }
    else
    {
        displayPersonsVector(_domain.sortPersons(viewInput));
        inputToReturn();
    }

}
//The main menu options when the user choose to view the Computers database
void Presentation::viewComputersDatabase()
{
    cout << "How would you like view the database? " << endl;
    cout << "1. Default" << endl;
    cout << "2. Name of computer: A-Z" << endl;
    cout << "3. Name of computer: Z-A" << endl;
    cout << "4. When built: Desc." << endl;
    cout << "5. When built: Asc." << endl;
    cout << "6. Type: Desc." << endl;
    cout << "7. Type: Asc." << endl;
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
    else
    {
        displayComputersVector(_domain.sortComputers(viewInput));
    }
    inputToReturn();

}
//views the connection between certain Scientists and the computers he is linked to and prints out in table
void Presentation::viewScientistConnection()
{
    displayPersonsVector(_domain.getPersons());

    int ID;
    cout << endl;
    cout << "Enter ID for a scientist: ";
    cin >> ID;

    if(cin.fail())
    {
        // clears the buffer
        cin.clear();
        cin.ignore(100, '\n');
    }
    while(!_domain.validID(1, ID))
    {
        cout << "Error!\n";
        cout << "Enter correct ID: ";
        cin >> ID;

        if(cin.fail())
        {
            // clears the buffer
            cin.clear();
            cin.ignore(100, '\n');
        }
    }
    cout << endl;
    cout << "These are the computers connected to the scientist: "<< endl;
    cout << endl;
    displayComputersVector(_domain.getScientistToComputer(ID));

    inputToReturn();
}
//The user can view the connection between the Scientist and the computers he is linked to
void Presentation::viewComputerConnection()
{
    displayComputersVector(_domain.getComputers());

    int ID;
    cout << endl;
    cout << "Enter ID for a computer: ";
    cin >> ID;

    if(cin.fail())
    {
        // clears the buffer
        cin.clear();
        cin.ignore(100, '\n');
    }
    while(!_domain.validID(2, ID))
    {
        cout << "Error!\n";
        cout << "Enter correct ID: ";
        cin >> ID;

        if(cin.fail())
        {
            // clears the buffer
            cin.clear();
            cin.ignore(100, '\n');
        }
    }
    cout << endl;
    cout << "These are the scientists connected to the computer: "<< endl;
    cout << endl;
    displayPersonsVector(_domain.getComputerToScientist(ID));
    inputToReturn();

}
// Main menu when the user wants to search for Scientist by multiple options
void Presentation::searchPersonDatabase()
{
    int userChoice = 0;
    string searchTerm = "";
    cout << "Please enter one of the following commands: " << endl;
    cout << "1. Search by name" << endl;
    cout << "2. Search by gender" << endl;
    cout << "3. Search by year of birth" << endl;
    cout << "4. Search by year of death" << endl;
    cout << "5. Return to main menu" << endl;
    cout << endl;
    cout << "Enter your choice: ";
    cin >> userChoice;

    if(cin.fail())
    {
        // clears the buffer
        cin.clear();
        cin.ignore(100, '\n');
    }
    vector<Persons> searchResults;

    if(userChoice == 1)
    {
        cout << "Enter a name to search for: ";
        cin.ignore();
        getline(cin, searchTerm);

        while (_domain.validNameCheck(searchTerm) || !_domain.emptyStringCheck(searchTerm))
        {
            cout << "Name must only contain alphabet characters A-Z. \nPlease enter a valid name." << endl;
            cin >> searchTerm;
        }

        searchResults = _domain.getPersonsSearch(searchTerm, userChoice);
        displayPersonsVector(searchResults);
        inputToReturn();

    }
    else if(userChoice == 2)
    {
        cout << "Enter either 'm' or 'f': ";
        cin >> searchTerm;
        while(!_domain.validGenderCheck(searchTerm))
        {
            cout << "Please enter either 'm' for male or 'f' for female: ";
            cin >> searchTerm;
        }

        searchResults = _domain.getPersonsSearch(searchTerm, userChoice);
        displayPersonsVector(searchResults);
        inputToReturn();
    }
    else if(userChoice == 3)
    {
        cout << "Enter Birth year: ";
        cin >> searchTerm;

        while (_domain.validYearCheck(searchTerm))
        {
            cout << "Wrong input! Please enter 4 digits: ";
            cin >> searchTerm;
        }

        searchResults = _domain.getPersonsSearch(searchTerm, userChoice);
        displayPersonsVector(searchResults);
        inputToReturn();
    }
    else if(userChoice == 4)
    {
        cout << "Is the person deceased? Y/N: ";
        cin >> searchTerm;

        while(_domain.yesOrNoCheck(searchTerm) == 2)
        {
            cout << "Wrong input! Please enter Y/N: ";
            cin >> searchTerm;
        }

        if(_domain.yesOrNoCheck(searchTerm) == 1)
        {
            cout << "Enter year of death: ";
            cin >> searchTerm;
        }

        else if(_domain.yesOrNoCheck(searchTerm) == 0)
        {
            searchTerm = '-'; // If not dead
        }

        searchResults = _domain.getPersonsSearch(searchTerm, userChoice);
        displayPersonsVector(searchResults);
        inputToReturn();
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
//Main menu when the user wants to search for Computer by different options
void Presentation::searchComputersDatabase()
{
    int userChoice = 0;
    string searchTerm = "";
    cout << "Please enter one of the following commands: " << endl;
    cout << "1. Search by name" << endl;
    cout << "2. Search by built year" << endl;
    cout << "3. Search by type" << endl;
    cout << "4. Search by successful built" << endl;
    cout << "5. Return to computer menu" << endl;
    cout << endl;
    cout << "Enter your choice: ";
    cin >> userChoice;

    if(cin.fail())
    {
        // clears the buffer
        cin.clear();
        cin.ignore(100, '\n');
    }
    vector<Computers> searchResults;

    if(userChoice == 1)
    {
        cout << "Enter name: ";
        cin.ignore();
        getline(cin, searchTerm); // tekur fullt nafn
        while (!_domain.emptyStringCheck(searchTerm))
        {
            cout << "Name cannot be empty." << endl;
            cout << "Please enter a valid name." << endl;
            cin >> searchTerm;
        }

        searchResults = _domain.getComputersSearch(searchTerm, userChoice);
        displayComputersVector(searchResults);
        inputToReturn();

    }
    else if(userChoice == 2)
    {
        cout << "Enter built year: ";
        cin >> searchTerm;

        while (_domain.validYearCheck(searchTerm))
        {
            cout << "Wrong input! Please enter 4 digits: ";
            cin >> searchTerm;
        }

        searchResults = _domain.getComputersSearch(searchTerm, userChoice);
        displayComputersVector(searchResults);
        inputToReturn();
    }
    else if(userChoice == 3)
    {
        cout << "Enter computer type: ";
        cin >> searchTerm;

        // þarf villutékk til að hægt sé aðeins að stimpla inn ákveðnar gerðir

        string str = searchTerm;
        transform(str.begin(), str.end(), str.begin(), ::tolower);
        searchTerm = str;

        searchResults = _domain.getComputersSearch(searchTerm, userChoice);
        displayComputersVector(searchResults);
        inputToReturn();
    }
    else if(userChoice == 4)
    {
        cout << "Enter Y/N if computer was built: ";
        cin >> searchTerm;
        if(_domain.yesOrNoCheck(searchTerm) == 2)
        {
            cout << "Wrong input! Please enter Y/N: ";
            cin >> searchTerm;
        }
        else if(_domain.yesOrNoCheck(searchTerm) == 1)
        {
            searchTerm = "1";
        }
        else if(_domain.yesOrNoCheck(searchTerm) == 0)
        {
            searchTerm = "0";
        }

        searchResults = _domain.getComputersSearch(searchTerm, userChoice);
        displayComputersVector(searchResults);
        inputToReturn();
    }
    else if(userChoice == 5)
    {
        cout << endl;
        cout << "Going back to main menu..." << endl;
        cout << endl;
        addComputer();
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

// Main addScientist that gets called from main.
void Presentation::addScientist()
{
    int input = 0;
    // Displays a menu for user

    cout << "Please enter one of the following commands: " << endl;
    cout << "1 - Add a new scientist to the database " << endl;
    cout << "2 - Edit records for scientist in database" << endl;
    cout << "3 - Delete a scientist from the database " << endl;
    cout << "4 - View the scientist database " << endl;
    cout << "5 - View computer for a scientist " << endl;
    cout << "6 - Connect a scientist to a computer " << endl;
    cout << "7 - Search the scientist database " << endl;
    cout << "8 - Return to main menu " << endl;
    cout << "9 - Quit the program " << endl;
    cout << endl;
    cout << "Enter your choice: ";
    cin >> input;

    while(input < 1 || input > 8)
    {
        cout << "Please input a correct number: ";
        cin >> input;

        if(cin.fail())
        {
            // clears the buffer
            cin.clear();
            cin.ignore(100, '\n');
        }
    }

    if(input == 1)
    {
        newPersonsInFile();
    }
    else if(input == 2)
    {
        updatePerson();
    }
    else if(input == 3)
    {
        removePerson();
    }
    else if(input == 4)
    {
        viewPersonsDatabase();
    }
    else if(input == 5)
    {
        viewScientistConnection();
    }
    else if(input == 6)
    {

        connectScientist();
    }
    else if(input == 7)
    {
        searchPersonDatabase();
    }
    else if(input == 8)
    {
        startProgram();
    }
    else if(input == 9)
    {
        quitDoubt();
    }

    else if(cin.fail())
    {
        // clears the buffer
        cin.clear();
        cin.ignore(100, '\n');
    }
}
// Main addComputers that gets called from main
void Presentation::addComputer()
{
    int input = 0;
    do
    {   // Displays a menu for user

        cout << "Please enter one of the following commands: " << endl;
        cout << "1 - Add a new computer to the database" << endl;
        cout << "2 - Update records for computer in database" << endl;
        cout << "3 - Delete a computer from the database" << endl; // TODO - EXTRA
        cout << "4 - View the computer database" << endl;
        cout << "5 - View scientists for a computer" << endl;
        cout << "6 - Connect a computer to a scientist" << endl;
        cout << "7 - Search the computer database" << endl;
        cout << "8 - Return to main menu\n";
        cout << "9 - Quit the program\n";

        cout << endl;
        cout << "Enter your choice: ";
        cin >> input;
        cout << endl;

        while(input < 1 || input > 8)
        {
            cout << "Please input a correct number: ";
            cin >> input;

            if(cin.fail())
            {
                // clears the buffer
                cin.clear();
                cin.ignore(100, '\n');
            }
        }

        if(input == 1)
        {
            newComputer();
        }
        else if(input == 2)
        {
            updateComputer();
        }
        else if(input == 3)
        {
            removeComputer();
        }
        else if(input == 4)
        {
            viewComputersDatabase();
        }
        else if(input == 5)
        {
            viewComputerConnection();
        }
        else if(input == 6)
        {
            connectComputer();
        }
        else if(input == 7)
        {
            searchComputersDatabase();
        }
        else if(input == 8)
        {
            startProgram();
        }
        else if (input == 9)
        {
            quitDoubt();
        }
        else if(cin.fail())
        {
            // clears the buffer
            cin.clear();
            cin.ignore(100, '\n');
        }
    }while (input != 7);
}
// Connects certain computer to a scientist from the database
void Presentation::connectComputer()
{
    int computerID;
    int scientistID;
    displayComputersVector(_domain.getComputers());

    cout << "Select an ID for a computer: ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin >> computerID;
    while(!_domain.validID(2, computerID))
    {
        if(cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        cout << "Please enter a valid input: ";
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin >> computerID;
    }

    displayPersonsVector(_domain.getPersons());

    cout << "Select an ID for a scientist: ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin >> scientistID;
    while(!_domain.validID(1, scientistID))
    {
        if(cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        cout << "Please enter a valid input: ";
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin >> scientistID;
    }

    vector<Persons> legalID = _domain.getComputerToScientist(computerID);

    for(size_t i=0; i<legalID.size(); i++)
    {
        while(scientistID == legalID[i].getID())
        {
            cout << "This computer already has this connection." << endl;
            cout << "Press '0' to go back to main menu." << endl;
            cout << "Select an ID for a scientist: " << endl;
            cin >> scientistID;

            if(cin.fail())
            {
                // clears the buffer
                cin.clear();
                cin.ignore(100, '\n');
            }
            if(scientistID == 0)
            {
                inputToReturn();
            }
        }
    }
    _domain.connectComputersAndScientists(scientistID, computerID);
    cout << "Connection successful! " << endl;
    cout << endl;
    inputToReturn();
}
//Connects a Scientist to a computer in the database.
void Presentation::connectScientist()
{
    int computerID;
    int scientistID;
    displayPersonsVector(_domain.getPersons());

    cout << "Select an ID for a scientist: ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin >> scientistID;
    while(!_domain.validID(1, scientistID))
    {
        if(cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        cout << "Please enter a valid input: ";
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin >> scientistID;
    }

    displayComputersVector(_domain.getComputers());

    cout << "Select an ID for a computer: ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin >> computerID;
    while(!_domain.validID(2, computerID))
    {
        if(cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        cout << "Please enter a valid input: ";
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin >> computerID;
    }

    vector<Computers> legalID = _domain.getScientistToComputer(scientistID);

    for(size_t i=0; i<legalID.size(); i++)
    {
        while(computerID == legalID[i].getCompID())
        {
            cout << "This scientist already has this connection." << endl;
            cout << "Press '0' to go back to main menu." <<endl;
            cout << "Select an ID for a computer: ";
            cin >> computerID;

            if(cin.fail())
            {
                // clears the buffer
                cin.clear();
                cin.ignore(100, '\n');
            }
            if(scientistID == 0)
            {
                inputToReturn();
            }
        }
    }
    _domain.connectComputersAndScientists(scientistID, computerID);
    cout << "Connection successful! " << endl;
    inputToReturn();
}

// Displays a table with file information.
void Presentation::displayPersonsVector(vector<Persons> p)
{
    cout << endl;
    cout << "ID \t" << setw(34) << left << "Name"  << setw(15) << "Gender" << setw(15) << "Born" << setw(15) << "Died" << endl;
    for(int i=0; i<80; i++)
    {
        cout << "-";
    }
    cout << endl;
    if(p.size() > 0)
    {

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
// Prints out the computers vector into a table
void Presentation::displayComputersVector(vector<Computers> c)
{
    string built = "";
    cout << endl;
    cout << "ID \t" << setw(34) << left << "Name"  << setw(15) << "Year" << setw(15) << "Type" << setw(15) << "Successful" << endl;
    for(int i=0; i<82; i++)
    {
        cout << "-";
    }
    cout << endl;
    if(c.size() > 0)
    {

        for(size_t i=0; i< c.size(); i++)
        {
            if(c[i].getCompBuilt())
            {
                built = "Yes";
            }
            else if(!c[i].getCompBuilt())
            {
                built = "No";
            }
            cout << c[i].getCompID() << ".\t" << setw(34) << left << c[i].getCompName() << setw(15) << c[i].getCompYearBuild() << setw(15) << c[i].getCompType() << setw(15) << built << endl;
        }
        cout << endl;
    }else
    {
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
        cout << "Enter one of the following commands: " <<endl;
        cout << endl;
        cout << " m - main menu \n"
                " s - scientist menu \n"
                " c - computer menu \n"
                " q - quit the program " << endl;;
        cout << endl;
        cout << "Your command: ";
        cin >> input;
    }
    while(input != "m" && input != "M" && input != "q" && input != "Q" && input != "s" && input != "S" && input != "c" && input != "C");
    cout << endl;

    if(input == "m" || input == "M")
    {
        startProgram();
    }
    else if(input == "s" || input == "S")
    {
        addScientist();
    }
    else if(input == "c" || input == "C")
    {
        addComputer();
    }
    else if(input == "q" || input == "Q")
    {
        quitDoubt();
    }
}
//Able to rename the variable you choose from the Scientists database
void Presentation::updatePerson()
{
    displayPersonsVector(_domain.getPersons());

    int ID = 0;
    string updateChoice = "";
    string newRecord = "";

    cout << "Enter the ID of the scientist you wish to update: ";
    cin >> ID;
    while(!_domain.validIDTwo(ID, "2"))
    {
        cout << "Error!\n";
        cout << "Enter correct ID: ";
        cin >> ID;

        if(cin.fail())
        {
            // clears the buffer
            cin.clear();
            cin.ignore(100, '\n');
        }
    }
    cout << endl;

    if(cin.fail())
    {
        // clears the buffer
        cin.clear();
        cin.ignore(100, '\n');
    }

    // needs a check if ID exists

    //

    cout << "Enter what you would like to update:\n";
    cout << "n: name | g: gender | b: birth year | d: death year: ";
    cin >> updateChoice;

    while(!_domain.validPersonUpdateChoice(updateChoice))
    {
        cout << "Invalid input!\n";
        cout << "n: name | g: gender | b: birth year | d: death year: ";
        cin >> updateChoice;
    }

    updateChoice = _domain.changePersonUpdateChoice(updateChoice);

    cout << endl;

    cout << "Enter your updated " << updateChoice << ": ";

    if(updateChoice == "Name")
    {
        cin.ignore();
        getline(cin, newRecord); // TODO ! Passa að ekki sé leyfilegt að slá inn tómt nafn !
        while (_domain.validNameCheck(newRecord))
        {
            cout << "Name must only contain alphabet characters A-Z. \n Please enter a valid name: ";
            cin >> newRecord;
        }
    }
    else if(updateChoice == "Gender")
    {
        cin >> newRecord;
        while(!_domain.validUpdateGender(newRecord))
        {
            cout << "Please enter either 'Male' or 'Female': ";
            cin >> newRecord;
        }
    }
    else if(updateChoice == "YearOfBirth")
    {
        cin >> newRecord;
        while (_domain.validYearCheck(newRecord))
        {
            cout << "Wrong input! Please enter 4 digits: ";
            cin >> newRecord;
        }
    }
    else if(updateChoice == "YearOfDeath")
    {
        cout << "Is the person deceased? Y/N: ";
        cin >> newRecord;

        while(_domain.yesOrNoCheck(newRecord) == 2)
        {
            cout << "Wrong input! Please enter Y/N: ";
            cin >> newRecord;
        }

        if(_domain.yesOrNoCheck(newRecord) == 1)
        {
            cout << "Enter year of death: ";
            cin >> newRecord;

            // þarf check if year death is correct
        }
        else if(_domain.yesOrNoCheck(newRecord) == 0)
        {
            newRecord = '-'; // If not dead
        }
    }
    _domain.updatePerson(ID, updateChoice, newRecord);
    displayPersonsVector(_domain.getPersons());
    inputToReturn();
}
//Allows the user to edit information in the Computers database
void Presentation::updateComputer()
{
    displayComputersVector(_domain.getComputers());

    int ID = 0;
    string updateChoice = "";
    string newRecord = "";

    cout << "Enter the ID of the computer you wish to update: ";
    cin >> ID;

    while(!_domain.validIDTwo(ID, "2"))
    {
        cout << "Error!\n";
        cout << "Enter correct ID: ";
        cin >> ID;

        if(cin.fail())
        {
            // clears the buffer
            cin.clear();
            cin.ignore(100, '\n');
        }
    }
    cout << endl;

    if(cin.fail())
    {
        // clears the buffer
        cin.clear();
        cin.ignore(100, '\n');
    }

    cout << "Enter what you would like to update:\n";
    cout << "n: name | y: year built | t: type | b: build successful: ";
    cin >> updateChoice;

    while(!_domain.validComputerUpdateChoice(updateChoice))
    {
        cout << "Invalid input!\n";
        cout << "n: name | y: year built | t: type | b: was built: ";
        cin >> updateChoice;
    }

    updateChoice = _domain.changeComputerUpdateChoice(updateChoice);

    cout << endl;
    if(updateChoice != "Built")
    {
        cout << "Enter your updated " << updateChoice << ": ";
    }

    if(updateChoice == "Name")
    {
        cin.ignore();
        getline(cin, newRecord);
        while (!_domain.emptyStringCheck(newRecord))
        {
            cout << "Name cannot be empty. "<< endl;
            cout << "Please enter a valid name: ";
            cin >> newRecord;
        }
    }
    else if(updateChoice == "YearBuilt")
    {
        cin >> newRecord;
        while (_domain.validYearCheck(newRecord))
        {
            cout << "Wrong input! Please enter 4 digits: ";
            cin >> newRecord;
        }
    }
    else if(updateChoice == "Type")
    {
        vector<string> types =_domain.getComputersTypes();
        for(size_t i = 0; i<types.size(); i++)
        {
            cout << i+1 << ". " << types[i]<<endl;
        }
        cin.ignore();
        getline(cin, newRecord); // TODO ! Passa að ekki sé leyfilegt að slá inn tómt nafn !

        while(stoi(newRecord) < 0 && stoi(newRecord) > types.size())
        {
            cout << "Please enter a valid number from 1 - " << types.size() << " : " << endl;
            cin >> newRecord;
        }

        newRecord = types[stoi(newRecord) -1];
    }
    else if(updateChoice == "Built")
    {

    }
    _domain.updateComputer(ID, updateChoice, newRecord);
    displayComputersVector(_domain.getComputers());
    inputToReturn();
}
