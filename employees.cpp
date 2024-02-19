#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstdlib>
#include <limits>
#include <cstdio>
#include <regex>
#include <conio.h>
#include "employees.h"

bool isInteger(const std::string &exampleInput) // function for validate input_integer
{
    std::regex integerValue("\\D"); // \\D: matches any non-digit characters
    bool result = regex_search(exampleInput, integerValue);

    if(result)
    {   
        std::cout << "\nInput value is not correct. Try again." << std::endl << std::endl;
    }
    else
    {   
        return true; 
    }
    
    return false;
}

bool isString(const std::string &exampleString) // function for validate input_string
{
    int input_string;
    bool check = 0;
    std::regex isString("[\\d\\W_]"); 
    // regex = [\\d\\W_] = [-_'\";:,.<>/?=+!@#$%^&*(){}|\\`\]\[~0-9], \\d: matches any digit character. \\W: matches any non-word character. 
    bool result = regex_search(exampleString, isString);

    if(result)
    {   
        std::cout << "\nInput value is not correct. Try again.\n\n";
    }
    else
    {   
        check = 1; 
    }
    
    return check;
}

int displayMenu() // display menu with options
{
    std::cout << "\nThis is list of employees, please choose one of the options below:\n\n";
    std::cout << "1 - Show all list of employees" << std::endl;
    std::cout << "2 - Generate document file" << std::endl;
    std::cout << "3 - Add a new employee" << std::endl;
    std::cout << "4 - Search employee from list" << std::endl;
    std::cout << "5 - Delete employee from list" << std::endl;
    std::cout << "6 - Remove all list" << std::endl;
    std::cout << "7 - Quit" << std::endl;

    int option = {0};
    bool inRange = {true};
    std::string input;

    while(inRange)
    {
        std::cout << "\nYour option: ";
        std::cin >> input;
        std::cout << "\n";

        if (isInteger(input))
        {
            option = stoi(input);

            if (option < 1 ||  option > 7) // condition for check range od numbers
            {
                std::cout << "\nInput value is out of range. Try again." << std::endl;
            } 
            else
            {
                inRange = false;
            }
        } 
    }

    return option;
}

std::vector<project::Employee>project::Employee::createVector(Employee &member) // create vector of objects from file
{
    std::vector<Employee> tempData;
    std::fstream employeesData; 

    employeesData.open("employeesData.txt", std::ios::in); 

    if(employeesData) 
    {   
        while(true)
        {
            employeesData >> member.employeeId;
            employeesData >> member.name;
            employeesData >> member.surname;
            employeesData >> member.gender;
            employeesData >> member.age;

            if (employeesData.eof())
            {
                break;
            }
           
            tempData.push_back(member);  
        }
    }

    employeesData.close();

    return tempData;
}

void project::Employee::showData(const std::vector<Employee> &currentVector) // read current all data file
{   
    if (currentVector.empty()) 
    {
        std::cout << "\nData file doesn't exist. Add a new employee for create a new data file.\n\n"; 
        return;
    }
    else 
    {   
        std::cout << "\n\nLIST OF YOUR EMPLOYEES ( " << currentVector.size() << " REGISTERED EMPLOYEES ) :" << std::endl; 

        for (auto element: currentVector)
        {
            std::cout   << "\n<< Employee nr " << element.employeeId << " >>" << std::endl
                        << "\nName: " << element.name << std::endl
                        << "Surname: " << element.surname << std::endl
                        << "Gender: " << element.gender << std::endl
                        << "Age: " << element.age << std::endl;
        } 
        std::cout << "\n";
    }
}

void project::Employee::generateDocFile(const std::vector<Employee> &currentVector) // function for generate document
{
    if (currentVector.size() == 0) 
    {
        std::cout << "\nData file doesn't exist. Add a new employee for create a new data file. " << std::endl << std::endl; 
    }
    else 
    {   
        std::string fileName;
        std::ofstream employeesData; 
    
        while(true) // check input name is string
        {
            std::cout << "Please enter the name of your file ( don't use any digits and special signs ): ";
            std::cin >> fileName;

            if (isString(fileName))
            {
                break;
            } 
        }

        employeesData.open(fileName + ".doc", std::ios::out);

        employeesData << "LIST OF YOUR EMPLOYEES ( " << currentVector.size() << " REGISTERED EMPLOYEES ) :\n\n"; 

        for (auto element: currentVector)
        {
            employeesData << "\n<< Employee nr " << element.employeeId << " >>" << std::endl;
            employeesData << "\nName: " << element.name << std::endl;
            employeesData << "Surname: " << element.surname << std::endl;
            employeesData << "Gender: " << element.gender << std::endl;
            employeesData << "Age: " << element.age << std::endl << std::endl;
        } 

        employeesData.close();

        std::cout << "\nDocument was generated successfully!." << std::endl << std::endl;
    }  
}

