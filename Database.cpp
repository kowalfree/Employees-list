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

void Database::showData(const vecEmp &currentVector) const 
{    
    cout << "\n\nLIST OF YOUR EMPLOYEES ( " << currentVector.size() << " REGISTERED EMPLOYEES ) :" << endl; 

    for (auto element: currentVector)
    {
        displayObject(element, cout);
    } 
}

void Database::generateDocFile(const vecEmp &currentVector) const
{
    string fileName; 

    do
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

int Database::search(const vecEmp &currentVector) const
{     
    string number;
    bool integerValue = true;

    do
    {
        cout << "\nPlease write number of employee: ";
        cin >> number;

        if (!isInteger(number))
        {
            continue;
        }
        else if (stoi(number) > currentVector.size() || stoi(number) == 0)
        {   
            cout << "\nEmployee number starts from 1. There is/are " << currentVector.size() << " registered employee/s in the database. Try again.\n" << endl;
        }
        else 
        {
            integerValue = false;
        } 

    } while (integerValue);

    return stoi(number) - 1;
}   

void Database::deleteEmployee(vecEmp &currentVector, int &idToDelete) const
{
    currentVector.erase(currentVector.begin() + idToDelete);
    cout << "Emploee number " << ++idToDelete << " was deleted!\n\n";

    if (currentVector.empty()) 
    {
        remove("employeesData.txt");
    }    
}   
