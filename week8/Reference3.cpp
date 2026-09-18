#include <iostream>

using namespace std;

int main()
{
    // =========================
    // PHAN 1
    // =========================

    int a = 5;

    // r la reference cua a
    int& r = a;

    // Thay doi gia tri thong qua reference
    r = 10;

    cout << "===== PRACTICE 3 =====" << endl;
    cout << "1. a = " << a << endl;
    cout << "2. r = " << r << endl;


    // =========================
    // PHAN 2 - VARIATION
    // =========================

    int x = 3;

    // y la reference cua x
    int& y = x;

    x = 7;
    y = 2;

    cout << "\n===== VARIATION =====" << endl;
    cout << x << " " << y << endl;

    return 0;
}