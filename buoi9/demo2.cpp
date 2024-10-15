#include <iostream>
#include <algorithm> // Sử dụng để sắp xếp mảng
using namespace std;

// Hàm nhập danh sách khách hàng
void nhapDanhSachKhachHang(string *khachHang, int soLuongKhachHang) {
    cin.ignore(); // Bỏ qua ký tự '\n' còn sót lại từ lần nhập trước
    for (int i = 0; i < soLuongKhachHang; i++) {
        cout << "Nhập tên khách hàng thứ " << i + 1 << ": ";
        getline(cin, *(khachHang + i));
    }
}

// Hàm hiển thị danh sách khách hàng
void hienThiDanhSachKhachHang(string *khachHang, int soLuongKhachHang) {
    cout << "\nDanh sách khách hàng:\n";
    for (int i = 0; i < soLuongKhachHang; i++) {
        cout << i + 1 << ". " << *(khachHang + i) << endl;
    }
}

// Hàm tìm kiếm nhị phân để tìm khách hàng
int timKiemNhiPhan(string *khachHang, int soLuongKhachHang, string tenTimKiem) {
    int left = 0, right = soLuongKhachHang - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;

        // So sánh tên khách hàng ở giữa với tên cần tìm
        if (*(khachHang + mid) == tenTimKiem) {
            return mid; // Trả về vị trí nếu tìm thấy
        }

        // Nếu tên khách hàng ở giữa nhỏ hơn tên cần tìm, bỏ nửa trái
        if (*(khachHang + mid) < tenTimKiem) {
            left = mid + 1;
        }
        // Nếu tên khách hàng ở giữa lớn hơn tên cần tìm, bỏ nửa phải
        else {
            right = mid - 1;
        }
    }
    return -1; // Trả về -1 nếu không tìm thấy
}

int main() {
    int soLuongKhachHang;

    // Nhập số lượng khách hàng
    cout << "Nhập số lượng khách hàng: ";
    cin >> soLuongKhachHang;

    // Khởi tạo mảng động để lưu tên khách hàng
    string *danhSachKhachHang = new string[soLuongKhachHang];

    // Nhập danh sách các khách hàng
    nhapDanhSachKhachHang(danhSachKhachHang, soLuongKhachHang);

    // Sắp xếp danh sách khách hàng trước khi thực hiện tìm kiếm nhị phân
    sort(danhSachKhachHang, danhSachKhachHang + soLuongKhachHang);

    // Hiển thị danh sách khách hàng sau khi sắp xếp
    cout << "\nDanh sách khách hàng sau khi sắp xếp:\n";
    hienThiDanhSachKhachHang(danhSachKhachHang, soLuongKhachHang);

    // Tìm kiếm khách hàng theo tên
    string tenTimKiem;
    cout << "\nNhập tên khách hàng cần tìm kiếm: ";
    cin.ignore(); // Bỏ qua ký tự '\n' còn sót lại từ lần nhập trước
    getline(cin, tenTimKiem);

    // Gọi hàm tìm kiếm nhị phân
    int ketQua = timKiemNhiPhan(danhSachKhachHang, soLuongKhachHang, tenTimKiem);

    // Kiểm tra kết quả tìm kiếm
    if (ketQua != -1) {
        cout << "Khách hàng \"" << tenTimKiem << "\" có trong danh sách tại vị trí số " << ketQua + 1 << endl;
    } else {
        cout << "Không tìm thấy khách hàng \"" << tenTimKiem << "\" trong danh sách." << endl;
    }

    // Giải phóng bộ nhớ của mảng động
    delete[] danhSachKhachHang;

    return 0;
}
