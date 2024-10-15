#include <iostream>
using namespace std;

// Cấu trúc nhân vật
struct Character {
    int health;
    int mana;
    bool isAlive;
};

// Hàm để kiểm tra trạng thái của nhân vật
void checkStatus(Character &character) {
    if (character.health <= 0) {
        character.isAlive = false;
        character.health = 0; // Đảm bảo không hiển thị giá trị âm
    } else {
        character.isAlive = true;
    }

    if (character.isAlive) {
        cout << "Nhân vật còn sống." << endl;
    } else {
        cout << "Nhân vật đã chết." << endl;
    }
}

// Hàm để tấn công nhân vật
void attack(Character &character, int damage) {
    if (character.isAlive) {
        character.health -= damage;
        cout << "Nhân vật bị tấn công và mất " << damage << " máu." << endl;
        checkStatus(character); // Kiểm tra sau khi bị tấn công
    } else {
        cout << "Không thể tấn công vì nhân vật đã chết." << endl;
    }
}

// Hàm để hồi phục nhân vật
void heal(Character &character, int healAmount, int manaCost) {
    if (character.isAlive) {
        if (character.mana >= manaCost) {
            character.health += healAmount;
            character.mana -= manaCost;
            cout << "Nhân vật đã hồi phục " << healAmount << " máu và mất " << manaCost << " mana." << endl;
        } else {
            cout << "Không đủ mana để hồi phục!" << endl;
        }
    } else {
        cout << "Nhân vật đã chết, không thể hồi phục." << endl;
    }
}

// Hàm để hiển thị thông tin của nhân vật
void displayCharacter(const Character &character) {
    cout << "Lượng máu: " << character.health << endl;
    cout << "Mana: " << character.mana << endl;
    cout << "Trạng thái: " << (character.isAlive ? "Còn sống" : "Đã chết") << endl;
}

int main() {
    // Tạo một nhân vật
    Character hero = {100, 50, true};

    // Hiển thị thông tin ban đầu của nhân vật
    displayCharacter(hero);
    cout << endl;

    // Nhân vật bị tấn công
    attack(hero, 30);
    displayCharacter(hero);
    cout << endl;

    // Nhân vật hồi phục
    heal(hero, 20, 10);
    displayCharacter(hero);
    cout << endl;

    // Nhân vật bị tấn công quá mạnh dẫn đến chết
    attack(hero, 100);
    displayCharacter(hero);
    cout << endl;

    // Cố gắng hồi phục sau khi nhân vật đã chết
    heal(hero, 50, 20);
    displayCharacter(hero);

    return 0;
}
