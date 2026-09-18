#include <iostream>
using namespace std;

// Khai báo biến toàn cục (Global variables) ngoài hàm main
// Bản chất: Cả hàm main() và hàm swapValues() đều dùng chung ĐỊA CHỈ của hai ô nhớ này.
int a = 5;
int b = 10;

// HÀM SWAP CỦA BẠN (Dùng biến toàn cục)
void swapValues(){
    int temp = a; // Ô nhớ tạm giữ giá trị cũ của a (temp = 5)
    a = b;        // Gán giá trị của ô nhớ b vào ô nhớ a -> a lúc này bằng 10
    b = temp;     // Gán giá trị của temp vào ô nhớ b -> b lúc này bằng 5
}

int main(){
    cout << "Before: a = " << a << ", b = " << b << endl;

    swapValues();   // lấy hàm swap

    
    cout << "After: a = " << a << ", b = " << b << endl;
    // SAU KHI CHẠY THÌ 2 BIẾN ĐỔI GIÁ TRỊ CHO NHAU!
    // NGUYÊN NHÂN: Do dùng biến toàn cục, hàm swapValues() không cần tạo bản sao (tham trị),
    // mà nó can thiệp và thay đổi TRỰC TIẾP giá trị ngay tại địa chỉ gốc của `a` và `b`.

    return 0;
}