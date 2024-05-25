#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <limits>
#include <cstdlib>
#include <cstdio>
#include <regex>
#include <conio.h>


// You can create another file with some utils (optional)
bool checkInteger(const std::string &example_input);
bool checkString(const std::string &example_string);
int display_menu();
void remove_list();
int validate_integer(const int &size);

// you can add some namespace with name lets say project

// namespace project
// {

class Employee
{
// private:
    int employeeNum; // prefer employeeId unsigned int
    std::string name, surname; // each declaration should be written separate lines
    char gender;

    // maybe enum class will be better
    /*
    enum class Gender
    {
        MALE,
        FEMALE,
        NOT_SET
    };

    Gender gender{Gender::NOT_SET};
    */
    int age; // unsigned
   
    public:
    
    Employee(int = 0, std::string = "unknown", std::string = "unknown", char = '-', int = 0); // please add name of args
    ~Employee();
    Employee(const Employee &copy_obj);

    // you can use --> using EmployeesList = std::vector<Employee>
    // add to functions declarations const in case of we dont modify member variables i.e void showData(...) const;
    // this size arg is not needed
    std::vector<Employee> create_vector(Employee &member);
    void showData(const std::vector<Employee> &current_vector, const int &size); // const int& arg --> better to read
    void generate_doc_file(const std::vector<Employee> &current_vector, const int &size);
    void add(const std::vector<Employee> &current_vector, const int &size);
    int search(const std::vector<Employee> &current_vector, const int &size);
    void delete_employee(std::vector<Employee> &current_vector, int &size);
};

// } // namespace project 