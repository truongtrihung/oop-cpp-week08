#include <iostream>
#include <string>
using namespace std;

#define MAX 10

// 1. Khai báo struct MOBILE trước
struct MOBILE {
    int id;
    string brand;
    string version;
    string seriesID;
    int year;
    double cost;

    void inputInfo() {
        cout << "Enter the id of the phone: ";
        cin >> id;

        cin.ignore();

        cout << "Enter the brand of the phone: ";
        getline(cin, brand);

        cout << "Enter the version of the phone: ";
        getline(cin, version);

        cout << "Enter the series ID of the phone: ";
        getline(cin, seriesID);

        cout << "Enter the year of the phone: ";
        cin >> year;

        cout << "Enter the cost of the phone: ";
        cin >> cost;
    }

    void outputInfo() {
        cout << "========================" << endl;
        cout << "   | ID        : " << id << endl;
        cout << "   | Brand     : " << brand << endl;
        cout << "   | Version   : " << version << endl;
        cout << "   | SeriesID  : " << seriesID << endl;
        cout << "   | Year      : " << year << endl;
        cout << "   | Cost      : " << cost << endl;
        cout << "========================" << endl;
    }
};

// 2. Khai báo struct ORDER tiếp theo
struct ORDER {
    bool paymentMethod;     // TRUE = CHUYEN KHOAN ; FALSE = TIEN MAT
    int idOrder;
    int idCustomer;
    string tieuChiKhachHang;
    MOBILE item[MAX];
    int itemCount;
    string date;

    void inputInfo(MOBILE availableMobiles[], int availableCount) {
        cout << "Enter order ID: ";
        cin >> idOrder;

        cout << "Enter customer ID: ";
        cin >> idCustomer;

        cin.ignore();

        cout << "Enter Customer Criteria: ";
        getline(cin, tieuChiKhachHang);

        cout << "Enter order Date (dd/mm/yyyy): ";
        getline(cin, date);

        cout << "Payment method (1: Transfer ; 0: Cash): ";
        cin >> paymentMethod;

        cout << "Enter the number of items in this order: ";
        cin >> itemCount;

        for (int i = 0; i < itemCount; i++) {
            int searchID;
            cout << "Enter the ID of item #" << i + 1 << ": ";
            cin >> searchID;

            bool found = false;
            for (int j = 0; j < availableCount; j++) {
                if (searchID == availableMobiles[j].id) {
                    item[i] = availableMobiles[j];
                    found = true;
                    break;
                }
            }

            if (!found) {
                cout << "Sorry the ID doesn't match any items here. Please enter details manually:\n";
                item[i].inputInfo();
            }
        }
    }

    void outputInfo() {
        cout << "******************************" << endl;
        cout << "   | Order ID          : " << idOrder << endl;
        cout << "   | Customer ID       : " << idCustomer << endl;
        cout << "   | Customer Criteria : " << tieuChiKhachHang << endl;
        cout << "   | Order Date        : " << date << endl;
        cout << "   | Payment method    : " << (paymentMethod ? "Transfer" : "Cash") << endl;
        cout << "   | Number of items   : " << itemCount << endl;
        cout << "   --- Purchased Items List ---" << endl;
        for (int i = 0; i < itemCount; i++) {
            item[i].outputInfo();
        }
        cout << "******************************" << endl;
    }
};

// 3. Khai báo struct SHOP sau khi MOBILE và ORDER đã có sẵn
struct SHOP {
    int idShop;
    string nameShop;

    MOBILE mobiles[MAX];
    int mobileCount = 0;

    ORDER orders[MAX];
    int orderCount = 0;

    bool checkShop(int id, string name) {
        return (id == 123 && name == "A5-103");
    }

    bool inputShop() {
        cout << "******************************" << endl;
        cout << "Enter the ID of the shop: ";
        cin >> idShop;

        cin.ignore();

        cout << "Enter the name of the shop: ";
        getline(cin, nameShop);

        if (!checkShop(idShop, nameShop)) {
            cout << "Sorry we don't know this one" << endl;
            return false;
        }

        // Inputing mobiles infor
        cout << "Enter the number of mobiles: ";
        cin >> mobileCount;

        for (int i = 0; i < mobileCount; i++) {
            cout << "\n --> Input phone " << i + 1 << ": " << endl;
            mobiles[i].inputInfo();
        }

        // Inputing orders
        cout << "Enter the number of orders: ";
        cin >> orderCount;

        for (int i = 0; i < orderCount; i++){
            cout << "\n --> Order " << i + 1 << ": " << endl;
            orders[i].inputInfo(mobiles, mobileCount);
        }
        cout << "******************************" << endl;
        return true;
    }

    void outputShop() {
        cout << "<<<<<<<<<<<<<< SHOP INFO >>>>>>>>>>>>>>" << endl;
        cout << "Shop ID: " << idShop << endl;
        cout << "Shop Name: " << nameShop << endl;
        cout << "Total Mobiles in stock: " << mobileCount << endl;
        for (int i = 0; i < mobileCount; i++) {
            mobiles[i].outputInfo();
        }
        cout << "Total Orders processed: " << orderCount << endl;
        for (int i = 0; i < orderCount; i++) {
            orders[i].outputInfo();
        }
    }

