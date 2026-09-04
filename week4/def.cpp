#include <iostream>
#include <string>
using namespace std;

int n = 0;
string names[20];
string ids[20];
string phones[20];

void printnames()
{
    cout << "My name is Nguyen Hoang Gia Bao" << endl;
}
void solveEquation()
{
    double a, b;
    cout << "\n===== EX2: LINEAR EQUATION =====" << endl;
    cout << "Input a: ";
    cin >> a;
    cout << "Input b: ";
    cin >> b;
    // Xét các trường hợp của phương trình
    if (a == 0)
    {
        if (b == 0)
        {
            cout << "The equation has infinitely many solutions." << endl;
        }
        else
        {
            cout << "The equation has no solution." << endl;
        }
    }
    else
    {
        double x = -b / a;
        cout << "The solution is x = " << x << endl;
    }
}
// EX3: Kiểm tra n có phải số nguyên tố hay không
void checkPrime()
{
    int n;
    cout << "\n===== EX3: CHECK PRIME =====" << endl;
    cout << "Input n: ";
    cin >> n;
    bool isPrime = true;
    // Số nhỏ hơn 2 không phải số nguyên tố
    if (n < 2)
    {
        isPrime = false;
    }
    else
    {
        // Kiểm tra các số từ 2 đến n - 1
        for (int i = 2; i < n; i++)
        {
            if (n % i == 0)
            {
                isPrime = false;
                break;
            }
        }
    }
    // In kết quả
    if (isPrime)
    {
        cout << n << " is a prime number." << endl;
    }
    else
    {
        cout << n << " is not a prime number." << endl;
    }
}
// Hàm nhập thông tin sinh viên
void inputStudent()
{
    cout << "Input the number of students: ";
    cin >> n;
    if (n > 0 && n <= 20)
    {
        cin.ignore();
        for (int i = 0; i < n; i++)
        {
            cout << "\nEnter information of student " << i + 1 << endl;
            cout << "Name: ";
            getline(cin, names[i]);
            cout << "ID: ";
            getline(cin, ids[i]);
            cout << "Phone: ";
            getline(cin, phones[i]);
        }
        cout << "\nNumber of inputted students: " << n << endl;
    }
    else
    {
        cout << "The number of students must be from 1 to 20." << endl;
    }
}
// Hàm xuất thông tin sinh viên
void outputStudents()
{
    cout << "\n===== STUDENT LIST =====" << endl;

    for (int i = 0; i < n; i++)
    {
        cout << "\nStudent: " << i + 1 << endl;
        cout << "Name: " << names[i] << endl;
        cout << "ID: " << ids[i] << endl;
        cout << "Phone: " << phones[i] << endl;
    }
}
// Hàm main
int main()
{
    // EX1
    printnames();
    // EX2
    solveEquation();
    // EX3
    checkPrime();
    // Nhập và xuất sinh viên
    inputStudent();
    outputStudents();

    return 0;
}

