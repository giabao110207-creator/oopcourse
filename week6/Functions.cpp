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