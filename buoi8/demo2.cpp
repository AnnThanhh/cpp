#include <iostream>
#include <cstring>
using namespace std;

// Hàm nhập danh sách sinh viên
void nhapDanhSachSinhVien(string *sinhVien, int soLuongSinhVien) {
    cin.ignore(); // Bỏ qua ký tự '\n' còn sót lại từ lần nhập trước
    for (int i = 0; i < soLuongSinhVien; i++) {
        cout << "Nhập tên sinh viên thứ " << i + 1 << ": ";
        getline(cin, *(sinhVien + i));
    }
}

// Hàm hiển thị danh sách sinh viên
void hienThiDanhSachSinhVien(string *sinhVien, int soLuongSinhVien) {
    cout << "\nDanh sách sinh viên:\n";
    for (int i = 0; i < soLuongSinhVien; i++) {
        cout << i + 1 << ". " << *(sinhVien + i) << endl;
    }
}

// Hàm tìm kiếm sinh viên theo tên
void timKiemSinhVien(string *sinhVien, int soLuongSinhVien, string tenTimKiem) {
    bool timThay = false;
    for (int i = 0; i < soLuongSinhVien; i++) {
        if (*(sinhVien + i) == tenTimKiem) {
            cout << "Sinh viên \"" << tenTimKiem << "\" có trong danh sách tại vị trí số " << i + 1 << endl;
            timThay = true;
            break;
        }
    }
    if (!timThay) {
        cout << "Không tìm thấy sinh viên \"" << tenTimKiem << "\" trong danh sách." << endl;
    }
}

// Hàm chỉnh sửa tên sinh viên
void chinhSuaTenSinhVien(string *sinhVien, int soLuongSinhVien, int viTri) {
    if (viTri < 1 || viTri > soLuongSinhVien) {
        cout << "Vị trí không hợp lệ!" << endl;
        return;
    }
    cin.ignore(); // Bỏ qua ký tự '\n' còn sót lại từ lần nhập trước
    cout << "Nhập tên sinh viên mới: ";
    getline(cin, *(sinhVien + (viTri - 1)));
}

int main() {
    int soLuongSinhVien;

    // Nhập số lượng sinh viên
    cout << "Nhập số lượng sinh viên: ";
    cin >> soLuongSinhVien;

    // Khởi tạo mảng động để lưu tên sinh viên
    string *danhSachSinhVien = new string[soLuongSinhVien];

    // Nhập danh sách các sinh viên
    nhapDanhSachSinhVien(danhSachSinhVien, soLuongSinhVien);

    // Hiển thị danh sách sinh viên
    hienThiDanhSachSinhVien(danhSachSinhVien, soLuongSinhVien);

    // Tìm kiếm sinh viên theo tên
    string tenTimKiem;
    cout << "\nNhập tên sinh viên cần tìm kiếm: ";
    cin.ignore(); // Bỏ qua ký tự '\n' còn sót lại từ lần nhập trước
    getline(cin, tenTimKiem);
    timKiemSinhVien(danhSachSinhVien, soLuongSinhVien, tenTimKiem);

    // Chỉnh sửa tên sinh viên
    int viTri;
    cout << "\nNhập vị trí sinh viên cần chỉnh sửa (1 - " << soLuongSinhVien << "): ";
    cin >> viTri;
    chinhSuaTenSinhVien(danhSachSinhVien, soLuongSinhVien, viTri);

    // Hiển thị danh sách sinh viên sau khi chỉnh sửa
    hienThiDanhSachSinhVien(danhSachSinhVien, soLuongSinhVien);

    // Giải phóng bộ nhớ của mảng động
    delete[] danhSachSinhVien;

    return 0;
}
