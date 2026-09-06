//Bài 4: Kiểm tra n có phải số đối xứng hay không
#include <iostream>
using namespace std;

int main(){
    int n;
    cout << "Nhap so nguyen n: ";
    cin >> n;
    int original = n;
    int reversed = 0;
    while (n > 0){
        int digit = n % 10;
            reversed = reversed * 10 + digit;
            n = n/10;
    }
    if (original == reversed){
        cout << original << " la so doi xung: ";
    }else{
        cout << original << " khong phai la so doi xung: ";
      }
    return 0;
}
