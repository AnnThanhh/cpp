#include <iostream>
#include <string>
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

// Hàm sắp xếp chọn lựa (Selection Sort)
void sapXepChonLua(string *sinhVien, int soLuongSinhVien) {
    for (int i = 0; i < soLuongSinhVien - 1; i++) {
        // Giả sử phần tử nhỏ nhất nằm ở vị trí i
        int viTriNhoNhat = i;

        // Tìm phần tử nhỏ nhất trong các phần tử còn lại của mảng
        for (int j = i + 1; j < soLuongSinhVien; j++) {
            if (*(sinhVien + j) < *(sinhVien + viTriNhoNhat)) {
                viTriNhoNhat = j;
            }
        }

        // Hoán đổi phần tử nhỏ nhất với phần tử ở vị trí i
        if (viTriNhoNhat != i) {
            string temp = *(sinhVien + i);
            *(sinhVien + i) = *(sinhVien + viTriNhoNhat);
            *(sinhVien + viTriNhoNhat) = temp;
        }
    }
}

int main() {
    int soLuongSinhVien;

    // Nhập số lượng sinh viên
    cout << "Nhập số lượng sinh viên: ";
    cin >> soLuongSinhVien;

    // Khởi tạo mảng động để lưu tên sinh viên
    string *danhSachSinhVien = new string[soLuongSinhVien];

    // Nhập danh sách sinh viên
    nhapDanhSachSinhVien(danhSachSinhVien, soLuongSinhVien);

    // Hiển thị danh sách sinh viên trước khi sắp xếp
    cout << "\nDanh sách sinh viên trước khi sắp xếp:\n";
    hienThiDanhSachSinhVien(danhSachSinhVien, soLuongSinhVien);

    // Sắp xếp danh sách sinh viên theo thứ tự bảng chữ cái bằng thuật toán chọn lựa
    sapXepChonLua(danhSachSinhVien, soLuongSinhVien);

    // Hiển thị danh sách sinh viên sau khi sắp xếp
    cout << "\nDanh sách sinh viên sau khi sắp xếp theo thứ tự bảng chữ cái:\n";
    hienThiDanhSachSinhVien(danhSachSinhVien, soLuongSinhVien);

    // Giải phóng bộ nhớ của mảng động
    delete[] danhSachSinhVien;

    return 0;
}
