#include <iostream>
#include <string>
using namespace std;

// Cấu trúc lưu trữ thông tin nhân viên
struct Employee {
    string maNhanVien;
    string hoTen;
    int tuoi;
    double luong;
    string viTri;
};

// Node cho danh sách liên kết đơn
struct Node {
    Employee data;
    Node *next;
};

// Node cho danh sách liên kết đôi
struct DoublyNode {
    Employee data;
    DoublyNode *prev;
    DoublyNode *next;
};

// Hàm thêm nhân viên vào danh sách liên kết đơn (thêm vào cuối)
void themNhanVien(Node *&head, Employee nv) {
    Node *newNode = new Node();
    newNode->data = nv;
    newNode->next = nullptr;

    if (head == nullptr) {
        head = newNode;
    } else {
        Node *temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// Hàm hiển thị danh sách nhân viên
void hienThiDanhSachNhanVien(Node *head) {
    Node *temp = head;
    cout << "\nDanh sách nhân viên hiện tại:\n";
    while (temp != nullptr) {
        cout << "Mã NV: " << temp->data.maNhanVien
             << ", Họ tên: " << temp->data.hoTen
             << ", Tuổi: " << temp->data.tuoi
             << ", Lương: " << temp->data.luong
             << ", Vị trí: " << temp->data.viTri << "\n";
        temp = temp->next;
    }
}

// Hàm tìm kiếm nhân viên theo mã
Node* timKiemNhanVienTheoMa(Node *head, string maNV) {
    Node *temp = head;
    while (temp != nullptr) {
        if (temp->data.maNhanVien == maNV) {
            return temp;
        }
        temp = temp->next;
    }
    return nullptr;
}

// Hàm xóa nhân viên khỏi danh sách liên kết đơn
void xoaNhanVien(Node *&head, string maNV, DoublyNode *&daNghiHead) {
    Node *temp = head;
    Node *prev = nullptr;

    // Tìm nhân viên cần xóa
    while (temp != nullptr && temp->data.maNhanVien != maNV) {
        prev = temp;
        temp = temp->next;
    }

    // Nếu không tìm thấy nhân viên
    if (temp == nullptr) {
        cout << "Không tìm thấy nhân viên có mã: " << maNV << endl;
        return;
    }

    // Nếu tìm thấy, chuyển nhân viên vào danh sách nghỉ việc
    DoublyNode *newDoublyNode = new DoublyNode();
    newDoublyNode->data = temp->data;
    newDoublyNode->next = daNghiHead;
    newDoublyNode->prev = nullptr;
    if (daNghiHead != nullptr) {
        daNghiHead->prev = newDoublyNode;
    }
    daNghiHead = newDoublyNode;

    // Xóa nhân viên khỏi danh sách hiện tại
    if (prev == nullptr) { // Nhân viên cần xóa là node đầu
        head = temp->next;
    } else {
        prev->next = temp->next;
    }

    delete temp;
    cout << "Đã xóa nhân viên và chuyển vào danh sách nghỉ việc.\n";
}

// Hàm hiển thị danh sách nhân viên đã nghỉ việc (từ gần nhất đến xa nhất)
void hienThiNhanVienDaNghi(DoublyNode *head) {
    DoublyNode *temp = head;
    cout << "\nDanh sách nhân viên đã nghỉ việc (gần nhất đến xa nhất):\n";
    while (temp != nullptr) {
        cout << "Mã NV: " << temp->data.maNhanVien
             << ", Họ tên: " << temp->data.hoTen
             << ", Tuổi: " << temp->data.tuoi
             << ", Lương: " << temp->data.luong
             << ", Vị trí: " << temp->data.viTri << "\n";
        temp = temp->next;
    }
}

// Hàm hiển thị danh sách nhân viên đã nghỉ việc (từ xa nhất đến gần nhất)
void hienThiNhanVienDaNghiNguoc(DoublyNode *tail) {
    DoublyNode *temp = tail;
    cout << "\nDanh sách nhân viên đã nghỉ việc (xa nhất đến gần nhất):\n";
    while (temp != nullptr) {
        cout << "Mã NV: " << temp->data.maNhanVien
             << ", Họ tên: " << temp->data.hoTen
             << ", Tuổi: " << temp->data.tuoi
             << ", Lương: " << temp->data.luong
             << ", Vị trí: " << temp->data.viTri << "\n";
        temp = temp->prev;
    }
}

// Hàm tìm node cuối cùng của danh sách liên kết đôi
DoublyNode* timNodeCuoi(DoublyNode *head) {
    DoublyNode *temp = head;
    while (temp != nullptr && temp->next != nullptr) {
        temp = temp->next;
    }
    return temp;
}

int main() {
    Node *danhSachNhanVien = nullptr;   // Danh sách liên kết đơn
    DoublyNode *danhSachDaNghi = nullptr; // Danh sách liên kết đôi

    // Thêm một vài nhân viên mẫu
    Employee nv1 = {"NV001", "Nguyen Van A", 30, 1500.0, "Developer"};
    Employee nv2 = {"NV002", "Tran Thi B", 25, 1200.0, "Tester"};
    Employee nv3 = {"NV003", "Le Quoc C", 28, 1800.0, "Manager"};

    themNhanVien(danhSachNhanVien, nv1);
    themNhanVien(danhSachNhanVien, nv2);
    themNhanVien(danhSachNhanVien, nv3);

    // Hiển thị danh sách nhân viên
    hienThiDanhSachNhanVien(danhSachNhanVien);

    // Tìm kiếm nhân viên theo mã
    string maTimKiem;
    cout << "\nNhập mã nhân viên cần tìm: ";
    cin >> maTimKiem;
    Node *timThay = timKiemNhanVienTheoMa(danhSachNhanVien, maTimKiem);
    if (timThay != nullptr) {
        cout << "Tìm thấy nhân viên: " << timThay->data.hoTen << ", Lương: " << timThay->data.luong << "\n";
    } else {
        cout << "Không tìm thấy nhân viên.\n";
    }

    // Xóa một nhân viên và chuyển vào danh sách đã nghỉ việc
    cout << "\nNhập mã nhân viên cần xóa: ";
    string maXoa;
    cin >> maXoa;
    xoaNhanVien(danhSachNhanVien, maXoa, danhSachDaNghi);

    // Hiển thị lại danh sách nhân viên hiện tại
    hienThiDanhSachNhanVien(danhSachNhanVien);

    // Hiển thị danh sách nhân viên đã nghỉ việc
    hienThiNhanVienDaNghi(danhSachDaNghi);

    // Hiển thị danh sách nhân viên đã nghỉ việc từ xa nhất đến gần nhất
    DoublyNode *tail = timNodeCuoi(danhSachDaNghi);
    hienThiNhanVienDaNghiNguoc(tail);

    return 0;
}
