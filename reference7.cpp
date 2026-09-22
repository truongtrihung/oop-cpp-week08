#include <iostream>
#include <string>
using namespace std;

void addExclaim (string& str){
    str += "!!";
}

int main(){
    string msg = "Good Day";
    addExclaim(msg);
    cout << msg << endl;

    return 0;
}