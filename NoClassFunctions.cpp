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
    
    do // check input gender is correct
    {   
        std::cout << "Please write gender of employee [M/F]: ";
        newObject.gender = toupper(getche());
        
        if (newObject.gender == 'M' || newObject.gender == 'F')
        {
            break;
        }
        else
        {
            std::cout << "\n\nInput value is not correct. Try again.\n\n";
        }
        
    } while(true);

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
    std::regex integerValue("\\D"); // \\D: matches any non-digit characters
    bool result = regex_search(exampleInput, integerValue);

    if(result)
    {   
        cout << "\nInput value is not correct. Try again.\n\n";
    }
    else
    {   
        return true; 
    }
    
    return false;
}

bool isString(const string &exampleString) // function for validate input_string
{
    std::regex isString("[\\d\\W_]"); 
    // regex = [\\d\\W_] = [-_'\";:,.<>/?=+!@#$%^&*(){}|\\`\]\[~0-9], \\d: matches any digit character. \\W: matches any non-word character. 
    bool result = regex_search(exampleString, isString);

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
        cout << "\n";

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
