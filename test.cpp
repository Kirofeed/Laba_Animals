#include <iostream>
#include <set>
#include <map>
#include <sstream>

using namespace std;

int  main() {
    setlocale(LC_ALL, "ru");
//    set<int> set;
//    map<int, string> map;
//
//    map[1] = "kirill";
//    map[2] = "sasha";
//    map[3] = "masha";
//    map[3] = "natasha";
//
//    for (const auto& it : map) {
//        cout << it.second << "\t";
//    }
//    string hello;
//    string how;
//    size_t delim = 3;
//    string str = "hello, how are u?";
////    delim = str.find(',');
////    hello = str.substr(0, delim);
////    str.erase( 0, hello.size() + 2);
////    delim = str.find('?');
////    how = str.substr(0, delim+1);
////    cout << hello << endl << how << endl;
////    delim = str.find('*');
//    cout << delim;
//    string line = "Kirill Drozhzh; +375295009636; Minsk; 18";
//    string name;
//    string telephoneNumber;
//    string adress;
//    int age;
//    size_t delim;
//    delim = line.find(';');
//    if (delim > line.size()) {
//        cerr << "problem with reading data";
//    }
//    name = line.substr(0, delim);
//    line.erase(0, name.size() +  2);
//
//    delim = line.find(';');
//    if (delim > line.size()) {
//        cerr << "problem with reading data";
//    }
//    telephoneNumber = line.substr(0, delim);
//    line.erase(0, telephoneNumber.size() +  2);
//
//    delim = line.find(';');
//    if (delim > line.size()) {
//        cerr << "problem with reading data";
//    }
//    adress = line.substr(0, delim);
//    line.erase(0, adress.size() +  2);
//
//    delim = line.find(';');
//    age = stoi(line.substr(0, delim));
//
//    cout << name << endl << telephoneNumber << endl << adress << endl << age;
//    string str = ", kirill";
//    size_t delim = str.find(' ');
//    if (str.substr(0, delim) == "") {
//        cout << "наше";
//    }
    string str = "2. For the type of animal print all the owners of this type and names of the animals";
    cout << str.size();

}