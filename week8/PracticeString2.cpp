#include <iostream>
#include <string>

using namespace std;

int main(){
string sentence;

// 1. Nhap mot cau
cout << "Enter a sentence: ";
getline(cin, sentence);
// 2. Hien thi do dai cau
cout << "Length: " << sentence.length() << endl;
// 3. Tim vi tri cua "C++"
size_t pos = sentence.find("C++");
// 4. Neu tim thay, in tu bat dau tu vi tri do
if (pos != string::npos){
    cout << "Found C++ at position: " << pos << endl;
    cout << "Substring: " << sentence.substr(pos) << endl;
}else{
    cout << "C++ not found!" << endl;
}
// 5. Thay "C++" bang "Programming"
if (pos != string::npos){
    sentence.replace(pos, 3, "Programming");
}
cout << "New sentence: " << sentence << endl;

return 0;
}