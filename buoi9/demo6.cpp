#include <iostream>
using namespace std;

// Hàm đổi chỗ (swap) hai giá trị
void hoanDoi(float &a, float &b) {
    float temp = a;
    a = b;
    b = temp;
}

// Hàm chia mảng và trả về vị trí pivot
int phanHoach(float *giaSanPham, int low, int high) {
    float pivot = giaSanPham[high]; // Chọn phần tử cuối làm pivot
    int i = low - 1; // Chỉ số của phần tử nhỏ hơn pivot

    for (int j = low; j <= high - 1; j++) {
        if (giaSanPham[j] < pivot) {
            i++; // Tăng chỉ số của phần tử nhỏ hơn
            hoanDoi(giaSanPham[i], giaSanPham[j]); // Hoán đổi
        }
    }
    hoanDoi(giaSanPham[i + 1], giaSanPham[high]); // Đưa pivot vào đúng vị trí
    return i + 1;
}

// Hàm Quicksort để sắp xếp mảng
void quicksort(float *giaSanPham, int low, int high) {
    if (low < high) {
        // Chia mảng và lấy vị trí pivot
        int pivot = phanHoach(giaSanPham, low, high);

        // Gọi đệ quy sắp xếp các phần phía trước và sau pivot
        quicksort(giaSanPham, low, pivot - 1);
        quicksort(giaSanPham, pivot + 1, high);
    }
}

// Hàm nhập danh sách giá sản phẩm
void nhapGiaSanPham(float *giaSanPham, int soLuongSanPham) {
    for (int i = 0; i < soLuongSanPham; i++) {
        cout << "Nhập giá sản phẩm thứ " << i + 1 << ": ";
        cin >> giaSanPham[i];
    }
}

// Hàm hiển thị danh sách giá sản phẩm
void hienThiGiaSanPham(float *giaSanPham, int soLuongSanPham) {
    cout << "\nDanh sách giá sản phẩm:\n";
    for (int i = 0; i < soLuongSanPham; i++) {
        cout << "Sản phẩm " << i + 1 << ": " << giaSanPham[i] << " VND" << endl;
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

    // Sắp xếp danh sách giá sản phẩm bằng thuật toán Quicksort
    quicksort(danhSachGiaSanPham, 0, soLuongSanPham - 1);

    // Hiển thị danh sách giá sản phẩm sau khi sắp xếp
    cout << "\nDanh sách giá sản phẩm sau khi sắp xếp tăng dần:\n";
    hienThiGiaSanPham(danhSachGiaSanPham, soLuongSanPham);

    // Giải phóng bộ nhớ của mảng động
    delete[] danhSachGiaSanPham;

    return 0;
}
