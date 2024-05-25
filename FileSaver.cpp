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

std::vector <Employee> FileSaver::createLocalStorage() const
{
    std::vector <Employee> storage;
    std::ifstream read; 

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

            storage.emplace_back(member); 
        } 
    }

    read.close();

    return storage;
}

void FileSaver::addToFile(Employee &exampleEmployee) const
{   
    std::ofstream write;

    write.open("employeesData.txt", std::ios::out | std::ios::app);
    write << "\n";
    write << exampleEmployee.employeeId << endl;
    write << exampleEmployee.name << endl;
    write << exampleEmployee.surname << endl;
    write << exampleEmployee.gender << endl;
    write << exampleEmployee.age;

    write.close();

    cout << "\nRegistered new employee!" << endl;
}

void FileSaver::uploadDataFile(std::vector <Employee> &currentVector) const
{
    if (not currentVector.empty())
    {
        std::ofstream write; 
        currentVector.at(0).employeeId = 0;

        write.open("employeesData.txt", std::ios::out | std::ios::trunc);

        for (auto e: currentVector)
        {   
            e.employeeId++;

            write << "\n";
            write << e.employeeId << endl;
            write << e.name << endl;
            write << e.surname << endl;
            write << e.gender << endl;
            write << e.age;
        }

        write.close();
    }
}
