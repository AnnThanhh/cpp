#include <iostream>
#include <string>
using namespace std;

class Product {
private:
    // Các thuộc tính được đóng gói
    string productID;
    string name;
    double price;

public:
    // Constructor để khởi tạo đối tượng Product
    Product(string id, string productName, double productPrice) {
        productID = id;
        name = productName;
        price = productPrice;
    }

    // Phương thức getProductInfo() để lấy thông tin sản phẩm
    void getProductInfo() const {
        cout << "Product ID: " << productID << endl;
        cout << "Product Name: " << name << endl;
        cout << "Price: " << price << " USD" << endl;
    }

    // Phương thức setPrice() để thay đổi giá sản phẩm theo chính sách giảm giá
    void setPrice(double discountPercent) {
        if (discountPercent < 0 || discountPercent > 100) {
            cout << "Invalid discount percentage!" << endl;
            return;
        }

        // Tính giá sau khi giảm giá
        double discountAmount = price * (discountPercent / 100);
        price -= discountAmount;
    }
};

int main() {
    // Tạo đối tượng sản phẩm
    Product product1("P001", "Laptop", 1200.0);

    // Hiển thị thông tin sản phẩm trước khi giảm giá
    cout << "Before discount:" << endl;
    product1.getProductInfo();

    // Thay đổi giá với chính sách giảm giá
    product1.setPrice(10);  // Giảm giá 10%

    // Hiển thị thông tin sản phẩm sau khi giảm giá
    cout << "\nAfter discount:" << endl;
    product1.getProductInfo();

    return 0;
}
