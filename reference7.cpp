#include <iostream>
#include <string>
using namespace std;

void changeFirstChar (string& str){
    str[0] = ']';
}

int main(){
    string name = "Python";
    changeFirstChar(name);
    cout << name << endl;
    
    return 0;
}