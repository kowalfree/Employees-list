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
            cout   << "\n<< Employee nr " << element.employeeId << " >>" << endl
                        << "\nName: " << element.name << endl
                        << "Surname: " << element.surname << endl
                        << "Gender: " << element.gender << endl
                        << "Age: " << element.age << endl;
        } 
        cout << "\n";
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
        std::ofstream write; 
    
        do // check input name is string
        {
            cout << "\nDon't use same name like datafile: \"employeesData\", don't use any digits and special signs.\nPlease enter the name of your file: ";
            cin >> fileName;

        } while(!isString(fileName));

        write.open(fileName + ".doc", std::ios::out);

        write << "LIST OF YOUR EMPLOYEES ( " << currentVector.size() << " REGISTERED EMPLOYEES ) :\n\n"; 

        for (auto element: currentVector)
        {
            write << "\n<< Employee nr " << element.employeeId << " >>" << endl;
            write << "\nName: " << element.name << endl;
            write << "Surname: " << element.surname << endl;
            write << "Gender: " << element.gender << endl;
            write << "Age: " << element.age << endl << endl;
        } 

        write.close();

        cout << "\nDocument was generated successfully!.\n\n";
    }  
}

int Database::validateInteger(const vecEmp &currentVector) const // function for check if input is integer
{   
    string number;
    bool option = {true};

    while (option)
    {
        cout << "\nPlease write number of employee: ";
        cin >> number;

        if (not isInteger(number)) // statement for check if input is integer
        {
            cout << "\nThe entered value is not correct, try again." << endl; 
            continue;;
        } 
        else if (stoi(number) > currentVector.size())
        {   
            cout << "\nThe entered value is not correct! There are " << currentVector.size() << " registered employees in the database. Try again." << endl; 
        } 
        else 
        { 
            option = false;
        }
    }
    
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
        int new_number = validateInteger(currentVector);
        
        cout   << "\n<< Employee nr " << currentVector.at(new_number).employeeId << " >>" << endl
                    << "\nName: " << currentVector.at(new_number).name << endl
                    << "Surname: " << currentVector.at(new_number).surname << endl
                    << "Gender: " << currentVector.at(new_number).gender << endl
                    << "Age: " << currentVector.at(new_number).age << "\n\n";
        
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

        cout   << "\n<< Employee nr " << currentVector.at(idToDelete).employeeId << " >>" << endl
                    << "\nName: " << currentVector.at(idToDelete).name << endl
                    << "Surname: " << currentVector.at(idToDelete).surname << endl
                    << "Gender: " << currentVector.at(idToDelete).gender << endl
                    << "Age: " << currentVector.at(idToDelete).age << endl;

        currentVector.erase(currentVector.begin() + idToDelete);
        cout << "\nEmploee number " << ++idToDelete << " was deleted!\n\n";

        if (currentVector.empty()) 
        {
            remove("employeesData.txt");
        }    
    }
}   
