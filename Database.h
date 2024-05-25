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
    void showData(const vecEmp &currentVector) const;
    void generateDocFile(const vecEmp &currentVector) const;
    int search(const vecEmp &currentVector) const;
    void deleteEmployee(vecEmp &currentVector, int &idToDelete) const;
};
