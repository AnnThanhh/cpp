#include <iostream>
#include <string>
using namespace std;

// Interface IBooking định nghĩa các phương thức checkIn() và checkOut()
class IBooking {
public:
    virtual void checkIn() = 0;  // Phương thức thuần ảo để check-in
    virtual void checkOut() = 0; // Phương thức thuần ảo để check-out
};

// Lớp cha Room
class Room {
protected:
    int roomNumber;
    bool isOccupied;

public:
    // Constructor cho Room
    Room(int number) : roomNumber(number), isOccupied(false) {}

    // Phương thức hiển thị thông tin phòng
    virtual void displayInfo() const {
        cout << "Room Number: " << roomNumber << endl;
        cout << "Occupied: " << (isOccupied ? "Yes" : "No") << endl;
    }

    // Phương thức để đặt phòng
    virtual void bookRoom() {
        if (!isOccupied) {
            isOccupied = true;
            cout << "Room " << roomNumber << " has been booked." << endl;
        } else {
            cout << "Room " << roomNumber << " is already occupied." << endl;
        }
    }

    // Phương thức để trả phòng
    virtual void freeRoom() {
        if (isOccupied) {
            isOccupied = false;
            cout << "Room " << roomNumber << " has been checked out." << endl;
        } else {
            cout << "Room " << roomNumber << " is already free." << endl;
        }
    }

    virtual ~Room() {}
};

// Lớp con SingleRoom kế thừa từ Room và triển khai IBooking
class SingleRoom : public Room, public IBooking {
public:
    // Constructor cho SingleRoom
    SingleRoom(int number) : Room(number) {}

    // Ghi đè phương thức checkIn()
    void checkIn() override {
        bookRoom();  // Sử dụng phương thức bookRoom từ Room
    }

    // Ghi đè phương thức checkOut()
    void checkOut() override {
        freeRoom();  // Sử dụng phương thức freeRoom từ Room
    }

    // Ghi đè phương thức hiển thị thông tin phòng
    void displayInfo() const override {
        cout << "Single Room" << endl;
        Room::displayInfo();  // Gọi phương thức hiển thị từ lớp cha
    }
};

// Lớp con DoubleRoom kế thừa từ Room và triển khai IBooking
class DoubleRoom : public Room, public IBooking {
public:
    // Constructor cho DoubleRoom
    DoubleRoom(int number) : Room(number) {}

    // Ghi đè phương thức checkIn()
    void checkIn() override {
        bookRoom();  // Sử dụng phương thức bookRoom từ Room
    }

    // Ghi đè phương thức checkOut()
    void checkOut() override {
        freeRoom();  // Sử dụng phương thức freeRoom từ Room
    }

    // Ghi đè phương thức hiển thị thông tin phòng
    void displayInfo() const override {
        cout << "Double Room" << endl;
        Room::displayInfo();  // Gọi phương thức hiển thị từ lớp cha
    }
};

// Lớp con LuxuryRoom kế thừa từ DoubleRoom và triển khai thêm phương thức provideService
class LuxuryRoom : public DoubleRoom {
public:
    // Constructor cho LuxuryRoom
    LuxuryRoom(int number) : DoubleRoom(number) {}

    // Phương thức cung cấp dịch vụ đặc biệt cho phòng hạng sang
    void provideService() const {
        cout << "Providing luxury services to Room " << roomNumber << endl;
    }

    // Ghi đè phương thức hiển thị thông tin phòng
    void displayInfo() const override {
        cout << "Luxury Room" << endl;
        Room::displayInfo();  // Gọi phương thức hiển thị từ lớp cha
    }
};

// Chương trình chính
int main() {
    // Tạo đối tượng SingleRoom
    IBooking* singleRoom = new SingleRoom(101);
    singleRoom->checkIn();
    singleRoom->checkOut();
    cout << "----------------------" << endl;

    // Tạo đối tượng DoubleRoom
    IBooking* doubleRoom = new DoubleRoom(202);
    doubleRoom->checkIn();
    doubleRoom->checkOut();
    cout << "----------------------" << endl;

    // Tạo đối tượng LuxuryRoom
    LuxuryRoom* luxuryRoom = new LuxuryRoom(303);
    luxuryRoom->checkIn();
    luxuryRoom->provideService();
    luxuryRoom->checkOut();

    // Giải phóng bộ nhớ
    delete singleRoom;
    delete doubleRoom;
    delete luxuryRoom;

    return 0;
}
