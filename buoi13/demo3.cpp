#include <iostream>
#include <string>
using namespace std;

// Lớp cha Document
class Document {
protected:
    string title;
    string author;
    int publicationYear;

public:
    // Constructor cho Document
    Document(string docTitle, string docAuthor, int docYear) {
        title = docTitle;
        author = docAuthor;
        publicationYear = docYear;
    }

    // Phương thức hiển thị thông tin Document (sẽ được ghi đè bởi các lớp con)
    virtual void displayInfo() const {
        cout << "Title: " << title << endl;
        cout << "Author: " << author << endl;
        cout << "Publication Year: " << publicationYear << endl;
    }
};

// Lớp con Book kế thừa từ Document
class Book : public Document {
private:
    int numPages;

public:
    // Constructor cho Book
    Book(string bookTitle, string bookAuthor, int bookYear, int pages)
        : Document(bookTitle, bookAuthor, bookYear) {
        numPages = pages;
    }

    // Ghi đè phương thức displayInfo()
    void displayInfo() const override {
        Document::displayInfo();  // Gọi phương thức hiển thị từ lớp cha
        cout << "Number of Pages: " << numPages << endl;
    }
};

// Lớp con Magazine kế thừa từ Document
class Magazine : public Document {
private:
    int issueNumber;

public:
    // Constructor cho Magazine
    Magazine(string magTitle, string magAuthor, int magYear, int issue)
        : Document(magTitle, magAuthor, magYear) {
        issueNumber = issue;
    }

    // Ghi đè phương thức displayInfo()
    void displayInfo() const override {
        Document::displayInfo();  // Gọi phương thức hiển thị từ lớp cha
        cout << "Issue Number: " << issueNumber << endl;
    }
};

// Lớp con Ebook kế thừa từ Document
class Ebook : public Document {
private:
    double fileSize;  // Kích thước file tính bằng MB
    string format;    // Định dạng file (ví dụ: PDF, EPUB)

public:
    // Constructor cho Ebook
    Ebook(string ebookTitle, string ebookAuthor, int ebookYear, double size, string fileFormat)
        : Document(ebookTitle, ebookAuthor, ebookYear) {
        fileSize = size;
        format = fileFormat;
    }

    // Ghi đè phương thức displayInfo()
    void displayInfo() const override {
        Document::displayInfo();  // Gọi phương thức hiển thị từ lớp cha
        cout << "File Size: " << fileSize << " MB" << endl;
        cout << "Format: " << format << endl;
    }
};

// Chương trình chính
int main() {
    // Tạo đối tượng Book
    Book myBook("The Great Gatsby", "F. Scott Fitzgerald", 1925, 180);
    cout << "Book Information:" << endl;
    myBook.displayInfo();
    cout << "----------------------" << endl;

    // Tạo đối tượng Magazine
    Magazine myMagazine("National Geographic", "Various Authors", 2023, 105);
    cout << "Magazine Information:" << endl;
    myMagazine.displayInfo();
    cout << "----------------------" << endl;

    // Tạo đối tượng Ebook
    Ebook myEbook("Clean Code", "Robert C. Martin", 2008, 2.5, "PDF");
    cout << "Ebook Information:" << endl;
    myEbook.displayInfo();

    return 0;
}
