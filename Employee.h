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
    unsigned int employeeId;
    std::string name;
    std::string surname;

    enum class Gender
    {
        MALE,
        FEMALE,
        NOT_SET
    };

    Gender gender;
    unsigned int age;

    Employee(unsigned int objId = 0, std::string objName = "unknown", std::string objSurname = "unknown", Gender objGender = Gender::NOT_SET, unsigned int objAge = 0);
    Employee(const Employee &copyObj);
    ~Employee();
};

#endif