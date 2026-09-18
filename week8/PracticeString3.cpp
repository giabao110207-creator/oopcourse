#include <iostream>
#include <string>

using namespace std;

int main(){
cout << "===== 1. LENGTH / SIZE =====" << endl;
string s1 = "Hello C++";
cout << "Length: " << s1.length() << endl;
cout << "Size: " << s1.size() << endl;
  
cout << "\n===== 2. EMPTY =====" << endl;
string s2 = "";
string s3 = "Hi";
cout << "s2 empty: " << s2.empty() << endl;
cout << "s3 empty: " << s3.empty() << endl;

cout << "\n===== 3. FIND =====" << endl;
string text = "I love C++";
size_t pos = text.find("C++");
if (pos != string::npos){
    cout << "Found at: " << pos << endl;
}else{
    cout << "Not found!" << endl;
}

cout << "\n===== 4. SUBSTR =====" << endl;
string s4 = "Hello World";
string part1 = s4.substr(0, 5);
string part2 = s4.substr(6, 5);
cout << "Part 1: " << part1 << endl;
cout << "Part 2: " << part2 << endl;

cout << "\n===== 5. APPEND =====" << endl;
string s5 = "Hello";
s5.append(" C++");
cout << "After append: " << s5 << endl;

cout << "\n===== 6. INSERT =====" << endl;
string s6 = "Hello World";
s6.insert(5, " C++");
cout << "After insert: " << s6 << endl;
 
cout << "\n===== 7. ERASE =====" << endl;
string s7 = "Hello World";
s7.erase(5, 6);
cout << "After erase: " << s7 << endl;

cout << "\n===== 8. REPLACE =====" << endl;
string s8 = "I like Java";
s8.replace(7, 4, "C++");
cout << "After replace: " << s8 << endl;

cout << "\n===== 9. COMPARE =====" << endl;
string s9 = "apple";
string s10 = "apple";
string s11 = "banana";
cout << "apple vs apple: " << s9.compare(s10) << endl;
cout << "apple vs banana: " << s9.compare(s11) << endl;
cout << "banana vs apple: " << s11.compare(s9) << endl;

return 0;
}