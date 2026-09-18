#include <iostream>

using namespace std;

void setFirstToZero(int arr[])
{
    arr[0] = 0;
}

void incrementAll(int (&arr)[4])
{
    for (int i = 0; i < 4; i++)
    {
        arr[i] += 1;
    }
}

void setLastToTen(int& x)
{
    x = 10;
}

int main()
{
    int nums[4] = {1, 2, 3, 4};
    cout << "===== PRACTICE 5 =====" << endl;
    // Gọi hàm đổi phần tử đầu tiên thành 0
    setFirstToZero(nums);
    // Tăng tất cả phần tử lên 1
    incrementAll(nums);
    // In mảng
    cout << "Final array: ";
    for (int i = 0; i < 4; i++)
    {
        cout << nums[i] << " ";
    }
    cout << endl;
    int nums2[4] = {3, 5, 7, 9};
    cout << "\n===== VARIATION =====" << endl;
    // Truyền phần tử cuối bằng reference
    setLastToTen(nums2[3]);

    cout << "Final array: ";

    for (int i = 0; i < 4; i++)
    {
        cout << nums2[i] << " ";
    }

    cout << endl;

return 0;
}