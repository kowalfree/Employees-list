#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <limits>
#include <cstdlib>
#include <cstdio>
#include <regex>
#include <conio.h>

struct Employee
{   
    unsigned employeeId;
    std::string name;
    std::string surname;
    char gender;
    unsigned age;

    Employee(unsigned int objId = 0, std::string objName = "unknown", std::string objSurname = "unknown", char objGender = '-', unsigned int objAge = 0);
    Employee(const Employee &copyObj);
    ~Employee();
};

#endif