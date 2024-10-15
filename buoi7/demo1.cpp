#include <iostream>
using namespace std;

int main() {
    int x = 10;            // Khai báo biến int
    int *ptrX = &x;        // Con trỏ trỏ đến biến x
    int **ptrPtrX = &ptrX; // Con trỏ của con trỏ trỏ đến ptrX

    // Hiển thị địa chỉ của biến x, con trỏ ptrX, và con trỏ ptrPtrX
    cout << "Địa chỉ của biến x: " << &x << endl;
    cout << "Địa chỉ của con trỏ ptrX: " << &ptrX << endl;
    cout << "Địa chỉ của con trỏ ptrPtrX: " << &ptrPtrX << endl;

    // Hiển thị giá trị của x thông qua con trỏ của con trỏ
    cout << "Giá trị của x thông qua ptrX: " << *ptrX << endl;
    cout << "Giá trị của x thông qua ptrPtrX: " << **ptrPtrX << endl;

    return 0;
}
