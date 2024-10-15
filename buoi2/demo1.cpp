#include <iostream>
using namespace std;

int main() {
    string dish;
    int quantity = 0;
    double price = 0.0;
    bool isVIP;
    double discount = 0.0;
    char continueOrder;  // Dùng để quyết định xem có tiếp tục đặt món hay không
    double total = 0.0;

    // Kiểm tra khách hàng VIP
    cout << "Khách hàng có phải là VIP không? (1: Có, 0: Không): ";
    cin >> isVIP;

    // Lặp đặt món ăn cho đến khi khách hàng muốn dừng
    do {
        // Nhập món ăn
        cout << "Enter dish name (Burger, Pizza, Pasta): ";
        cin >> dish;

        // Xác định giá món ăn
        if (dish == "Burger") {
            price = 5.0;
        } else if (dish == "Pizza") {
            price = 7.0;
        } else if (dish == "Pasta") {
            price = 6.0;
        } else {
            cout << "Dish not available." << endl;
            continue;
        }

        // Nhập số lượng món ăn
        cout << "Enter quantity: ";
        cin >> quantity;

        // Tính tổng tiền cho món vừa chọn
        total += price * quantity;

        // Hỏi khách hàng có muốn tiếp tục đặt món không
        cout << "Do you want to order another dish? (y/n): ";
        cin >> continueOrder;

    } while (continueOrder == 'y' || continueOrder == 'Y');

    // Tính toán giảm giá
    if (quantity > 10 && isVIP) {
        discount = 0.2;  // Giảm thêm 20%
    } else if (isVIP) {
        discount = 0.1;  // Giảm 10%
    }

    double finalAmount = total * (1 - discount);

    // Output
    cout << "\n--- Recipe ---" << endl;
    cout << "Total amount: $" << total << endl;
    cout << "Discount applied: " << discount * 100 << "%" << endl;
    cout << "Final amount: $" << finalAmount << endl;

    return 0;
}
