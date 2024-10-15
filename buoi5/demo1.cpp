#include <iostream>
using namespace std;

const int SO_HOC_SINH = 5;

// Hàm nhập điểm cho học sinh
void nhapDiem(double diem[SO_HOC_SINH]) {
    for (int i = 0; i < SO_HOC_SINH; i++) {
        cout << "Nhập điểm cho học sinh thứ " << i + 1 << ": ";
        cin >> diem[i];
    }
}

// Hàm tính tổng điểm
double tinhTongDiem(double diem[SO_HOC_SINH]) {
    double tongDiem = 0;
    for (int i = 0; i < SO_HOC_SINH; i++) {
        tongDiem += diem[i];
    }
    return tongDiem;
}

// Hàm tính điểm trung bình
double tinhDiemTrungBinh(double diem[SO_HOC_SINH]) {
    double tongDiem = tinhTongDiem(diem);
    return tongDiem / SO_HOC_SINH;
}

// Hàm tìm học sinh có điểm cao nhất
int timHocSinhCaoNhat(double diem[SO_HOC_SINH]) {
    int viTriCaoNhat = 0;
    for (int i = 1; i < SO_HOC_SINH; i++) {
        if (diem[i] > diem[viTriCaoNhat]) {
            viTriCaoNhat = i;
        }
    }
    return viTriCaoNhat;
}

int main() {
    double diem[SO_HOC_SINH];

    // Nhập điểm cho học sinh
    nhapDiem(diem);

    // Tính tổng và điểm trung bình
    double tongDiem = tinhTongDiem(diem);
    double diemTrungBinh = tinhDiemTrungBinh(diem);

    // Tìm học sinh có điểm cao nhất
    int hocSinhCaoNhat = timHocSinhCaoNhat(diem);

    // Hiển thị kết quả
    cout << "Tổng điểm của tất cả học sinh: " << tongDiem << endl;
    cout << "Điểm trung bình của tất cả học sinh: " << diemTrungBinh << endl;
    cout << "Học sinh có điểm cao nhất là " << hocSinhCaoNhat + 1 << " voi diem so: " << diem[hocSinhCaoNhat] << endl;

    return 0;
}
