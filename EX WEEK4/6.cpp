//Bài 6: Đếm chữ số
#include <iostream>
using namespace std;

int main(){
    int n;
    cout << " Nhap so nguyen n:";
    cin >> n;
    int count = 0;
    while(n > 0){
        int digit = n % 10;
        count = count + digit;
        n = n / 10;
    }
    cout << "Tong cac chu so cua n la: " << count;
    return 0;
}