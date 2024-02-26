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

struct Database 
{   
    int validateInteger(const vecEmp &currentVector) const;
    void showData(const vecEmp &currentVector) const;
    void generateDocFile(const vecEmp &currentVector) const;
    void search(const vecEmp &currentVector) const;
    void deleteEmployee(vecEmp &currentVector) const;
};
