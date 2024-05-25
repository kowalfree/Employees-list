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

bool decribeEmployee(Employee &newObject)
{
    do 
    {
        cout << "\nPlease write name of employee: ";
        cin >> newObject.name;
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    } while(!isString(newObject.name)); 

    do 
    {
        cout << "Please write surname of employee: ";
        cin >> newObject.surname;
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        
    } while(!isString(newObject.surname));
    
    bool myInput = true;
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

    string inputAge;
    do 
    {
        cout << "\nPlease write age of employee: ";
        cin >> inputAge;

    } while(!isInteger(inputAge));

    newObject.age = stoi(inputAge);

    return true;
}

bool isInteger(const string &exampleInput)
{
    std::regex notInteger("\\D"); // \\D: matches any non-digit characters

    if(regex_search(exampleInput, notInteger))
    {   
        cout << "\nInput value is not correct. Try again.\n";
    }
    else
    {   
        return true; 
    }
    
    return false;
}

bool isString(const string &exampleString)
{
    std::regex notString("[\\d\\W_]"); // \\d: matches any digit character. \\W: matches any non-word character. 

    if(regex_search(exampleString, notString) || exampleString == "employeesData")
    {   
        cout << "\nInput value is not correct. Try again.\n\n";
    }
    else
    {   
        return true; 
    }
    
    return false;
}

void displayObject(Employee &myObject, std::ostream &os)
{
    os << "\n---<< Employee nr " << myObject.employeeId << " >>---" << endl
       << "\nName: " << myObject.name << endl
       << "Surname: " << myObject.surname << endl
       << "Gender: " << myObject.gender << endl
       << "Age: " << myObject.age << "\n\n";
}

void displayMenu()
{
    cout << "\n_________________________________________________________________________________________________________________________________________________\n";
    cout << "\nThis is list of employees, please choose one of the options below:\n\n";
    cout << "1 - Show all list of employees\n";
    cout << "2 - Generate document file\n";
    cout << "3 - Add a new employee\n";
    cout << "4 - Search employee from list\n";
    cout << "5 - Delete employee from list\n";
    cout << "6 - Remove all list\n";
    cout << "7 - Quit\n";
}

int makeChoice()
{
    int option = 0;
    bool inRange = true;
    string input;

    while(inRange)
    {
        cout << "\nYour option: ";
        cin >> input;

        if (isInteger(input))
        {
            option = stoi(input);

            if (std::clamp(option, 1, 7) != option)
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
