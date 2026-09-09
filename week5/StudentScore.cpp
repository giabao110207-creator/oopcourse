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
return 0;
}