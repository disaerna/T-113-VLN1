#include "presentation.h"
#include "persons.h"

using namespace std;

Presentation::Presentation()
{

}

void Presentation::newPersonsinFile()
{
    Persons newPerson;
    int number = 0;
    string name1;
    string gender1;
    string yearOfBirth1;
    string yearOfDeath1;
    string answer;
    string currentYear;

    currentYear = _domain.currentYear();

    cout << "How many persons would you like to input: ";
    cin >> number;

    if(cin.fail())
    {

        // clears the buffer
        cin.clear();
        cin.ignore(100, '\n');
    }

    for(int i=0; i<number; i++)
    {
        cout << "-------------" << endl;
        cout << "Person " << i+1 << " of " << number << endl;
        cout << "-------------" << endl;
        cout << "Enter name: ";
        cin.ignore();
        getline(cin, name1); // tekur fullt nafn

        if ( _domain.validNameCheck(name1))
        {
            while ( _domain.validNameCheck(name1) )
            {
                cout << "Name must only contain alphabet characters A-Z. \n Please enter a valid name." << endl;
                cin >> name1;
            }
        }
        //Vantar að gera fallakall sem sendir inn strenginn castar honum í lower case og checkar hvort sett var inn male eða female og svarar viðeigandi
        cout << "Enter gender M/F: ";
        cin >> gender1;
        while(!_domain.validGenderCheck(gender1))
        {
            cout << "Please enter either 'M' for male or 'F' for female: ";
            cin >> gender1;
        }

        gender1 = _domain.setGender(gender1); // setur M/m = male & F/f = female
        cout << "Enter year of birth: ";
        cin >> yearOfBirth1;
        if(_domain.futureBabies(yearOfBirth1))
        {
            cout << "Wrong input! Please enter a valid year: ";
            cin >> yearOfBirth1;
        }
        while (_domain.validBirthYearCheck(yearOfBirth1))
        {
            cout << "Wrong input! Please enter 4 digits: ";
            cin >> yearOfBirth1;
        }

        cout << "Is the person deceased? Y/N: ";

        cin >> answer;
        //Vantar að setja inn fallakall á þessi
        //
        //
        //
        if(_domain.isDeadCheck(answer))
        {
            cout << "Enter year of death: ";
            cin >> yearOfDeath1;

            while( _domain.validDeathYearCheck(yearOfBirth1, yearOfDeath1))
            {
                cout << "People can't die before they're born! And no messing with spacetime continuum. \n";
                cout << "Wrong input! Please enter 4 digits." << endl;
                cout << "Enter year of death: ";
                cin >> yearOfDeath1;
            }
        }
        else if(!_domain.isDeadCheck(answer))
        {
            yearOfDeath1 = '-';
        }
        cout << endl;

        newPerson.setPersons(name1, gender1, yearOfBirth1, yearOfDeath1);
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

void Presentation::removePerson()
{
    //vector<Persons> getPerson;
    //getPerson = _domain.getPersons();
    //_domain.getPersons() returns a vector which can be sent right into the displayVector function
    displayVector(_domain.getPersons());

    int numberOfPerson = 0;

    cout << "Enter the number of person you wish to delete from the database: ";
    cin >> numberOfPerson;
    if(cin.fail())
    {
        // clears the buffer
        cin.clear();
        cin.ignore(100, '\n');
    }

    string deletedName = _domain.deletePersonFromFile(numberOfPerson);
    cout << deletedName << " has been deleted from the database." << endl;
    cout << endl;
    inputToReturn();
}

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

    // allt föll inní domain ! sortera
    // öll föll hér inní þurfa að nota readPersonsFromFile fallið í data !

    int viewInput = 10;
    cout << "Enter your choice: ";
    cin >> viewInput;
    if(cin.fail())
    {
        // clears the buffer
        cin.clear();
        cin.ignore(100, '\n');
    }

    vector<Persons> getPerson;
    getPerson = _domain.getPersons();

    displayVector(_domain.SortPersons(getPerson, viewInput));

    inputToReturn();
}

void Presentation::searchDatabase()
{
    // fall inní domain ! leitar
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

    //  if the user chooses to search by name
    //  we need to link the Person vector to the vector
    //  we use the searchName function in the Domain class
    //  our vector results gets the indexes searchName gave us
    //  we display the results
    //  we clean the vector so that the user can search again

    if(userChoice == 1)                 //Leita eftir nafni.
    {
        searchByName();
    }
    else if(userChoice == 2)            //Leita eftir kyni.
    {
        searchByGender();
    }
    else if(userChoice == 3)            //Leita eftir fæðingarári.
    {
        searchByBirthYear();
    }
    else if(userChoice == 4)            //Leita eftir dánarári.
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
    else if(cin.fail())
    {
        // clears the buffer
        cin.clear();
        cin.ignore(100, '\n');
    }
}

void Presentation::searchByName()
{
    vector<Persons> personVector;
    personVector = _domain.getPersons(); // get the vector from file input
    vector<int> results;
    string nameInput = " ";

    cout << "Enter a name to search: ";
    cin >> nameInput;
    cout << endl;

    _domain.searchName(personVector, nameInput);
    results = _domain.getResults();

    // error check to check if the user has input only letters
    if (nameInput.find_first_not_of("qwertyuiopasdfghjklzxcvbnmQWERTYUIOPASDFGHJKLZXCVBNM ") != std::string::npos)
    {
        while ( nameInput.find_first_not_of("qwertyuiopasdfghjklzxcvbnmQWERTYUIOPASDFGHJKLZXCVBNM ") != std::string::npos )
        {
            cout << "Name must only contain alphabet characters A-Z. \nPlease enter a valid name: ";
            cin >> nameInput;
        }
    }

    string commandInput = "";

    // if the search returns nothing, it will show on the screen
    if(results.size() < 1 && commandInput != "r" && commandInput != "s") {
        cout << "No results to display!" << endl;
        cout << endl;
        while(commandInput != "s" && commandInput != "S" && commandInput != "r" && commandInput != "R") {
            cout << "Enter 's' to search again or 'r' to return to main menu: ";
            cin >> commandInput;
            if(commandInput == "s" || commandInput == "S") {
                   searchByName(); // user returns to search by name
            }
            else if(commandInput == "r" || commandInput == "R") {
                program(); // user returns to main menu
            }
        }
    }
    // if the search returns >0 results, a table will be displayed
    else if(results.size() > 0) {
        displaySearchResults(personVector, results);
        _domain.cleanVector(results);
        while(commandInput != "s" && commandInput != "S" && commandInput != "r" && commandInput != "R") {
            cout << "Enter 's' to search again or 'r' to return to main menu: ";
            cin >> commandInput;
            if(commandInput == "s" || commandInput == "S") {
                   searchByName();
            }
            else if(commandInput == "r" || commandInput == "R") {
                program();
            }
        }
    }

}

void Presentation::searchByGender()
{

    vector<Persons> personVector;
    personVector = _domain.getPersons();
    vector<int> results;

    string genderInput = "m";
    int counter = 0;

    do
    { // if the string doesn't match, then this will loop
        if(counter > 0) {
            cout << endl;
            cout << "Error: Please input the correct character" << endl;
            cout << endl;
        }
        cout << "Enter 'Male' for male results" << endl;
        cout << "Enter 'Female' for female results" << endl;
        cout << "Enter your choice: ";
        cin >> genderInput;
        counter++;
    }
    while(genderInput != "Male" && genderInput != "Female");

    string commandInput = "";
    _domain.searchGender(personVector, genderInput);
    results = _domain.getResults();

    if(results.size() < 1 && commandInput != "r" && commandInput != "s") {
        cout << "No results to display!" << endl;
        cout << endl;
        while(commandInput != "s" && commandInput != "S" && commandInput != "r" && commandInput != "R") {
            cout << "Enter 's' to search again or 'r' to return to main menu: ";
            cin >> commandInput;
            if(commandInput == "s" || commandInput == "S") {
                   searchByGender();
            }
            else if(commandInput == "r" || commandInput == "R") {
                program();
            }
        }
    }
    else if(results.size() > 0) {
        displaySearchResults(personVector, results);
        _domain.cleanVector(results);
        while(commandInput != "s" && commandInput != "S" && commandInput != "r" && commandInput != "R") {
            cout << "Enter 's' to search again or 'r' to return to main menu: ";
            cin >> commandInput;
            if(commandInput == "s" || commandInput == "S") {
                   searchByGender();
            }
            else if(commandInput == "r" || commandInput == "R") {
                program();
            }
        }
    }
}

void Presentation::searchByBirthYear()
{
    vector<Persons> personVector;
    personVector = _domain.getPersons();
    vector<int> results;
    string birthYear = " ";

    cout << "Enter birth year: ";
    cin >> birthYear;

    while(birthYear.find_first_not_of("0123456789")!= std::string::npos || birthYear.length() != 4) {
        cout << "Wrong input! Please enter 4 digits: ";
        cin >> birthYear;
    }

    _domain.searchBirthYear(personVector, birthYear);
    results = _domain.getResults();

    string commandInput = "";
    if(results.size() < 1 && commandInput != "r" && commandInput != "s") {
        cout << "No results to display!" << endl;
        cout << endl;
        while(commandInput != "s" && commandInput != "S" && commandInput != "r" && commandInput != "R") {
            cout << "Enter 's' to search again or 'r' to return to main menu: ";
            cin >> commandInput;
            if(commandInput == "s" || commandInput == "S") {
                   searchByBirthYear();
            }
            else if(commandInput == "r" || commandInput == "R") {
                program();
            }
        }
    }
    else if(results.size() > 0) {
        displaySearchResults(personVector, results);
        _domain.cleanVector(results);
        while(commandInput != "s" && commandInput != "S" && commandInput != "r" && commandInput != "R") {
            cout << "Enter 's' to search again or 'r' to return to main menu: ";
            cin >> commandInput;
            if(commandInput == "s" || commandInput == "S") {
                   searchByBirthYear();
            }
            else if(commandInput == "r" || commandInput == "R") {
                program();
            }
        }
    }

}

void Presentation::searchByDeathYear()
{
    vector<Persons> personVector;
    personVector = _domain.getPersons();
    vector<int> results;
    string deathYear = " ";

    cout << "Enter year of death (enter '-' for living persons): ";
    cin >> deathYear;

    // if the death year is not all numbers and not 4 characters, the program will loop until he inputs the correct input
    while(deathYear.find_first_not_of("0123456789")!= std::string::npos || deathYear.length() != 4) {
        if(deathYear == "-") { // if the user inputs '-', or not deceased, the user will break out of the loop
            break;
        }
        cout << "Wrong input! Please enter 4 digits or '-': ";
        cin >> deathYear;
    }

    _domain.searchDeathYear(personVector, deathYear);
    results = _domain.getResults();

    string commandInput = "";
    if(results.size() < 1 && commandInput != "r" && commandInput != "s") {
        cout << "No results to display!" << endl;
        cout << endl;
        while(commandInput != "s" && commandInput != "S" && commandInput != "r" && commandInput != "R") {
            cout << "Enter 's' to search again or 'r' to return to main menu: ";
            cin >> commandInput;
            if(commandInput == "s" || commandInput == "S") {
                   searchByDeathYear();
            }
            else if(commandInput == "r" || commandInput == "R") {
                program();
            }
        }
    }
    else if(results.size() > 0) {
        displaySearchResults(personVector, results);
        _domain.cleanVector(results);
        while(commandInput != "s" && commandInput != "S" && commandInput != "r" && commandInput != "R") {
            cout << "Enter 's' to search again or 'r' to return to main menu: ";
            cin >> commandInput;
            if(commandInput == "s" || commandInput == "S") {
                   searchByDeathYear();
            }
            else if(commandInput == "r" || commandInput == "R") {
                program();
            }
        }
    }
}

void Presentation::program()
{
    int input = 0;
    do
    {   // Það fyrsta sem birtist á skjá notanda.
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

        if(input == 1)              // Ef valið er 1 bætist ný manneskja í database.
        {
            newPersonsinFile();
        }
        else if(input == 2)         // Ef valið er 2 eyðum við manneskju úr database.
        {
            removePerson();
        }
        else if(input == 3)         // Ef valið er 3 bjóðum við valmöguleika til að skoða database.
        {
            viewDatabase();
        }
        else if(input == 4)         // Search the database.
        {
            searchDatabase();
        }
        else if(input == 5) {
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
        else if(cin.fail())
        {
            // clears the buffer
            cin.clear();
            cin.ignore(100, '\n');
        }
    }while (input != 6);        //Fer aftur inn í menu gluggan.
}

void Presentation::displayVector(vector<Persons> p) //Uppröðun töflu.
{
    // cout << "Fer inni displayVector" << endl;

    cout << endl;
    cout << "Nr.\t" << setw(34) << left << "Name"  << setw(15) << "Gender" << setw(15) << "Born" << setw(15) << "Died" << endl;
    for(int i=0; i<80; i++)
    {
        cout << "-";
    }
    cout << endl;
    for(size_t i=0; i< p.size(); i++)
    {
        cout << (i+1) << ".\t" << setw(34) << left << p[i].getName() << setw(15) << p[i].getGender() << setw(15) << p[i].getYearOfBirth() << setw(15) << p[i].getYearOfDeath()<< endl;
    }
    cout << endl;
}

// prints out only information about the indexes that match the search
// þarf að raða betur
void Presentation::displaySearchResults(vector<Persons> p, vector<int> results)
{
    int number = 0;

    cout << endl;
    cout << "Nr.\t" << setw(34) << left << "Name"  << "Gender" << "\t" << "Born" << "\t" << "Died" << endl;
    for(int i=0; i<80; i++)
    {
        cout << "-";
    }
    cout << endl;
    for(size_t i=0; i< results.size(); i++)
    {
        number = results[i];
        cout << (i+1) << ".\t" << setw(34) << left << p[number].getName() << p[number].getGender() << "\t" << p[number].getYearOfBirth() << "\t" << p[number].getYearOfDeath()<< endl;
    }
    cout << endl;
}

// function to stop the user to exit immediately back to the main menu, allowing the user to view the data requested
void Presentation::inputToReturn()
{
    string input = "";
    // the program will loop until user inputs the right command
    do
    {
        cout << "Enter 'r' to return to main menu or 'q' to quit the program: ";
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

void Presentation::splashMessage()
{
    // endl í byrjun
    cout << endl;

    // lína uppi
    for(int i = 0; i < 1; i++)
    {
        for(int j = 0; j < 40; j++)
        {
            cout << "*";
        }
        cout << endl;
    }

    // önnur lína
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

    // þriðja lína
    for(int i = 0; i < 1; i++)
    {
        for(int j = 0; j < 40; j++)
        {
            cout << "*";
        }
        cout << endl;
    }

    // eitt endl í lokin
    cout << endl;
}
