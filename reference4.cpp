#include <iostream>
using namespace std;

void changeValue(int x){
    x = 100;    // pass by value
}
void changeRef(int& x){
    x = 200;    // pass by reference
}

int main(){
    int a = 5;
    changeValue(a);
    cout << "After changeValue: " << a << endl; // Output = 5
    changeRef(a);
    cout << "After changeRef: " << a << endl; // Output = 200

    return 0;
}