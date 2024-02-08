#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstdlib>
#include <cstdio>
#include <limits>
#include "employees.h"


int main () 
{
    do
    {
        Employee newEmployee;
        std::vector<Employee> vector_from_file;
        
        newEmployee.create_vector(newEmployee);
        vector_from_file = newEmployee.create_vector(newEmployee);

        int size_of_vector = vector_from_file.size();

        int choice;
        choice = display_menu();

        switch(choice) 
        {
            case 1: newEmployee.showData(vector_from_file, size_of_vector);
                    system("pause"); break;

            case 2: newEmployee.generate_doc_file(vector_from_file, size_of_vector);
                    system("pause"); break;

            case 3: newEmployee.add(vector_from_file, size_of_vector);
                    system("pause"); break;

            case 4: newEmployee.search(vector_from_file, size_of_vector);
                    system("pause"); break;

            case 5: newEmployee.delete_employee(vector_from_file, size_of_vector);
                    system("pause"); break;

            case 6: remove_list();
                    system("pause"); break;

            case 7: std::cout << "\nExiting from program..." << std::endl << std::endl;
                    return false; break;
        }
    }
    while (true);

    return 0;
}