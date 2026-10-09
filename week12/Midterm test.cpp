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



    };

// ================== CAU 5: Ham main ==================
int main() {



    return 0;
}