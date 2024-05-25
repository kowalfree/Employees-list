#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstdlib>
#include <limits>
#include <cstdio>
#include <regex>
#include <conio.h>
#include "employees.h"

// name --> isInteger
bool checkInteger(const std::string &example_input) // function for validate input_integer
{
    int input_integer; // not in use
    bool check = 0; // remove
    std::regex isInteger("\\D"); // \\D: matches any non-digit characters
    bool result = regex_search(example_input, isInteger);

    if(result) // if (regex_search(example_input, std::regex("\\D"))) - optional
    {   
        std::cout << "\nInput value is not correct. Try again." << std::endl << std::endl;
    }
    else
    {   
        check = 1; // return true ???
    }
    
    return check; // return false
}

bool checkString(const std::string &example_string) // function for validate input_string
{
    int input_string;
    bool check = 0;
    std::regex isString("[\\d\\W_]"); 
    // regex = [\\d\\W_] = [-_'\";:,.<>/?=+!@#$%^&*(){}|\\`\]\[~0-9], \\d: matches any digit character. \\W: matches any non-word character. 
    bool result = regex_search(example_string, isString);

    if(result)
    {   
        std::cout << "\nInput value is not correct. Try again." << std::endl << std::endl;
    }
    else
    {   
        check = 1; 
    }
    
    return check;
}

int display_menu() // display menu with options
{
    std::cout << "\nThis is list of employees, please choose one of the options below:" << std::endl << std::endl; // maybe \n\n ???? intead of std::endl
    std::cout << "1 - Show all list of employees" << std::endl;
    std::cout << "2 - Generate document file" << std::endl;
    std::cout << "3 - Add a new employee" << std::endl;
    std::cout << "4 - Search employee from list" << std::endl;
    std::cout << "5 - Delete employee from list" << std::endl;
    std::cout << "6 - Remove all list" << std::endl;
    std::cout << "7 - Quit" << std::endl;

    int option; // uninitialized variable

    while(true) // i really dont like this design ;_;
    {
        std::cout << "\nYour option: ";
        std::string input;
        std::cin >> input;
        std::cout << std::endl;

        if (checkInteger(input) == 1) // checkInteger(input) == true or just checkInteger(input)
        {
            option = stoi(input);

            if (option < 1 ||  option > 7) // condition for check range od numbers
            {
                std::cout << "\nInput value is out of range. Try again." << std::endl;
            } 
            else
            {
                break;
            }
        } 
    }

    return option;
}

// this function has two responsibility - create vector and write data to file, please do separation
std::vector<Employee> Employee::create_vector(Employee &member) // create vector of objects from file
{
    std::vector<Employee> box_for_members; // tempData
    std::fstream employeesData; 

    employeesData.open("employeesData.txt", std::ios::in); 
    
    if(employeesData) // mix of format style --> formatStyle vs format_style (suggest to use camel case style)
    {   
        while(true)
        {
            employeesData >> member.employeeNum;
            employeesData >> member.name;
            employeesData >> member.surname;
            employeesData >> member.gender;
            employeesData >> member.age;

            if (employeesData.eof()) // why not while (not employeesData.eof()) ???
            {
                break;
            }
           
            box_for_members.push_back(member);  
        }
    }

    employeesData.close();

    return box_for_members;
}

void Employee::showData(const std::vector<Employee> &current_vector, const int &size) // read current all data file // <--- remove second argument
{   
    if (size == 0) // current_vector.size() == 0
    {
        std::cout << "\nData file doesn't exist. Add a new employee for create a new data file. " << std::endl << std::endl;
        // return;
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
    
        while(true) // check input name is string
        {
            std::cout << "Please enter the name of your file ( don't use any digits and special signs ): ";
            std::cin >> file_name;

            if (checkString(file_name) == 1) // isCorrectStringFormat
            {
                break;
            } 
        }

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
    
    while(true) // check input name is string
    {
        std::cout << "Please write name of employee: ";
        std::cin >> name;

        if (checkString(name) == 1)
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            break;
        } 
    }

    while(true) // check input surname is string
    {
        std::cout << "Please write surname of employee: ";
        std::cin >> surname;

        if (checkString(surname) == 1)
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            break;
        } 
    }
    
    while(true) // check input gender is correct
    {   
        std::cout << "Please write gender of employee [M/F]: ";
        gender = getche();
        
        if (gender == 'M' || gender == 'F')
        {
            break;
        }
        else if (gender == 'm' || gender == 'f')
        {   
            gender = toupper(gender);
            break;
        } 
        else
        {
            std::cout << "\nInput value is not correct. Try again." << std::endl << std::endl;
        }
    }

    while(true) // check input age is integer
    {
        std::cout << "\nPlease write age of employee: ";
        std::string input_age;
        std::cin >> input_age;

        if (checkInteger(input_age) == 1)
        {
            age = stoi(input_age);
            break;
        } 
    }

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
    int number; // int number{0};

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
            char ch; 
            std::cin.get(ch);
    
            if (!std::cin.good() || number <= 0 || ch == '.') // statement for check if input is integer
            {
                std::cout << "\nThe entered value is not correct, try again." << std::endl; 
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            } 
            else if ( number > size)
            {   
                std::cout << "\nThe entered value is too high! There are " << size << " registered employees in the database. Try again." << std::endl; 
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
    int new_number = search(current_vector, size); // this function tells us about delete but here we have something with name new, what does mean ???
    
    if (size != 0) // if (not current_vector.empty())
    {
        // more safety is -->
        /*
            emploeeIdToDelete = new_number + 1;

            const auto& matchedId = std::find_if(
                current_vector.begin(),
                current_vector.end(),
                [&new_number](const auto& employee) { return ( employee.employeeNum == emploeeIdToDelete ); });
            if(matchedId != current_vector.end())
            {
                current_vector.erase(matchedId);
            }

            NOTE: you can try with erase_if or remove_if too // C++20
        */

        current_vector.erase(current_vector.begin() + new_number);
        std::cout   << "Emploee number " << new_number + 1  << " was deleted!" << std::endl << std::endl;
    }

    size = current_vector.size();

    if (size == 0) // if (current_vector.empty())
    {
        remove("employeesData.txt");
    } 
    else
    {
        std::ofstream employeesData; 
        employeesData.open("employeesData.txt", std::ios::out | std::ios::trunc); //  clear all file and write a new data file from vector of objects

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

void remove_list() // function for destroy data file
{   
    if (remove("employeesData.txt") == 0)
    {
        std::cout << "\nData file deleted successfully!" << std::endl << std::endl;
    }
    else 
    {
        std::cout << "\nData file doesn't exist. Add a new employee." << std::endl << std::endl; 
    }
}

Employee::Employee(int id, std::string n, std::string s, char g, int a) // please use full words
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
