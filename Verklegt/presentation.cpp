#include "presentation.h"
#include "persons.h"
#include <string>
#include <iostream>
#include <vector>
#include <fstream>
#include <iterator>
#include <algorithm>


using namespace  std;


Presentation::Presentation()
{

}

<<<<<<< Updated upstream
void Presentation::program()
{
=======
void displayVector(vector<Persons> p);

void Presentation::program()
{

>>>>>>> Stashed changes

    cout << "Please enter one of the following commands: " << endl;
    cout << "add - Add a new person to the database" << endl;
    cout << "delete - Delete a person from the database" << endl; // TODO - EXTRA
    cout << "view - View the database" << endl;
    cout << "search - Search the database" << endl;
    cout << "quit - Quit the program" << endl;

    string input = " ";

    cin >> input;

<<<<<<< Updated upstream
    if(input == "add" || input == "Add" || input == "ADD")
    {
        string name1;
        string gender1;
        string yearOfBirth1;
        string yearOfDeath1;
=======
    if(input == "add" || input == "Add" || input == "ADD") {

        string name;
        string gender;
        int DOB;
        int DOD;
>>>>>>> Stashed changes
        Persons newPerson;
        int number = 0;

        cout << "How many persons would you like to input: " << endl;
        cin >> number;
<<<<<<< Updated upstream
=======
        for(int i=0; i<number; i++)
        {
>>>>>>> Stashed changes

        for(int i=0; i<number; i++)
        {
            cout << "Enter name: ";
            cin >> name;
            cout << "Enter gender: ";
            cin >> gender;
            cout << "Enter year of birth: ";
            cin >> DOB;
            cout << "If deceased enter year of death, else enter 0: ";
            cin >> DOD;

            newPerson.setPersons(name, gender, DOB, DOD);

            _domain.addPersons(newPerson);
        }
    }
<<<<<<< Updated upstream
    else if(input == "delete" || input == "Delete" || input == "DELETE")
    {
=======


    /*else if(input == "delete" || input == "Delete" || input == "DELETE")
    {

>>>>>>> Stashed changes
        // delete person from the database
        // fara inní nýja klasann sem sér um að deleta & adda
    }

    */
    else if(input == "view" || input == "View" || input == "VIEW")
    {
        cout << "How would you like view the database? " << endl;
    }

        cout << "1. Default" << endl;
        cout << "2. Name: A-Z" << endl;
        cout << "3. Name: Z-A" << endl;
        cout << "4. Gender: F-M" << endl;
        cout << "5. Gender: M-F" << endl;
        cout << "6. Birth Year: Desc." << endl;
        cout << "7. Birth Year: Asc." << endl;
        cout << "8. Death Year: Desc." << endl;
        cout << "9. Death Year: Asc." << endl;

        // allt föll inní domain ! sortera
        // öll föll hér inní þurfa að nota readPersonsFromFile fallið í data !

        int viewInput = 0;
        cin >> viewInput;

        vector<Persons> getPerson;
        getPerson = _domain.getPersons();

        _domain.SortPersons(getPerson);



   /* else if(input == "search" || input == "Search" || input == "SEARCH")
    {
        // search the database
        // fall inní domain ! leitar
    }
    else if(input == "quit" || input == "Quit" || input == "QUIT")
    {

            // hætta í forriti

    }
    else
    {
            // villutékk
        cout << "Please enter a valid command!" << endl;

    }
*/
}

void Presentation::displayVector(vector<Persons> p)
{
    // raða betur upp í töflu, ef t.d langt nafn
    //cout << "Fer inni displayVector" << endl;
    cout << endl;
    cout << "Nr. Name" << "\t" << "Gender" << "\t" << "Year of birth" << "\t" << "Year of death" << "\t" << endl;
    cout << "----------------------------------------------" << endl;
    for(int i=0; i< p.size(); i++)
    {

        cout << (i+1) << ".  " <<p[i].getName() << "\t" << p[i].getGender() << "\t" << p[i].getYearOfBirth() << "\t" << "\t" << p[i].getYearOfDeath()<< endl;
    }
}




