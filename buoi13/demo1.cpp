#include <iostream>
#include <string>
using namespace std;

// Lớp cha Vehicle
class Vehicle {
protected:
    string brand;
    string model;

public:
    // Constructor cho Vehicle
    Vehicle(string vehicleBrand, string vehicleModel) {
        brand = vehicleBrand;
        model = vehicleModel;
    }

    // Phương thức hiển thị thông tin phương tiện
    virtual void displayInfo() const {
        cout << "Brand: " << brand << endl;
        cout << "Model: " << model << endl;
    }
};

// Lớp con Car kế thừa từ Vehicle
class Car : public Vehicle {
private:
    int numDoors;

public:
    // Constructor cho Car
    Car(string carBrand, string carModel, int doors)
        : Vehicle(carBrand, carModel) {
        numDoors = doors;
    }

    // Ghi đè phương thức displayInfo()
    void displayInfo() const override {
        cout << "Vehicle Type: Car" << endl;
        Vehicle::displayInfo();  // Gọi phương thức displayInfo() của lớp cha
        cout << "Number of doors: " << numDoors << endl;
    }
};

// Lớp con Bike kế thừa từ Vehicle
class Bike : public Vehicle {
public:
    // Constructor cho Bike
    Bike(string bikeBrand, string bikeModel)
        : Vehicle(bikeBrand, bikeModel) {}

    // Ghi đè phương thức displayInfo()
    void displayInfo() const override {
        cout << "Vehicle Type: Bike" << endl;
        Vehicle::displayInfo();  // Gọi phương thức displayInfo() của lớp cha
    }
};

// Lớp con Truck kế thừa từ Vehicle
class Truck : public Vehicle {
private:
    double payloadCapacity;  // Sức chứa tải trọng

public:
    // Constructor cho Truck
    Truck(string truckBrand, string truckModel, double capacity)
        : Vehicle(truckBrand, truckModel) {
        payloadCapacity = capacity;
    }

    // Ghi đè phương thức displayInfo()
    void displayInfo() const override {
        cout << "Vehicle Type: Truck" << endl;
        Vehicle::displayInfo();  // Gọi phương thức displayInfo() của lớp cha
        cout << "Payload Capacity: " << payloadCapacity << " tons" << endl;
    }
};

// Chương trình chính
int main() {
    // Tạo đối tượng Car
    Car myCar("Toyota", "Corolla", 4);
    myCar.displayInfo();
    cout << "----------------------" << endl;

    // Tạo đối tượng Bike
    Bike myBike("Yamaha", "MT-07");
    myBike.displayInfo();
    cout << "----------------------" << endl;

    // Tạo đối tượng Truck
    Truck myTruck("Ford", "F-150", 3.5);
    myTruck.displayInfo();

    return 0;
}
