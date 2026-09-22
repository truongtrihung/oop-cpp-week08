#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

void toUpperCase (string& str){
    for (char& c : str){
        c = toupper(c);
    }
}

int main(){
    string text = "C++ is fun";
    toUpperCase(text);
    cout << text << endl;

    return 0;
}