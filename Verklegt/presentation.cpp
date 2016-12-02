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

            while ( _domain.validNameCheck(name1) )
            {
                cout << "Name must only contain alphabet characters A-Z. \n Please enter a valid name." << endl;
                cin >> name1;
            }

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
        /*if(_domain.futureBabies(yearOfBirth1))
        {
            cout << "Wrong input! Please enter a valid year: ";
            cin >> yearOfBirth1;
        }*/
        while (_domain.validBirthYearCheck(yearOfBirth1))
        {
            cout << "Wrong input! Please enter 4 digits: ";
            cin >> yearOfBirth1;
        }

        cout << "Is the person deceased? Y/N: ";

        cin >> answer;

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
    while(!_domain.validDeleteOfPerson(numberOfPerson))
    {
        cout << "Please enter a valid number from 1 - " << _domain.getPersons().size() << ": ";
        cin >> numberOfPerson;
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
    if(cin.fail()) // athuga þetta betur ? hvað gerir eþtta
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
    _domain.setUserInput(userChoice);

    //  if the user chooses to search by name
    //  we need to link the Person vector to the vector
    //  we use the searchName function in the Domain class
    //  our vector results gets the indexes searchName gave us
    //  we display the results
    //  we clean the vector so that the user can search again

    if(userChoice >0 && userChoice <5)                 //Leita eftir nafni.
    {
       searchLogic();
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

/*

void Presentation::searchByName()
{
    vector<Persons> personVector = _domain.getPersons(); // get the vector from file input
    vector<int> results;
    string nameInput = " ";

    cout << "Enter a name to search: ";
    cin >> nameInput;
    cout << endl;

    displaySearchResults(_domain.searchName(personVector, nameInput));
    inputToReturn();
}
void Presentation::searchByGender()
{
    vector<Persons> personVector = _domain.getPersons();
    string genderInput = " ";

    cout << "Enter 'M' for male results" << endl;
    cout << "Enter 'F' for female results" << endl;
    cin >> genderInput;

    displaySearchResults(_domain.searchGender(personVector, genderInput));
    inputToReturn();
}
void Presentation::searchByBirthYear()
{
    vector<Persons> personVector = _domain.getPersons();
    string birthYear = " ";

    cout << "Enter birth year";
    cin >> birthYear;

    displaySearchResults(_domain.searchBirthYear(personVector, birthYear));
    inputToReturn();
}
void Presentation::searchByDeathYear()
{
    vector<Persons> personVector = _domain.getPersons();
    string deathYear = " ";

    cout << "Enter death year";
    cin >> deathYear;

    displaySearchResults(_domain.searchDeathYear(personVector, deathYear));
    inputToReturn();
}

*/

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
        else if(cin.fail())
        {
            // clears the buffer
            cin.clear();
            cin.ignore(100, '\n');
        }
    }while (input != 5);        //Fer aftur inn í menu gluggan.
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
void Presentation::displaySearchResults(vector<Persons> results)
{
    cout << endl;
    cout << "Nr.\t" << setw(34) << left << "Name"  << "Gender" << "\t" << "Born" << "\t" << "Died" << endl;
    for(int i=0; i<80; i++)
    {
        cout << "-";
    }
    cout << endl;
    for(size_t i=0; i< results.size(); i++)
    {
        cout << (i+1) << ".\t" << setw(34) << left << results[i].getName() << results[i].getGender() << "\t" << results[i].getYearOfBirth() << "\t" << results[i].getYearOfDeath()<< endl;
    }
    cout << endl;
}

void Presentation::inputToReturn()
{
    // ??
    int input = 0;

    cout << "Enter '1' to return to main menu, any button to quit";
    cin >> input;

    cout << endl;
}




//////////////////////////


void Presentation::search() {
    int userChoice = _domain.getUserInput();
    string searchInput = "";
    if(userChoice == 1) {
        cout << "Enter a name to search: ";
        cin >> searchInput;
    }
    else if(userChoice == 2) {
        cout << "Enter 'm' for male results" << endl;
        cout << "Enter 'f' for female results" << endl;
        cout << "Enter your choice: ";
        cin >> searchInput;
    }
    else if(userChoice == 3) {
        cout << "Enter birth year: ";
        cin >> searchInput;
    }
    else if(userChoice == 4) {
        cout << "Enter year of death (enter '-' for living persons): ";
        cin >> searchInput;
    }
    _domain.setSearchInput(searchInput);
}

void Presentation::noResults() {
    cout << "No results to display! Try another search term." << endl;
}

/*

void Presentation::showResults() {
    _domain.showSearchResults();
    searchAgain();
    string commandInput = _domain.getCommandInput();
}

*/

void Presentation::searchAgain() {
    string commandInput;
    cout << "Enter 's' to search again or 'r' to return to main menu: ;";
    cin >> commandInput;
    _domain.setCommandInput(commandInput);
}

void Presentation::searchLogic() {
    vector<Persons> results;

    Presentation::search();

    _domain.searchAlgo();

    results = _domain.searchAlgo();



    // error check if input matches the search


/*
    _domain.showSearchResults();
    */
}


/*

void Domain::showSearchResults() {
    vector<Persons> results;
    results = searchAlgo();
    string commandInput = Domain::getCommandInput();
    if(results.size() < 1) { // no results
        Presentation::noResults();
        Presentation::searchAgain();
        while(commandInput != "s" && commandInput != "S" && commandInput != "r" && commandInput != "R") {
            Domain::searchAgainLogic();
            commandInput = Domain::getCommandInput;
        }
    }
    else if(results.size() > 0) { // results found
        displaySearchResults(personVector, results);
        while(commandInput != "s" && commandInput != "S" && commandInput != "r" && commandInput != "R") {
            Domain::searchAgainLogic()
        }
    }
}

*/





















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
