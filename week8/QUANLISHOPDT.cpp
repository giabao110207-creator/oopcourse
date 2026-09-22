#include <iostream>
#include <string>
using namespace std;

#define MAX_MOBILE 100
#define MAX_ORDER 100
#define MAX_ITEM 20

struct Mobile{
    string id;
    string brand;
    string version;
    string series;
    int year;
    double price;
    int quantity;
};

struct OrderItem{
    string mobileId;
    int quantity;
};

struct Order{
    string id;
    string customerName;

    int day;
    int month;
    int year;

    OrderItem items[MAX_ITEM];
    int nItem;

    bool status; // true = đã thanh toán, false = chưa thanh toán
};

struct Shop{
    string shopName;
    string address;
    string phone;

    Mobile mobiles[MAX_MOBILE];
    int nMobile;

    Order orders[MAX_ORDER];
    int nOrder;
};

// 1. THÊM MỚI ĐIỆN THOẠI
void addMobile(Shop &shop){
    if (shop.nMobile >= MAX_MOBILE){
        cout << "Danh sach dien thoai da day!\n";
        return;
    }

    Mobile m;
    cout << "\n===== THEM DIEN THOAI =====\n";
    cout << "Nhap ID dien thoai: ";
    cin >> m.id;

    // Kiem tra ID da ton tai chua
    for (int i = 0; i < shop.nMobile; i++){
        if (shop.mobiles[i].id == m.id){
            cout << "ID dien thoai da ton tai!\n";
            return;
        }
    }

    cin.ignore();
    cout << "Nhap hang: ";
    getline(cin, m.brand);
    cout << "Nhap phien ban: ";
    getline(cin, m.version);
    cout << "Nhap series: ";
    getline(cin, m.series);
    cout << "Nhap nam san xuat: ";
    cin >> m.year;
    cout << "Nhap gia ban: ";
    cin >> m.price;
    cout << "Nhap so luong: ";
    cin >> m.quantity;
    shop.mobiles[shop.nMobile] = m;
    shop.nMobile++;

    cout << "Them dien thoai thanh cong!\n";
}

// 2. XOA DIEN THOAI
void deleteMobile(Shop &shop){
    string id;
    cout << "\n===== XOA DIEN THOAI =====\n";
    cout << "Nhap ID dien thoai can xoa: ";
    cin >> id;

    int pos = -1;
    for (int i = 0; i < shop.nMobile; i++){
        if (shop.mobiles[i].id == id){
            pos = i;
            break;
        }
    }

    if (pos == -1){
        cout << "Khong tim thay dien thoai!\n";
        return;
    }

    // Dich cac phan tu phia sau len 1 vi tri
    for (int i = pos; i < shop.nMobile - 1; i++){
        shop.mobiles[i] = shop.mobiles[i + 1];
    }
    shop.nMobile--;

    cout << "Xoa dien thoai thanh cong!\n";
}

// HAM TIM DIEN THOAI THEO ID
int findMobile(Shop &shop, string id){
    for (int i = 0; i < shop.nMobile; i++){
        if (shop.mobiles[i].id == id){
            return i;
        }
    }

    return -1;
}

// 3. TAO MOI ORDER
void createOrder(Shop &shop){
    if (shop.nOrder >= MAX_ORDER){
        cout << "Danh sach order da day!\n";
        return;
    }

    Order o;
    cout << "\n===== TAO ORDER =====\n";
    cout << "Nhap ID order: ";
    cin >> o.id;
    // Kiem tra ID order trung
    for (int i = 0; i < shop.nOrder; i++){
        if (shop.orders[i].id == o.id){
            cout << "ID order da ton tai!\n";
            return;
        }
    }
    cin.ignore();
    cout << "Nhap ten khach hang: ";
    getline(cin, o.customerName);
    cout << "Nhap ngay: ";
    cin >> o.day;
    cout << "Nhap thang: ";
    cin >> o.month;
    cout << "Nhap nam: ";
    cin >> o.year;
    cout << "Nhap so luong mat hang trong order: ";
    cin >> o.nItem;

    if (o.nItem > MAX_ITEM){
        cout << "So luong mat hang qua lon!\n";
        return;
    }

    for (int i = 0; i < o.nItem; i++){
        cout << "\nMat hang thu " << i + 1 << endl;

        cout << "Nhap ID dien thoai: ";
        cin >> o.items[i].mobileId;

        int pos = findMobile(shop, o.items[i].mobileId);

        if (pos == -1){
            cout << "Khong tim thay dien thoai!\n";
            i--;
            continue;
        }

        cout << "Nhap so luong: ";
        cin >> o.items[i].quantity;

        // Kiem tra ton kho
        if (o.items[i].quantity > shop.mobiles[pos].quantity){
            cout << "Khong du hang trong kho!\n";
            i--;
            continue;
        }

        // Tru so luong trong kho
        shop.mobiles[pos].quantity -= o.items[i].quantity;
    }

    cout << "Trang thai thanh toan (1: Da thanh toan, 0: Chua thanh toan): ";
    cin >> o.status;

    shop.orders[shop.nOrder] = o;
    shop.nOrder++;

    cout << "\nTao order thanh cong!\n";
}

// HAM TIM ORDER THEO ID
int findOrder(Shop &shop, string id){
    for (int i = 0; i < shop.nOrder; i++){
        if (shop.orders[i].id == id){
            return i;
        }
    }

    return -1;
}

