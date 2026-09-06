//Bài 3: Kiểm tra n có phải số hoàn hảo không
#include <iostream>
using namespace std;

int main(){
    int n;
    cout << "Nhap so nguyen n: ";
    cin >> n;
    int sum = 0;
    for (int i = 1; i < n; i++){
        if (n % i == 0){
            sum = sum + i;
        }
    }
    if (sum == n){
        cout << n << " la so hoan hao: ";
    }else{
        cout << n << " khong phai la so hoan hao: ";
    }
    return 0;
}