#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Lớp Employee với tính đóng gói
class Employee {
private:
    // Các thuộc tính được đóng gói
    string employeeID;
    string name;
    string position;
    double salary;

public:
    // Constructor để khởi tạo đối tượng Employee
    Employee(string id, string employeeName, string employeePosition, double initialSalary) {
        employeeID = id;
        name = employeeName;
        position = employeePosition;
        if (initialSalary >= 0) {
            salary = initialSalary;
        } else {
            salary = 0;
            cout << "Invalid initial salary! Salary set to 0." << endl;
        }
    }

    // Phương thức setSalary() để thay đổi lương (với kiểm tra)
    void setSalary(double newSalary) {
        if (newSalary >= 0) {
            salary = newSalary;
            cout << "Salary updated successfully!" << endl;
        } else {
            cout << "Invalid salary! Salary not updated." << endl;
        }
    }

    // Phương thức getEmployeeInfo() để hiển thị thông tin nhân viên
    void getEmployeeInfo() const {
        cout << "Employee ID: " << employeeID << endl;
        cout << "Name: " << name << endl;
        cout << "Position: " << position << endl;
        cout << "Salary: " << salary << " USD" << endl;
    }

    // Phương thức để lấy mã nhân viên
    string getEmployeeID() const {
        return employeeID;
    }
};

// Hệ thống quản lý nhiều nhân viên
class EmployeeManagementSystem {
private:
    vector<Employee> employees;

public:
    // Phương thức thêm nhân viên mới
    void addEmployee(const Employee& employee) {
        employees.push_back(employee);
    }

    // Phương thức tìm kiếm và hiển thị thông tin nhân viên theo ID
    void displayEmployeeInfoByID(const string& employeeID) {
        for (const auto& employee : employees) {
            if (employee.getEmployeeID() == employeeID) {
                employee.getEmployeeInfo();
                return;
            }
        }
        cout << "Employee with ID " << employeeID << " not found." << endl;
    }

    // Phương thức hiển thị tất cả nhân viên
    void displayAllEmployees() {
        for (const auto& employee : employees) {
            employee.getEmployeeInfo();
            cout << "----------------------" << endl;
        }
    }
};

int main() {
    // Tạo hệ thống quản lý nhân viên
    EmployeeManagementSystem system;

    // Thêm một số nhân viên vào hệ thống
    Employee emp1("E001", "Alice Johnson", "Manager", 5000);
    Employee emp2("E002", "Bob Smith", "Developer", 4000);
    Employee emp3("E003", "Charlie Brown", "Designer", 3500);

    system.addEmployee(emp1);
    system.addEmployee(emp2);
    system.addEmployee(emp3);

    // Hiển thị thông tin của tất cả nhân viên
    cout << "All Employees Information:" << endl;
    system.displayAllEmployees();

    // Tìm kiếm và hiển thị thông tin của một nhân viên theo ID
    cout << "\nDisplaying information of employee with ID E002:" << endl;
    system.displayEmployeeInfoByID("E002");

    // Thay đổi lương của nhân viên và hiển thị lại thông tin
    cout << "\nUpdating salary for employee E002..." << endl;
    emp2.setSalary(4500);
    system.displayEmployeeInfoByID("E002");

    return 0;
}
