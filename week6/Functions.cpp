#include <iostream>
#include <string>
#include <vector>

using namespace std;


struct ScoreInfo
{
    double sum;
    double average;
    int count;
    double maxScore;
    double minScore;
};

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

// STEP 3
// Gọi hàm có nhiều tham số
cout << endl;
cout << "===== STEP 3 =====" << endl;
printStudentInfo(studentName, studentID);
double score;
cout << "Enter score: ";
cin >> score;
showScore(studentName, score);

// STEP 4
// Hàm có tham số và trả về kết quả
cout << endl;
cout << "===== STEP 4 =====" << endl;
double math, english;

cout << "Enter Math score: ";
cin >> math;
cout << "Enter English score: ";
cin >> english;
double average = calculateAverage(math, english);
cout << "Average score = " << average << endl;

// Bài tập maxValue()
int a, b;
cout << endl;
cout << "Enter two integers: ";
cin >> a >> b;
int max = maxValue(a, b);
cout << "Maximum value = " << max << endl;

// STEP 5
// Struct chứa nhiều kết quả
cout << endl;
cout << "===== STEP 5 =====" << endl;
vector<double> scores = {8.5, 7.0, 9.5, 6.0, 8.0};
ScoreInfo info = analyzeScores(scores);

cout << "Total   : " << info.sum << endl;
cout << "Average : " << info.average << endl;
cout << "Count   : " << info.count << endl;
cout << "Max     : " << info.maxScore << endl;
cout << "Min     : " << info.minScore << endl;



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

// STEP 3
// Hàm có nhiều tham số và không có giá trị trả về
void printStudentInfo(string name, int id)
{
    cout << "------------------------" << endl;
    cout << "Name : " << name << endl;
    cout << "ID   : " << id << endl;
    cout << "------------------------" << endl;
}
// Bài tập Step 3: showScore()
void showScore(string name, double score)
{
    cout << "Student: " << name << endl;
    cout << "Score  : " << score << endl;
    cout << "Keep going!" << endl;
}

// STEP 4
// Hàm có tham số và có giá trị trả về
double calculateAverage(double score1, double score2)
{
    double sum = score1 + score2;
    double avg = sum / 2;

    return avg;
}
// Bài tập Step 4: maxValue()
int maxValue(int a, int b)
{
    if (a > b)
    {
        return a;
    }
    else
    {
        return b;
    }
}

// STEP 5
// Hàm trả về nhiều kết quả bằng struct
ScoreInfo analyzeScores(const vector<double>& scores)
{
    ScoreInfo result;

    result.sum = 0;
    result.count = scores.size();

    // Nếu không có điểm
    if (result.count == 0)
    {
        result.average = 0;
        result.maxScore = 0;
        result.minScore = 0;

        return result;
    }

    // Gán giá trị ban đầu
    result.minScore = scores[0];
    result.maxScore = scores[0];

    // Duyệt qua danh sách điểm
    for (double s : scores)
    {
        result.sum += s;

        if (s > result.maxScore)
        {
            result.maxScore = s;
        }

        if (s < result.minScore)
        {
            result.minScore = s;
        }
    }
    result.average = result.sum / result.count;

    return result;
}