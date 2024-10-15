#include <iostream>
#include <string>
using namespace std;

class Customer {
private:
    // Các thuộc tính được đóng gói
    string customerID;
    string name;
    double balance;

public:
    // Constructor để khởi tạo đối tượng Customer
    Customer(string id, string customerName, double initialBalance) {
        customerID = id;
        name = customerName;
        balance = initialBalance;
    }

    // Phương thức nạp tiền vào tài khoản
    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Deposit successful! Current balance: " << balance << " USD" << endl;
        } else {
            cout << "Deposit amount must be positive!" << endl;
        }
    }

    // Phương thức rút tiền từ tài khoản
    void withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            cout << "Withdrawal successful! Current balance: " << balance << " USD" << endl;
        } else if (amount > balance) {
            cout << "Insufficient balance!" << endl;
        } else {
            cout << "Withdrawal amount must be positive!" << endl;
        }
    }

    // Phương thức lấy số dư hiện tại
    double getBalance() const {
        return balance;
    }

    // Phương thức hiển thị thông tin khách hàng
    void getCustomerInfo() const {
        cout << "Customer ID: " << customerID << endl;
        cout << "Customer Name: " << name << endl;
        cout << "Balance: " << balance << " USD" << endl;
    }
};

int main() {
    // Tạo đối tượng khách hàng
    Customer customer1("C001", "John Doe", 5000.0);

    // Hiển thị thông tin khách hàng
    customer1.getCustomerInfo();

    // Giao dịch nạp tiền
    cout << "\nDepositing 1000 USD..." << endl;
    customer1.deposit(1000);

    // Giao dịch rút tiền
    cout << "\nWithdrawing 2000 USD..." << endl;
    customer1.withdraw(2000);

    // Thử rút số tiền lớn hơn số dư
    cout << "\nWithdrawing 5000 USD..." << endl;
    customer1.withdraw(5000);

    // Hiển thị số dư cuối cùng
    cout << "\nFinal balance: " << customer1.getBalance() << " USD" << endl;

    return 0;
}
