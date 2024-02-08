#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstdlib>
#include <limits>
#include <cstdio>
#include "employees.h"


int display_menu() // display menu with options
{
    std::cout << "\nThis is list of employees, please choose one of the options below:" << std::endl;
    std::cout << "\n1 - Show all list of employees" << std::endl;
    std::cout << "2 - Generate document file" << std::endl;
    std::cout << "3 - Add a new employee" << std::endl;
    std::cout << "4 - Search employee from list" << std::endl;
    std::cout << "5 - Delete employee from list" << std::endl;
    std::cout << "6 - Remove all list" << std::endl;
    std::cout << "7 - Quit" << std::endl;

    int option;
    std::cout << "\nYour option: ";
    std::cin >> option; 

    return option;
}

std::vector<Employee> Employee::create_vector(Employee &member) // create vector of objects from file
{
    std::vector<Employee> box_for_members;
    std::fstream employeesData; 

    employeesData.open("employeesData.txt", std::ios::in); 
    
    if (!employeesData)
    {                 
        return box_for_members;
    } 
    else 
    {   
        while(true)
        {
            employeesData >> member.employeeNum;
            employeesData >> member.name;
            employeesData >> member.surname;
            employeesData >> member.gender;
            employeesData >> member.age;

            if (employeesData.eof())
            {
                break;
            }
           
            box_for_members.push_back(member); 
        }
    }

    employeesData.close();

    return box_for_members;
}

void Employee::showData(const std::vector<Employee> &current_vector, const int &size) // read current all data file
{   
    if (size == 0) 
    {
        std::cout << "\nData file doesn't exist. Add a new employee for create a new data file. " << std::endl << std::endl; 
    }
    else 
    {   
        std::cout << "\n\nLIST OF YOUR EMPLOYEES ( " << size << " REGISTERED EMPLOYEES ) :" << std::endl; 

        for (auto element: current_vector)
        {
            std::cout   << "\n<< Employee nr " << element.employeeNum << " >>" << std::endl
                        << "\nName: " << element.name << std::endl
                        << "Surname: " << element.surname << std::endl
                        << "Gender: " << element.gender << std::endl
                        << "Age: " << element.age << std::endl;
        } 
        std::cout << "\n";
    }
}

void Employee::generate_doc_file(const std::vector<Employee> &current_vector, const int &size) // function for generate document
{
    if (size == 0) 
    {
        std::cout << "\nData file doesn't exist. Add a new employee for create a new data file. " << std::endl << std::endl; 
    }
    else 
    {   
        std::string file_name;
        std::ofstream employeesData; 
        std::cout << "\nPlease enter the name of your file. " << std::endl;
        std::cin >> file_name;

        employeesData.open(file_name + ".doc", std::ios::out);

        employeesData << "LIST OF YOUR EMPLOYEES ( " << size << " REGISTERED EMPLOYEES ) :" << std::endl << std::endl; 

        for (auto element: current_vector)
        {
            employeesData << "\n<< Employee nr " << element.employeeNum << " >>" << std::endl;
            employeesData << "\nName: " << element.name << std::endl;
            employeesData << "Surname: " << element.surname << std::endl;
            employeesData << "Gender: " << element.gender << std::endl;
            employeesData << "Age: " << element.age << std::endl << std::endl;
        } 

        employeesData.close();

        std::cout << "\nDocument was generated successfully!." << std::endl << std::endl;
    }  
}

void Employee::add(const std::vector<Employee> &current_vector, const int &size) // write to file a new employee
{   
    employeeNum = size + 1;

    std::cout << "\nPlease write name of employee: ";
    std::cin >> name;
    std::cout << "Please write surname of employee: ";
    std::cin >> surname;
    std::cout << "Please write gender of employee [M/F]: ";
    std::cin >> gender;
    std::cout << "Please write age of employee: ";
    std::cin >> age;

    std::ofstream employeesData; 
    employeesData.open("employeesData.txt", std::ios::out | std::ios::app);

    employeesData << employeeNum << std::endl;
    employeesData << name << std::endl;
    employeesData << surname << std::endl;
    employeesData << gender << std::endl;
    employeesData << age << std::endl;

    std::cout << "\nRegistered new employee!" << std::endl;

    employeesData.close();

    std::cout << "\n---<< Employee nr " << employeeNum << " >>---" << std::endl
              << "\nName: " << name << std::endl
              << "Surname: " << surname << std::endl
              << "Gender: " << gender << std::endl
              << "Age: " << age << std::endl << std::endl;
}

int validate_integer(const int &size) // function for check if input is integer
{   
    int number;

    if (size == 0)
    {                 
        std::cout<<"\nFile doesn't exist. Add a new employee." << std::endl << std::endl;
    } 
    else
    {
        while (true)
        {
            std::cout << "\nPlease write number of employee: ";

            std::cin >> number; 

            if (!std::cin.good() || number <= 0) // integer check
            {
                std::cout << "\nThe entered value is not correct, try again." << std::endl; 
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            } 
            else if ( number > size)
            {   
                std::cout << "\nThe entered value is too high. There are " << size << " registered employees in the database. Try again." << std::endl; 
            } 
            else 
            { 
                break;
            }
        }
    }

    return number - 1;
}

int Employee::search(const std::vector<Employee> &current_vector, const int &size) // function for display just one employee from list
{   
    int new_number = validate_integer(size);

    if (size != 0)
    {
        std::cout   << "\n<< Employee nr " << current_vector.at(new_number).employeeNum << " >>" << std::endl
                    << "\nName: " << current_vector.at(new_number).name << std::endl
                    << "Surname: " << current_vector.at(new_number).surname << std::endl
                    << "Gender: " << current_vector.at(new_number).gender << std::endl
                    << "Age: " << current_vector.at(new_number).age << std::endl << std::endl;
    }

    return new_number;
}   

void Employee::delete_employee(std::vector<Employee> &current_vector, int &size) // function for delete just one employee from list
{
        int new_number = search(current_vector, size);
        current_vector.erase(current_vector.begin() + new_number);
        size = current_vector.size();

        std::cout   << "Emploee number " << new_number + 1  << " was deleted!" << std::endl << std::endl;

        if (size == 0) 
        {
            std::remove("employeesData.txt");
        } 
        else
        {
            std::ofstream employeesData; 
            employeesData.open("employeesData.txt", std::ios::out | std::ios::trunc);

            for (int i = 0; i < size; i++)
            {
                current_vector.at(i).employeeNum = i + 1;
                
                employeesData << current_vector.at(i).employeeNum << std::endl;
                employeesData << current_vector.at(i).name << std::endl;
                employeesData << current_vector.at(i).surname << std::endl;
                employeesData << current_vector.at(i).gender << std::endl;
                employeesData << current_vector.at(i).age << std::endl;
            }

            employeesData.close();
        } 
}   

void remove_list() // function for destroy all data file
{   
    if (std::remove("employeesData.txt") == 0)
    {
        std::cout << "\nData file deleted successfully!" << std::endl << std::endl;
    }
    else 
    {
        std::cout << "\nData file doesn't exist. Add a new employee." << std::endl << std::endl; 
    }
}

Employee::Employee(int id, std::string n, std::string s, char g, int a) 
{
    employeeNum = id;
    name = n;
    surname = s;
    gender = g;
    age = a;
}

Employee::Employee(const Employee &copy_obj) 
{
    employeeNum = copy_obj.employeeNum;
    name = copy_obj.name;
    surname = copy_obj.surname;
    gender = copy_obj.gender;
    age = copy_obj.age;
}

Employee::~Employee() 
{
    //  std::cout << "\nClean" << std::endl;
}
