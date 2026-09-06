//Bài 9: Tính lũy thừa x^n
#include <iostream>
using namespace std;

int main(){
    int x, n;
    cout << "Nhap 2 so nguyen x va n: ";
    cin >> x >> n;
    int result = 1;
    for (int i = 1; i <= n; i++){
        result *= x;
    }
    cout << x << "^" << n << " = " << result;
    return 0;
}