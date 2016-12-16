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

        while (_domain.validBirthYearCheck(yearOfBirth))
        {
            cout << "Wrong input! Please enter 4 digits: ";
            cin >> yearOfBirth;
        }

        cout << "Is the person deceased? Y/N: ";
        cin >> answer;

        while(_domain.isDeadCheck(answer) == 2)
        {
            cout << "Wrong input! Please enter Y/N" << endl;
            cin >> answer;
        }

        if(_domain.isDeadCheck(answer) == 1)
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
        else if(_domain.isDeadCheck(answer) == 0)
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

// Removes person
void Presentation::removePerson()
{
    displayVector(_domain.getPersons());

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

    displayVector(_domain.getPersons());
    inputToReturn();
}

// View menu
void Presentation::viewDatabase()
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

    displayVector(_domain.sortPersons(viewInput));
    inputToReturn();
}

// Searches the database(file).
void Presentation::searchDatabase()
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
        program();
    }
    else
    {
        // clears the buffer
        cin.clear();
        cin.ignore(100, '\n');
        cout << "Wrong input!" << endl;
        cout << endl;
        searchDatabase();
    }
}

void Presentation::searchByName()
{
    string nameInput = " ";

    cout << "Enter a name to search: ";
    cin >> nameInput;
    cout << endl;

    displayVector( _domain.searchName(nameInput));
    inputToReturn();
}

void Presentation::searchByGender()
{
    string genderInput = " ";

    cout << "Enter 'M' for male results" << endl;
    cout << "Enter 'F' for female results" << endl;
    cout << ": ";
    cin >> genderInput;

    displayVector(_domain.searchGender(genderInput));
    inputToReturn();
}

void Presentation::searchByBirthYear()
{
    string birthYear = " ";

    cout << "Enter birth year: ";
    cin >> birthYear;

    displayVector( _domain.searchBirthYear(birthYear));
    inputToReturn();
}

void Presentation::searchByDeathYear()
{
    string deathYear = " ";

    cout << "Enter death year: ";
    cin >> deathYear;

    displayVector(_domain.searchDeathYear(deathYear));
    inputToReturn();
}

// Main program that gets called from main.
void Presentation::program()
{
    int input = 0;
    do
    {   // Displays a menu for user

        cout << "Please enter one of the following commands: " << endl;
        cout << "1 - Add a new person to the database" << endl;
        cout << "2 - Delete a person from the database" << endl; // TODO - EXTRA
        cout << "3 - View the database" << endl;
        cout << "4 - Search the database" << endl;
        cout << "5 - Quit the program" << endl;
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
            viewDatabase();
        }
        else if(input == 4)
        {
            searchDatabase();
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
void Presentation::displayVector(vector<Persons> p)
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

// Asks user to return to main or quit the program.
void Presentation::inputToReturn()
{
    string input = "";
    // the program will loop until user inputs the right command
    do
    {
        cout << "Enter 'R' to return to main menu or 'Q' to quit the program: ";
        cin >> input;
    }
    while(input != "r" && input != "R" && input != "q" && input != "Q");
    cout << endl;

    // asking user if he is sure he wants to quit the program
    if(input != "r" && input != "R") {
        string userQuitting = "";
        while(userQuitting != "N" && userQuitting != "n" && userQuitting != "Y" && userQuitting != "y") {
            cout << "Are you sure that you want to quit the program?" << endl;
            cout << "Y/N: ";
            cin >> userQuitting;
        }
        if(userQuitting != "N" && userQuitting != "n") {
            // exit = quitting the program
            exit(1);
        }
    }
    cout << endl;
}

// Message that prints out when program begins.
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
