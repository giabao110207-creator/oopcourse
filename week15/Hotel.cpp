
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
using namespace std;

// Lop cha
class Room {
private:
    int roomNumber;
    int adults;
    int children;
    double price;

protected:
    string roomType;
    string facilities;

public:
    // Constructor
    Room(int number, string type, double p, string f) {
        roomNumber = number;
        roomType = type;
        price = p;
        facilities = f;
        adults = 0;
        children = 0;
    }

    // Getter
    int getRoomNumber() {
        return roomNumber;
    }

    int getAdults() {
        return adults;
    }

    int getChildren() {
        return children;
    }

    double getPrice() {
        return price;
    }

    string getRoomType() {
        return roomType;
    }

    // Setter
    void setPrice(double p) {
        if (p >= 0)
            price = p;
    }

    bool setGuests(int a, int c) {
        if (a < 0 || a > 2 || c < 0 || c > 1)
            return false;

        adults = a;
        children = c;
        return true;
    }

    // Hien thi thong tin phong
    virtual void displayInfo() {
        cout << "Phong " << roomNumber
             << " | Loai: " << roomType
             << " | Nguoi lon: " << adults
             << " | Tre em: " << children
             << " | Gia: " << fixed << setprecision(0) << price
             << " VND"
             << " | Tien nghi: " << facilities
             << endl;
    }

    virtual ~Room() {}
};

// Phong Standard
class StandardRoom : public Room {
public:
    StandardRoom(int number)
        : Room(number, "Standard", 1000000,
               "Tien nghi tieu chuan") {
    }
};

// Phong Deluxe
class DeluxeRoom : public Room {
public:
    DeluxeRoom(int number)
        : Room(number, "Deluxe", 1500000,
               "Giuong don lon hoac 2 giuong doi") {
    }
};

// Phong Luxury
class LuxuryRoom : public Room {
public:
    LuxuryRoom(int number)
        : Room(number, "Luxury", 2000000,
               "Giuong don lon hoac 2 giuong doi, "
               "phong tam rieng") {
    }
};

int main() {
    vector<Room*> rooms;
    vector<Room*> selectedRooms;

    // Tao 10 phong Standard
    for (int i = 1; i <= 10; i++) {
        rooms.push_back(new StandardRoom(i));
    }

    // Tao 10 phong Deluxe
    for (int i = 11; i <= 20; i++) {
        rooms.push_back(new DeluxeRoom(i));
    }

    // Tao 10 phong Luxury
    for (int i = 21; i <= 30; i++) {
        rooms.push_back(new LuxuryRoom(i));
    }

    // Chia phong cho doan:
    // 7 Standard, 7 Deluxe, 6 Luxury
    for (int i = 0; i < 7; i++)
        selectedRooms.push_back(rooms[i]);

    for (int i = 10; i < 17; i++)
        selectedRooms.push_back(rooms[i]);

    for (int i = 20; i < 26; i++)
        selectedRooms.push_back(rooms[i]);

    // Phan bo 30 nguoi lon va 20 tre em
    // 15 phong dau: moi phong 2 nguoi lon, 1 tre em
    // 5 phong tiep theo: moi phong 1 tre em
    for (int i = 0; i < 20; i++) {
        if (i < 15)
            selectedRooms[i]->setGuests(2, 1);
        else
            selectedRooms[i]->setGuests(0, 1);
    }

    // Tinh tien
    double total = 0;

    cout << "===== DANH SACH PHONG CUA DOAN =====\n";

    for (int i = 0; i < selectedRooms.size(); i++) {
        selectedRooms[i]->displayInfo();
        total += selectedRooms[i]->getPrice();
    }

    cout << "\n===== THONG KE =====\n";
    cout << "Tong so khach: 50\n";
    cout << "Nguoi lon: 30\n";
    cout << "Tre em: 20\n";
    cout << "So phong Standard: 7\n";
    cout << "So phong Deluxe: 7\n";
    cout << "So phong Luxury: 6\n";
    cout << "Tong so phong su dung: "
         << selectedRooms.size() << endl;

    cout << "Tong chi phi 1 dem: "
         << total << " VND\n";

    // Giai phong bo nho
    for (int i = 0; i < rooms.size(); i++) {
        delete rooms[i];
    }

    return 0;
}
