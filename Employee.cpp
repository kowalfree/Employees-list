#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstdlib>
#include <limits>
#include <cstdio>
#include <regex>
#include <conio.h>

#include "Employee.h"

Employee::Employee(unsigned int objId, std::string objName, std::string objSurname, char objGender, unsigned int objAge) 
{
    employeeId = objId;
    name = objName;
    surname = objSurname;
    gender = objGender;
    age = objAge;
    // std::cout << "\nnew employee";
}

Employee::Employee(const Employee &copyObj) 
{
    employeeId = copyObj.employeeId;
    name = copyObj.name;
    surname = copyObj.surname;
    gender = copyObj.gender;
    age = copyObj.age;
    // std::cout << "\ncopy employee";
}

Employee::~Employee() 
{
    // std::cout << "\nClean object Employee";
}
