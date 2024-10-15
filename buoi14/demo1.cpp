#include <iostream>
#include <string>
using namespace std;

// Lớp trừu tượng Pet
class Pet {
public:
    // Phương thức thuần ảo (trừu tượng)
    virtual void speak() const = 0; // Phương thức trừu tượng, các lớp con phải triển khai
};

// Lớp Dog kế thừa từ Pet
class Dog : public Pet {
public:
    // Ghi đè phương thức speak()
    void speak() const override {
        cout << "Woof! Woof!" << endl;
    }
};

// Lớp Cat kế thừa từ Pet
class Cat : public Pet {
public:
    // Ghi đè phương thức speak()
    void speak() const override {
        cout << "Meow! Meow!" << endl;
    }
};

// Chương trình chính
int main() {
    // Sử dụng tính đa hình
    Pet* myDog = new Dog();
    Pet* myCat = new Cat();

    cout << "Dog says: ";
    myDog->speak();  // Gọi phương thức speak của Dog

    cout << "Cat says: ";
    myCat->speak();  // Gọi phương thức speak của Cat

    // Giải phóng bộ nhớ
    delete myDog;
    delete myCat;

    return 0;
}
