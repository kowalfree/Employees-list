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

/*
Propose to create 3 classes
Emplyee - simple class with basic data about employee
Database - local data storage
FileSaver - create file / read / write data
*/

int main () 
{
    do
    {
        Employee newEmployee; 
        std::vector<Employee> vector_from_file;
        
        vector_from_file = newEmployee.create_vector(newEmployee); // maybe readDataFromFile ???

        int size_of_vector = vector_from_file.size();

        int choice; // uninitialize --> int choice{0};
        choice = display_menu();

        switch(choice) 
        {
            case 1: newEmployee.showData(vector_from_file, size_of_vector); // <-- second argument not needed, remove
                    system("pause"); break;

            case 2: newEmployee.generate_doc_file(vector_from_file, size_of_vector); // <-- the same in others functions
                    system("pause"); break;

            case 3: newEmployee.add(vector_from_file, size_of_vector); // Do you mean addToFile ???
                    system("pause"); break;

            case 4: newEmployee.search(vector_from_file, size_of_vector);
                    system("pause"); break;

            case 5: newEmployee.delete_employee(vector_from_file, size_of_vector);
                    system("pause"); break;

            case 6: remove_list();
                    system("pause"); break;

            case 7: std::cout << "\nExiting from program..." << std::endl << std::endl;
                    return false; break; // dont use return value form main btw break; has no effect
            // default:
            // std::cout << "\nExiting from program...\n\n";
        }
    }
    while (true); // while (display_menu() != 7)

    return 0;
}