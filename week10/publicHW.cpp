#include <iostream>
#include <string>
#include <vector>

using namespace std;

#define MAX 10

class FOOD {
private:
    string id;
    string name;
    double price;
    int quantity;

public:
    // Default constructor (without parameters)
    FOOD() : id (""), name (""), price (0.0), quantity (0) {}

    // Constructor with parameters
    FOOD (string i, string n, double p, int q) : id(i), name(n), price(p), quantity(q){}

    
    void inputFood(){
        cout << "Nhap ma mon: "; getline (cin, id);
        cout << "Nhap ten mon : "; getline (cin, name);
        cout << "Nhap gia   : "; cin >> price;
        cout << "Nhap so luong : "; cin >> quantity;
        cin.ignore() ;
    } 

    void displayFood() const {
        cout << " | " << id << " | " << name 
             << " | Gia: " << price << " | So luong: " 
             << quantity << endl; 
    } 

    void setPrice (double newPrice){
        if (newPrice > 0){
            price = newPrice;
        }
    }    

    bool reduceQuantity(int amount){
        if (amount > 0 && quantity >= amount){
            quantity -= amount;
            return true;
        }
        return false;
    }
    bool isAvailable() const {
        return quantity > 0;
    }           
    
    // Hàm Getter
    string getID() const { return id; }               
    string getName() const { return name;}             
    double getPrice() const { return price; }           
    int getQuantity() const { return quantity; }              
};

int main(){
    vector <FOOD> menu;
    int n;
    cout << "Nhap so luong mon an: ";
    cin >> n;
    cin.ignore();
    
    for (int i = 0; i < n; i++){
        FOOD f("", "", 0.0, 0);     // constructor
        cout << "\n === NHAP THONG TIN MON " << i + 1 << " ===\n";
        f.inputFood();      // gọi hàm public
        menu.push_back(f);  // Lưu món ăn vào menu 
    }

    cout << "\n === Danh sach mon an ===\n ";
    for (const FOOD& f : menu) { // const: dùng để đọc và không thể sửa dữ liệu trong f
        f.displayFood();    // gọi hàm public
    }

    cout << "\n Nhap ma mon an can giam so luong: ";
    string id; getline (cin, id);

    cout << "Nhap so luong can giam: ";
    int amount; cin >> amount;

    bool found = false;
    for (FOOD& f : menu){ // const: cho phép tương tác và thay đổi trực tiếp của f
        if (f.getID() == id){   // gọi hàm public
            if (f.reduceQuantity(amount)){
                cout << "Giam so luong thanh cong!\n";
                found  = true;
                cout << "\n === Danh sach mon an sau khi cap nhat ===\n";
                for (const FOOD& f : menu){
                    f.displayFood();
                }
            } else{
                cout << "Khong du so luong!\n";
            }
            break;
        }
    }
    if (!found) cout << "Khong tim thay mon an!\n";
    
    return 0;
}