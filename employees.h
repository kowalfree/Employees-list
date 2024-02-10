#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <limits>
#include <cstdlib>
#include <cstdio>
#include <regex>
#include <conio.h>

bool checkInteger(const std::string &example_input);
bool checkString(const std::string &example_string);
int display_menu();
void remove_list();
int validate_integer(const int &size);
  
class Employee 
{
    int employeeNum;
    std::string name, surname;
    char gender;
    int age;
   
    public:
    
    Employee(int = 0, std::string = "unknown", std::string = "unknown", char = '-', int = 0);
    ~Employee();
    Employee(const Employee &copy_obj);

    std::vector<Employee> create_vector(Employee &member);
    void showData(const std::vector<Employee> &current_vector, const int &size);
    void generate_doc_file(const std::vector<Employee> &current_vector, const int &size);
    void add(const std::vector<Employee> &current_vector, const int &size);
    int search(const std::vector<Employee> &current_vector, const int &size);
    void delete_employee(std::vector<Employee> &current_vector, int &size);
};