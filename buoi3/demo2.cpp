#include <iostream>
#include <string>
using namespace std;

int main() {
    string productName;
    int quantity;
    double price, totalValue = 0;
    char choice;

    do {
        // Nhập tên sản phẩm
        cout << "Enter product name: ";
        cin >> productName;

        // Nhập số lượng sản phẩm
        cout << "Enter quantity of " << productName << ": ";
        cin >> quantity;

        // Nhập giá của mỗi sản phẩm
        cout << "Enter price of " << productName << ": ";
        cin >> price;

        // Tính tổng giá trị cho sản phẩm đó
        totalValue += quantity * price;

        // Hỏi người dùng có muốn nhập thêm sản phẩm không
        cout << "Do you want to add another product? (y/n): ";
        cin >> choice;

    } while (choice == 'y' || choice == 'Y');

    // Hiển thị tổng giá trị sản phẩm trong kho
    cout << "\nTotal value of products in stock: $" << totalValue << endl;

    return 0;
}
