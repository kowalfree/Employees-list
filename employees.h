#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <limits>
#include <cstdlib>
#include <cstdio>
#include <regex>
#include <conio.h>

bool isInteger(const std::string &exampleInput);
bool isString(const std::string &exampleString);
int displayMenu();
void removeList();
  
namespace project 
{
    class Employee 
    {   
        private:

        unsigned employeeId;
        std::string name;
        std::string surname;
        char gender;
        unsigned age;
    
        public:
        
        Employee(unsigned int objId = 0, std::string objName = "unknown", std::string objSurname = "unknown", char objGender = '-', unsigned int objAge = 0);
        ~Employee();
        Employee(const Employee &copyObj);

        std::vector<Employee> createVector(Employee &member);
        void showData(const std::vector<Employee> &currentVector);
        void generateDocFile(const std::vector<Employee> &currentVector);
        void addToFile(const std::vector<Employee> &currentVector);
        int validateInteger(const std::vector<Employee> &currentVector);
        int search(const std::vector<Employee> &currentVector);
        void deleteEmployee(std::vector<Employee> &currentVector);
    };
}