    // Chức năng 1: Thêm mới điện thoại
    void addMobile() {
        if (mobileCount < MAX) {
            cout << "\n === ADD NEW MOBILE ===" << endl;
            mobiles[mobileCount].inputInfo();
            mobileCount++;
            cout << " --> Add mobile successfully" << endl;
        } else {
            cout << " --> Sorry there is no space left" << endl;
        }
    }

    // Chức năng 2: Xóa điện thoại theo ID
    void deleteMobile(int idSearch) {
        int index = -1;
        for (int i = 0; i < mobileCount; i++) {
            if (mobiles[i].id == idSearch) {
                index = i;
                break;
            }
        }
        if (index != -1) {
            for (int i = index; i < mobileCount - 1; i++) {
                mobiles[i] = mobiles[i + 1];
            }
            mobileCount--;
            cout << " --> Delete mobile ID " << idSearch << " successfully!" << endl;
        } else {
            cout << " --> Mobile ID " << idSearch << " not found!" << endl;
        }
    }

    // Chức năng 3: Tạo mới 1 order
    void createOrder() {
        if (orderCount < MAX) {
            cout << "\n === CREATE NEW ORDER === " << endl;
            orders[orderCount].inputInfo(mobiles, mobileCount);
            orderCount++;
            cout << " --> Create order successfully!" << endl;
        } else {
            cout << " --> Order list is full!" << endl;
        }
    }

    // Chức năng 4: Chỉnh sửa thông tin order
    void editOrder(int idOrderSearch) {
        int index = -1;
        for (int i = 0; i < orderCount; i++) { // Sửa lại chạy trên orderCount
            if (orders[i].idOrder == idOrderSearch) {
                index = i;
                break;
            }
        }
        if (index != -1) {
            cout << "\n === EDIT ORDER ID " << idOrderSearch << " ===" << endl;
            orders[index].inputInfo(mobiles, mobileCount);
            cout << " --> Edit order successfully!" << endl;
        } else {
            cout << " --> Order ID " << idOrderSearch << " not found!" << endl;
        }
    }

    // Chức năng 5: Thống kê order theo tháng (định dạng date: dd/mm/yyyy)
    void reportOrdersByMonth(string monthSearch) {
        cout << "\n=== ORDERS IN MONTH " << monthSearch << " ===" << endl;
        int count = 0;
        for (int i = 0; i < orderCount; i++) {
            if (orders[i].date.length() >= 5) {
                string monthInDate = orders[i].date.substr(3, 2);
                if (monthInDate == monthSearch) {
                    orders[i].outputInfo();
                    count++;
                }
            }
        }
        cout << "Total orders found in month " << monthSearch << ": " << count << endl;
    }
};

int main() {
    SHOP myShop;

    cout << "================================" << endl;
    cout << "=====WELCOME TO MOBILE SHOP=====" << endl;
    cout << "================================" << endl;

    // Nhập thông tin Shop ban đầu (gồm id = 123, name = A5-103)
    if (!myShop.inputShop()) {
        cout << "Chuong trinh ket thuc do nhap sai thong tin Shop!" << endl;
        return 0; 
    }

    // Vòng lặp Menu liên tục cho đến khi nhấn 0
    while (true) {
        cout << "\n========== MENU CUA HANG ==========" << endl;
        cout << "1. Them moi dien thoai" << endl;
        cout << "2. Xoa dien thoai" << endl;
        cout << "3. Tao moi 1 order" << endl;
        cout << "4. Chinh sua thong tin order" << endl;
        cout << "5. Thong ke order theo thang" << endl;
        cout << "6. Hien thi toan bo thong tin Shop" << endl;
        cout << "0. Thoat" << endl;
        cout << "Chon chuc nang: ";

        int choice;
        cin >> choice;

        // Neu chon 0 thi thoát khoi vong lap ngay lap tuc
        if (choice == 0) {
            cout << "Exiting program..." << endl;
            break; 
        }

        if (choice == 1) {
            myShop.addMobile();
        } 
        else if (choice == 2) {
            int id;
            cout << "Nhap ID dien thoai can xoa: ";
            cin >> id;
            myShop.deleteMobile(id);
        } 
        else if (choice == 3) {
            myShop.createOrder();
        } 
        else if (choice == 4) {
            int idOrder;
            cout << "Nhap ID order can chinh sua: ";
            cin >> idOrder;
            myShop.editOrder(idOrder);
        } 
        else if (choice == 5) {
            string month;
            cout << "Nhap thang can thong ke (2 chu so, vi du 03, 12): ";
            cin >> month;
            myShop.reportOrdersByMonth(month);
        } 
        else if (choice == 6) {
            myShop.outputShop();
        } 
        else {
            cout << "Lua chon khong hop le, vui long nhap lai!" << endl;
        }
    }

    return 0;
}