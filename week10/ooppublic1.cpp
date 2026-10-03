#include <iostream>
#include <string>
using namespace std;

class Food {
private: 
    string id; 
    string name;
    double price;
    int quantity;

public: 

    // Constructor mặc định (Không tham số)
    Food() : id(""), name(""), price(0.0), quantity(0) {}

    // Constructor có tham số (Dùng để khởi tạo dữ liệu nhanh ở main)
    Food(string i, string n, double p, int q): id(i), name(n), price(p), quantity(q) {
        cout << "Da khoi tao constructor co tham so" << endl;
    }

    void input() {
        
        cout << "Nhap ID: ";
        getline(cin, id);

        cout << "Nhap ten: ";
        getline(cin, name);

        cout << "Nhap gia: ";
        cin >> price;

        cout << "Nhap so luong: ";
        cin >> quantity;
        cin.ignore(); 
    }
    
    void display() {
        cout << "\n[ID: " << id << "] " << name << " - " << price << " (" << quantity << " products)" << endl;
    }

    // Các hàm Getter (Lấy dữ liệu ra)
    string getId() const { return id; }
    string getName() const { return name; }
    double getPrice() const { return price; }
    int getQuantity() const { return quantity; }

    // Các hàm Setter (Cập nhật dữ liệu từ bên ngoài vào private)
    void setId(string i) { id = i; }
    void setName(string n) { name = n; }
    
    void setPrice(double p) { // Đổi tên từ getPrice thành setPrice cho đúng bản chất
        if (p > 0) price = p;
    }
    
    void setQuantity(int q) {
        if (q >= 0) quantity = q;
    }
};

int main() {
    // CÁCH 1: Khởi tạo đối tượng và truyền thẳng dữ liệu qua Constructor có tham số
    // (Vì thuộc tính là private nên ta dùng cách này thay cho việc gán f1.name = "Burger")
    Food f1("F001", "Burger", 50000, 10);

    cout << "--- Du lieu ban dau tu Constructor ---";
    f1.display();

    // CÁCH 2: Dùng hàm Setter nếu muốn cập nhật thông tin thủ công
    f1.setPrice(55000); // Tăng giá lên 55k thông qua Setter công khai
    cout << "\n--- Sau khi dung Setter cập nhat gia ---";
    f1.display();

    // CÁCH 3: Nhập đè dữ liệu mới từ bàn phím bằng hàm input() công khai
    cout << "\n--- Nhap du lieu moi tu ban phim ---" << endl;
    f1.input();
    
    cout << "\n--- Du lieu sau khi nhap tu ban phim ---";
    f1.display();

    return 0;
}