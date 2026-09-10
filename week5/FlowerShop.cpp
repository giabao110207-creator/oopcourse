#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

#define MAX 20

struct Flower
{
    string name;
    double price;
    int quantity;
    string type;
};

int main(){
int n;
cout << "How many flowers: " << endl;
cin >> n;

while (n < 1 || n > 20)
{
    cout << "Invalid number of flowers!" << endl;
    cout << "Please enter a number from 1 to 20." << endl;
    cout << "How many flowers? ";
    cin >> n;
}

Flower flowers[MAX];

for (int i = 0; i < n; i++)
{
    cout << "\nEnter information of flower " << i + 1 << endl;
    cout << "Enter name: ";
    cin >> flowers[i].name;
    cout << "Enter price: ";
    cin >> flowers[i].price;

    while (flowers[i].price <= 0)
    {
        cout << "Invalid price! Please enter a value > 0: ";
        cin >> flowers[i].price;
    }
    cout << "Enter quantity: ";
    cin >> flowers[i].quantity;

while (flowers[i].quantity < 0)
    {
        cout << "Invalid quantity! Please enter a value >= 0: ";
        cin >> flowers[i].quantity;
    }

    cout << "Enter type: ";
    cin >> flowers[i].type;
}

// 1. DISPLAY ALL FLOWERS
cout << endl;
cout << "===== DISPLAY ALL FLOWERS =====" << endl;

for (int i = 0; i < n; i++)
{
    cout << "Flower " << i + 1 << ": "
        << flowers[i].name << " - "
        << flowers[i].price << " - "
        << flowers[i].quantity << " - "
        << flowers[i].type << endl;
}






}