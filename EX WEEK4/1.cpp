//Bài 1: Tìm số lớn nhất trong 3 số a, b, c
#include <iostream>
using namespace std;

int main(){
    int a, b, c;
    cout << "Nhap 3 so nguyen a, b, c:";
    cin >> a >> b >> c;
    int max = a;
    if (b > max){
        max = b;
    }
    if (c > max){
        max = c;
    }
    cout << "So lon nhat trong 3 so la: " << max;

    return 0;
}

