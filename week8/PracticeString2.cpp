#include <iostream>
#include <string>

using namespace std;

int main (){
    string s1 = "Hello";
    string s2 = "C++";
    cout << s1 << endl;
    cout << s2 << endl;

    string name;
    cout << "Enter your name: ";
    getline(cin, name);
    cout << "Hello, " << name << "!" << endl;

    string first = "Hello";
    string second = "World";
    string messages = first + " " + second + " ";
    cout << messages << endl;

    string s = "Hello C++";
    cout << "Length: " << s.length() << endl;

    string s_char = "Hello";
    cout << "First character : " << s_char[0] << endl;
    cout << "Third character: " << s_char[2] << endl;

    string text = "I love C++!";
    size_t pos = text.find("C++");
    if (pos != string::npos){
        cout << "Found at position: " << pos << endl;
    }
    else {
        cout << "Not found!" << endl;
    }

    string text2 = "Hello C++ World";
    string part = text2.substr(6, 3);
    cout << part << endl;

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