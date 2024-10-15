#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Cấu trúc để lưu thông tin nhân viên
struct Employee {
    string name;
    int age;
    double baseSalary;
};

// Hàm hiển thị menu
void showMenu() {
    cout << "===== MENU =====" << endl;
    cout << "1. Add new employee" << endl;
    cout << "2. Show all employees" << endl;
    cout << "3. Calculate salary" << endl;
    cout << "4. Exit" << endl;
    cout << "================" << endl;
}

// Hàm nhận lựa chọn từ người dùng
int getUserChoice() {
    int choice;
    cout << "Enter your choice: ";
    cin >> choice;
    return choice;
}

// Hàm thêm nhân viên mới
void addEmployee(vector<Employee>& employees) {
    Employee emp;
    cout << "Enter employee name: ";
    cin.ignore(); // Loại bỏ ký tự newline còn sót lại
    getline(cin, emp.name);
    cout << "Enter employee age: ";
    cin >> emp.age;
    cout << "Enter employee base salary: ";
    cin >> emp.baseSalary;
    
    employees.push_back(emp); // Thêm nhân viên vào danh sách
    cout << "Employee added successfully!" << endl;
}

// Hàm hiển thị tất cả nhân viên
void showAllEmployees(const vector<Employee>& employees) {
    if (employees.empty()) {
        cout << "No employees to show." << endl;
        return;
    }

    cout << "===== Employee List =====" << endl;
    for (const auto& emp : employees) {
        cout << "Name: " << emp.name << ", Age: " << emp.age << ", Base Salary: $" << emp.baseSalary << endl;
    }
    cout << "=========================" << endl;
}

// Hàm tính lương (giả sử thêm phụ cấp lương dựa trên kinh nghiệm tuổi)
void calculateSalary(const vector<Employee>& employees) {
    if (employees.empty()) {
        cout << "No employees to calculate salary for." << endl;
        return;
    }

    cout << "===== Salary Calculation =====" << endl;
    for (const auto& emp : employees) {
        double totalSalary = emp.baseSalary + (emp.age * 100);
        cout << "Employee: " << emp.name << ", Total Salary: $" << totalSalary << endl;
    }
    cout << "==============================" << endl;
}

// Hàm thực hiện tác vụ tương ứng với lựa chọn của người dùng
void performTask(int choice, vector<Employee>& employees) {
    switch (choice) {
        case 1: {
            addEmployee(employees);
            break;
        }
        case 2: {
            showAllEmployees(employees);
            break;
        }
        case 3: {
            calculateSalary(employees);
            break;
        }
        case 4: {
            cout << "Exiting the program." << endl;
            break;
        }
        default: {
            cout << "Invalid choice. Please try again." << endl;
            break;
        }
    }
}

// Hàm chính
int main() {
    vector<Employee> employees; 
    int choice;
    
    do {
        showMenu();                
        choice = getUserChoice();   
        performTask(choice, employees); 
        cout << endl;
    } while (choice != 4); 
    
    return 0;
}
