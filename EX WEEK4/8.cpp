//Bài 8: Bội chung nhỏ nhất
#include <iostream>
using namespace std;

int main(){
    int a, b;
    cout <<"Nhap 2 so nguyen a va b: " << endl;
    cin >> a >> b;
    int original = a * b;
    while (b != 0){
        int temp = b;
        b = a % b;
        a = temp;
    }
    cout << "Boi chung nho nho nhat cua a va b la: " << original/a;

    return 0;
}