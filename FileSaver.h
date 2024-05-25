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

struct FileSaver
{
    std::vector <Employee> createLocalStorage() const;
    void addToFile(Employee &exampleEmployee) const;
    void uploadDataFile(std::vector <Employee> &currentVector) const;
};
