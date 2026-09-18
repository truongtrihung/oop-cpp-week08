#include <iostream>
using namespace std;

int main(){
    int a = 5;
    int& r = a;     // r is reference to a
    r = 10;         // modify through reference
    cout << a << endl;  // (1)
    cout << r << endl;  // (2)

    return 0;
}