#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <limits>
#include <cstdlib>
#include <cstdio>
#include <regex>
#include <conio.h>

#include "Database.h"
#include "NoClassFunctions.h"

using std::cout;
using std::cin;
using std::string;
using std::endl;
typedef std::vector <Employee> vecEmp;

void Database::showData(const vecEmp &currentVector) const // read current all data file
{   
    if (currentVector.empty()) 
    {
        cout << "\nData file doesn't exist. Add a new employee.\n\n"; 
        return;
    }
    else 
    {   
        cout << "\n\nLIST OF YOUR EMPLOYEES ( " << currentVector.size() << " REGISTERED EMPLOYEES ) :" << endl; 

        for (auto element: currentVector)
        {
            displayObject(element, cout);
        } 
    }
}

void Database::generateDocFile(const vecEmp &currentVector) const // function for generate document
{
    if (currentVector.empty()) 
    {
        cout << "\nData file doesn't exist. Add a new employee.\n\n"; 
    }
    else 
    {   
        string fileName; 
    
        do // check input name is string
        {
            cout << "\nDon't use same name like datafile: \"employeesData\", don't use any digits and special signs.\nPlease enter the name of your file: ";
            cin >> fileName;

        } while(!isString(fileName));

        std::ofstream write;
        write.open(fileName + ".doc", std::ios::out);

        write << "LIST OF YOUR EMPLOYEES ( " << currentVector.size() << " REGISTERED EMPLOYEES ) :\n\n"; 

        for (auto element: currentVector)
        {
            displayObject(element, write);
        } 

        write.close();

        cout << "\nDocument was generated successfully!.\n\n";
    }  
}

int Database::validateInteger(const vecEmp &currentVector) const // function for check if input is integer
{   
    string number;
    bool integerValue = {true};

    do
    {
        cout << "Please write number of employee: ";
        cin >> number;

        if (isInteger(number))
        {
           if (stoi(number) > currentVector.size())
            {   
                cout << "There are " << currentVector.size() << " registered employees in the database. Try again.\n" << endl;
            } 
            else 
            {
                integerValue = {false};
            } 
        }

    } while (integerValue);

    return stoi(number) - 1;
}

void Database::search(const vecEmp &currentVector) const // function for display just one employee from list
{   
    if (currentVector.empty())
    {                 
        cout<<"\nFile doesn't exist. Add a new employee.\n\n";
    } 
    else
    {
        int indexNum = validateInteger(currentVector);
        auto element = currentVector.at(indexNum);
        displayObject(element, cout);
    }
}   

void Database::deleteEmployee(vecEmp &currentVector) const // function for delete just one employee from list
{
    if (currentVector.empty())
    {                 
        cout<<"\nFile doesn't exist. Add a new employee.\n\n";
    } 
    else
    {
        int idToDelete = validateInteger(currentVector);
        auto element = currentVector.at(idToDelete);
        displayObject(element, cout);

        currentVector.erase(currentVector.begin() + idToDelete);
        cout << "\nEmploee number " << ++idToDelete << " was deleted!\n\n";

        if (currentVector.empty()) 
        {
            remove("employeesData.txt");
        }    
    }
}   
