#include <iostream>
using namespace std;

void setLastToTen (int& x){
    x = 10;
}

int main(){
    int nums[4] = {3, 5, 7, 9};
    
    setLastToTen(nums[3]);  // Truyền tham chiếu phần tử cuối (đổi 9 thành 10)
    
    // In mảng (Kết quả: 3 5 7 10)
    for (int i = 0; i < 4; i++){
        cout << nums[i] << " ";
    }
    cout << endl;

    return 0;
}
