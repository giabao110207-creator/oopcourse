#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <cctype>

using namespace std;

#define MAX 100
struct FOOD {
    string id;
    string name;
    double price;
    int quantity;

    void inputInfo() {
        cout << "Enter food ID: ";
        cin >> id;
        cin.ignore();
        cout << "Enter food name: ";
        getline(cin, name);
        cout << "Enter price: ";
        cin >> price;
        cout << "Enter quantity: ";
        cin >> quantity;
    }

    void outputInfo() {
        cout << "ID       : " << id << endl;
        cout << "Name     : " << name << endl;
        cout << "Price    : " << price << endl;
        cout << "Quantity : " << quantity << endl;
    }
};

struct ORDER {
    string id;
    string customerName;
    string phone;
    string address;
    FOOD food;
    int quantity;
    string status;
    void outputInfo() {
        cout << "-----------------------------" << endl;
        cout << "Order ID       : " << id << endl;
        cout << "Customer       : " << customerName << endl;
        cout << "Phone          : " << phone << endl;
        cout << "Address        : " << address << endl;
        cout << "Food           : " << food.name << endl;
        cout << "Quantity       : " << quantity << endl;
        cout << "Status         : " << status << endl;
    }
};
struct RESTAURANT {
    string name;
    string address;
    string phone;
    FOOD foods[MAX];
    int foodCount = 0;
    ORDER orders[MAX];
    int orderCount = 0;

    // BÀI 1: NHẬP VÀ HIỂN THỊ TÊN CỬA HÀNG
    void inputRestaurantName() {
        cout << "Enter restaurant name: ";
        getline(cin, name);

        cout << "Chao mung den voi [" << name << "]!" << endl;
    }

    // BÀI 2: CHUẨN HÓA TÊN MÓN ĂN
    string normalizeFoodName(string s) {
        // Xóa khoảng trắng đầu
        while (!s.empty() && s[0] == ' ') {
            s.erase(0, 1);
        }
        // Xóa khoảng trắng cuối
        while (!s.empty() && s[s.length() - 1] == ' ') {
            s.erase(s.length() - 1, 1);
        }
        // Xóa khoảng trắng thừa ở giữa
        string result = "";
        bool space = false;
        for (char c : s) {
            if (c == ' ') {
                if (!space) {
                    result += c;
                    space = true;
                }
            }
            else {
                result += c;
                space = false;
            }
        }

        // Viết hoa chữ cái đầu mỗi từ
        bool firstLetter = true;
        for (int i = 0; i < result.length(); i++) {
            if (result[i] == ' ') {
                firstLetter = true;
            }
            else {
                if (firstLetter) {
                    result[i] = toupper(result[i]);
                    firstLetter = false;
                }
                else {
                    result[i] = tolower(result[i]);
                }
            }
        }

        return result;
    }

    // BÀI 3: TẠO MÃ ĐƠN HÀNG
    string createOrderID(string customerName, string phone) {
        string code = "DH";
        // Lấy chữ cái đầu của tên khách hàng
        stringstream ss(customerName);
        string word;
        while (ss >> word) {
            code += toupper(word[0]);
        }
        // Lấy 4 số cuối của số điện thoại
        if (phone.length() >= 4) {
            code += phone.substr(phone.length() - 4);
        }
        else {
            code += phone;
        }
        return code;
    }

    // BÀI 4: KIỂM TRA MÓN ĂN
    void checkFood() {

        string foodName;

        cin.ignore();

        cout << "Enter food name: ";
        getline(cin, foodName);

        bool found = false;

        for (int i = 0; i < foodCount; i++) {

            if (foods[i].name == foodName) {
                cout << "Mon an co trong menu!" << endl;
                found = true;
                break;
            }
        }

        if (!found) {
            cout << "Mon an khong co trong menu!" << endl;
        }
    }


    // ==========================================
    // THÊM MÓN ĂN
    // ==========================================
    void addFood() {

        if (foodCount >= MAX) {
            cout << "Menu is full!" << endl;
            return;
        }

        foods[foodCount].inputInfo();

        // Chuẩn hóa tên món ăn
        foods[foodCount].name =
            normalizeFoodName(foods[foodCount].name);

        foodCount++;

        cout << "Add food successfully!" << endl;
    }


    // ==========================================
    // HIỂN THỊ MENU
    // ==========================================
    void displayFoods() {

        cout << "\n========== MENU ==========" << endl;

        for (int i = 0; i < foodCount; i++) {
            cout << "\nFood " << i + 1 << endl;
            foods[i].outputInfo();
        }
    }


    // ==========================================
    // TÌM MÓN ĂN
    // ==========================================
    int findFood(string name) {

        for (int i = 0; i < foodCount; i++) {

            if (foods[i].name == name) {
                return i;
            }
        }

        return -1;
    }


    // ==========================================
    // TẠO ĐƠN HÀNG
    // ==========================================
    void createOrder() {

        if (orderCount >= MAX) {
            cout << "Order list is full!" << endl;
            return;
        }

        ORDER newOrder;

        cin.ignore();

        // Nhập tên khách hàng
        cout << "Enter customer name: ";
        getline(cin, newOrder.customerName);

        // Nhập số điện thoại
        cout << "Enter phone: ";
        getline(cin, newOrder.phone);

        // Nhập địa chỉ
        cout << "Enter address: ";
        getline(cin, newOrder.address);

        // Nhập tên món
        string foodName;

        cout << "Enter food name: ";
        getline(cin, foodName);

        int index = findFood(foodName);

        if (index == -1) {
            cout << "Food not found!" << endl;
            return;
        }

        newOrder.food = foods[index];

        cout << "Enter quantity: ";
        cin >> newOrder.quantity;

        cin.ignore();

        cout << "Enter status: ";
        getline(cin, newOrder.status);

        // BÀI 3
        newOrder.id =
            createOrderID(newOrder.customerName, newOrder.phone);

        orders[orderCount] = newOrder;
        orderCount++;

        cout << "\nOrder created successfully!" << endl;
        cout << "Order ID: " << newOrder.id << endl;
    }


