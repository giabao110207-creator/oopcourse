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

// TASK 12
// FIND FIRST FAILING STUDENT
findFirstFailingStudent(scores, n);

// TASK 13
// COMPARE ADJACENT STUDENTS
compareAdjacentStudents(scores, n);

// TASK 14
// FIND THE LONGEST PASS STREAK
findLongestPassStreak(scores, n);

// TASK 15
// CREATE A SCORE DISTRIBUTION
createScoreDistribution(scores, n);

return 0;

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

// TASK 12
// FIND FIRST FAILING STUDENT
void findFirstFailingStudent(double scores[], int n){
int firstFail = -1;

for (int i = 0; i < n; i++){
    if (scores[i] < 5){
        firstFail = i;
        break;
    }
}

cout << endl;
cout << "===== TASK 12: FIRST FAILING STUDENT =====" << endl;

if (firstFail == -1){
    cout << "All students pass!" << endl;
}else{
    cout << "First failing student:" << endl;
    cout << "Student "  << firstFail + 1 << ": " << scores[firstFail] << endl;
    }
}

// TASK 13
// COMPARE ADJACENT STUDENTS
void compareAdjacentStudents(double scores[], int n){
cout << endl;
cout << "===== TASK 13: COMPARE ADJACENT STUDENTS =====" << endl;

for (int i = 0; i < n - 1; i++){
    if (scores[i + 1] > scores[i]){
        cout << "Student " << i + 2 << " improved compared to Student " << i + 1 << endl;
        }
    }
}

// TASK 14
// FIND LONGEST PASS STREAK
void findLongestPassStreak(double scores[], int n){
int currentStreak = 0;
int longestStreak = 0;

for (int i = 0; i < n; i++){
    if (scores[i] >= 5){
        currentStreak++;
        if (currentStreak > longestStreak){
            longestStreak = currentStreak;
        }
    }else{
        currentStreak = 0;
    }
}

cout << endl;
cout << "===== TASK 14: LONGEST PASS STREAK =====" << endl;
cout << "Longest pass streak: " << longestStreak << " students" << endl;
}

// TASK 15
// CREATE A SCORE DISTRIBUTION
void createScoreDistribution(double scores[], int n){
int range1 = 0;
int range2 = 0;
int range3 = 0;
int range4 = 0;
int range5 = 0;

for (int i = 0; i < n; i++){
    if (scores[i] < 5){
        range1++;
    }else if (scores[i] < 6.5){
        range2++;
    }else if (scores[i] < 8){
        range3++;
    }else if (scores[i] < 9){
        range4++;
    }else{
        range5++;
    }
}
cout << endl;
cout << "===== TASK 15: SCORE DISTRIBUTION =====" << endl;
cout << "0 - <5     : ";
for (int i = 0; i < range1; i++){
    cout << "*";
}

cout << " " << range1 << endl;
cout << "5 - <6.5   : ";

for (int i = 0; i < range2; i++){
    cout << "*";
}

cout << " " << range2 << endl;
cout << "6.5 - <8   : ";

for (int i = 0; i < range3; i++){
    cout << "*";
}

cout << " " << range3 << endl;
cout << "8 - <9     : ";
for (int i = 0; i < range4; i++){
    cout << "*";
}

cout << " " << range4 << endl;
cout << "9 - 10     : ";

for (int i = 0; i < range5; i++){
    cout << "*";
}

cout << " " << range5 << endl;
}