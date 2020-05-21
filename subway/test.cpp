#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

int main(){

    ifstream data222;
    data222.open("data222.txt");

    string line;

    while (getline(data222,line)){
        if (line.compare("\n") == 0) break;
        //cout << line << endl;
        istringstream iss (line);
        string second, first, third;
        iss >> second >> first >> third;
        cout << second << endl;
        //cout << second << first << third;
        second += "2";
        cout << "second : " << second << endl;
    }

    
    
    


    
    data222.close();


}