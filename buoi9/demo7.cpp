#include <iostream>
#include <string>
using namespace std;

// Cấu trúc đơn hàng
struct DonHang {
    string maDonHang;
    string tenKhachHang;
    float giaTriDonHang;
    string thoiGianDatHang;
};

// Hàm nhập danh sách đơn hàng
void nhapDanhSachDonHang(DonHang *danhSach, int soLuongDonHang) {
    for (int i = 0; i < soLuongDonHang; i++) {
        cout << "\nNhập thông tin đơn hàng thứ " << i + 1 << ":\n";
        cout << "Mã đơn hàng: ";
        cin >> danhSach[i].maDonHang;
        cin.ignore();
        cout << "Tên khách hàng: ";
        getline(cin, danhSach[i].tenKhachHang);
        cout << "Giá trị đơn hàng: ";
        cin >> danhSach[i].giaTriDonHang;
        cin.ignore();
        cout << "Thời gian đặt hàng (dd/mm/yyyy): ";
        getline(cin, danhSach[i].thoiGianDatHang);
    }
}

// Hàm hiển thị danh sách đơn hàng
void hienThiDanhSachDonHang(DonHang *danhSach, int soLuongDonHang) {
    cout << "\nDanh sách đơn hàng:\n";
    for (int i = 0; i < soLuongDonHang; i++) {
        cout << "Mã đơn hàng: " << danhSach[i].maDonHang << "\n";
        cout << "Tên khách hàng: " << danhSach[i].tenKhachHang << "\n";
        cout << "Giá trị đơn hàng: " << danhSach[i].giaTriDonHang << " VND\n";
        cout << "Thời gian đặt hàng: " << danhSach[i].thoiGianDatHang << "\n\n";
    }
}

// Hàm tìm kiếm tuyến tính theo mã đơn hàng
void timKiemTuyenTinh(DonHang *danhSach, int soLuongDonHang, string maDonHang) {
    bool timThay = false;
    for (int i = 0; i < soLuongDonHang; i++) {
        if (danhSach[i].maDonHang == maDonHang) {
            cout << "\nĐơn hàng tìm thấy:\n";
            cout << "Mã đơn hàng: " << danhSach[i].maDonHang << "\n";
            cout << "Tên khách hàng: " << danhSach[i].tenKhachHang << "\n";
            cout << "Giá trị đơn hàng: " << danhSach[i].giaTriDonHang << " VND\n";
            cout << "Thời gian đặt hàng: " << danhSach[i].thoiGianDatHang << "\n\n";
            timThay = true;
            break;
        }
    }
    if (!timThay) {
        cout << "Không tìm thấy đơn hàng có mã " << maDonHang << ".\n";
    }
}

// Hàm sắp xếp nổi bọt theo giá trị đơn hàng
void sapXepNoiBotTheoGiaTri(DonHang *danhSach, int soLuongDonHang) {
    for (int i = 0; i < soLuongDonHang - 1; i++) {
        for (int j = 0; j < soLuongDonHang - i - 1; j++) {
            if (danhSach[j].giaTriDonHang > danhSach[j + 1].giaTriDonHang) {
                // Hoán đổi hai đơn hàng
                DonHang temp = danhSach[j];
                danhSach[j] = danhSach[j + 1];
                danhSach[j + 1] = temp;
            }
        }
    }
}

// Hàm sắp xếp chọn lựa theo thời gian đặt hàng (giả sử ngày tháng dưới dạng chuỗi)
void sapXepChonLuaTheoThoiGian(DonHang *danhSach, int soLuongDonHang) {
    for (int i = 0; i < soLuongDonHang - 1; i++) {
        int viTriNhoNhat = i;
        for (int j = i + 1; j < soLuongDonHang; j++) {
            if (danhSach[j].thoiGianDatHang < danhSach[viTriNhoNhat].thoiGianDatHang) {
                viTriNhoNhat = j;
            }
        }
        // Hoán đổi hai đơn hàng
        if (viTriNhoNhat != i) {
            DonHang temp = danhSach[i];
            danhSach[i] = danhSach[viTriNhoNhat];
            danhSach[viTriNhoNhat] = temp;
        }
    }
}

// Hàm hoán đổi
void hoanDoi(DonHang &a, DonHang &b) {
    DonHang temp = a;
    a = b;
    b = temp;
}

// Hàm phân hoạch cho quicksort
int phanHoach(DonHang *danhSach, int low, int high) {
    float pivot = danhSach[high].giaTriDonHang;
    int i = low - 1;
    for (int j = low; j <= high - 1; j++) {
        if (danhSach[j].giaTriDonHang < pivot) {
            i++;
            hoanDoi(danhSach[i], danhSach[j]);
        }
    }
    hoanDoi(danhSach[i + 1], danhSach[high]);
    return (i + 1);
}

// Hàm quicksort theo giá trị đơn hàng
void quickSort(DonHang *danhSach, int low, int high) {
    if (low < high) {
        int pi = phanHoach(danhSach, low, high);
        quickSort(danhSach, low, pi - 1);
        quickSort(danhSach, pi + 1, high);
    }
}

int main() {
    int soLuongDonHang;

    // Nhập số lượng đơn hàng
    cout << "Nhập số lượng đơn hàng: ";
    cin >> soLuongDonHang;

    // Khởi tạo mảng động để lưu trữ đơn hàng
    DonHang *danhSachDonHang = new DonHang[soLuongDonHang];

    // Nhập danh sách đơn hàng
    nhapDanhSachDonHang(danhSachDonHang, soLuongDonHang);

    // Hiển thị danh sách đơn hàng
    hienThiDanhSachDonHang(danhSachDonHang, soLuongDonHang);

    // Tìm kiếm đơn hàng theo mã
    string maTimKiem;
    cout << "\nNhập mã đơn hàng cần tìm kiếm: ";
    cin >> maTimKiem;
    timKiemTuyenTinh(danhSachDonHang, soLuongDonHang, maTimKiem);

    // Sắp xếp đơn hàng theo giá trị bằng Bubble Sort
    sapXepNoiBotTheoGiaTri(danhSachDonHang, soLuongDonHang);
    cout << "\nDanh sách đơn hàng sau khi sắp xếp theo giá trị tăng dần:\n";
    hienThiDanhSachDonHang(danhSachDonHang, soLuongDonHang);

    // Sắp xếp đơn hàng theo thời gian bằng Selection Sort
    sapXepChonLuaTheoThoiGian(danhSachDonHang, soLuongDonHang);
    cout << "\nDanh sách đơn hàng sau khi sắp xếp theo thời gian đặt hàng:\n";
    hienThiDanhSachDonHang(danhSachDonHang, soLuongDonHang);

    // Giải phóng bộ nhớ của mảng động
    delete[] danhSachDonHang;

    return 0;
}
