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
ScoreInfo analyzeScores(const vector<double>& scores);

int main(){
// STEP 1
// Gọi hàm không tham số
cout << "===== STEP 1 =====" << endl;
showWelcome();
showMenu();


return 0;
}

