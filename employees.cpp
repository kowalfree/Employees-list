#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include "employees.h"

void menu()
{   
    std::cout << "\nThis is list of employees, please choose one of the options below:" << std::endl;
    std::cout << "\n1 - Show list of employees" << std::endl;
    std::cout << "2 - Add a new employee" << std::endl;
    std::cout << "3 - Search employee from list" << std::endl;
    std::cout << "4 - Edit employee from list" << std::endl;
    std::cout << "5 - Delete employee from list" << std::endl;
    std::cout << "6 - Quit" << std::endl;

    int option;
    std::cout << "\nYour option: ";
    std::cin >> option;

    Employee newEmployee;

    switch(option) 
    {
        case 1: 
                newEmployee.showData();
                break;

        case 2: 
                newEmployee.add();
                break;

        // case 3: ;
        //         break;

        // case 4: ;
        //         break;

        // case 5: ;
        //         break;

        case 6: 
                exit(0);
                break;
    }
}

void Employee::showData() // read from file
{
    employeesData.open("employeesData.txt", std::ios::in); 
    
    if (!employeesData)
    {                 
        std::cout<<"File doesn't exist. Add a new employee.";    
        exit(0);
    } 
    else 
    {
        std::string line; 
        int numLine = {1}; 

        while (getline(employeesData, line)) 
        {         
            switch(numLine)
            {
                case 1: 
                        name = line; 
                        std::cout << name << std::endl; 
                        break;
                case 2: 
                        surname = line;  
                        std::cout << surname << std::endl; 
                        break;
                case 3: 
                        gender = line.at(0);  
                        std::cout << gender << std::endl;
                        break;
                case 4: 
                        age = atoi(line.c_str());  
                        std::cout << age << std::endl; 
                        break;
                numLine ++;
            }   
        }
    }
}

void Employee::add() // write to file
{   
    employeesData.open("employeesData.txt", std::ios::out | std::ios::app);

    std::cout << "\nPlease write name of employer: ";
    std::cin >> name;
    std::cout << "Please write surname of employer: ";
    std::cin >> surname;
    std::cout << "Please write gender of employer: ";
    std::cin >> gender;
    std::cout << "Please write age of employer: ";
    std::cin >> age;

    employeesData << "\nName: " << name << std::endl;
    employeesData << "Surname: " << surname << std::endl;
    employeesData << "Gender: " << gender << std::endl;
    employeesData << "Age: " << age << std::endl;

    std::cout << "\nRegistered new employee!" << std::endl;

    employeesData.close();

    std::cout << "\nName: " << name << std::endl
              << "Surname: " << surname << std::endl
              << "Gender: " << gender << std::endl
              << "Age: " << age << std::endl;
}


// void Employer::remove()
// {
    
// }   

Employee::Employee(std::string n, std::string s, char g, int a) 
{
    name = n;
    surname = s;
    gender = g;
    age = a;
}

Employee::~Employee() 
{
     std::cout << "\nClean" << std::endl;
}