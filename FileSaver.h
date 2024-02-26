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

typedef std::vector <Employee> vecEmp;

struct FileSaver
{
    vecEmp createLocalStorage()const;
    void addToFile(const vecEmp &currentVector) const;
    void uploadDataFile(vecEmp &currentVector) const;
};
