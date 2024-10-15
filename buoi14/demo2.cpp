#include <iostream>
using namespace std;

// Lớp trừu tượng Shape
class Shape {
public:
    // Phương thức thuần ảo (trừu tượng)
    virtual void draw() const = 0; // Các lớp con phải triển khai phương thức này
};

// Lớp Circle kế thừa từ Shape
class Circle : public Shape {
public:
    // Ghi đè phương thức draw() để vẽ hình tròn
    void draw() const override {
        cout << "Drawing a Circle" << endl;
    }
};

// Lớp Rectangle kế thừa từ Shape
class Rectangle : public Shape {
public:
    // Ghi đè phương thức draw() để vẽ hình chữ nhật
    void draw() const override {
        cout << "Drawing a Rectangle" << endl;
    }
};

// Lớp Triangle kế thừa từ Shape
class Triangle : public Shape {
public:
    // Ghi đè phương thức draw() để vẽ hình tam giác
    void draw() const override {
        cout << "Drawing a Triangle" << endl;
    }
};

// Chương trình chính
int main() {
    // Sử dụng tính đa hình để vẽ các hình khác nhau
    Shape* shape1 = new Circle();
    Shape* shape2 = new Rectangle();
    Shape* shape3 = new Triangle();

    shape1->draw();  // Gọi phương thức draw của Circle
    shape2->draw();  // Gọi phương thức draw của Rectangle
    shape3->draw();  // Gọi phương thức draw của Triangle

    // Giải phóng bộ nhớ
    delete shape1;
    delete shape2;
    delete shape3;

    return 0;
}
