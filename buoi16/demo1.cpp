#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Interface cho báo cáo khóa học (ISP)
class ICourseReport {
public:
    virtual void generateReport() const = 0;
    virtual ~ICourseReport() = default;
};

// Interface cho lưu trữ khóa học (ISP)
class ICourseRepository {
public:
    virtual void saveCourse(const string& courseName) = 0;
    virtual ~ICourseRepository() = default;
};

// Lớp cơ sở Course tuân theo nguyên tắc LSP
class Course {
protected:
    string courseName;
    int courseDuration; // Thời lượng khóa học tính theo giờ
public:
    Course(const string& name, int duration) : courseName(name), courseDuration(duration) {}

    virtual void displayInfo() const {
        cout << "Course Name: " << courseName << endl;
        cout << "Course Duration: " << courseDuration << " hours" << endl;
    }

    // Phương thức getter cho courseName
    string getCourseName() const {
        return courseName;
    }

    virtual ~Course() = default;
};

// Lớp con OnlineCourse kế thừa từ Course (LSP, OCP)
class OnlineCourse : public Course {
private:
    string platform;
public:
    OnlineCourse(const string& name, int duration, const string& platformName)
        : Course(name, duration), platform(platformName) {}

    void displayInfo() const override {
        Course::displayInfo();
        cout << "Platform: " << platform << endl;
    }
};

// Lớp con OfflineCourse kế thừa từ Course (LSP, OCP)
class OfflineCourse : public Course {
private:
    string location;
public:
    OfflineCourse(const string& name, int duration, const string& locationName)
        : Course(name, duration), location(locationName) {}

    void displayInfo() const override {
        Course::displayInfo();
        cout << "Location: " << location << endl;
    }
};

// Lớp quản lý khóa học tuân theo DIP
class CourseManager {
private:
    ICourseRepository* courseRepo; // Dependency được đảo ngược (DIP)
    ICourseReport* courseReport;   // Dependency được đảo ngược (DIP)
    vector<Course*> courses;       // Danh sách các khóa học

public:
    CourseManager(ICourseRepository* repo, ICourseReport* report)
        : courseRepo(repo), courseReport(report) {}

    // Thêm khóa học vào hệ thống
    void addCourse(Course* course) {
        courses.push_back(course);
        courseRepo->saveCourse(course->getCourseName()); // Sử dụng getter để lấy tên khóa học
    }

    // Hiển thị tất cả các khóa học
    void displayAllCourses() const {
        for (const auto& course : courses) {
            course->displayInfo();
            cout << "----------------------" << endl;
        }
    }

    // Tạo báo cáo cho các khóa học
    void generateReport() const {
        courseReport->generateReport();
    }

    ~CourseManager() {
        for (auto& course : courses) {
            delete course;
        }
    }
};

// Lớp lưu trữ khóa học (tuân theo SRP, DIP)
class CourseRepository : public ICourseRepository {
public:
    void saveCourse(const string& courseName) override {
        cout << "Saving course: " << courseName << endl;
    }
};

// Lớp báo cáo khóa học (tuân theo SRP, DIP)
class CourseReport : public ICourseReport {
public:
    void generateReport() const override {
        cout << "Generating course report..." << endl;
    }
};

// Chương trình chính
int main() {
    // Khởi tạo các thành phần quản lý khóa học
    ICourseRepository* repo = new CourseRepository();
    ICourseReport* report = new CourseReport();
    CourseManager courseManager(repo, report);

    // Thêm các khóa học Online và Offline
    Course* onlineCourse = new OnlineCourse("C++ Programming", 40, "Udemy");
    Course* offlineCourse = new OfflineCourse("Data Science", 50, "New York");

    courseManager.addCourse(onlineCourse);
    courseManager.addCourse(offlineCourse);

    // Hiển thị thông tin khóa học
    cout << "All Courses:" << endl;
    courseManager.displayAllCourses();

    // Tạo báo cáo
    courseManager.generateReport();

    // Giải phóng bộ nhớ
    delete repo;
    delete report;

    return 0;
}
