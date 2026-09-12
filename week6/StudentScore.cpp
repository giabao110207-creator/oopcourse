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

// TASK 3
// COUNT STUDENTS
countStudents(scores, n);

// TASK 4
// FIND HIGHEST AND LOWEST SCORE
findHighestLowest(scores, n);

// TASK 5
// CLASSIFY STUDENTS
classifyStudents(scores, n);

// TASK 6
// COUNT EXCELLENT STUDENTS
   
int excellent = countExcellent(scores, n);
cout << endl;
cout << "===== TASK 6: COUNT EXCELLENT STUDENTS =====" << endl;
cout << "Number of excellent students: " << excellent << endl;

// TASK 7
// COUNT STUDENTS IN A SCORE RANGE
double a, b;

cout << endl;
cout << "===== TASK 7: COUNT STUDENTS IN A SCORE RANGE =====" << endl;
cout << "Enter minimum score: ";
cin >> a;
cout << "Enter maximum score: ";
cin >> b;

int countRange = countStudentsInRange(scores, n, a, b);
cout << "Students in range [" << a << ", " << b << "]: " << countRange << endl;

// TASK 8
// FIND STUDENTS ABOVE AVERAGE
findStudentsAboveAverage(scores, n);

// TASK 9
// FIND THE SECOND HIGHEST SCORE
findSecondHighest(scores, n);

// TASK 10
// SEARCH FOR A SCORE
searchScore(scores, n);

// TASK 11
// COUNT SCORE FREQUENCY
countScoreFrequency(scores, n);
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

// TASK 3
// COUNT STUDENTS
void countStudents(double scores[], int n){
int pass = 0;
int fail = 0;

for (int i = 0; i < n; i++){
    if (scores[i] >= 5){
        pass++;
    }else{
        fail++;
    }
}

double passRate = (double)pass / n * 100;

cout << endl;
cout << "===== TASK 3: STATISTICS =====" << endl;
cout << "Passed: " << pass << " students" << endl;
cout << "Failed: " << fail << " students" << endl;
cout << "Pass rate: " << passRate << "%" << endl;
}

// TASK 4
// FIND HIGHEST AND LOWEST SCORE
// =====================================================

void findHighestLowest(double scores[], int n){
double highest = scores[0];
double lowest = scores[0];

for (int i = 1; i < n; i++){
    if (scores[i] > highest){
        highest = scores[i];
    }
    if (scores[i] < lowest){
        lowest = scores[i];
    }
}

cout << endl;
cout << "===== TASK 4: HIGHEST AND LOWEST =====" << endl;
cout << "Highest score: " << highest << endl;
cout << "Lowest score: " << lowest << endl;
}

// TASK 5
// CLASSIFY STUDENTS
// =====================================================

void classifyStudents(double scores[], int n){
cout << endl;
cout << "===== TASK 5: CLASSIFICATION =====" << endl;
for (int i = 0; i < n; i++){
    cout << "Student " << i + 1 << ": " << scores[i] << " -> ";
    if (scores[i] >= 9){
        cout << "Excellent";
    }else if (scores[i] >= 8){
        cout << "Very Good";
    }else if (scores[i] >= 6.5){
        cout << "Good";
    }else if (scores[i] >= 5){
        cout << "Average";
    }else{
        cout << "Fail";
    }
    cout << endl;
    }
}

// TASK 6
// COUNT EXCELLENT STUDENTS
int countExcellent(double scores[], int n){
int count = 0;
for (int i = 0; i < n; i++){
    if (scores[i] >= 9){
        count++;
    }
}

return count;
}

// TASK 7
// COUNT STUDENTS IN A SCORE RANGE
int countStudentsInRange(double scores[],int n,double a,double b){
int countRange = 0;

for (int i = 0; i < n; i++){
    if (scores[i] >= a && scores[i] <= b){
        countRange++;
    }
}

 return countRange;
}

// TASK 8
// FIND STUDENTS ABOVE AVERAGE
// =====================================================

void findStudentsAboveAverage(double scores[], int n){
double sum = 0;

for (int i = 0; i < n; i++){
    sum += scores[i];
}
double average = sum / n;

cout << endl;
cout << "===== TASK 8: STUDENTS ABOVE AVERAGE =====" << endl;

cout << "Average score: " << average << endl;
cout << "Students above average:" << endl;

for (int i = 0; i < n; i++){
    if (scores[i] > average){
        cout << "Student " << i + 1 << ": " << scores[i] << endl;
        }
    }
}

// TASK 9
// FIND SECOND HIGHEST SCORE
void findSecondHighest(double scores[], int n){
double highest = scores[0];
double secondHighest = -1;
for (int i = 1; i < n; i++){
    if (scores[i] > highest){
        secondHighest = highest;
        highest = scores[i];
    }else if (scores[i] > secondHighest && scores[i] < highest){
        secondHighest = scores[i];
    }
}

cout << endl;
cout << "===== TASK 9: SECOND HIGHEST SCORE =====" << endl;
cout << "Highest score: " << highest << endl;

if (secondHighest == -1){
    cout << "There is no second highest score." << endl;
}else{
    cout << "Second highest score: " << secondHighest << endl;
    }
}

// TASK 10
// SEARCH FOR A SCORE
void searchScore(double scores[], int n){
double x;
bool found = false;
cout << endl;
cout << "===== TASK 10: SEARCH FOR A SCORE =====" << endl;

cout << "Enter score to search: ";
cin >> x;
cout << "Found at:" << endl;
for (int i = 0; i < n; i++){
    if (scores[i] == x){
        cout << "Student " << i + 1 << endl;
        found = true;
    }
}if (found == false){
    cout << "Score not found!" << endl;
}
}

// TASK 11
// COUNT SCORE FREQUENCY
void countScoreFrequency(double scores[], int n){
double x;
int frequency = 0;

cout << endl;
cout << "===== TASK 11: COUNT SCORE FREQUENCY =====" << endl;
cout << "Enter score: ";
cin >> x;
for (int i = 0; i < n; i++){
    if (scores[i] == x){
        frequency++;
    }
}

cout << "Score " << x << " appears " << frequency << " times." << endl;
}