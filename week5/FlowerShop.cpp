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

// 2. FIND THE MOST EXPENSIVE FLOWER
int maxPrice = 0;

for (int i = 1; i < n; i++)
{
    if (flowers[i].price > flowers[maxPrice].price)
    {
        maxPrice = i;
    }
}

cout << endl;
cout << "===== MOST EXPENSIVE FLOWER =====" << endl;

cout << "Name: " << flowers[maxPrice].name << endl;
cout << "Price: " << flowers[maxPrice].price << endl;
cout << "Quantity: " << flowers[maxPrice].quantity << endl;
cout << "Type: " << flowers[maxPrice].type << endl;

// 3. FIND THE CHEAPEST FLOWER
int minPrice = 0;
for (int i = 1; i < n; i++)
{
    if (flowers[i].price < flowers[minPrice].price)
    {
        minPrice = i;
    }
}

cout << endl;
cout << "===== CHEAPEST FLOWER =====" << endl;
cout << "Name: " << flowers[minPrice].name << endl;
cout << "Price: " << flowers[minPrice].price << endl;

// 4. FIND THE FLOWER WITH THE LARGEST QUANTITY
int maxQuantity = 0;

for (int i = 1; i < n; i++)
{
    if (flowers[i].quantity > flowers[maxQuantity].quantity)
    {
        maxQuantity = i;
    }
}
cout << endl;
cout << "===== LARGEST QUANTITY =====" << endl;
cout << "Name: " << flowers[maxQuantity].name << endl;
cout << "Quantity: " << flowers[maxQuantity].quantity << endl;

// 5. CALCULATE TOTAL QUANTITY
int totalQuantity = 0;
for (int i = 0; i < n; i++)
{
    totalQuantity += flowers[i].quantity;
}

cout << endl;
cout << "===== TOTAL QUANTITY =====" << endl;
cout << "Total quantity: "
     << totalQuantity << endl;


}