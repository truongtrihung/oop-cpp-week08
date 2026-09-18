#include <iostream>
using namespace std;

int main(){
    int x = 3;
    
    int& y = x;      // Khai báo y là tham chiếu (reference) của x. 
                     // y đóng vai trò là "biệt danh" của x, cả x và y cùng quản lý chung 1 vùng nhớ.

    x = 7;           // Đổi giá trị của x thành 7. 
                     // Vì y dùng chung vùng nhớ với x nên giá trị khi truy cập qua y lúc này cũng là 7.

    y = 2;           // Gán giá trị 2 thông qua biến y. 
                     // Vùng nhớ chung bị cập nhật thành 2, kéo theo giá trị của x cũng chuyển thành 2.

    cout << x << " " << y << endl; // In giá trị của x và y ra màn hình (Kết quả in ra: 2 2)
    
    return 0;        
}