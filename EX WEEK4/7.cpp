//Bài 7: Ước chung lớn nhất
#include <iostream>
using namespace std;

int main(){
    int a, b;
    cout << "Nhap 2 so nguyen a va b: " << endl;
    cin >> a >> b;
    while (b != 0){
        int temp  = b;
        b = a % b;
        a = temp;
    }
    cout << "Uoc chung lon nhat cua a va b la: "<< a;
    return 0;
}