#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstdlib>
#include <cstdio>
#include <limits>
#include <regex>
#include <conio.h>
#include <windows.h>  
#include <time.h>

#include "Employee.h"
#include "Database.h"
#include "FileSaver.h"
#include "NoClassFunctions.h"

int main() 
{
    Database localStorage;
    FileSaver fileStorage;
    
    int choice = 0; 
    
    do
    {   
        std::vector<Employee> localData = fileStorage.createLocalStorage();

        displayMenu();
        choice = makeChoice();

        if (choice !=3 && choice !=7 && localData.empty())
        {                 
           std::cout<<"\nData file doesn't exist. Add a new employee."; Sleep(2500); continue;
        }

        switch(choice) 
        {
            case 1: {localStorage.showData(localData);} break; 
            
            case 2: {localStorage.generateDocFile(localData);} break;
        
            case 3: {Employee newEmployee;
                    newEmployee.employeeId = localData.size() + 1;
                    decribeEmployee(newEmployee);
                    fileStorage.addToFile(newEmployee);
                    displayObject(newEmployee, std::cout);} break;

            case 4: {int searchId = localStorage.search(localData);
                    displayObject(localData.at(searchId), std::cout);} break;

            case 5: {int deleteId = localStorage.search(localData);
                    displayObject(localData.at(deleteId), std::cout);
                    localStorage.deleteEmployee(localData, deleteId);
                    fileStorage.uploadDataFile(localData);} break;
                       
            case 6: {remove("employeesData.txt");
                    std::cout << "\nData file deleted successfully!\n\n";} break;

           default: {std::cout << "\nExiting from program...\n\n";}
        }

        std::cout << "Please press any key to continue...";
        getch();
    }
    while (choice != 7);

    return 0;
}