#include <iostream>
#include <string>
#include <vector>
using namespace std;

// ================== Lop Date ==================
class Date {
public:
    int year, month, day;
    Date() {
        year = 0;
        month = 0;
        day = 0;
    }
    Date(int y, int m, int d) {
        year = y;
        month = m;
        day = d;
    }
};

// ================== CAU 7: Lop Category ==================
class Category {
private:
    int categoryId;
    string categoryName;
    string description;

public:
    // Constructors
    Category() {
        categoryId = 0;
        categoryName = "";
        description = "";
    }
    Category(int i) {
        categoryId = i;
        categoryName = "";
        description = "";
    }
    Category(int i, string n) {
        categoryId = i;
        categoryName = n;
        description = "";
    }
    Category(int i, string n, string d) {
        categoryId = i;
        categoryName = n;
        description = d;
    }

    // Getter
    int getCategoryId() {
        return categoryId;
    }
    string getCategoryName() {
        return categoryName;
    }
    string getDescription() {
        return description;
    }

    // Setter
    void setCategoryId(int i) {
        categoryId = i;
    }
    void setCategoryName(string n) {
        categoryName = n;
    }
    void setDescription(string d) {
        description = d;
    }

    // Display info
    void displayCategoryInfo() {
        cout << "Category ID   : " << categoryId << endl;
        cout << "Category Name : " << categoryName << endl;
        cout << "Description   : " << description << endl;
        cout << "-----------------------------------" << endl;
    }
};

// ================== CAU 1: Lop Fish ==================
class Fish {
private:
    int id;
    string name;
    string color;
    string characteristic;
    int categoryId;

public:
    // ================== CAU 2: Constructors ==================
    Fish() {
        id = 0;
        name = "";
        color = "";
        characteristic = "";
        categoryId = 0;
    }
    Fish(int i) {
        id = i;
        name = "";
        color = "";
        characteristic = "";
        categoryId = 0;
    }
    Fish(int i, string n) {
        id = i;
        name = n;
        color = "";
        characteristic = "";
        categoryId = 0;
    }
    Fish(int i, string n, string c) {
        id = i;
        name = n;
        color = c;
        characteristic = "";
        categoryId = 0;
    }
    Fish(int i, string n, string c, string ch) {
        id = i;
        name = n;
        color = c;
        characteristic = ch;
        categoryId = 0;
    }
    Fish(int i, string n, string c, string ch, int catId) {
        id = i;
        name = n;
        color = c;
        characteristic = ch;
        categoryId = catId;
    }

    // ================== CAU 3: Getter va Setter ==================
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
    int getCategoryId() {
        return categoryId;
    }

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
    void setCategoryId(int catId) {
        categoryId = catId;
    }

    // ================== CAU 4: Hien thi thong tin ==================
    void displayFishInfo() {
        cout << "ID             : " << id << endl;
        cout << "Name           : " << name << endl;
        cout << "Color          : " << color << endl;
        cout << "Characteristic : " << characteristic << endl;
        cout << "Category ID    : " << categoryId << endl;
        cout << "-----------------------------------" << endl;
    }
};

// ================== CAU 1: Lop FishShop ==================
class FishShop {
private:
    int id;
    string name;
    string address;
    string owner;
    Date startdate;
    vector<Category> categories;   // Category[] categories
    vector<Fish> fishes;           // Fish[] fishes

public:
    // Constructors
    FishShop() {
        id = 0;
        name = "";
        address = "";
        owner = "";
        startdate = Date();
    }
    FishShop(int i, string n, string addr, string o, Date d) {
        id = i;
        name = n;
        address = addr;
        owner = o;
        startdate = d;
    }
 // ================== CAU 2: Getter ==================
    int getId() {
        return id;
    }
    string getName() {
        return name;
    }
    string getAddress() {
        return address;
    }
    string getOwner() {
        return owner;
    }
    Date getStartDate() {
        return startdate;
    }
    vector<Category> getCategories() {
        return categories;
    }
    vector<Fish> getFishes() {
        return fishes;
    }

