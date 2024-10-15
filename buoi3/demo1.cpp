#include <iostream>
using namespace std;

int main() {
    int level = 1;           // Cấp độ ban đầu của nhân vật
    int exp = 0;             // Điểm kinh nghiệm ban đầu
    const int EXP_PER_LEVEL = 100;  // Điểm kinh nghiệm cần để lên cấp
    int expToNextLevel = EXP_PER_LEVEL;  // Điểm kinh nghiệm để lên cấp tiếp theo
    int expGain = 20;        // Điểm kinh nghiệm nhận được sau mỗi lần luyện tập
    int choice;

    cout << "Welcome to the training system! Your character starts at level 1.\n";

    // Vòng lặp chính của game
    while (true) {
        cout << "\nCurrent Level: " << level << " | Current EXP: " << exp << " / " << expToNextLevel << endl;
        cout << "Choose an action:\n1. Train (Gain " << expGain << " EXP)\n2. Exit\n";
        cout << "Your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                // Nhân vật luyện tập và nhận điểm kinh nghiệm
                exp += expGain;
                cout << "You gained " << expGain << " EXP!" << endl;

                // Kiểm tra xem có đủ EXP để lên cấp không
                if (exp >= expToNextLevel) {
                    exp -= expToNextLevel;  // Bỏ đi số EXP đã dùng để lên cấp
                    level++;  // Tăng cấp
                    expToNextLevel = EXP_PER_LEVEL * level;  // Tăng lượng EXP cần cho cấp độ tiếp theo
                    cout << "Congratulations! You leveled up to level " << level << "!" << endl;
                }
                break;
            case 2:
                // Thoát game
                cout << "Exiting the game..." << endl;
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}
