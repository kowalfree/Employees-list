#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <vector>
#include "employees.h"

void Employee::add() 
{
    std::cout << "Please write name of employer: ";
    std::cin >> name;
    std::cout << "Please write surname of employer: ";
    std::cin >> surname;
    std::cout << "Please write gender of employer: ";
    std::cin >> gender;
    std::cout << "Please write age of employer: ";
    std::cin >> age;

    // save to file
    employeesData.open("employeesData.doc", std::ios::out | std::ios::app); 

    employeesData << "\nName: " << name << std::endl;
    employeesData << "Surname: " << surname << std::endl;
    employeesData << "Gender: " << gender << std::endl;
    employeesData << "Age: " << age << std::endl;

    std::cout << "Registered new employee!" << std::endl;

    employeesData.close();
}

void Employee::show()
{
    // read file
    employeesData.open("employeesData.doc", std::ios::in); 

    if (employeesData.good() == false)
    {                 
        std::cout<<"File doesn't exist";    
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
    employeesData.close();
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