    // ================== CAU 2: Setter ==================
    void setId(int i) {
        id = i;
    }
    void setName(string n) {
        name = n;
    }
    void setAddress(string addr) {
        address = addr;
    }
    void setOwner(string o) {
        owner = o;
    }
    void setStartDate(Date d) {
        startdate = d;
    }
    void setCategories(vector<Category> c) {
        categories = c;
    }
    void setFishes(vector<Fish> f) {
        fishes = f;
    }

    // Them 1 category / 1 fish vao cua hang
    void addCategory(Category c) {
        categories.push_back(c);
    }
    void addFish(Fish f) {
        fishes.push_back(f);
    }

    // ================== CAU 2: Display ==================
    // Hien thi thong tin cua hang (khong gom danh sach)
    void displayShopInfo() {
        cout << "====================" << endl;
        cout << "=== Fish Shop Info ===" << endl;
        cout << "====================" << endl;
        cout << "ID         : " << id << endl;
        cout << "Name       : " << name << endl;
        cout << "Address    : " << address << endl;
        cout << "Owner      : " << owner << endl;
        cout << "Start date : " << startdate.year << "/" << startdate.month << "/" << startdate.day << endl;
        cout << "So category: " << categories.size() << endl;
        cout << "So ca      : " << fishes.size() << endl;
    }

    // Hien thi tat ca category
    void displayCategories() {
        cout << "\n===== DANH SACH CATEGORY =====" << endl;
        for (int i = 0; i < categories.size(); i++) {
            categories[i].displayCategoryInfo();
        }
    }

    // Hien thi tat ca ca
    void displayFishes() {
        cout << "\n===== DANH SACH TAT CA CA (" << fishes.size() << " con) =====" << endl;
        for (int i = 0; i < fishes.size(); i++) {
            fishes[i].displayFishInfo();
        }
    }
};

// ================== CAU 6: Tim danh sach Fish theo mau ==================
vector<Fish> getFishByColor(vector<Fish> fishList, string color) {
    vector<Fish> result;
    for (int i = 0; i < fishList.size(); i++) {
        if (fishList[i].getColor() == color) {
            result.push_back(fishList[i]);
        }
    }
    return result;
}

