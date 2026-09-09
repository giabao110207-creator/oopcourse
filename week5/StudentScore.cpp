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

return 0;
}