#include <iostream>
#include <string>

using namespace std;

int main (){
    // 1. Khai báo và xuất chuỗi cơ bản
    string s1 = "Hello";
    string s2 = "C++";
    cout << s1 << endl;
    cout << s2 << endl;

    // 2. Nhập chuỗi có khoảng trắng bằng getline
    string name;
    cout << "Enter your name: ";
    getline(cin, name);
    cout << "Hello, " << name << "!" << endl;

    // 3. Nối chuỗi bằng toán tử +
    string first = "Hello";
    string second = "World";
    string messages = first + " " + second + " ";
    cout << messages << endl;

    // 4. Độ dài chuỗi
    string s = "Hello C++";
    cout << "Length: " << s.length() << endl;

    // 5. Truy cập ký tự qua chỉ số (Index) - Đổi tên thành s_char
    string s_char = "Hello";
    cout << "First character : " << s_char[0] << endl;
    cout << "Third character: " << s_char[2] << endl;

    // 6. Tìm kiếm chuỗi con bằng find()
    string text = "I love C++!";
    size_t pos = text.find("C++");
    if (pos != string::npos){
        cout << "Found at position: " << pos << endl;
    }
    else {
        cout << "Not found!" << endl;
    }

    // 7. Cắt chuỗi con bằng substr() - Đổi tên thành text2
    string text2 = "Hello C++ World";
    string part = text2.substr(6, 3);
    cout << part << endl;

    // 8. So sánh chuỗi bằng compare() - Đổi tên thành str1, str2
    string str1 = "apple";
    string str2 = "apple";
    if (str1.compare(str2) == 0){
        cout << "The strings are equal. " << endl;
    }
    else {
        cout << "The strings are different. " << endl;
    }

    return 0;
}
