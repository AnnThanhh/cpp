#include <iostream>
#include <string>
using namespace std;

// Lớp cha Person
class Person {
protected:
    string name;
    int age;

public:
    // Constructor cho Person
    Person(string personName, int personAge) {
        name = personName;
        age = personAge;
    }

    // Phương thức hiển thị thông tin Person
    virtual void displayInfo() const {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
    }
};

// Lớp con Employee kế thừa từ Person
class Employee : public Person {
protected:
    double salary;
    string position;

public:
    // Constructor cho Employee
    Employee(string employeeName, int employeeAge, double employeeSalary, string employeePosition)
        : Person(employeeName, employeeAge) {
        salary = employeeSalary;
        position = employeePosition;
    }

    // Ghi đè phương thức displayInfo() để hiển thị thêm thông tin Employee
    void displayInfo() const override {
        Person::displayInfo();  // Gọi phương thức hiển thị thông tin từ lớp cha
        cout << "Position: " << position << endl;
        cout << "Salary: " << salary << " USD" << endl;
    }
};

// Lớp con Manager kế thừa từ Employee
class Manager : public Employee {
private:
    int teamSize;

public:
    // Constructor cho Manager
    Manager(string managerName, int managerAge, double managerSalary, string managerPosition, int managerTeamSize)
        : Employee(managerName, managerAge, managerSalary, managerPosition) {
        teamSize = managerTeamSize;
    }

    // Ghi đè phương thức displayInfo() để hiển thị thông tin Manager
    void displayInfo() const override {
        Employee::displayInfo();  // Gọi phương thức hiển thị thông tin từ lớp Employee
        cout << "Team Size: " << teamSize << endl;
    }
};

// Chương trình chính
int main() {
    // Tạo đối tượng Employee
    Employee emp1("John Doe", 30, 50000, "Software Engineer");
    cout << "Employee Information:" << endl;
    emp1.displayInfo();
    cout << "----------------------" << endl;

    // Tạo đối tượng Manager
    Manager mgr1("Alice Smith", 45, 85000, "IT Manager", 10);
    cout << "Manager Information:" << endl;
    mgr1.displayInfo();

    return 0;
}
