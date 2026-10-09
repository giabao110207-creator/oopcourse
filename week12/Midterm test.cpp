#include <iostream>
#include <string>
using namespace std;

// ================== CAU 1: Dinh nghia lop Fish ==================
class Fish {
private:
    int id;
    string name;
    string color;
    string characteristic;

public:
    // ================== CAU 2: Constructors ==================
    // Constructor mac dinh
    Fish() {
        id = 0;
        name = "";
        color = "";
        characteristic = "";
    }

    // Constructor 1 tham so
    Fish(int i) {
        id = i;
        name = "";
        color = "";
        characteristic = "";
    }

    // Constructor 2 tham so
    Fish(int i, string n) {
        id = i;
        name = n;
        color = "";
        characteristic = "";
    }

    // Constructor 3 tham so
    Fish(int i, string n, string c) {
        id = i;
        name = n;
        color = c;
        characteristic = "";
    }

    // Constructor 4 tham so
    Fish(int i, string n, string c, string ch) {
        id = i;
        name = n;
        color = c;
        characteristic = ch;
    }

  // ================== CAU 3: Getter va Setter ==================
    // Getter
    int getId() {
        return id;
    }
    string getName() {
        return name;
    }
    string getColor() {
        return color;
    }
    string getCharacteristic() {
        return characteristic;
    }
    // Setter
    void setId(int i) {
        id = i;
    }
    void setName(string n) {
        name = n;
    }
    void setColor(string c) {
        color = c;
    }
    void setCharacteristic(string ch) {
        characteristic = ch;
    }

    // ================== CAU 4: Hien thi thong tin ==================
    void displayFishInfo() {
        cout << "ID             : " << id << endl;
        cout << "Name           : " << name << endl;
        cout << "Color          : " << color << endl;
        cout << "Characteristic : " << characteristic << endl;
        cout << "-----------------------------------" << endl;
    }

    };

// ================== CAU 5: Ham main ==================
int main() {
    // Tao 5 doi tuong, moi doi tuong dung 1 constructor khac nhau
    Fish f1;                                                      // mac dinh
    Fish f2(2);                                                   // 1 tham so
    Fish f3(3, "Ca Ro Phi");                                      // 2 tham so
    Fish f4(4, "Ca Map", "Xanh duong");                           // 3 tham so
    Fish f5(5, "Koi", "Do-Trang", "Song lau");                    // 4 tham so

    // Hien thi thong tin 5 doi tuong
    cout << "===== DANH SACH CA CANH BAN DAU =====" << endl;
    f1.displayFishInfo();
    f2.displayFishInfo();
    f3.displayFishInfo();
    f4.displayFishInfo();
    f5.displayFishInfo();

    // Dung setter cap nhat name, color, characteristic cua f2
    f2.setName("Ca Bay Mau");
    f2.setColor("Blue");
    f2.setCharacteristic("Nho nhat trong cac loai ca canh");

    // Dung getter lay va in thong tin doi tuong vua cap nhat
    cout << "===== THONG TIN F2 SAU KHI CAP NHAT (dung getter) =====" << endl;
    cout << "ID             : " << f2.getId() << endl;
    cout << "Name           : " << f2.getName() << endl;
    cout << "Color          : " << f2.getColor() << endl;
    cout << "Characteristic : " << f2.getCharacteristic() << endl;
    cout << "-----------------------------------" << endl;

    // Goi lai displayFishInfo() de kiem tra su thay doi (chi f2)
    cout << "===== F2 SAU KHI CAP NHAT (kiem tra lai) =====" << endl;
    f2.displayFishInfo();

    return 0;
}