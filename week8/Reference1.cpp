#include <iostream>

using namespace std;

int main()
{
    // Bước 1: Tạo biến x có giá trị 10
    int x = 10;

    // Bước 2: Tạo reference rx tham chiếu đến x
    int& rx = x;

    // Bước 3: Thay đổi giá trị thông qua reference
    rx = 20;

    // Bước 4: In giá trị của x và rx
    cout << "x = " << x << endl;
    cout << "rx = " << rx << endl;

    return 0;
}