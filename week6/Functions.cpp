#include <iostream>
#include <string>
#include <vector>

using namespace std;

void showWelcome();
void showMenu();
void showStudentName(string name);
void showStudentID(int id);
void printStudentInfo(string name, int id);
void showScore(string name, double score);
double calculateAverage(double score1, double score2);
int maxValue(int a, int b);

int main(){
// STEP 1
// Gọi hàm không tham số
cout << "===== STEP 1 =====" << endl;
showWelcome();
showMenu();

// STEP 2
// Gọi hàm có 1 tham số
    
cout << endl;
cout << "===== STEP 2 =====" << endl; 
string studentName;
int studentID;
cout << "Enter student name: ";
getline(cin, studentName);
cout << "Enter student ID: ";
cin >> studentID;
showStudentName(studentName);
showStudentID(studentID);

return 0;
}

// STEP 1
// Hàm không có tham số và không có giá trị trả về
void showWelcome()
{
    cout << "==============================" << endl;
    cout << " Welcome to Student Manager!" << endl;
    cout << "==============================" << endl;
}
// Bài tập Step 1: showMenu()
void showMenu()
{
    cout << endl;
    cout << "===== MENU =====" << endl;
    cout << "1. Display students" << endl;
    cout << "2. Show statistics" << endl;
    cout << "3. Exit" << endl;
    cout << "================" << endl;
}

// STEP 2
// Hàm có 1 tham số và không có giá trị trả về
void showStudentName(string name)
{
    cout << "Hello, " << name << "!" << endl;
    cout << "Welcome to our class!" << endl;
}
// Bài tập Step 2: showStudentID()
void showStudentID(int id)
{
    cout << "Student ID: " << id << endl;
}