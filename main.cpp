#include "func.cpp"
#include <iostream>
#include <fstream>


using namespace std;


int main() {
    // ReadDataFromFile();
    // Menu();

    cat cat1 = cat("vdjkfh", 3, "jhfsd", "dfhgo", 3, "jfdhsg");
    cat cat2(move(cat1));
    int k = 5;
    return 0;
}