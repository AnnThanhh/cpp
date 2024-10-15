#include <iostream>
#include <string>
using namespace std;

// Lớp trừu tượng Employee
class Employee {
protected:
    string name;
    int age;

public:
    // Constructor cho Employee
    Employee(string empName, int empAge) : name(empName), age(empAge) {}

    // Phương thức thuần ảo (trừu tượng) tính lương
    virtual double calculateSalary() const = 0; // Các lớp con phải triển khai

    // Phương thức hiển thị thông tin nhân viên
    virtual void displayInfo() const {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
    }

    // Destructor ảo
    virtual ~Employee() {}
};

// Lớp Manager kế thừa từ Employee
class Manager : public Employee {
private:
    double baseSalary;    // Lương cơ bản
    int numEmployees;     // Số lượng nhân viên dưới quyền

public:
    // Constructor cho Manager
    Manager(string mgrName, int mgrAge, double mgrBaseSalary, int employees)
        : Employee(mgrName, mgrAge), baseSalary(mgrBaseSalary), numEmployees(employees) {}

    // Ghi đè phương thức tính lương
    double calculateSalary() const override {
        return baseSalary + numEmployees * 100; // Mỗi nhân viên dưới quyền thêm 100 vào lương
    }

    // Ghi đè phương thức hiển thị thông tin
    void displayInfo() const override {
        Employee::displayInfo();
        cout << "Base Salary: " << baseSalary << " USD" << endl;
        cout << "Number of Employees: " << numEmployees << endl;
        cout << "Total Salary: " << calculateSalary() << " USD" << endl;
    }
};

// Lớp Developer kế thừa từ Employee
class Developer : public Employee {
private:
    int hoursWorked;      // Số giờ làm việc
    double hourlyRate;    // Hệ số lương theo giờ

public:
    // Constructor cho Developer
    Developer(string devName, int devAge, int hours, double rate)
        : Employee(devName, devAge), hoursWorked(hours), hourlyRate(rate) {}

    // Ghi đè phương thức tính lương
    double calculateSalary() const override {
        return hoursWorked * hourlyRate; // Tính lương dựa trên số giờ làm việc và hệ số lương
    }

    // Ghi đè phương thức hiển thị thông tin
    void displayInfo() const override {
        Employee::displayInfo();
        cout << "Hours Worked: " << hoursWorked << endl;
        cout << "Hourly Rate: " << hourlyRate << " USD" << endl;
        cout << "Total Salary: " << calculateSalary() << " USD" << endl;
    }
};

// Chương trình chính
int main() {
    // Tạo đối tượng Manager
    Employee* manager = new Manager("Alice Johnson", 45, 5000, 10);
    cout << "Manager Information:" << endl;
    manager->displayInfo();
    cout << "----------------------" << endl;

    // Tạo đối tượng Developer
    Employee* developer = new Developer("Bob Smith", 30, 160, 30);  // 160 giờ làm việc, 30 USD/giờ
    cout << "Developer Information:" << endl;
    developer->displayInfo();

    // Giải phóng bộ nhớ
    delete manager;
    delete developer;

    return 0;
}