void project::Employee::addToFile(const std::vector<Employee> &currentVector) // write to file a new employee
{   
    while(true) // check input name is string
    {
        std::cout << "Please write name of employee: ";
        std::cin >> name;

        if (isString(name))
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            break;
        } 
    }

    while(true) // check input surname is string
    {
        std::cout << "Please write surname of employee: ";
        std::cin >> surname;

        if (isString(surname))
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            break;
        } 
    }
    
    while(true) // check input gender is correct
    {   
        std::cout << "Please write gender of employee [M/F]: ";
        gender = getche();
        
        if (gender == 'M' || gender == 'F')
        {
            break;
        }
        else if (gender == 'm' || gender == 'f')
        {   
            gender = toupper(gender);
            break;
        } 
        else
        {
            std::cout << "\nInput value is not correct. Try again." << std::endl << std::endl;
        }
    }

    while(true) // check input age is integer
    {
        std::cout << "\nPlease write age of employee: ";
        std::string inputAge;
        std::cin >> inputAge;

        if (isInteger(inputAge))
        {
            age = stoi(inputAge);
            break;
        } 
    }

    std::ofstream employeesData;
    employeeId = currentVector.size() + 1;

    employeesData.open("employeesData.txt", std::ios::out | std::ios::app);

    employeesData << employeeId << std::endl;
    employeesData << name << std::endl;
    employeesData << surname << std::endl;
    employeesData << gender << std::endl;
    employeesData << age << std::endl;

    std::cout << "\nRegistered new employee!" << std::endl;

    employeesData.close();

    std::cout << "\n---<< Employee nr " << employeeId << " >>---" << std::endl
              << "\nName: " << name << std::endl
              << "Surname: " << surname << std::endl
              << "Gender: " << gender << std::endl
              << "Age: " << age << "\n\n";
}

int project::Employee::validateInteger(const std::vector<Employee> &currentVector) // function for check if input is integer
{   
    int number;

    if (currentVector.empty())
    {                 
        std::cout<<"\nFile doesn't exist. Add a new employee.\n\n";
    } 
    else
    {
        while (true)
        {
            std::cout << "\nPlease write number of employee: ";

            std::cin >> number;
            char ch; 
            std::cin.get(ch);
    
            if (!std::cin.good() || number <= 0 || ch == '.') // statement for check if input is integer
            {
                std::cout << "\nThe entered value is not correct, try again." << std::endl; 
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            } 
            else if ( number > currentVector.size())
            {   
                std::cout << "\nThe entered value is too high! There are " << currentVector.size() << " registered employees in the database. Try again." << std::endl; 
            } 
            else 
            { 
                break;
            }
        }
    }
    
    return number - 1;
}

int project::Employee::search(const std::vector<Employee> &currentVector) // function for display just one employee from list
{   
    int new_number = validateInteger(currentVector);

    if (not currentVector.empty())
    {
        std::cout   << "\n<< Employee nr " << currentVector.at(new_number).employeeId << " >>" << std::endl
                    << "\nName: " << currentVector.at(new_number).name << std::endl
                    << "Surname: " << currentVector.at(new_number).surname << std::endl
                    << "Gender: " << currentVector.at(new_number).gender << std::endl
                    << "Age: " << currentVector.at(new_number).age << "\n\n";
    }
    
    return new_number;
}   

void project::Employee::deleteEmployee(std::vector<Employee> &currentVector) // function for delete just one employee from list
{
    int idToDelete = search(currentVector) + 1;

    if (not currentVector.empty())
    {
        currentVector.erase(currentVector.begin() + idToDelete);

        std::cout   << "Emploee number " << idToDelete << " was deleted!\n\n";

        if (currentVector.empty()) 
        {
            remove("employeesData.txt");
        }  
        else
        {
            std::ofstream employeesData; 
            employeesData.open("employeesData.txt", std::ios::out | std::ios::trunc); //  clear all file and write a new data file from vector of objects

            for (int i = 0; i < currentVector.size(); i++)
            {
                currentVector.at(i).employeeId = i + 1;
                
                employeesData << currentVector.at(i).employeeId << std::endl;
                employeesData << currentVector.at(i).name << std::endl;
                employeesData << currentVector.at(i).surname << std::endl;
                employeesData << currentVector.at(i).gender << std::endl;
                employeesData << currentVector.at(i).age << std::endl;
            }

            employeesData.close();
        }
    }
   
}   

void removeList() // function for destroy data file
{   
    if (remove("employeesData.txt") == 0)
    {
        std::cout << "\nData file deleted successfully!" << std::endl << std::endl;
    }
    else 
    {
        std::cout << "\nData file doesn't exist. Add a new employee." << std::endl << std::endl; 
    }
}

project::Employee::Employee(unsigned int objId, std::string objName, std::string objSurname, char objGender, unsigned int objAge) 
{
    employeeId = objId;
    name = objName;
    surname = objSurname;
    gender = objGender;
    age = objAge;
}

project::Employee::Employee(const Employee &copyObj) 
{
    employeeId = copyObj.employeeId;
    name = copyObj.name;
    surname = copyObj.surname;
    gender = copyObj.gender;
    age = copyObj.age;
}

project::Employee::~Employee() 
{

}
