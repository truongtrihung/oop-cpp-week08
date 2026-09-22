#include <iostream>
#include <string>
using namespace std;


int main(){
    string s = "Hello";
    string r = s;       // r is copy of s
    string& ref = s;    // ref is a reference to s

    r += "!!!";         // modify the copy
    ref += "???";       // modify the original

    cout << "s    :" << s << endl;
    cout << "r    :" << r << endl;
    cout << "ref  :" << ref << endl;

    return 0;
}