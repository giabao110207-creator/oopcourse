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

// TASK 7
// COUNT FLOWERS BY TYPE
countFlowersByType(flowers, n);
// TASK 8
// FIND ALL FLOWERS OF A GIVEN TYPE
findFlowersByType(flowers, n);
// TASK 9
// SEARCH BY NAME
searchByName(flowers, n);
// TASK 10
// CHECK IF A FLOWER EXISTS
checkFlowerExists(flowers, n);
// TASK 11
// COUNT FLOWERS WITH LOW QUANTITY
int lowQuantity = countLowQuantity(flowers, n);
cout << endl;
cout << "===== TASK 11: LOW QUANTITY =====" << endl;
cout << "Flowers with quantity < 5: " << lowQuantity << endl;
// TASK 12
// COUNT FLOWERS IN A PRICE RANGE
double a, b;
cout << endl;
cout << "===== TASK 12: PRICE RANGE =====" << endl;
cout << "Enter minimum price: ";
cin >> a;
cout << "Enter maximum price: ";
cin >> b;
int countRange = countFlowersInPriceRange(flowers, n, a, b);
cout << "Flowers in range ["<< a << ", " << b << "]: " << countRange << endl;
// TASK 13
// CALCULATE TOTAL VALUE
double totalValue = calculateTotalValue(flowers, n);
cout << endl;
cout << "===== TASK 13: TOTAL VALUE =====" << endl;
cout << "Total value: " << totalValue << endl;
// TASK 14
// FIND THE MOST VALUABLE FLOWER
int mostValuable = findMostValuable(flowers, n);
cout << endl;
cout << "===== TASK 14: MOST VALUABLE FLOWER =====" << endl;
cout << "Name: " << flowers[mostValuable].name << endl;
cout << "Price: " << flowers[mostValuable].price << endl;
cout << "Quantity: " << flowers[mostValuable].quantity << endl;
cout << "Value: " << flowers[mostValuable].price *
flowers[mostValuable].quantity << endl;
// TASK 15
// SORT FLOWERS BY PRICE ASCENDING
sortByPriceAscending(flowers, n);
// TASK 16
// SORT FLOWERS BY NAME
sortByName(flowers, n);
// TASK 17
// FIND TOP 3 MOST EXPENSIVE FLOWERS
findTop3MostExpensive(flowers, n);
// TASK 18
// FIND FLOWERS WITH NAME CONTAINING KEYWORD
searchByKeyword(flowers, n);
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

// TASK 7
// COUNT FLOWERS BY TYPE
// =====================================================

void countFlowersByType(Flower flowers[], int n){
cout << endl;
cout << "===== TASK 7: COUNT FLOWERS BY TYPE =====" << endl;
for (int i = 0; i < n; i++){
    bool counted = false;
    for (int j = 0; j < i; j++){
        if (flowers[i].type == flowers[j].type){
                counted = true;
        }
    }
    if (counted == false){
        int count = 0;
        for (int j = 0; j < n; j++){
            if (flowers[j].type == flowers[i].type){
                count++;
            }
        }
        cout << flowers[i].type << ": " << count << endl;
        }
    }
}

// TASK 8
// FIND FLOWERS BY TYPE
void findFlowersByType(Flower flowers[], int n){
string type;
cout << endl;
cout << "===== TASK 8: FIND FLOWERS BY TYPE =====" << endl;
cout << "Enter type: ";
cin >> type;
for (int i = 0; i < n; i++){
    if (flowers[i].type == type){
    cout << flowers[i].name << " - " << flowers[i].price << " - " << flowers[i].quantity << endl;
        }
    }
}

// TASK 9
// SEARCH BY NAME
// =====================================================

void searchByName(Flower flowers[], int n){
string name;
bool found = false;
cout << endl;
cout << "===== TASK 9: SEARCH BY NAME =====" << endl;
cout << "Enter flower name: ";
cin >> name;
for (int i = 0; i < n; i++){
    if (flowers[i].name == name){
    cout << "Name: " << flowers[i].name << endl;
    cout << "Price: " << flowers[i].price << endl;
    cout << "Quantity: " << flowers[i].quantity << endl;
    cout << "Type: " << flowers[i].type << endl;
        found = true;
    }
}if (found == false){
    cout << "Flower not found!" << endl;
}
}

