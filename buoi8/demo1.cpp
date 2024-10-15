#include <iostream>
#include <cstring>
using namespace std;

// Hàm nhập danh sách các tiêu đề sách
void nhapDanhSachSach(string *sach, int soLuongSach) {
    cin.ignore(); // Bỏ qua ký tự '\n' còn sót lại từ lần nhập trước
    for (int i = 0; i < soLuongSach; i++) {
        cout << "Nhập tiêu đề sách thứ " << i + 1 << ": ";
        getline(cin, *(sach + i));
    }
}

// Hàm hiển thị danh sách các sách
void hienThiDanhSachSach(string *sach, int soLuongSach) {
    cout << "\nDanh sách các sách trong thư viện:\n";
    for (int i = 0; i < soLuongSach; i++) {
        cout << i + 1 << ". " << *(sach + i) << endl;
    }
}

// Hàm tìm kiếm sách theo tiêu đề
void timKiemSach(string *sach, int soLuongSach, string tenTimKiem) {
    bool timThay = false;
    for (int i = 0; i < soLuongSach; i++) {
        if (*(sach + i) == tenTimKiem) {
            cout << "Sách \"" << tenTimKiem << "\" có trong thư viện tại vị trí số " << i + 1 << endl;
            timThay = true;
            break;
        }
    }
    if (!timThay) {
        cout << "Không tìm thấy sách \"" << tenTimKiem << "\" trong thư viện." << endl;
    }
}

// Hàm chỉnh sửa tên sách
void chinhSuaTenSach(string *sach, int soLuongSach, int viTri) {
    if (viTri < 1 || viTri > soLuongSach) {
        cout << "Vị trí không hợp lệ!" << endl;
        return;
    }
    cin.ignore(); // Bỏ qua ký tự '\n' còn sót lại từ lần nhập trước
    cout << "Nhập tên sách mới: ";
    getline(cin, *(sach + (viTri - 1)));
}

int main() {
    int soLuongSach;

    // Nhập số lượng sách
    cout << "Nhập số lượng sách trong thư viện: ";
    cin >> soLuongSach;

    // Khởi tạo mảng động để lưu tiêu đề sách
    string *danhSachSach = new string[soLuongSach];

    // Nhập danh sách các tiêu đề sách
    nhapDanhSachSach(danhSachSach, soLuongSach);

    // Hiển thị danh sách sách
    hienThiDanhSachSach(danhSachSach, soLuongSach);

    // Tìm kiếm sách theo tiêu đề
    string tenTimKiem;
    cout << "\nNhập tiêu đề sách cần tìm kiếm: ";
    cin.ignore(); // Bỏ qua ký tự '\n' còn sót lại từ lần nhập trước
    getline(cin, tenTimKiem);
    timKiemSach(danhSachSach, soLuongSach, tenTimKiem);

    // Chỉnh sửa tên sách
    int viTri;
    cout << "\nNhập vị trí sách cần chỉnh sửa (1 - " << soLuongSach << "): ";
    cin >> viTri;
    chinhSuaTenSach(danhSachSach, soLuongSach, viTri);

    // Hiển thị danh sách sách sau khi chỉnh sửa
    hienThiDanhSachSach(danhSachSach, soLuongSach);

    // Giải phóng bộ nhớ của mảng động
    delete[] danhSachSach;

    return 0;
}
