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

void inputFlowers(Flower flowers[], int n);
void displayFlowers(Flower flowers[], int n);
int findMostExpensive(Flower flowers[], int n);
int findCheapest(Flower flowers[], int n);
int findLargestQuantity(Flower flowers[], int n);
int calculateTotalQuantity(Flower flowers[], int n);
double calculateAveragePrice(Flower flowers[], int n);
void countFlowersByType(Flower flowers[], int n);
void findFlowersByType(Flower flowers[], int n);
void searchByName(Flower flowers[], int n);
void checkFlowerExists(Flower flowers[], int n);
int countLowQuantity(Flower flowers[], int n);
int countFlowersInRange(Flower flowers[], int n, double a, double b);
double calculateTotalValue(Flower flowers[], int n);
int findMostValuable(Flower flowers[], int n);
void sortByPriceAscending(Flower flowers[], int n);
void sortByName(Flower flowers[], int n);
void findTop3Expensive(Flower flowers[], int n);
void searchByKeyword(Flower flowers[], int n);
void averageQuantityByType(Flower flowers[], int n);
void simpleReport(Flower flowers[], int n);

int main(){
int n;
cout << "How many flowers: " << endl;
cin >> n;
while (n < 1 || n > 20){
    cout << "Invalid number of flowers!" << endl;
    cout << "Please enter a number from 1 to 20." << endl;
    cout << "How many flowers? ";
    cin >> n;
}
Flower flowers[MAX];
inputFlowers(flowers, n);

// TASK 1
displayAllFlowers(flowers, n);

// TASK 2
// FIND THE MOST EXPENSIVE FLOWER
int maxPrice = findMostExpensive(flowers, n);
cout << endl;
cout << "===== TASK 2: MOST EXPENSIVE FLOWER =====" << endl;
cout << "Name: " << flowers[maxPrice].name << endl;
cout << "Price: " << flowers[maxPrice].price << endl;
cout << "Quantity: " << flowers[maxPrice].quantity << endl;
cout << "Type: " << flowers[maxPrice].type << endl;
}

void inputFlowers(Flower flowers[], int n){
for (int i = 0; i < n; i++){
    cout << "\nEnter information of flower " << i + 1 << endl;
    cout << "Enter name: ";
    cin >> flowers[i].name;

    cout << "Enter price: ";
    cin >> flowers[i].price;
    while (flowers[i].price <= 0){
        cout << "Invalid price! " << "Please enter a value > 0: ";
            cin >> flowers[i].price;
    }

    cout << "Enter quantity: ";
    cin >> flowers[i].quantity;
    while (flowers[i].quantity < 0){
            cout << "Invalid quantity! " << "Please enter a value >= 0: ";
            cin >> flowers[i].quantity;
    }
        cout << "Enter type: ";
        cin >> flowers[i].type;
    }

// TASK 3
// FIND THE CHEAPEST FLOWER
int minPrice = findCheapest(flowers, n);

cout << endl;
cout << "===== TASK 3: CHEAPEST FLOWER =====" << endl;
cout << "Name: " << flowers[minPrice].name << endl;
cout << "Price: " << flowers[minPrice].price << endl;

// TASK 4
// FIND THE FLOWER WITH THE LARGEST QUANTITY
int maxQuantity = findLargestQuantity(flowers, n);
cout << endl;
cout << "===== TASK 4: LARGEST QUANTITY =====" << endl;
cout << "Name: " << flowers[maxQuantity].name << endl;
cout << "Quantity: " << flowers[maxQuantity].quantity << endl;

// TASK 5
// CALCULATE TOTAL QUANTITY
int totalQuantity = calculateTotalQuantity(flowers, n);
cout << endl;
cout << "===== TASK 5: TOTAL QUANTITY =====" << endl;
cout << "Total quantity: " << totalQuantity << endl;

// TASK 6
// CALCULATE AVERAGE PRICE
double averagePrice = calculateAveragePrice(flowers, n);
cout << endl;
cout << "===== TASK 6: AVERAGE PRICE =====" << endl;
cout << "Average price: " << averagePrice << endl;
}

// TASK 1
// DISPLAY ALL FLOWERS
void displayAllFlowers(Flower flowers[], int n){
cout << endl;
cout << "===== TASK 1: DISPLAY ALL FLOWERS ====="
        << endl;

for (int i = 0; i < n; i++){
    cout << "Flower " << i + 1 << ": "
        << flowers[i].name << " - "
        << flowers[i].price << " - "
        << flowers[i].quantity << " - "
        << flowers[i].type << endl;
}
}

// TASK 2
// FIND MOST EXPENSIVE FLOWER
int findMostExpensive(Flower flowers[], int n){
int maxPrice = 0;
for (int i = 1; i < n; i++){
        if (flowers[i].price > flowers[maxPrice].price){
            maxPrice = i;
        }
}

return maxPrice;
}

// TASK 3
// FIND CHEAPEST FLOWER
int findCheapest(Flower flowers[], int n){
int minPrice = 0;
for (int i = 1; i < n; i++){
    if (flowers[i].price < flowers[minPrice].price){
        minPrice = i;
    }
}
return minPrice;
}

// TASK 4
// FIND LARGEST QUANTITY
int findLargestQuantity(Flower flowers[], int n){
int maxQuantity = 0;
for (int i = 1; i < n; i++){
    if (flowers[i].quantity > flowers[maxQuantity].quantity){
        maxQuantity = i;
    }
}
 return maxQuantity;
}

// TASK 5
// CALCULATE TOTAL QUANTITY
int calculateTotalQuantity(Flower flowers[], int n){
int totalQuantity = 0;
for (int i = 0; i < n; i++){
    totalQuantity += flowers[i].quantity;
}
return totalQuantity;
}

// TASK 6
// CALCULATE AVERAGE PRICE
double calculateAveragePrice(Flower flowers[], int n){
double totalPrice = 0;
for (int i = 0; i < n; i++){
    totalPrice += flowers[i].price;
}
double averagePrice = totalPrice / n;
return averagePrice;
}