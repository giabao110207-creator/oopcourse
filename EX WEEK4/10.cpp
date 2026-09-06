//Bài 10: Đếm số lượng ước của n
#include <iostream>
using namespace std;

int main(){
    int n;
    cout <<" Nhap so nguyen n: ";
    cin >> n;
    int count = 0;
    for (int i = 1; i <= n; i++){
        if (n % i == 0){
            count++;
        }
    }
    cout << "So luong uoc cua n la: " << count << endl;

    return 0;
}