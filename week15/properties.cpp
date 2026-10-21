
#include <iostream>
#include <cmath>
using namespace std;

// Lop phuong trinh co so
class PT {
protected:
    int bac;

public:
    PT() {
        bac = 0;
    }

    PT(int b) {
        bac = b;
    }

    void setBac(int b) {
        bac = b;
    }

    int getBac() {
        return bac;
    }

    virtual void solve() {
        cout << "Phuong trinh co bac: " << bac << endl;
    }
};

// Lop phuong trinh bac 2
class PTB2 : public PT {
private:
    double a, b, c;

public:
    PTB2() : PT(2) {
        a = 0;
        b = 0;
        c = 0;
    }

    PTB2(double a, double b, double c) : PT(2) {
        this->a = a;
        this->b = b;
        this->c = c;
    }

    void setA(double a) {
        this->a = a;
    }

    void setB(double b) {
        this->b = b;
    }

    void setC(double c) {
        this->c = c;
    }

    double getA() {
        return a;
    }

    double getB() {
        return b;
    }

    double getC() {
        return c;
    }

    void solve() override {
        cout << "\nPhuong trinh bac 2: "
             << a << "x^2 + " << b << "x + " << c << " = 0\n";

        if (a == 0) {
            cout << "Day khong phai phuong trinh bac 2.\n";
            if (b != 0) {
                cout << "Nghiem x = " << -c / b << endl;
            } else if (c == 0) {
                cout << "Phuong trinh vo so nghiem.\n";
            } else {
                cout << "Phuong trinh vo nghiem.\n";
            }
            return;
        }

        double delta = b * b - 4 * a * c;

        if (delta < 0) {
            cout << "Phuong trinh vo nghiem trong tap so thuc.\n";
        } else if (delta == 0) {
            cout << "Nghiem kep x = " << -b / (2 * a) << endl;
        } else {
            cout << "x1 = " << (-b + sqrt(delta)) / (2 * a) << endl;
            cout << "x2 = " << (-b - sqrt(delta)) / (2 * a) << endl;
        }
    }
};

// Lop phuong trinh bac 3
class PTB3 : public PT {
private:
    double a, b, c, d;

public:
    PTB3() : PT(3) {
        a = 0;
        b = 0;
        c = 0;
        d = 0;
    }

    PTB3(double a, double b, double c, double d) : PT(3) {
        this->a = a;
        this->b = b;
        this->c = c;
        this->d = d;
    }

    void setA(double a) {
        this->a = a;
    }

    void setB(double b) {
        this->b = b;
    }

    void setC(double c) {
        this->c = c;
    }

    void setD(double d) {
        this->d = d;
    }

    double getA() {
        return a;
    }

    double getB() {
        return b;
    }

    double getC() {
        return c;
    }

    double getD() {
        return d;
    }

    void solve() override {
        cout << "\nPhuong trinh bac 3: " << a << "x^3 + " << b << "x^2 + " << c << "x + " << d << " = 0\n";

        if (a == 0) {
            cout << "He so a = 0, khong phai phuong trinh bac 3.\n";
            cout << "Hay su dung PTB2 neu phuong trinh tro thanh bac 2.\n";
            return;
        }

        // Chia hai ve cho a:
        // x^3 + A*x^2 + B*x + C = 0
        double A = b / a;
        double B = c / a;
        double C = d / a;

        // Doi bien x = t - A/3
        double p = B - A * A / 3;
        double q = 2 * A * A * A / 27 - A * B / 3 + C;

        double delta = q * q / 4 + p * p * p / 27;
        double x;

        if (delta > 1e-12) {
            double u = cbrt(-q / 2 + sqrt(delta));
            double v = cbrt(-q / 2 - sqrt(delta));

            x = u + v - A / 3;
            cout << "Nghiem thuc: x = " << x << endl;
            cout << "Phuong trinh con co 2 nghiem phuc.\n";
        } else if (delta >= -1e-12) {
            double u = cbrt(-q / 2);
            double x1 = 2 * u - A / 3;
            double x2 = -u - A / 3;

            cout << "Nghiem x1 = " << x1 << endl;
            cout << "Nghiem x2 = " << x2 << endl;
            cout << "Trong do x2 la nghiem lap neu x1 = x2.\n";
        } else {
            double pi = acos(-1.0);
            double r = 2 * sqrt(-p / 3);
            double theta = acos(
                (3 * q / (2 * p)) * sqrt(-3 / p)
            ) / 3;

            for (int k = 0; k < 3; k++) {
                x = r * cos(theta - 2 * pi * k / 3) - A / 3;
                cout << "Nghiem x" << k + 1 << " = " << x << endl;
            }
        }
    }
};

int main() {
    int chon;

    cout << "===== CHUONG TRINH GIAI PHUONG TRINH =====\n";
    cout << "1. Phuong trinh bac 2\n";
    cout << "2. Phuong trinh bac 3\n";
    cout << "Nhap lua chon: ";
    cin >> chon;

    if (chon == 1) {
        double a, b, c;

        cout << "Nhap a, b, c: ";
        cin >> a >> b >> c;

        PTB2 pt(a, b, c);
        pt.solve();
    } else if (chon == 2) {
        double a, b, c, d;

        cout << "Nhap a, b, c, d: ";
        cin >> a >> b >> c >> d;

        PTB3 pt(a, b, c, d);
        pt.solve();
    } else {
        cout << "Lua chon khong hop le.\n";
    }

    return 0;
}
