#include <iostream>
#include <string>
using namespace std;

int main(){
    string s = "Hello";
    string& r = s;  // r is a reference to s
    r += " World";  // modigy through reference
    cout << s << endl;  // (1)
    cout << r << endl;  // (2)

    return 0;
}