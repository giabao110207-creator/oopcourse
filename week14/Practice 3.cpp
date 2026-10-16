
#include <iostream>
#include <string>
using namespace std;

class Drinks {
protected:
    string name;
    double revenue;
    int day, month, year;

public:
    Drinks(string n, double r, int d, int m, int y) {
        name = n;
        revenue = r;
        day = d;
        month = m;
        year = y;
    }

    virtual double calculateRevenue(int d, int m, int y) {
        if (day == d && month == m && year == y) {
            return revenue;
        }
        return 0;
    }

    virtual ~Drinks() = default;
};

class Coffee : public Drinks {
public:
    Coffee(double r, int d, int m, int y)
        : Drinks("Coffee", r, d, m, y) {
    }
};

class Tea : public Drinks {
public:
    Tea(double r, int d, int m, int y)
        : Drinks("Tea", r, d, m, y) {
    }
};

class Smoothies : public Drinks {
public:
    Smoothies(double r, int d, int m, int y)
        : Drinks("Smoothies", r, d, m, y) {
    }
};

class Juices : public Drinks {
public:
    Juices(double r, int d, int m, int y)
        : Drinks("Juices", r, d, m, y) {
    }
};

class Foods {
protected:
    string name;
    double revenue;
    int day, month, year;

public:
    Foods(string n, double r, int d, int m, int y) {
        name = n;
        revenue = r;
        day = d;
        month = m;
        year = y;
    }

    virtual double calculateRevenue(int d, int m, int y) {
        if (day == d && month == m && year == y) {
            return revenue;
        }
        return 0;
    }

    virtual ~Foods() = default;
};

class Cake : public Foods {
public:
    Cake(double r, int d, int m, int y)
        : Foods("Cake", r, d, m, y) {
    }
};

class Breads : public Foods {
public:
    Breads(double r, int d, int m, int y)
        : Foods("Breads", r, d, m, y) {
    }
};

// Tinh tong doanh thu Drinks theo ngay
double calculateDrinksRevenue(
    Drinks* drinks[], int n,
    int d, int m, int y) {

    double total = 0;

    for (int i = 0; i < n; i++) {
        total += drinks[i]->calculateRevenue(d, m, y);
    }

    return total;
}

// Tinh tong doanh thu Foods theo ngay
double calculateFoodsRevenue(
    Foods* foods[], int n,
    int d, int m, int y) {

    double total = 0;

    for (int i = 0; i < n; i++) {
        total += foods[i]->calculateRevenue(d, m, y);
    }

    return total;
}

int main() {
    // Du lieu doanh thu: ten san pham, doanh thu, ngay, thang, nam
    Coffee c(500000, 16, 10, 2026);
    Tea t(300000, 16, 10, 2026);
    Smoothies s(400000, 16, 10, 2026);
    Juices j(200000, 15, 10, 2026);

    Cake ca(600000, 16, 10, 2026);
    Breads b(250000, 16, 10, 2026);

    Drinks* drinks[] = {&c, &t, &s, &j};
    Foods* foods[] = {&ca, &b};

    int d, m, y;

    cout << "Nhap ngay (dd mm yyyy): ";
    cin >> d >> m >> y;

    cout << "\nDoanh thu ngay "
         << d << "/" << m << "/" << y << endl;

    cout << "Drinks: "
         << calculateDrinksRevenue(drinks, 4, d, m, y)
         << " VND" << endl;

    cout << "Foods: "
         << calculateFoodsRevenue(foods, 2, d, m, y)
         << " VND" << endl;

    return 0;
}
