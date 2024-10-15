#include <iostream>
using namespace std;

// Hàm nhập điểm cho học sinh
void nhapDiem(double *diem, int soHocSinh) {
    for (int i = 0; i < soHocSinh; i++) {
        cout << "Nhập điểm cho học sinh thứ " << i + 1 << ": ";
        cin >> *(diem + i);
    }
}

// Hàm tính tổng điểm
double tinhTongDiem(double *diem, int soHocSinh) {
    double tongDiem = 0;
    for (int i = 0; i < soHocSinh; i++) {
        tongDiem += *(diem + i);
    }
    return tongDiem;
}

// Hàm tính điểm trung bình
double tinhDiemTrungBinh(double *diem, int soHocSinh) {
    double tongDiem = tinhTongDiem(diem, soHocSinh);
    return tongDiem / soHocSinh;
}

// Hàm tìm điểm cao nhất
double timDiemCaoNhat(double *diem, int soHocSinh) {
    double diemCaoNhat = *diem;
    for (int i = 1; i < soHocSinh; i++) {
        if (*(diem + i) > diemCaoNhat) {
            diemCaoNhat = *(diem + i);
        }
    }
    return diemCaoNhat;
}

// Hàm tìm điểm thấp nhất
double timDiemThapNhat(double *diem, int soHocSinh) {
    double diemThapNhat = *diem;
    for (int i = 1; i < soHocSinh; i++) {
        if (*(diem + i) < diemThapNhat) {
            diemThapNhat = *(diem + i);
        }
    }
    return diemThapNhat;
}

int main() {
    int soHocSinh;

    // Nhập số lượng học sinh
    cout << "Nhập số lượng học sinh: ";
    cin >> soHocSinh;

    // Khởi tạo mảng động để lưu điểm
    double *diem = new double[soHocSinh];

    // Nhập điểm cho học sinh
    nhapDiem(diem, soHocSinh);

    // Tính tổng điểm và điểm trung bình
    double tongDiem = tinhTongDiem(diem, soHocSinh);
    double diemTrungBinh = tinhDiemTrungBinh(diem, soHocSinh);

    // Tìm điểm cao nhất và điểm thấp nhất
    double diemCaoNhat = timDiemCaoNhat(diem, soHocSinh);
    double diemThapNhat = timDiemThapNhat(diem, soHocSinh);

    // Hiển thị kết quả
    cout << "\nTổng điểm của tất cả học sinh: " << tongDiem << endl;
    cout << "Điểm trung bình của tất cả học sinh: " << diemTrungBinh << endl;
    cout << "Điểm cao nhất: " << diemCaoNhat << endl;
    cout << "Điểm thấp nhất: " << diemThapNhat << endl;

    // Giải phóng bộ nhớ cho mảng động
    delete[] diem;

    return 0;
}