    // ==========================================
    // BÀI 6: THAY ĐỔI TRẠNG THÁI ĐƠN HÀNG
    // ==========================================
    void changeOrderStatus() {

        string id;
        string newStatus;

        cin.ignore();

        cout << "Enter order ID: ";
        getline(cin, id);

        cout << "Enter new status ";
        cout << "(Dang chuan bi / Dang giao / Hoan thanh / Da huy): ";
        getline(cin, newStatus);

        for (int i = 0; i < orderCount; i++) {

            if (orders[i].id == id) {

                orders[i].status = newStatus;

                cout << "Cap nhat trang thai thanh cong!" << endl;
                return;
            }
        }

        cout << "Khong tim thay don hang!" << endl;
    }


    // ==========================================
    // BÀI 7: TÌM ĐƠN HÀNG THEO TÊN KHÁCH HÀNG
    // ==========================================
    void findOrdersByCustomer() {

        string keyword;

        cin.ignore();

        cout << "Enter customer name: ";
        getline(cin, keyword);

        bool found = false;

        for (int i = 0; i < orderCount; i++) {

            string customer = orders[i].customerName;

            // Chuyển cả 2 về chữ thường
            transform(customer.begin(),
                      customer.end(),
                      customer.begin(),
                      ::tolower);

            string key = keyword;

            transform(key.begin(),
                      key.end(),
                      key.begin(),
                      ::tolower);

            // Tìm chuỗi con
            if (customer.find(key) != string::npos) {

                orders[i].outputInfo();

                found = true;
            }
        }

        if (!found) {
            cout << "Khong tim thay don hang!" << endl;
        }
    }


    // ==========================================
    // BÀI 9: THỐNG KÊ MÓN ĂN BÁN CHẠY
    // ==========================================
    void statisticFood() {

        string foodName;

        cin.ignore();

        cout << "Enter food name: ";
        getline(cin, foodName);

        int count = 0;

        for (int i = 0; i < orderCount; i++) {

            if (orders[i].food.name == foodName) {
                count++;
            }
        }

        cout << "Mon [" << foodName << "] da xuat hien trong "
             << count << " don hang." << endl;
    }


    // ==========================================
    // BÀI 10: TẠO THÔNG BÁO GIAO HÀNG
    // ==========================================
    void createDeliveryNotification() {

        string customerName;
        string orderID;
        string address;

        cin.ignore();

        cout << "Enter customer name: ";
        getline(cin, customerName);

        cout << "Enter order ID: ";
        getline(cin, orderID);

        cout << "Enter address: ";
        getline(cin, address);

        cout << "\n========== DELIVERY NOTIFICATION =========="
             << endl;

        cout << "Don hang [" << orderID << "] cua "
             << customerName
             << " dang duoc giao den ["
             << address << "]. Cam on ban!" << endl;
    }


    // ==========================================
    // HIỂN THỊ ĐƠN HÀNG
    // ==========================================
    void displayOrders() {

        cout << "\n========== ORDERS ==========" << endl;

        if (orderCount == 0) {
            cout << "Chua co don hang!" << endl;
            return;
        }

        for (int i = 0; i < orderCount; i++) {
            orders[i].outputInfo();
        }
    }
};


// ==========================================
// MAIN
// ==========================================
int main() {

    RESTAURANT restaurant;

    cout << "======================================" << endl;
    cout << "     FOOD DELIVERY MANAGEMENT" << endl;
    cout << "======================================" << endl;

    // BÀI 1
    restaurant.inputRestaurantName();

    int choice;

    do {

        cout << "\n============== MENU ==============" << endl;

        cout << "1. Them mon an" << endl;
        cout << "2. Hien thi menu" << endl;
        cout << "3. Tao don hang" << endl;
        cout << "4. Kiem tra mon an" << endl;
        cout << "5. Thay doi trang thai don hang" << endl;
        cout << "6. Tim don hang theo ten khach hang" << endl;
        cout << "7. Thong ke mon an ban chay" << endl;
        cout << "8. Tao thong bao giao hang" << endl;
        cout << "9. Hien thi don hang" << endl;
        cout << "0. Thoat" << endl;

        cout << "Nhap lua chon: ";
        cin >> choice;

        switch (choice) {

        case 1:
            restaurant.addFood();
            break;

        case 2:
            restaurant.displayFoods();
            break;

        case 3:
            restaurant.createOrder();
            break;

        case 4:
            restaurant.checkFood();
            break;

        case 5:
            restaurant.changeOrderStatus();
            break;

        case 6:
            restaurant.findOrdersByCustomer();
            break;

        case 7:
            restaurant.statisticFood();
            break;

        case 8:
            restaurant.createDeliveryNotification();
            break;

        case 9:
            restaurant.displayOrders();
            break;

        case 0:
            cout << "Thoat chuong trinh!" << endl;
            break;

        default:
            cout << "Lua chon khong hop le!" << endl;
        }

    } while (choice != 0);

    return 0;
}