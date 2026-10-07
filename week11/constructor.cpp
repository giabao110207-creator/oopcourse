#include <iostream>
#include <string>
using namespace std;

class Date {
public:
    int year, month, day;

    Date() {
        year = 0;
        month = 0;
        day = 0;
    }

    Date(int y, int m, int d) {
        year = y;
        month = m;
        day = d;
    }
};

class Student {
private:
    string name;
    string address;
    Date birthdate;
    string cccd;

public:
    // ===== Constructors =====
    Student() {
        name = "";
        address = "";
        birthdate = Date();
        cccd = "";
    }

    Student(string n) {
        name = n;
        address = "";
        birthdate = Date();
        cccd = "";
    }

    Student(string n, string addr) {
        name = n;
        address = addr;
        birthdate = Date();
        cccd = "";
    }

    Student(string n, string addr, Date d) {
        name = n;
        address = addr;
        birthdate = d;
        cccd = "";
    }

    Student(string n, string addr, Date d, string id) {
        name = n;
        address = addr;
        birthdate = d;
        cccd = id;
    }

    // ===== Methods =====

    void setStudentInfo(string n) {
        name = n;
    }

    void setStudentInfo(string n, string addr) {
        name = n;
        address = addr;
    }

    void setStudentInfo(string n, string addr, Date d) {
        name = n;
        address = addr;
        birthdate = d;
    }

    void setStudentInfo(string n, string addr, Date d, string id) {
        name = n;
        address = addr;
        birthdate = d;
        cccd = id;
    }

    // ===== Get Student Info =====
    void getStudentInfo() {
        cout << "====================" << endl;
        cout << "=== Student Info ===" << endl;
        cout << "====================" << endl;

        cout << "Name: " << name << endl;
        cout << "Address: " << address << endl;
        cout << "Birthdate: "
             << birthdate.year << "/"
             << birthdate.month << "/"
             << birthdate.day << endl;
        cout << "CCCD: " << cccd << endl;
    }

    // ===== Get CCCD =====
    string getCCCD() {
        return cccd;
    }
};


// ===== Tim Student theo CCCD =====
Student getStudent(Student students[], int n, string cccd) {
    for (int i = 0; i < n; i++) {
        if (students[i].getCCCD() == cccd) {
            return students[i];
        }
    }

    // Khong tim thay
    return Student();
}


int main() {

    Student student1;
    Student student2("Huong");
    Student student3("An", "Vo Van Ngan");

    Date d(1989, 9, 12);
    Student student4("DoMIXI", "Ha Noi", d, "0007777056");

    Date d2(1996, 10, 26);
    Student student5("DungSenpai", "Da Nang", d2, "999993884");


    // ===== Hien thi thong tin =====
    student2.getStudentInfo();
    student3.getStudentInfo();
    student4.getStudentInfo();
    student5.getStudentInfo();


    // ===== Tao danh sach sinh vien =====
    Student students[3];

    students[0] = student2;
    students[1] = student4;
    students[2] = student5;


    // ===== Tim sinh vien theo CCCD =====
    string id;

    cout << "\nNhap CCCD can tim: ";
    cin >> id;

    Student result = getStudent(students, 3, id);

    if (result.getCCCD() != "") {
        cout << "\nSinh vien tim thay:" << endl;
        result.getStudentInfo();
    }
    else {
        cout << "\nKhong tim thay sinh vien!" << endl;
    }

    return 0;
}