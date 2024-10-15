#include <iostream>
using namespace std;

const int SO_HOC_SINH = 5;

// Hàm hiển thị điểm của tất cả học sinh
void hienThiDiem(double *diem) {
    for (int i = 0; i < SO_HOC_SINH; i++) {
        cout << "Điểm của học sinh thứ " << i + 1 << ": " << *(diem + i) << endl;
    }
}

// Hàm thay đổi điểm của một học sinh thông qua con trỏ
void thayDoiDiem(double *diem, int viTri, double diemMoi) {
    if (viTri >= 0 && viTri < SO_HOC_SINH) {
        *(diem + viTri) = diemMoi;
    } else {
        cout << "Vị trí không hợp lệ!" << endl;
    }
}

int main() {
    double diem[SO_HOC_SINH]; 
    double *ptrDiem = diem;   

    // Nhập điểm cho học sinh
    for (int i = 0; i < SO_HOC_SINH; i++) {
        cout << "Nhập điểm cho học sinh thứ " << i + 1 << ": ";
        cin >> *(ptrDiem + i);
    }

    // Hiển thị điểm của tất cả học sinh
    cout << "\nĐiểm của các học sinh:" << endl;
    hienThiDiem(ptrDiem);

    // Thay đổi điểm của một học sinh
    int viTriThayDoi;
    double diemMoi;
    cout << "\nNhập vị trí học sinh cần thay đổi điểm (1 - 5): ";
    cin >> viTriThayDoi;
    cout << "Nhập điểm mới: ";
    cin >> diemMoi;

    // Gọi hàm thay đổi điểm
    thayDoiDiem(ptrDiem, viTriThayDoi - 1, diemMoi);

    // Hiển thị lại điểm sau khi thay đổi
    cout << "\nĐiểm của các học sinh sau khi thay đổi:" << endl;
    hienThiDiem(ptrDiem);

    return 0;
}
