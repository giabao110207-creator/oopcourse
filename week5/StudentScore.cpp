#include <iostream>
using namespace std;

int main(){
    int n;
    cout << "How many students: " << endl;
    cin >> n;

while (n < 2 || n > 20)
{
    cout << "Invalid number of students!" << endl;
    cout << "Please enter a number from 2 to 20." << endl;
    cout << "How many students? ";
    cin >> n;
}

//Enter the scores of the students
double scores[20];
for (int i = 0; i < n; i++){
    cout << "Enter the score of student " << i + 1 << ": ";
    cin >> scores[i];

while (scores[i] < 0 || scores[i] > 10)
    {
        cout << "Invalid score! Please enter a value from 0 to 10: ";
        cin >> scores[i];
    }
}

//Display the array
cout << endl;
cout << "=====STUDENTS SCORES=====: " << endl;
for (int i = 0; i < n; i++){
    cout << "Student " << i + 1 << ": " << scores[i] << endl;
}

//Pass or fail
cout << endl;
for (int i = 0; i < n; i++){
    cout << "student " << i + 1 << ": ";
    if (scores[i] >= 5){
        cout << "Pass " << endl;
    }
    else{
        cout << "Fail " << endl;
    }
}

//Count students
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
cout << "=====STATISTICS=====" << endl;
cout << "Pass: " << pass << "students " << endl;
cout << "Fail: " << fail << "students " << endl;
cout << "Pass Rate: " << passRate << "%" << endl;

//Find the highest and lowest scores
double highest = scores[0];
double lowest = scores[0];

for (int i = 0; i < n; i++){
    if (scores[i] > highest){
        highest = scores[i];
    }
    if (scores[i] < lowest){
        lowest = scores[i];
    }
}
cout << "Highest score: " << highest << endl;
cout << "lowest score: " << lowest << endl;

//Classify students
cout << endl;
cout << "=====CLASSIFY STUDENTS=====" << endl;
for (int i = 0; i < n; i++)
{
    cout << "Student " << i + 1 << ": " << scores[i] << " -> ";
    if (scores[i] >= 9)
    {
        cout << "Excellent";
    }
    else if (scores[i] >= 8)
    {
        cout << "Very Good";
    }
    else if (scores[i] >= 6.5)
    {
        cout << "Good";
    }
    else if (scores[i] >= 5)
    {
        cout << "Average";
    }
    else
    {
        cout << "Fail";
    }
    cout << endl;
}

//Count excellent students
int count = 0;
for (int i = 0; i < n; i++){
    if (scores[i] >= 9)
    count++; 
}

cout << endl;
cout << "=====EXCELLENT=====" << endl;
cout << "Number of excellent students: " << count << endl;

//COUNT STUDENTS IN A SCORE RANGE
    double a, b;
    int countRange = 0;
    cout << "===== 2. COUNT STUDENTS IN A SCORE RANGE =====";
    cout << "Enter minimum score: ";
    cin >> a;
    cout << "Enter maximum score: ";
    cin >> b;
    for (int i = 0; i < n; i++) {
        if (scores[i] >= a && scores[i] <= b) {
            countRange++;
        }
    }
    cout << "Students in range [" << a << ", " << b << "]: "
         << countRange << endl;

//Find students above averrage
double sum = 0;
double average;

for (int i = 0; i < n; i++) {
    sum += scores[i];
}

average = sum / n;

cout << "===== FIND STUDENTS ABOVE AVERAGE =====";
cout << "Average score: " << average << endl;
cout << "Students above average: ";

for (int i = 0; i < n; i++) {
    if (scores[i] > average) {
        cout << "Student " << i + 1
             << ": " << scores[i] << endl;
        }
    }

//Find the second highest score
double highest = scores[0];
double secondHighest = -1;

for (int i = 1; i < n; i++) {
    if (scores[i] > highest) {
        secondHighest = highest;
        highest = scores[i];
        }
        else if (scores[i] > secondHighest &&
                scores[i] < highest) {
            secondHighest = scores[i];
        }
    }

cout << "===== 4. FIND THE SECOND HIGHEST SCORE =====";
cout << "Highest score: " << highest << endl;

if (secondHighest == -1) {
    cout << "There is no second highest score.";
}
else {
    cout << "Second highest score: "
         << secondHighest << endl;
}

//SEARCH FOR A SCORE
double x;
bool found = false;

cout << "===== 5. SEARCH FOR A SCORE =====";
cout << "Enter score to search: ";
cin >> x;

cout << "Found at:";

for (int i = 0; i < n; i++) {
    if (scores[i] == x) {
        cout << "Student " << i + 1 << endl;
        found = true;
    }
}
if (!found) {
        cout << "Score not found!";
}


// 6. COUNT SCORE FREQUENCY
int frequency = 0;

cout << "=====COUNT SCORE FREQUENCY=====";
cout << "Enter score: ";
cin >> x;

for (int i = 0; i < n; i++) {
    if (scores[i] == x) {
            frequency++;
    }
}

cout << "Score " << x << " appears "
     << frequency << " times.\n";


// 7. FIND FIRST FAILING STUDENT
int firstFail = -1;

for (int i = 0; i < n; i++) {
    if (scores[i] < 5) {
            firstFail = i;
            break;
    }
}

cout << "=====FIND FIRST FAILING STUDENT=====";

if (firstFail == -1) {
    cout << "All students pass!\n";
}
else {
    cout << "First failing student:\n";
    cout << "Student " << firstFail + 1
         << ": " << scores[firstFail] << endl;
}

// 8. COMPARE ADJACENT STUDENTS
cout << "=====COMPARE ADJACENT STUDENTS=====";

for (int i = 0; i < n - 1; i++) {

    if (scores[i + 1] > scores[i]) {
        cout << "Student " << i + 2
             << " improved compared to Student "
             << i + 1 << endl;
        }
    }


// 9. FIND THE LONGEST PASS STREAK
int currentStreak = 0;
int longestStreak = 0;

for (int i = 0; i < n; i++) {
    if (scores[i] >= 5) {
        currentStreak++;

        if (currentStreak > longestStreak) {
                longestStreak = currentStreak;
        }
    }
    else {
            currentStreak = 0;
    }
}

cout << "=====FIND THE LONGEST PASS STREAK=====";
cout << "Longest pass streak: "
     << longestStreak << " students";


//10. CREATE A SCORE DISTRIBUTION
int range1 = 0;
int range2 = 0;
int range3 = 0;
int range4 = 0;
int range5 = 0;
for (int i = 0; i < n; i++) {
    if (scores[i] < 5) {
        range1++;
    }
    else if (scores[i] < 6.5) {
        range2++;
    }
    else if (scores[i] < 8) {
        range3++;
    }
    else if (scores[i] < 9) {
        range4++;
    }
    else {
        range5++;
    }
}

cout << "=====SCORE DISTRIBUTION=====";

cout << "0 - <5     : ";
for (int i = 0; i < range1; i++)
    cout << "*";
cout << " " << range1 << endl;

cout << "5 - <6.5   : ";
for (int i = 0; i < range2; i++)
    cout << "*";
cout << " " << range2 << endl;

cout << "6.5 - <8   : ";
for (int i = 0; i < range3; i++)
    cout << "*";
cout << " " << range3 << endl;

cout << "8 - <9     : ";
for (int i = 0; i < range4; i++)
    cout << "*";
cout << " " << range4 << endl;

cout << "9 - 10     : ";
for (int i = 0; i < range5; i++)
    cout << "*";
cout << " " << range5 << endl;

return 0;
}