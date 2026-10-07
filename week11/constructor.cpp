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
        cout << "Birthdate: " << birthdate.year << "/" << birthdate.month << "/" << birthdate.day << endl;
        cout << "CCCD: " << cccd << endl;
    }
    // ===== Get CCCD =====
    string getCCCD() {
        return cccd;
    }
    // ===== Get Address =====
    string getAddress() {
        return address;
    }
    // ===== Get Birth Year =====
    int getBirthYear() {
        return birthdate.year;
    }
    // ===== Get Name =====
    string getName() {
        return name;
    }
};

// Tim Student theo CCCD
Student getStudent(Student students[], int n, string cccd) {
    for (int i = 0; i < n; i++) {
        if (students[i].getCCCD() == cccd) {
            return students[i];
        }
    }
    return Student();
}

// Tim Student theo ten
void getStudentsByName(Student students[], int n, string name) {
    cout << "\n===== SINH VIEN TEN " << name << " =====" << endl;
    bool found = false;
    for (int i = 0; i < n; i++) {
        if (students[i].getName() == name) {
            students[i].getStudentInfo();
            found = true;
        }
    }
    if (found == false) {
        cout << "Khong co sinh vien ten " << name << endl;
    }
}

// Tim danh sach Student theo nam sinh
void getStudents(Student students[], int n, int year) {
    cout << "\n===== DANH SACH SINH VIEN SINH NAM " << year << " =====" << endl;
    bool found = false;
    for (int i = 0; i < n; i++) {
        if (students[i].getBirthYear() == year) {
            students[i].getStudentInfo();
            found = true;
        }
    }
    if (found == false) {
        cout << "Khong co sinh vien sinh nam " << year << endl;
    }
}

// Tim danh sach Student theo dia chi
void getStudentsByAddress(Student students[], int n, string address) {
    cout << "\n===== SINH VIEN O " << address << " =====" << endl;
    bool found = false;
    for (int i = 0; i < n; i++) {
        if (students[i].getAddress() == address) {
            students[i].getStudentInfo();
            found = true;
        }
    }
    if (found == false) {
        cout << "Khong co sinh vien o " << address << endl;
    }
}

// Thong ke so luong sinh vien theo nam sinh
void statisticsByYear(Student students[], int n, int year) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (students[i].getBirthYear() == year) {
            count++;
        }
    }
    cout << "Nam sinh " << year << ": " << count << " sinh vien" << endl;
}
// Thong ke nhieu nam
void statisticsByYear(Student students[], int n, int year) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (students[i].getBirthYear() == year) {
            count++;
        }
    }
    cout << year << ": " << count << " sinh vien" << endl;
}

// Thong ke theo tinh / thanh pho
void statisticsByAddress(Student students[], int n, string address) {
    int count = 0;
    for (int i = 0; i < n; i++) {

        if (students[i].getAddress() == address) {
            count++;
        }
    }
    cout << address << ": " << count << " sinh vien" << endl;
}


int main() {

    // ===== Tao cac Student =====
    Student student1;
    Student student2("Huong");
    Student student3("An", "Vo Van Ngan");
    Date d(2000, 9, 12);
    Student student4("PhuKheoBa","Ha Noi",d,"0007777056");
    Date d2(2001, 10, 26);
    Student student5("HungDepTrai","Da Nang",d2,"999993884");
    Date d3(2000, 5, 20);
    Student student6("Nguyen Van A","Ha Noi",d3,"111111111");
    Date d4(2001, 8, 15);
    Student student7("Nguyen Van B","Da Nang",d4,"222222222");
    Date d5(2005, 3, 10);
    Student student8("Nguyen Van C","TP HCM",d5,"333333333");
    Date d6(2005, 7, 25);
    Student student9("Nguyen Van D","TP HCM",d6,"444444444");
    Date d7(2003, 12, 5);
    Student student10("Nguyen Van E","Ha Noi",d7,"555555555");
    // Tao mang 10 sinh vien
    Student students[10];
    students[0] = student1;
    students[1] = student2;
    students[2] = student3;
    students[3] = student4;
    students[4] = student5;
    students[5] = student6;
    students[6] = student7;
    students[7] = student8;
    students[8] = student9;
    students[9] = student10;

    // 1. Tim Student theo CCCD
    string id;
    cout << "\nNhap CCCD can tim: ";
    cin >> id;
    Student result = getStudent(students, 10, id);
    if (result.getCCCD() != "") {
        cout << "\nSinh vien tim thay:" << endl;
        result.getStudentInfo();
    }
    else {
        cout << "\nKhong tim thay sinh vien!" << endl;
    }

    // 2. Tim Student theo ten
    string name;
    cout << "\nNhap ten can tim: ";
    cin >> ws;
    getline(cin, name);
    getStudentsByName(students, 10, name);

    // 2. Tim Student theo nam sinh
    int year;
    cout << "\nNhap nam sinh can tim: ";
    cin >> year;
    getStudents(students, 10, year);

    // 3. Tim Student theo dia chi
    string address;

    cout << "\nNhap dia chi muon tim: ";
    cin >> ws;
    getline(cin, address);
    getStudentsByAddress(students, 10, address);

    // 4. Thong ke theo nam sinh
    cout << "\n===== THONG KE THEO NAM SINH =====" << endl;
    statisticsByYear(students, 10, 2000);
    statisticsByYear(students, 10, 2001);
    statisticsByYear(students, 10, 2002);
    statisticsByYear(students, 10, 2003);
    statisticsByYear(students, 10, 2004);
    statisticsByYear(students, 10, 2005);

    // 5. Thong ke theo tinh / thanh pho
    cout << "\n===== THONG KE THEO TINH / THANH PHO =====" << endl;
    statisticsByAddress(students, 10, "Ha Noi");
    statisticsByAddress(students, 10, "Da Nang");
    statisticsByAddress(students, 10, "TP HCM");


    return 0;
}