#include <iostream> 
using namespace std;  

// Hàm nhận mảng theo cách thông thường (truyền con trỏ trỏ tới phần tử đầu tiên)
void setFirstToZero(int arr[]){
    arr[0] = 0;     // Gán phần tử đầu tiên bằng 0 (thay đổi trực tiếp trên mảng gốc)
}

// Hàm nhận tham chiếu đến mảng cố định 4 phần tử: int (&arr)[4]
void incrementAll (int (&arr)[4]){
    for (int i = 0; i < 4; ++i){
        arr[i] += 1;    // Tăng từng phần tử trong mảng gốc lên 1 đơn vị
    }
}

int main(){
    int nums[4] = {1, 2, 3, 4}; // Khởi tạo mảng nums gồm 4 phần tử: {1, 2, 3, 4}

    setFirstToZero(nums);       // nums[0] chuyển từ 1 thành 0 -> mảng thành {0, 2, 3, 4}
    
    incrementAll(nums);         // Tăng tất cả phần tử lên 1 -> mảng thành {1, 3, 4, 5}
    
    // In ra các phần tử của mảng (Kết quả xuất ra: 1 3 4 5)
    cout << nums[0] << " " << nums[1] << " " << nums[2] << " " << nums[3] << endl;
    
    return 0;                   // Trả về 0 báo hiệu chương trình kết thúc thành công
}