#include <iostream>
#include <string>
using namespace std;

int main (){
    int x = 10;
    int& rx = x;    //reference to x
    rx = 20;        // change value using reference
    cout << "x = " << x << endl;
    cout << "rx = " << rx << endl;

    // Ouput x = 20; rx = 20
    return 0;
}