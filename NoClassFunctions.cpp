#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <limits>
#include <cstdlib>
#include <cstdio>
#include <regex>
#include <conio.h>

#include "NoClassFunctions.h"

using std::cout;
using std::cin;
using std::string;
using std::endl;

std::ostream &operator<<(std::ostream &os, Employee::Gender &obj)
{   
    switch (obj)
    {
        case Employee::Gender::MALE: os << "MALE"; break;
        case Employee::Gender::FEMALE: os << "FEMALE"; break;
        default: os << "NOT_SET";
    }
    
    return os;
};

std::istream &operator>>(std::istream &is, Employee::Gender &obj)
{   
    std::string input;
    is >> input;


    if (input == "MALE")
    {
        obj = Employee::Gender::MALE;
    }
    else if (input == "FEMALE")
    {
        obj = Employee::Gender::FEMALE;
    }
    else
    {
        obj = Employee::Gender::NOT_SET;
    }
    
    return is;
};

bool inputsValidator(Employee &newObject) // function for validate inputs for createLocalStorage function
{
    do // check input name is string
    {
        cout << "Please write name of employee: ";
        cin >> newObject.name;
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    } while(!isString(newObject.name)); 

    do // check input surname is string
    {
        cout << "Please write surname of employee: ";
        cin >> newObject.surname;
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        
    } while(!isString(newObject.surname));
    
    // check input gender is correct
    bool myInput = {true};
    do 
    {   
        cout << "Please write gender of employee [M/F]: ";
        char inputGender = toupper(getche());

        switch (inputGender)
        {
            case 'M': newObject.gender = Employee::Gender::MALE; myInput = false; break;
            case 'F': newObject.gender = Employee::Gender::FEMALE; myInput = false; break;
            default : cout << "\n\nInput value is not correct. Try again.\n\n";
        }

    } while(myInput);

    // check input age is integer
    string inputAge;
    do 
    {
        cout << "\nPlease write age of employee: ";
        cin >> inputAge;

    } while(!isInteger(inputAge));

    newObject.age = stoi(inputAge);

    return true;
}

bool isInteger(const string &exampleInput) // function for validate input_integer
{
    std::regex notInteger("\\D"); // \\D: matches any non-digit characters
    bool result = regex_search(exampleInput, notInteger);

    if(result)
    {   
        cout << "\nInput value is not correct. Try again.\n";
    }
    else
    {   
        return true; 
    }
    
    return false;
}

bool isString(const string &exampleString) // function for validate input_string
{
    std::regex notString("[\\d\\W_]"); // \\d: matches any digit character. \\W: matches any non-word character. 
    bool result = regex_search(exampleString, notString); 

    if(result || exampleString == "employeesData")
    {   
        cout << "\nInput value is not correct. Try again.\n\n";
    }
    else
    {   
        return true; 
    }
    
    return false;
}

void displayObject(Employee &myObject, std::ostream &os) // display object informations
{
    os << "\n---<< Employee nr " << myObject.employeeId << " >>---" << endl
       << "\nName: " << myObject.name << endl
       << "Surname: " << myObject.surname << endl
       << "Gender: " << myObject.gender << endl
       << "Age: " << myObject.age << "\n\n";
}

void displayMenu() // display menu with options
{
    cout << "\n_________________________________________________________________________________________________________________________________________________\n";
    cout << "\nThis is list of employees, please choose one of the options below:\n\n";
    cout << "1 - Show all list of employees" << endl;
    cout << "2 - Generate document file" << endl;
    cout << "3 - Add a new employee" << endl;
    cout << "4 - Search employee from list" << endl;
    cout << "5 - Delete employee from list" << endl;
    cout << "6 - Remove all list" << endl;
    cout << "7 - Quit" << endl;
}

int makeChoice() // choice options
{
    int option = {0};
    bool inRange = {true};
    string input;

    while(inRange)
    {
        cout << "\nYour option: ";
        cin >> input;

        if (isInteger(input))
        {
            option = stoi(input);

            if (option < 1 ||  option > 7) // condition for check range od numbers
            {
                cout << "\nInput value is out of range. Try again." << endl;
            } 
            else
            {
                inRange = false;
            }
        } 
    }

    return option;
}

void removeList() // function for destroy data file
{   
    (remove("employeesData.txt") == 0)?  cout << "\nData file deleted successfully!\n\n" : cout << "\nData file doesn't exist. Add a new employee.\n\n";
}
