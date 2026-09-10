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

// 6. CALCULATE AVERAGE PRICE
double totalPrice = 0;

for (int i = 0; i < n; i++)
{
    totalPrice += flowers[i].price;
}
double averagePrice = totalPrice / n;

cout << endl;
cout << "===== AVERAGE PRICE =====" << endl;

cout << "Average price: "
     << averagePrice << endl;

// 7. COUNT FLOWERS BY TYPE
cout << endl;
cout << "===== COUNT FLOWERS BY TYPE =====" << endl;

for (int i = 0; i < n; i++)
{
    bool counted = false;

    for (int j = 0; j < i; j++)
    {
        if (flowers[i].type == flowers[j].type)
        {
            counted = true;
        }
    }

    if (counted == false)
    {
        int count = 0;
        for (int j = 0; j < n; j++)
        {
            if (flowers[j].type == flowers[i].type)
            {
                count++;
            }
        }

        cout << flowers[i].type
             << ": " << count << endl;
    }
}


// 8. FIND ALL FLOWERS OF A GIVEN TYPE
string type;

cout << endl;
cout << "===== FIND FLOWERS BY TYPE =====" << endl;

cout << "Enter type: ";
cin >> type;

for (int i = 0; i < n; i++)
{
    if (flowers[i].type == type)
    {
            cout << flowers[i].name << " - "
                 << flowers[i].price << " - "
                 << flowers[i].quantity << endl;
    }
}

// 9. SEARCH BY NAME
string name;
bool found = false;

cout << endl;
cout << "===== SEARCH BY NAME =====" << endl;

cout << "Enter flower name: ";
cin >> name;

for (int i = 0; i < n; i++)
{
    if (flowers[i].name == name)
    {
        cout << "Name: " << flowers[i].name << endl;
        cout << "Price: " << flowers[i].price << endl;
        cout << "Quantity: " << flowers[i].quantity << endl;
        cout << "Type: " << flowers[i].type << endl;

        found = true;
    }
}

if (found == false)
{
    cout << "Flower not found!" << endl;
}

// 10. CHECK IF A FLOWER EXISTS
string searchName;
bool exists = false;

cout << endl;
cout << "===== CHECK FLOWER EXISTS =====" << endl;

cout << "Enter flower name: ";
cin >> searchName;
for (int i = 0; i < n; i++)
{
    if (flowers[i].name == searchName)
    {
        exists = true;
    }
}

if (exists)
{
    cout << "Yes" << endl;
}
else
{
    cout << "No" << endl;
}

// 11. COUNT FLOWERS WITH LOW QUANTITY
int lowQuantity = 0;
for (int i = 0; i < n; i++)
{
    if (flowers[i].quantity < 5)
    {
        lowQuantity++;
    }
}
cout << endl;
cout << "===== LOW QUANTITY =====" << endl;
cout << "Flowers with quantity < 5: "
     << lowQuantity << endl;

// 12. COUNT FLOWERS IN A PRICE RANGE
double a, b;
int countRange = 0;

cout << endl;
cout << "===== COUNT FLOWERS IN A PRICE RANGE =====" << endl;
cout << "Enter minimum price: ";
cin >> a;
cout << "Enter maximum price: ";
cin >> b;
for (int i = 0; i < n; i++)
{
    if (flowers[i].price >= a &&
        flowers[i].price <= b)
    {
        countRange++;
    }
}

cout << "Flowers in range ["
        << a << ", " << b << "]: "
        << countRange << endl;

// 13. CALCULATE TOTAL VALUE
double totalValue = 0;

for (int i = 0; i < n; i++)
{
    totalValue += flowers[i].price * flowers[i].quantity;
}

cout << endl;
cout << "===== TOTAL VALUE =====" << endl;

cout << "Total value: "
     << totalValue << endl;


// 14. FIND THE MOST VALUABLE FLOWER
int mostValuable = 0;
for (int i = 1; i < n; i++)
{
    double value1 =
        flowers[i].price * flowers[i].quantity;
    double value2 = flowers[mostValuable].price * flowers[mostValuable].quantity;
    if (value1 > value2)
    {
        mostValuable = i;
    }
}
cout << endl;
cout << "===== MOST VALUABLE FLOWER =====" << endl;

cout << "Name: "
        << flowers[mostValuable].name << endl;

cout << "Price: "
        << flowers[mostValuable].price << endl;

cout << "Quantity: "
        << flowers[mostValuable].quantity << endl;

cout << "Value: "
        << flowers[mostValuable].price * flowers[mostValuable].quantity
        << endl;

}