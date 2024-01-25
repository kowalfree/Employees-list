#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>


void menu();

class Employee 
{
    std::string name, surname;
    char gender;
    int age;
    
    int employeeNum;
    int allEmployees;
    std::fstream employeesData; 
   
    public:
    
    Employee(std::string = "unknown", std::string = "unknown", char = '-', int = 0);
    ~Employee();

    void showData();
    int count();
    void add();
    void remove();
};
