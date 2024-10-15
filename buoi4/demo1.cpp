#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Cấu trúc lưu trữ thông tin về sách
struct Book {
    string title;
    string author;
    double price;
    int quantity;
};

// Hàm thêm sách vào cửa hàng
void addBook(vector<Book>& store) {
    Book newBook;
    cout << "Enter book title: ";
    cin.ignore(); // Xóa ký tự xuống dòng còn sót lại
    getline(cin, newBook.title);
    
    cout << "Enter author: ";
    getline(cin, newBook.author);
    
    cout << "Enter price of the book: ";
    cin >> newBook.price;
    
    cout << "Enter quantity of the book: ";
    cin >> newBook.quantity;
    
    store.push_back(newBook);
    cout << "Book added successfully!\n";
}

// Hàm hiển thị danh sách sách trong cửa hàng
void displayBooks(const vector<Book>& store) {
    if (store.empty()) {
        cout << "No books in the store.\n";
        return;
    }
    
    cout << "\n--- List of Books in Store ---\n";
    for (size_t i = 0; i < store.size(); ++i) {
        cout << "Book " << i + 1 << ":\n";
        cout << "Title: " << store[i].title << endl;
        cout << "Author: " << store[i].author << endl;
        cout << "Price: $" << store[i].price << endl;
        cout << "Quantity: " << store[i].quantity << endl;
        cout << "-------------------------\n";
    }
}

// Hàm tính tổng giá sách trong cửa hàng
void calculateTotalValue(const vector<Book>& store) {
    double totalValue = 0;
    
    for (const auto& book : store) {
        totalValue += book.price * book.quantity;
    }
    
    cout << "\nTotal value of all books in the store: $" << totalValue << endl;
}

// Hàm chính điều khiển chương trình
int main() {
    vector<Book> store;
    int choice;
    
    while (true) {
        cout << "\n--- Bookstore Management ---\n";
        cout << "1. Add a book\n";
        cout << "2. Display all books\n";
        cout << "3. Calculate total value of books\n";
        cout << "4. Exit\n";
        cout << "Choose an option: ";
        cin >> choice;
        
        switch (choice) {
            case 1:
                addBook(store);
                break;
            case 2:
                displayBooks(store);
                break;
            case 3:
                calculateTotalValue(store);
                break;
            case 4:
                cout << "Exiting program...\n";
                return 0;
            default:
                cout << "Invalid choice, please try again.\n";
        }
    }
    
    return 0;
}
