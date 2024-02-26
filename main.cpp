#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstdlib>
#include <cstdio>
#include <limits>
#include <regex>
#include <conio.h>

#include "Employee.h"
#include "Database.h"
#include "FileSaver.h"
#include "NoClassFunctions.h"

int main() 
{
    Database localStorage;
    FileSaver fileStorage;
    int choice = {0}; 
    
    do
    {   
        std::vector<Employee> localData = fileStorage.createLocalStorage();
        
        displayMenu();
        choice = makeChoice();

        switch(choice) 
        {
            case 1: localStorage.showData(localData);
                    system("pause"); break;
            
            case 2: localStorage.generateDocFile(localData);
                    system("pause"); break;
        
            case 3: fileStorage.addToFile(localData);
                    system("pause"); break;

            case 4: localStorage.search(localData);
                    system("pause"); break;

            case 5: localStorage.deleteEmployee(localData);
                    fileStorage.uploadDataFile(localData);
                    system("pause"); break; 

            case 6: removeList();
                    system("pause"); break;

           default: std::cout << "\nExiting from program...\n\n";
        }
    }
    while (choice != 7);

    return 0;
}