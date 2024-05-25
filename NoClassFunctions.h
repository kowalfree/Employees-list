#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <limits>
#include <cstdlib>
#include <cstdio>
#include <regex>
#include <conio.h>

#include "Employee.h"

std::ostream &operator<<(std::ostream &os, Employee::Gender &obj);
std::istream &operator>>(std::istream &is, Employee::Gender &obj);
bool isInteger(const std::string &exampleInput);
int makeChoice();
bool decribeEmployee(Employee &newObject);
void displayObject(Employee &myObject, std::ostream &os);
void displayMenu();
bool isString(const std::string &exampleString);
