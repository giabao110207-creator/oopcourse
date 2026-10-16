
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Vehicle {
private:
    string id;
    string name;
    double rentalPrice;

public:
    // Default constructor
    Vehicle() {
        id = "";
        name = "";
        rentalPrice = 0;
    }

    // Parameterized constructor
    Vehicle(string i, string n, double p) {
        id = i;
        name = n;
        rentalPrice = p;
    }

    // Getter
    string getId() {
        return id;
    }

    string getName() {
        return name;
    }

    double getRentalPrice() {
        return rentalPrice;
    }

    // Setter
    void setId(string i) {
        id = i;
    }

    void setName(string n) {
        name = n;
    }

    void setRentalPrice(double p) {
        rentalPrice = p;
    }

    // Display information
    virtual void displayInfo() {
        cout << "ID: " << id << endl;
        cout << "Name: " << name << endl;
        cout << "Rental price/day: " << rentalPrice << endl;
    }

    // Calculate rental fee
    virtual double calculateRentalFee(int days) = 0;

    virtual ~Vehicle() {}
};

// ================= CAR =================
class Car : public Vehicle {
private:
    int seats;

public:
    Car() : Vehicle() {
        seats = 0;
    }

    Car(string i, string n, double p, int s)
        : Vehicle(i, n, p) {
        seats = s;
    }

    int getSeats() {
        return seats;
    }

    void setSeats(int s) {
        seats = s;
    }

    void displayInfo() override {
        cout << "\n--- CAR ---" << endl;
        Vehicle::displayInfo();
        cout << "Seats: " << seats << endl;
    }

    double calculateRentalFee(int days) override {
        double fee = days * getRentalPrice();

        if (days >= 7) {
            fee = fee * 0.9;
        }

        return fee;
    }
};

// ================= MOTORBIKE =================
class Motorbike : public Vehicle {
private:
    int engineCC;

public:
    Motorbike() : Vehicle() {
        engineCC = 0;
    }

    Motorbike(string i, string n, double p, int cc)
        : Vehicle(i, n, p) {
        engineCC = cc;
    }

    int getEngineCC() {
        return engineCC;
    }

    void setEngineCC(int cc) {
        engineCC = cc;
    }

    void displayInfo() override {
        cout << "\n--- MOTORBIKE ---" << endl;
        Vehicle::displayInfo();
        cout << "Engine CC: " << engineCC << endl;
    }

    double calculateRentalFee(int days) override {
        double fee = days * getRentalPrice();

        if (days >= 5) {
            fee = fee * 0.95;
        }

        return fee;
    }
};

// ================= TRUCK =================
class Truck : public Vehicle {
private:
    double transportFee;

public:
    Truck() : Vehicle() {
        transportFee = 0;
    }

    Truck(string i, string n, double p, double t)
        : Vehicle(i, n, p) {
        transportFee = t;
    }

    double getTransportFee() {
        return transportFee;
    }

    void setTransportFee(double t) {
        transportFee = t;
    }

    void displayInfo() override {
        cout << "\n--- TRUCK ---" << endl;
        Vehicle::displayInfo();
        cout << "Transport fee: " << transportFee << endl;
    }

    double calculateRentalFee(int days) override {
        return days * getRentalPrice() + transportFee;
    }
};

// ================= MAIN =================
int main() {
    vector<Vehicle*> vehicles;

    vehicles.push_back(new Car("C01", "Toyota", 1000000, 7));
    vehicles.push_back(new Car("C02", "Honda", 800000, 5));

    vehicles.push_back(new Motorbike("M01", "Honda Winner", 150000, 150));
    vehicles.push_back(new Motorbike("M02", "Yamaha Exciter", 120000, 155));

    vehicles.push_back(new Truck("T01", "Hyundai Truck", 2000000, 500000));
    vehicles.push_back(new Truck("T02", "Isuzu Truck", 2500000, 700000));

    int days;

    cout << "Enter rental days: ";
    cin >> days;

    if (days <= 0) {
        cout << "Invalid number of days!" << endl;

        for (Vehicle* v : vehicles) {
            delete v;
        }

        return 0;
    }

    double totalRevenue = 0;
    double maxFee = -1;
    Vehicle* maxVehicle = nullptr;

    cout << "\n========== VEHICLE LIST ==========" << endl;

    for (Vehicle* v : vehicles) {
        v->displayInfo();

        double fee = v->calculateRentalFee(days);

        cout << "Rental days: " << days << endl;
        cout << "Rental fee: " << fee << " VND" << endl;

        totalRevenue += fee;

        if (fee > maxFee) {
            maxFee = fee;
            maxVehicle = v;
        }
    }

    cout << "\n========== SUMMARY ==========" << endl;

    cout << "Total rental revenue: "
         << totalRevenue << " VND" << endl;

    if (maxVehicle != nullptr) {
        cout << "\nVehicle with highest rental fee:" << endl;
        maxVehicle->displayInfo();
        cout << "Highest rental fee: "
             << maxFee << " VND" << endl;
    }

    // Free memory
    for (Vehicle* v : vehicles) {
        delete v;
    }

    vehicles.clear();

    return 0;
}
