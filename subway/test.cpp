#include <iostream>
#include <fstream>

using namespace std;

int main(){

    ifstream data222;
    data222.open("data222.txt");

    string line;

    while (getline(data222,line)){
        cout << line << endl;
    }

}