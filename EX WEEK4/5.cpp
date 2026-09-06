//Bài 5: Đảo ngược số
#include <iostream>
using namespace std;

int main(){
    int n;
    cout << "Nhap so nguyen n: ";
    cin >> n;

    int dao = 0;
    while (n > 0){
        int digit = n % 10;
        dao = dao * 10 + digit;
        n = n / 10;
    }
    cout << "So dao nguoc la: " << dao;

    return 0;
}