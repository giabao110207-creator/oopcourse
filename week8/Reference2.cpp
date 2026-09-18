#include <iostream>

using namespace std;

// ==================== SWAP BANG REFERENCE ====================
void swapReference(int& x, int& y)
{
    int temp = x;
    x = y;
    y = temp;
}

// ==================== SWAP BANG POINTER ====================
void swapPointer(int* x, int* y){
int temp = *x;
*x = *y;
*y = temp;
}

int main(){
int choice;

do{
    cout << "\n========== SWAP TWO NUMBERS ==========" << endl;
    cout << "1. Swap using Reference" << endl;
    cout << "2. Swap using Pointer" << endl;
    cout << "0. Exit" << endl;
    cout << "======================================" << endl;

    cout << "Enter your choice: ";
    cin >> choice;

    if (choice == 1){
        int a = 5;
        int b = 10;
        cout << "\n===== REFERENCE =====" << endl;
        cout << "Before: a = " << a;
        cout << ", b = " << b << endl;

        swapReference(a, b);

        cout << "After : a = " << a;
        cout << ", b = " << b << endl;
    }else if (choice == 2){
        int a = 5;
        int b = 10;

        cout << "\n===== POINTER =====" << endl;

        cout << "Before: a = " << a;
        cout << ", b = " << b << endl;

        swapPointer(&a, &b);

        cout << "After : a = " << a;
        cout << ", b = " << b << endl;
    }else if (choice == 0){
        cout << "Program ended!" << endl;
    }else{
        cout << "Invalid choice!" << endl;
    }

} while (choice != 0);

    return 0;
}