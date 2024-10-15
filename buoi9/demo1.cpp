#include <iostream>
#include <string>
using namespace std;

// Hàm nhập danh sách hàng hóa
void nhapDanhSachHangHoa(string *hangHoa, int soLuongHangHoa) {
    cin.ignore(); // 
    for (int i = 0; i < soLuongHangHoa; i++) {
        cout << "Nhập tên sản phẩm thứ " << i + 1 << ": ";
        getline(cin, *(hangHoa + i));
    }
}

// Hàm hiển thị danh sách hàng hóa
void hienThiDanhSachHangHoa(string *hangHoa, int soLuongHangHoa) {
    cout << "\nDanh sách hàng hóa trong kho:\n";
    for (int i = 0; i < soLuongHangHoa; i++) {
        cout << i + 1 << ". " << *(hangHoa + i) << endl;
    }
}

// Hàm tìm kiếm sản phẩm theo tên bằng tìm kiếm tuyến tính
void timKiemSanPham(string *hangHoa, int soLuongHangHoa, string tenSanPham) {
    bool timThay = false;
    for (int i = 0; i < soLuongHangHoa; i++) {
        if (*(hangHoa + i) == tenSanPham) {
            cout << "Sản phẩm \"" << tenSanPham << "\" có trong kho tại vị trí số " << i + 1 << endl;
            timThay = true;
            break;
        }
    }
    if (!timThay) {
        cout << "Không tìm thấy sản phẩm \"" << tenSanPham << "\" trong kho." << endl;
    }
}

int main() {
    int soLuongHangHoa;

    cout << "Nhập số lượng hàng hóa trong kho: ";
    cin >> soLuongHangHoa;

    // Khởi tạo mảng động để lưu danh sách hàng hóa
    string *danhSachHangHoa = new string[soLuongHangHoa];

    // Nhập danh sách các hàng hóa
    nhapDanhSachHangHoa(danhSachHangHoa, soLuongHangHoa);

    // Hiển thị danh sách hàng hóa
    hienThiDanhSachHangHoa(danhSachHangHoa, soLuongHangHoa);

    // Tìm kiếm sản phẩm theo tên
    string tenSanPham;
    cout << "\nNhập tên sản phẩm cần tìm kiếm: ";
    cin.ignore(); 
    getline(cin, tenSanPham);
    timKiemSanPham(danhSachHangHoa, soLuongHangHoa, tenSanPham);

    // Giải phóng bộ nhớ cho mảng động
    delete[] danhSachHangHoa;

    return 0;
}