// TASK 10
// CHECK IF A FLOWER EXISTS
void checkFlowerExists(Flower flowers[], int n){
string searchName;
bool exists = false;
cout << endl;
cout << "===== TASK 10: CHECK FLOWER EXISTS =====" << endl;
cout << "Enter flower name: ";
cin >> searchName;

for (int i = 0; i < n; i++){
    if (flowers[i].name == searchName){
        exists = true;
    }
}
if (exists){
    cout << "Yes" << endl;
}else{
    cout << "No" << endl;
}
}

// TASK 11
// COUNT FLOWERS WITH LOW QUANTITY
int countLowQuantity(Flower flowers[], int n){
int lowQuantity = 0;
for (int i = 0; i < n; i++){
    if (flowers[i].quantity < 5){
        lowQuantity++;
    }
}
return lowQuantity;
}

// TASK 12
// COUNT FLOWERS IN PRICE RANGE
// =====================================================

int countFlowersInPriceRange(Flower flowers[], int n, double a, double b){
int countRange = 0;
for (int i = 0; i < n; i++){
    if (flowers[i].price >= a && flowers[i].price <= b){
        countRange++;
    }
}
return countRange;
}

// TASK 13
// CALCULATE TOTAL VALUE
double calculateTotalValue(Flower flowers[], int n){
double totalValue = 0;
for (int i = 0; i < n; i++){
    totalValue += flowers[i].price * flowers[i].quantity;
}
return totalValue;
}

// TASK 14
// FIND MOST VALUABLE FLOWER
int findMostValuable(Flower flowers[], int n){
int mostValuable = 0;
for (int i = 1; i < n; i++){
    double value1 = flowers[i].price * flowers[i].quantity;
    double value2 = flowers[mostValuable].price * flowers[mostValuable].quantity;
    if (value1 > value2){
        mostValuable = i;
    }
}

    return mostValuable;
}

// TASK 15
// SORT BY PRICE ASCENDING
void sortByPriceAscending(Flower flowers[], int n){
cout << endl;
cout << "===== TASK 15: SORT BY PRICE ASCENDING =====" << endl;
for (int i = 0; i < n - 1; i++){
    int minPos = i;
    for (int j = i + 1; j < n; j++){
        if (flowers[j].price < flowers[minPos].price){
        minPos = j;
        }
    }
    Flower temp = flowers[i];
    flowers[i] = flowers[minPos];
    flowers[minPos] = temp;
    }
    for (int i = 0; i < n; i++){
    cout << flowers[i].name << " - " << flowers[i].price << endl;
    }
}

// TASK 16
// SORT BY NAME A -> Z
// =====================================================

void sortByName(Flower flowers[], int n){
cout << endl;
cout << "===== TASK 16: SORT BY NAME =====" << endl;

for (int i = 0; i < n - 1; i++){
    int minPos = i;

    for (int j = i + 1; j < n; j++){
        if (flowers[j].name < flowers[minPos].name){
            minPos = j;
        }
    }

    Flower temp = flowers[i];
    flowers[i] = flowers[minPos];
    flowers[minPos] = temp;
    }

    for (int i = 0; i < n; i++){
        cout << flowers[i].name << endl;
    }
}

// TASK 17
// FIND TOP 3 MOST EXPENSIVE FLOWERS
// =====================================================

void findTop3MostExpensive(Flower flowers[], int n){
cout << endl;
cout << "===== TASK 17: TOP 3 MOST EXPENSIVE =====" << endl;

for (int i = 0; i < n - 1; i++){
    for (int j = i + 1; j < n; j++){
        if (flowers[i].price < flowers[j].price){
            Flower temp = flowers[i];
            flowers[i] = flowers[j];
            flowers[j] = temp;
        }
    }
}
int top = 3;
if (n < 3){
    top = n;
}
for (int i = 0; i < top; i++){
    cout << i + 1 << ". " << flowers[i].name << " - " << flowers[i].price << endl;
    }
}

// TASK 18
// SEARCH BY KEYWORD
// =====================================================

void searchByKeyword(Flower flowers[], int n){
string keyword;
cout << endl;
cout << "===== TASK 18: SEARCH BY KEYWORD =====" << endl;

cout << "Enter keyword: ";
cin >> keyword;
for (int i = 0; i < n; i++){
    if (flowers[i].name.find(keyword) != string::npos){
        cout << flowers[i].name << endl;
    }
}
}