// 4. CHINH SUA ORDER
void editOrder(Shop &shop){
    string id;

    cout << "\n===== CHINH SUA ORDER =====\n";
    cout << "Nhap ID order can sua: ";
    cin >> id;

    int pos = findOrder(shop, id);

    if (pos == -1){
        cout << "Khong tim thay order!\n";
        return;
    }

    Order &o = shop.orders[pos];

    cin.ignore();
    cout << "Ten khach hang hien tai: " << o.customerName << endl;
    cout << "Nhap ten khach hang moi: ";
    getline(cin, o.customerName);
    cout << "Nhap ngay moi: ";
    cin >> o.day;
    cout << "Nhap thang moi: ";
    cin >> o.month;
    cout << "Nhap nam moi: ";
    cin >> o.year;
    cout << "Nhap trang thai moi (1: Da thanh toan, 0: Chua thanh toan): ";
    cin >> o.status;

    cout << "Chinh sua order thanh cong!\n";
}

// 5. THONG KE ORDER THEO THANG
void statisticOrderByMonth(Shop &shop){
    int month;
    int year;

    cout << "\n===== THONG KE ORDER THEO THANG =====\n";
    cout << "Nhap thang: ";
    cin >> month;

    cout << "Nhap nam: ";
    cin >> year;
    int count = 0;
    double total = 0;

    for (int i = 0; i < shop.nOrder; i++){
        Order &o = shop.orders[i];

        if (o.month == month && o.year == year){
            count++;

            // Tinh tong tien cua order
            for (int j = 0; j < o.nItem; j++){
                int pos = findMobile(shop, o.items[j].mobileId);

                if (pos != -1){
                    total += shop.mobiles[pos].price * o.items[j].quantity;
                }
            }
        }
    }

    cout << "\n===== KET QUA =====\n";
    cout << "Thang: " << month << "/" << year << endl;
    cout << "So luong order: " << count << endl;
    cout << "Tong doanh thu: " << total << endl;
}

// HIEN THI DANH SACH DIEN THOAI
void showMobiles(Shop &shop){
    cout << "\n========== DANH SACH DIEN THOAI ==========\n";

    for (int i = 0; i < shop.nMobile; i++){
        cout << "\nDien thoai " << i + 1 << endl;

        cout << "ID: " << shop.mobiles[i].id << endl;
        cout << "Hang: " << shop.mobiles[i].brand << endl;
        cout << "Version: " << shop.mobiles[i].version << endl;
        cout << "Series: " << shop.mobiles[i].series << endl;
        cout << "Nam: " << shop.mobiles[i].year << endl;
        cout << "Gia: " << shop.mobiles[i].price << endl;
        cout << "So luong: " << shop.mobiles[i].quantity << endl;
    }
}

// HIEN THI DANH SACH ORDER
void showOrders(Shop &shop){
    cout << "\n========== DANH SACH ORDER ==========\n";

    for (int i = 0; i < shop.nOrder; i++){
        cout << "\nOrder " << i + 1 << endl;

        cout << "ID: " << shop.orders[i].id << endl;
        cout << "Khach hang: " << shop.orders[i].customerName << endl;

        cout << "Ngay: " << shop.orders[i].day << "/" << shop.orders[i].month << "/" << shop.orders[i].year << endl;

        cout << "Trang thai: ";

        if (shop.orders[i].status)
            cout << "Da thanh toan\n";
        else
            cout << "Chua thanh toan\n";

        cout << "Danh sach san pham:\n";

        for (int j = 0; j < shop.orders[i].nItem; j++){
            cout << "- Mobile ID: " << shop.orders[i].items[j].mobileId << " | So luong: " << shop.orders[i].items[j].quantity << endl;
        }
    }
}

// MAIN
int main(){
    Shop shop;

    shop.nMobile = 0;
    shop.nOrder = 0;

    cout << "========== THONG TIN SHOP ==========\n";
    cout << "Nhap ten shop: ";
    getline(cin, shop.shopName);
    cout << "Nhap dia chi: ";
    getline(cin, shop.address);
    cout << "Nhap so dien thoai shop: ";
    getline(cin, shop.phone);

    int choice;

    do{
        cout << "\n\n========== MENU ==========\n";
        cout << "1. Them dien thoai\n";
        cout << "2. Xoa dien thoai\n";
        cout << "3. Tao order\n";
        cout << "4. Chinh sua order\n";
        cout << "5. Thong ke order theo thang\n";
        cout << "6. Xem danh sach dien thoai\n";
        cout << "7. Xem danh sach order\n";
        cout << "0. Thoat\n";

        cout << "Nhap lua chon: ";
        cin >> choice;

        switch (choice){
        case 1:
            addMobile(shop);
            break;

        case 2:
            deleteMobile(shop);
            break;

        case 3:
            createOrder(shop);
            break;

        case 4:
            editOrder(shop);
            break;

        case 5:
            statisticOrderByMonth(shop);
            break;

        case 6:
            showMobiles(shop);
            break;

        case 7:
            showOrders(shop);
            break;

        case 0:
            cout << "Thoat chuong trinh!\n";
            break;

        default:
            cout << "Lua chon khong hop le!\n";
        }

    } while (choice != 0);

    return 0;
}