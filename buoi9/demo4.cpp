#include <iostream>
using namespace std;

// Hàm nhập danh sách giá sản phẩm
void nhapGiaSanPham(float *giaSanPham, int soLuongSanPham) {
    for (int i = 0; i < soLuongSanPham; i++) {
        cout << "Nhập giá sản phẩm thứ " << i + 1 << ": ";
        cin >> *(giaSanPham + i);
    }
}

// Hàm hiển thị danh sách giá sản phẩm
void hienThiGiaSanPham(float *giaSanPham, int soLuongSanPham) {
    cout << "\nDanh sách giá sản phẩm:\n";
    for (int i = 0; i < soLuongSanPham; i++) {
        cout << "Sản phẩm " << i + 1 << ": " << *(giaSanPham + i) << " VND" << endl;
    }
}

// Hàm sắp xếp nổi bọt
void sapXepNoiBot(float *giaSanPham, int soLuongSanPham) {
    for (int i = 0; i < soLuongSanPham - 1; i++) {
        for (int j = 0; j < soLuongSanPham - i - 1; j++) {
            // So sánh từng cặp phần tử liền kề và hoán đổi nếu cần
            if (*(giaSanPham + j) > *(giaSanPham + j + 1)) {
                // Hoán đổi giá trị
                float temp = *(giaSanPham + j);
                *(giaSanPham + j) = *(giaSanPham + j + 1);
                *(giaSanPham + j + 1) = temp;
            }
        }
    }
}

int main() {
    int soLuongSanPham;

    // Nhập số lượng sản phẩm
    cout << "Nhập số lượng sản phẩm: ";
    cin >> soLuongSanPham;

    // Khởi tạo mảng động để lưu giá sản phẩm
    float *danhSachGiaSanPham = new float[soLuongSanPham];

    // Nhập danh sách giá sản phẩm
    nhapGiaSanPham(danhSachGiaSanPham, soLuongSanPham);

    // Hiển thị danh sách giá sản phẩm trước khi sắp xếp
    cout << "\nDanh sách giá sản phẩm trước khi sắp xếp:\n";
    hienThiGiaSanPham(danhSachGiaSanPham, soLuongSanPham);

    // Sắp xếp danh sách giá sản phẩm theo thứ tự tăng dần bằng thuật toán nổi bọt
    sapXepNoiBot(danhSachGiaSanPham, soLuongSanPham);

    // Hiển thị danh sách giá sản phẩm sau khi sắp xếp
    cout << "\nDanh sách giá sản phẩm sau khi sắp xếp tăng dần:\n";
    hienThiGiaSanPham(danhSachGiaSanPham, soLuongSanPham);

    // Giải phóng bộ nhớ của mảng động
    delete[] danhSachGiaSanPham;

    return 0;
}
