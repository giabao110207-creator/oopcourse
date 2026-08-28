#include <iostream>
#include <string>

using namespace std;

const int MAX_AGE = 120;

int main()
{
    string name;
    int age;

    cout << "What is your name? ";
    cin >> name;

    cout << "How old are you? ";
    cin >> age;

    if (age > MAX_AGE)
    {
        cout << "Please enter a valid age." << endl;
        return 1;
    }

    cout << "Hello, " << name << "! You are " << age << " years old." << endl;

    return 0;
}