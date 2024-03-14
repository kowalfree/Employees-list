#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <limits>
#include <cstdlib>
#include <cstdio>
#include <regex>
#include <conio.h>

#include "FileSaver.h"
#include "NoClassFunctions.h"

using std::cout;
using std::endl;
typedef std::vector <Employee> vecEmp;

vecEmp FileSaver::createLocalStorage() const // create vector of objects from file
{
    vecEmp tempData;
    std::fstream read; 

    read.open("employeesData.txt", std::ios::in); 

    if(read) 
    {   
        Employee member;

        while(!read.eof())
        {   
            read >> member.employeeId;
            read >> member.name;
            read >> member.surname;
            read >> member.gender;
            read >> member.age;

            tempData.push_back(member); 
        } 
    }

    read.close();

    return tempData;
}

void FileSaver::addToFile(const vecEmp &currentVector) const // write to file a new employee
{   
    Employee newEmployee;

    inputsValidator(newEmployee);

    std::ofstream write;
    newEmployee.employeeId = currentVector.size() + 1;

    write.open("employeesData.txt", std::ios::out | std::ios::app);
    write << "\n";
    write << newEmployee.employeeId << endl;
    write << newEmployee.name << endl;
    write << newEmployee.surname << endl;
    write << newEmployee.gender << endl;
    write << newEmployee.age;

    write.close();

    cout << "\nRegistered new employee!" << endl;

    displayObject(newEmployee, cout);
}

void FileSaver::uploadDataFile(vecEmp &currentVector) const
{
    if (not currentVector.empty())
    {
        std::ofstream write; 

        write.open("employeesData.txt", std::ios::out | std::ios::trunc); //  clear all file and write a new data file from vector of objects

        for (int i = 0; i < currentVector.size(); i++)
        {
            currentVector.at(i).employeeId = i + 1;
            write << "\n";
            write << currentVector.at(i).employeeId << endl;
            write << currentVector.at(i).name << endl;
            write << currentVector.at(i).surname << endl;
            write << currentVector.at(i).gender << endl;
            write << currentVector.at(i).age;
        }

        write.close();
    }
}
