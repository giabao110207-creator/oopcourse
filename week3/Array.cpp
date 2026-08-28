#include <iostream>
#include <string>
using namespace std;


int main()
{
    const int N = 20;

    // Khai bao 3 mang
    string names[N];
    string ids[N];
    string phones[N];

    // =========================
    // NHAP 20 SINH VIEN
    // =========================

    for (int i = 0; i < N; i++)
    {
        cout << "Enter student " << i + 1 << endl;

        cout << "Name : ";
        getline(cin, names[i]);

        cout << "ID   : ";
        getline(cin, ids[i]);

        cout << "Phone: ";
        getline(cin, phones[i]);

        cout << "-------------------------" << endl;
    }

    // =========================
    // XUAT 20 SINH VIEN
    // =========================

    cout << "\n===== STUDENT LIST =====\n\n";

    for (int i = 0; i < N; i++)
    {
        cout << "Student " << i + 1 << "\n";
        cout << "Name  : " << names[i] << "\n";
        cout << "ID    : " << ids[i] << "\n";
        cout << "Phone : " << phones[i] << "\n";
        cout << "-------------------------" << endl;
    }

    cout << "Total students = " << N << endl;

    return 0;
}