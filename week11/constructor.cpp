#include <iostream>
#include <string>
#include <vector>
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
    // ===== Display Student Info =====
    void displayStudentInfo() {
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

// 1. Tim Student theo CCCD
Student getStudent(vector<Student> students, string cccd) {
    for (int i = 0; i < students.size(); i++) {
        if (students[i].getCCCD() == cccd) {
            return students[i];
        }
    }
    return Student();
}

// 2. Tim danh sach Student theo ten
vector<Student> getStudentsByName(
    vector<Student> students,
    string name
) {
    vector<Student> result;
    for (int i = 0; i < students.size(); i++) {
        if (students[i].getName() == name) {
            result.push_back(students[i]);
        }
    }
    return result;
}

// 3. Tim danh sach Student theo nam sinh
vector<Student> getStudentsByYear(
    vector<Student> students,
    int year
) {
    vector<Student> result;
    for (int i = 0; i < students.size(); i++) {
        if (students[i].getBirthYear() == year) {
            result.push_back(students[i]);
        }
    }
    return result;
}

// 4. Tim danh sach Student theo dia chi
vector<Student> getStudentsByAddress(
    vector<Student> students,
    string address
) {
    vector<Student> result;
    for (int i = 0; i < students.size(); i++) {
        if (students[i].getAddress() == address) {
            result.push_back(students[i]);
        }
    }
    return result;
}

// 5. Thong ke theo nam sinh
static vector<int> statisticByYear(vector<Student> students, vector<int> years) {
    vector<int> counts;
    for (int i = 0; i < years.size(); i++) {
        int count = 0;
        for (int j = 0; j < students.size(); j++) {
            if (students[j].getBirthYear() == years[i]) {
                count++;
            }
        }
        counts.push_back(count);
    }
    return counts;
}

// 6. Thong ke theo tinh / thanh pho
static vector<int> statisticByProvince(vector<Student> students, vector<string> provinces) {
    vector<int> counts;
    for (int i = 0; i < provinces.size(); i++) {
        int count = 0;
        for (int j = 0; j < students.size(); j++) {
            if (students[j].getAddress() == provinces[i]) {
                count++;
            }
        }
        counts.push_back(count);
    }
    return counts;
}

// 6. Tim danh sach Student theo tinh / thanh pho 
vector<Student> getStudentsByProvince( vector<Student> students, string province ) { 
    vector<Student> result; 
    for (int i = 0; i < students.size(); i++) { 
        if (students[i].getAddress().find(province) != string::npos) { 
            result.push_back(students[i]); } 
        } 
        return result; 
    }
int main() {

    // Tao cac Student
    Student student1;
    Student student2("Huong");
    Student student3("An","Vo Van Ngan");
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

    // Tao vector Student
    vector<Student> students;
    students.push_back(student1);
    students.push_back(student2);
    students.push_back(student3);
    students.push_back(student4);
    students.push_back(student5);
    students.push_back(student6);
    students.push_back(student7);
    students.push_back(student8);
    students.push_back(student9);
    students.push_back(student10);

    // 1. Tim Student theo CCCD
    string id;
    cout << "\nNhap CCCD can tim: ";
    cin >> id;
    Student result = getStudent(students, id);
    if (result.getCCCD() != "") {
        cout << "\nSinh vien tim thay:" << endl;
        result.displayStudentInfo();
    }
    else {
        cout << "\nKhong tim thay sinh vien!" << endl;
    }

    // 2. Tim danh sach Student theo ten
    string name;
    cout << "\nNhap ten can tim: ";
    cin >> ws;
    getline(cin, name);
    vector<Student> listByName =
        getStudentsByName(students, name);
    cout << "\n===== SINH VIEN TEN " << name << " =====" << endl;
    if (listByName.size() == 0) {
        cout << "Khong co sinh vien ten " << name << endl;
    }
    else {
        for (int i = 0; i < listByName.size(); i++) {
            listByName[i].displayStudentInfo();
        }
    }

    // 3. Tim danh sach Student theo nam sinh
    int year;
    cout << "\nNhap nam sinh can tim: ";
    cin >> year;
    vector<Student> listByYear =
        getStudentsByYear(students, year);
    cout << "\n===== SINH VIEN SINH NAM " << year << " =====" << endl;
    if (listByYear.size() == 0) {
        cout << "Khong co sinh vien sinh nam " << year << endl;

    }
    else {
        for (int i = 0; i < listByYear.size(); i++) {
            listByYear[i].displayStudentInfo();
        }
    }

    // 4. Tim danh sach Student theo dia chi
    string address;
    cout << "\nNhap dia chi muon tim: ";
    cin >> ws;
    getline(cin, address);
    vector<Student> listByAddress =
        getStudentsByAddress(students, address);
    cout << "\n===== SINH VIEN O " << address << " =====" << endl;
    if (listByAddress.size() == 0) {
        cout << "Khong co sinh vien o " << address << endl;
    }
    else {
        for (int i = 0; i < listByAddress.size(); i++) {

            listByAddress[i].displayStudentInfo();
        }
    }

    // 5. Thong ke theo nam sinh
    vector<int> years;
    years.push_back(2000);
    years.push_back(2001);

    vector<int> yearCounts = statisticByYear(students, years); 
    for (int i = 0; i < years.size(); i++) { 
        cout << "Year " << years[i] << ": " << yearCounts[i] << " student(s)" << endl; 
        vector<Student> yearList = getStudentsByYear(students, years[i]); 
        for (int j = 0; j < yearList.size(); j++) { 
            yearList[j].displayStudentInfo(); 
        }
    }

    // 6. Thong ke theo tinh / thanh pho
    vector<string> provinces;
    provinces.push_back("TP HCM"); 
    provinces.push_back("Dong Nai"); 
    provinces.push_back("Binh Duong"); 
    provinces.push_back("Ha Noi"); 
    provinces.push_back("Da Nang");

    vector<int> provinceCounts = statisticByProvince(students, provinces); 
    for (int i = 0; i < provinces.size(); i++) { cout << provinces[i] << ": " << provinceCounts[i] << " student(s)" << endl; 
        vector<Student> provinceList = getStudentsByProvince(students, provinces[i]); 
        for (int j = 0; j < provinceList.size(); j++) { 
            provinceList[j].displayStudentInfo(); 
        }
    }

    return 0;
}