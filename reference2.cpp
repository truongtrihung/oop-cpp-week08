#include <iostream>
using namespace std;

int a = 5;
int b = 10;

void swapValues(){
    int temp = a;
    a = b;
    b = temp;
}
int main(){
    cout << "Before: a = " << a << ", b = " << b << endl;

    swapValues();
    
    cout << "After: a = " << a << ", b = " << b << endl;

    return 0;
}