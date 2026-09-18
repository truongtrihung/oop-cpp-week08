#include <iostream>
using namespace std;

void addFive(int &x){
    x += 5;
}

int main(){
    int a = 10;
    addFive(a);
    cout << a << endl;
    // expect 15
    return 0;
}