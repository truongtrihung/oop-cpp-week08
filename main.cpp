#include <iostream>
using namespace std;

int main(){
    int n = 7;
    int &r = n;
    r = 15;
    cout << n << " " << r << endl;
    // 15 15
    return 0;
}