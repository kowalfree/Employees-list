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

bool isInteger(const std::string &exampleInput);
int makeChoice();
bool inputsValidator(Employee &newObject);
void displayMenu();
bool isString(const std::string &exampleString);
void removeList();