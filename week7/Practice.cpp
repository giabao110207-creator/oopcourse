#include <iostream>
#include <string>
using namespace std;

#define MAX 100

struct Computer
{
    string id;
    string tenMay;
    string heDieuHanh;
    string username;
    string password;
    string model;
    int year;
};

struct Lab
{
    string maPhong;
    Computer computers[MAX];
    int n = 0;
};

struct UserPassword
{
    string username;
    string password;
};


void getLabInfo(Lab& lab);
void getComputerInfo(Computer& c, string id);
Computer getComputerInfo(Lab lab, string id);
void getComputer(Lab& lab);
void showLabInfo(Lab lab);
UserPassword getUserAndPassword(Lab lab, string id);

int main()
{
    Lab lab;
    getLabInfo(lab);
    getComputer(lab);
    showLabInfo(lab);
    string id;
    cout << "\nNhap ID computer can tim: ";
    cin >> id;
    Computer c = getComputerInfo(lab, id);

    if (c.id != "")
    {
        cout << "\n==========================================";
        cout << "\n          COMPUTER TIM THAY";
        cout << "\n==========================================";

        cout << "\nID: " << c.id;
        cout << "\nTen may: " << c.tenMay;
        cout << "\nHe dieu hanh: " << c.heDieuHanh;
        cout << "\nModel: " << c.model;
        cout << "\nYear: " << c.year;
    }
    else
    {
        cout << "\nKhong tim thay computer!";
    }

    UserPassword user = getUserAndPassword(lab, id);
    if (user.username != "")
    {
        cout << "\n\n==========================================";
        cout << "\n       USERNAME VA PASSWORD";
        cout << "\n==========================================";

        cout << "\nUsername: " << user.username;
        cout << "\nPassword: " << user.password;
    }

    return 0;
}

// getLabInfo()
// Nhap thong tin Lab
void getLabInfo(Lab& lab)
{
    cout << "Nhap ma phong: ";
    cin >> lab.maPhong;
}

// 1. getComputerInfo(Computer&, string)
// Nhap thong tin mot Computer
void getComputerInfo(Computer& c, string id)
{
    c.id = id;

    cout << "Ten may: ";
    cin >> c.tenMay;

    cout << "He dieu hanh: ";
    cin >> c.heDieuHanh;

    cout << "Username: ";
    cin >> c.username;

    cout << "Password: ";
    cin >> c.password;

    cout << "Model: ";
    cin >> c.model;

    cout << "Year: ";
    cin >> c.year;
}

// 2. getComputerInfo(Lab, string)
// Tim Computer theo ID
Computer getComputerInfo(Lab lab, string id)
{
    for (int i = 0; i < lab.n; i++)
    {
        if (lab.computers[i].id == id)
        {
            return lab.computers[i];
        }
    }

    // Khong tim thay
    Computer c;
    c.id = "";

    return c;
}

// 3. getComputer()
// Nhap danh sach Computer
void getComputer(Lab& lab)
{
    cout << "Nhap so luong computer: ";
    cin >> lab.n;

    // Kiem tra so luong
    while (lab.n < 1 || lab.n > MAX)
    {
        cout << "So luong computer phai tu 1 den "
             << MAX << ". Nhap lai: ";
        cin >> lab.n;
    }

    // Nhap thong tin tung Computer
    for (int i = 0; i < lab.n; i++)
    {
        string id;

        cout << "\n===== COMPUTER " << i + 1 << " =====";

        cout << "\nID: ";
        cin >> id;

        getComputerInfo(lab.computers[i], id);
    }
}

// 4. getUserAndPassword()
// Tim username va password theo ID
UserPassword getUserAndPassword(Lab lab, string id)
{
    for (int i = 0; i < lab.n; i++)
    {
        if (lab.computers[i].id == id)
        {
            UserPassword user;

            user.username = lab.computers[i].username;
            user.password = lab.computers[i].password;

            return user;
        }
    }

    // Khong tim thay
    UserPassword user;

    user.username = "";
    user.password = "";

    return user;
}



// showLabInfo()
// Hien thi thong tin Lab
void showLabInfo(Lab lab)
{
    cout << "\n\n==========================================";
    cout << "\n                LAB INFO";
    cout << "\n==========================================";

    cout << "\nMa phong: " << lab.maPhong;
    cout << "\nSo luong computer: " << lab.n;

    // Hien thi tung Computer
    for (int i = 0; i < lab.n; i++)
    {
        cout << "\n\n===== COMPUTER " << i + 1 << " =====";

        cout << "\nID: " << lab.computers[i].id;
        cout << "\nTen may: " << lab.computers[i].tenMay;
        cout << "\nHe dieu hanh: " << lab.computers[i].heDieuHanh;
        cout << "\nUsername: " << lab.computers[i].username;
        cout << "\nPassword: " << lab.computers[i].password;
        cout << "\nModel: " << lab.computers[i].model;
        cout << "\nYear: " << lab.computers[i].year;
    }

    cout << "\n==========================================\n";
}