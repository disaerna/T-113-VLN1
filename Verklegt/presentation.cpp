#include "presentation.h"

using namespace std;

Presentation::Presentation()
{

}

void Presentation::startProgram()
{

    int input = 0;
    cout << "Verk Solutions v.2.0 -- Main menu:\n";
    cout << "----------------------------------\n";
    cout << "Please select one of the options below\n";
    cout << "----------------------------------\n";
    cout << "1. Scientists\n";
    cout << "2. Computers\n";
    cout << "3. Scientists and computers\n";
    cout << "4. Quit the program\n";

    cout << "----------------------------------\n";
    cout << "Enter your command: ";
    cin >> input;




    while(input < 1 || input > 3)

    {
        cout << "Please enter a correct input: ";
        cin >> input;
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
        getline(cin, name); // TODO ! Passa að ekki sé leyfilegt að slá inn tómt nafn !
        while (_domain.validNameCheck(name))
        {
            cout << "Name must only contain alphabet characters A-Z. \n Please enter a valid name: " << endl;
            cin >> name;
        }
        if(name == " ")
        {
            cout << "\n Name cannot be empty. \n Please enter a valid name: " << endl;
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

    /*
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
    */

    inputToReturn();
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
        getline(cin, name); // tekur fullt nafn

        while (_domain.validNameCheck(name))
        {
            cout << "Name must only contain alphabet characters A-Z. \n Please enter a valid name." << endl;
            cin >> name;
        }
        if(name == " ")
        {

            cout << "\n Name cannot be empty. \n Please enter a valid name: " << endl;
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

                for(int i = 0; i<types.size(); i++)
                {
                    cout << i+1 << ". " << types[i]<<endl;
                }
                cout<<"Is the type of your computer in the list above? Please enter Y/N: "<<endl;

                cin>>answer;
                while(_domain.yesOrNoCheck(answer) == 2)
                {
                    cout << "Wrong input! Please enter Y/N: " << endl;
                    cin >> answer;
                }
                if(_domain.yesOrNoCheck(answer) == 1)
                {
                    cout << " Please enter the number for the type of computer you wish to register: " << endl;
                    cin >> chooseType;

                    while(chooseType < 0 && chooseType > types.size())
                    {
                        cout << "Please enter a valid number from 1 - "<<types.size()<<" : "<< endl;
                        cin>>chooseType;
                    }
                    type = types[chooseType -1];

                    //Villutékk hvort týpan sé til
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

        // villutjékk fyrir týpur
        // sýna töflu með ´týpum & spurja notenda hvort týpan sé til staðar i töflunni annars gera notanda kleift að bæta við týpu

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

        newComp.setComputers(3, name, yearOfBuild, type, built); // tjekka betur á ID inntaki
        _domain.addComputer(newComp);
    }

    cout << "Your input has been saved..." << endl;
    cout << endl;

    cout << "You added these computers to the database: " << endl;
    cout << name << endl;
    cout << endl;

    inputToReturn();
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
    displayComputersVector(_domain.getComputers());

    int ID = 0;

    cout << "Enter the ID of the computer you wish to delete from the database: ";
    cin >> ID;
    cout << endl;

    if(cin.fail())
    {
        // clears the buffer
        cin.clear();
        cin.ignore(100, '\n');
    }

    string deletedComputer = _domain.getSingleComputer(ID).getCompName();
    bool success = _domain.deleteComputerFromDatabase(ID);
    while(!success)
    {
        cout << "Please enter a valid ID: ";
        cin >> ID;

        deletedComputer = _domain.getSingleComputer(ID).getCompName();
        success = _domain.deleteComputerFromDatabase(ID);
    }
    cout << deletedComputer << " has been deleted from the database." << endl;
    cout << endl;

    displayComputersVector(_domain.getComputers());
    inputToReturn();
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
        inputToReturn();
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
        inputToReturn();
    }
    else
    {
        displayComputersVector(_domain.sortComputers(viewInput));
        inputToReturn();
    }

    // Kalla á fall í domain sem tekur inn val notenda(tölu) sem kallar á data & birtir einungis þær uppl.

    //displayPersonsVector(_domain.sortPersons(viewInput));
    //inputToReturn();
}
void Presentation::viewScientistConnection()
{
    displayPersonsVector(_domain.getPersons());

    int ID;
    cout << endl;
    cout << "Enter ID for a scientist: " << endl;
    cin >> ID;
    while(_domain.getSinglePerson(ID).getName() == " ")
    {
        cout << "Please enter a valid ID: ";
        cin >> ID;
    }

    displayComputersVector(_domain.getScientistToComputer(ID));
}
void Presentation::viewComputerConnection()
{
    displayComputersVector(_domain.getComputers());

    int ID;
    cout << endl;
    cout << "Enter ID for a computer: " << endl;
    cin >> ID;
    while(_domain.getSingleComputer(ID).getCompName() == " ")
    {
        cout << "Please enter a valid ID: ";
        cin >> ID;
    }

    displayPersonsVector(_domain.getComputerToScientist(ID));
}
// Searches the database(file).
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
    vector<Persons> searchResults;

    if(userChoice == 1)
    {
        cout << "Enter a name to search for: ";
        cin.ignore();
        getline(cin, searchTerm); // tekur fullt nafn
        // villutékk
        while (_domain.validNameCheck(searchTerm))
        {
            cout << "Name must only contain alphabet characters A-Z. \n Please enter a valid name." << endl;
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
        // villutékk
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

        // villutékk
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

        // villutékk
        while(_domain.yesOrNoCheck(searchTerm) == 2)
        {
            cout << "Wrong input! Please enter Y/N" << endl;
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
    vector<Computers> searchResults;

    if(userChoice == 1)
    {
        cout << "Enter name: ";
        cin.ignore();
        getline(cin, searchTerm); // tekur fullt nafn


        searchResults = _domain.getComputersSearch(searchTerm, userChoice);
        displayComputersVector(searchResults);
        inputToReturn();

    }
    else if(userChoice == 2)
    {
        cout << "Enter built year: ";
        cin >> searchTerm;

        // villutékk
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
            cout << "Wrong input! Please enter Y/N" << endl;
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

        // þarf villutékk til að tékka hvort aðeins var stimplað inn "y eða n"

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
    cout << "2 - Delete a scientist from the database " << endl;
    cout << "3 - View the scientist database " << endl;
    cout << "4 - View computer for a scientist " << endl;
    cout << "5 - Connect a scientist to a computer " << endl;
    cout << "6 - Search the scientist database " << endl;
    cout << "7 - Return to main menu " << endl;
    cout << "8 - Quit the program " << endl;
    cout << endl;
    cout << "Enter your choice: ";
    cin >> input;

    while(input < 1 || input > 8)
    {
        cout << "Please input a correct number: ";
        cin >> input;
    }

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

        viewScientistConnection();
    }
    else if(input == 5)
    {
        connectScientist();
    }
    else if(input == 6)
    {
       searchPersonDatabase();
    }
    else if(input == 7)
    {
        startProgram();
    }
    else if(input == 8)
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

void Presentation::addComputer()
{
    int input = 0;
    do
    {   // Displays a menu for user

        cout << "Please enter one of the following commands: " << endl;
        cout << "1 - Add a new computer to the database" << endl;
        cout << "2 - Delete a computer from the database" << endl; // TODO - EXTRA
        cout << "3 - View the computer database" << endl;
        cout << "4 - View scientists for a computer" << endl;
        cout << "5 - Connect a computer to a scientist" << endl;
        cout << "6 - Search the computer database" << endl;
        cout << "7 - Return to main menu\n";
        cout << "8 - Quit the program\n";

        cout << endl;
        cout << "Enter your choice: ";
        cin >> input;
        cout << endl;


        while(input < 1 || input > 8)
        {
            cout << "Please input a correct number: ";
            cin >> input;
        }

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
            viewComputerConnection();
        }
        else if(input == 5)
        {
            connectComputer();
        }
        else if(input == 6)
        {
            searchComputersDatabase();
        }

        else if(input == 7)
        {
            startProgram();
        }
        else if (input == 8)
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
void Presentation::connectComputer()
{
    int computerID;
    int scientistID;
    displayComputersVector(_domain.getComputers());
    cout << "Select an ID for a computer: " << endl;
    cin >> computerID;
    displayPersonsVector(_domain.getPersons());
    cout << "Select an ID for a scientist: " << endl;
    cin >> scientistID;
    _domain.connectComputersAndScientists(scientistID, computerID);

}
void Presentation::connectScientist()
{
    int computerID;
    int scientistID;
    displayPersonsVector(_domain.getPersons());
    cout << "Select an ID for a scientist: " << endl;
    cin >> scientistID;
    displayComputersVector(_domain.getComputers());
    cout << "Select an ID for a computer: " << endl;
    cin >> computerID;
    _domain.connectComputersAndScientists(scientistID, computerID);

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
    cout << "Nr.\t" << setw(34) << left << "Name"  << setw(15) << "Year" << setw(15) << "Type" << setw(15) << "Successful" << endl;
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
        cout << "Enter one of the following commands:\n";
        cout << "| 'm' - main menu | 's' - scientist menu | 'c' - computer menu | 'q' - quit the program |\n";
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

/*
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
*/
