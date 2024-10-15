#include <iostream>
#include <string>
using namespace std;

// Cấu trúc sản phẩm
struct Product {
    string name;
    double price;
    int quantity;
    bool isAvailable;
};

// Hàm để nhập thông tin sản phẩm
void inputProduct(Product &product) {
    cout << "Nhập tên sản phẩm: ";
    getline(cin, product.name);

    cout << "Nhập giá sản phẩm: ";
    cin >> product.price;

    cout << "Nhập số lượng sản phẩm: ";
    cin >> product.quantity;

    cout << "Sản phẩm có sẵn không (1: Có, 0: Không): ";
    cin >> product.isAvailable;
    cin.ignore(); // Bỏ qua ký tự xuống dòng sau khi nhập boolean
}

// Hàm để tính tổng tiền
double calculateTotalPrice(const Product &product) {
    return product.price * product.quantity;
}

// Hàm để kiểm tra trạng thái kho
void checkAvailability(const Product &product) {
    if (product.isAvailable) {
        cout << "In Stock" << endl;
    } else {
        cout << "Out of Stock" << endl;
    }
}

// Hàm để hiển thị thông tin sản phẩm
void displayProduct(const Product &product) {
    cout << "\n--- Thông tin sản phẩm ---" << endl;
    cout << "Tên sản phẩm: " << product.name << endl;
    cout << "Giá: " << product.price << " VND" << endl;
    cout << "Số lượng: " << product.quantity << endl;
    cout << "Trạng thái: " << (product.isAvailable ? "Có sẵn" : "Không có sẵn") << endl;

    double total = calculateTotalPrice(product);
    cout << "Tổng tiền: " << total << " VND" << endl;

    checkAvailability(product);
}

int main() {
    Product product;

    inputProduct(product);

    displayProduct(product);

    return 0;
}