// ================== CAU 7: Tim danh sach Fish theo category ==================
vector<Fish> getFishByCategory(vector<Fish> fishList, int categoryId) {
    vector<Fish> result;
    for (int i = 0; i < fishList.size(); i++) {
        if (fishList[i].getCategoryId() == categoryId) {
            result.push_back(fishList[i]);
        }
    }
    return result;
}

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

     // ================== CAU 7: Tao 3 category ==================
    Category cat1(1, "Freshwater", "Ca nuoc ngot nuoi trong be kinh");
    Category cat2(2, "Saltwater", "Ca nuoc man, can be nuoc man chuyen dung");
    Category cat3(3, "Pond", "Ca nuoi trong ho, be ngoai troi");

    // Tao vector Category
    vector<Category> categories;
    categories.push_back(cat1);
    categories.push_back(cat2);
    categories.push_back(cat3);

    // Gan category cho 5 con ca dau (gan truoc khi push_back vao vector)
    f1.setCategoryId(1);
    f2.setCategoryId(1);
    f3.setCategoryId(1);
    f4.setCategoryId(3);
    f5.setCategoryId(3);

    // ================== CAU 6: Tao vector Fish (them 10 con ca) ==================
    Fish f6(6, "Ca Neon", "Xanh duong", "Nho, song theo dan", 1);
    Fish f7(7, "Ca Thien Than", "Bac", "Than hinh tam giac thanh lich", 1);
    Fish f8(8, "Ca Hanh Phuc", "Cam", "Song cung hai quy", 2);
    Fish f9(9, "Ca Bac Si Xanh", "Xanh duong", "Hoat bat, can khong gian rong", 2);
    Fish f10(10, "Ca Dia", "Do", "Than tron, nhay cam voi nuoc", 1);
    Fish f11(11, "Ca Ho Bao", "Den", "To lon va thong minh", 1);
    Fish f12(12, "Ca Su Tu", "Do", "Co gai doc tren than", 2);
    Fish f13(13, "Ca Buom", "Vang", "Than det, mau sac ruc ro", 2);
    Fish f14(14, "Ca Chep Nhat Nho", "Cam", "Khoe, de nuoi trong ho", 3);
    Fish f15(15, "Ca Vang Duoi Dai", "Do", "Duoi dai, boi nhanh", 3);

    vector<Fish> fishList;
    fishList.push_back(f1);
    fishList.push_back(f2);
    fishList.push_back(f3);
    fishList.push_back(f4);
    fishList.push_back(f5);
    fishList.push_back(f6);
    fishList.push_back(f7);
    fishList.push_back(f8);
    fishList.push_back(f9);
    fishList.push_back(f10);
    fishList.push_back(f11);
    fishList.push_back(f12);
    fishList.push_back(f13);
    fishList.push_back(f14);
    fishList.push_back(f15);

    // Hien thi toan bo danh sach ca
    cout << "\n===== DANH SACH TAT CA CA CANH (" << fishList.size() << " con) =====" << endl;
    for (int i = 0; i < fishList.size(); i++) {
        fishList[i].displayFishInfo();
    }

    // ================== CAU 6: Nhom ca theo mau ==================
     // Tu dong lay danh sach cac mau khac nhau tu fishList
    vector<string> colors;
    for (int i = 0; i < fishList.size(); i++) {
        string c = fishList[i].getColor();
        bool exists = false;
        for (int j = 0; j < colors.size(); j++) {
            if (colors[j] == c) {
                exists = true;
                break;
            }
        }
        if (!exists && c != "") {
            colors.push_back(c);
        }
    }

    // Voi moi mau, goi ham getFishByColor de lay danh sach ca roi in ra
    cout << "\n===== NHOM CA THEO MAU =====" << endl;
    for (int i = 0; i < colors.size(); i++) {
        vector<Fish> colorList = getFishByColor(fishList, colors[i]);
        cout << "\n*** MAU " << colors[i] << ": " << colorList.size() << " con ***" << endl;
        for (int j = 0; j < colorList.size(); j++) {
            colorList[j].displayFishInfo();
        }
    }

    // ================== CAU 7: Hien thi tat ca category ==================
    cout << "\n===== DANH SACH CATEGORY =====" << endl;
    for (int i = 0; i < categories.size(); i++) {
        categories[i].displayCategoryInfo();
    }

    // ================== CAU 7: Hien thi ca thuoc category duoc chon ==================
    int selectedId;
    cout << "\nNhap CategoryId muon xem (1-3): ";
    cin >> selectedId;

    vector<Fish> listByCategory = getFishByCategory(fishList, selectedId);
    cout << "\n===== CA THUOC CATEGORY " << selectedId << " =====" << endl;
    if (listByCategory.size() == 0) {
        cout << "Khong co ca nao thuoc category " << selectedId << endl;
    }
    else {
        for (int i = 0; i < listByCategory.size(); i++) {
            listByCategory[i].displayFishInfo();
        }
    }

     // =====================================================================
    // ================== FISHSHOP - CAU 3: main() ==========================
    // =====================================================================

    // Tao cua hang ca canh
    Date shopDate(2024, 1, 15);
    FishShop shop(1, "Cua Hang Ca Canh Sai Gon", "Vo Van Ngan, Thu Duc", "Nguyen Van An", shopDate);

    // Tao 4 category
    Category shopCat1(1, "Ca Nuoc Ngot", "Ca nuoi trong be kinh nuoc ngot");
    Category shopCat2(2, "Ca Nuoc Man", "Ca bien, can be nuoc man chuyen dung");
    Category shopCat3(3, "Ca Ho", "Ca nuoi trong ho, be ngoai troi");
    Category shopCat4(4, "Ca Rong", "Ca rong lon, quy hiem");

    shop.addCategory(shopCat1);
    shop.addCategory(shopCat2);
    shop.addCategory(shopCat3);
    shop.addCategory(shopCat4);

    // Du lieu 10 con ca cho moi category
    string names1[10] = { "Ca Neon", "Ca Thien Than", "Ca Dia", "Ca Betta", "Ca Bay Mau",
                          "Ca Chuot", "Ca He", "Ca Ngua Van", "Ca Ho Bao", "Ca Tu Quy" };
    string colors1[10] = { "Xanh duong", "Bac", "Do", "Xanh la", "Cam",
                           "Den", "Vang", "Bac", "Den", "Do" };

    string names2[10] = { "Ca Hanh Phuc", "Ca Bac Si Xanh", "Ca Su Tu", "Ca Buom", "Ca Mao Tien",
                          "Ca Gai", "Ca Chim", "Ca Bom", "Ca Mat Quy", "Ca Hai Ma" };
    string colors2[10] = { "Cam", "Xanh duong", "Do", "Vang", "Trang",
                           "Den", "Xanh la", "Vang", "Do", "Bac" };

    string names3[10] = { "Ca Chep Nhat", "Ca Vang Duoi Dai", "Ca Koi Do", "Ca Koi Trang", "Ca Tre",
                          "Ca Tram", "Ca Diec", "Ca Ro", "Ca Loc", "Ca Rep" };
    string colors3[10] = { "Do", "Cam", "Do", "Trang", "Bac",
                           "Den", "Xanh la", "Vang", "Den", "Cam" };

    string names4[10] = { "Ca Rong Kim Long", "Ca Rong Huyet Long", "Ca Rong Thanh Long", "Ca Rong Ngan Long", "Ca Rong Den",
                          "Ca Rong Do", "Ca Rong Bach Kim", "Ca Rong Xanh", "Ca Rong Vang", "Ca Rong Cam" };
    string colors4[10] = { "Vang", "Do", "Xanh la", "Bac", "Den",
                           "Do", "Trang", "Xanh duong", "Vang", "Cam" };

    // Nhap du lieu: moi category 10 con ca
    for (int j = 0; j < 10; j++) {
        Fish f(j + 1, names1[j], colors1[j], "Phu hop nuoi be kinh nuoc ngot", 1);
        shop.addFish(f);
    }
    for (int j = 0; j < 10; j++) {
        Fish f(10 + j + 1, names2[j], colors2[j], "Can be nuoc man chuyen dung", 2);
        shop.addFish(f);
    }
    for (int j = 0; j < 10; j++) {
        Fish f(20 + j + 1, names3[j], colors3[j], "Song tot trong ho ngoai troi", 3);
        shop.addFish(f);
    }
    for (int j = 0; j < 10; j++) {
        Fish f(30 + j + 1, names4[j], colors4[j], "Ca lon, gia tri cao", 4);
        shop.addFish(f);
    }

    // Hien thi thong tin cua hang
    cout << "\n\n";
    shop.displayShopInfo();

    // Hien thi tat ca category cua hang
    shop.displayCategories();

    // Hien thi ca theo tung category cua hang
    vector<Category> shopCategories = shop.getCategories();
    vector<Fish> shopFishes = shop.getFishes();

    cout << "\n===== CA THEO TUNG CATEGORY CUA HANG =====" << endl;
    for (int i = 0; i < shopCategories.size(); i++) {
        vector<Fish> shopListByCategory = getFishByCategory(shopFishes, shopCategories[i].getCategoryId());
        cout << "\n*** CATEGORY " << shopCategories[i].getCategoryName()
             << ": " << shopListByCategory.size() << " con ***" << endl;
        for (int j = 0; j < shopListByCategory.size(); j++) {
            shopListByCategory[j].displayFishInfo();
        }
    }

    return 0;
}