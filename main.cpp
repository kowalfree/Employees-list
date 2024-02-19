#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstdlib>
#include <cstdio>
#include <limits>
#include <regex>
#include <conio.h>
#include "employees.h"


int main () 
{
    int choice = {0}; 

    do
    {
        project::Employee newEmployee;
        std::vector<project::Employee> readDataFile = newEmployee.createVector(newEmployee);

        choice = displayMenu();

        switch(choice) 
        {
            case 1: newEmployee.showData(readDataFile);
                    system("pause"); break;

            case 2: newEmployee.generateDocFile(readDataFile);
                    system("pause"); break;

            case 3: newEmployee.addToFile(readDataFile);
                    system("pause"); break;

            case 4: newEmployee.search(readDataFile);
                    system("pause"); break;

            case 5: newEmployee.deleteEmployee(readDataFile);
                    system("pause"); break;

            case 6: removeList();
                    system("pause"); break;

           default: std::cout << "\nExiting from program...\n\n";
        }
    }
    while (choice != 7);

    return 0;
}