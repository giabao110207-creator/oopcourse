#include <iostream>
using namespace std;

#define MAX 20

void inputStudents(double scores[], int n);
void displayScores(double scores[], int n);
void checkPassFail(double scores[], int n);
void countStudents(double scores[], int n);
void findHighestLowest(double scores[], int n);
void classifyStudents(double scores[], int n);
int countExcellent(double scores[], int n);
int countStudentsInRange(double scores[], int n, double a, double b);
void findStudentsAboveAverage(double scores[], int n);
void findSecondHighest(double scores[], int n);
void searchScore(double scores[], int n);
void countScoreFrequency(double scores[], int n);
void findFirstFailingStudent(double scores[], int n);
void compareAdjacentStudents(double scores[], int n);
void findLongestPassStreak(double scores[], int n);
void createScoreDistribution(double scores[], int n);

int main(){
int n;
cout << "How many students: " << endl;
cin >> n;

while (n < 2 || n > 20){
    cout << "Invalid number of students!" << endl;
    cout << "Please enter a number from 2 to 20." << endl;
    cout << "How many students? ";
    cin >> n;
}

double scores[MAX];
inputStudents(scores, n);

// TASK 1
// DISPLAY THE ARRAY
displayScores(scores, n);

// TASK 2
// PASS OR FAIL
checkPassFail(scores, n);


}

// INPUT STUDENTS
void inputStudents(double scores[], int n){
for (int i = 0; i < n; i++){
    cout << "Enter the score of student " << i + 1 << ": ";
    cin >> scores[i];
    while (scores[i] < 0 || scores[i] > 10){
        cout << "Invalid score! " << "Please enter a value from 0 to 10: ";
        cin >> scores[i];
        }
    }
}

// TASK 1
// DISPLAY THE ARRAY
void displayScores(double scores[], int n){
cout << endl;
cout << "===== TASK 1: STUDENT SCORES =====" << endl;
for (int i = 0; i < n; i++){
    cout << "Student " << i + 1 << ": " << scores[i] << endl;
    }
}

// TASK 2
// PASS OR FAIL
// =====================================================

void checkPassFail(double scores[], int n){
cout << endl;
cout << "===== TASK 2: PASS OR FAIL =====" << endl;

for (int i = 0; i < n; i++){
    cout << "Student " << i + 1 << ": ";

    if (scores[i] >= 5){
        cout << "PASS";
    }else{
        cout << "FAIL";
    }
    cout << endl;
    }
}