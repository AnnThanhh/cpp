#include <iostream>
using namespace std;

// Hằng số cho giá trị hồi máu và sát thương
const int HEALTH_BOOST = 10;
const int DAMAGE = 15;
const int MAX_HEALTH = 100;
const int MIN_HEALTH = 0;

// Hàm hiển thị tình trạng sức khỏe hiện tại
void displayHealth(int health) {
    cout << "\nCurrent Health: " << health << endl;
}

// Hàm hồi máu
void pickHealthBooster(int &health) {
    if (health == MAX_HEALTH) {
        cout << "Health is already full! No need for a health booster." << endl;
    } else {
        health += HEALTH_BOOST;
        if (health > MAX_HEALTH) health = MAX_HEALTH; // Đảm bảo không vượt quá 100 máu
        cout << "You picked up a health booster! Health increased by " << HEALTH_BOOST << "." << endl;
    }
}

// Hàm gây sát thương
void takeDamage(int &health) {
    health -= DAMAGE;
    if (health < MIN_HEALTH) health = MIN_HEALTH; // Đảm bảo không dưới 0 máu
    cout << "You took damage! Health decreased by " << DAMAGE << "." << endl;
}

int main() {
    int health = 100;  // Bắt đầu với 100 máu
    int choice;

    while (true) {
        displayHealth(health);
        cout << "Choose an action:\n1. Pick health booster (+10 HP)\n2. Take damage (-15 HP)\n3. Exit\n";
        cout << "Your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                pickHealthBooster(health);
                break;
            case 2:
                takeDamage(health);
                break;
            case 3:
                cout << "Exiting game..." << endl;
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }

        if (health == MIN_HEALTH) {
            cout << "Game over! You have no health left." << endl;
            break;
        }
    }

    return 0;
}
