#include <iostream>
using namespace std;

void swapValues (int& x, int& y){
    int temp = x;
    x = y; 
    y = temp;
}

int main(){
    int a = 4, b = 9;
    swapValues(a, b);
    cout << a << " " << b << endl;
    // Ouput: a = 9, b = 4
    return 0;
}