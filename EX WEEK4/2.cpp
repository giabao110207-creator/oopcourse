//Bài 2: Tính n!
#include <iostream>
using namespace std;

int main(){
    int n;
    cout << "Nhap so nguyen n: ";
    cin >> n;
    int factorial = 1;
    for (int i =1; i <= n; i++){
        factorial *= i;
    }
    cout << "Giai thua cua "<< n << " la :"<< factorial;

    return 0;

}