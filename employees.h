#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <vector>

class Employee 
{
    std::string name;
    std::string surname;
    char gender;
    int age;
    std::fstream employeesData; 
     
    public:
   
    Employee(std::string = "unknown", std::string = "unknown", char = '-', int = 0);
    ~Employee();

    void add();
    void show();
    // void remove();
};