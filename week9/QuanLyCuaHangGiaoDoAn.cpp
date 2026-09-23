#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

#define MAX 100

struct  Food{
    string id;
    string name;
    double price;
    int quantity;
};

struct Order{
    string id;
    string customerName;
    string address;
    Food food;
    int quantity;
    string status;
};

struct Restaurant{
    string name;
    string address;
    string phone;
    Food foods[MAX];
    int foodCount;
    Order orders[MAX];
    int orderCount;
};

void inputRestaurant(Restaurant &r);
void addFood(Restaurant &r);
void showFoods(Restaurant r);
int findFoodById(Restaurant r, string id);
int findFoodByName(Restaurant r, string name);
void searchFood(Restaurant r);
void updateFood(Restaurant &r);
void createOrder(Restaurant &r);
void checkFood(Restaurant r);
double calculateOrderMoney(Order o);
void showOrders(Restaurant r);
int findOrderById(Restaurant r, string id);
void updateOrderStatus(Restaurant &r);
void calculateRevenue(Restaurant r);
void showRestaurant(Restaurant r);
void menu();

// MENU
void menu() {
    cout << "\n\n";
    cout << "=========================================\n";
    cout << "       QUAN LY CUA HANG GIAO DO AN\n";
    cout << "=========================================\n";

    cout << "1. Nhap thong tin cua hang\n";
    cout << "2. Them mon an moi\n";
    cout << "3. Hien thi danh sach mon an\n";
    cout << "4. Tim mon an theo ma hoac ten\n";
    cout << "5. Cap nhat gia hoac so luong mon an\n";
    cout << "6. Tao don hang moi\n";
    cout << "7. Kiem tra mon an\n";
    cout << "8. Tinh tong tien cua don hang\n";
    cout << "9. Hien thi danh sach don hang\n";
    cout << "10. Tim don hang theo ma\n";
    cout << "11. Cap nhat trang thai don hang\n";
    cout << "12. Thong ke tong doanh thu\n";
    cout << "0. Thoat\n";

    cout << "=========================================\n";
}

// 1. NHAP THONG TIN CUA HANG
void inputRestaurant(Restaurant &r) {
    cin.ignore();

    cout << "Nhap ten cua hang: ";
    getline(cin, r.name);

    cout << "Nhap dia chi: ";
    getline(cin, r.address);

    cout << "Nhap so dien thoai: ";
    getline(cin, r.phone);

    r.foodCount = 0;
    r.orderCount = 0;
}

int main(){
Restaurant restaurant;
int choice;
do {
    menu();
    cout << "Nhap lua chon: ";
    cin >> choice;

    switch (choice) {
        case 1:
            inputRestaurant(restaurant);
            break;
        case 2:
            addFood(restaurant);
            break;
        case 3:
            showFoods(restaurant);
            break;
        case 4:
            searchFood(restaurant);
            break;
        case 5:
            updateFood(restaurant);
            break;
        case 6:
            createOrder(restaurant);
            break;
        case 7:
            checkFood(restaurant);
            break;
        case 8:{
            string id;
            cin.ignore();
            cout << "Nhap ma don hang: ";
            getline(cin, id);
            int index = findOrderById(restaurant, id);
            if (index == -1) {
                cout << "Khong tim thay don hang!\n";
            }
            else {
                cout << "Tong tien don hang: " << calculateOrderMoney(restaurant.orders[index]) << " VND\n";
            }

            break;
        }
        case 9:
            showOrders(restaurant);
            break;
        case 10:{
            string id;
            cin.ignore();
            cout << "Nhap ma don hang: ";
            getline(cin, id);
            int index = findOrderById(restaurant, id);

            if (index == -1) {
                cout << "Khong tim thay don hang!\n";
            }
            else {
                cout << "\n===== THONG TIN DON HANG =====\n";
                cout << "Ma don: " << restaurant.orders[index].id << endl;
                cout << "Khach hang: " << restaurant.orders[index].customerName << endl;
                cout << "Dia chi: " << restaurant.orders[index].address << endl;
                cout << "Mon an: " << restaurant.orders[index].food.name << endl;
                cout << "So luong: " << restaurant.orders[index].quantity << endl;
                cout << "Trang thai: " << restaurant.orders[index].status << endl;
            }

            break;
        }
        case 11:
            updateOrderStatus(restaurant);
            break;
        case 12:
            calculateRevenue(restaurant);
            break;
        case 0:
            cout << "Ket thuc chuong trinh!\n";
            break;
        default:
            cout << "Lua chon khong hop le!\n";
        }
    } while (choice != 0);

    return 0;
}