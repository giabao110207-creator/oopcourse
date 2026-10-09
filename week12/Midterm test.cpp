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



    return 0;
}